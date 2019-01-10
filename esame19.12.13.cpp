/*
Scrivere un metodo che prenda in input una matrice A[7][10] di float, e restituisca l'indice di
una riga il cui elemento massimo è strettamente minore dei valori medi della riga soprastante e di
quella sottostante o restituisca il valore -1 se tale riga non esiste.
N.B.: Non è possibile usare array ausiliari.
*/
#include<iostream>
#include<string>

using namespace std;

int f(float A[7][10]){
    for(int i=1;i<6;i++){
        int max=A[i][i];
        int meanSup=0;
        int meanInf=0;
        for(int j=0;j<10;j++){
            if(max<A[i][j]) max=A[i][j];
            meanInf+=A[i-1][j];
            meanSup+=A[i+1][j];
        }
        meanInf/=10;
        meanSup/=10;
        cout<<"media riga sotto: "<<meanSup<<endl;
        cout<<"massimo corrente: "<<max<<endl;
        cout<<"media riga sopra: "<<meanInf<<endl;
        
        if(max<meanInf) return i-1;
        else if(max<meanSup) return i+1;
    }


    return -1;
}

int main(){
    srand(time(NULL));
    float A[7][10];

    for(int i=0;i<7;i++){
        for(int j=0;j<10;j++){
            A[i][j]=rand()%20;
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    int a=f(A);
    cout<<"indice: "<<a<<endl;

    return 0;
}