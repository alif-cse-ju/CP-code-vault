#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    int t;
    LL ans,low,mid,high,steps;
    long double avg,cur,hot,cold,expect;
    cin >> t;
    while(t--)
    {
        cin >> hot >> cold >> expect;
        ans=2LL,low=1,high=1e6,cur=abs(expect-(hot+cold)/2.0);
        while(low <= high)
        {
            mid=(low+high) >> 1;
            steps=2*mid-1;
            avg=((mid*1.0)*hot+((mid-1)*1.0)*cold)/(steps*1.0);
            if(avg > expect)low=mid+1;
            else high=mid-1;
            avg=abs(expect-avg);
            if(avg < cur)ans=steps,cur=avg;
            else if(avg == cur)ans=min(ans,steps);
        }
        cout << ans << '\n';
    }
    return 0;