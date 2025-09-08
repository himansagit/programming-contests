#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      string s = "helllo";
      auto dfs = [&](this auto ,string s)->void{
            if( s.length() == 0)
                  return;
            cout << s[0];
            dfs(s.substr(1,s.length()-1));
      };
      dfs(s);
}

