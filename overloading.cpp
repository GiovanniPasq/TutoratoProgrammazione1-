#include<iostream>
#include<string>

using namespace std;

class A{
    private:
    int x;
    public:
    A(){
        x=19;
    }
    int getX(){
        return x;
    }
};

class Persona{
    private:
    string nome;
    string cognome;
    string dataNascita;
    int *p;
    public:
    Persona(string nome="Mario",string cognome="Rossi", string dataNascita="1-1-90"){
        p = new int[10];
        for(int i=0;i<10;i++){
            p[i] = rand()%20;
        } 
        this->nome=nome;
        this->cognome=cognome;
        this->dataNascita=dataNascita;
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
    void setNome(string nome){this->nome=nome;}
    void setCognome(string cognome){this->cognome=cognome;}
    void setData(string data){this->dataNascita=data;}


    ostream& put(ostream& out){
        out<<"Nome: "<<nome<<"Cognome: "<<cognome<<"Data N: "<<dataNascita<<endl;
        return out;
    }

    Persona operator ()(string s,string s1, string s2){
        return Persona(s,s1,s2);
    } 
    A* operator ->(){
        return new A();
    }
    int& operator[](int x){
        if(x<10) return p[x];
        return p[0];
    }
    void operator = (Persona &p){
        setNome(p.getNome());
        setCognome(p.getCognome());
        setData(p.getData());
    }
    void operator delete (void *p){
        free(p);
    }
    void operator delete [](void *p){
         ::operator delete (p);
    }
     void* operator new(size_t size){
        void * p = ::new Persona();
        return p;
    }
    void* operator new [](size_t size){
        return ::operator new(size);
    }
};

bool operator &&(Persona &p, Persona &p1){
    if(p.getCognome()== p1.getCognome()) return true;
    return false;
}

ostream& operator<<(ostream& cout, Persona& p){
    return cout<<p.getNome()<<" "<<p.getCognome()<< " "<<p.getData()<<endl;
}

Persona operator+(Persona &a ,Persona &b){
    return Persona(a.getNome()+b.getNome(),a.getCognome()+b.getCognome(),a.getData()+b.getData());
}


int main(){
    srand(time(NULL));
    Persona *p = new Persona();
    cout<<*p;
    Persona *f=new Persona[10];
    for(int i=0;i<10;i++)cout<<f[i]<<endl;
    if(*p && f[0]) cout<<"ok"<<endl;
    Persona z = Persona();
    int  d = z->getX();
    Persona i = z("f","fg","234");
    cout<<d<<endl;
    cout<<z[8]<<endl;
    Persona c = *p+*p;
    cout<<c;
    c = i;
    cout<<c;
    // delete [] f;
     delete p;
    return 0;
}