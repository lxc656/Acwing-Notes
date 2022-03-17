//一维的动态规划
#include<iostream>
#include<algorithm>

using namespace std;

const int N=1010;

int n,m; //n用来表示所有的物品个数，m来表示所有的物品的总容量上限
int v[N],w[N]; //数组v和w分别表示物品的体积和价值
int f[N];
int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];

//下面这段是将原代码直接降到一维的结果，可是逻辑上面有一点问题
    /*for(int i=1;i<=n;i++) 
        for(int j=v[i];j<=m;j++) //因为 j<v[i]时无意义,且现在变成了一维，
                                 //二维情况下的 f[i][j] = f[i-1][j]; 这句代码
                                 //降到一维就没有了意义，所以就让j从v[i]开始
        {
            f[j]=max(f[j],f[j-v[i]]+w[i]);
            //二维情况下的代码:f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
            //将二维的情况直接降到一维，应该变成
            //f[j]=max(f[j],f[j-v[i]]+w[i]); j-v[i]小于j，并且j是从小到大枚举的，
            //因此在计算f[j]时,f[j-v[i]]在上一层已经被计算过了(因为正好减去v[i]所以是上一层)，
            //无法实现动态规划中的“拆分成子集然后去考虑”的思想
        }*/
//因此应该这样做
    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
        f[j]=max(f[j],f[j-v[i]]+w[i]); //这样的话，计算f[j]时，f[j-v[i]]还没被计算
    cout<<f[m]<<endl;
    return 0;
}