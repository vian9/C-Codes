#include <stdio.h>

int main(){
    
    printf("Enter size of square array: ");
    int n; scanf("%d", &n);

    int arr[n][n];

    printf("Enter array (%dx%d): \n", n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    return 0;
}