#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N],f[N];

int main()
{
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        f[i] = 1;
        for(int j=1;j<i;j++)
            if(a[j]<a[i]) f[i] = max(f[i] , f[j]+1);
    }

    int res = 0;
    for(int i=1;i<=n;i++) res = max(res,f[i]);

    printf("%d\n",res);

    return 0;
}
/*以下代码可记录最长上升子序列内容
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N],f[N],g[N]; //g[N]用来记录状态转移的轨迹

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    for(int i=1;i<=n;i++)
    {
        f[i]=1;
        g[i]=0;
        for(int j=1;j<i;j++)
            if(a[j]<a[i])
                if(f[i]<f[j]+1)
                {
                    f[i]=f[j]+1;
                    g[i]=j;
                }
    }
    
    int k=1;
    for(int i=1;i<=n;i++)
        if(f[k]<f[i])
            k=i;
    
    printf("%d\n",f[k]);

    for(int i=0;len=f[k];i<len;i++)
    {
        printf("%d",a[k]);
        k=g[k];
    }

    return 0;
}
*/