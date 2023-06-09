#include<bits/stdc++.h>
using namespace std;
vector<int>pos_odd;
vector<int>neg_odd;
int main()
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,x,ans=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&x);
        if(x >= 0)
        {
            ans+=x;
            if(x%2 == 1)
            {
                pos_odd.push_back(x);
            }
        }
        else
        {
            if((x+10010)%2 == 1)
            {
                neg_odd.push_back(x);
            }
        }
    }
    if((pos_odd.size())%2 == 1)
    {
        printf("%d",ans);
    }
    else
    {
        int check1=-10000,check2=-10000;
        if(pos_odd.size() > 0)
        {
            sort(pos_odd.begin(),pos_odd.end());
            check1=ans-pos_odd[0];
        }
        if(neg_odd.size() > 0)
        {
            sort(neg_odd.begin(),neg_odd.end());
            check2=ans+neg_odd[neg_odd.size()-1];
        }
        ans=max(check1,check2);
        printf("%d",ans);
    }
    return 0;
}