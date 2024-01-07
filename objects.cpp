#include <vector>
#include <climits>
#include<iostream>
using namespace std;
#include "classes.h"

int main(){
        // **********fraction**********
  {
    Fraction f1(10,2);
    Fraction f2(15,4);
    Fraction f3(7,2);
    Fraction f4(15,14);
    Fraction f5(7,12);
    Fraction f6(5,14);
    f1.sum(f2);
    f1.print();
    f3.mul(f4);
    f3.print();
    f5.div(f6);
    f5.print();
  }

       //********** complex numbers ***********
  {
      ComplexNumbers z1(2,4);
      ComplexNumbers z2(3,5);
      ComplexNumbers z3(12,4);
      ComplexNumbers z4(3,15);
      z1.multiply(z2);
      z3.plus(z4);
      z1.print();
      z3.print();

  }

     //******** Polynomial *************
  {int count1,count2,choice;
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
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            // result.print();
            break;
            
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

/*   test case
  3 
  3 1 7
  1 2 3
  2
  2 1
  7 8
  1   change this 1 to 1,2,3,4,5
*/
  }

    return 0;
}