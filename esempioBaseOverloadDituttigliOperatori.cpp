#include<iostream>
#include<string>

using namespace std;
//all'interno della classe A definisco un metodo che torna un ostream, tale metodo verrà richiamato dall'operatore << facendone l'overload
class A{
    private:
        int x;
    public:
    A(int x){
        this->x=x;
    }
    int getX(){
        return x;
    }
    //operatore prefisso
    A operator++(){    
        x++;
        return *this;
    }
    /*
        void operator++(){x++;}
    */
    //operatore postfisso il parametro int permette
    //al compilatore di distunguere tra prefisso e 
    //postfisso
    A operator++(int){
        A temp=*this;
        x++;
        return temp;
    }
    /*
        void operator++(int){x++;}
    */
    ostream& stampa(ostream& printer){
        return printer<<"Sono la classe A e x= "<<x;
    }
    string getStr(string str){
         return str; 
    } 
};
/* il metodo overload << (esterno alla classe) si limita a chiamare una funzione
presente all'interno del metodo della classe chiamata
*/
ostream& operator<<(ostream& xD, A* a){
    return a->stampa(xD);
}
A operator+(A &a, A &b){
        return A(b.getX()+a.getX());
}
A operator-(A &a, A &b){
        return A(b.getX()+a.getX());
}
bool operator==(A &a, A &b){
        if(a.getX()==b.getX()) return true;
        return false;
}

/*
il metodo stampaStr è un metodo esterno alla classe che prende un puntatore alla classe A e a richiamare
un metodo della classe
*/
string stampaStr(string s,A* a){
    return a->getStr(s);
}
int main(){
    A*a = new A(5);
    cout<<a->getX()<<endl;
    //tramite l'overload del << vogliamo evitare di creare un metodo getX() all'interno della classe
    cout<<a; //equivalente a operator<<(cout,a);
    cout<<endl<<stampaStr("stampo da dentro la classe A",a)<<endl;
   // cout.operator<<(5); // equivalente a cout<<5;
    A *b = new A(10);
    ++(*b);//equivale a b->operator++();
    A d= ++(*b); // equivale a b->operator++(0)
    cout<<"B: "<<b<<endl;
    A *c = new A(*a+*b); // equivalente ad A c= operator+(*a,*b);
    cout<<c;
    if(*a==*b) cout<<endl<<"vero"<<endl;
    else cout<<endl<<"falso"<<endl;

    cout<<"D: "<<&d;
    /* int x,z;     /* due variabili intere */
    /* z = 4;       /* z vale 4 */
    /*x = z++;     /* anche x vale 4 ma z vale 5 */
    return 0;
}
