#include<iostream>
#include<string>

using namespace std;



void f1(){cout<<"f1"<<endl;}
void f2(){cout<<"f2"<<endl;}
void f3(){cout<<"f3"<<endl;}

template<class T> class A{
    private:
        T x;
    public: 
        A(T x){
            this->x=x;
        }
        T getX(){
            return x;
        }
        bool f(T x, T y){
            if(x>y) return true;
            else return false;
        }

};

template<class T> T f(T x){ 
    return x;
}

int main(){
    srand(time(NULL));
    void (*ptr)();

    if(rand()%5>3) ptr = f1;
    else ptr=f2;
    ptr();

    A<string> a = A<string>("giovanni");
    A<int> b = A<int>(5);
    cout<<a.getX()<<endl;
    cout<<b.getX()<<endl;
    cout<<f(34245)<<endl;
    cout<<f("prova")<<endl;
    return 0;

}