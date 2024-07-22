#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

class Appointment {
public:
    Appointment(const std::string& patient, const std::string& doctor, const std::string& date, const std::string& time);

    bool scheduleAppointment();
    void viewAppointments();
    void cancelAppointment();

private:
    std::string patient;
    std::string doctor;
    std::string date;
    std::string time;
};

#endif
