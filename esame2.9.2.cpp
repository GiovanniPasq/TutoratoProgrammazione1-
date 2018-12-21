#include<iostream>
#include<string>

#define N 10
#define M 7
#define K 3
#define Z 6


using namespace std;

bool f(long *A, long *B, long **C){
    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++){
            for(int i=0;i<K;i++){
                for(int j=0;j<Z;j++){
                    if(A[n]==B[m] && A[n]==C[i][j]) return true;
                }
            }
        }
    }



    return false;
}

int main(){
    srand(time(NULL));

    long *A = new long[N];
    cout<<"Array A: "<<endl;
    for(int i=0;i<N;i++){
        A[i]=rand()%90;
        cout<<A[i]<<" ";
    }
    cout<<endl<<"Array B: "<<endl;
    long *B=new long[M];
    for(int i=0;i<M;i++){
        B[i]=rand()%90;
        cout<<B[i]<<" ";
    }
    cout<<endl<<"Matrice C: "<<endl;
    long **C=new long*[K];
    for(int i=0;i<K;i++) C[i]=new long[Z];

    for(int i=0;i<K;i++){
        for(int j=0;j<Z;j++){
            C[i][j]=rand()%90;
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    if(f(A,B,C)) cout<<"found"<<endl;
    else cout<<"not found"<<endl;
    return 0;
}