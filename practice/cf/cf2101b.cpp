#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif
 
using namespace std;

void compress( vector<int> &a){
      int n = a.size();
      vector<int> d = a;
      sort( d.begin(), d.end() );
      d.resize( unique( d.begin(), d.end()) - d.begin());
      for( int i = 0; i < n; i++){
            a[i] = lower_bound( d.begin(), d.end(), a[i]) - d.begin();
      }
}

int parity( vector<int> &a){
      int n = a.size();
      vector<int> inv(n);
      for( int i = 0; i < n; i++){
            inv[a[i]] = i;
      }
      for( int i = 0; i < n-2; i++){
           if( a[i] != i){
                 //assert( inv[i] != i);
                 int x = a[i];
                 int j = inv[i];
                 //int y = a[j];
                 //assert(y == i);
                 int k = n-1;
                 if( j == k) k = n-2;
                  int z = a[k];
                  swap(a[i], a[j]);
                  swap(a[j], a[k]);
                  inv[i] = i;
                  inv[x] = k;
                  inv[z] = j;
           }
      }     
      if( n == 1) return 0;
      else return a[n-1] < a[n-2];
}

void solve(){
      int n; cin >>n;
      vector<int> odd, even;
      for( int i = 0; i < n; i++){
            int x; cin >> x;
            if( i%2) even.push_back(x);
            else odd.push_back(x);
      }
      vector<int> ods = odd;
      vector<int> evs = even;
      sort( ods.begin(), ods.end());
      sort( evs.begin(), evs.end());
      
      vector<int> ans(n);
      for( int i = 0; i < n; i++){
            if( i%2 == 0){
                  ans[i] = ods[i/2];
            }else{
                  ans[i] = evs[i/2];
            }
      }
      compress(odd);
      compress(even);
      int p1 = parity(odd);
      int p2 = parity(even);
      //debug(p1,p2);
      if( p1 != p2){
            swap( ans[n-1], ans[n-3]);
      }
      for( int &x:ans) cout << x << " ";
      cout << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

