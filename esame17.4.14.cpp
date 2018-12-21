/*
scrivere un metodo che prende in input una matrice A N*M di long dove ogni elemento è formato da 6 numeri
selezioni il massimo in A, lo suddivida in 3 parti tale che le prime due parti individuino la riga e la colonna
e l'ultimo determini il numero di volte da sommare tale elemento.
Il metodo deve ritornare la somma ottenuta.

es:
    supposto che l'elemento massimo in A sia 234560
    si selezioni l'elemento A[23][45] e lo si sommi 60 volte
*/


#include<iostream>
#include<string>

#define N 90
#define M 100


using namespace std;

long f(long**A){
    int max=A[0][0];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(max<A[i][j]) max=A[i][j];
        }
    }
    cout<<"max: "<<max<<endl;

    string s= to_string(max);
    int i=stoi(s.substr(0,2));
    int j=stoi(s.substr(2,2));
    int n=stoi(s.substr(4,2));

    cout<<"i "<<i<<endl;
    cout<<"j "<<j<<endl;
    cout<<"n "<<n<<endl

    long value=0;
    for(int i=0;i<n;i++){
        value+=A[i][j];
    }
    return value;
}

int main(){

    srand(time(NULL));
    long **A= new long*[N];
    for(int i=0;i<N;i++) A[i]=new long[M];

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            A[i][j]=rand()%100000+100000;
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<f(A)<<endl;
    return 0;
}