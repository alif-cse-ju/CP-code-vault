#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
bool mark[N];
int a[N],rit[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>v,ans,temp;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            mark[i]=0;
            rit[i]=i+1;
            v.emplace_back(i);
        }
        rit[n]=1;
        while(!v.empty())
        {
            temp.clear();
            for(int it : v)
            {
                if(mark[it])continue;
                if(__gcd(a[it],a[rit[it]]) == 1)
                {
                    mark[rit[it]]=1;
                    temp.emplace_back(it);
                    ans.emplace_back(rit[it]);
                    rit[it]=rit[rit[it]];
                }
            }
            v=temp;
        }
        cout << (int)ans.size();
        for(int it : ans)cout << ' ' << it;
        cout << '\n';
    }
    return 0;
}
//