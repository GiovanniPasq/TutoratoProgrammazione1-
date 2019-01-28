#include<iostream>
#include<string>
#include<typeinfo>
#include<math.h>

using namespace std;

class A{
    protected:
    int n;
    public:
    A(int n){
        this->n=n;
    }
    virtual const int f(int n)=0;
    virtual  ostream& print(ostream &printer)=0;
};

class B:public A{
    private:
    int m;
    public:
    B(int _n):A(_n){
        m = (n%7)*3;
    }
    const int fatt(int n){
        if(n==0 || n==1) return 1;
        return n*fatt(n-1);
    }
    const int f(int z){
        if(n<z) return fatt(n);
        return fatt(m);
    }
    ostream& print(ostream& printer){
        printer<<"B:"<<"n: "<<n<<endl;
    }
    virtual B operator++(int){
        B a =*this;
        n++;
        return a;
    }
};

template<class T> class C:public A{
    private:
    T x;
    public:
    C(int n):A(n){
        if(typeid(n)==typeid(int)) x = g(n);
        else if(typeid(n)==typeid(double)) x = sin(n);
    }
    const T g(T x){
        return x*x;
    }
    const int f(int z){
        return g(n+x+z);
    }
    ostream& print(ostream& printer){
        if(typeid(*this)==typeid(C<int>)) printer<<"C<int>";
        if(typeid(*this)==typeid(C<double>)) printer<<"C<double>";
        printer<<" n= "<<n<<" x="<<x<<" f(5)="<<f(5)<<" g(5)= "<<g(5)<<endl;
    }
};

ostream& operator<<(ostream& printer, A &a){
    return a.print(printer);
}


int main(){
    srand(328832748);
    A *vett[50];
    for(int i=0; i<50; i++) {
        int n=1+rand()%100;
        switch(rand()%3) {
            case 0: vett[i]= new B(n); break;
            case 1: vett[i]= new C<double>(n);break;            
            case 2: vett[i]= new C<int>(n);
            }
        
    }
    for(int i=0;i<50;i++) cout<<*vett[i];
    
    C<double>* obj;
    int max =0;
    int sum=0;
    for(int i=0;i<50;i++){
        if(vett[i]->f(5)>max) max=vett[i]->f(5);
        obj = dynamic_cast<C<double>*>(vett[i]);
        if(obj!=NULL) sum+=obj->g(5);
    }
    cout<<"Max: "<<max<<endl;
    cout<<"Sum: "<<sum<<endl;
    return 0;
}