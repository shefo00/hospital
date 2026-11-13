#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    int age;
    string doctor;

    Patient(string n, int a) {
        name = n;
        age = a;
        doctor = "Not assigned";
    }
};

int main() {

    vector<Patient> patients;

    int choice;
    int age;
    string name, doctor;

    do {
        cout << "\n=== Hospital System ===" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Assign Doctor" << endl;
        cout << "3. Search Patient" << endl;
        cout << "4. Display All Patients" << endl;
        cout << "5. Exit" << endl;

        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                cout << "Enter patient name: ";
                getline(cin >> ws, name);

                cout << "Enter age: ";
                cin >> age;

                if (age <= 0) {
                    cout << "Invalid age!" << endl;
                    break;
                }

                bool found = false;

                for (int i = 0; i < patients.size(); i++) {
                    if (patients[i].name == name) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    cout << "Patient already exists!" << endl;
                }
                else {
                    patients.push_back(Patient(name, age));
                    cout << "Patient \"" << name << "\" added." << endl;
                }

                break;
            }

            case 2: {
                cout << "Enter patient name: ";
                getline(cin >> ws, name);

                bool found = false;

                for (int i = 0; i < patients.size(); i++) {
                    if (patients[i].name == name) {

                        cout << "Enter doctor name: ";
                        getline(cin >> ws, doctor);

                        patients[i].doctor = doctor;

                        cout << name << " assigned to "
                             << doctor << "." << endl;

                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Patient not found!" << endl;
                }

                break;
            }

            case 3: {
                cout << "Enter patient name: ";
                getline(cin >> ws, name);

                bool found = false;

                for (int i = 0; i < patients.size(); i++) {
                    if (patients[i].name == name) {

                        cout << "\nPatient: " << patients[i].name << endl;
                        cout << "Age: " << patients[i].age << endl;
                        cout << "Doctor: " << patients[i].doctor << endl;

                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Patient not found!" << endl;
                }

                break;
            }

            case 4: {
                if (patients.empty()) {
                    cout << "No patients found." << endl;
                }
                else {
                    for (int i = 0; i < patients.size(); i++) {

                        cout << "\nPatient: " << patients[i].name;
                        cout << " | Age: " << patients[i].age;
                        cout << " | Doctor: " << patients[i].doctor << endl;

                    }
                }

                break;
            }

            case 5:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid option! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}