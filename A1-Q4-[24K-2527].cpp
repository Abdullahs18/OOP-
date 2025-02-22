#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int studentID;
    string name;
    int cardNumber;
    double balance;
    string assignedStop;
    bool isActive;

public:
    Student() {
        studentID = 0;
        name = "";
        cardNumber = 0;
        balance = 0.00;
        assignedStop = "";
        isActive = false;
    }

    Student(int id, string name, int card) {
        studentID = id;
        this->name = name;
        cardNumber = card;
        balance = 0.0;
        isActive = false;
    }

    void payFee(double amount) {
        balance += amount;  // Add payment to balance
        isActive = true;
        cout << "Payment successful! Balance: $" << balance << endl;
    }

    void assignStop(string stop) {
        assignedStop = stop;
    }

    void tapCard() {
        if (isActive) {
            cout << name << " tapped the card. Entry granted!" << endl;
        } else {
            cout << "Card not active. Please pay the fee." << endl;
        }
    }

    void displayDetails() const {
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Assigned Stop: " << assignedStop << endl;
        cout << "Card Status: " << (isActive ? "Active" : "Inactive") << endl;
    }

    int getID() const {
        return studentID;
    }
};

class BusStop {
private:
    string stopName;
    Student* students[100];
    int studentCount;

public:
    BusStop() {
        stopName = "";
        studentCount = 0;
    }

    BusStop(string name) {
        stopName = name;
        studentCount = 0;
    }

    void addStudent(Student* student) {
        if (studentCount < 100) {
            students[studentCount++] = student;
            student->assignStop(stopName);
        } else {
            cout << "Stop is full!\n";
        }
    }

    void displayDetails() const {
        cout << "Stop Name: " << stopName << endl;
        cout << "Number of Students: " << studentCount << endl;
        for (int i = 0; i < studentCount; i++) {
            students[i]->displayDetails();
        }
    }
};

class Route {
private:
    int routeID;
    BusStop* stops[20];
    int stopCount;

public:
    Route() {
        routeID = 0;
        stopCount = 0;
    }

    Route(int id) {
        routeID = id;
        stopCount = 0;
    }

    void addStop(BusStop* stop) {
        if (stopCount < 20) {
            stops[stopCount++] = stop;
        } else {
            cout << "Route is full! Cannot add more stops.\n";
        }
    }

    void displayRouteDetails() const {
        cout << "Route ID: " << routeID << " has " << stopCount << " stops." << endl;
        for (int i = 0; i < stopCount; i++) {
            stops[i]->displayDetails();
        }
    }
};

class Bus {
private:
    int busID;
    Route* assignedRoute;

public:
    Bus() {
        busID = 0;
        assignedRoute = nullptr;
    }

    Bus(int id) {
        busID = id;
        assignedRoute = nullptr;
    }

    void assignRoute(Route* route) {
        assignedRoute = route;
    }

    void displayBusDetails() const {
        cout << "Bus ID: " << busID << " is assigned to route "
             << (assignedRoute ? "Yes" : "No") << endl;
    }
};

class TransportSystem {
private:
    Student students[100];
    int studentCount;

public:
    TransportSystem() {
        studentCount = 0;
    }

    void registerStudent(int id, string name, int card) {
        if (studentCount < 100) {
            students[studentCount++] = Student(id, name, card);
            cout << "Student registered successfully!" << endl;
        } else {
            cout << "Cannot register more students." << endl;
        }
    }

    void processPayment(int studentID, double amount) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getID() == studentID) {
                students[i].payFee(amount);
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
};

int main() {
    TransportSystem ts;

    ts.registerStudent(1, "Abdullah", 123);
    ts.registerStudent(2, "Zymal", 567);

    BusStop stop1("Stop A");
    BusStop stop2("Stop B");

    Route route1(56);
    route1.addStop(&stop1);
    route1.addStop(&stop2);

    Bus bus1(4);
    bus1.assignRoute(&route1);

    cout << "\nDisplay Route Details:\n";
    route1.displayRouteDetails();

    cout << "\nDisplay Bus Details:\n";
    bus1.displayBusDetails();

    ts.processPayment(1, 500.0);  

    return 0;
}
