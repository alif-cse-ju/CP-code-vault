#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
long long x[5005],y[5005];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n;
    cin >> n;
    for(i=0;i<n;i++)cin >> x[i] >> y[i];
    vector<int>ans;
    for(i=0;i<n;i++)
    {
        ans.emplace_back(i);
        for(j=i;j>1;j--)
        {
            if((x[ans[j]]-x[ans[j-1]])*(x[ans[j-1]]-x[ans[j-2]]) + (y[ans[j]]-y[ans[j-1]])*(y[ans[j-1]]-y[ans[j-2]]) >= 0)swap(ans[j],ans[j-1]);
            else break;
        }
    }
    for(int it : ans)cout << it+1 << ' ';
    return 0;