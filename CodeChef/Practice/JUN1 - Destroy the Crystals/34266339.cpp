#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,n,p,ans=0;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)cin >> a[i];
    cin >> p;
    sort(a,a+n);
    deque<int>dq;
    for(i=0;i<n;i++)dq.emplace_back(a[i]);
    while(!dq.empty())
    {
        if(dq.front() <= p)++ans,p-=dq.front(),dq.pop_front();
        else
        {
            if(dq.size() > 1)--ans,p+=dq.back(),dq.pop_back();
            else break;
        }
    }
    cout << ans;
    return 0;
}