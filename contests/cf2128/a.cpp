#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(int){
      i64 n,c;
      cin >> n >> c;
      vector<i64> a(n);
      rep(i,n) cin >> a[i];
      sort(a.rbegin(),a.rend());
      i64 cnt = 0;
      i64 m = 1; 
      rep(i,n){
            if( a[i]*m > c )
                  cnt++;
            else{
                  m*=2;
            }
      }
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

