#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int i,j,n,t,a[505];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        vector<int>ans;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<n-1;j++)
            {
                if(a[j] > a[j+1])
                {
                    swap(a[j],a[j+2]);
                    swap(a[j],a[j+1]);
                    ans.emplace_back(j);
                    ans.emplace_back(j);
                }
                else if(a[j+1] > a[j+2])
                {
                    swap(a[j],a[j+1]);
                    swap(a[j],a[j+2]);
                    ans.emplace_back(j);
                }
            }
        }
        for(i=2;i<=n;i++)
        {
            if(a[i] < a[i-1])break;
        }
        if(i <= n)cout << "-1\n";
        else
        {
            cout << ans.size() << '\n';
            for(int x : ans)cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}