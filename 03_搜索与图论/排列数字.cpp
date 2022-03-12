#include<iostream>

using namespace std;

const int N=10;

int n;
int path[N]; //用于存储当前所处的路径
bool st[N]; //用于哪些点在路径中已经被用过了

void dfs(int u)
{
    if(u==n) /*u==n表示搜索到了最后的位置，也就是dfs(n-1)在进行最后一层的搜索时，
    函数中调用了dfs(n)*/
    {
        for(int i=0;i<n;i++) printf("%d",path[i]);
        puts("");
        return;
    }
    for(int i=1;i<=n;i++)
        if(!st[i])
        {
            path[u] = i;
            st[i] = true;
            dfs(u+1);
            st[i] = false; //用于回溯时的恢复现场
        }
}

int main()  
{
    cin>>n;
    dfs(0); //从第0个位置开始dfs搜索
    return 0;
}