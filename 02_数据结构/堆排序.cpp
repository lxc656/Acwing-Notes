#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int n,m;
int h[N],size;

void down(int u)
{
    int t = u; //t用于存放比较过程中值最小的节点的下标
    if(u*2<=size && h[u*2]<h[t]) t=u*2; //和左子节点比较
    if(u*2+1<=size && h[u*2+1]<h[t]) t=u*2+1; //和右子节点比较
    if(u!=t) //根节点若不是最小
    {
        swap(h[u],h[t]);
        down(t);
    }
}

void up(int u)
{
    while(u/2 && h[u/2]>h[u])
    {
        swap(h[u/2],h[u]);
        u/=2;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    size=n;
    
    for(int i=n/2;i;i--) down(i); //快速建堆

    while(m--)
    {
        printf("%d",h[1]); //输出根节点
        h[1]=h[size]; //删除根节点
        size--; 
        down(1);
    }

    return 0;
}