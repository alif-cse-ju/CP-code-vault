#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long i,l,x=1,y=1;
    cin >> l;
    if(l == 12)
    {
        cout << '1';
        return 0;
    }
    --l;
    vector<long long>v1,v2;
    for(i=l;i>l-11;i--)v1.emplace_back(i);
    for(i=2;i<12;i++)v2.emplace_back(i);
    for(i=0;i<10;i++)
    {
        for(int j=0;j<(int)v1.size();j++)
        {
            long long gcd=__gcd(v1[j],v2[i]);
            if(gcd > 1)
            {
                v1[j]/=gcd;
                v2[i]/=gcd;
            }
        }
    }
    for(long long it : v1)x*=it;
    for(long long it : v2)y*=it;
    cout << x/y;
    return 0;
}