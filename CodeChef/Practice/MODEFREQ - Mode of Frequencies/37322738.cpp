#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,n,t,x,mx,cnt[12];
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<n;i++)
        {
            cin >> x;
            ++cnt[x];
        }
        mx=-1;
        map<int,int>mp;
        for(i=1;i<11;i++)
        {
            if(cnt[i])mx=max(mx,++mp[cnt[i]]);
        }
        for(auto it : mp)
        {
            if(it.second == mx)
            {
                cout << it.first << '\n';
                break;
            }
        }
    }
    return 0;
}