#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N=100010,M=N*2;

int n,m;
int h[N],e[M],ne[M],idx;
bool st[N]; //一般每个点只会被遍历一次，通过此bool数组记录每个点是否被遍历过

int ans=N;

void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

//返回以u为根的子树中的点的数目
int dfs(int u)
{
    st[u]=true; //标记一下已经被搜过
    int sum=1,res=0; //res是删掉该点之后的所有连通块的节点数的大小的最大值
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
        {
            int s=dfs(j);
            res=max(res,s);
            sum+=s;
        }
    }
    res=max(res,n-sum);
    ans=min(ans,res);
    return sum;
}

int main()
{
    cin>>n;
    memset(h,-1,sizeof h); //将所有的单链表的头节点下标初始化成-1
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1); //以从第一个点开始搜索

    cout<<ans<<endl;

    return 0;
}