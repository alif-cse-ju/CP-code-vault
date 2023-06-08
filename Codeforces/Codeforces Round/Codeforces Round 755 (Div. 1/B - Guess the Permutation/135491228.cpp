#include<bits/stdc++.h>
using namespace std;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long long l,ll,m,mm,n,r,rr,tot,v1,v2,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << "? 1 " << n << endl;
        cin >> tot;
        l=2,r=n-1;
        map<long long,long long>mp;
        while(l <= r)
        {
            m=(l+r) >> 1ll;
            if(mp.find(m) != mp.end())v1=mp[m];
            else
            {
                cout << "? " << 1 << ' ' << m << endl;
                cin >> v1;
                mp[m]=v1;
            }
            if(!v1)
            {
                l=m+1;
                continue;
            }
            if(v1 == tot)
            {
                r=m-1;
                continue;
            }
            ll=1,rr=1e9;
            while(ll <= rr)
            {
                mm=(ll+rr) >> 1ll;
                if((mm*(mm+1))/2 >= v1)rr=mm-1;
                else ll=mm+1;
            }
            ++rr;
            if((rr*(rr+1))/2 != v1)r=m-1;
            else
            {
                if(v1 != 6)l=m+1;
                else
                {
                    if(mp.find(m+1) != mp.end())v2=mp[m+1];
                    else
                    {
                        cout << "? " << 1 << ' ' << m+1 << endl;
                        cin >> v2;
                        mp[m+1]=v2;
                    }
                    if(v1 == 6  &&  v2 == 7)
                    {
                        l=m+1;
                        continue;
                    }
                    ll=1,rr=1e9;
                    while(ll <= rr)
                    {
                        mm=(ll+rr) >> 1ll;
                        if((mm*(mm+1))/2 >= v2)rr=mm-1;
                        else ll=mm+1;
                    }
                    ++rr;
                    if((rr*(rr+1))/2 == v2)l=m+1;
                    else r=m-1;
                }
            }
        }
        y=l-1;
        if(mp.find(y) != mp.end())mm=mp[y];
        else
        {
            cout << "? 1 " << y << endl;
            cin >> mm;
        }
        l=1,r=1e9;
        while(l <= r)
        {
            m=(l+r) >> 1;
            if((m*(m+1))/2 >= mm)r=m-1;
            else l=m+1;
        }
        x=y-r-2;
        tot -= mm;
        l=1,r=1e9;
        while(l <= r)
        {
            m=(l+r) >> 1;
            if((m*(m+1))/2 >= tot)r=m-1;
            else l=m+1;
        }
        z=y+r+1;
        cout << "! " << x << ' ' << y << ' ' << z << endl;
    }
    return 0;
}