#include<iostream>
#include<string>
#include<math.h>
#include<limits>
#include<typeinfo>
#include<bits/stdc++.h> 

using namespace std;

#define DIM 30

class A{
    private:
        int *p;
        short l;
        float y;
    protected:
        int val(short j){
            if(j<l&& j>=0) return p[j];
            else return p[rand()%l];
        }
    public:
        A(short i1, short i2){
            p = new int[i1+i2];
            int min;
            int max;
            if(i1<i2){
                min = i1;
                max = i2;
            }
            else{
                min=i2;
                max=i1;
            }
            
            for(int i=0;i<i1+i2;i++){
                p[i] = rand()%(max-min+1)+min;
            }
            l = i1+i2;
            y= log((i1+i2)/2);
        }
        virtual float f(short i, float x)=0;
        virtual ostream& put(ostream &out){
            out<<"Class "<<typeid(*this).name()<<", p=[ ";
            for(int i=0;i<l;i++) out<<p[i]<< " ";
            out<<" ]"<<" l= "<<l<<", y= "<<y;
            return out;
        }
        
};

ostream& operator<<(ostream &out, A* a){
    return a->put(out);
}

class B:public A{
    private:
        string str;
    public:
        B(string w, short a, short b):A(a,b){
            for(int i=0;i<w.length();i++){
                switch(w[i]){
						case 'a':
						case 'e':
						case 'i':
						case 'o':
						case 'u':
							str+=w[i];
							break;
					}
            }
        }
        float f(short i, float x){
            return sin(val(i))*x;
        }
        ostream& put(ostream &out){
            A::put(out);
            out<<" { str= "<<str<<" }"<<endl;
            return out;
        }
};
class C:public A{
    private:
        float m;
    public:
        C(float z):A((int) (z+0.5), (int (z+0.5))*5){
				m = val(2*((int) (z+0.5)))/2.0;
        }
        float f(short i, float x){
            if(i%2==0 && x!=0) return sin(val(i)*x);
            else if(i%2!=0 && x!=0) return val(i)/x;
            else return 0;
        }
        float g(){
            return log(m);
        }
        ostream& put(ostream &out){
            A::put(out);
            out<<" { m="<<m<<" }"<<endl;
            return out;
        }
};

int main(){
     srand(111222333);
  A *vett[DIM];
    float mean =0;
  string w;
  short s1, s2;
  for(int i=0; i<DIM; i++){
		if(rand()%2==0){ //B
			w = "";
			s1 = rand()%20 + 5;
			s2 = rand()%20 + 5;
			short len = rand()%50 + 10; 
			for(int j=0; j<len; j++)
				w+=((rand()%2) ? (char) (rand()%26 + 'a') : (char) (rand()%10 + '0'));
				vett[i] = new B(w, s1, s2);
    }
    else{ // C
			int max = 10;
			float z = ((float) rand())/INT_MAX * (rand()%max) + 1.0; 
			vett[i] = new C(z);
            mean+=((C*)vett[i])->g();
            
   }
   //punto 1 overloading
   cout<<vett[i]<<endl;
   // punto 2 
   if(vett[i]->f(5,0.5)<0.5) cout<<"indice: "<<i<<endl;
 }
    //punto 3
    cout<< "media: "<<mean/DIM;
    return 0;
}