#include<bits/stdc++.h>

using i64 = long long;
using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int k; cin >> k;
      string s; cin >> s;
      int n = s.length();
      vector<int> pre(n+1);
      int x = 0 ;
      for( int i = 0; i < n; i++){
            if( s[i] == '1') x++;
            pre[i+1] = x;
      }
      i64 res = 0;
      for( int i = 1; i <= n; i++){
            int t = pre[i-1] + k;
            int l = lower_bound( pre.begin()+i, pre.end(), t) - pre.begin();
            int r = upper_bound( pre.begin()+i, pre.end(), t) - pre.begin();
            if( pre[r-1] == t){
                  res += r - l;
            }
      }
      cout << res << '\n';
}

