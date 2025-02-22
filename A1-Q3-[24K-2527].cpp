#include <iostream>
#include <string>
using namespace std;

class User {
private:
    int age;
    string licence_type;
    string contact_info;
    int ID;

public:
    void set_age() {
        cout << "Enter age: ";
        cin >> age;
    }
    int get_age() {
        return age;
    }
    void set_licence_type() {
        cout << "Enter Licence type: ";
        cin >> licence_type;
    }
    string get_licence_type() {
        return licence_type;
    }
    void set_contact_info() {
        cout << "Enter contact number: ";
        cin >> contact_info;
    }
    string get_contact_info() {
        return contact_info;
    }
    void set_id() {
        cout << "Enter ID: ";
        cin >> ID;
    }
    int get_id() {
        return ID;
    }
    void update_details() {
        cout << "Enter your Details Again:\n";
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter ID: ";
        cin >> ID;
        cout << "Enter Licence Type (Full / Intermediate): ";
        cin >> licence_type;
        cout << "Enter contact info: ";
        cin >> contact_info;
    }
};

class Vehicle {
public:
    string model;
    double rental_price;
    string elig_licence;

    Vehicle(string m, double price, string licence) {
        model = m;
        rental_price = price;
        elig_licence = licence;
    }
    void showDetails() {
        cout << "Model: " << model << ", Rental Price: $" << rental_price
             << " per day, Licence Type: " << elig_licence << endl;
    }
    string get_licence() {
        return elig_licence;
    }
};

int main() {
    User u1;
    u1.set_age();
    u1.set_id();
    u1.set_contact_info();
    u1.set_licence_type();

    cout << "\nUser Details:\n";
    cout << "Age: " << u1.get_age() << "\nID: " << u1.get_id()
         << "\nContact Info: " << u1.get_contact_info()
         << "\nLicence Type: " << u1.get_licence_type() << endl;

    int vehicleCount = 15;
    Vehicle** vehicles = new Vehicle*[vehicleCount]; // Dynamic array of pointers

    // Creating 15 different vehicles dynamically
    vehicles[0] = new Vehicle("Toyota Corolla", 40.0, "Full");
    vehicles[1] = new Vehicle("Honda Civic", 45.0, "Full");
    vehicles[2] = new Vehicle("Ford Mustang", 80.0, "Full");
    vehicles[3] = new Vehicle("Chevrolet Camaro", 85.0, "Full");
    vehicles[4] = new Vehicle("Tesla Model 3", 70.0, "Full");
    vehicles[5] = new Vehicle("Nissan Altima", 38.0, "Intermediate");
    vehicles[6] = new Vehicle("Hyundai Elantra", 36.0, "Intermediate");
    vehicles[7] = new Vehicle("Jeep Wrangler", 90.0, "Full");
    vehicles[8] = new Vehicle("BMW X5", 120.0, "Full");
    vehicles[9] = new Vehicle("Mercedes C-Class", 110.0, "Full");
    vehicles[10] = new Vehicle("Volkswagen Jetta", 35.0, "Intermediate");
    vehicles[11] = new Vehicle("Mazda CX-5", 50.0, "Intermediate");
    vehicles[12] = new Vehicle("Subaru Outback", 55.0, "Intermediate");
    vehicles[13] = new Vehicle("Honda CR-V", 48.0, "Intermediate");
    vehicles[14] = new Vehicle("Ford F-150", 95.0, "Full");

    cout << "\nAvailable Vehicles:\n";
    for (int i = 0; i < vehicleCount; i++) {
        vehicles[i]->showDetails();
    }

    cout << "\nVehicles available for your licence type:\n";
    bool found = false;
    for (int i = 0; i < vehicleCount; i++) {
        if (u1.get_licence_type() == vehicles[i]->elig_licence) {
            vehicles[i]->showDetails();
            found = true;
        }
    }
    if (!found) {
        cout << "No vehicles available for your license type.\n";
    }

    string choice;
    cout << "Do you want to update details (yes or no)? ";
    cin >> choice;
    if (choice == "yes") {
        u1.update_details();
        cout << "\nUpdated vehicles available:\n";
        found = false;
        for (int i = 0; i < vehicleCount; i++) {
            if (u1.get_licence_type() == vehicles[i]->elig_licence) {
                vehicles[i]->showDetails();
                found = true;
            }
        }
        if (!found) {
            cout << "No vehicles available for your license type after update.\n";
        }
    }

    for (int i = 0; i < vehicleCount; i++) {
        delete vehicles[i];
    }
    delete[] vehicles;

    return 0;
}
