/*
scrivere un metodo che prenda un array di interi di dimensione N e restituisca true o false se esiste una coppia di numeri
la cui distanza (differenza) in valore assoluto e minima e la cui somma è un multiplo di 7
*/


#include<iostream>
#include<string>
#include<cmath>

#define N 10

using namespace std;

bool f(int *A){
    int min=abs(A[0]-A[1]);
    int z=0;
    int t=1;
    for(int i=0;i<N-1;i++){
        int j=i+1;
        for(;j<N;j++){
            if(abs(A[i]-A[j])<min){
                 min=abs(A[i]-A[j]);
                 z=i;
                 t=j;
            }
        }
    }
    cout<<"numero 1: "<<A[z]<<" numero 2: "<<A[t]<<endl;
    if((A[z]+A[t])%7==0) return true;
    return false;
}

int main(){
    srand(time(NULL));
    int *A=new int[N];
    for(int i=0;i<N;i++){
        A[i]=-rand()%25;
        cout<<A[i]<<" ";
    }
    cout<<endl;

    if(f(A)) cout<<"found"<<endl;
    else cout<<"not found"<<endl;

    return 0;
}