#include "patient.h"
#include "database.h"
#include <iostream>

extern Database db;

Patient::Patient(const std::string& name, const std::string& dob, const std::string& address, const std::string& phone)
    : name(name), dob(dob), address(address), phone(phone) {}

bool Patient::addPatient() {
    std::string query = "INSERT INTO patients (name, dob, address, phone) VALUES ('" + name + "', '" + dob + "', '" + address + "', '" + phone + "')";
    return db.executeQuery(query);
}

void Patient::viewPatientDetails() {
    // Implementation to view patient details
}

void Patient::updatePatientDetails() {
    // Implementation to update patient details
}

void Patient::deletePatient() {
    // Implementation to delete patient
}
