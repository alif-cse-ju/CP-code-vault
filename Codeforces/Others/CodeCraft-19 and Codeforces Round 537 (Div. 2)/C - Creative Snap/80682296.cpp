#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL A,B;
vector<int>pos;
LL FindAns(int l,int r)
    int x=lower_bound(pos.begin(),pos.end(),l)-pos.begin();
    int y=upper_bound(pos.begin(),pos.end(),r)-pos.begin();
    if(x == y)return A;
    if(l == r)return B*(LL)(y-x);
    int mid=(l+r) >> 1;
    return min(B*(LL)(y-x)*(LL)(r-l+1),FindAns(l,mid)+FindAns(mid+1,r));
int main()
    FAST();
    int i,l,n,x;
    cin >> n;l=(1 << n);
    cin >> n >> A >> B;
    for(i=0;i<n;i++)cin >> x,pos.emplace_back(x);
    sort(pos.begin(),pos.end());
    cout << FindAns(1,l);
    return 0;