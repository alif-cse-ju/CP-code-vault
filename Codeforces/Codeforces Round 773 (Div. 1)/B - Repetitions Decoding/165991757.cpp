#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
const int sz=505;
int a[sz];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i];
        if(n & 1)cout << "-1\n";
        else
        {
            map<int,int>cnt;
            for(int i=1;i<=n;i++)++cnt[a[i]];
            bool ok=1;
            for(auto [x,y] : cnt)ok &= (1-y%2);
            if(!ok)cout << "-1\n";
            else
            {
                int curLen=0;
                vector<int>lens;
                vector<pair<int,int>>updates;
                for(int i=1;i<=n;i++)
                {
                    if(!a[i])continue;
                    for(int j=i+1;j<=n;j++)
                    {
                        if(a[i] == a[j])
                        {
                            a[i]=a[j]=0;
                            lens.emplace_back((j-i) << 1);
                            for(int k=i+1;k<j;k++)updates.emplace_back(curLen+j-i+k-i, a[k]);
                            curLen += ((j-i) << 1);
                            reverse(a+i+1,a+j+1);
                            break;
                        }
                    }
                }
                cout << (int)updates.size() << '\n';
                for(auto [x,y] : updates)cout << x << ' ' << y << '\n';
                cout << (int)lens.size() << '\n';
                for(int it : lens)cout << it << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}