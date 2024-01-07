// #include"classes.h"  //files saved with ".h" extension cannot have main() in them
#include <iostream>
using namespace std;
#include<stack>
int main(){
    /**
     * push(element)
     * pop()-> does not return the deleted element. It just deletes the top element[dont pop empty stack]
     * top()->returns the top element[don't try to compare s.top() if stack is empty as we cant compare NULL]
     * size()->returns size
     * empty()->returns true or false    
    */

   stack<int> s;
//    s.pop();
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(5);
   s.push(67);
   s.push(7);

   cout<<s.top()<<endl;
   s.pop();
   cout<<s.top()<<endl;
   cout<<s.size()<<endl;
   cout<<s.empty()<<endl;
   

    return 0;
}