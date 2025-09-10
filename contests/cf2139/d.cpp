#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif


using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,q; cin >> n >> q;
      vector<int> a(n+2);
      rep(i,n) cin >> a[i+1];
      a[0] = a[1];
      a[n+1] = a[n];
      vector<int> odd(n+2), even(n+2);
      for( int i = 1; i <= n+1; i++){
            int x = min(a[i],a[i-1]);
            int y = -1;
            if( i > 1) y = max(y,a[i-2]);
            if( i > 2) y = max(y,a[i-3]);
            if( i%2 == 0){
                  if( x >= y){
                        if( i > 1)
                             even[i-1] = even[i-2];
                        else 
                              even[i] = i;
                        even[i] = even[i-1];
                  }else{
                        even[i-1] = i-1;
                        even[i] = even[i-1];
                  }
            }else{
                  if( x >= y){
                        if( i > 1)
                             odd[i-1] = odd[i-2];
                        else 
                              odd[i] = i;
                        odd[i] = odd[i-1];
                  }else{
                        odd[i-1] = i-1;
                        odd[i] = odd[i-1];
                  }

            }
      }
      auto find = [&](int l, int r)->bool{
            int w = r-l+1;
           assert( w%2 == 0);
            if( w <= 2) return true;
           if( r%2 == 0) return even[r] <= l;
           else return odd[r] <= l;
      };
      rep(j,q){
            int l,r;
            cout << j+ 1<< " ";
            cin >> l >> r;
            cout << l << " " << r << " ";
            int w = r-l+1;
            if( w%2 == 0){
                 if( find(l,r) ) cout << "YES\n";
                 else{
                       assert( w >= 4);
                        if( a[l] <= min(a[l+1], a[l+2]) and a[r] >= max(a[r-1],a[r-2]) and find(l+1,r-1))
                                    cout << "YES\n";
                        else
                              cout << "NO\n";
                 }
            }else{
                  if( w == 1) cout << "YES\n";
                  else{
                       if( find(l,r-1) and a[r] >= max(a[r-1],a[r-2])) cout << "YES\n";
                        else if( find(l+1,r) and a[l] <= min(a[l+1],a[l+2])) cout << "YES\n";
                        else cout << "NO\n";
                  }
            }
      }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

