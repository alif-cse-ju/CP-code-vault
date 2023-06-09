#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,k,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        set<int>st;
        for(i=0;i<n;i++)
        {
            cin >> x;
            st.insert(x);
        }
        n=st.size();
        if(n <= k)cout << "1\n";
        else if(k == 1)
        {
            if(n > k)cout << "-1\n";
            else cout << "1\n";
        }
        else n-=k,k--,cout << n/k+(n%k > 0)+1 << '\n';
    }
    return 0;