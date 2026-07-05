#include <iostream>
#include <map>
#include <string>
#include <ctime>

using namespace std;



// -------------------- CAR CLASS --------------------
class Car {
private:
    int carId;
    string model;
    double rentPerHour;
    bool available;

public:
    Car() {}

    Car(int id, string model, double rent)
        : carId(id), model(model), rentPerHour(rent), available(true) {}

    int getId() const { return carId; }
    string getModel() const { return model; }
    double getRent() const { return rentPerHour; }
    bool isAvailable() const { return available; }

    void rentCar() { available = false; }
    void returnCar() { available = true; }

    void display() const {
        cout << "Car ID: " << carId
             << " | Model: " << model
             << " | Rent/Hour: ₹" << rentPerHour
             << " | Status: "
             << (available ? "Available" : "Rented")
             << endl;
    }
};
