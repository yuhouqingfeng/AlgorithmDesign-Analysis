
#include<stdio.h>
#include<stdlib.h>
#define MAX 30
int main (void) {
    int n,i = 0,sum = 0,sn = 1,k,s,j;//n表示正整数、i记录个数、sum开始总共和、sn乘积和、
    printf("请输入正整数n：");
    scanf("%d",&n);
    int *an = (int *)malloc(sizeof(int)*MAX);
    an[0] = 0;
    do {
        sum += an[i];
        an[++i] = i+1;
    printf("++++++++%d",an[i]);
    }while((sum+an[i])<= n);
    j= s = i-1;//表示数组当前个数
    printf("\n******sum = %d\n",sum);
    k = n-sum;
    while(k >= 1) {
            an[s] += 1;
            s--;
            if(s == 0) s = j;
            k--;
    }
    for(j = 1;j<= i-1;j++) {
        sn *= an[j];
    }
    printf("\n******%d",sn);
}
