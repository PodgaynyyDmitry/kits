#include "../include/kitchecker.h"

bool KitChecker::checkKit(Document &doc, const Kit &kit, vector<DocumentLine> &foundLines) {
    foundLines.clear();
    for (const auto &kitLine : kit.getLines()) {
        DocumentLine found;
        vector<int> positions = doc.findIndexes(kitLine.catalog, kitLine.quantity);
        if (positions.size() > 0) {
            vector<DocumentLine> lineForKit = doc.checkQuantity(kitLine.quantity, positions, kitLine.catalog);
            if (lineForKit.size() > 0) {
                for (const auto line : lineForKit) {
                    foundLines.push_back(line);
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}
