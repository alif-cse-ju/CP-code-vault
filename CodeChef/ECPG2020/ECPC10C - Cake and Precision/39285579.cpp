#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string SumOfTwoStrings(string a,string b)
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    char c;
    string ans="";
    int length_of_a=a.size(),length_of_b=b.size();
    int i,carry=0,sum,length=max(length_of_a,length_of_b);
    for(i=0; i<length; i++)
    {
        if(i >= length_of_a)sum=(b[i]-48)+carry;
        else if(i >= length_of_b)sum=(a[i]-48)+carry;
        else sum=(a[i]-48)+(b[i]-48)+carry;
        carry=sum/10,sum%=10,c=sum+48,ans+=c;
    }
    if(carry > 0)ans+=(carry+48);
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        cout << SumOfTwoStrings(s,"1") << '\n';
    }
    return 0;
}