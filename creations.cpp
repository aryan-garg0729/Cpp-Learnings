#include <iostream>
#include<climits>
#include<math.h>
using namespace std;
#define f(x) pow(M_E,pow(x,2))  //function for trapazoidal rule [f(x) = e^(x^2)] or change it

void gaussSeidal(){
    float e1[4] = {};
    float e2[4] = {};
    float e3[4] = {};

    for(int i = 0;i<4;i++){
        cout<<"enter for equation1(x>y+z)"<<endl;
        cin>>e1[i];
    }
    for(int i = 0;i<4;i++){
        cout<<"enter for equation2(y>x+z)"<<endl;
        cin>>e2[i];
    }
    for(int i = 0;i<4;i++){
        cout<<"enter for equation3(z>y+x)"<<endl;
        cin>>e3[i];
    }
    int n = 100;
    // cout<<"enter number of iterations"<<endl;
    // cin>>n;

    int ic;
    cout<<"enter initial condition"<<endl;
    cin>>ic;

    float x = ic,y = ic,z = ic;
    while(--n){
        x = (1/e1[0])*(e1[3]-(y*e1[1])-(z*e1[2]));
        y = (1/e2[1])*(e2[3]-(x*e2[0])-(z*e2[2]));
        z = (1/e3[2])*(e3[3]-(y*e3[1])-(x*e3[0]));
    }

    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"z = "<<z<<endl;
}

void trapazoidRule(){
    double ll,ul;
    cout<<"enter lower and upper limit";
    cin>>ll>>ul;

    int n = 1000;
    double h = (ul-ll)/n;

    double limits[n+1];
    for(int i = 0;i<n+1;i++){
        limits[i] = ll+h*i;
    }

    double o1 = (f(limits[0])+f(limits[n]))/2;
    double o2 = 0;
    for(int i = 1;i<n;i++){
        o2+=f(limits[i]);
    }
    cout<<h*(o1+o2);
}

int main(){

    // gaussSeidal();
    // trapazoidRule();
    string s;
    s+=to_string(97);
    cout<<s;

}