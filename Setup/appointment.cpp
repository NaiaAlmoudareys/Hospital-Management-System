#include "appointment.h"
#include "database.h"
#include <iostream>

extern Database db;

Appointment::Appointment(const std::string& patient, const std::string& doctor, const std::string& date, const std::string& time)
    : patient(patient), doctor(doctor), date(date), time(time) {}

bool Appointment::scheduleAppointment() {
    std::string query = "INSERT INTO appointments (patient, doctor, date, time) VALUES ('" + patient + "', '" + doctor + "', '" + date + "', '" + time + "')";
    return db.executeQuery(query);
}

void Appointment::viewAppointments() {
    // Implementation to view appointments
}

void Appointment::cancelAppointment() {
    // Implementation to cancel appointment
}
