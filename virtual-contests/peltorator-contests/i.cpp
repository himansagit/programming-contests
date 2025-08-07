#include<bits/stdc++.h>

using namespace std;
//DEBUG
using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)
//SNIPS

const int N = 6e6+10;
int n;

i64 dp0[N];
i64 dp1[N];

void compress( vector<int> &a){
      int n = a.size();
      vector<int> d = a;
      sort( d.begin(), d.end() );
      d.resize( unique( d.begin(), d.end()) - d.begin());
      for( int i = 0; i < n; i++){
            a[i] = lower_bound( d.begin(), d.end(), a[i]) - d.begin();
      }
}
i64 find(i64 tree[], int l, int r){
      i64 sum = 0;
      l += n;
      r += n;
      while( l <= r){
            if( l%2 == 1){
                  sum += tree[l];
                  l++;
            }
            if( r%2 == 0){
                  sum += tree[r];
                  r--;
            }
            l /= 2;
            r /= 2;
      }
      return sum;
}

void update(i64 tree[], int i,i64 x){
      i += n;
      tree[i] += x;
      while( i > 1){
            i /= 2;
            tree[i] = tree[2*i] + tree[2*i+1];
      }
}
void solve(){

      int t; cin >> t;
     vector<int> a(t);
     rep(i,t) cin >> a[i];

     compress(a);
      n = *max_element(a.begin(), a.end())+1;
      i64 ans = 0;
     for( int x: a){
           update(dp0,x,1LL);
            i64 d1 = find(dp0,x+1,n-1);  
            update(dp1,x,d1);
            i64 d2 = find(dp1,x+1,n-1);
            ans += d2; 
     }
     cout << ans ;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

