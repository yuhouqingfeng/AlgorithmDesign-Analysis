#include<stdio.h>
#include<stdlib.h>

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

int calculate (int *a,int n1,int s1) {
    int i=1,sum = 0,x,y,d,e,cont = 1,time;
    d = time = s1; // x表示商，y表示余数、d表示间隔 // 56 12 1 99 1000 234 33 55 99 812
    e = x = n1/s1;
    y = n1%s1;printf("%d",y);
    while(time > 0) {
            if(y!=0) {
                e = n1/s1;
                while (i <= n1 && e >= 0) {
                    sum +=  (e+1)*a[i];  printf("\n=========y = %d  sum = %d  ",y,sum);
                     i+=d; e--;
                }y--;
            }
            if(y == 0) {
                e = n1/s1;
                while (i <= n1 && e >= 1) {
                    sum +=  e*a[i];printf("\n\n\n************ sum = %d  ",sum);
                    i+=d;e--;
                }
            }
        time--;cont++; i = cont;
    }
    printf("\n\n %d ",sum);
    return sum;
}

int main () {
    int n,s,i,someall;
    printf("请输入有几个顾客和有几处服务：（2 3）");
    scanf("%d %d",&n,&s);
    int *an = (int *)malloc (sizeof(int)*(n+1));
    printf("请输入%d个顾客服务时间：",n);
    for(i = 0;i <= n ;i++) {
        if(i==0) an[0] = 0;
        else {
            scanf("%d",&an[i]);
        }
    }
    sortgroup(an,n);
    printgroup(an,n);
    someall = calculate(an,n,s);
}
