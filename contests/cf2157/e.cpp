#include<bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using namespace std;
const int N = 1e7+6;
int tree[N];
int cnt[N];
const int inf = 1e8;

void solve(){
      int n,k; cin >> n >> k;
      vector<int> a(n);
      for( int i = 0; i < n; i++) cin >> a[i];
      int n8 = 8*n + 8;
      int n4 = 4*n + 4;
      
      auto update = [&](int i,int x)->void{
            i += n4;
            tree[i] = x;
            while( i > 1){
                 i /= 2;
                 tree[i] = max(tree[2*i], tree[2*i+1]);
            }
      };

      auto get = [&](int l, int r)->int{
            l += n4;
            r += n4;
            int res = 0;
            while( l <= r){
                  if( l%2 == 1){
                        res = max(res, tree[l]);
                        l++;
                  }
                  if( r%2 == 0){
                        res = max(res, tree[r]);
                        r--;
                  }
                  l /= 2;
                  r /= 2;
            }
            return res;
      };

      int l = 0, r = n*n+1;
      while( l < r){
            int m = (l+r)/2;
            fill(cnt,cnt+n8,0);       
            fill(tree,tree+n8,inf);       
            //debug(l,r,m);
            for( int i = 0; i < n; i++){
                  int x = a[i];
                  //debug(x);
                  int left = x, right = x + m;
                  while( left < right){
                        int mid = (left + right+1)/2;
                        //debug(left,right,mid);
                        //int mm  = get(x,mid);
                        //debug(mm);
                        if( get(x,mid) < m) left = mid;
                        else right = mid-1;
                  }
                  int mm = get(x,left);
                  if( mm >= inf){
                        update(x,0);
                        cnt[x]++;
                  }else{
                        update(left+1,mm+1);
                        cnt[left+1]++;
                  }
                 // if( left > right){
                 //       update(x,0);
                 //       cnt[x]++;
                 // }else{
                 //       update(left+1, get(x,left)+1);
                 //       cnt[left+1]++;
                 // }

            }
            bool ok = true;
            for( int i = 1; i <= 4*n; i++){
                  if( cnt[i] > k) ok = false;
            }
            if( ok) r = m;
            else l = m+1;
      }
      cout << l << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

