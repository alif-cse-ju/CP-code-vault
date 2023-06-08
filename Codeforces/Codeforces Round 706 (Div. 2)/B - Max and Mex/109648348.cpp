#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<int>v;
        for(i=0;i<n;i++)
        {
            cin >> x;
            v.emplace_back(x);
        }
        if(!k)cout << n << '\n';
        else
        {
            sort(v.begin(),v.end());
            if(v.back() == n-1)cout << n+k << '\n';
            else
            {
                for(i=0;i<n;i++)
                {
                    if(v[i] != i)
                    {
                        x=(v.back()+i+1)/2;
                        break;
                    }
                }
                if(binary_search(v.begin(),v.end(),x))cout << n << '\n';
                else cout << n+1 << '\n';
            }
        }
    }
    return 0;
}