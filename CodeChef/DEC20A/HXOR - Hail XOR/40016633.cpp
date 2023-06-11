#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,p,q,t,x,z;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        deque<int>idx[35];
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            for(j=30;j>=0;j--)
            {
                if((a[i] >> j) & 1)idx[j].emplace_back(i);
            }
        }
        for(i=1;i<n  &&  x>0;i++)
        {
            for(j=30;j>=0  &&  x>0;j--)
            {
                if(idx[j].empty())continue;
                if(idx[j].front() != i)continue;
                z=(1 << j);
                if((int)idx[j].size() == 1)
                {
                    p=idx[j].front();
                    idx[j].pop_front();
                    a[p] ^= z,a[n] ^= z;
                }
                else
                {
                    p=idx[j].front();
                    idx[j].pop_front();
                    q=idx[j].front();
                    idx[j].pop_front();
                    a[p] ^= z,a[q] ^= z;
                }
                x--;
            }
        }
        if(x > 0)
        {
            if(n == 2)
            {
                if(x & 1)a[n] ^= 1,a[n-1] ^= 1;
            }
            else
            {
                if(x == 1)a[n] ^= 1,a[n-1] ^= 1;
            }
        }
        for(i=1;i<=n;i++)cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}