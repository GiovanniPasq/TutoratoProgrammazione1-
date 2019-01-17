#include<iostream>
#include<string>
#include<time.h>
using namespace std;

class Figura{
    public:
        virtual double perimetro()=0;
        virtual double area()=0;
        virtual ostream& put(ostream &out)=0;
};

ostream& operator<<(ostream& ostream, Figura *f){
    return f->put(ostream);
}

class Rettangolo: public Figura{
    private:
    double lato1,lato2;
    public:
        Rettangolo(double lato1,double lato2){
            this->lato1=lato1;
            this->lato2=lato2;
        }
        double perimetro(){
            return lato1*2+lato2*2;
        }
        double area(){
            return lato1*lato2;
        }
        ostream& put(ostream& out){
            return out<<"Sono il rettangolo "<<"Area: "<<area()<<endl;
        }
};
class Quadrato: public Rettangolo{
    public:
        Quadrato(double lato1):Rettangolo(lato1,lato1){}

        ostream& put(ostream& out){
            return out<<"sono il quadrato"<<endl;
        }
};

int main(){
    srand(time(NULL));
    Figura *f= new Quadrato(2);
    cout<<f;
    f=new Rettangolo(3,3);
    cout<<f;
    return 0;
}