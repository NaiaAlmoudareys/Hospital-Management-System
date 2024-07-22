#include "doctor.h"
#include "database.h"
#include <iostream>

extern Database db;

Doctor::Doctor(const std::string& name, const std::string& specialty, const std::string& phone)
    : name(name), specialty(specialty), phone(phone) {}

bool Doctor::addDoctor() {
    std::string query = "INSERT INTO doctors (name, specialty, phone) VALUES ('" + name + "', '" + specialty + "', '" + phone + "')";
    return db.executeQuery(query);
}

void Doctor::viewDoctorDetails() {
    // Implementation to view doctor details
}

void Doctor::updateDoctorDetails() {
    // Implementation to update doctor details
}

void Doctor::deleteDoctor() {
    // Implementation to delete doctor
}
