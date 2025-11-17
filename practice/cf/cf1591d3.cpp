#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
const int N = 1e6+1;
int tree[N];

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      for( int &x:a) cin >> x;
      //memset(tree,0,2*n*sizeof(int));
      for( int i = 0; i <= n; i++) tree[i] = 0;
      auto find = [&](int i)->i64{
            i64 res = 0;
            while( i >= 0){
                  res += tree[i];
                  i = (i&(i+1))-1;
            }
            return res;
      };
      auto update = [&](int i)->void{
            while( i <= n){
                  tree[i]++;
                  i = (i|(i+1));
            }
      };
      i64 c = 0;
      for( int i = 0; i < n; i++){
            c += find(n) - find(a[i]);
            update(a[i]);
      }
      sort( a.begin(), a.end());
      for( int i = 1; i < n; i++){
            if( a[i] == a[i-1]) c = 0;
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

