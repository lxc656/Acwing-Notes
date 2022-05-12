#include<iostream>
#include<algorithm>

using namespace std;

#define MAXSIZE 100010

struct range {
    int left;
    int right;
    bool operator < (range& x) {
        return right < x.right;
    }
} Range[MAXSIZE];

int main() {
    int n, ans = 0, R = -(1e9+1);
    cin>>n;
    for(int i=0; i<n; i++) {
        int l, r;
        cin>>l>>r;
        Range[i].left = l, Range[i].right = r;
    }
    sort(Range, Range+n);
    for(int i=0; i<n; i++) {
        if(Range[i].left > R) {
            R = Range[i].right;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
