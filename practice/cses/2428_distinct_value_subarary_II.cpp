#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void compress( vector<int> &a){
      int n = a.size();
      vector<int> d = a;
      sort( d.begin(), d.end() );
      d.resize( unique( d.begin(), d.end()) - d.begin());
      for( int i = 0; i < n; i++){
            a[i] = lower_bound( d.begin(), d.end(), a[i]) - d.begin();
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,k; cin >> n >> k;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      compress(a);
      vector<int> m(n+1);
      int w = 0;
      int l= 0, r = 0;
      long long ans = 0;
      while( r < n){
            m[a[r]]++;
            if(m[a[r]] == 1){
                  w++;
            }
            while( w > k){
                  m[a[l]]--;
                  if( m[a[l]] == 0)
                        w--;
                  l++;
            }
            ans += (r-l+1);
            r++;
      }
      cout << ans;

}

