#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int minPrimeDiv[N];
void PreCal()
    int i,j;
    for(i=2;i<N;i++)
    {
        if(!minPrimeDiv[i])
        {
            minPrimeDiv[i]=i;
            for(j=2*i;j<N;j+=i)minPrimeDiv[j]=i;
        }
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    long long w;
    int i,j,n,t,q,x,y,cnt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<vector<int>>p(n);
        for(i=0;i<n;i++)
        {
            cin >> x;
            while(x > 1)
            {
                cnt=0;
                y=minPrimeDiv[x];
                while(minPrimeDiv[x] == y)
                {
                    ++cnt;
                    x/=y;
                }
                if(cnt & 1)p[i].emplace_back(y);
            }
        }
        sort(p.begin(),p.end());
        x=y=0;
        for(i=0;i<n;)
        {
            j=i;
            while(j < n  &&  p[i] == p[j])++j;
            x=max(x,j-i);
            if(p[i].empty()  ||  (j-i)%2 == 0)y+=j-i;
            i=j;
        }
        y=max(x,y);
        cin >> q;
        while(q--)
        {
            cin >> w;
            cout << (w ? y : x) << '\n';
        }
    }
    return 0;
}
//