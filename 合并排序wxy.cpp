
#include<stdio.h>
#include<stdlib.h>

//获得有序数列下标
int  getPoint(int a[],int x[],int n)
{
    int i = 0, j = 1;
    int count1 = 1;
    x[0] = 0;
    while(i+1<n)
    {
        if(a[i] <= a[i+1])
            i++;
        else{
            x[j] = i;j++;
            i++;count1++;
        }
    }
    x[j] = n-1;
    return j+1;
}
// 合并数组到d中
void Merge(int c[],int d[],int l,int m,int r)
{
    int i = l, j = m+1, k = l;
    while(i<=m && j<=r)
    {
        if(c[i]<=c[j])
            d[k++] = c[i++];
        else
            d[k++] = c[j++];
    }
    int q;
    if(i>m)
        for(q = j;q<=r;q++)
            d[k++] = c[q];
    else
        for(q = i;q<=m;q++)
        d[k++] = c[q];
    for(i = l;i<= r;i++)
        c[i] = d[i];
}
void MergePass(int a[],int b[],int x[],int n,int length)
{
    int l = 0,m = l+1,r = l+2;
    while (r<=length)
    {
        if(l == 0)
        {
            Merge(a,b,x[l],x[m],x[r]);
        }
        else
        {
            Merge(a,b,l,x[m],x[r]);
        }
         l = x[r]+1;m = m+2;r = r+2;
    }
}
int main(void)
{
    int i,n,count1;
    printf("请输入数组长度：");
    scanf("%d",&n);
    while(n<=0)
   {
       printf("输入错误，重新输入！：");
       scanf("%d",&n);
   }
    int *a  = (int*)malloc(n*sizeof(int));
	int *b  = (int*)malloc(n*sizeof(int));
	int *x  = (int*)malloc(n*sizeof(int));
    printf("请输入数组：");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    count1 = getPoint(a,x,n);
//    for(i=0;i<count1;i++)
//    {
//        printf(" %d ",x[i]);
//    }printf("\n");
     while(count1 > 2)
    {
        MergePass(a,b,x,n,count1-1);
        count1 = getPoint(a,x,n);
    }
    for(i=0;i< n ;i++)
        printf(" %d ",a[i]);
}



