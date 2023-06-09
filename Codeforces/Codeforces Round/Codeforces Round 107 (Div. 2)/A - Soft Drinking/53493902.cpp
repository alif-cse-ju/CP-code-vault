#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define PB push_back
#define LL long long int
#define PII pair<int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MLI map<long long int,int>
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n, k, l, c, d, p, nl, np;
    cin >> n;
    cin >> k >> l;
    int total_drink=k*l;
    cin >> c >> d;
    int total_slice=c*d;
    cin >> p;
    int total_salt=p;
    cin >> nl >> np;
    cout << min(total_drink/nl,min(total_slice,total_salt/np))/n;
    return 0;