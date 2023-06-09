#include<bits/stdc++.h>
using namespace std;
vector<int>even;
vector<int>odd;
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,x;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&x);
        if(x%2 == 0)
        {
            even.push_back(x);
        }
        else
        {
            odd.push_back(x);
        }
    }
    int s1,s2;
    s1=even.size();
    s2=odd.size();
    if(abs(s1-s2) <= 1)
    {
        printf("0");
    }
    else
    {
        int ans=0;
        if(s1 > s2)
        {
            sort(even.begin(),even.end());
            for(i=0; i<s1-s2-1; i++)
            {
                ans+=even[i];
            }
        }
        else
        {
            sort(odd.begin(),odd.end());
            for(i=0; i<s2-s1-1; i++)
            {
                ans+=odd[i];
            }
        }
        printf("%d",ans);
    }
    return 0;
}