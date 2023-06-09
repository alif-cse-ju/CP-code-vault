#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int ager1[200005],ager2[200005],porer1[200005],porer2[200005];
int main()
    FAST();
    int i,l,t,x,y,ans;
    bool ache1,ache2,ache3;
    char s[200005];
    cin >> t;
    while(t--)
    {
        cin >> s+1;
        l=strlen(s+1);
        ache1=ache2=ache3=false;
        for(i=1;i<=l;i++)
        {
            ache1 |= (s[i] == '1');
            ache2 |= (s[i] == '2');
            ache3 |= (s[i] == '3');
        }
        if(!ache1  ||  !ache2  ||  !ache3)cout << "0\n";
        else
        {
            ans=INT_MAX;
            ager1[0]=ager2[0]=-2*l;
            porer1[l+1]=porer2[l+1]=2*l;
            for(i=1;i<=l;i++)
            {
                if(s[i] == '1')ager1[i]=i,ager2[i]=ager2[i-1];
                else if(s[i] == '2')ager2[i]=i,ager1[i]=ager1[i-1];
                else ager1[i]=ager1[i-1],ager2[i]=ager2[i-1];
            }
            for(i=l;i>0;i--)
            {
                if(s[i] == '1')porer1[i]=i,porer2[i]=porer2[i+1];
                else if(s[i] == '2')porer2[i]=i,porer1[i]=porer1[i+1];
                else porer1[i]=porer1[i+1],porer2[i]=porer2[i+1];
            }
            for(i=1;i<=l;i++)
            {
                if(s[i] == '3')
                {
                    x=min(ager1[i],ager2[i]);
                    ans=min(ans,i-x+1);
                    x=max(porer1[i],porer2[i]);
                    ans=min(ans,x-i+1);
                    x=ager1[i],y=porer2[i];
                    ans=min(ans,y-x+1);
                    x=ager2[i],y=porer1[i];
                    ans=min(ans,y-x+1);
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}