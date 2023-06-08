#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
bool Check(long long n)
    long long tmp=n;
    vector<int>v;
    while(tmp)
    {
        v.emplace_back(tmp%10);
        tmp/=10;
    }
    for(int it : v)
    {
        if(!it)continue;
        if(n%it)return 0;
    }
    return 1;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    long long n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        while(!Check(n))++n;
        cout << n << '\n';
    }
    return 0;