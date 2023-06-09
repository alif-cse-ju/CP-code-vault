#include<bits/stdc++.h>
using namespace std;
vector<int>left_foot[30];
vector<int>right_foot[30];
int mark[30];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,j,n,bal,l1,r1,cnt1,cnt2;
    string s1,s2;
    cin >> n;
    cin >> s1 >> s2;
    for(i=0; i<n; i++)
    {
        if(s1[i] == '?')
        {
            left_foot[27].push_back(i+1);
        }
        else
        {
            left_foot[s1[i]-96].push_back(i+1);
        }
        if(s2[i] == '?')
        {
            right_foot[27].push_back(i+1);
        }
        else
        {
            right_foot[s2[i]-96].push_back(i+1);
        }
    }
    int cnt=left_foot[27].size()+right_foot[27].size();
    for(i=1; i<=26; i++)
    {
        mark[i]=min(right_foot[i].size(),left_foot[i].size());
        cnt+=mark[i];
    }
    if(cnt > n)
    {
        cnt=n;
    }
    cout << cnt << endl;
    int check=0;
    if(cnt > 0)
    {
        for(i=1; i<27; i++)
        {
            for(j=0; j<mark[i]; j++)
            {
                cout << left_foot[i][j] << ' ' << right_foot[i][j] << endl;
                check++;
                if(check == cnt)
                {
                    return 0;
                }
            }
        }
        if(check < cnt)
        {
            l1=left_foot[27].size();
            r1=right_foot[27].size();
            cnt1=0;
            for(i=1; i<=26; i++)
            {
                bal=right_foot[i].size();
                if(bal >= mark[i])
                {
                    for(j=mark[i]; j<bal; j++)
                    {
                        cout << left_foot[27][cnt1] << ' ' << right_foot[i][j] << endl;
                        check++;
                        cnt1++;
                        if(cnt1 == l1)
                        {
                            break;
                        }
                        if(check == cnt)
                        {
                            return 0;
                        }
                    }
                }
                if(cnt1 == l1)
                {
                    break;
                }
            }
        }
         if(check < cnt)
        {
            cnt2=0;
            for(i=1; i<=26; i++)
            {
                for(j=mark[i]; j<left_foot[i].size(); j++)
                {
                    cout << left_foot[i][j] << ' ' << right_foot[27][cnt2] << endl;
                    cnt2++;
                    check++;
                    if(cnt2 == r1 || check == cnt)
                    {
                        return 0;
                    }
                }
            }
        }
        i=cnt1,j=cnt2;
        for( ; i<l1 && j<r1; i++,j++)
        {
            cout << left_foot[27][i] << ' ' << right_foot[27][j] << endl;
        }
    }
    return 0;
}
 