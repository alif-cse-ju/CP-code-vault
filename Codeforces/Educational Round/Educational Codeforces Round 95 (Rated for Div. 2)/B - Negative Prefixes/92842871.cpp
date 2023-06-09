#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,x,a[102];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        vector<int>idx,val;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(!x)
            {
                idx.emplace_back(i);
                val.emplace_back(a[i]);
            }
        }
        sort(val.rbegin(),val.rend());
        for(i=0;i<idx.size();i++)a[idx[i]]=val[i];
        for(i=1;i<=n;i++)cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;