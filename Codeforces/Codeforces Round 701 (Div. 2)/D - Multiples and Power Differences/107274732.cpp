#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
long long a[505][505],b[505][505];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,n;
    vector<int>v;
    long long lcm;
    for(i=1;i<17;i++)v.emplace_back(i*i*i*i);
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin >> a[i][j];
            if(i == 1  &&  j == 1)lcm=a[i][j];
            else lcm=(lcm*a[i][j])/__gcd(lcm,a[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)b[i][j]=lcm;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if((i+j) & 1)
            {
                for(int it : v)
                {
                    if(it%a[i][j] == 0)
                    {
                        b[i][j]+=it;
                        break;
                    }
                }
            }
            cout << b[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
//