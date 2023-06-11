#include<bits/stdc++.h>
using namespace std;
priority_queue<int>pq;
int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,t,x,y,z,val;
    long long int a,b,ans,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %lld %lld %d %d %d",&n,&a,&b,&x,&y,&z);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&val);
            pq.push(val);
        }
        cnt=(z-b)/y;
        if(b+y*cnt == z)
        {
            cnt--;
        }
        a+=(x*cnt);
        ans=0;
        val=pq.top();
        pq.pop();
        while(a<z && val>0)
        {
            a+=val;
            val/=2;
            ans++;
            pq.push(val);
            val=pq.top();
            pq.pop();
        }
        if(a >= z)
        {
            printf("%lld\n",ans);
        }
        else
        {
            printf("RIP\n");
        }
        while(!pq.empty())
        {
            pq.pop();
        }
    }
    return 0;
}