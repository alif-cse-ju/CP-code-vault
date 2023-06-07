#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mem(x,y) memeset(x,y,sizeof(x))
const int sz =2e3+5;
const int lim = 2e3;
const ll mod = 1e9+7;
ll Dn[sz], ncr[sz][sz], PDn[sz][sz];
int num[sz], visi[sz], n;
void pre()
    int i, j;
    Dn[0]=1;
    Dn[1] = 0;
    Dn[2] = 1;
    for(i=3; i<=lim; i++)
    {
        Dn[i] = (i * Dn[i-1]) % mod;
        if(i & 1)
        {
            Dn[i] -= 1;
            if(Dn[i] < 0)Dn[i] += mod;
        }
        else
        {
            Dn[i] += 1;
            if(Dn[i] >= mod)Dn[i] -= mod;
        }
    }
    for(int i=0;i<=lim;i++)ncr[i][0]=1;
    for(i=1; i<=lim; i++)
    {
        for(j=1; j<=i; j++)
        {
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
            if(ncr[i][j] >= mod)ncr[i][j] -= mod;
        }
    }
 }
 int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
     pre();
    int test, tc;
     ll i,j,s,d,r,m = 0, k=0;
     //for(i=1; i<=10; i++) cout<<Dn[i]<<endl;
     cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>num[i];
        if (num[i] >= 0)    visi[num[i]] = 1;
        else   k++;
    }
     for(i=1; i<=n; i++)
    {
        if(num[i] ==-1 && visi[i]) m++;
    }
     n = k;
     s = Dn[n];
    for(i=1; i<=m; i++)
    {
        d = (Dn[n-i] * ncr[m][i]) % mod;
        s = s + d;
        if(s >= mod)s -= mod;
    }
    cout<<s<<endl;
}