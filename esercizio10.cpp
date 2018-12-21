/*
data una matrice di stringhe A N*M e una matrice C di char, si scriva un metodo  che ritorni true o false se esiste un carattere
della matrice C che si ripete un numero maggiore o uguale a w 
*/

#include<iostream>
#include<string>

#define N 4
#define M 5
#define K 2
#define Z 3

using namespace std;

bool f(string**A, char**C, short w){
    for(int i=0;i<K;i++){
        for(int j=0;j<Z;j++){
            for(int n=0;n<N;n++){
                int temp=0;
                for(int m=0;m<M;m++){
                    for(int l=0;l<A[n][m].length();l++){
                        if(A[n][m][l]==C[i][j]) temp+=1;
                    }
                }
                if(temp==w){
                    cout<<"elemento della matrice C trovato: "<<C[i][j]<<endl;
                    cout<<"riga della matrice A: "<<n<<endl;
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    string **A = new string*[N];
    for(int i=0;i<N;i++) A[i] = new string[M];

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<5;k++){
                A[i][j]+=rand()%25+97;  
            }
            cout<<A[i][j]<<" ";  
        }
        cout<<endl;
    }
    cout<<endl;
    char **C = new char*[K];
    for(int i=0;i<Z;i++) C[i]=new char[Z];

    for(int i=0;i<K;i++){
        for(int j=0;j<Z;j++){
            C[i][j]=rand()%25+97;
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    if(f(A,C,3)) cout<<"found"<<endl;
    else cout<<"not found"<<endl;


    return 0;
}