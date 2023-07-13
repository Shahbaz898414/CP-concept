#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    string s, t;
    cin >> s >> t;

    ll n = s.length();

    ll m = t.length();

    set<int> posn[26];

    for (int i = 0; i < n; i++)
    {
        /* code */
        posn[s[i] - 'a'].insert(i);
    }

    int ans = 1, lastindex = -1;

    for (int i = 0; i < m; i++)
    {
        /* code */
        int ch = t[i] - 'a';
        if(posn[ch].size()==0){
            cout<<-1<<endl;
            return;
        }

        auto it=posn[ch].upper_bound(lastindex);
        if(it==posn[ch].end())
        ans++,lastindex=*posn[ch].begin();
        else lastindex=*it;
    }

    cout<<ans<<endl;
}

int main()
{

    // int t;cin>>t;
    // while(t--) {

    // }

    solve();

    return 0;
}

/*


#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
string s;
int main()
{
    cin>>s;
    vector<int> u[26];
    for(int i = 0;i < s.size(); ++i)
    {
        u[s[i] - 'a'].push_back(i);
    }
    int lastt = -1,ans = 1;
    cin>>s;
    for(int i = 0;i < s.size(); ++i)
    {
        int t = s[i] - 'a';
        if(u[t].empty())
        {
            printf("-1\n");
            return 0;
        }
        vector<int>::iterator iter = lower_bound(u[t].begin(),u[t].end(),lastt + 1);
        if(iter == u[t].end())
        {
            ans++;
            lastt = u[t].front();
        }
        else
        {
            lastt = *iter;
        }
    }
    printf("%d\n",ans);
    return 0;
}

*/
