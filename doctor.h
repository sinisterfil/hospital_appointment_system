#ifndef DOCTOR_H
#define DOCTOR_H
#include "person.h"

class Doctor : public Person {
private:
    string specialization;
public:
    Doctor(string n = "Unknown", int i = 0, string spec = "General") : Person(n, i), specialization(spec) {}
    int getId() const { return id; }
    string getName() const { return name; }
    void display() const override {
        cout << "[Doctor] ID: " << id << ", Name: " << name << ", Specialization: " << specialization << endl;
    }
    string getSpecialization() const { return specialization; }
};

#endif