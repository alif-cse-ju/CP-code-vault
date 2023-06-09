#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
long long sum[N];
void Update(int idx,int val)
    while(idx <= n)
    {
        sum[idx]+=val;
        idx+=idx & (-idx);
    }
long long Query(int idx)
    long long ans=0;
    while(idx > 0)
    {
        ans+=sum[idx];
        idx-=idx & (-idx);
    }
    return ans;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,m,r,x,op;
    cin >> n >> m;
    while(m--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> l >> r >> x;
            Update(l+1,x),Update(r+1,-x);
        }
        else
        {
            cin >> l;
            cout << Query(l+1) << '\n';
        }
    }
    return 0;
}