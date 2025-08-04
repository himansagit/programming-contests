#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define all(x) (x).begin(),(x).end()
#define rep(i, a, b) for( int i = a; i < (b); ++i)

//RNG

void solve(int){
      int n, x;
      cin >> n >> x;
      vector<int> a(n);
      rep(i,0,n) cin >> a[i];
      vector<int> suf(n);
      suf[n-1] = 1;
      for(int i = n-2; i >=0; i--){
            if( a[i] > a[i+1]) suf[i] = 0;
            else suf[i] = suf[i+1];
      }
     int m = min(x,a[0]);
     int cnt = 0;
      rep(i,0,n){
            if( a[i] < m ){
                  cout << "-1\n";
                  return;
            }
            if(suf[i] == 1)
                  break;
            if( a[i] > x ){
                  swap(a[i],x);
                  cnt++;
            }
            m = max(m,a[i]);
      }
      //for(int i = 1; i < n; i++){
      //      if( a[i] < a[i-i]){
      //            cout << "-1\n";
      //            return;
      //      }
      //}
      cout << cnt << "\n";


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
// 81 324   218   413   324
// 81  218   218    324      324               
// 18 81 218 
