#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif


using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,m;
      cin >> n >> m;
      vector<char> res;
      if( n == 0){
             res.assign(2*m-1,'>');
            for( int i = 1; i < 2*m-1; i +=2) res[i] = '<';
            res[2*m-3] = '=';
      }else if( m == 0){
             res.assign(2*n-1,'<');
            res[2*n-3] = '=';
      }else{
            rep(i,2*n) res.push_back('<');
            res.push_back('>');
            rep(i,m-1){
                  res.push_back('<');
                  res.push_back('>');
            }
      }
      for(char c: res) cout << c ;
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

