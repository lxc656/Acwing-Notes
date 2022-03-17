#include<iostream>
#include<algorithm>

using namespace std;

const int N = 310;

int n;
int s[N]; //前缀和
int f[N][N];

//核心思想是按照区间长度从小到大来枚举(即从1开始)，这样的话在计算某个状态时，
//其所依赖的状态已经被算出
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);

    for(int i=1;i<=n;i++) s[i]+=s[i-1];

    for(int len=2;len<=n;len++) //枚举各种区间长度，区间长为1时不需要枚举，
                                //因为全局数组f[][]本来就已经将这种情况初始化为0
        for(int i=1;i+len-1<=n;i++) //枚举起点
        {
            int l=i , r=i+len-1;
            f[l][r] = 1e8; //要先初始化为较大的数，不然后面执行min函数时会直接返回值是0
            for(int k=l;k<r;k++)
                f[l][r] = min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
        }
    
    printf("%d\n",f[1][n]);
    return 0;
}