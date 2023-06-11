#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int s1=0,s2=0;
        int a[n],b[n];
        for(int i=0;i<n;i++)
        {cin>>a[i];
        s1+=a[i];
        }
        for(int i=0;i<n;i++)
        {cin>>b[i];
        s2+=b[i];
        }
        int c=1;
        if(s1>s2)
        {c=0;
        }
        else
        {
        if(a[0]>(b[0]+b[n-1]))
        {c=0;}
        else
        for(int i=1;i<n;i++)
        {if(a[i]>(b[i-1]+b[i]))
        {c=0;
        break;
        }
        }}
        if(c==1)
        cout<<"YES\n";
        else
        cout<<"NO\n";
            }
    return 0;}