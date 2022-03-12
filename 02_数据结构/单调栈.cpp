#include<iostream>

using namespace std;

const int N = 100010;

int n;
int stk[N],tt;

int main()
{
    ios::sync_with_stdio(false); //加速读入数据
    
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        while(tt && stk[tt] >= x) tt--;
        if(tt) cout<<stk[tt]<<endl;
        else cout<<-1<<endl;

        stk[++tt] = x;
    }
    
    return 0;
}