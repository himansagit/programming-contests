#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define all(x) (x).begin(),(x).end()
#define sz(x)	(int)(x).size() 
#define pb push_back
#define rep(i, a, b) for( int i = a; i < (b); ++i)

//RNG
void solve(int){
      int n; 
      cin >> n;
      vector<i64> a(n);
      rep(i,0,n) cin >> a[i];
      i64 sum = 0;
      rep(i,0,n) if( (i&1) == 0 ) sum += a[i];
  //    debug(sum);
      i64 pre  = 0;
      i64 modd = 0, meven = 0;
      i64 res = sum; 
      rep(i,0,n){
            if(i&1){
                  pre += a[i];
                  res = max(res,sum + pre - modd);             
//                  debug(i,pre,modd,sum + pre - modd);
                  modd = min(modd, pre);
            }else{
                  pre -= a[i];
                 res = max(res, sum + pre - meven);
 //                 debug(i,pre,meven,sum + pre - meven);
                 meven = min(meven, pre);
            }
      }
      cout << res <<"\n";
}

int32_t main()
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  cin>>tc;
  for(int i = 1; i <= tc; i++){
    solve(i);
  }
  //TIME
}

// sum = 11
// 0 4 1 2 7 5
// 0 -4 -3 -5 2 -3
// 0 11   
// keep prefix min for odd and even
// positions separately
