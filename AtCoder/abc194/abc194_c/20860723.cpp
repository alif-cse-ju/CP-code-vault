#include<bits/stdc++.h>

using namespace std;

const int N=5e2+5;
const int mod=1e9+7;

int cnt[N];
bool mark[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    long long x,ans=0;
    vector<long long>v;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> x;
        for(long long it : v)ans+=(x-it)*(x-it)*cnt[it+200];
        ++cnt[x+200];
        if(!mark[x+200])
        {
            mark[x+200]=1;
            v.emplace_back(x);
        }
    }
    cout << ans;
    return 0;
}