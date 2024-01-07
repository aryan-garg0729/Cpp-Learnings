#include<iostream>
using namespace std;

            // ***** ASSIGNMENT *****

/* Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.*/

bool checkAB(char input[]) {
	
    if(input[0]=='\0'){
        return true;
    }
    bool b = true;
    if(input[0]=='a'){
        if((input[1] == '\0')||(input[1]=='b'&&input[2]=='b')||(input[1] == 'a')){
            if(input[1]=='a'){
                b  = checkAB(input+1);
                return b;
            }
            else if(input[1] == '\0'){
                b= true;
                return true;
            }
            b  = checkAB(input+3);         
            return b;
        }
        b = false;
        return b;
    }   
    b = false;
    return b;
}





/*A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.*/

int staircase(int n){
    
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    int count = 0;
    count += staircase(n-1)+staircase(n-2)+staircase(n-3);
    return count;
    
}


/*Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :

Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)*/

// input - input array
// size - length of input array
// element - value to be searched

int binarySearch(int input[], int size, int element) { 
    if(size<=0){
        return -1;
    }
    int mid = (size-1)/2;
    if(element==input[mid]){
        return mid;
    }
    else if(element>input[mid]){ 
        int i = binarySearch(input+mid+1,size-mid-1,element);
        if(i==-1){
            return -1;
        }
        return mid+1+i;
    }
    else if(element<input[mid]){
        int i = binarySearch(input,mid,element);
        if(i==-1){
            return -1;
        }
        return i;
    }

}



/*Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)*/

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subset(int input[], int n, int output[][20]) {
    if(n==0){
        output[0][0] = 0;
        return 1;
    }
    int no_of_rows = subset(input,n-1,output);
    for(int i =0;i<no_of_rows;i++){
        for(int j = 0;j<20;j++){
            output[no_of_rows+i][j] = output[i][j];
            
        }
        int num = ++output[no_of_rows+i][0];
        output[no_of_rows+i][num] = input[n-1];
    }
    return 2*no_of_rows; 

}


/*Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)*/

void psoa(int input[], int size, int output[],int size2){
    if(size==0){
        for(int i = 0;i<size2;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    int newOutput[1000];
    for(int i = 0;i<size2;i++){
        newOutput[i] = output[i];
    }
    newOutput[size2] = input[0];
    psoa(input+1,size-1,output,size2);
    psoa(input+1,size-1,newOutput,size2+1);
    
}

void printSubsetsOfArray(int input[], int size) {
	int output[1000];
    psoa(input,size,output,0);
    return;
}



/*Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K */

int sum(int arr[],int size){
    int sum = 0;
    for(int i = 0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}
void psoa(int input[], int size, int output[],int size2,int k){
    if(size==0){
        int s = sum(output,size2);
        if(s==k){
        for(int i = 0;i<size2;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        }
        return;
    }
    int newOutput[1000];
    for(int i = 0;i<size2;i++){
        newOutput[i] = output[i];
    }
    newOutput[size2] = input[0];
    psoa(input+1,size-1,output,size2,k);
    psoa(input+1,size-1,newOutput,size2+1,k);
    
}
void printSubsetSumToK(int input[], int size, int k) {
    
    int output[1000];
    psoa(input,size,output,0,k);
    return;
    
}



/*Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10*/

#include <string.h>
using namespace std;
char code(string s){
    if(s.size()==1){
        int i = s[0]-'0';
        char c = 'a'+i-1;
        return c;
    }
    else if(s.size()==2){
        int i = s[0]-'0';
        int j = s[1]-'0';
        int num = i*10+j;
        if(num<27){
            char c = 'a'+num-1;
        	return c;  
        }
        return '?';
    }
    
}
int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    
    if(input[0] == '\0'){
        output[0] = "";
        return 1;
    }
    int a1 = getCodes(input.substr(1),output);
    for(int i = 0;i<a1;i++){
        output[i] = code(input.substr(0,1))+output[i];
    }
    if(input.size()>=2){
    	string s = input.substr(0,2);
    	char cod = code(s);
    	if(cod!='?'){
        	int a2 = getCodes(input.substr(2),output+a1);
    		for(int i = a1;i<a1+a2;i++){
    		output[i] = cod+output[i];
    		}
    		return a1+a2;
    	}
	}
    return a1;
    
    
}



/*Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S*/

#include <string.h>
using namespace std;
char code(string s){
    if(s.size()==1){
        int i = s[0]-'0';
        char c = 'a'+i-1;
        return c;
    }
    else if(s.size()==2){
        int i = s[0]-'0';
        int j = s[1]-'0';
        int num = i*10+j;
        if(num<27){
            char c = 'a'+num-1;
        	return c;  
        }
        return '?';
    }
    
}

void papc(string input,string output){
    if(input[0] == '\0'){
        cout<<output<<endl;
        return;
    }
    string newOutput = output;
    string s = input.substr(0,1);
    char c = code(s);
    newOutput = newOutput+c;
    papc(input.substr(1),newOutput);
    if(input.size()>=2){
        string s = input.substr(0,2);
        char c = code(s);
        if(c != '?'){
        	output = output+c;
        	papc(input.substr(2),output);
        }
    }
    return;
}

void printAllPossibleCodes(string input) {
    
    papc(input,"");
    return;
    
}


/*Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S*/

#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	
    if(input.size() == 1){
        output[0] = input;
        return 1;
    }
    int count  = returnPermutations(input.substr(1),output);
    int c = count;
    int sm1 = input.size()-1;
    for(int i = 0;i<sm1;i++){
        for(int j = 0;j<c;j++){
            output[count+j] = output[j];
        }
        count+=c;
    }
    for(int i = 0;i<input.size();i++){
        for(int j = 0;j<c;j++){
            output[i*(c)+j].insert(i,input.substr(0,1));
        }
    }
    return count;
}

/*print permutations*/
void pp(string input,string output){
    
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    string out = output;
    for(int i = 0;i<input.length();i++){
        string newinp = "";
        for(int j = 0;j<input.length();j++){
            if(i!=j){
                newinp+=input[j];
            }
        }
        output+=input[i];
        pp(newinp,output);
        output = out;
    }
    
}
void printPermutations(string input){
    string output = "";
    pp(input,output);
}

/*tower of hanoi*/
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if(n==1){
        cout<<source<<" "<<destination<<endl;
        return;
    }
    if(n==0){
        return;
    }
    towerOfHanoi(n-1,source,destination,auxiliary);
    cout<<source<<" "<<destination<<endl;
    towerOfHanoi(n-1,auxiliary,source,destination);
    return;

}
