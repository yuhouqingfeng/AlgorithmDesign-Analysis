#include<stdio.h>
#include<stdlib.h>
#define MAX 20

void  sortgroup(int *a,int n1) {
    int i,j,m;
    for(i = 1; i <= n1+1; i++) {
        for(j = 1; j <= n1-i; j++) {
            if(a[j]>a[j+1]) {
                m = a[j]; a[j] = a[j+1];a[j+1] = m;
            }
        }
    }
}

void printgroup(int *a,int n1) {
    int i;
    for(i = 1; i <= n1; i++) {
        printf(" %d ",a[i]);
    }
}

int main (void) {
    char h;
    int i = 0,j,k;
    long long int sum  = 0;
    int *an = (int *)malloc(sizeof(int)*MAX) ;
    printf("请输入n位正整数a：（1345145）：");
    do {
        h = getchar();
        an[++i] = h-'0';
    }while(h != '\n');
    sortgroup(an,i-1);
//    printgroup(an,i-1);
    printf("请输入去掉的k个数字：");
    scanf("%d",&k);
    int n = i-1-k;
    for(j = 1;j<=n;j++) {
        sum *= 10;
        sum += an[j];
    }
    printf("===========%ld",sum);
}
