#include<stdio.h>
#include<stdlib.h>

//动态创建二维数组
int **Creatgroup1(int x,int y) {
    int i,j;
    int **m;
    m=(int**)malloc(x*sizeof(int*));
    for(i=0;i<=x;i++) {
        m[i]=(int*)malloc(y*sizeof(int));
        for(j=0;j<=y;j++) {
                m[i][j] = 0;
        }
    }
    return m;
}
//打印矩阵
void printRectangle1(int **m,int x,int y) {
 int i,j;
 printf("\n");
 for(i=0;i<x;i++) {
    for(j=0;j<y;j++) {
            printf("   %d   ",m[i][j]);
    }printf("\n \n");
 }
}
//创建A，B字符串
void CreatChars(char *a,char *b,int *na,int *nb) {
    printf("请输入字符串A:  ");
    do {
         (*na)++;
         scanf("%c",&a[*na]);
     }while(a[*na]!='\n');
     a[*na] = '\0';
     printf("\n请输入字符串B:  ");
    do {
         (*nb)++;
         scanf("%c",&b[*nb]);
     }while(b[*nb]!='\n');
     b[*nb] = '\0';
}

//获得三个数中最小值
int getMin1(int a,int b,int c) {
    int a1 = a>b?b:a;
    int b1 = b>c?c:a;
    return a1>b1?b1:a1;
}

//编辑距离问题
void CreatEditDistance(int **m,char *a,char *b,int x,int y) {
    int i,j;
    for(i = 0;i < x;i++) {
        for(j = 0;j < y;j++) {
            if(i==0 && j==0) m[i][j] = 0;
            else if(i == 0 && j != 0) m[i][j] = j;
            else if(i != 0 && j == 0) m[i][j] = i;
            else{
                if(a[i] == b[j]) m[i][j] = m[i-1][j-1];
                else{
                    m[i][j] = getMin1(m[i-1][j]+1,m[i-1][j-1]+1,m[i][j-1]+1);
                }
            }
        }
    }
}

int main (void) {
     int NumA = -1,NumB = -1;
     char *A = (char *)malloc(sizeof(char));
     char *B = (char *)malloc(sizeof(char));
     CreatChars(A,B,&NumA,&NumB);
//     printf("%s\n",A);
//     printf("%s",B);//printf("%d %d",NumA,NumB);
     int **M = Creatgroup1(NumA,NumB);
     CreatEditDistance(M,A,B,NumA,NumB);
//     printRectangle1(M,NumA,NumB);
 printf("\n%d\n",M[NumA-1][NumB-1]);
//     printf("\n\n======%d====\n\n",M[NumA-1][NumB-1]);
     return 0;
}
