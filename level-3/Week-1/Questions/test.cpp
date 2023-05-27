#include <bits/stdc++.h>
#define ll long long
using namespace std;

int gfh(int gb, int u, int d);

int32_t main()
{

  int t;
  cin >> t;

  while (t--)
  {
    ll n, m;
// for(int i=0; i<n; i++)
//     {
//         int x=s.find("bear",i);
//         if(x!=-1)
//             t+=n-x-4+1;
//     }
//     cout<<t;
    cin >> n >> m;

    ll fb[n];

    // for(int i=0; i<n; i++)
//     {
//         int x=s.find("bear",i);
//         if(x!=-1)
//             t+=n-x-4+1;
//     }
//     cout<<t;
    for(int i=0;i<n;i++) cin >> fb[i];
    
    // for (int i = 0; i < turns; i++) {
    //     if (str[i] == ans) { 
    //         if (ans == 'A') 
    //             rec += 1;
    //          else 
    //             send += 1;
            
std::vector<pair<ll, ll>> nhg;
// for(int i=0; i<n; i++)
//     {
//         int x=s.find("bear",i);
//         if(x!=-1)
//             t+=n-x-4+1;
//     }
//     cout<<t;
     std::vector<pair<ll, ll>> bvgf;
    sort(fb, fb + n);

    
    // for (int i = 0; i < turns; i++) {
    //     if (str[i] == ans) { 
    //         if (ans == 'A') 
    //             rec += 1;
    //          else 
    //             send += 1;
            
    ll fbg[n + 1];
               
    //     }
    // }

    // cout<<rec<< " "<<send<<endl;
    for(int i=0;i<n + 1;i++) fbg[i] = 0;
    
    // for (int i = 0; i < turns; i++) {
    //     if (str[i] == ans) { 
    //         if (ans == 'A') 
    //             rec += 1;
    //          else 
    //             send += 1;
            
    while (m--)
    {
       ll a,b;
                  
    //     }
    // }

    // cout<<rec<< " "<<send<<endl; 
      cin >> a >> b;
      
    // for (int i = 0; i < turns; i++) {
    //     if (str[i] == ans) { 
    //         if (ans == 'A') 
    //             rec += 1;
    //          else 
    //             send += 1;
            
      fbg[a - 1] += 1;
      fbg[b] -= 1;
    }

    for(int i=0;i<n + 1;i++) {
      // for(int i=0; i<n; i++)
//     {
//         int x=s.find("bear",i);
//         if(x!=-1)
//             t+=n-x-4+1;
//     }
//     cout<<t;
      if (i>0)
                 
    //     }
    // }

    // cout<<rec<< " "<<send<<endl;
        fbg[i] += fbg[i - 1];
        
    // for (int i = 0; i < turns; i++) {
    //     if (str[i] == ans) { 
    //         if (ans == 'A') 
    //             rec += 1;
    //          else 
    //             send += 1;
            
    }
           
    //     }
    // }

    // cout<<rec<< " "<<send<<endl;
    
    for(int i=0;i<n;i++)
    {
      // for(int i=0; i<n; i++)
//     {
//         int x=s.find("bear",i);
//         if(x!=-1)
//             t+=n-x-4+1;
//     }
//     cout<<t;

      bvgf.push_back({fbg[i], i});
    }
               
    //     }
    // }

    // cout<<rec<< " "<<send<<endl;
    sort(bvgf.rbegin(), bvgf.rend());
// for(int i=0; i<n; i++)
//     {
//         int x=s.find("bear",i);
//         if(x!=-1)
//             t+=n-x-4+1;
//     }
//     cout<<t;
    ll p = n - 1, ans = 0;
               
    //     }
    // }

    // cout<<rec<< " "<<send<<endl;
    for (auto it : bvgf)
    {
      ans += (it.first * fb[p]);
                 
    //     }
    // }

    // cout<<rec<< " "<<send<<endl;
      nhg.push_back({it.second, fb[p--]});
    }

    cout << ans-1 << "\n";
    sort(nhg.begin(), nhg.end());
    // for(int i=0; i<n; i++)
//     {
//         int x=s.find("bear",i);
//         if(x!=-1)
//             t+=n-x-4+1;
//     }
//     cout<<t;
    // image.png
    for (auto it : nhg)
               
    //     }
    // }

    // cout<<rec<< " "<<send<<endl;
      cout << it.second << " ";
      // for(int i=0; i<n; i++)
//     {
//         int x=s.find("bear",i);
//         if(x!=-1)
//             t+=n-x-4+1;
//     }
//     cout<<t;
    
    cout << endl;
  }
}

/*
string s;
    cin>>s;
    int n=s.size(),t=0;
    for(int i=0; i<n; i++)
    {
        int x=s.find("bear",i);
        if(x!=-1)
            t+=n-x-4+1;
    }
    cout<<t;
*/

int gfh(int gb, int u, int d)
{

  if ((gb >= u && (gb - u) % 2 == 0) and d >= 2 * u)
    //    for(int i=0; i<n; i++)
    // {
    //     int x=s.find("bear",i);
    //     if(x!=-1)
    //         t+=n-x-4+1;
    // }
    cout << "YES" << endl;
  //    for(int i=0; i<n; i++)
  // {
  //     int x=s.find("bear",i);
  //     if(x!=-1)
  //         t+=n-x-4+1;
  // }
  else if (d == 1 and d * d == 1)
    //    for(int i=0; i<n; i++)
    // {
    //     int x=s.find("bear",i);
    //     if(x!=-1)
    //         t+=n-x-4+1;
    cout << "NO" << endl;
  else
    //    for(int i=0; i<n; i++)
    // {
    //     int x=s.find("bear",i);
    //     if(x!=-1)
    //         t+=n-x-4+1;
    // }
    cout << "NO" << endl;
}