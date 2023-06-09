#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool flag;
    int i,m,n,s,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        set<int>st;
        for(i=2;i<=n;i++)
        {
            if(a[i] >= a[i-1])st.insert(a[i]-a[i-1]);
            else break;
        }
        if(i > n)
        {
            if((int)st.size() <= 1)cout << "0\n";
            else cout << "-1\n";
            continue;
        }
        st.clear();
        for(i=2;i<=n;i++)
        {
            if(a[i] <= a[i-1])st.insert(a[i-1]-a[i]);
            else break;
        }
        if(i > n)
        {
            if((int)st.size() <= 1)cout << "0\n";
            else cout << "-1\n";
            continue;
        }
        for(i=2;i<n;i++)
        {
            if(a[i] >= a[i-1]  &&  a[i] >= a[i+1])break;
            if(a[i] <= a[i-1]  &&  a[i] <= a[i+1])break;
        }
        if(a[i-1] <= a[i])s=a[i]-a[i-1];
        else s=a[i+1]-a[i];
        m=abs(a[i-1]-a[i])+abs(a[i]-a[i+1]);
        flag=(a[1] < m);
        for(i=2;i<=n  &&  flag;i++)
        {
            if(a[i] != (a[i-1]+s)%m)flag=0;
        }
        if(flag)cout << m << ' ' << s << '\n';
        else cout << "-1\n";
    }
    return 0;
}
//