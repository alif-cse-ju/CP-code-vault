#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int cnt[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cnt[i]=0;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            --cnt[i+1];
            ++cnt[max(1,i-x+1)];
        }
        for(i=2;i<=n;i++)cnt[i]+=cnt[i-1];
        for(i=1;i<=n;i++)cout << (cnt[i] > 0) << ' ';
        cout << '\n';
    }
    return 0;