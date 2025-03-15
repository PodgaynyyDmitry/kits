#ifndef KIT_H
#define KIT_H

#include <string>
#include <vector>

using namespace std;

struct KitLine {
    string catalog;
    int quantity;
};

class Kit {
private:
    vector<KitLine> lines;
public:
    bool loadFromFile(const string &filePath);
    const vector<KitLine>& getLines() const { return lines; }

    void leftTrim(string &s);
    void rightTrim(string &s);
};

#endif // KIT_H
