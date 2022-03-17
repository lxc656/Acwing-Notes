#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int n,m;
char a[N],b[N]; //这里要注意，a[]的类型是char数组
int f[N][N];

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s%s",a+1,b+1); //因为本题的公式里用到了f[i-1]里的这种i-1下标，因此数组
                           //下标从1开始，故读数据读到a+1,b+1的位置
    for(int i=1;i<=n;i++)
        for(int j=1;i<=m;j++)
        {
            f[i][j] = max(f[i-1][j] , f[i][j-1]);
            if(a[i] == b[j]) f[i][j] = max(f[i][j] , f[i-1][j-1] + 1);
        }
    
    printf("%d\n",f[n][m]);

    return 0;
}