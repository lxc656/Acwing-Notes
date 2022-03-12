#include<iostream>

using namespace std;

const int N = 100010;

int m;
int e[N],l[N],r[N],idx;

//初始化
void init()
{
    r[0] = 1 , l[1] = 0;
    idx = 2;
}

//在下标为k的点的右边插入值为x的点
void add(int k , int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx; //注意这行代码和上一行代码的顺序不能颠倒
}
//如果想在在下标为k的点的左边插入值为x的点，则只需调用 add(l[k] , x)

//删除下标为k的点
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}