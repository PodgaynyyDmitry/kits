#ifndef KITCHECKER_H
#define KITCHECKER_H

#include <vector>
#include "document.h"
#include "kit.h"

class KitChecker {
public:
    bool checkKit(Document &doc, const Kit &kit, vector<DocumentLine> &foundLines);
};

#endif // KITCHECKER_H
