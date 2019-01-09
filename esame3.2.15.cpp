/* 
scrivere un metodo che prenda in input una matrice quadrata A di
N*N puntatori a stringhe e restituisca un puntatore a una stringa
ottenuta concatenando tutti i caratteri centrali delle stringhe
di lunghezza dispari presenti nella diagonale secondaria di A
*/


#include<iostream>
#include<string>

#define N 5

using namespace std;

string* f(string*** S){
    string p;
    for(int i=0;i<N;i++){
        if(S[i][N-i-1]->length()%2!=0){
            p+=S[i][N-i-1]->substr(S[i][N-i-1]->length()/2,1);
        }
    }
    return new string(p);
}

int main(){
    srand(time(NULL));
    string ***S=new string**[N];
    for(int i=0;i<N;i++) S[i]=new string*[N];

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            string p;
            for(int k=0;k<rand()%5+1;k++) p+=rand()%25+97;
            S[i][j] = new string(p);
            cout<<*S[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<*f(S)<<endl;

    return 0;
}