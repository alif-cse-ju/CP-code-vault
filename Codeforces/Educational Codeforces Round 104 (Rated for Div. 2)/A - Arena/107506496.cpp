#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,t,x,cnt[105];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=100;i++)cnt[i]=0;
        for(i=0;i<n;i++)
        {
            cin >> x;
            ++cnt[x];
        }
        for(i=1;i<=100;i++)
        {
            if(cnt[i])
            {
                cout << n-cnt[i] << '\n';
                break;
            }
        }
    }
    return 0;