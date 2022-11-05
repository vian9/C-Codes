#include <iostream>
using namespace std;

int ** addMatrix(int **mat1, int **mat2, int size) {
    int **mat = new int *[size];
    for (int i = 0; i < size; i++) {
        mat[i] = new int[size];
        for (int j = 0; j < size; j++) {
            mat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return mat;
}

int ** subtractMatrix(int **mat1, int **mat2, int size) {
    int **mat = new int *[size];
    for (int i = 0; i < size; i++) {
        mat[i] = new int[size];
        for (int j = 0; j < size; j++) {
            mat[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return mat;
}

void makeMatrix(int **to, int **from, int size, int row, int col) {
    for (int i = 0; i < size; ++i) {
        {
            to[i] = new int[size];
            for (int j = 0; j < size; ++j) {
                to[i][j] = from[i + row][j + col];
            }
        }

    }
}

int ** strassensMultiply2by2(int **mat1, int **mat2) {

    int P,Q,R,S,T,U,V;
    P = (mat1[0][0] + mat1[1][1]) * (mat2[0][0] + mat2[1][1]);
    Q = (mat1[1][0] + mat1[1][1]) * mat2[0][0];
    R = mat1[0][0] * (mat2[0][1] - mat2[1][1]);
    S = mat1[1][1] * (mat2[1][0] - mat2[0][0]);
    T = (mat1[0][0] + mat1[0][1]) * mat2[1][1];
    U = (mat1[1][0] - mat1[0][0]) * (mat2[0][0] + mat2[0][1]);
    V = (mat1[0][1] - mat1[1][1]) * (mat2[1][0] + mat2[1][1]);

    int **result = new int *[2];
    for (int i = 0; i < 2; i++)
        result[i] = new int[2];

    result[0][0] = P+S-T+V;
    result[0][1] = R+T;
    result[1][0] = Q+S;
    result[1][1] = P+R-Q+U;

    return result;

}

int ** strassenMulti(int **mat1, int **mat2, int size) {
    if(size<=2){
        return strassensMultiply2by2(mat1, mat2);
    } else {
        int **result = new int *[size];
        for (int i = 0; i < size; ++i)
            result[i] = new int[size];

        int mid = size / 2;
        int **a11 = new int *[mid];
        int **a12 = new int *[mid];
        int **a21 = new int *[mid]; 
        int **a22 = new int *[mid];
        int **b11 = new int *[mid]; 
        int **b12 = new int *[mid]; 
        int **b21 = new int *[mid]; 
        int **b22 = new int *[mid];

        makeMatrix(a11, mat1, mid, 0, 0);
        makeMatrix(a12, mat1, mid, 0, mid);
        makeMatrix(a21, mat1, mid, mid, 0);
        makeMatrix(a22, mat1, mid, mid, mid);
        makeMatrix(b11, mat2, mid, 0, 0);
        makeMatrix(b12, mat2, mid, 0, mid);
        makeMatrix(b21, mat2, mid, mid, 0);
        makeMatrix(b22, mat2, mid, mid, mid);

        int **P = strassenMulti(addMatrix(a11, a22, mid), addMatrix(b11, b22, mid), mid);
        int **Q = strassenMulti(addMatrix(a21, a22, mid), b11, mid);
        int **R = strassenMulti(a11, subtractMatrix(b12, b22, mid), mid);
        int **S = strassenMulti(a22, subtractMatrix(b21, b11, mid), mid);
        int **T = strassenMulti(addMatrix(a11, a12, mid), b22, mid);
        int **U = strassenMulti(subtractMatrix(a21, a11, mid), addMatrix(b11, b12, mid), mid);
        int **V = strassenMulti(subtractMatrix(a12, a22, mid), addMatrix(b21, b22, mid), mid);


        int **p1 = addMatrix(subtractMatrix(addMatrix(P, S, mid), T, mid), V, mid);
        int **p2 = addMatrix(R, T, mid);
        int **p3 = addMatrix(Q, S, mid);
        int **p4 = addMatrix(subtractMatrix(addMatrix(P, R, mid), Q, mid), U, mid);

        for (int i = 0; i < mid; ++i) {
            for (int j = 0; j < mid; ++j) {
                result[i][j] = p1[i][j];
                result[i][j + mid] = p2[i][j];
                result[i + mid][j] = p3[i][j];
                result[i + mid][j + mid] = p4[i][j];
            }
        }
        return result;
    }   

}

void printMatrix(int **m, int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << m[i][j];
            cout << " ";
        }
        cout << "" << endl;
    }
    cout << endl;
}

int get_next_power(int a, int b, int c) {
    int max_num = max(max(a, b), c);
    int n = 2;
    while (n < max_num)
        n *= 2;
    cout << "Matrix size: " << n << endl;
    return n;
}

int main() {

    int m1, n1, m2, n2, n;
    cout<<endl;
    cout << "Enter the number of rows and cols of matrix 1: ";
    cin >> m1 >> n1;
    cout << "Enter the value of rows and cols of matrix 2: ";
    cin >> m2 >> n2;
    if (n1 != m2) {
        cout << "\nInvalid matrix size";
        return 0;
    }
    n = get_next_power(m1, n1, n2);


    int **mat1 = new int *[n];
    cout << "For first matrix enter the element" << endl;
    for (int i = 0; i < m1; i++) {
        mat1[i] = new int[n];
        for (int j = 0; j < n1; j++) {
            cin >> mat1[i][j];
        }
        for (int j = n1; j < n; j++)
            mat1[i][j] = 0;
    }
    for (int i = m1; i < n; ++i) {
        mat1[i] = new int[n];
        for (int j = 0; j < n; j++)
            mat1[i][j] = 0;
    }


    int **mat2 = new int *[n];
    cout << "For second matrix enter the number" << endl;
    for (int i = 0; i < m2; i++) {
        mat2[i] = new int[n];
        for (int j = 0; j < n2; j++) {
            cin >> mat2[i][j];
        }
        for (int j = n2; j < n; j++)
            mat2[i][j] = 0;
    }
    for (int i = m2; i < n; ++i) {
        mat2[i] = new int[n];
        for (int j = 0; j < n; j++)
            mat2[i][j] = 0;
    }


    cout << "Matrix 1 is :\n";
    printMatrix(mat1, n, n);
    cout << "Matrix 2 is :\n";
    printMatrix(mat2, n, n);
    int **result = strassenMulti(mat1, mat2, n);
    cout << "Matrix 1 Multiplied by Matrix 2 is :\n";
    printMatrix(result, m1, n2);
    cout<<endl;
    return 0;
}