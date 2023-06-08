#include<bits/stdc++.h>
 using namespace std;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,B,e=0,o=0,ans=0,a[102];
    cin >> n >> B;
    for(i=1;i<=n;i++)cin >> a[i];
    vector<int>v;
    for(i=1;i<n;i++)
    {
        if(a[i] & 1)++o;
        else ++e;
        if(e == o)v.emplace_back(abs(a[i]-a[i+1]));
    }
    sort(v.begin(),v.end());
    for(int x : v)
    {
        if(x <= B)B-=x,++ans;
        else break;
    }
    cout << ans;
    return 0;
}