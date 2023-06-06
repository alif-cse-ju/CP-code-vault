#include<bits/stdc++.h>

using namespace std;

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=1e5+5;
const int mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long long n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n & 1ll)cout << "Odd\n";
        else
        {
            n/=2ll;
            if(n & 1ll)cout << "Same\n";
            else cout << "Even\n";
        }
    }
    return 0;
}
//