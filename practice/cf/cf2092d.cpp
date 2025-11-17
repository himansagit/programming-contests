#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;

void solve(){
      int n; cin >> n;
      string s; cin >> s;
      vector<int> cnt(3);
      vector<pair<int,char>> t;
      for( char &c:s){
            if( c == 'L') cnt[0]++;
            else if( c == 'I') cnt[1]++;
            else cnt[2]++;
      }
      t.push_back({cnt[0],'L'});
      t.push_back({cnt[1],'I'});
      t.push_back({cnt[2],'T'});
      string tmp(4*n, '#');
      for( int i = 0; i < n; i++) tmp[i] = s[i];
      int sz = n;
      vector<int> ans;
      auto fill = [&](char c)->bool{
            for( int j = 0; j < sz-1; j++){
                  if( tmp[j] != tmp[j+1] and tmp[j] != c and tmp[j+1] != c){
                        for( int k = sz-1; k >= j+1; k--){
                              swap(tmp[k], tmp[k+1]);
                        }
                        tmp[j+1] = c;
                        ans.push_back(j+1);
                        return true;
                  }
            }
            return false;
      };
      bool ok = false;
      for( int i = 0; i < 2*n; i++){
            sort( t.begin(), t.end());
            //debug(t);
            if( t[0].first == t[1].first and t[1].first == t[2].first){
                  ok = true;
                  break;
            }
            for( int j = 0; j < 3; j++){
                  if( fill(t[j].second)){
                        t[j].first++;
                        sz++;
                        break;
                  }
            }
      }
      if(ok){
            cout << ans.size() << '\n';
            for( int &x:ans) cout << x << " " ;
            cout << '\n';
      }else{
            cout << "-1\n";
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}
