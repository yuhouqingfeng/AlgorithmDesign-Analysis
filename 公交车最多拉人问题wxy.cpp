#include<stdio.h>
#include<stdlib.h>

//动态创建二维数组
int **Creatgroup2(int x,int y) {
    int i,j;
    int **m;
    m=(int**)malloc((x+1)*sizeof(int*));
    for(i=0;i<=x;i++) {
        m[i]=(int*)malloc((y+1)*sizeof(int));
        for(j=0;j<=y;j++) {
                m[i][j] = 0;
        }
    }
    return m;
}
//打印矩阵
void printRectangle2(int **m,int x,int y) {
 int i,j;
 printf("\n");
 for(i=1;i<=x;i++) {
    for(j=1;j<=y;j++) {
            printf("   %d   ",m[i][j]);
    }printf("\n \n");
 }
}
//得到最大值
int getMax1(int a,int b) {
    if(a>=b) return a;
    else return b;
}
//矩阵途径最大值
void BusMaximumPeople(int **P,int **m,int x,int y) {
    int i,j;
    for(i = 1;i <= x ;i++) {
        for(j = 1; j <= y;j++) {
            if(i == 1 && j ==1 ) m[i][j] = P[i][j];
            else if(i==1) m[i][j] = m[i][j-1]+P[i][j];
            else if(j==1) m[i][j] = m[i-1][j]+P[i][j];
            else {
                m[i][j] = (getMax1(m[i-1][j],m[i][j-1])+P[i][j]);
            }
        }
    }
}
//车站行驶逆推
void InferBack(int **P,int **m,int **a,int x,int y) {
    int i = x,j = y;
    a[x][y] = 1;
    while (i>=1 || j >=1) {
        if((m[i][j] == m[i][j-1] )|| (m[i][j] == (m[i][j-1] + P[i][j]))) {
               j--;a[i][j] = 1;
            }
         if((m[i][j] == m[i-1][j]) || (m[i][j] == (m[i-1][j] + P[i][j]))) {
               i--;a[i][j] = 1;
            }
    }
}

int main(void) {
    int i,j;
    int m,n;
    printf("请输入人数矩阵的行数和列数（3 4）：");
    scanf("%d %d",&m,&n);
    int **PersonalG = Creatgroup2(m,n);
    printf("请输入人数矩阵：");
    for(i = 1;i <= m ;i++) {
        for(j = 1; j<= n;j++) {
            scanf("%d",&PersonalG[i][j]);
        }
    }
    int **M = Creatgroup2(m,n);
    BusMaximumPeople(PersonalG,M,m,n);
//    printRectangle2(M,m,n);
    printf("\n\n=========%d ======\n\n",M[m][n] );
    int **A = Creatgroup2(m,n);
    InferBack(PersonalG,M,A,m,n);
    printRectangle2(A,m,n);
}





