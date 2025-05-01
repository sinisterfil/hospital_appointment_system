#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int id;
public:
    Person(string n = "Unknown", int i = 0) : name(n), id(i) {}
    virtual void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
    string getName() const { return name; }
    int getId() const { return id; }
};

#endif