#include "../include/document.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>


bool Document::loadFromFile(const string &filePath) {
    ifstream file(filePath);
    if (!file.is_open()){
        cerr << "Не удалось открыть файл документа: " << filePath << "\n";
        return false;
    }
    string line;
    while (getline(file, line)) {
        if (line.empty())
            continue;
        istringstream streamLine(line);
        DocumentLine documentLine;
        if (!(streamLine >> documentLine.position >> documentLine.quantity)) {
            cerr << "Некорректная строка в документе (пропускаем): " << line << "\n";
            continue;
        }
        string token;
        while (getline(streamLine, token, ',')) {
            //cout << "Каталоги " << token << endl;
            leftTrim(token);
            rightTrim(token);
            documentLine.catalogs.push_back(token);
        }
        lines.push_back(documentLine);
    }
    return true;
}

vector<int> Document::findIndexes(const string &catalog, int quantity) {
    vector<int> positions;
    for (int  i = 0; i < lines.size(); ++i) {
        for ( auto &cat : lines[i].catalogs) {
            if (cat == catalog)
                positions.push_back(i);
        }
    }
    return positions;
}

vector<DocumentLine> Document::checkQuantity(int quantity, vector<int> positions, const string &catalog)
{
    vector<DocumentLine>  matchedLine;
    DocumentLine documentLine;
    vector<string> kitCatalog = {catalog};
    int catalogLenght = 0;

    while (quantity > 0) {
        for (auto i : positions) {
            if (catalogLenght == lines[i].catalogs.size()) {
                documentLine.position = lines[i].position;
                documentLine.catalogs = kitCatalog;
                documentLine.quantity = (lines[i].quantity >= quantity) ? quantity : quantity - lines[i].quantity;
                matchedLine.push_back(documentLine);

                quantity -= lines[i].quantity;
            }
            if (quantity <= 0)
                break;
        }
        catalogLenght++;
    }
    return matchedLine;
}

void Document::leftTrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
                return !isspace(ch);
            }));
}

void Document::rightTrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
                return !isspace(ch);
            }).base(), s.end());
}
