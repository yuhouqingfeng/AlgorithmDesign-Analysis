
#include<stdio.h>
#include<stdlib.h>
#define MAX 30
int main (void) {
    int n,i = 0,sum = 0,sn = 1,k,s,j;//n��ʾ��������i��¼������sum��ʼ�ܹ��͡�sn�˻��͡�
    printf("������������n��");
    scanf("%d",&n);
    int *an = (int *)malloc(sizeof(int)*MAX);
    an[0] = 0;
    do {
        sum += an[i];
        an[++i] = i+1;
    printf("++++++++%d",an[i]);
    }while((sum+an[i])<= n);
    j= s = i-1;//��ʾ���鵱ǰ����
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
