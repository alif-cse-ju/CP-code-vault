#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    LL ans=0;
    int i,n,bit,cnt;
    cin >> n;
    vector<int>a(n);
    vector<LL>b(n);
    for(i=0;i<n;i++)cin >> a[i];
    for(bit=0;bit<20;bit++)
    {
        cnt=0;
        for(i=0;i<n;i++)cnt+=((a[i] >> bit) & 1);
        for(i=0;i<cnt;i++)b[i]|=(1 << bit);
    }
    for(i=0;i<n;i++)ans+=b[i]*b[i];
    cout << ans;
    return 0;