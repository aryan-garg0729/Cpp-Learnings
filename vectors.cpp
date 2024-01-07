#include <iostream>
using namespace std;
#include<vector>
int main(){
    // Vector are inbuilt dynamic array
    // vector<int>*v = new vector<int>;  //dynamic allocation
    vector<int> v;
    //always use push_back function to add a new element
    v.push_back(1);  //1
    v.push_back(2);  //1 2
    v.push_back(3);  //1 2 3
    v.push_back(4);  //1 2 3 4
    v.push_back(5);  //1 2 3 4 5

    v.pop_back();  //pops the last element --> 1 2 3

    //use v[] to "access" and "update" elements only
    cout<<v[2]<<endl;
    v[3] = 7;

    cout<<v.size()<<endl;

    cout<<v.at(3)<<endl;  //gives element at that index. Unlike v[] it produces error if the element is out of index

    for(int i = 0;i<100;i++){
        cout<<"cap: "<<v.capacity()<<endl;
        cout<<"size: "<<v.size()<<endl;
        v.push_back(i+1);
    }

    /*When a vector is passed to a function, a copy of the vector is created. This new copy of the vector is then used in the function and thus, any changes made to the vector in the function do not affect the original vector.

    insert() – It inserts new elements before the element at the specified position
    erase() – It is used to remove elements from a container from the specified position or range.
    */
   vector<int>v1;
    for(int i = 0;i<10;i++){
        v1.push_back(i+1);
    }
    for(int i = 0;i<10;i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    v1.insert(v1.begin()+2,68); //inserts element at index 2
    cout<<v1[2]<<endl;

    v1.erase(v1.begin()+6); //deletes element at index 6

    for(int i = 0;i<10;i++){
        cout<<v1[i]<<" ";
    }

    // 2d vector
    vector<vector<int>> vect{{1, 2}, {4, 5, 6}, {7, 8, 9, 10} }; 


    return 0;
}