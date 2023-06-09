#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL FindDiv(LL n)
    int i,rt=sqrt(n);
    for(i=2;i<=rt;i++)
    {
        if(n%i == 0)return i;
    }
    return n;
int main()
    FAST();
    int t;
    LL k,n;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cout << n+FindDiv(n)+(k-1)*2 << '\n';
    }
    return 0;