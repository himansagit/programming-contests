#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
const int E = 100000;
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      vector<string> s(n);
      rep(i,n) cin >> s[i];

      vector<vector<int>> mat( n, vector<int> (n));

      for( int k = 2*n-2; k >= 0; k--){
            vector<pair<int,int>> v;
            for( int r = 0;  r < n; r++){
                  int c = k - r;
                  if(   min(r,c) >= 0 and max(r,c) < n){
                       int e = E;
                       if( r + 1 < n) e = min(e, mat[r+1][c]);
                       if( c+1 < n) e = min(e, mat[r][c+1]);
                       //assert( e < E);
                       v.push_back({E*(s[r][c] - 'A') + e, n*r + c});
                  }
            }
            sort( v.begin(), v.end());
            for( int j = 0; j < v.size(); j++){
                  auto [deg,x] = v[j];
                  mat[x/n][x%n] = j;
            }
      }
      int r = 0, c = 0;
      while( r < n and c < n){
            cout << s[r][c];
            if( r+1 < n and c+1 < n){
                 if( mat[r+1][c] <= mat[r][c+1]){
                       r++;
                 }else{
                       c++;
                 }
            }else if( r+1 < n){
                  r++;
            }else if( c+1 < n){
                  c++;
            }else{
                  break;
            }
      }
      cout << '\n';
}

