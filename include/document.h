#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <vector>

using namespace std;

struct DocumentLine {
    int position;
    int quantity;
    vector<string> catalogs;
};

class Document {
private:
    vector<DocumentLine> lines;
public:
    bool loadFromFile(const string &filePath);
    vector<int> findIndexes(const string &catalog, int quantity);
    const vector<DocumentLine>& getLines() const { return lines; }
    vector<DocumentLine> checkQuantity(int quantity, vector<int> positions, const string &catalog);

    void leftTrim(string &s);
    void rightTrim(string &s);
};

#endif // DOCUMENT_H
