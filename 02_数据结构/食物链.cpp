#include<iostream>

using namespace std;

const int N=50010;

int n,m;
int p[N],d[N]; //p存储父节点的下标，d存储到根节点的距离

int find(int x) //路径压缩之前，d[x]存储的是x到其父节点的距离
{
    if(p[x]!=x)
    {
        int t=find(p[x]); //记录根节点下标
        d[x]+=d[p[x]];
        p[x]=t;
    }
    return p[x];
}



int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++) p[i]=i;

    int res=0; //记录有几句假话
    while(m--)
    {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);

        if(x>n || y>n) res++;
        else
        {
            int px=find(x),py=find(y); //记录x和y的根节点
            if(t==1)
            {
                if(px==py && ((d[x]-d[y])%3)) res++;
                else if(px!=py) //若不在一个集合里
                {
                    p[px]=py;
                    d[px]=d[y]-d[x];/*这样可以使"新的d[x]"-d[y]，
                    即(d[px]+"旧的d[x]"-d[y])mod3==0*/
                }
            }
            else
            {
                //若x吃y，则在mod3的意义下，x到根节点的距离比y多1
                if(px == py && (d[x]-d[y]-1)%3) res++;
                else if(px!=py)
                {
                    p[px]=py;
                    d[px]=d[y]+1-d[x];/*这样可以使"新的d[x]"-d[y]-1，
                    即(d[px]+"旧的d[x]"-d[y]-1)mod3==0*/
                }
            }
        }
    }
    printf("%d\n",res);
    return 0;
} 