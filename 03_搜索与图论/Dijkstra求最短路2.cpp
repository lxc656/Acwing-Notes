#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> PII; //用于存储<节点距离，节点编号>

const int N = 1000010;

int n, m, idx;
int h[N], e[N], ne[N];
int w[N]; //w数组表示边的权重
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if(st[ver]) continue; //判断当前从堆中取出的点是不是冗余备份

        st[ver] = true;
        for(int i=h[ver]; i!=-1; i=ne[i])
        {
            int j=e[i];
            if(dist[j] > distance+w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int t = dijkstra();
    printf("%d\n", t);
    return 0;
}