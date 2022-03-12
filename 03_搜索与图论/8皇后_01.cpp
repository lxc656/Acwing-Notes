#include<iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N]; //表示解决方案
bool col[N],dg[N],udg[N]; //dg表示对角线(左上至右下)，udg表示反对角线(左下至右上)
/*col[i用于]表示第i列是否已经存在皇后，dg[i]用于表示第i号对角线是否已经存在皇后，
udg[i]用于表示第i号反对角线是否已经存在皇后*/

void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++) puts(g[i]);
        puts("");
        return;
    }
    for(int i=0;i<n;i++)
        if(!col[i]&&!dg[u+i]&&!dg[n-u+i])
        {
            g[u][i]='Q';
            col[i]=dg[u+i]=udg[n-u+i]=true;
            dfs(u+1);
            col[i]=dg[u+i]=udg[n-u+i]=false;
            g[u][i]='.';
        }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;i<n;j++)
            g[i][j]='.';
    dfs(0);

    return 0;
}