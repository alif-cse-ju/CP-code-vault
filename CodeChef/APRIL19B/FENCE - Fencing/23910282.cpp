#include<bits/stdc++.h>
using namespace std;
long long int ans;
map<pair<int,int>,int>mp;
pair<int,int>temp,check[100010];
int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t,n,m,k,x,y,i,mark;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&k);
        mp.clear();
        mark=0;
        for(i=0; i<k; i++)
        {
            scanf("%d %d",&x,&y);
            check[i].first=x;
            check[i].second=y;
            mp[check[i]]=++mark;
        }
        ans=0;
        for(i=0; i<k; i++)
        {
            temp.first=check[i].first-1;
            temp.second=check[i].second;
            if(mp[temp] == 0)
            {
                ans++;
            }
            temp.first=check[i].first+1;
            temp.second=check[i].second;
            if(mp[temp] == 0)
            {
                ans++;
            }
            temp.first=check[i].first;
            temp.second=check[i].second-1;
            if(mp[temp] == 0)
            {
                ans++;
            }
            temp.first=check[i].first;
            temp.second=check[i].second+1;
            if(mp[temp] == 0)
            {
                ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}