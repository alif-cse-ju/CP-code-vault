#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int cnt[100002];
int main()
    FAST();
    string s;
    int i,n,q,x,cnt2=0,cnt4=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> x;
        ++cnt[x];
    }
    for(i=1;i<=1e5;i++)
    {
        cnt4+=cnt[i]/4;
        cnt2+=(cnt[i]%4)/2;
    }
    cin >> q;
    while(q--)
    {
        cin >> s >> x;
        if(s[0] == '+')
        {
            if(cnt[x]%4 == 3)++cnt4,--cnt2;
            else if(cnt[x]%2 == 1)++cnt2;
            ++cnt[x];
        }
        else
        {
            if(cnt[x]%4 == 0)--cnt4,++cnt2;
            else if(cnt[x]%2 == 0)--cnt2;
            --cnt[x];
        }
        if(cnt4 > 1)cout << "YES\n";
        else if(cnt4 == 1  &&  cnt2 > 1)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}