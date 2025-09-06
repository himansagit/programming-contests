#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

using A = array<int,26>;
void solve(){
      string s,t;
      cin >> s >> t;
      int n = s.length();
      vector<A> next(n+1);
      A idx; idx.fill(n+1);
      for( int i = n-1; i >= 0; i--){
            next[i+1] = idx;
            idx[ s[i] - 'a'] = i+1;
      }
      next[0] = idx;
      bool ok = true;
      int cnt = 0;
      int itr = 0;
      for( char c:t){
            int j = c - 'a';
            if( next[0][j] == n+1){
                  // character doesn't exist
                  ok = false;
                  break;
            }
            itr = next[itr][j];
            if(itr == n+1){
                  cnt++;
                  itr = next[0][j];
            }
      }
      if(!ok){
            cout << "-1\n";
      }else{
            cout << cnt +1 << '\n';
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

