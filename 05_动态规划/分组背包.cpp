#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100;

int n,m;
int v[N][N],w[N][N],s[N]; //s[i]表示第i组里共有多少个物品
int f[N]; //直接写从两维优化成一维之后的

int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>s[i]; //输入第i组里共有多少个物品
        for(int j=0;j<s[i];j++)
            cin>>v[i][j]>>w[i][j];
    }

    for(int i=1;i<=n;i++)
        for(int j=m;j>=0;j++)
            for(int k=0;k<s[i];k++)
                if(v[i][k]<=j)
                    f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
    cout<<f[m]<<endl;

    return 0;                
}