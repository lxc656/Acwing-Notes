#include<iostream>
#include<cstring>

using namespace std;

const int N = 100003;

int h[N] , e[N] , ne[N] , idx;

void insert(int x)
{
    int k = (x%N + N)%N; //这么做是为了防止x是负数时哈希值k是负数
    
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++; //使用头插法把x插入链表
}

bool find(int x)
{
    int  k = (x%N + N)%N;
    for(int i=h[k];i!=-1;i=ne[i])
        if(e[i]==x) return true;
    return false;
}

int main()
{
    int n;
    scanf("%d",&n);
    memset(h , -1 , sizeof h); /*清空数组，因为h数组存储的是链表的head结点的下标，
    因此根据链表初始化的原则要把h数组所有元素初始化为-1*/

    while(n--)
    {
        char op[2];
        int x;
        scanf("%s%d" , op , &x);

        if(*op == 'I') insert(x);
        else
        {
            if(find(x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}