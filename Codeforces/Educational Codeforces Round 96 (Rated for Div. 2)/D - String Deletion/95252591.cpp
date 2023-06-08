#include<bits/stdc++.h>
 using namespace std;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
        string s;
    int i,l,n,r,t,ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        vector<int>v;
        for(i=0;i<n;i++)
        {
            if(!i  ||  s[i-1] != s[i])v.emplace_back(0);
            ++v.back();
        }
        ans=0;
        l=r=0;
        n=v.size();
        for(l=0;l<=r  &&  r < n;l++)
        {
            while(r < n  &&  v[r] == 1)++r;
            if(r == n)++ans,r-=2,n--;
            else if(v[r] == 1)++ans,r--,n--;
            else ++ans,--v[r],r+=(l == r);
        }
        cout << ans << '\n';
    }
    return 0;
}