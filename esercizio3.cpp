//data una matrice di stringe A N*M, un array C di dimensione K di caratteri e uno short w, scrivere un metodo
//che prenda in input tali elementi e restituisca true se esiste almeno una riga o una colonna della matrice A
// contenente un numero maggiore o uguale di occorrenze w di uno dei caratteri presenti in C

#include<iostream>
#include<string>

#define N 4
#define M 5
#define K 6
using namespace std;

bool f(string** S, char*C, short w){
    for(int k=0;k<K;k++){
        for(int i=0;i<N;i++){
            int temp=0;
            for(int j=0;j<M;j++){
                for(int l=0;l<S[i][j].length();l++){
                    if(S[i][j][l]==C[k]) temp+=1;
                }
            }
            if(temp>=w){
                cout<<"riga: "<<i<<endl;
                cout<<"carattere trovato: "<<C[k]<<endl;
                return true;
            }
        }
    }
    for(int k=0;k<K;k++){
        for(int j=0;j<M;j++){
            int temp=0;
            for(int i=0;i<N;i++){
                for(int l=0;l<S[i][j].length();l++){
                    if(S[i][j][l]==C[k]) temp+=1;
                }
            }
            if(temp>=w){
                cout<<"colonna: "<<j<<endl;
                cout<<"carattere trovato: "<<C[k]<<endl;
                return true;
            }
        }
    }
    return false;
}


int main(){
    srand(time(NULL));
    string **S=new string*[N];
    for(int i=0;i<N;i++) S[i]=new string[M];
    cout<<"Matrice: "<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<5;k++){
                S[i][j]+=rand()%25+97;
            }
            cout<<S[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    char *C=new char[K];
    cout<<"Array"<<endl;
    for(int i=0;i<K;i++){
        C[i]=rand()%25+97;
        cout<<C[i]<<" ";
    }
    cout<<endl;
    if(f(S,C,3)) cout<<"found"<<endl;
    else cout<<"not found"<<endl;

    return 0;
}