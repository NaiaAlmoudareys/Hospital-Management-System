#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient {
public:
    Patient(const std::string& name, const std::string& dob, const std::string& address, const std::string& phone);

    bool addPatient();
    void viewPatientDetails();
    void updatePatientDetails();
    void deletePatient();

private:
    std::string name;
    std::string dob;
    std::string address;
    std::string phone;
};

#endif
