/* scrivere un metodo che prende in input una matrice  A  NxM di puntatori a stringhe e un carattere x,
si eliminino tutte le occorrenze di x dalle stringhe della matrice A e si restituisca true se esiscono due stringhe uguali
(dopo aver eliminato le occorrente x),false altrimenti.
*/
#include<iostream>
#include<string>
#define N 3
#define M 3
using namespace std;

bool f(string ***A, char c){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            string p="";
            string f="";
            for(int k=0;k<(A[i][j][0]).length();k++){
                if(c!=(A[i][j][0][k])) p+=A[i][j][0][k];
            }
            for(int q=j+1;q<M;q++){
                for(int k=0;k<(*A[i][q]).length();k++){
                    if(c!=A[i][q][0][k]) f+=A[i][q][0][k];
                }
                cout<<"P: "<<p<<" F : "<<f<<" "<<endl;
                if(p.compare(f)==0) return true;
                f="";
            }
            for(int n=i+1;n<N;n++){
                for(int m=0;m<M;m++){
                    for(int k=0;k<(*A[n][m]).length();k++){
                        if(c!=A[n][m][0][k]) f+=A[n][m][0][k];
                    }
                    cout<<"P: "<<p<<" F : "<<f<<" "<<endl;
                    if(p.compare(f)==0) return true;
                    f="";
                }
            }
        }  
    }
    return false;
}

int main(){
    //srand(time(NULL));
    string ***A = new string**[N];
    for(int i=0;i<N;i++)    A[i] = new string*[M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            string p;
            for(int k=0;k<rand()%5+1;k++) p+=(rand()%25+97);
            A[i][j]=new string(p);
        }
    }
    A[2][1]=new string("asdacc");
    A[2][2]=new string("asdccca");
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<A[i][j][0]<<" "; // alternativa cout<<*A[i][j]
        }
        cout<<endl;
    }
    if(f(A,'c')) cout<<"trovata"<<endl;
    else cout<<"non trovata"<<endl;
    
    return 0;
}
