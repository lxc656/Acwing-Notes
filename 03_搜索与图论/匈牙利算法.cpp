#include<cstring>
#include<iostream>
#include<algorithm>;
using namespace std;
//只需要存储从二分图左侧的点集指向右侧的点集的边
const int N = 510, M = 100010;
int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N]; //记录从右侧点集到左侧点集的映射
bool st[N]; //防止重复搜索

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool find(int x)
{
	for(int i=h[x]; i!=-1; i=ne[i])
	{
		int j = e[i];
		if(!st[j])
		{
			st[j] = true;
			if(match[j]==0 || find(match[j]))
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d%d", &n1, &n2, &m);
	memset(h, -1, sizeof h);
	while(m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	int res = 0;
	for(int i=1; i<=n1; i++)
	{
		memset(st, false, sizeof st);
		if(find(i)) res++;
	}
	printf("%d\n", res);
	return 0;
}