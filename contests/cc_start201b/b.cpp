#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n;
      cin >> n;
      string s;
      cin >> s;
      int cnt = 0;
      for( char c:s){
            if( c == '0'){
                  if(cnt > 0 and cnt <= 2){
                        cout << "No\n";
                        return;
                  }
                  cnt = 0;
            }else{
                  cnt++;
            }
      }
      if( cnt > 0 and cnt <= 2){
            cout << "No\n";
            return;
      }
      cout << "Yes\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

