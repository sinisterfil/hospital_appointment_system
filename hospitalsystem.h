#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H
#include <vector>
#include <fstream>
#include <iostream>
#include "patient.h"
#include "doctor.h"
#include "appointment.h"
using namespace std;

class HospitalSystem {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;
    static int totalAppointments;
public:
    HospitalSystem() {}
    void addPatient(const Patient& p) { patients.push_back(p); }
    void addDoctor(const Doctor& d) { doctors.push_back(d); }
    void addDoctor(string name, int id, string specialization = "General") {
        Doctor d(name, id, specialization);
        addDoctor(d); 
    }
    void scheduleAppointment(Patient* p, Doctor* d, Date date, string time = "10:00") {
        appointments.emplace_back(p, d, date, time);
        totalAppointments++;
    }
    static void showTotalAppointments() { cout << "Total Appointments: " << totalAppointments << endl; }
    void showAllAppointments() {
        for (const auto& app : appointments) {
            showAppointment(app);
            cout << "------------------\n";
        }
    }
    void savePatients() {
        ofstream file("patients.txt");
        for (const auto& p : patients) file << p.getId() << "," << p.getName() << "," << p.getIllness() << endl;
        file.close();
    }
    void saveDoctors() {
        ofstream file("doctors.txt");
        for (const auto& d : doctors) file << d.getId() << "," << d.getName() << "," << d.getSpecialization() << endl;
        file.close();
    }
    void loadPatients() {
        ifstream file("patients.txt");
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
    
            size_t pos1 = line.find(",");
            size_t pos2 = line.rfind(",");
    
            if (pos1 == string::npos || pos2 == string::npos || pos1 == pos2) {
                cerr << "Invalid patient line." << line << endl;
                continue;
            }
    
            string idStr = line.substr(0, pos1);
            string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string illness = line.substr(pos2 + 1);
    
            try {
                int id = stoi(line.substr(0, pos1));
                string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                string specialization = line.substr(pos2 + 1);
    
                patients.emplace_back(name, id, illness);
            } catch (...) {
                cerr << "Patient line could not be distinguished." << line << endl;

            }
        }
        file.close();
    }    
    void loadDoctors() {
        ifstream file("doctors.txt");
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
    
            size_t pos1 = line.find(",");
            size_t pos2 = line.rfind(",");
    
            if (pos1 == string::npos || pos2 == string::npos || pos1 == pos2) {
                cerr << "Invalid doctor line." << line << endl;
                continue;
            }
    
            try {
                int id = stoi(line.substr(0, pos1));
                string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                string specialization = line.substr(pos2 + 1);
    
                doctors.emplace_back(name, id, specialization);
            } catch (...) {
                cerr << "Doctor line could not be distinguished." << line << endl;
            }
        }
        file.close();
    }
    Patient* findPatientById(int id) {
        for (auto& patient : patients) {
            if (patient.getId() == id) {
                return &patient;
            }
        }
        return nullptr;
    }
    Doctor* findDoctorById(int id) {
        for (auto& doctor : doctors) {
            if (doctor.getId() == id) {
                return &doctor;
            }
        }
        return nullptr;
    }
    void showAllPatients() const {
        cout << "\n--- All Patients ---\n";
        if (patients.empty()) {
            cout << "No patients found.\n";
            return;
        }
        for (const auto& p : patients) {
            cout << "ID: " << p.getId()
                 << ", Name: " << p.getName()
                 << ", Illness: " << p.getIllness() << endl;
        }
    }
    void showAllDoctors() const {
        cout << "\n--- All Doctors ---\n";
        if (doctors.empty()) {
            cout << "No doctors found.\n";
            return;
        }
        for (const auto& p : doctors) {
            cout << "ID: " << p.getId()
                 << ", Name: " << p.getName()
                 << ", Specialization: " << p.getSpecialization() << endl;
        }
    }
};

int HospitalSystem::totalAppointments = 0;

#endif