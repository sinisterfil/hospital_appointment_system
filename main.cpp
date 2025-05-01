#include "hospitalsystem.h"

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isNumber(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    HospitalSystem system;
    system.loadPatients();
    system.loadDoctors();

    string input;
    int choice = 0;

    do {
        cout << "\n--- Hospital Appointment Scheduling System ---\n";
        cout << "1. Add Patient\n2. Add Doctor\n3. Schedule Appointment\n4. Show All Appointments\n5. Show All Patients\n6. Show All Doctors\n7. Exit\nEnter your choice: ";

        getline(cin, input);
        if (!isNumber(input)) {
            cout << "Invalid input. Please enter a number between 1 and 7.\n";
            continue;
        }

        choice = stoi(input); // güvenli çünkü kontrol ettik

        if (choice == 1) {
            string name, illness; int id;
            cout << "Enter Patient ID: "; cin >> id; cin.ignore();
            cout << "Enter Patient Name: "; getline(cin, name);
            cout << "Enter Illness: "; getline(cin, illness);
            Patient p(name, id, illness);
            system.addPatient(p);
            system.savePatients();
        } else if (choice == 2) {
            string name, specialization; int id;
            cout << "Enter Doctor ID: "; cin >> id; cin.ignore();
            cout << "Enter Doctor Name: "; getline(cin, name);
            cout << "Enter Specialization: "; getline(cin, specialization);
            system.addDoctor(name, id, specialization);
            system.saveDoctors();
        } else if (choice == 3) {
            int patientId, doctorId;
            string time;
            Date date; 
            cout << "Enter Patient ID: "; cin >> patientId;
            cout << "Enter Doctor ID: "; cin >> doctorId;
            Patient *p = system.findPatientById(patientId);
            Doctor *d = system.findDoctorById(doctorId);
            if (!p || !d) {
                cout << "Invalid Patient or Doctor ID!\n";
                cin.ignore();
                continue;
            } cout << "Enter Appointment Date (day month year): ";
            cin >> date.day >> date.month >> date.year;
            cout << "Enter Time (HH:MM): "; cin >> time;
            system.scheduleAppointment(p, d, date, time);
            cin.ignore();
        } else if (choice == 4) {
            system.showAllAppointments();
        }
        else if (choice == 5) {
            system.showAllPatients();
        }
        else if (choice == 6) {
            system.showAllDoctors();
        } else if (choice != 7) {
            cout << "Invalid choice. Please enter a number between 1 and 7.\n";
        }
    } while (choice != 7);
    cout << "Exiting system.\n";
    return 0;
}
