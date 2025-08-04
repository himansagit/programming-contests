#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

const int  N = 1e6+10;
void solve(){
      int n;
      cin >> n;
      vector<int>  a(n+1);
      rep(i,n) cin >> a[i+1];
      vector<int> mark(N);
      i64 cnt = 0;
      for(int i = 1; i<= n; i++){
            if( i >= a[i]){
                  cnt += (i64)mark[i-a[i]];
            }
            mark[i+a[i]]++;
      }
      cout << cnt << "\n";

}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

