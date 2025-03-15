#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "include/document.h"
#include "include/kit.h"
#include "include/kitchecker.h"

using namespace std;

int main(int argc, char* argv[]) {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    if (argc < 3) {
        cerr << "Использование: " << argv[0] << " <document.txt> <kit.txt>" << endl;
        return 1;
    }

    const string documentPath = argv[1];
    const string kitPath = argv[2];

    Document doc;
    if (!doc.loadFromFile(documentPath)) {
        return 1;
    }

    Kit kit;
    if (!kit.loadFromFile(kitPath)) {
        return 1;
    }

    KitChecker checker;
    vector<DocumentLine> foundLines;

    if (checker.checkKit(doc, kit, foundLines)) {
        cout << "Набор присутствует в документе." << endl;
        cout << "Найденные строки (позиция, количество, каталоги):" << endl;
        for (const auto &line : foundLines) {
            cout << line.position << " " << line.quantity;
            for (const auto &catalog : line.catalogs) {
                cout << " " << catalog;
            }
            cout << endl;
        }
    } else {
        cout << "Набор не найден в документе." << endl;
    }

    return 0;
}

