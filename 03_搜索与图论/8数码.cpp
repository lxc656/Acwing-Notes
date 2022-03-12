#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

int bfs(string start)
{
    string end="12345678x";

    queue<string> q;
    unordered_map<string,int> d; //distance

    q.push(start);
    d[start]=0;

    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

    while(q.size())
    {
        string t=q.front();
        q.pop();

        int distance=d[t];

        if(t==end) return distance;

        //状态转移
        int k=t.find('x');
        int x=k/3,y=k%3;

        for(int i=0;i<4;i++)
        {
            int a=x+dx[i],b=y+dy[i];
            if(a>=0&&a<3&&b>=0&&b<3)//如果(a,b)没有出界
            {
                swap(t[k],t[a*3+k]);

                if(!d.count(t))
                {
                    d[t]=distance+1;
                    q.push(t);
                }

                swap(t[k],t[a*3+k]);//恢复状态，从而接下来继续模拟x和矩阵里其他元素交换
            }
        }
    }
    return -1;//如果while循环里没有走到终点那么就找不到终点
}

int main()
{
    string start; //初始状态
    for(int i=0;i<9;i++)
    {
        char c;
        cin>>c;
        start+=c;
    }
    cout<<bfs(start)<<endl;

    return 0;
}