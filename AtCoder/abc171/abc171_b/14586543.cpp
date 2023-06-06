#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    vector<int>v;
    int i,k,n,x,ans=0;
    cin >> n >> k;
    for(i=0;i<n;i++)cin >> x,v.emplace_back(x);
    sort(v.begin(),v.end());
    for(i=0;i<k;i++)ans+=v[i];
    cout << ans;
    return 0;
}
