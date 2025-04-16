#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    int userID;
    string name;
    int cardNumber;
    double balance;
    string assignedStop;
    bool isActive;

public:
    User(int id, string name, int card) : userID(id), name(name), cardNumber(card), balance(0.0), isActive(false) {}
    virtual void payFee(double amount) = 0;
    void assignStop(string stop) { assignedStop = stop; }
    void tapCard() const {
        if (isActive)
            cout << name << " tapped the card. Entry granted!" << endl;
        else
            cout << "Card not active. Please pay the fee." << endl;
    }
    void displayDetails() const {
        cout << "ID: " << userID << "\nName: " << name << "\nAssigned Stop: " << assignedStop
             << "\nCard Status: " << (isActive ? "Active" : "Inactive") << endl;
    }
    int getID() const { return userID; }
    bool operator==(const User& other) const { return userID == other.userID; }
};

class Student : public User {
public:
    Student(int id, string name, int card) : User(id, name, card) {}
    void payFee(double amount) override {
        balance += amount;
        isActive = true;
        cout << "Student payment successful! Balance: $" << balance << endl;
    }
};

class Teacher : public User {
public:
    Teacher(int id, string name, int card) : User(id, name, card) {}
    void payFee(double amount) override {
        balance += amount;
        isActive = true;
        cout << "Teacher payment successful! Balance: $" << balance << endl;
    }
};

class BusStop {
private:
    string stopName;
    User* users[100];
    int userCount;

public:
    BusStop(string name) : stopName(name), userCount(0) {}
    void addUser(User* user) {
        if (userCount < 100) {
            users[userCount++] = user;
            user->assignStop(stopName);
        } else {
            cout << "Stop is full!\n";
        }
    }
    void displayDetails() const {
        cout << "Stop Name: " << stopName << "\nNumber of Users: " << userCount << endl;
        for (int i = 0; i < userCount; i++) {
            users[i]->displayDetails();
        }
    }
};

class Route {
private:
    int routeID;
    BusStop* stops[20];
    int stopCount;

public:
    Route(int id) : routeID(id), stopCount(0) {}
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
    bool operator==(const Route& other) const { return routeID == other.routeID; }
};

class Bus {
private:
    int busID;
    Route* assignedRoute;

public:
    Bus(int id) : busID(id), assignedRoute(nullptr) {}
    void assignRoute(Route* route) { assignedRoute = route; }
    void displayBusDetails() const {
        cout << "Bus ID: " << busID << " is assigned to route " << (assignedRoute ? "Yes" : "No") << endl;
    }
};

int main() {
    Student s1(1, "Abdullah", 123);
    Teacher t1(2, "Dr. Zain", 567);

    BusStop stop1("Stop A");
    stop1.addUser(&s1);
    stop1.addUser(&t1);

    Route route1(56);
    route1.addStop(&stop1);

    Bus bus1(4);
    bus1.assignRoute(&route1);

    cout << "\nDisplay Route Details:\n";
    route1.displayRouteDetails();

    cout << "\nDisplay Bus Details:\n";
    bus1.displayBusDetails();

    s1.payFee(500.0);
    t1.payFee(1000.0);

    return 0;
}