#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const i64 mod = 1e9+7;

void mul(i64 &a, i64 b){
      a = ( a * b) % mod;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n;
      cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      i64 ans = 1;
      map<int,i64> cnt;
      rep(i,n){
            cnt[ a[i] ]++;
      }
      for( auto itr:cnt){
            mul(ans,itr.second+1LL);
      }
      cout << ans - 1;
}

