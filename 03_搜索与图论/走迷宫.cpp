#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

const int N = 110;

using namespace std;

typedef pair<int,int> PII;

int n,m;
int g[N][N]; //存储地图
int d[N][N]; //存储每个点的最短距离
PII q[N * N]; //队列

int bfs()
{
    queue<PII> q;
    memset(d,-1,sizeof d);
    d[0][0]=0;
    q.push({0,0});

    int dx[4]={-1,0,1,0} , dy[4]={0,1,0,-1};

    while(q.size())
    {
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++) //遍历队头元素的前后左右四个方向的点
        {
            int x=t.first+dx[i] , y=t.second+dy[i];
            if(x>=0 && x<n && y>=0 && y<=m
            && g[x][y]==0 && d[x][y]==-1)
            {
                d[x][y]=d[t.first][t.second]+1;
                q.push({x,y});
            }
        }
    }
    return d[n-1][m-1];
}

int main()
{
    cin>>n>>m;

    for(int i=0;i<n;i++)
        for(int j=0;i<m;j++)
            cin>>g[i][j];

    cout<<bfs()<<endl;

    return 0;
}