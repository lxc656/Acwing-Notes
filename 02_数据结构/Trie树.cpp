#include<iostream>

using namespace std;

const int N = 100010;

int son[N][26] , cnt[N] , idx; /*son数组用于存储子结点的数组下标，因为字符串里都是
小写字母，所以每个结点最多连26个子结点,cnt存储以当前的这个结点结尾的单词有多少个,
idx和单链表里的idx一样，用于表示当前用到了哪个下标*/
//数组下标是0的结点，既是根结点，又是空结点

//插入字符串
void insert(char str[])
{
    int p = 0;
    for(int i=0;str[i];i++) //遍历字符串直至结尾的空字符
    {
        int u = str[i] - 'a'; //将小写字母映射到0~25
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u]; 
    }
    cnt[p]++; //以下标p对应的结点为结尾的字符串的数目++
}
//查询字符串出现多少次
int query(char str[])
{
    int p = 0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!son[p][u]) return 0;
        p=son[p][u];
    }
    return cnt[p];
}