#include<iostream>
#include<string>

using namespace std;
class Lavoro{
    private:
    string nome;
    int guadagno;
    public:
    Lavoro(string nome, int guadagno){
        this->nome = nome;
        this->guadagno= guadagno;
    }
    void setNome(string nome){
        this->nome=nome;
    }
    void setGuadagno(int guadagno){
        this->guadagno=guadagno;
    }
    string getNome(){
        return nome;
    }
    int getGuadagno(){
        return guadagno;
    }
};

class Person{
    private:
        string name;
        string surname;
        int age;
        string birth;
        string cf;
        Lavoro *lavoro;
    public:
        Person(string name,string surname,int age, string birth){
            this->name=name;
            this->surname=surname;
            this->age=age;
            this->birth=birth;
            
        }
        int getAge(){
            return age;
        }
        void setAge(int age){
            this->age=age;
        }
        void setLavoro(Lavoro lavoro){
            this->lavoro=new Lavoro(lavoro.getNome(),lavoro.getGuadagno());
        }
        string getNomeLavoro(){
            return lavoro->getNome();
        }
};



int main(){
    Person *p = new Person("antonio","rossi",22,"29-12-90");
    cout<<"Age: "<< p->getAge()<<endl;
    p->setAge(35);
    cout<<"age: "<<p->getAge();
    Lavoro l = Lavoro("insegnante",1800);
    cout<<endl<<"lavoro: "<<l.getNome()<<endl;
    p->setLavoro(l);
    cout<<"nome Lavoro: "<<p->getNomeLavoro()<<endl;
    Lavoro l2 = Lavoro("postino",1000);
    p->setLavoro(l2);
    cout<<"Nuovo lavoro: "<<p->getNomeLavoro();
    return 0;
}
