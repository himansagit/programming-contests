#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int n,k;
const int N = 4e5+10;
int tree[N];
void build( vector<int> &a){
      int n = a.size();
      rep(i,n) tree[n+i] = a[i];
      for( int i = n-1; i > 0; i--){
            tree[i] = max( tree[2*i] , tree[2*i+1]);
      }
}

int find(int l, int r){
      l += n-1;
      r += n-1;
      int res = 0;
      while( l <= r){
            if( l%2 == 1){
                  res = max(res, tree[l]);
                  l++;
            }
            if( r%2 == 0){
                  res = max( res, tree[r]);
                  r--;
            }
            l /= 2;
            r /= 2;
      }
      return res;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
     cin >> n;
     vector<int> a(n);
     rep(i,n) cin >> a[i];
      build(a);
      cin >> k;
      while(k--){
            int l, r;
            cin >> l >> r;
            cout << find(l,r) << '\n';
      }

}

