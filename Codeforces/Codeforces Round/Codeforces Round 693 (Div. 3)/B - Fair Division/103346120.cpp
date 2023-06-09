#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int N=5e5+5;
const int mod=1e9+7;
int main()
    FAST();
    int i,n,t,x,cnt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt=0;
        for(i=0;i<n;i++)
        {
            cin >> x;
            if(x == 1)++cnt;
        }
        if(cnt & 1  ||  (cnt == 0  &&  (n & 1)))cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;