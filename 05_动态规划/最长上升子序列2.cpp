#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N];
int p[N]; //单调递增的数组

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    int len=0; //len存储当前p数组的长度
    p[0]=-2e9;//为了保证p数组中小于a[i]的数一定存在，我们将p[0]设为-2e9，让它作为哨兵
    for(int i=0;i<n;i++) //二分出来p数组里小于a[i]的最大的数
    {
        int l=0,r=len;
        while(l<r)
        {
            int l=0,r=len;
            //二分查找代码的步骤：确定二分范围➡️默写代码模板➡️设计check函数，
            //让我们的二分查找结果处在check函数两种结果的的边界位置
            while(l<r)
            {
                int mid = l+r+1 >>1; //+1是因为后面有l=mid
                if(p[mid]<a[i]) l=mid;
                else r=mid-1;
            }
            len=max(len,r+1);
            p[r+1]=a[i];
        }
    }
    printf("%d\n",len); //算到最后len的值就是最长上升子序列的长度

    return 0;
}