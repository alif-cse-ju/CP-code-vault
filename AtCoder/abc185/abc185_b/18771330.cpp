#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,m,n,r,t,cnt,temp=0;
    cin >> n >> m >> t;
    cnt=n;
    while(m--)
    {
        cin >> l >> r;
        cnt-=l-temp;
        if(cnt <= 0)
        {
            cout << "No";
            return 0;
        }
        cnt+=r-l;
        temp=r;
        cnt=min(n,cnt);
    }
    cnt-=t-temp;
    if(cnt <= 0)cout << "No";
    else cout << "Yes";
    return 0;
}