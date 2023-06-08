#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int a[N],b[N];
long long cum[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,idx;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        map<int,int>pos;
        for(i=1;i<=n;i++)
        {
            pos[b[i]]=i;
            cum[i]=cum[i-1]+b[i];
        }
        idx=1;
        b[n+1]=0;
        for(i=n;i;i--)
        {
            if(cum[pos[b[i]]] < b[pos[b[i]]+1])
            {
                idx=i+1;
                break;
            }
        }
        vector<int>ans;
        for(i=1;i<=n;i++)
        {
            if(a[i] >= b[idx])ans.emplace_back(i);
        }
        cout << (int)ans.size() << '\n';
        for(int it : ans)cout << it << ' ';
        cout << '\n';
    }
    return 0;
}
//