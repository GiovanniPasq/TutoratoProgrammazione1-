/*
    Esercizio 1:
        Scrivere un metodo che prenda in input una matrice quadrata di stringhe nxn e restituisca
        true se esiste una stringa nella diagonale secondaria avente i primi tre caratteri
        coincidenti con gli ultimi tre di una qualunque stringa nella diagonale principale,
        false altrimenti.
*/

#include<iostream>
#include<string>

#define N 5

using namespace std;

bool f(string**A){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(A[i][N-i-1].substr(A[i][N-i-1].length()-3,A[i][N-i-1].length())==A[j][j].substr(0,3)) return true;
        }
    }
    return false;
}

int main(){
    string **A=new string*[N];
    for(int i=0;i<N;i++) A[i]=new string[N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<7;k++){
                A[i][j]+=rand()%25+97;
            }
            
            A[4][4]="pppsdfe";
            A[4][0]="dfjsppp";
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    if(f(A)) cout<<"found"<<endl;
    else cout<<"not found"<<endl;
    return 0;
}