#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int Solve(vector<int>&a,vector<int>&b)
    int i,j,l,m,n,r,ans=0;
    n=(int)a.size();
    m=(int)b.size();
    vector<int>temp(n+1,0);
    for(i=n-1,r=m-1;i>=0;i--)
    {
        temp[i]+=temp[i+1];
        while(r >= 0  &&  b[r] > a[i])--r;
        if(r >= 0  &&  b[r] == a[i])++temp[i];
    }
    for(j=l=r=0;l<m;l++)
    {
        while(j < n  &&  a[j] <= b[l]+j)++j;
        while(r < m  &&  b[r]-b[l] < j)++r;
        ans=max(ans,r-l+temp[j]);
    }
    return ans;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,m,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<int>al,ar,bl,br;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(x < 0)al.emplace_back(-x);
            else ar.emplace_back(x);
        }
        for(i=1;i<=m;i++)
        {
            cin >> x;
            if(x < 0)bl.emplace_back(-x);
            else br.emplace_back(x);
        }
        reverse(al.begin(),al.end());
        reverse(bl.begin(),bl.end());
        cout << Solve(al,bl)+Solve(ar,br) << '\n';
    }
    return 0;
}
//