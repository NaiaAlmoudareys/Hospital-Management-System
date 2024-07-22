# Hospital Management System

## Project Description
A comprehensive console-based application to manage a hospital system, including user management, patient management, doctor management, appointment management, billing, and inventory management.

## Features
- User Management: Register, login, and profile management for staff and patients.
- Patient Management: Add, view, edit, and delete patient details and medical records.
- Doctor Management: Add, view, edit, and delete doctor details.
- Appointment Management: Schedule, view, and cancel appointments.
- Billing Management: Generate bills, track payments, and manage financial records.
- Inventory Management: Manage medical supplies and equipment.
- Security: Secure authentication, authorization, and data encryption.
- Notifications: Send notifications for appointments and billing activities.

## Technology Stack
- **Language:** C++
- **Database:** SQLite
- **Security:** OpenSSL for encryption
- **Library:** Qt for GUI (optional if you want to extend to a graphical interface)

## Installation

### Dependencies
- SQLite
- OpenSSL

### Setup
1. Install the dependencies using your package manager. For example, on Ubuntu:
    ```sh
    sudo apt-get install libsqlite3-dev libssl-dev
    ```

2. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/hospital-management-system.git
    cd hospital-management-system
    ```

3. Compile the program:
    ```sh
    g++ -o hospital src/*.cpp -lsqlite3 -lssl -lcrypto
    ```

4. Run the program:
    ```sh
    ./hospital
    ```

## Usage
1. Register a new user (patient, staff, or admin) or login with an existing user.
2. Manage patients, doctors, appointments, billing, and inventory through the console interface.
3. Admins can log in to manage users and generate reports.

## Contributing
Feel free to fork this project and submit pull requests. All contributions are welcome!

## License
This project is licensed under the MIT License.
