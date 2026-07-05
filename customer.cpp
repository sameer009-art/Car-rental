#include <iostream>
#include <map>
#include <string>
#include <ctime>

using namespace std;

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
