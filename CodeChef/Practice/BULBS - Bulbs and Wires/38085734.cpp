#include<bits/stdc++.h>
using namespace std;
int Solve1(string s,int k)
{
    if(k < 0)return 1e7;
    vector<int>v;
    int ans=0,cnt=0;
    for(char c : s)
    {
        if(c == '1')
        {
            if(cnt)v.emplace_back(cnt);
            cnt=0;
        }
        else ++cnt;
    }
    sort(v.begin(),v.end());
    while(k > 1  &&  !v.empty())
    {
        k-=2;
        v.pop_back();
    }
    for(int it : v)ans+=it;
    return ans;
}
int Solve(string &s,int &k)
{
    string s1;
    bool flag=1;
    int cnt1=0,cnt2=0;
    for(char c : s)
    {
        if(flag  &&  c == '0')++cnt1;
        else
        {
            flag=0;
            s1+=c;
        }
    }
    while(s1.back() == '0')
    {
        ++cnt2;
        s1.pop_back();
    }
    return min(min(Solve1(s1,k)+cnt1+cnt2,Solve1(s1,k-2)),min(Solve1(s1,k-1)+cnt1,Solve1(s1,k-1)+cnt2));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,k,l,t,cnt;
    cin >> t;
    while(t--)
    {
        cin >> l >> k >> s;
        cnt=0;
        for(i=0;i<l;i++)cnt+=(s[i] == '1');
        if(!cnt  ||  cnt == l)cout << "0\n";
        else cout << Solve(s,k) << '\n';
    }
    return 0;
}