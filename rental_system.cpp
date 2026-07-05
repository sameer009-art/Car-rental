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

// ---------------------PERSON BASED CLASS--------------
class Person {
protected:
    int id;
    string name;

public:
    Person() {}

    Person(int id, string name)
        : id(id), name(name) {}

    virtual void displayRole() = 0;

    int getId() const { return id; }
    string getName() const { return name; }

    virtual ~Person() {}
};

// -------------------- CUSTOMER CLASS --------------------
class Customer : public Person {
private:
    int rentedCarId;

public:
    Customer() {}

    Customer(int id, string name)
        : Person(id, name), rentedCarId(-1) {}

    void displayRole() override {
        cout << "Customer\n";
    }

    void rentCar(int carId) {
        rentedCarId = carId;
    }

    void returnCar() {
        rentedCarId = -1;
    }

    int getRentedCarId() const {
        return rentedCarId;
    }
};

// -------------------- RENTAL RECORD --------------------
class RentalRecord {
public:
    int customerId;
    int carId;
    time_t startTime;

    RentalRecord() {}

    RentalRecord(int custId, int cId) {
        customerId = custId;
        carId = cId;
        startTime = time(nullptr);
    }
};

// -------------------- CAR RENTAL SYSTEM --------------------
class CarRentalSystem {
private:
    map<int, Car> cars;
    map<int, Customer> customers;
    map<int, RentalRecord> activeRentals;

public:

    // Add Car
    void addCar(int id, string model, double rent) {
        cars[id] = Car(id, model, rent);
        cout << "Car added successfully.\n";
    }

    // Add Customer
    void addCustomer(int id, string name) {
        customers[id] = Customer(id, name);
        cout << "Customer registered successfully.\n";
    }

    // Display Cars
    void displayCars() {
        cout << "\nAvailable Cars:\n";
        for (auto &car : cars) {
            car.second.display();
        }
    }

    // Rent Car
    void rentCar(int customerId, int carId) {

        if (customers.find(customerId) == customers.end()) {
            cout << "Customer not found.\n";
            return;
        }

        if (cars.find(carId) == cars.end()) {
            cout << "Car not found.\n";
            return;
        }

        if (!cars[carId].isAvailable()) {
            cout << "Car already rented.\n";
            return;
        }

        cars[carId].rentCar();
        customers[customerId].rentCar(carId);

        activeRentals[customerId] =
            RentalRecord(customerId, carId);

        cout << "Car rented successfully.\n";
    }

    // Return Car
    void returnCar(int customerId) {

        if (activeRentals.find(customerId) ==
            activeRentals.end()) {
            cout << "No active rental found.\n";
            return;
        }

        RentalRecord record =
            activeRentals[customerId];

        time_t endTime = time(nullptr);

        double hours =
            difftime(endTime, record.startTime) / 3600.0;

        if (hours < 1)
            hours = 1;

        double bill =
            hours * cars[record.carId].getRent();

        cars[record.carId].returnCar();
        customers[customerId].returnCar();

        activeRentals.erase(customerId);

        cout << "\nRental Summary\n";
        cout << "Car ID: " << record.carId << endl;
        cout << "Hours Used: " << hours << endl;
        cout << "Total Bill: ₹" << bill << endl;
    }
};
