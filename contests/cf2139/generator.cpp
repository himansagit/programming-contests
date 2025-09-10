
#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)


int32_t main(int argc, char* argv[])
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      mt19937_64 RNG( atoi(argv[1]));
      // start code here
      int t = 1;
      cout << t << '\n';
      while(t--){
            int n = RNG()%5 +1;
            vector<pair<int,int>> qry;
            for( int i = 1; i  <= n; i++){
                  for( int j = i ; j <= n; j++){
                        qry.push_back({i,j});
                  }
            }
            cout << n << " " << qry.size() << '\n';
            rep(i,n) cout << RNG()%(2*n) +1 << " ";
            cout << '\n';
            for( auto &x:qry) cout << x.first << " " << x.second << '\n';
      }
}
