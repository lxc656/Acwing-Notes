#include<iostream>

using namespace std;

const int N = 10010 , M = 100010;

int n,m;
char p[N] , s[M];
int ne[N]; //本来应该是命名为next数组，但由于和C++的关键字重名，故命名为ne

int main()
{
    cin >> n >> p+1 >> m >> s+1; //输入到p+1和s+1是因为KMP中下标从1开始

    //求next[]的过程和匹配的过程类似
    for(int i=2,j=0;i<=n;i++) //next[1] = 0
    {
        while(j && p[i] != p[j+1]) j=ne[j];
        if(p[i] == p[j+1]) j++; 
        ne[i] = j;
    }

    //kmp匹配过程
    for(int i=1,j=0;i<=m;i++) //j从0开始是因为我们使用了j+1作为下标以便于子串移位后的匹配判断
    {
        while(j && s[i]!=p[j+1]) j = ne[j]; //while(子串还没移动到头且匹配失败)
        if(s[i] == p[j+1]) j++;
        if(j == n)
        {
            printf("%d",i-n); //输出要和题目要求一致
            j = ne[j]; //匹配成功之后要回退
        }
    }

    return 0;
}