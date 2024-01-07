#include<iostream>
using namespace std;

class Fraction{

private:
int num;
int deno;

public:
Fraction(int num,int deno){ //constructor to set Nr and Dr
    this-> num = num;   //using this M1
    (*this).deno = deno;  //using this M2
}
void simplify(){
    int gcd = 1;
    int j = min(num,deno);
    for(int i =1;i<=j;i++){
        if(num%i==0 && deno%i==0){
            gcd = i;
        }
    }
    num/=gcd;
    deno/=gcd;
}
void sum(Fraction f2){
    int a = this->num*f2.deno;
    int b = this->deno*f2.num;
    num = a+b;
    deno = deno*f2.deno;
    simplify();
}
void mul(Fraction f2){
    int a = this->num*f2.num;
    int b = this->deno*f2.deno;
    num = a;
    deno = b;
    simplify();
}
void div(Fraction f2){
    int a = this->num*f2.deno;
    int b = this->deno*f2.num;
    num = a;
    deno = b;
    simplify();
}
void print(){
    cout<<num<<"/"<<deno<<endl;
}
};

class ComplexNumbers {
    int real,img;

    public:
    ComplexNumbers(int real,int img){
        this->real = real;
        this->img = img;
    }
    
    void print(){
        cout<<real<<" + "<<"i"<<img<<endl;
    }
    void plus(ComplexNumbers c){
        this->real = real+c.real;
        this->img = img+c.img;
    }
    void multiply(ComplexNumbers c){
        int i = real;
        this->real = real*c.real-img*c.img;
        this->img = this->img*c.real + i*c.img;
    }  
};

class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    
    Polynomial(){    //initialising variables
        capacity = 5;
        degCoeff = new int[5];
        for(int i = 0;i<5;i++){
            degCoeff[i] = 0;
        }
    }
    
    Polynomial(Polynomial const & p){    //deep copy constructor
        capacity = p.capacity;
        degCoeff = new int[capacity];
        for(int i = 0;i<capacity;i++){
            degCoeff[i] = p.degCoeff[i];
        }
    }
    
    void operator=(Polynomial const & p){  //deep copy assignment operator
        capacity = p.capacity;
        degCoeff = new int[capacity];
        for(int i = 0;i<capacity;i++){
            degCoeff[i] = p.degCoeff[i];
        }
    }
    
    void setCoefficient(int j,int c){   //setting coeff
        if(j<capacity){
            degCoeff[j] = c;
        }
        else{
            // int size = capacity;
            // while(j>=size){
            //     size = 2*capacity;
            // }
            // int *newdegCoeff = new int[size];
            // for(int i = capacity;i<size;i++){
            // 	newdegCoeff[i] = 0;
        	// }
            // for(int i = 0;i<capacity;i++){
            // 	newdegCoeff[i] = degCoeff[i];
        	// }
            // newdegCoeff[j] = c;
            // capacity = size;
            // delete [] degCoeff;
            // degCoeff = newdegCoeff;

            // Something wrong with recursive approach!!!!!!!!(x^10 :(  )

            int *newdegCoeff = new int[2*capacity];
            for(int i = capacity;i<2*capacity;i++){
            	newdegCoeff[i] = 0;
        	}
            for(int i = 0;i<capacity;i++){
            	newdegCoeff[i] = degCoeff[i];
        	}
            
            capacity *= 2;
            delete [] degCoeff;
            degCoeff = newdegCoeff;
            setCoefficient(j,c);
        }
        print();
    }
    
    void print(){
        for(int i = 0;i<capacity;i++){
            if(degCoeff[i]!=0){
            	cout<<degCoeff[i]<<"x"<<i<<" ";
        	}
        }
        cout<<endl;
    }
    
    Polynomial operator+(Polynomial const & p){
        if(capacity>=p.capacity){
            Polynomial p1(*this);
            for(int i = 0;i<p.capacity;i++){
                int j = degCoeff[i]+p.degCoeff[i];
                p1.setCoefficient(i,j);
            }
            return p1;
        }
        else{
            Polynomial p1(p);
            for(int i = 0;i<capacity;i++){
                int j = degCoeff[i]+p.degCoeff[i];
                p1.setCoefficient(i,j);
            }
            return p1;
        }

    }
    
    Polynomial operator-(Polynomial const & p){
        if(capacity>=p.capacity){
            Polynomial p1(*this);
            for(int i = 0;i<p.capacity;i++){
                int j = degCoeff[i]-p.degCoeff[i];
                p1.setCoefficient(i,j);
            }
            return p1;
        }
        else{
            Polynomial p1(p);
            for(int i = 0;i<capacity;i++){
                int j = degCoeff[i]-p.degCoeff[i];
                p1.setCoefficient(i,j);
            }
            return p1;
        }
    }
    
    Polynomial operator*(Polynomial const & p){
        Polynomial p1;
        for(int i = 0;i<capacity;i++){
            for(int j = 0;j<p.capacity;j++){
                p1.setCoefficient(i+j,p1.degCoeff[i+j]+degCoeff[i]*p.degCoeff[j]);
            }
        }
        return p1;
    } 
};
