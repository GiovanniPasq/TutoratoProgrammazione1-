//data una matrice A N*M e una stringa s, si scriva un metodo
//che torna true se esistono almeno due stringhe uguali ad s
//e che abbiano differenti indici di riga e colonna nella matrice

#include<iostream>
#include<string>

#define N 3
#define M 2

using namespace std;

bool f(string *A, string s){
    int count=0;
    int x,y;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i*M+j]==s){
                count++;
                if(count==2 &&(x!=i && y!=j)) return true;
                else if(count==2)count -=1;
                x=i;
                y=j;
            }
            cout<< "x "<<x<<" y "<<y <<" count "<<count<<endl;
        }
    }
    return false;
}

int main(){
    string B[] = {"prova","pippo",
                "te","test",
                "test","sdfgfd"};
    string *A = new string[N*M];
    string p = "test";
    for(int i=0;i<N*M;i++){
        A[i] = B[i];
    } 
    if(f(A,p)) cout<<"trovata"<<endl;
    else cout<<"non trovata"<<endl;
    return 0;
}