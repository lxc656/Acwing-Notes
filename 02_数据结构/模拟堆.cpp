#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

const int N = 100010;

int n,m;
int h[N],ph[N],hp[N],size;

void heap_swap(int a,int b)
{
    swap(ph[hp[a]],ph[hp[b]]); 
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}

void down(int u)
{
    int t = u; //t用于存放比较过程中值最小的节点的下标
    if(u*2<=size && h[u*2]<h[t]) t=u*2; //和左子节点比较
    if(u*2+1<=size && h[u*2+1]<h[t]) t=u*2; //和右子节点比较
    if(u!=t) //根节点若不是最小
    {
        heap_swap(u,t);
        down(t);
    }
}

void up(int u)
{
    while(u/2 && h[u/2]>h[u])
    {
        heap_swap(u/2,u);
        u/=2;
    }
}

int main()
{
    int n, m = 0; //m用来记录当前被插入的数是第几个被插入的
    scanf("%d", &n);
    while (n -- )
    {
        char op[5];
        int k, x;
        scanf("%s", op);
        if (!strcmp(op, "I"))
        {
            scanf("%d", &x);
            size ++ ;
            m ++ ;
            ph[m] = size, hp[size] = m; 
            h[size] = x;
            up(size);
        }
        else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, size);
            size -- ;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, size);
            size -- ;
            up(k);
            down(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }

    return 0;
}
