// counting inversion using seg tree
#include<bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      for( int &x: a) cin >> x;
      vector<int> tree(2*n+1);
      auto update = [&](int i)->void{
            i += n;
            while( i > 0){
                  tree[i]++;
                  i /= 2;
            }
      };
      auto find = [&](int l, int r)->int{
            l += n;
            r += n;
            int ans = 0;
            while(  l <= r){
                  if( l%2 == 1){
                        ans += tree[l];
                        l++;
                  }
                  if( r%2 == 0){
                        ans += tree[r];
                        r--;
                  }
                  l /= 2;
                  r /= 2;
            }
            return ans;
      };
      i64 c = 0;
      for( int i = 0; i < n; i++){
            c += find(a[i]+1,n);
            update(a[i]);
      }
      sort( a.begin(), a.end());
      for( int i = 1; i < n; i++){
            if( a[i] == a[i-1]){
                  c = 0;
            }
      }
      if( c%2 == 0) cout << "YES\n";
      else cout << "NO\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

