#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
bool mark[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long k,l,r,t,x,y,z;
    cin >> k >> l >> r >> t >> x >> y;
    if(k < l  ||  k > r)cout << "No";
    else
    {
        if(x > y)
        {
            if(k+y > r)--t,k-=x;
            if(k < l)cout << "No";
            else
            {
                z=(k-l)/(x-y);
                if(z >= t)cout << "Yes";
                else cout << "No";
            }
        }
        else
        {
            while(t)
            {
                if(mark[k%x])
                {
                    cout << "Yes";
                    return 0;
                }
                mark[k%x]=1;
                z=min(t,(k-l)/x);
                k-=z*x,t-=z;
                if(!t)
                {
                    cout << "Yes";
                    return 0;
                }
                --t;
                if(k+y <= r)k+=y;
                k-=x;
                if(k < l)
                {
                    cout << "No";
                    return 0;
                }
            }
            cout << "Yes";
        }
    }
    return 0;
}
//