#include<iostream>
#include<string>
#include<math.h>
#include<typeinfo>
using namespace std;

class A{
    private:
    string sa;
    public:
    A(string s1,string s2){
        sa="";
        for(int i =0;i<s1.length();i++){
            if(s1[i]=='a') sa+=s1[i];
            else if(s1[i]=='e') sa+=s1[i];
            else if(s1[i]=='i') sa+=s1[i];
            else if(s1[i]=='o') sa+=s1[i];
            else if(s1[i]=='u') sa+=s1[i];
            else if(s1[i]=='A') sa+=s1[i];
            else if(s1[i]=='E') sa+=s1[i];
            else if(s1[i]=='I') sa+=s1[i];
            else if(s1[i]=='O') sa+=s1[i];
            else if(s1[i]=='U') sa+=s1[i];
        }
        for(int i=0;i<s2.length();i++){
            if(s2[i]>'a' && s2[i]<'z') sa+=s2[i]; 
        }
    }
    virtual bool v(char c,short n)=0;
    //Funzione richiamata dal metodo overload operator<<
    virtual ostream& out(ostream& printer){
        printer<<"Class "<<typeid(*this).name()<<" sa="<<sa;
        return printer;
    }
    protected:
    short num(char c){
        for(int i=0;i<sa.length();i++){
            if(c==sa[i]) return  sa.length()-(i+1);
        }
        return -1;
    }
};
class B: public A{
    private:
    int *vec;
    short len;
    public:
    B(string w, short k):A(w.substr(0,k),w.substr(k)){
        vec = new int[w.length()];
        len = w.length();
        for(int i=0;i<len;i++){
            vec[i] = (int)(w[i]);
        }
    }
    bool v(char c, short n){
        if(num(c)>n) return true;
        return false;
    }
    ostream& out(ostream& printer){
        A::out(printer);
        printer<<" vec=[ ";
        for(int i=0;i<len;i++){
            printer<<vec[i]<<" ";
        }
        printer<<" ], "<<"len= "<<len;
        return printer;
    }
};
class C: public A{
    private:
    float y;
    string diff;
    public:
    C(string s1,string s2):A(s1,s2){
        y = (s1.length()+s2.length())/2;
        int min,max;
        bool find=false;
        if(s1.length()<s2.length()){
            min = s1.length();
            max = s2.length();
        } 
        else{
            min = s2.length();
            max = s1.length();
        }
        for(int i=0;i<min;i++){
            find=false;
            for(int j=0;j<max;j++){
                if(s1[i]==s2[j]){
                    find=true;
                    break;
                }
            }
            if(!find) diff+=s1[i];
        }
    }
    bool v(char c, short n){
        for(int i=0;i<diff.length();i++){
            if(diff[i]==c){
                if(i>n) return true;
            }else return false;
        }
        return false;
    }
    float f(){
        return log(y);
    }
    ostream& out(ostream& printer){
        A::out(printer);
        printer<<" { y = "<<y <<" diff= "<<diff<< " }";
        return printer;
    }
};

ostream& operator<<(ostream& printer, A& a){
    return a.out(printer);
}

int main(){
     const int DIM = 30;
  srand(111222333);
  A *vett[DIM];

  string s1, s2;
  short l1, l2;
  short k;

  for(int i=0; i<DIM; i++){
    if(rand()%2==0){ 
      s1 = "";
      l1 = rand()%10+5;
      k = rand()%(l1/2)+1;

      for(int j=0; j<l1; j++)
	s1+=((rand()%2) ? (char) (rand()%25 + 'a') : (char) (rand()%25 + 'A'));      

      vett[i] = new B(s1, k);
    }
    else{
      s1 = "";
      s2 = "";
      l1 = rand()%20 +6;
      l2 = rand()%20 +6;
      for(int j=0; j<l1; j++)
	s1+=(rand()%2 ? (char) (rand()%25 + 'a') : (char) (rand()%25 + 'A'));
      

      for(int k=0; k<l2; k++)
	s2+=(rand()%2 ? (char) (rand()%25 + 'a') : (char) (rand()%25 + 'A'));

      vett[i] = new C(s1, s2);
    }
    // PUNTO 1: OVERLOADING DEL <<
    cout<<*vett[i]<<endl;
  }
  // PUNTO 2: 
  cout<<endl<<"Indici: ";
  for(int i=0; i<DIM; i++)
      if(vett[i] -> v('b', 2))
  	cout << i << " ";
  cout << endl;
  // PUNTO 3
  C *temp;
  float mean=0;
  for(int i=0; i<DIM; i++){
      temp=dynamic_cast<C*>(vett[i]);
      if(temp) mean+=temp->f();
  }  
  cout<<endl<<"Media: "<<mean/30<<endl;
  return 0;
}