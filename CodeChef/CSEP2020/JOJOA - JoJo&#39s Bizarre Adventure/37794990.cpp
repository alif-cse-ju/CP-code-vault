#include<bits/stdc++.h>
using namespace std;
const int N=1e6+2;
char s[N];
int n,lb,rb,check,cnt[28][N];
bool Check(int idx)
{
    int i,j,bal;
    for(i=idx;i<=n;i++)
    {
        bal=0;
        for(j=1;j<27;j++)bal+=cnt[j][i]-cnt[j][i-idx] > 0;
        if(bal == check)
        {
            rb=i,lb=i-idx+1;
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,l,m,r,t;
    cin >> t;
    while(t--)
    {
        cin >> s+1;
        n=strlen(s+1);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<27;j++)cnt[j][i]=cnt[j][i-1];
            ++cnt[s[i]-'a'+1][i];
        }
        check=0;
        for(i=1;i<=26;i++)check+=cnt[i][n] > 0;
        l=1,r=n;
        while(l <= r)
        {
            m=(l + r) >> 1;
            if(Check(m))r=m-1;
            else l=m+1;
        }
        for(i=lb;i<=rb;i++)cout << s[i]-'a'+1;
        cout << '\n';
    }
    return 0;
}