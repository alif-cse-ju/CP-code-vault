#include<bits/stdc++.h>
using namespace std;
int main()
    int i,l;
    char word[105],uppercase[105],lowercase[105],ucnt=0,lcnt=0;
    cin >> word ;
    l=strlen(word);
    for(i=0; i<l; i++)
    {
        if(word[i]>='A' && word[i]<='Z')
        {
            ucnt++;
            uppercase[i]=word[i];
            lowercase[i]=word[i]-'A'+'a';
        }
        else
        {
            lcnt++;
            uppercase[i]=word[i]-'a'+'A';
            lowercase[i]=word[i];
        }
    }
    if(ucnt>lcnt)
    {
        for(i=0;i<l;i++)
        {
            cout << uppercase[i];
        }
    }
    else
    {
        for(i=0;i<l;i++)
        {
            cout << lowercase[i];
        }
    }
    return 0;
}