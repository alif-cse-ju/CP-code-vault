#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    LL i,n,x=1,cnt=1,lagbe[12];
    cin >> n;
    while(x < n)
    {
        ++cnt;
        x=pow(cnt,10);
    }
    for(i=1;i<11;i++)lagbe[i]=cnt;
    i=10;
    while(true)
    {
        x=pow(cnt,i-1)*pow(cnt-1,11-i);
        if(x < n)break;
        else --lagbe[i--];
    }
    string s="codeforces";
    for(i=1;i<11;i++)
    {
        while(lagbe[i]--)cout << s[i-1];
    }
    return 0;