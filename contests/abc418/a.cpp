#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      string s; cin >> s;
      if( n >= 3 and  s.substr(n-3,3) == "tea") cout << "Yes\n";
      else cout << "No\n";
}

