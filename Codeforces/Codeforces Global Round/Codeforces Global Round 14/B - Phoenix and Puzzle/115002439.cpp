#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    FAST();
    int n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n%2 == 0  &&  (int)sqrt(n/2)*(int)sqrt(n/2) == n/2)cout << "YES\n";
        else if(n%4 == 0  &&  (int)sqrt(n/4)*(int)sqrt(n/4) == n/4)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;