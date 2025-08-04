#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      string s;
      cin >> s;
      int n = s.length();

      string t = s.substr(0,1);
      int l = 0, r = 0;
      int i = 0;
      vector<int> mark(26);
      mark[s[0]-'a'] = 1;
      bool ok = true;
      for(int j = 1; j < n ;j ++){
            int c = s[j] - 'a';
            if( mark[c] == 1){
                  // already on keyboard;
                  // must be to left or right;
                  if( i > 0 and t[i-1] == s[j]){
                        i--;
                  }else if( i < r and t[i+1] == s[j]){
                        i++;
                  }else{
                        ok = false;
                        break;
                  }
            }else{
                  if( i == 0){
                        // append to left
                        t = s[j] + t;
                        mark[c] = 1;
                        r++;
                  }else if( i == r){
                        //append to right
                        t = t + s[j];
                        mark[c] = 1;
                        r++;
                        i++;
                  }else{
                        ok = false;
                        break;
                  }
            }
      }
      if(!ok){
            cout << "NO\n";
            return;
      }
      cout << "YES\n";
      rep(i,26){
            if( mark[i] == 0){
                  t += (char)(i+ 'a');
            }
      }
      cout << t <<"\n";


}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
      //TIME
}

