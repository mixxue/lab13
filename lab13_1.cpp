#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum = 0;
    for (int i = 0; i < N; i++){
        sum += A[i];
    }
    B[0] = sum / N;

    double sumSD = 0;
    for (int i = 0; i < N; i++){
       sumSD += pow(A[i] - B[0], 2);
    }
    B[1] = sqrt(sumSD / N);

    double sumGD = 1;
    for (int i = 0; i < N; i++){
       sumGD *= A[i];
    }
    B[2] = pow(sumGD, 1.0 / N);
    
    double sumHM = 0;
    for (int i = 0; i < N; i++){
        sumHM += 1.0 / A[i];
    }
    B[3] = N / sumHM;

    B[4] = A[0];
    B[5] = A[0];
    for(int i = 1; i < N; i++){
   if (A[i] > B[4]){
            B[4] = A[i]; 
        }
        if (A[i] < B[5]){
            B[5] = A[i]; 
        }
    }
}