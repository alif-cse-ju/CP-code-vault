#include<bits/stdc++.h>
using namespace std;
using lol=long long int;
#define endl "\n"
int main()
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int _=1;
cin>>_;
while(_--)
    int n;
    cin>>n;
    vector<lol> v(n);
    for(auto& e:v)  cin>>e;
    int k=accumulate(v.begin(),v.end(),0ll)/n;
    vector<int> b(n),ans(n,0);
    int lf=n-k;
    for(int i=lf;i<n;i++)   b[i]=n-1;
    for(int i=n-1;i>=0 && lf<=i;i--)
    {
        int cur=v[i]-(b[i]-i);
        if(cur==i+1)    ans[i]=1;
        else if(cur==1)
        {
            ans[i]=0;
            lf--;
            b[lf]=i-1;
        }
    }
    for(auto& e:ans)    cout<<e<<" ";
    cout<<endl;
return 0;