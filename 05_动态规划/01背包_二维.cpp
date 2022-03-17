//二维的动态规划
#include<iostream>
#include<algorithm>

using namespace std;

const int N=1010;

int n,m; //n用来表示所有的物品个数，m来表示所有的物品的总容量上限
int v[N],w[N]; //数组v和w分别表示物品的体积和价值
int f[N][N]; //二维数组f用来表示动态规划当中的状态集合，并且状态f[0][0~m]
             //应该为0，正好这里让二维数组f做全局变量，可以达到这个目的

int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];

    for(int i=1;i<=n;i++) //开始计算除了f[0][0~m]以外其他f数组的元素的值
        for(int j=0;j<=m;j++)
        {
            f[i][j] = f[i-1][j];
            if(j>=v[i]) f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]); 
            //上面这一步非常重要，因为可能存在第i个物品的体积大于总体积上限，所以要先判断
        }
    cout<<f[n][m]<<endl;

    return 0;
}