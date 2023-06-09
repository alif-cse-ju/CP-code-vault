#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int n,cnt[1000005];
void Update(int x,int y)
    while(x <= n)
    {
        cnt[x]+=y;
        x+=x & (-x);
    }
int Query(int x)
    int ans=0;
    while(x > 0)
    {
        ans+=cnt[x];
        x-=x & (-x);
    }
    return ans;
int main()
    FAST();
    int i,k,x,low,mid,high,val;
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> x;
        Update(x,1);
    }
    for(i=0;i<k;i++)
    {
        cin >> x;
        if(x > 0)Update(x,1);
        else
        {
            x=-x;
            low=1,high=n;
            while(low < high)
            {
                mid=(low+high) >> 1;
                val=Query(mid);
                if(val < x)low=mid+1;
                else high=mid;
            }
            Update(low,-1);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(cnt[i] > 0)
        {
            cout << i;
            return 0;
        }
    }
    cout << "0";
    return 0;
}