#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int mod=1e9+7;
int GetIndex(vector<int>& a,vector<int>& b)
    int i,j,la=(int)a.size(),lb=(int)b.size();
    for(i=j=0;i<la;i++)
    {
        while(j < lb  &&  b[j] < a[i])++j;
        if(j == lb)return i;
        ++j;
    }
    return la;
void Solve()
    int i,l,n,r,x;
    vector<int>a,b;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> x;
        a.emplace_back(x);
    }
    for(i=1;i<=2*n;i++)
    {
        if(!binary_search(a.begin(),a.end(),i))b.emplace_back(i);
    }
    r=GetIndex(a,b);
    l=n-GetIndex(b,a);
    cout << r-l+1 << '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)Solve();
    return 0;
}
//