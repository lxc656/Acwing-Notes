#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;

int n, m;
int g[N][N]; //稠密图用邻接矩阵存储
int dist[N];
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0; //用于记录最小生成树中的所有边的长度之和
    for(int i=0; i<n; i++)
    { 
        int t = -1;
        for(int j=1; j<=n; j++)
            if(!st[j] && (t==-1 || dist[t]>dist[j]))
                t = j;
        
        if(i && (dist[t]==INF)) return INF;
        
        if(i) res+=dist[t]; /*注意这行代码和下行的顺序不可颠倒，
        因为图中有的点可能存在自环*/

        for(int j=1; j<=n; j++) dist[j] = min(dist[j], g[t][j]);

        st[t] = true;
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);

    while(m--) //读入所有边
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b]=g[b][a]=min(g[a][b], c); /*这么做是因为可能有重边，
        而且这是无向图，所以要双向建边*/
    }

    int t = prim();

    if(t == INF) puts("impossible");
    else printf("%d\n", t);

    return 0;
}