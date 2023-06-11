#include <bits/stdc++.h> 
#define ll              long long
#define FastIO          ios_base :: sync_with_stdio (0) ; cin.tie(NULL) ;
using namespace std;
int main()
{
    FastIO
    ll t = 0 ; cin>>t ;
    while ( t-- )
    {
        ll n = 0 ; cin>>n ;
        if ( n == 1 || n == 2 || n == 145 || n == 40585 )
        {
            cout<<1 ;
        }
        else
        {
            cout<<0 ;
        }
        cout<<"\n" ;
    }  
    return 0 ;
}