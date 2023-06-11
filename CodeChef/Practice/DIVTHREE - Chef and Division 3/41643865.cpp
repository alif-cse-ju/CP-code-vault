#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int d,i,k,n,t,x,cnt;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> d;
        cnt=0;
        for(i=0;i<n;i++)
        {
            cin >> x;
            cnt+=x;
        }
        cout << min(d,cnt/k) << '\n';
    }
    return 0;
}