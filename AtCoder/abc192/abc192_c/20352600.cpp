#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
const int mod=1e9+7;

long long Solve(long long n)
{
    vector<int>v;
    while(n)
    {
        v.emplace_back(n%10);
        n/=10;
    }
    long long x=0,y=0;
    sort(v.begin(),v.end());
    for(int it : v)y=y*10+it;
    reverse(v.begin(),v.end());
    for(int it : v)x=x*10+it;
    return x-y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long k,n;
    cin >> n >> k;
    while(k--)n=Solve(n);
    cout << n;
    return 0;
}
//
