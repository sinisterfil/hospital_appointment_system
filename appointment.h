#include <iostream>     
#include <vector>    
#include <string>     
#include <fstream>   
#include <sstream>      
#include <stdexcept> 

using namespace std;

struct Date {
    int day, month, year;
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    Date() {
        day = 1;
        month = 1;
        year = 2000;
    }
};
    
    class Appointment {
        private:
            Patient* patient;
            Doctor* doctor;
            Date date;
            string time;
        public:
            Appointment(Patient* p, Doctor* d, Date dt, string t = "10:00")
                : patient(p), doctor(d), date(dt), time(t) {}
            
            friend void showAppointment(const Appointment& a) {
                cout << "Appointment Info:" << endl;
                a.patient->display();
                a.doctor->display();
                cout << "Date: " << a.date.day << "/" << a.date.month << "/" << a.date.year << endl;
                cout << "Time: " << a.time << endl;
            }
        };
        