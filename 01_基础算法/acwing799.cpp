#include<iostream>
using namespace std;

const int N = 100010;

int n, res;
int a[N];
int s[N]; //当前j~i这个区间里面的每个数的出现次数

int main()
{
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int j=0, i=0; i<n; i++)
    {
        s[a[i]]++;
        while(s[a[i]]>1)
        {
            s[a[j]]--;
            j++;
        }
        res = max(res, i-j+1);
    }
    cout<<res<<endl;
    return 0;
}