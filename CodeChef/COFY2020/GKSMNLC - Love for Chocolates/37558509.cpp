#include<bits/stdc++.h>
using namespace std;
const int N=805;
int n;
bool ok;
long long k,a[N],sum[N];
void Solve(long long lagbe,int cur)
{
    if(lagbe == 0)
    {
        ok=1;
        return;
    }
    if(cur == 0  ||  lagbe < 0  ||  ok)return;
    int pos;
    for(int i=cur;sum[i]>=lagbe  &&  !ok;i--)
    {
        pos=upper_bound(a+1,a+i,lagbe-a[i])-a;
        Solve(lagbe-a[i],pos-1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,t;
    cin >> t;
    while(t--)
    {
        cin >> k >> n;
        for(i=1;i<=n;i++)cin >> a[i],sum[i]=sum[i-1]+a[i];
        sort(a+1,a+n+1);
        if(a[1] > k)cout << "0\n";
        else
        {
            for(i=n;i>0;i--)
            {
                if(a[i] <= k)break;
            }
            if(a[i] == k)
            {
                cout << "1\n";
                continue;
            }
            if(sum[n] < k)
            {
                cout << "0\n";
                continue;
            }
            ok=false;
            Solve(k,i);
            if(ok)cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}