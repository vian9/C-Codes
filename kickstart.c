#include<stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    int y = 0;
    int N;
    int num [N];
    for(int j=1; j<=N; j++){
        num [j] = j+1;
        if(j==N) num[j]=1;
    }
    scanf("%d",&N);
    for(int x =1; x<=N; x++){
        if( num [x] > x){
            y++;
        }
    }
    printf("%d \n", &y);
}