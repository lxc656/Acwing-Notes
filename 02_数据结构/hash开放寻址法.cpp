#include<iostream>
#include<cstring>

using namespace std;

const int N = 200003; //大于20w的最小质数
int null = 0x3f3f3f3f; //这个数的大小在-10^9~10^9之外，若h[x]==null，则表示h[x]所在的位置没有被占用

int h[N];

bool find(int x) //若x在哈希表里，则find函数返回其位置，若x不在哈希表里，则find返回它应该被存储的位置
{
    int k = (x%N + N)%N;
    while(h[k]!=null && h[k]!=x)
    {
        k++;
        if(k==N) k=0;
    }
    return k;
}

int main()
{
    int n;
    scanf("%d",&n);
    memset(h , 0x3f , sizeof h);//初始化h数组，使用0x3f的原因和前面null值的设置有关

    while(n--)
    {
        char op[2];
        int x;
        scanf("%s%d" , op , &x);

        int k = find(x);
        if(*op == 'I') h[k] = x;
        else
        {
            if(h[k]!=null) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}