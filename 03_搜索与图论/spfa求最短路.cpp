#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1000010;

int n, m, idx;
int h[N], e[N], ne[N];
int w[N];
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while(q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;
        for(int i=h[t]; i!=-1; i=ne[i])
        {
            int j =e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j] = dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
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
    int t = spfa();

    if(t==0x3f3f3f3f) puts("impossible");
    else printf("%d\n", t);
    return 0;
}