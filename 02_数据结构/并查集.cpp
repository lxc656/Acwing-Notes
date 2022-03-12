#include<iostream>

using namespace std;

const int N = 10010;

int n,m;
int p[N]; //用于存储每个节点的父节点是谁

int find(int x) //返回编号为x的节点的所在集合的编号+路径压缩
{
    if(p[x]!=x) p[x]=find(p[x]); //若x不是根节点，那么让它的父节点等于根结点，递归完成路径压缩
    return p[x]; 
}

//初始的时候每个元素都是一个单独的集合，每个集合只有一个根节点
int main()
{
    for(int i=1;i<=n;i++) p[i]=i;
}