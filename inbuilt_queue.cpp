#include <iostream>
using namespace std;
#include<queue>
int main(){
    /**
     * push(element) ->enqueue()
     * pop() -> dequeue(): does not return the deleted element. It just deletes the front element[dont pop empty queue]
     * front() ->returns the first element[don't try to compare s.front() if queue is empty as we cant compare NULL]
     * size()  ->returns size
     * empty()  ->returns true or false    
    */

   queue<int> s;
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(5);
   s.push(67);
   s.push(7);

   cout<<s.front()<<endl;
   s.pop();
   cout<<s.front()<<endl;
   cout<<s.size()<<endl;
   cout<<s.empty()<<endl;
   

    return 0;
}