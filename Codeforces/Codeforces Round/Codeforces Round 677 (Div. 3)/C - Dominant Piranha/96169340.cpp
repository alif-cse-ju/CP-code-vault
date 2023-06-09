#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int a[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,t,mx,idx;
    cin >> t;
    while(t--)
    {
        cin >> n;
        mx=-1;
        set<int>st;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            st.insert(a[i]);
            mx=max(a[i],mx);
        }
        if(st.size() == 1)cout << "-1\n";
        else
        {
            idx=0;
            for(i=2;i<n;i++)
            {
                if(a[i] == mx  &&  (a[i] > a[i-1]  ||  a[i] > a[i+1]))
                {
                    idx=i;
                    break;
                }
            }
            if(!idx)
            {
                if(a[1] == mx  &&  a[2] < a[1])idx=1;
                if(a[n] == mx  &&  a[n-1] < a[n])idx=n;
            }
            cout << idx << '\n';
        }
    }
    return 0;
}