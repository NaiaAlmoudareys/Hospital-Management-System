#ifndef BILLING_H
#define BILLING_H

#include <string>

class Billing {
public:
    Billing(const std::string& patient, const std::string& treatment, double amount);

    bool generateBill();
    void viewBills();
    void trackPayments();

private:
    std::string patient;
    std::string treatment;
    double amount;
};

#endif
