#include "../include/kit.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

bool Kit::loadFromFile(const string &filePath) {
    ifstream file(filePath);
    if (!file.is_open()){
        cerr << "Не удалось открыть файл набора: " << filePath << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        if (line.empty())
            continue;
        istringstream stremLine(line);
        KitLine kitLine;
        string catalog;
        if (!(stremLine >> catalog >> kitLine.quantity)) {
            cerr << "Некорректная строка в наборе (пропускаем): " << line << endl;
            continue;
        }
        leftTrim(catalog);
        rightTrim(catalog);
        kitLine.catalog = catalog;
        lines.push_back(kitLine);
    }
    return true;
}

void Kit::leftTrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
                return !isspace(ch);
            }));
}

void Kit::rightTrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
                return !isspace(ch);
            }).base(), s.end());
}
