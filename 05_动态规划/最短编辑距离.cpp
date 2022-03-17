#include<iostream>
#include<algorithm>

using namespace std;

const int N = 10010;

int n,m;
char a[N],b[N];
int f[N][N];

int main()
{
    scanf("%d%s",&n,a+1); //状态转移方程里出现i-1，因此下标从1开始更合适
    scanf("%d%s",&m,b+1);

    for(int i=0;i<=m;i++) f[0][i]=i; //初始化边界条件
    for(int i=0;i<=n;i++) f[i][0]=i;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            f[i][j] = min(f[i-1][j]+1 , f[i][j-1]+1);
            if(a[i]==b[j]) f[i][j] = min(f[i][j] , f[i-1][j-1]);
            else f[i][j] = min(f[i][j] , f[i-1][j-1] + 1);
        }
    
    printf("%d\n",f[n][m]);

    return 0;
}