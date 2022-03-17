//朴素做法
#include<iostream>
#include<algorithm>

using namespace std;

const int N=1010;

int n,m;
int v[N],w[N];
int f[N][N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];

    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++) //j是容量上限，要从0开始算
            for(int k=0;k*v[i]<=j;k++) //因为容量有限，所以第i个物品的数目存在上限，要进行判断
                                       //而且朴素完全背包里面用了三重循环，时间复杂度提升
                f[i][j]=max(f[i][j],f[i-1][j-v[i]*k]+w[i]*k);
    cout<<f[n][m]<<endl;

    return 0;
}