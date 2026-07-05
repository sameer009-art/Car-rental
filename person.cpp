#include <iostream>
#include <map>
#include <string>
#include <ctime>

using namespace std;

// -------------------- PERSON BASE CLASS --------------------
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
