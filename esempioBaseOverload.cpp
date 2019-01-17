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
    cout<<a;
    cout<<endl<<stampaStr("stampo da dentro la classe A",a);
    return 0;
}