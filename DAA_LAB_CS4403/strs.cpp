#include <iostream>

using namespace std;

int getNumSize(int num) {
    if (num == 0)
        return 1;
    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }
    if (num < 0)
        return count + 1;
    return count;
}


int getMaxNumSize(int **m, int n) {
    int maxim = m[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            maxim = max(maxim, m[i][j]);
        }
    }
    maxim = getNumSize(maxim);
    if (maxim < 6)
        return 6;
    return getNumSize(maxim * maxim);
}

void printMatrix(int **m, int row, int col) {

    int spaces = getMaxNumSize(m, col);

    for (int i = 0; i < row; i++) {
        cout << "|";
        for (int j = 0; j < col; j++) {
            cout << m[i][j];
            if (j != col - 1)
                for (int s = 0; s < (spaces - getNumSize(m[i][j])); s++)
                    cout << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
}

int **add(int **mat1, int **mat2, int size) {
    int **mat = new int *[size];
    for (int i = 0; i < size; i++) {
        mat[i] = new int[size];
        for (int j = 0; j < size; j++) {
            mat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return mat;
}

int **sub(int **mat1, int **mat2, int size) {
    int **mat = new int *[size];
    for (int i = 0; i < size; i++) {
        mat[i] = new int[size];
        for (int j = 0; j < size; j++) {
            mat[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return mat;
}

int get_next_power(int a, int b, int c) {
    int max_num = max(max(a, b), c);
    int n = 2;
    while (n < max_num)
        n *= 2;
    cout << "Matrix size: " << n << endl;
    return n;

}

void createMatrix(int **to, int **from, int size, int row, int col) {
    for (int i = 0; i < size; ++i) {
        {
            to[i] = new int[size];
            for (int j = 0; j < size; ++j) {
                to[i][j] = from[i + row][j + col];
            }
        }

    }
}


//To calculate result of 2 by 2 matrix
int **strassensMultiply2by2(int **mat1, int **mat2) {

    int m1, m2, m3, m4, m5, m6, m7;
    m1 = (mat1[0][0] + mat1[1][1]) * (mat2[0][0] + mat2[1][1]);
    m2 = (mat1[1][0] + mat1[1][1]) * mat2[0][0];
    m3 = mat1[0][0] * (mat2[0][1] - mat2[1][1]);
    m4 = mat1[1][1] * (mat2[1][0] - mat2[0][0]);
    m5 = (mat1[0][0] + mat1[0][1]) * mat2[1][1];
    m6 = (mat1[1][0] - mat1[0][0]) * (mat2[0][0] + mat2[0][1]);
    m7 = (mat1[0][1] - mat1[1][1]) * (mat2[1][0] + mat2[1][1]);

    int **result = new int *[2];
    for (int i = 0; i < 2; i++)
        result[i] = new int[2];

    result[0][0] = m1 + m4 - m5 + m7;
    result[0][1] = m3 + m5;
    result[1][0] = m2 + m4;
    result[1][1] = m1 + m3 - m2 + m6;

    return result;

}


// to divide the matrix
int **strassenMulti(int **mat1, int **mat2, int size) {
    if (size > 2) {
        int **result = new int *[size];
        for (int i = 0; i < size; ++i)
            result[i] = new int[size];

        int mid = size / 2;
        int **a = new int *[mid], **b = new int *[mid], **c = new int *[mid], **d = new int *[mid], **e = new int *[mid], **f = new int *[mid], **g = new int *[mid], **h = new int *[mid];

//        Dividing both the matrix into 4 halves
        createMatrix(a, mat1, mid, 0, 0);
        createMatrix(b, mat1, mid, 0, mid);
        createMatrix(c, mat1, mid, mid, 0);
        createMatrix(d, mat1, mid, mid, mid);
        createMatrix(e, mat2, mid, 0, 0);
        createMatrix(f, mat2, mid, 0, mid);
        createMatrix(g, mat2, mid, mid, 0);
        createMatrix(h, mat2, mid, mid, mid);

        // Applying Strassen's formula
        int **m1 = strassenMulti(add(a, d, mid), add(e, h, mid), mid);
        int **m2 = strassenMulti(add(c, d, mid), e, mid);
        int **m3 = strassenMulti(a, sub(f, h, mid), mid);
        int **m4 = strassenMulti(d, sub(g, e, mid), mid);
        int **m5 = strassenMulti(add(a, b, mid), h, mid);
        int **m6 = strassenMulti(sub(c, a, mid), add(e, f, mid), mid);
        int **m7 = strassenMulti(sub(b, d, mid), add(g, h, mid), mid);


        int **p1 = add(sub(add(m1, m4, mid), m5, mid), m7, mid);
        int **p2 = add(m3, m5, mid);
        int **p3 = add(m2, m4, mid);
        int **p4 = add(sub(add(m1, m3, mid), m2, mid), m6, mid);

        // Creating the result matrix

        for (int i = 0; i < mid; ++i) {
            for (int j = 0; j < mid; ++j) {
                result[i][j] = p1[i][j];
                result[i][j + mid] = p2[i][j];
                result[i + mid][j] = p3[i][j];
                result[i + mid][j + mid] = p4[i][j];
            }
        }
        return result;
    } else
        return strassensMultiply2by2(mat1, mat2);

}


int main() {

    int m1, n1, m2, n2, n;

    cout << "Enter the number of rows and cols of matrix 1";
    cin >> m1 >> n1;
    cout << "Enter the value of rows and cols of matrix 2";
    cin >> m2 >> n2;
    if (n1 != m2) {
        cout << "\nInvalid matrix size";
        return 0;
//        Result will be m1 x n2
    }
    n = get_next_power(m1, n1, n2);


    int **mat1 = new int *[n];
    cout << "For first matrix" << endl;
    for (int i = 0; i < m1; i++) {
        mat1[i] = new int[n];
        for (int j = 0; j < n1; j++) {
            cout << "Enter the " << i << " " << j << " element\n";
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
    cout << "For second matrix" << endl;
    for (int i = 0; i < m2; i++) {
        mat2[i] = new int[n];
        for (int j = 0; j < n2; j++) {
            cout << "Enter the " << i << " " << j << " element\n";
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


    cout << "Matrix 1:\n";
    printMatrix(mat1, n, n);
    cout << "Matrix 2:\n";
    printMatrix(mat2, n, n);
    int **result = strassenMulti(mat1, mat2, n);
    cout << "Matrix 1  X  Matrix 2:\n";
    printMatrix(result, m1, n2);
    return 0;
}