#include<string>
#include<iostream>
#define N 3
#define M 4
#define P 3

using namespace std;

int** multiply(int**A, int**B){
    int **C = new int*[N];
    for(int i=0;i<N;i++) C[i] = new int[P];
    int temp=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<P;j++){
            for(int k=0;k<M;k++){
                temp+=A[i][k]*B[k][j];
            }
            C[i][j]=temp;
            temp=0;
        }
    }
    cout<<endl<<endl;
    return C;
}

int main(){
    srand(time(NULL));

    int **A = new int*[N];
    for(int i=0;i<N;i++) A[i] = new int[M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            A[i][j] = rand()%2+1;
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    int **B = new int*[M];
    for(int i=0;i<M;i++) B[i] = new int[P];
    for(int i=0;i<M;i++){
        for(int j=0;j<P;j++){
            B[i][j] = rand()%2+1;
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    int **F = new int*[N];
    for(int i=0;i<N;i++) F[i] = new int[P];

    F = multiply(A,B);
    for(int i=0;i<N;i++){
        for(int j=0;j<P;j++)    cout<<F[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    return 0;
}