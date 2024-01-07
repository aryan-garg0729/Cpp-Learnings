#include<iostream>
using namespace std;

class Fraction{

private:
int num;
int deno;

public:

Fraction(int num,int deno){ //constructor to set Nr and Dr
    this-> num = num;   //using this M1
    (*this).deno = deno;  //using this M2
}

void simplify(){
    int gcd = 1;
    int j = min(num,deno);
    for(int i =1;i<=j;i++){
        if(num%i==0 && deno%i==0){
            gcd = i;
        }
    }
    num/=gcd;
    deno/=gcd;
}

                    //       + operator
Fraction operator+(Fraction const & f2)const{   //f2 is made const so that no changes can be made in f2. It is passed by reference so that no unnecessary copy is made
    int a = num*f2.deno;
    int b = deno*f2.num;
    Fraction fnew(a+b,deno*f2.deno);
    fnew.simplify();
    return fnew;
}
/*operators can be overloaded by using the key word "operator"
  The value before operator goes as "this" and after it goes as the "argument"
  Fraction f3 = f1+f2; here f1 goes as "this" and f2 as arg 
        same as --> f1.sum(f2)    
*/

//                          == operator
bool operator==(Fraction const & f2){
    simplify();
    Fraction f=f2;
    f.simplify();
    if(num==f.num && deno==f.deno){
        return true;
    }
    return false;
}

                    // pre increment(++)

// Fraction operator++(){    
// /*this fxn cannot calculate more than one ++ operator (concept:- buffer memory see notes!!!)*/
//     num += deno;
//     simplify();
//     return *this;   //here we will use "*this" and not "this" as "this" is a pointer and "*this" is the fraction object pointed by the pointer "this"
// }


Fraction& operator++(){     /*NOTE: here the return type is a REFERENCE of the object.Because of
                            this it is capable of calculating multiple ++ operations.            e.g. f3 = ++(++f4);*/
    num += deno;
    simplify();
    return *this;   //here we will use "*this" and not "this" as "this" is a pointer and "*this" is the fraction object pointed by the pointer "this"
}
                    // Post increment(++)

Fraction operator++(int){
    Fraction fnew = *this;
    num = num+deno;
    simplify();
    fnew.simplify();
    return fnew;
}

                //       Short hand operator(+=)

// void operator+=(Fraction f2){//works well but nesting not possible as it does not return anything
//     int a = num*f2.deno;
//     int b = deno*f2.num;
//     num = a+b;
//     deno = deno*f2.deno;
//     simplify();
// }
Fraction& operator+=(Fraction const & f2){ //returning by reference (buffer memory!!)
    int a = num*f2.deno;
    int b = deno*f2.num;
    num = a+b;
    deno = deno*f2.deno;
    simplify();
    return *this;
}

void print(){
    cout<<num<<"/"<<deno<<endl;
}

};
int main(){

    Fraction f1(2,8);
    Fraction f2(1,4);
    Fraction f4(1,4);
    Fraction f5(8,4);

                    //      sum
    Fraction f3 = f1+f2;
    f3.print();


                    //    == operator
    bool b = f1==f2;
    cout<<b<<endl;


                //       pre increment
    f3 = ++f1; //this assignment is possible as the return type is fraction and not void so ++f1 returns a fraction
    f1.print();
    f3.print();

    f3 = ++(++(++f4));
    f3.print();
    f4.print();
                //       post increment

    f3 = f5++;     //nesting of post increment operator is not possible even the inbuilt post inc does not support nesting
    f3.print();
    f5.print();
                //       Short hand operator(+=)
    f5+=f1;
    f1.print();
    f5.print();
    (f5+=f1)+=f1;
    f1.print();
    f5.print();




    return 0;
}