/*
templates are used to make generic classes i.e. any datatype can be used for their variables.
templates should be declared just above the class 
we can have multiple templates in a class
*/
template<typename T,typename V>
class pair{
    T x;  //x has datatype 'T'
    V y;  //y has datatype 'V'
    public:
    void setx(T x){
        this->x = x;
    }
    void sety(V y){
        this->y = y;
    }
    T getx(){     //Note the return type
        return x;
    }
    V gety(){     //Note the return type
        return y;
    }
};

int main(){

    pair<int,int> p1;   //T = int and V = int
    pair<int,char> p2;  //T = int and V = char    [order of telling datatype matters]
    pair<char,int> p3;  //T = char and V = int    [order of telling datatype matters]

    p1.setx(2);
    p1.sety(4);
    p1.getx();
    p1.gety();

    p2.setx(2);
    p2.sety('d');
    p2.getx();
    p2.gety();

    //               triplet
    pair<pair<int, int>,int> p4;
    p4.setx(p1);
    p4.sety(4);
    p4.getx().getx();
    p4.getx().gety();
    p4.gety();

    return 0;
}
