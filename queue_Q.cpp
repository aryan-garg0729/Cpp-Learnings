#include <iostream>
using namespace std;
#include<queue>
void reverseQueue(queue<int> &input) {
	if(input.empty()){
        return;
    }
    int a = input.front();
    input.pop();
    reverseQueue(input);
    input.push(a);
    return;
}

