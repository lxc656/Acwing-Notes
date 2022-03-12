#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];

struct Edge
{
    int a, b, w;
}edges[M];

int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for(int i=0; i<k; i++)
    {
        memcpy(backup, dist, sizeof dist); //备份dist数组
        for(int j=0; j<m; j++)
        {
            int a = edges[j].a;
            int b = edges[j].b;
            int w = edges[j].w;
            dist[b] = min(dist[b], backup[a]+w);
        }
    }
    if(dist[n]>0x3f3f3f3f/2) return -1; //因为图中存在负权边，所以更新dist数组时有可能让+∞加上一个负值
    return dist[n];
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for(int i=0; i<m; i++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    int t = bellman_ford();

    if(t==-1) puts("impossible");
    else printf("%d\n", t);

    return 0;
}