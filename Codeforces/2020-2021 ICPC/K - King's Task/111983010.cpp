#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e3+5;
const int mod=1e9+7;
int n,a[N],b[N];
void DO1()
    int i;
    for(i=2;i<=n;i+=2)swap(b[i],b[i-1]);
void DO2()
    int i;
    for(i=1;i<=n/2;i++)swap(b[i],b[i+n/2]);
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j;
    cin >> n;
    n <<= 1;
    for(i=1;i<=n;i++)cin >> a[i];
    if(is_sorted(a+1,a+n+1))
    {
        cout << 0;
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)b[j]=a[j];
        for(j=1;j<=i;j++)
        {
            if(j & 1)DO1();
            else DO2();
        }
        if(is_sorted(b+1,b+n+1))
        {
            cout << i;
            return 0;
        }
         for(j=1;j<=n;j++)b[j]=a[j];
        for(j=1;j<=i;j++)
        {
            if(j & 1)DO2();
            else DO1();
        }
        if(is_sorted(b+1,b+n+1))
        {
            cout << i;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
//