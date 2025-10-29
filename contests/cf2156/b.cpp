#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n, q; cin >> n >> q;
      string s; cin >> s; 
      int c = count(s.begin(), s.end(), 'B');
      while(q--){
            int x; cin >> x;
            if(c == 0){
                  cout << x << '\n';
            }else{
                  int i = 0;
                  while(x){
                        if( s[i%n] == 'A'){
                              x--;
                        }else{
                              x /= 2;
                        }
                        i++;
                  }
                  cout << i << '\n';
            }
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

