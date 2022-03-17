#include<iostream>
#include<algorithm>

using namespace std;

const int N=510,INF=1e9;

int n;
int a[N][N];
int f[N][N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&a[i][j]);
    
    for(int i=0;i<=n;i++)
        for(int j=0;j<=i+1;j++)
            f[i][j]=-INF; //为了不处理边界问题，在此将f先全初始化为负无穷
//举个例子，计算[3,3]点时需要[2,2]点的状态值和[2,3]点的状态值，而[2,3]点的状态值是没有意义的，
//因为三角形里没有这个点，故先将其初始化为负无穷
    
    f[1][1]=a[1][1];
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            f[i][j]=max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j]);

    int res=-INF;
    for(int i=1;i<=n;i++) res=max(res,f[n][i]); //因为最后走到底层，只需比较底层的状态值即可

    printf("%d\n",res);
    return 0;
}