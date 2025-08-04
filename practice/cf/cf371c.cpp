#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      string S;
      cin >> S;
      i64 nb,ns,nc,pb,ps,pc,r;
      cin >> nb >> ns >> nc >> pb >> ps >> pc;
      cin >> r;
      i64 b = count( S.begin(), S.end(), 'B');
      i64 s = count( S.begin(), S.end(), 'S');
      i64 c = count( S.begin(), S.end(), 'C');
      
      i64 ans = -1;
      auto check = [&](i64 t)->bool{
            i64 cost = max( t*b - nb,0LL)*pb;
            cost += max( t*s - ns,0LL)*ps;
            cost += max( t*c - nc,0LL)*pc;
            return cost <= r;
      };
      for( i64 z = 1e14; z > 0LL; z /= 2LL){
            while( check(ans +z)){
                  ans += z;
            }
      }
      cout << ans ;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

