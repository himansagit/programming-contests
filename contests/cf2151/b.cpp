#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,m; cin >> n >> m;
      int t = n+m;
      string s; cin >> s;
      vector<int> a(m);
      set<int> black;
      //set<int> white;
      vector<int> white(4*t,1);
      rep(i,m){
            cin >> a[i];
            black.insert(a[i]);
            if( a[i] < 4*t) white[a[i]] = 0;
      }

      int cur = 1; 
      for(char c:s){
            if( c== 'A'){
                  cur++;
                 // if( white.find(cur) != white.end()){
                 //       white.erase(white.find(cur));
                 // }
                  if(white[cur] == 1){
                        white[cur] = 0;
                        black.insert(cur);
                  }
            }else{
                  //cur = *white.lower_bound(cur+1);
                  cur++;
                  while( white[cur] == 0) cur++;
                  black.insert(cur);
                  //white.erase(white.find(cur));
                  white[cur] = 0;
                  cur++;
                  while( white[cur] == 0) cur++;
            }
      }
      cout << black.size() << '\n';
      for(int x:black) cout << x << " ";
      cout << '\n';

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

