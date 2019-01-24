#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

// decommentare o commentare il codice del main in base all'esempio che si vuole studiare
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
        ostream& put(ostream & asd){
            asd<<"sono dentro la classe A";
            return asd;
        }
};

ostream& operator<<(ostream& out, A &a){
    return a.put(out);
}

A operator+(A& a, A& b){
    return A(a.getX()+b.getX());
}

class Persona{
    private:
    string nome;
    string cognome;
    string dataNascita;
    public:
    Persona(string nome,string cognome, string dataNascita){
        this->nome=nome;
        this->cognome=cognome;
        this->dataNascita=dataNascita;
    }
    ostream& put(ostream& out){
        out<<"Nome: "<<nome<<"Cognome: "<<cognome<<"Data N: "<<dataNascita<<endl;
        return out;
    }
    string getNome(){
        return nome;
    }
    string getCognome(){
        return cognome;
    }
    string getData(){
        return dataNascita;
    }
};

ostream& operator<<(ostream& cout, Persona& p){
    return cout<<p.getNome()<<p.getCognome()<<endl;
}

Persona operator+(Persona &a ,Persona &b){
    return Persona(a.getNome()+b.getNome(),a.getCognome()+b.getCognome(),a.getData()+b.getData());
}

class Rettangolo{
    protected:
        double lato1, lato2;
    public:
        Rettangolo(double lato1, double lato2){
            this->lato1=lato1;
            this->lato2=lato2;
        }
         virtual double getPerimetro(){
            return 2*lato1+2*lato2;
        }
        virtual double getArea(){
            return lato1*lato2;
        }
        virtual ostream& print(ostream& printer){
            printer<<"Area: "<<lato1*lato2<<"Perimetro:"<<2*lato1+2*lato2<<endl;
            return printer;
        }
};


class Quadrato:public Rettangolo{
    private:
        int len;
        int *p;
        int x;
    public:
        Quadrato(int lato1):Rettangolo(lato1,lato1){
            len =10;
            p = new int[len];
            for(int i=0;i<len;i++){
                p[i]=rand()%10;
            }
            x=0;
        }
        double getPerimetro(){
            return 4*lato1;
        }
         double getArea(){
            return lato1*lato1;
        }
        void printA(){
            for(int i=0;i<len;i++) cout<<p[i]<<" ";
            cout<<endl;
        }
        virtual ostream& print(ostream& printer){
            printer<<"Area: "<<lato1*lato1<<"Perimetro:"<<4*lato1<<endl;
            printer<<"Array: "<<endl;
            for(int i=0;i<len;i++) printer<<p[i]<<" ";
            printer<<endl;
            return printer;
        }
        // se voglio solo incrementare x il parametro di ritorno della funzione sarà di tipo void
       /* void operator++(){
            x++;
        }
        void operator++(int){
            x++;
        }*/
        Quadrato operator++(){
            x++;
            return *this;                
        }
        Quadrato operator++(int){
            Quadrato q = *this;
            x++;
            return q;
        }
        int getX(){
            return x;
        }
};
/*ostream& operator<<(ostream& out, Rettangolo &p){
    //controllo sul tipo
    if(typeid(p)==typeid(Quadrato)) return out<<"ok"<<endl;
    return out<<"Area: "<<p.getArea()<<" Perimetro: "<<p.getPerimetro()<<endl;
}*/
// operator<<(cout,*r)
ostream& operator<<(ostream &out, Rettangolo &r){
    return r.print(out);
}

int main(){
    Quadrato q = Quadrato(3.0);
    q.operator++();
    cout<<q.getX()<<endl;
    ++q;
    q++;
    cout<<q.getX()<<endl;
    cout<<q;
    Rettangolo *r = new Rettangolo(3.0,5.0);
    //cout<<*r; //operator<<(cout,*r);
    r = new Quadrato(4.0);
    ((Quadrato*)r)->printA();
    cout<<*r;
    /*Persona p = Persona("mario","rossi", "20-2-90");
    cout<<p;// cout<<p.getCognome()<<" "<<p.getNome()<<" "<<p.getData()<<endl;
    Persona p1 = Persona("cesare","eren","12-3-15");
    Persona p2 = p1+p;
    cout<<p2; // equivalente operator<<(cout,p);
    A a = A(5);
    A b = A(6);
    A c = a+b; // equivale a A c = operator+(a,b)
    cout<<a; // eseguiamo l'verloading del << per evitare questa chiamata  cout<<a.getX()<<endl;
    cout<<a; // equivalente a operator<<(cout,a);  
    //cout<<10;*/// equivalente a cout.operator<<(10);
    return 0;
}
