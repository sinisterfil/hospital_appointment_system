#ifndef PATIENT_H
#define PATIENT_H
#include "person.h"

class Patient : public Person {
private:
    string illness;
public:
    Patient(string n = "Unknown", int i = 0, string ill = "None") : Person(n, i), illness(ill) {}
    int getId() const { return id; }
    string getName() const { return name; }
    void display() const override {
        cout << "[Patient] ID: " << id << ", Name: " << name << ", Illness: " << illness << endl;
    }
    string getIllness() const { return illness; }
};

#endif