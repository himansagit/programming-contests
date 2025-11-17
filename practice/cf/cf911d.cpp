#include<bits/stdc++.h>

using namespace std;


int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n,m; cin >> n;
      vector<int> a(n);
      for(int &e:a) cin >> e;
      vector<int> tree(n+1);
      auto add = [&]( int idx)->void{
            while( idx <= n){
                  tree[idx]++;
                  idx = (idx | (idx+1));
            }
      };
      auto sum = [&](int idx)->int{
            int res = 0;
            while( idx >= 0){
                  res += tree[idx];
                  idx = (idx&(idx+1)) -1;
            }
            return res;
      };
      int c  = 0;
      for( int i = 0; i < n; i++){
            c += sum(n) - sum(a[i]);
            add( a[i]);
      }
      cin >> m;
      while( m--){
            int l, r; cin >> l >> r;
            c += (r-l+1)/2;
            if( c%2 == 0) cout << "even\n";
            else cout << "odd\n";
      }
}

