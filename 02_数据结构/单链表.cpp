#include<iostream>

using namespace std;

const int N = 100010;

int head , e[N] , ne [N] , idx; //idx是指针，指向当前用到的结点，即最新的点的下标

//初始化
void init()
{
    head = -1;
    idx = 0;
}

//将值为x的点插到头结点
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

//将值为x的点插到下标为k的点的后面
void add(int k , int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

//将下标是k的点后面的点删除
void remove(int k)
{
    ne[k] = ne[ne[k]];
}
