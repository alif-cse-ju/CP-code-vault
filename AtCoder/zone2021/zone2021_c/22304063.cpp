#include<bits/stdc++.h>

using namespace std;

const int M=3e3+5;

int n,a[M][5];

bool Check(int val)
{
    int i,j,x;
    set<int>st;
    for(i=1;i<=n;i++)
    {
        x=0;
        for(j=0;j<5;j++)
        {
            if(a[i][j] >= val)x |= (1 << j);
        }
        st.insert(x);
    }
    for(int it1 : st)
    {
        for(int it2 : st)
        {
            for(int it3 : st)
            {
                if((it1 | it2 | it3) == 31)return 1;
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,l,m,r,ans;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<5;j++)cin >> a[i][j];
    }
    l=1,r=1e9;
    while(l <= r)
    {
        m=(l+r) >> 1;
        if(Check(m))ans=m,l=m+1;
        else r=m-1;
    }
    cout << ans;
    return 0;
}