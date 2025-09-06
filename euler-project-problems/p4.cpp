#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      vector<int> pal;
      for( int i = 100; i <= 999; i++){
            for( int j = 100; j <= 999; j++){
                  int x = i * j;
                  string s = to_string(x);
                  int n = s.length();
                  bool ok = true;
                  for( int k = 0; k < n- k -1; k++){
                       if( s[k] != s[n-k-1]) ok = false; 
                  }
                  if( ok) pal.push_back(x);
            }
      }
      sort(pal.begin(), pal.end());
      cout << pal.back() << '\n';
}

