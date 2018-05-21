#include<stdio.h>
#include<stdlib.h>

//动态创建三维数组
int ***Creatgroup(int w,int b,int n) {
    int i,j,k;
    int ***m;
    m=(int***)malloc((n+1)*sizeof(int**));
    for(i=0;i<=n;i++) {
        m[i]=(int**)malloc((w+1)*sizeof(int*));
        for(j=0;j<=w;j++) {
            m[i][j]=(int*)malloc((b+1)*sizeof(int));
            for(k=0;k<=b;k++)
                m[i][j][k] = 0;
        }
    }
    return m;
}
//打印矩阵
void printRectangle(int ***m,int n,int w,int b) {
 int i,j,k;
 for(i=1;i<=n;i++) {
    for(j=1;j<=w;j++) {
        for(k=1;k<=b;k++) {
            printf("   %d  ",m[i][j][k]);
        }printf("\n");
        printf("jjjj = %d\n\n",j);
    }printf("\n=========iii = %d\n",i);
 }
}
//得到最小值
int getMin(int a,int b) {
    if(a>=b) return b;
    else return a;
}
//得到最大值
int getMax(int a,int b) {
    if(a>=b) return a;
    else return b;
}
//计算背包问题
void Knapsack(int ***m,int w1[],int b1[],int v1[],int n,int w2,int b2) {
    int i,j,k;
    int jMax = getMin(w1[n]-1,w2);
    int kMax = getMin(b1[n]-1,b2);
    for(j = w1[n];j<=w2;j++) {
        for(k = b1[n];k<=b2;k++)
            m[n][j][k] = v1[n];
    }
    for(i = n-1;i>=1;i--) {
       jMax = getMin(w1[i]-1,w2);
       kMax = getMin(b1[i]-1,b2);
       for(j = 1;j<=jMax;j++) {
            for(k = 1;k<=b2;k++)
                m[i][j][k] = m[i+1][j][k];
       }
       for(j = jMax+1;j <= w2;j++) {
            for(k = 1;k <= kMax;k++)
                 m[i][j][k] = m[i+1][j][k];
       }
       for(j = w1[i];j<=w2;j++) {
            for(k = b1[i];k<= b2;k++) {
                    int a,b;
                    a = j - w1[i];
                    b = k-b1[i];
                    m[i][j][k] = getMax(m[i+1][j][k],m[i+1][a][b]+v1[i]);
            }
       }
    }
}
int  main(void) {
   int i,W,B,n;
   printf("请输入背包的容量和容积：（1 3）：");
   scanf("%d %d",&W,&B);
   printf("\n请输入物品的个数：");
   scanf("%d",&n);
   int *w = (int *)malloc((n+1)*sizeof(int));
   int *b = (int *)malloc((n+1)*sizeof(int));
   int *v = (int *)malloc((n+1)*sizeof(int));
   for(i=1;i<=n;i++) {
     printf("\n请输入第%d个物品的重量、体积、价值：（1 2 3）",i+1);
     scanf("%d %d %d",&w[i],&b[i],&v[i]);
     printf("\n");
   }
   int ***M = Creatgroup(W,B,n);
   Knapsack(M,w,b,v,n,W,B);
//   printRectangle(M,n,W,B);
    printf("\n%d",M[1][W][B]);
//   printf("\n\n =======%d=======",M[1][W][B]);
}
