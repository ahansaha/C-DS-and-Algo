#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//Parent
class Vehicle {

private:
    int maxSpeed;
    
protected:
    int numTyres;
    
public:
    int color;
    
    Vehicle() {
        cout << "Vehicle's default constructor" << endl;
    }
    
    Vehicle(int z) {
        cout << "vehicle's parameterized constrcutor" << endl;
        maxSpeed = z;
    }
    
    ~Vehicle() {
        cout << "Vehicle's destructor" << endl;
    }
    
};

//Child
class Car : public Vehicle {
  
public:
    int numGears;
    
    Car() : Vehicle(5) {
        cout << "Car's default constructor" << endl;
    }
    
    ~Car() {
        cout << "Car's destructor" << endl;
    }
};



int main() {

    Car c;
    
    return 0;
}

