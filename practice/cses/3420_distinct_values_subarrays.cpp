#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n;
      cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      map<int,int> m;
      i64 cnt = 0;
      int l = 0, r= 0;
      while(r < n){
            m [ a[r] ]  += 1;
            while( m[ a[r]] > 1){
                  m[ a[l]] -= 1;
                  l++;
            }
            cnt += (long long)(r-l+1);
            r++;
      }
      cout << cnt ;
}

