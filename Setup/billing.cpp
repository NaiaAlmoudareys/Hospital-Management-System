#include "billing.h"
#include "database.h"
#include <iostream>

extern Database db;

Billing::Billing(const std::string& patient, const std::string& treatment, double amount)
    : patient(patient), treatment(treatment), amount(amount) {}

bool Billing::generateBill() {
    std::string query = "INSERT INTO bills (patient, treatment, amount) VALUES ('" + patient + "', '" + treatment + "', " + std::to_string(amount) + ")";
    return db.executeQuery(query);
}

void Billing::viewBills() {
    // Implementation to view bills
}

void Billing::trackPayments() {
    // Implementation to track payments
}
