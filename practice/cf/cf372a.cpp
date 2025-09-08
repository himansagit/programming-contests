#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      sort( a.begin(), a.end());
      int add = -1;
      auto check = [&](int i)->bool{
            int l = 0, r = i+1;
            while(l <= i){
                  while( r < n and a[l]*2 > a[r]) r++;
                  if( r == n) return false;
                  r++;
                  l++;
            }
            if( l <= i) return false;
            return true;      
      };
      for( int z = n; z > 0 ; z /= 2){
            while( add + z < n and check(add+z)){
                  add += z;
            }
      }
      cout << n - add -1 << '\n';
}

