#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int l,cnt[30][N];
void Update(int idx1,int idx2)
{
    while(idx2 <= l)
    {
        ++cnt[idx1][idx2];
        idx2 += idx2 & (-idx2);
    }
}
int Query(int i,int j)
{
    int ans=0;
    while(j > 0)
    {
        ans+=cnt[i][j];
        j-=j & (-j);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    int i,q,x,y,ans,check;
    cin >> s;
    l=(int)s.size();
    for(i=0;i<l;i++)Update(s[i]-'a'+1,i+1);
    cin >> q;
    while(q--)
    {
        ans=0;
        cin >> x >> y;
        for(i=2;i<27;i+=2)
        {
            check=Query(i,y)-Query(i,x-1);
            ans+=(check > 0);
        }
        cout << ans << '\n';
    }
    return 0;
}
//1060,1422