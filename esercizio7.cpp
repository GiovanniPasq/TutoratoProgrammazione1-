//data una matrice di char, si scriva un metodo che prenda in input tale matrice, uno short w e uno short k e si controlli
//se esiste almeno una riga e almeno una colonna contenente k sequenze di lunghezza w
#include<iostream>
#include<string>

#define N 20
#define M 15
using namespace std;

bool f(char **S, short k, short w){
    int valueCount=1;
    int stringCountRow=0;
    int stringCountCol=0;
    bool findRow =false;
    bool findCol=false;
    for(int i=0;i<N;i++){
        valueCount=1;
        if(findRow) break;
        for(int j=0;j<M-1;j++){
           if(S[i][j]==S[i][j+1] && valueCount<w){
                valueCount+=1;
                if(valueCount==w){
                    stringCountRow+=1;
                    if(stringCountRow==k){
                         findRow=true;
                         cout<<S[i][j]<<" "<<S[i][j+1]<<endl;
                         cout<<"row: "<<i<<" col: "<<j<<endl;
                         cout<<"stringCountRow: "<<stringCountRow<<endl;
                    }
                }
            }
            else valueCount=1;
        }
        stringCountRow=0;
    }
     for(int j=0;j<M;j++){
        valueCount=1;
        if(findCol) break;
        for(int i=0;i<N-1;i++){
           if(S[i][j]==S[i+1][j] && valueCount<w){
                valueCount+=1;
                if(valueCount==w){
                    stringCountCol+=1;
                    if(stringCountCol==k){
                        findCol=true;
                        cout<<S[i][j]<<" "<<S[i+1][j]<<endl;
                        cout<<"row: "<<i<<" col: "<<j<<endl;
                        cout<<"stringCountcol: "<<stringCountCol<<endl;
                    }
                }
            }
            else valueCount=1;
        }
        stringCountCol=0;
    }
    cout<<"findcol: "<<findCol<<" findRow: "<<findRow<<endl;
    if(findCol && findRow /*&& stringCountRow%2==0 && stringCountCol%2==0*/) return true;
    return false;
}

int main(){
    srand(time(NULL));
    char **S = new char*[N];
    for(int i=0;i<N;i++) S[i] = new char[M];

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            S[i][j] = rand()%25+97;
            cout<<S[i][j]<<" ";
        }
        cout<<endl;
    }
    if(f(S,3,2)) cout<<"found"<<endl;
    else cout<<"not found"<<endl;
    return 0;
}