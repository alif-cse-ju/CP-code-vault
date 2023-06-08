#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t;
    long long x,y,ans,evenSum,oddSum;
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> y;
        priority_queue<long long>evenPQ,oddPQ;
        oddSum=x,evenSum=y,ans=n*(x+y);
        oddPQ.emplace(-x);
        evenPQ.emplace(-y);
        for(i=3;i<=n;i++)
        {
            cin >> x;
            if(i & 1)
            {
                oddPQ.emplace(-x);
                oddSum+=x;
            }
            else
            {
                evenPQ.emplace(-x);
                evenSum+=x;
            }
            ans=min(ans,oddSum+evenSum+(n-(int)oddPQ.size())*(-oddPQ.top())+(n-(int)evenPQ.size())*(-evenPQ.top()));
        }
        cout << ans << '\n';
    }
    return 0;
}
//