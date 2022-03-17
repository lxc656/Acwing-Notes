#include<iostream>
#include<algorithm>

using namespace std;

const int N=1010;

int n,m;
int v[N],w[N];
int f[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];

    for(int i=1;i<=n;i++)
        for(int j=v[i];j<=m;j++) //此处不必像01背包一样倒序遍历，此处当我们计算f[j]时，f[j-v[i]]已经被计算过了，
                                 //这相当于拿第i层的f[j-v[i]]去更新第i层的f[j]，和完全背包的思想一致
        {
            f[j]=max(f[j],f[j-v[i]]+w[i]); 
        }
    cout<<f[m]<<endl;

    return 0;
}