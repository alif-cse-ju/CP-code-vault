#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int Solve(vector<int>&v,int pos)
    if((int)v.size() == 1)return 1;
    vector<int>x,y;
    for(int it : v)
    {
        if((it >> pos) & 1)x.emplace_back(it);
        else y.emplace_back(it);
    }
    if(x.empty())return Solve(y,pos-1);
    if(y.empty())return Solve(x,pos-1);
    return 1+max(Solve(x,pos-1),Solve(y,pos-1));
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,x;
    vector<int>v;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        v.emplace_back(x);
    }
    cout << n-Solve(v,29);
    return 0;