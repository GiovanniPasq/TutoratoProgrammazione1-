//data una matrice quadrata di stringhe si faccia la trasposta

#include<iostream>
#include<string>
#define N 4
#define M 4

using namespace std;

void f(string **S){
    string temp;
    int j=0;
    for(int i=0;i<N;i++){
        j=i;
        for(;j<M;j++){
            temp = S[i][j];
            S[i][j] = S[j][i];
            S[j][i]= temp;
        }
        j=0;
    }
}
int main(){
    srand (time(NULL));
    string **S = new string*[N];
    for(int i=0;i<N;i++) S[i] = new string[M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            S[i][j]="test"+to_string(rand()%10);
            cout<<S[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    f(S);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
           cout<<S[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}