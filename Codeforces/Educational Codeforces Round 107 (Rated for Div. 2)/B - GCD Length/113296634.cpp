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
    int a,b,c,i,t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        cout << '1';
        for(i=1;i<a;i++)cout << '0';
        cout << '\n';
        for(i=0;i<=b-c;i++)cout << '1';
        for(i=1;i<c;i++)cout << '0';
        cout << '\n';
    }
    return 0;