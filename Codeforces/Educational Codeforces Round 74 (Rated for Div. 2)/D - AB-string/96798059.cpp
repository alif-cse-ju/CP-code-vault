#include<bits/stdc++.h>
 using namespace std;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i;
    string s;
    vector<int>v;
    long long l,ans;
    cin >> l >> s;
    v.emplace_back(1);
    for(i=1;i<l;i++)
    {
        if(s[i] != s[i-1])v.emplace_back(0);
        ++v.back();
    }
    ans=(l*(l+1)) >> 1;
    ans-=l;
    l=v.size();
    for(i=1;i<l;i++)ans-=v[i-1];
    for(i=1;i<l;i++)ans-=v[i];
    ans+=l-1;
    cout << ans;
    return 0;
}