#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
const int N = 2e5+10;
vector<int> T(N);
int find( int l, int r, vector<int> &a){
     if( r-l+1 <= 1) return 0; 
     int m = (l+r)/2;
     int c = find(l,m,a) + find(m+1,r,a);
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
      for( int i = 0; i < n; i++){
            cin >> a[i];
      }
      int c = find(0,n-1,a);
      cout << c << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

