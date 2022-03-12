#include<iostream>

using namespace std;

const int N = 1000010;

int n,k;
int a[N],q[N]; //窗口对应的队列q的元素不是数列的值，而是下标

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    int hh=0,tt=-1;
    for(int i=0;i<n;i++)
    {
        if(hh<=tt && i-k+1>q[hh]) hh++; //判断队头是否已经超出窗口的范围
        while(hh<=tt && a[q[tt]]>=a[i]) tt--; //队尾元素若比a[i]大，则弹出
        q[++tt] = i; //将i加入队列q，并且注意，这行代码和下一行代码顺序不可颠倒，因为如果i是队头，那么有可能在下一行代码输出
        if(i>=k-1) printf("%d",a[q[hh]]);
    }

    puts("");

    return 0;
}