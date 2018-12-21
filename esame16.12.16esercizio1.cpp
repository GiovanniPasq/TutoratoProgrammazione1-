//scrivere un metodo che prenda in input una matrice di interi di dimensione N*M e restituisca true se esiste un intero palindromo
//all'interno della matrice es: 4554

#include<iostream>
#include<string>

#define N 5
#define M 10

using namespace std;

bool f(int**A){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
           string t=to_string(A[i][j]);
           int temp=0;
           for(int k=0;k<t.length()/2;k++){
               if(t[k]!=t[t.length()-k-1]) break;
               else temp+=1;
           }
           if(temp==t.length()/2){
               cout<<"riga: "<<i<<endl<<"colonna: "<<j<<endl;
               return true;
           }
        }
    }
    return false;
}

int main(){
    int **A=new int*[N];
    for(int i=0;i<N;i++) A[i] =new int[M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            A[i][j]=rand()%10000+100000;
             
            if(i==4 && j==9) A[4][9]=4554;
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    if(f(A)) cout<<"found"<<endl;
    else cout<<"not foud"<<endl;
    return 0;
}