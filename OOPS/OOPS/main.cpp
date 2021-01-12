#include <iostream>
using namespace std;

class ComplexNumbers {

private:
    int real;
    int imaginary;

public:
    //Parameterized constructor
    ComplexNumbers(int real, int imaginary) {
        this -> real = real;
        this -> imaginary = imaginary;
    }
    
    //Print the complex number
    void print() {
        cout << real << " + i" << imaginary;
    }
    
    //Adding two complex numbers
    void plus(ComplexNumbers const &c2) {
        real = real + c2.real;
        imaginary = imaginary + c2.imaginary;
    }
    
    //Multiply two complex numbers.
    void multiply(ComplexNumbers const &c2) {
        int real_temp = (real * c2.real) - (imaginary * c2.imaginary);
        int imaginary_temp = (real * c2.imaginary) + (imaginary * c2.real);
        real = real_temp;
        imaginary = imaginary_temp;
    }
};

class Student {
    
    static int total;
    
public:
    int age;
    int roll;
    
    Student() {
        total++;
    }
    
    void get_total() {
        return total;
    }
};
int Student::total = 0;

int main() {
    
    Student s1,s2,s3,s4,s5;
    cout << Student::total << endl;
    
//    int real1, imaginary1, real2, imaginary2;
//
//    cin >> real1 >> imaginary1;
//    cin >> real2 >> imaginary2;
//
//    ComplexNumbers c1(real1, imaginary1);
//    ComplexNumbers c2(real2, imaginary2);
//
//    int choice;
//    cin >> choice;
//
//    if(choice == 1) {
//        c1.plus(c2);
//        c1.print();
//    }
//    else if(choice == 2) {
//        c1.multiply(c2);
//        c1.print();
//    }
//    else {
//        return 0;
//    }
}
