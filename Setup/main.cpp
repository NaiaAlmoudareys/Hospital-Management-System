#include <iostream>
#include "user.h"
#include "patient.h"
#include "doctor.h"
#include "appointment.h"
#include "billing.h"
#include "inventory.h"
#include "database.h"

Database db("hospital_management.db");

void userMenu(User& user) {
    int choice;
    Patient patient("", "", "", "");
    Appointment appointment("", "", "", "");

    do {
        std::cout << "1. View Profile\n2. Update Profile\n3. Add Patient\n4. View Patient Details\n5. Update Patient Details\n6. Delete Patient\n7. Schedule Appointment\n8. View Appointments\n9. Cancel Appointment\n10. Logout\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                user.viewProfile();
                break;
            case 2:
                user.updateProfile();
                break;
            case 3: {
                std::string name, dob, address, phone;
                std::cout << "Enter patient name: ";
                std::cin >> name;
                std::cout << "Enter date of birth: ";
                std::cin >> dob;
                std::cout << "Enter address: ";
                std::cin >> address;
                std::cout << "Enter phone number: ";
                std::cin >> phone;
                patient = Patient(name, dob, address, phone);
                if (patient.addPatient()) {
                    std::cout << "Patient added successfully\n";
                } else {
                    std::cout << "Failed to add patient\n";
                }
                break;
            }
            case 4:
                patient.viewPatientDetails();
                break;
            case 5:
                patient.updatePatientDetails();
                break;
            case 6:
                patient.deletePatient();
                break;
            case 7: {
                std::string patientName, doctorName, date, time;
                std::cout << "Enter patient name: ";
                std::cin >> patientName;
                std::cout << "Enter doctor name: ";
                std::cin >> doctorName;
                std::cout << "Enter date: ";
                std::cin >> date;
                std::cout << "Enter time: ";
                std::cin >> time;
                appointment = Appointment(patientName, doctorName, date, time);
                if (appointment.scheduleAppointment()) {
                    std::cout << "Appointment scheduled successfully\n";
                } else {
                    std::cout << "Failed to schedule appointment\n";
                }
                break;
            }
            case 8:
                appointment.viewAppointments();
                break;
            case 9:
                appointment.cancelAppointment();
                break;
            case 10:
                std::cout << "Logged out successfully\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != 10);
}

void adminMenu(User& admin) {
    int choice;
    Doctor doctor("", "", "");
    Billing billing("", "", 0);
    Inventory inventory("", 0, "");

    do {
        std::cout << "1. View Profile\n2. Update Profile\n3. Add Doctor\n4. View Doctor Details\n5. Update Doctor Details\n6. Delete Doctor\n7. Generate Bill\n8. View Bills\n9. Track Payments\n10. Add Inventory\n11. View Inventory\n12. Update Inventory\n13. Delete Inventory\n14. Logout\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                admin.viewProfile();
                break;
            case 2:
                admin.updateProfile();
                break;
            case 3: {
                std::string name, specialty, phone;
                std::cout << "Enter doctor name: ";
                std::cin >> name;
                std::cout << "Enter specialty: ";
                std::cin >> specialty;
                std::cout << "Enter phone number: ";
                std::cin >> phone;
                doctor = Doctor(name, specialty, phone);
                if (doctor.addDoctor()) {
                    std::cout << "Doctor added successfully\n";
                } else {
                    std::cout << "Failed to add doctor\n";
                }
                break;
            }
            case 4:
                doctor.viewDoctorDetails();
                break;
            case 5:
                doctor.updateDoctorDetails();
                break;
            case 6:
                doctor.deleteDoctor();
                break;
            case 7: {
                std::string patientName, treatment;
                double amount;
                std::cout << "Enter patient name: ";
                std::cin >> patientName;
                std::cout << "Enter treatment: ";
                std::cin >> treatment;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                billing = Billing(patientName, treatment, amount);
                if (billing.generateBill()) {
                    std::cout << "Bill generated successfully\n";
                } else {
                    std::cout << "Failed to generate bill\n";
                }
                break;
            }
            case 8:
                billing.viewBills();
                break;
            case 9:
                billing.trackPayments();
                break;
            case 10: {
                std::string item;
                int quantity;
                std::string supplier;
                std::cout << "Enter item name: ";
                std::cin >> item;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                std::cout << "Enter supplier: ";
                std::cin >> supplier;
                inventory = Inventory(item, quantity, supplier);
                if (inventory.addItem()) {
                    std::cout << "Item added to inventory successfully\n";
                } else {
                    std::cout << "Failed to add item to inventory\n";
                }
                break;
            }
            case 11:
                inventory.viewInventory();
                break;
            case 12:
                inventory.updateItem();
                break;
            case 13:
                inventory.deleteItem();
                break;
            case 14:
                std::cout << "Logged out successfully\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != 14);
}

int main() {
    int choice;

    do {
        std::cout << "1. Register\n2. Login\n3. Admin Login\n4. Exit\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string username, password, role;
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                std::cout << "Enter role (patient/staff/admin): ";
                std::cin >> role;
                User user(username, password, role);
                if (user.registerUser()) {
                    std::cout << "Registration successful\n";
                } else {
                    std::cout << "Registration failed\n";
                }
                break;
            }
            case 2: {
                std::string username, password;
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                User user(username, password, "patient");
                if (user.loginUser()) {
                    std::cout << "Login successful\n";
                    userMenu(user);
                } else {
                    std::cout << "Login failed\n";
                }
                break;
            }
            case 3: {
                std::string username, password;
                std::cout << "Enter admin username: ";
                std::cin >> username;
                std::cout << "Enter admin password: ";
                std::cin >> password;
                User admin(username, password, "admin");
                if (admin.loginUser()) {
                    std::cout << "Admin login successful\n";
                    adminMenu(admin);
                } else {
                    std::cout << "Admin login failed\n";
                }
                break;
            }
            case 4:
                std::cout << "Exiting program\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
