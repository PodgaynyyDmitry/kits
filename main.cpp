#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32
    #include <windows.h>
#endif

#include "include/document.h"
#include "include/kit.h"
#include "include/kitchecker.h"

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

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

