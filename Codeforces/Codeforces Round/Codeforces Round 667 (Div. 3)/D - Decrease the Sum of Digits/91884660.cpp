#include<bits/stdc++.h>
using namespace std;
long long s;
long long SOD(long long n)
    long long sum=0;
    while(n > 0)sum+=n%10,n/=10;
    return sum;
long long FindAns(long long n)
    if(SOD(n) <= s)return 0;
    if(n%10 == 0)return FindAns(n/10)*10;
    return FindAns((n/10)*10+10)-n%10+10;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    long long n;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        cout << FindAns(n) << '\n';
    }
    return 0;