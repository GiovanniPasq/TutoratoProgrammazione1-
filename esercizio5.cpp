//date due matrici A N*M e B K*N si restituisca un array C
//di dimensione N contenente la media della matrice A
//analizzata per righe e della matrice B analizzata per colonne

#include<iostream>
#include<string>

#define N 3
#define M 2
#define K 4

using namespace std;

int* f(int *A, double *B){
    static int mean[N];
    for(int i=0;i<N;i++) mean[i]=0;
    int tempMean=0;
    for(int i=0;i<N;i++){
        tempMean=0;
        for(int j=0;j<M;j++){
           tempMean += A[i*M+j];
           cout<<" elemento : "<<A[i*M+j]<<" ";
        }
        tempMean/=M;
        cout<<endl<<"media : "<<tempMean<<endl;
        mean[i] = tempMean;
    }
    cout<<endl;
    for(int i=0;i<N;i++){
        tempMean=0;
        for(int j=0;j<K;j++){
           tempMean += B[j*N+i];
           cout<<" elemento : "<<B[j*N+i]<<" ";
        }
        tempMean/=M;
        cout<<endl<<"media : "<<tempMean<<endl;
        mean[i] += int(tempMean);
    }
    return mean;
}
int main(){
    int *A=new int[N*M];
    for(int i=0;i<N*M;i++){
        A[i] = i*3+5;
         if(i!=0 && i%M==0){
            cout<<endl;
        }
        cout<<A[i]<<" ";
    } 
    cout<<endl<<endl;

    double *B=new double[K*N];
    for(int i=0;i<K*N;i++){
        B[i] = i*5 - 5;
        if(i!=0 && i%N==0){
            cout<<endl;
        }
        cout<<B[i]<<" ";
    }

    cout<<endl<<endl;
    int *mean;
    mean=f(A,B);
    for(int i=0;i<N;i++){
        cout<<mean[i]<<endl;
    }
    return 0;
}