#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL fact[100002];
int n,p,a[100002];
void Factorial()
    fact[0]=fact[1]=1;
    for(LL i=2;i<=100000;i++)fact[i]=(fact[i-1]*i)%p;
int Check(int val)
    int i;
    for(i=1;i<=n;i++)
    {
        if(val+i <= a[i])return -1;
    }
    LL check=1LL;
    for(i=n;i>0;i--)check=(check*fact[i-max(0,a[i]-val)])%p;
    if(check%p)return 0;
    return 1;
int FindL()
    int ans=-1,check,low=a[1],high=a[n],mid;
    while(low <= high)
    {
        mid=(low+high) >> 1;
        check=Check(mid);
        if(check == -1)low=mid+1;
        else
        {
            if(check == 0)ans=mid;
            high=mid-1;
        }
    }
    return ans;
}
 int FindR()
{
    int ans=-1,check,low=a[1],high=a[n],mid;
    while(low <= high)
    {
        mid=(low+high) >> 1;
        check=Check(mid);
        if(check == 1)high=mid-1;
        else
        {
            if(check == 0)ans=mid;
            low=mid+1;
        }
    }
    return ans;
}
 int main()
{
    FAST();
    int i,l,r;
    cin >> n >> p;
    for(i=1;i<=n;i++)cin >> a[i];
    Factorial();
    sort(a+1,a+n+1);
    l=FindL();
    r=FindR();
    if(l == -1)cout << "0";
    else
    {
        cout << r-l+1 << '\n';
        for(i=l;i<=r;i++)cout << i << ' ';
    }
    return 0;
}