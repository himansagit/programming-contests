#include<bits/stdc++.h>


#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      string s,t; cin >> s >> t;
      vector<int> pre,suf;
      int n =s.length();
      int l = 0, r = n-1;
      for(char c:t){
            while( l < n and s[l] != c){
                  l++;
            }
            assert(l < n);
            pre.push_back(l);
            l++;
      }
      for(int i = t.length()-1; i >= 0; i--){
            char c = t[i];
            while( r >= 0 and s[r] != c){
                  r--;
            }
            assert( r >= 0);
            suf.push_back(r);
            r--;
      }
      reverse(suf.begin(), suf.end());
      assert( pre.size() == suf.size());
      int ans = 0;
      for( int i = 0; i < pre.size()-1; i++){
            assert( pre[i] < suf[i+1]);
            ans = max( ans, suf[i+1] - pre[i]-1);
      }
      debug(pre,suf);
      debug(ans);      
      ans = max(ans, suf[0]);
      ans = max(ans, n-pre.back()-1);
      cout << ans << '\n';
}

