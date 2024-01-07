#include<iostream>
using namespace std;
#include <string.h>

class student{
    int age;
    char*name;
    public:
    student(int age,char*name){ 
        this->age = age;
        this->name = name;   //SHALLOW COPY:-it has not made a permanent copy but is just pointing towards an array.Copy constructor does shallow copy

            //            DEEP COPY:-
        // this->name = new char[strlen(name)+1];//allocating array dynamically
        // strcpy(this->name,name);   // storing name

    }

    //DEEP COPY Constructor: that takes student obj as arg, replaces default shallow copy constructor
    student(student const & s){
        this->age = s.age;
        this->name = new char[strlen(name)+1];//allocating array dynamically
        strcpy(this->name,s.name);   // storing name
    }

    void display(){
        cout<<name<<" "<<age<<endl;
    }
};


int main(){
    char name[] = "abcd";
    student s1(12,name);
    s1.display();

    name[0] = 'x';
    student s2(23,name);
    s1.display();  /*it should display 'abcd' but displays 'xbcd'.This is because the
                    char pointer in class is pointing towards the array in main and changes made in array will also be refelected there*/
    s2.display();  //displays 'xbcd'

return 0;
}