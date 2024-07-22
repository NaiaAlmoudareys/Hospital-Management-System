#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

class Doctor {
public:
    Doctor(const std::string& name, const std::string& specialty, const std::string& phone);

    bool addDoctor();
    void viewDoctorDetails();
    void updateDoctorDetails();
    void deleteDoctor();

private:
    std::string name;
    std::string specialty;
    std::string phone;
};

#endif
