#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
int get(int n){
      return (n*(n-1))/2;
}

void solve(){
      int n,k; cin >> n >> k;
      int r = get(n) - k;
      //debug(r);
      int l = n;
      vector<vector<int>> subs;
      int m = 1;
      for( int i = n; i >= 2 ; i--){
            //debug(i,get(i));
            while( get(i) <= r ){
                  r -= get(i);
                  l -= i;
                  vector<int> sub(i);
                  iota(sub.begin(), sub.end(), m);
                  subs.push_back(sub);
                  m += i;
            }
      }
      //debug(r,l);
      if( l < 0)    cout << "0\n";
      else{
            rep(i,l){
                  subs.push_back({m++});
            }
            for( int i = subs.size()-1; i >= 0; i--){
                  for( int &x:subs[i]){
                        cout << x << " ";
                  }
            }
            cout << '\n';
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

