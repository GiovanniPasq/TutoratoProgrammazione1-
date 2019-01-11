//dato un array di interi di dimensione K*N*N e un double w 
//si cerchi, se esiste, un livello della matrice k
//in modo che la media tra il minimo e il massimo
//presente nella diagonale principale sia <= di w

#include<iostream>
using namespace std;
#define N 5
#define K 3
bool f(int *A,double w){
    int max=0;
    int min=0;
    double mean=0;
    for(int k=0;k<K;k++){
        min=A[k*N*N];
        max=A[k*N*N];
        for(int r=0;r<N;r++){
          if(A[(r*N+r)+k*N*N]>max) max=A[(r*N+r)+k*N*N];
          if(A[(r*N+r)+k*N*N]<min) min =A[(r*N+r)+k*N*N];
          cout<<"A["<<(r*N+r)+k*N*N<<"] = "<<A[(r*N+r)+k*N*N]<<" ";
        }
        cout<<endl;
        mean=(double(min+max)/2.0;
        cout<<"MINIMO: "<<min<<endl<<"MASSIMO: "<<max<<endl<<"MEDIA: "<<mean<<endl;
        if(mean<=w) return true;
    }
    return false;
}
int main(){
    srand(time(NULL));
   int *p= new int[K*N*N];
    for(int k=0;k<K;k++){
        cout<<"livello"<<k<<endl;
        for(int r=0;r<N;r++){
            for(int c=0;c<N;c++){
                p[(r*N+c)+k*N*N] = rand()%10; 
                cout<<p[(r*N+c)+k*N*N]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    if(f(p,3)) cout<<"\nvero"<<endl;
        else cout<<"\nfalso"<<endl;
    return 0;
}