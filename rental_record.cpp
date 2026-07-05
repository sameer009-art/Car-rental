#include <iostream>
#include <map>
#include <string>
#include <ctime>

using namespace std;


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
