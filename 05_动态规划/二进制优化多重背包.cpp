#include<iostream>
#include<algorithm>

using namespace std;

const int N = 25000 , M = 2010; //N要使用题目中给出的数据带入"N * log(S)"向上取整得出

int n,m;
int v[N],w[N];
int f[N]; //使用一维的01背包

int main()
{
    cin>>n>>m;
    
    int cnt = 0;
    for(int i=1;i<=n;i++) //输入每个物品的体积，价值，数量限制
    {
        int a,b,s; //a是第i个物品的体积，b是第i个物品的价值，s是第i个物品的数量上限
        cin>>a>>b>>s;
        int k=1;
        while(k<=s)
        {
            cnt++;
            v[cnt] = a*k;
            w[cnt] = b*k;
            s -= k;
            k *= 2;
        }
        if(s>0) //最后一组，c个物品
        {
            cnt++;
            v[cnt] = a*s;
            w[cnt] = b*s;
        }
    }

    n = cnt;
    //下面开始01背包
    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
            f[j] = max(f[j],f[j-v[i]]+w[i]);
    cout << f[m] <<endl;

    return 0;
}