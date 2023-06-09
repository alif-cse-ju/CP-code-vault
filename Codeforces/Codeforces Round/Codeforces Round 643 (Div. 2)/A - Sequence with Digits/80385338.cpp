#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int t,mn,mx;
    LL k,n;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        mn=9;
        while(--k  &&  mn)
        {
            mn=9,mx=0;
            for(char c : to_string(n))mn=min(mn,c-'0'),mx=max(mx,c-'0');
            n+=mn*mx;
        }
        cout << n << '\n';
    }
    return 0;