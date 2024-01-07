#include <iostream>
using namespace std;

//declaring our functions and classes that will be friend of truck class
class Bus {
	public :
		void print();
};

void test();

class Truck {
	private :
		int x;

	protected :
		int y;

	public :
        int z;

        //to make something a friend of some class that must be declared before creating class thus bus ,test are declared before creating truck class

        friend class Bus;  //making class bus a friend of truck, all fxn of bus are now truck's friend
        friend void Bus :: print();  //making print fxn of class bus a friend of truck
        friend void test(); //making any random fxn a friend of truck
};


// Defining our friend functions
void Bus :: print() {
	Truck t;//since we need to access truck class thus truck must be defined before this fxn
	t.x = 10;
	t.y = 20;
	cout << t.x << " " << t.y << endl;
}

void test() {
	// Access truck private
	Truck t;//since we need to access truck class thus truck must be defined before this fxn
	t.x = 10;
	t.y = 20;
	cout << t.x << " " << t.y << endl;

}

int main() {
	Bus b;
	b.print();

	test();

}
