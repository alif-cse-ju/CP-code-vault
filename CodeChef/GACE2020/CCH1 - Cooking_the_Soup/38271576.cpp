#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N],temp[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n;
    long long x,y,ans,cnt=0;
    priority_queue<long long,vector<long long>,greater<long long>>pq;
    cin >> n;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)cin >> temp[i];
    for(i=1;i<=n;i++)
    {
        ans=0;
        while(!pq.empty())
        {
            if(pq.top()-cnt <= temp[i])
            {
                ans+=pq.top()-cnt;
                pq.pop();
            }
            else
            {
                ans+=pq.size()*temp[i];
                break;
            }
        }
        cnt+=temp[i];
        if(temp[i] >= a[i])ans+=a[i];
        else ans+=temp[i],pq.emplace(a[i]+cnt-temp[i]);
        cout << ans << ' ';
    }
    return 0;
}