#include "inventory.h"
#include "database.h"
#include <iostream>

extern Database db;

Inventory::Inventory(const std::string& item, int quantity, const std::string& supplier)
    : item(item), quantity(quantity), supplier(supplier) {}

bool Inventory::addItem() {
    std::string query = "INSERT INTO inventory (item, quantity, supplier) VALUES ('" + item + "', " + std::to_string(quantity) + ", '" + supplier + "')";
    return db.executeQuery(query);
}

void Inventory::viewInventory() {
    // Implementation to view inventory
}

void Inventory::updateItem() {
    // Implementation to update inventory item
}

void Inventory::deleteItem() {
    // Implementation to delete inventory item
}
