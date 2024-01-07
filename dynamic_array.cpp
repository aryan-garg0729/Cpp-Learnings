#include<iostream>
using namespace std;

class DynamicArray{
    int capacity;
    int * data;
    int index = 0;
    public:
    DynamicArray(){
        capacity = 5;
        data = new int[capacity];
    }
    DynamicArray(DynamicArray const & d1){   //deep copying constructor
        capacity = d1.capacity;
        index = d1.index;
        // data = d1.data;  // shallow copy
        data = new int[capacity];
        for(int i = 0;i<index;i++){
            data[i] = d1.data[i];
        }
    }
    void operator=(DynamicArray const & d1){//deep copying assignment operator
        capacity = d1.capacity;
        index = d1.index;
        // data = d1.data;  // shallow copy
        data = new int[capacity];
        for(int i = 0;i<index;i++){
            data[i] = d1.data[i];
        }
    }
    void add(int element){    //add new element
        if(index==capacity){
            capacity*=2;
            int * newdata = new int[capacity];
            for(int i = 0;i<index;i++){
                newdata[i] = data[i];
            }
            delete [] data;
            data = newdata;
            data[index] = element;
            index++;
        }
        else{
            data[index] = element;
            index++;
        }
    }

    int get(int i)const{
        if(i<index){
            return data[i];
        }
        else{
            return -1;
        }
    }

    void addAtIndex(int i,int element){
        if(i<index){
            data[i] = element;
        }
        else if(i==index){
            data[index] = element;
            index++;
        }
        else{
            return;
        }
    }

    void print(){
        for(int i = 0;i<index;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    DynamicArray d1;
    DynamicArray d3;
    d1.add(12);
    d1.add(17);
    d1.add(9);
    d1.add(56);
    d1.add(42);
    d1.add(2);
    d1.print();

    DynamicArray d2(d1); 
    //here if we would have used default copy constructor or assignment operator (d1= d2)(assignment op also does shallow copy) then shallow copy will be done and changes made in d1 will also be refelected in d2
    d1.addAtIndex(0,23);
    d1.print();
    d2.print();


    cout<<"enter 1 to add element"<<endl;
    cout<<"enter 2 to add element at specific index"<<endl;
    cout<<"enter 3 to print element"<<endl;
    cout<<"enter 4 to exit"<<endl;
    int i;
    cin>>i;
    while(i!=4){
        if(i==1){
            cout<<"enter element ";
            int e;
            cin>>e;
            d3.add(e);
        }
        else if(i==2){
            cout<<"enter index and element ";
            int j,e;
            cin>>j>>e;
            d3.addAtIndex(j,e);
        }
        else if(i==3){
            d3.print();
        }
        cout<<"enter 1 to add element"<<endl;
        cout<<"enter 2 to add element at specific index"<<endl;
        cout<<"enter 3 to print element"<<endl;
        cout<<"enter 4 to exit"<<endl;
        cin>>i;
    }

    return 0;
}