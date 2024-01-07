#include<iostream>
using namespace std;
#include<stack>
bool isBalanced(string expression) 
{
    stack<char> s;  //inbuilt stack

    for(int i = 0;expression[i]!='\0';i++){
        if(expression[i]=='('||expression[i]=='['||expression[i]=='{'){
            s.push(expression[i]); 
            continue;
        }

        if(s.empty()&&(expression[i]==')'||expression[i]==']'||expression[i]=='}')){
            return false;
        }

        if(!s.empty()){
            if(s.top()=='('&&expression[i]==')'){
                s.pop();
            }
            else if(s.top()=='['&&expression[i]==']'){
                s.pop();
            }
            else if(s.top()=='{'&&expression[i]=='}'){
                s.pop();
            }
        }
    }

    if(s.empty()){
        return true;
    }
    
    return false;
}

void reverseStack(stack<int> &input, stack<int> &extra) {
    if(input.empty()){
        return;
    }
    int a = input.top();
    input.pop();
    
    reverseStack(input,extra);
    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }
    input.push(a);
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
    return;
}

bool checkRedundantBrackets(string expression) {
	stack<char> s;
    for(int i = 0;expression[i]!='\0';i++){
        if(expression[i]!=')'){
            s.push(expression[i]);
        }
        else{
            int count = 0;
            while(s.top()!='('){
                count++;
                s.pop();
            }
            if(count<=1){
                return true;
            }
            s.pop();
        }
    }
    return false;
}

int countBracketReversals(string input) {
	if(input.length()%2!=0){
        return -1;
    }
    stack<char> s;
    for(int i = 0;i<input.length();i++){
    	if(s.empty()){
            s.push(input[i]);
    	}
        else if(s.top()=='{' && input[i]=='}'){
            s.pop();
        }
        else{
            s.push(input[i]);
        }
    }
    int count = 0;
    while(!s.empty()){
        char c1,c2;
        c1 = s.top();
        s.pop();
        c2 = s.top();
        s.pop();
        if(c1!=c2){
            count = count+2;
        }
        else{
            count++;
        }
    }
    return count;
}

int* stockSpan(int *price, int size)  {
	int*arr= new int[size];
    // int bp;
	stack<int> s;
    for(int i = 0;i<size;i++){
        if(i==0){
            s.push(i);
            // bp = price[0];
            arr[0] = 1;
        }
        else if(!s.empty()){
        	if(price[s.top()]>=price[i]){
            
            	arr[i] = i-s.top();
            	s.push(i);
        	}
        	else{
            	while(!s.empty()&&price[s.top()]<price[i]){
                	s.pop();
            	}
            	if(s.empty()){
            	    arr[i] = i+1;
                    // bp = arr[i];
                    s.push(i);
            	}
            	else{
            	    arr[i]=i-s.top();
                    s.push(i);
            	}
        	}
    }
    else{
            s.push(i);
            arr[i] = i+1;
        }
    }
    return arr;
}


