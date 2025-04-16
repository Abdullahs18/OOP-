#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    int vehicleID;
    static int totalDeliveries;

public:
    Vehicle(int id) : vehicleID(id) {}
    virtual void calculateRoute() = 0;
    virtual void estimateDeliveryTime() = 0;
    static int getTotalDeliveries() { return totalDeliveries; }
    virtual void move() = 0;
    friend bool operator==(const Vehicle& v1, const Vehicle& v2);
};

int Vehicle::totalDeliveries = 0;

class RamzanDrone : public Vehicle {
public:
    RamzanDrone(int id) : Vehicle(id) {}
    void calculateRoute() override { cout << "Aerial route for high-speed delivery." << endl; }
    void estimateDeliveryTime() override { cout << "Delivery time: 30 minutes." << endl; }
    void move() override { cout << "Flying at high speed." << endl; }
};

class RamzanTimeShip : public Vehicle {
public:
    RamzanTimeShip(int id) : Vehicle(id) {}
    void calculateRoute() override { cout << "Time travel route." << endl; }
    void estimateDeliveryTime() override { cout << "Delivery time: 1 hour." << endl; }
    void move() override { cout << "Travelling through time." << endl; }
};

class RamzanHyperPod : public Vehicle {
public:
    RamzanHyperPod(int id) : Vehicle(id) {}
    void calculateRoute() override { cout << "Underground tunnel route." << endl; }
    void estimateDeliveryTime() override { cout << "Delivery time: 45 minutes." << endl; }
    void move() override { cout << "Moving at high speed underground." << endl; }
};

bool operator==(const Vehicle& v1, const Vehicle& v2) {
    return v1.vehicleID == v2.vehicleID;
}

class ControlPanel {
public:
    void command(const string& cmd, int packageID) {
        if (cmd == "Deliver") {
            cout << "Delivering package ID: " << packageID << endl;
        }
    }

    void command(const string& cmd, int packageID, int urgencyLevel) {
        if (cmd == "Deliver") {
            if (urgencyLevel == 1) {
                cout << "Urgent delivery package ID: " << packageID << endl;
            }
            else {
                cout << "Normal delivery package ID: " << packageID << endl;
            }
        }
    }
};

int main() {
    RamzanDrone drone1(1);
    RamzanTimeShip timeShip1(2);
    RamzanHyperPod hyperPod1(3);

    drone1.calculateRoute();
    timeShip1.calculateRoute();
    hyperPod1.calculateRoute();

    drone1.estimateDeliveryTime();
    timeShip1.estimateDeliveryTime();
    hyperPod1.estimateDeliveryTime();

    drone1.move();
    timeShip1.move();
    hyperPod1.move();

    ControlPanel panel;
    panel.command("Deliver", 101);
    panel.command("Deliver", 102, 1);

    return 0;
}
