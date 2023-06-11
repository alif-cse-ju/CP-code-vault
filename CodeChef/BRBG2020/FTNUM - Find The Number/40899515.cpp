#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,j,n,t,rt;
    long long val,a[355];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        sort(a+1,a+n+1);
        set<long long>st;
        for(i=1;i<=n/2;i++)st.insert(a[i]*a[n-i+1]);
        if(n & 1)st.insert(a[n/2+1]*a[n/2+1]);
        if((int)st.size() == 1)
        {
            val=*(st.begin());
            rt=sqrt(val);
            for(i=2,j=1;i<=rt;i++)
            {
                if(val%i == 0)
                {
                    if(a[j] == i)++j;
                    else break;
                }
            }
            if(i <= rt)cout << "-1\n";
            else cout << val << '\n';
        }
        else cout << "-1\n";
    }
    return 0;
}
//1060,1422