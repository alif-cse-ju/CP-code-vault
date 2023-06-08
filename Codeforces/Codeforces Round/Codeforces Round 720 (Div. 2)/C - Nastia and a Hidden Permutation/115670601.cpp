#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int ans[M];
int Ask(int t,int i,int j,int x)
    cout << "? " << t << ' ' << i << ' ' << j << ' ' << x << endl;
    cin >> x;
    return x;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,pos,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<pair<int,pair<int,int>>>v;
        for(i=1;i<=n/2;i++)v.push_back({Ask(2,i,n-i+1,1),{i,n-i+1}});
        sort(v.begin(),v.end());
        if(v[0].first == 1)pos=v[0].second.first,ans[pos]=1;
        else
        {
            x=Ask(2,v[0].second.second,v[0].second.first,1);
            if(x == 1)pos=v[0].second.second,ans[pos]=1;
            else
            {
                x=Ask(1,v[0].second.first,v[0].second.second,2);
                if(x > 2)pos=v[0].second.first,ans[pos]=2;
                else pos=v[0].second.second,ans[pos]=2;
            }
        }
        for(i=pos-1;i;i--)
        {
            x=Ask(1,pos,i,n-1);
            if(x == ans[pos])ans[i]=1;
            else ans[i]=x;
        }
        for(i=pos+1;i<=n;i++)
        {
            x=Ask(1,pos,i,n-1);
            if(x == ans[pos])ans[i]=1;
            else ans[i]=x;
        }
        cout << "!";
        for(i=1;i<=n;i++)cout << ' ' << ans[i];
        cout << endl;
    }
    return 0;
}