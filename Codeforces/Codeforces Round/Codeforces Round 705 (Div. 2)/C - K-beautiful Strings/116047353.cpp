#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
char s[M];
int k,l,ans[26],cnt[26][M];
int Check(int pos)
    int i,j,cntT;
    for(j=s[pos]-'a'+1;j<26;j++)
    {
        cntT=0;
        for(i=1;i<26;i++)cntT+=((cnt[i][pos-1]+k-(i != j))/k)*k;
        if(l-cntT >= cnt[0][pos-1])return j;
    }
    return 0;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,ps,t,ll;
    cin >> t;
    while(t--)
    {
        cin >> l >> k >> s+1;
        if(l%k)
        {
            cout << "-1\n";
            continue;
        }
        for(i=1;i<=l;i++)
        {
            for(j=0;j<26;j++)cnt[j][i]=cnt[j][i-1];
            ++cnt[s[i]-'a'][i];
        }
        for(i=0;i<26 && (cnt[i][l]%k == 0);i++);
        if(i == 26)
        {
            for(i=1;i<=l;i++)cout << s[i];
            cout << '\n';
            continue;
        }
        for(ps=l;;ps--)
        {
            i=Check(ps);
            if(i)break;
        }
        s[ps]=(char)('a'+i);
        for(i=1;i<26;i++)ans[i]=cnt[i][ps-1]+(i == (s[ps]-'a'));
        ll=l;
        for(i=1;i<26;i++)ans[i]=((ans[i]+k-1)/k)*k,ll-=ans[i];
        ans[0]=ll;
        for(i=1;i<=ps;i++)cout << s[i],--ans[s[i]-'a'];
        for(i=0;i<26;i++)
        {
            while(ans[i]--)cout << (char)('a'+i);
        }
        cout << '\n';
    }
    return 0;
}