#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
using i64 = long long;
const int N = 5e5+10;
vector<int> T(N);
i64 find( int l, int r, vector<int> &a){
     if( r-l+1 <= 1) return 0; 
     int m = (l+r)/2;
     i64 c = find(l,m,a) + find(m+1,r,a);
     int i = l, j = m+1, idx = l;
     while( i <= m){
           while( j <= r and a[i] > a[j]) j++;
           c += (j-m-1);
           i++;
     }
     i = l, j = m+1, idx = l;
     while( idx <= r){
           if( i <= m and j <= r){
                 if( a[i] <= a[j]) T[idx] = a[i++];
                 else T[idx] = a[j++];

           }else if( i <= m){
                 T[idx] = a[i++];
           }else{
                 T[idx] = a[j++];
           }
           idx++;
     }
     for( int idx = l; idx <= r; idx++){
           a[idx] = T[idx];
     }
     return c;
}


void solve(){
      int n; cin >> n;
      vector<int> a(n);
      for( int &a:a) cin >> a;
      i64 c = find(0, a.size()-1, a);
      sort( a.begin(), a.end());    
      for( int i = 1; i < n; i++){
            if(a[i] == a[i-1]){
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

