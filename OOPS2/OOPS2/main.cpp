/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Polynomial {

public:
    
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;

    //Default Constructor
    Polynomial() {
        degCoeff = new int[5];
        capacity = 5;
        for (int i = 0; i < 5; i++) {
            degCoeff[i] = 0;
        }
    }
    
    //Copy Constructor
    Polynomial(Polynomial const &p1) {
        degCoeff = new int[p1.capacity];
        capacity = p1.capacity;
        for (int i = 0; i < p1.capacity; i++) {
            degCoeff[i] = p1.degCoeff[i];
        }
    }
    
    //Copy assignment operator
    void operator=(Polynomial const &p1) {
        degCoeff = new int[p1.capacity];
        capacity = p1.capacity;
        for (int i = 0; i < p1.capacity; i++) {
            degCoeff[i] = p1.degCoeff[i];
        }
    }
    
    //Set the coefficient
    void setCoefficient(int const &degree, int const &coeff) {
        if (degree < capacity) {
            degCoeff[degree] = coeff;
        }
        else {
            int * newDegCoeff = new int[2 * capacity];
            for (int i = 0; i < 2 * capacity; i++) {
                newDegCoeff[i] = 0;
            }
            for (int i = 0; i < capacity; i++) {
                newDegCoeff[i] = degCoeff[i];
            }
            degCoeff = newDegCoeff;
            capacity *= 2;
            setCoefficient(degree, coeff);
        }
    }
    
    //p3 = p1 + p2.
    Polynomial operator + (Polynomial const &p2) {
        Polynomial p3;
        p3.capacity = (capacity > p2.capacity) ? capacity : p2.capacity;
        p3.degCoeff = new int[p3.capacity];
        
        for (int i = 0; i < p3.capacity; i++) {
            p3.degCoeff[i] = 0;
        }
        
        int i = 0, j = 0, k = 0;
        while (i < capacity && j < p2.capacity) {
            p3.degCoeff[k] = degCoeff[i] + p2.degCoeff[j];
            i++;
            j++;
            k++;
        }
        
        while (i < capacity) {
            p3.degCoeff[k] = degCoeff[i];
            i++;
            k++;
        }
        
        while (j < p2.capacity) {
            p3.degCoeff[k] = p2.degCoeff[j];
            j++;
            k++;
        }
        
        return p3;
    }
    
    //p3 = p1 - p2.
    Polynomial operator-(Polynomial const &p2) {
        Polynomial p3;
        p3.capacity = (capacity > p2.capacity) ? capacity : p2.capacity;
        p3.degCoeff = new int[p3.capacity];
        
        for (int i = 0; i < p3.capacity; i++) {
            p3.degCoeff[i] = 0;
        }
        
        int i = 0, j = 0, k = 0;
        while (i < capacity && j < p2.capacity) {
            p3.degCoeff[k] = degCoeff[i] - p2.degCoeff[j];
            i++;
            j++;
            k++;
        }
        
        while (i < capacity) {
            p3.degCoeff[k] = degCoeff[i];
            i++;
            k++;
        }
        
        while (j < p2.capacity) {
            p3.degCoeff[k] = p2.degCoeff[j];
            j++;
            k++;
        }
        
        return p3;
    }
    
    //p3 = p1 * p2.
    Polynomial operator*(Polynomial const &p2) {
        Polynomial p3;
        p3.capacity = capacity + p2.capacity;
        p3.degCoeff = new int[p3.capacity];
        
        for (int i = 0; i < p3.capacity; i++) {
            p3.degCoeff[i] = 0;
        }
        
        for (int i = 0; i < capacity; i++) {
            if (degCoeff[i] != 0) {
                for (int j = 0; j < p2.capacity; j++) {
                    if (p2.degCoeff[j] != 0) {
                        p3.degCoeff[i + j] = p3.degCoeff[i + j] + (degCoeff[i] * p2.degCoeff[j]);
                    }
                }
            }
        }
        
        return p3;
    }
    
    //Print the polynomial.
    void print() const{
        for (int i = 0; i < capacity; i++) {
            if (degCoeff[i] != 0) {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
};


//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}

