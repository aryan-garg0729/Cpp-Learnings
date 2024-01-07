#include<iostream>
using namespace std;
class vehicle{
    public:
    int maxspeed; //accessible anywhere

    private:
    string color; //accessible only in this class

    protected:
    int numTyres; //accessible in this and its inherited classes
};

//a class can inherit only public and protected properties

class v1:public vehicle{
    /* by public access modifier, protected properties are inherited as protected
      and public as public */

    //this class has inherited protected numtyres, and public maxspeed
    public:
    int grears;
};

class v2:protected vehicle{
    /* by protected access modifier, protected and public both properties are inherited as 
       protected*/

    //this class has inherited protected numtyres, and protected maxspeed
    public:
    int grears;
};

class v3:private vehicle{
    /* by private access modifier, protected and public both properties are inherited as 
       private*/

    //this class has inherited private numtyres, and private maxspeed
    public:
    int grears;
};

