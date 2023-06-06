#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<int>digits;
int n,sz,ans=INT_MAX;

void Check(int cur,int pos)
{
    if(pos > sz)
    {
        if(cur >= n)ans=min(ans,cur);
        return;
    }
    for(int x : digits)Check(cur*10+x,pos+1);
}

int main()
{
    FAST();
    int i,k,x;
    bool mark[10]={0};
    cin >> n >> k;
    for(i=0;i<k;i++)
    {
        cin >> x;
        mark[x]=1;
    }
    for(i=0;i<10;i++)
    {
        if(!mark[i])digits.emplace_back(i);
    }
    sz=to_string(n).size();
    Check(0,1);
    if(ans < INT_MAX)cout << ans;
    else
    {
        if(digits[0] == 0)cout << digits[1];
        else cout << digits[0];
        for(i=0;i<sz;i++)cout << digits[0];
    }
    return 0;
}
