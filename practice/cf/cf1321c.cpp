#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      string s;
      cin >> s;
      char rm = 'z';
      int cnt = 0;
      while( rm > 'a'){
            bool f = false;
            for( int i = 0; i < s.length(); i++){
                  if( s[i] == rm ){
                        if( (i > 0 and s[i-1] == rm-1 ) or ( i < s.length()-1 and s[i+1] == (char)rm-1)){
                              cnt++;
                              f = true;
                              s.erase(s.begin() + i);
                        }
                  }
            }
            if(!f) rm--;
      }
      cout << cnt;



}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

