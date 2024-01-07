#include <iostream>
using namespace std;
int main(){
    // cout<<"it will be printed";
    // cout<<"\n"; //to press enter

    // //above two lines are same as:-
    // cout<<"it will be printed"<<"\n";

    // //"\n" can also be written as endl
    // cout<<"it will be printed"<<endl;

    // int a = 7;
    // int b = 9;
    // int c = a+b;
    // cout << c << endl;
    
    // char d = 'x';
    // cout << d << endl;
    // cout<<'d'<<endl;

    // float f = 7.98;
    // bool  bl = true;
    // cout<<bl<<"\n";  //prints 1 ,not true.Similarly 0 for false

    // int size = sizeof(f);
    // cout<<size<<endl;

    // //taking input
    // int p,q;
    // cout<<"enter numbers\n";
    // cin >> p >> q;
    // cout<<p+q;

    //typecasting and ASCII value
/*  char c = 'f'; --> here char stores the ascii value of 'f' in
    binary form
    char can store only one byte i.e. 8 bits
*/
    // int i = 97;
    // char c = i;//--> here char will store the character corresponding to ASCII value 97 i.e. 'a'
    // cout << c << endl;

    // int j = 299;
    // char c1 = j;//--> here 299 will be converted to binary i.e. 100101011 now since char can store only 1byte i.e. 8bits so it will store 00101011 which is 43. Now char corresponding to ASCII value 43 is printed i.e. '+'
    // cout << c1 << endl;

    // char v = 'A';
    // int r = v; //here int r will store ASCII value of char 'A' i.e. 65
    // cout << r<< endl;

    // float fl = 1.2;
    // int a1 = fl;//here int a1 will only store the integral part of decimal or floating point numbers
    // cout << a1 << endl;

    // int i = 10;
    // char c = 'a';//--> ASCII value 97
    // cout<< c+i <<endl; //prints 97+10 --> 107

    // int i = 202;
    // char c = 'a';//--> ASCII value 97
    // char h = c+i;//97+202 --> 299 --> convert to binary, take last 1 byte,convert to decomal no.,then take char corresponding to that ASCII value --> '+'
    // cout<< h <<endl;

    //          Storing signed numbers
/* * generally int is of 4 bytes
   * for signed int one bit is stored for sign of the no.
   * Lets consider a system in which int is of 4 bits _ _ _ _
   * here the first bit is sign bit 1 for +ive & 0 for -ive
   * so the max +ive no. that can be stored is 0111 (0 for +ive) i.e.
   4+2+1 = 7 = (2^(n-1))-1
   * the max -ive no. that can be stored is 1111 (1 for -ive) i.e.
   -(4+2+1) = -7 = -((2^(n-1))-1)
   * problem here is tha twe have 2 representations for 0 which are 
   1000(-0), 0000(+0)

   *so for +ive nos. convert to binary and first reserved bit is 0
   *for -ive nos.:-
    1) forget -ive sign 
    2) convert to binary
    3) take 2's complement
        2's complement:- 
        * take 1's complement(replace 0 with 1 and vice versa)
        * add 1 (note : 1+1 = 10 ) 
    4) store the result of step 3

    *eg: -5--> 5 in binary is 0101
    1's complement--> 1010
    add 1--> 1011 answer
    *eg: -6(8 bit)--> 6 in binary is 00000110
    1's complement--> 11111001
    add 1--> 11111010 answer

    *to get the no. back, take 2's complement again if no is -ive

    eg: 11111010-> since first bit 1 so its a -ive no.
    2's comp --> 00000101 + 1 = 00000110
    convert to decimal--> 4+2 =6 so it is -6 answer

    eg: 0110-> since first bit 0 so its a +ive no.
    convert to decimal--> 4+2 =6 answer

    *finally range is -2^(n-1) to (2^(n-1))-1

    * if unsigned is written then treat everything +ive i.e. 1111 is +ive and no bit is resreved for sign 1111 is 15. Range becomes 
    0 to (2^(n))-1
*/
    // unsigned int b = -6;
    // cout << b;
    //convert to binary as we saw --> 11....111010
    //now it is assigned to unsigned int so now treat that no. as unsigned and it will lead to a large no. 

    // printf("h");
    int arr[] = {3,5,5,6};
    cout<<sizeof(arr)<<endl;
    cout<<arr+2;
}