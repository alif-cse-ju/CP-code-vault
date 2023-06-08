#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    FAST();
    int i,n;
    set<int>st;
    long long ans=1;
    cin >> n;
    for(i=1;i<n;i++)
    {
        if(__gcd(i,n) == 1)
        {
            ans*=i;
            ans%=n;
            st.insert(i);
        }
    }
    if(ans > 1)st.erase(ans);
    cout << (int)st.size() << '\n';
    for(int it : st)cout << it << ' ';
    return 0;