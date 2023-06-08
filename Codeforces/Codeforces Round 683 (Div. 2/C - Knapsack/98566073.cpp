#include<bits/stdc++.h>
 using namespace std;
 const int N=2e5+5;
 int w[N];
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t;
    long long W,sum,half;
    cin >> t;
    while(t--)
    {
        cin >> n >> W;
        for(i=1;i<=n;i++)cin >> w[i];
        half=(W+1LL)/2LL;
        for(i=1;i<=n;i++)
        {
            if(w[i] >= half  &&  w[i] <= W)
            {
                cout << "1\n" << i << '\n';
                break;
            }
        }
        if(i > n)
        {
            sum=0;
            vector<int>ans;
            for(i=1;i<=n;i++)
            {
                if(sum < half  &&  sum+w[i] <= W)
                {
                    sum+=w[i];
                    ans.emplace_back(i);
                }
            }
            if(sum >= half)
            {
                cout << (int)ans.size() << '\n';
                for(int it : ans)cout << it << ' ';
                cout << '\n';
            }
            else cout << "-1\n";
        }
    }
    return 0;
}