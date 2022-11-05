#include<iostream>
using namespace std;

void mulMat(int a[][], int b[][] , int c[][]) {
    c[0][0]=(a[0][0]*b[0][0])+(a[0][1]*b[1][0]);
    c[0][1]=(a[0][0]*b[0][1])+(a[0][1]*b[1][1]);
    c[1][0]=(a[2][0]*b[0][0])+(a[1][1]*b[1][0]);
    c[1][1]=(a[2][0]*b[0][1])+(a[1][1]*b[1][0]);
    return;
}

void addMatrix(int a[][], int b[][] , int c[][]){
    for (i = 0; i < r; ++i){
    for (j = 0; j < c; ++j) {
      c[i][j] = a[i][j] + b[i][j];
    }
    }
    return;
}
void subtractMatrix(int a[][], int b[][] , int c[][]){
    for (i = 0; i < r; ++i){
    for (j = 0; j < c; ++j) {
      c[i][j] = a[i][j] - b[i][j];
    }
    }
    return;
}

void strassenMatrix(int a[][],int b[][],int n){
    int i=0, j=0;
    int c[n][n];
    //Base Case
   /* if (n==2){
        c[0][0]=(a[0][0]*b[0][0])+(a[0][1]*b[1][0]);
        c[0][1]=(a[0][0]*b[0][1])+(a[0][1]*b[1][1]);
        c[1][0]=(a[2][0]*b[0][0])+(a[1][1]*b[1][0]);
        c[1][1]=(a[2][0]*b[0][1])+(a[1][1]*b[1][0]);
        return;
    }*/
    int mid = n/2;
    int A1[2][2], A2[2][2], A3[2][2], A4[2][2];
    int B1[2][2], B2[2][2], B3[2][2], B4[2][2];
    
    for (int i = 0; i < 2; i++)
    {
       for (int j = 0; j < 2; j++)
       {
          A1[i][j] = a[i][j];
          B1[i][j] = b[i][j];
          A2[i][j] = a[i][j+2];
          B2[i][j] = b[i][j+2];
          A3[i][j] = a[i+2][j];
          B3[i][j] = b[i+2][j];
          A4[i][j] = a[i+2][j+2];
          B4[i][j] = b[i+2][j+2];
       }
       
    } 
    int temp1[2][2];
    int temp1[2][2];
    int P, Q,R,S[2][2],T[2][2],U[2][2],V[2][2];
    temp[2][2] = addMatrix(A1, A2, temp);
}

int main() {


return 0;
}