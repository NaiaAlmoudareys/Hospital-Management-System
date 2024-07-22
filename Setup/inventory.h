#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>

class Inventory {
public:
    Inventory(const std::string& item, int quantity, const std::string& supplier);

    bool addItem();
    void viewInventory();
    void updateItem();
    void deleteItem();

private:
    std::string item;
    int quantity;
    std::string supplier;
};

#endif
