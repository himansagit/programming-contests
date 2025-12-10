#include<bits/stdc++.h>

using namespace std;

struct BIT{
      vector<int> bit;
      int n;
      BIT(int _n){
            n = _n;
            bit.assign(n,0);
      }
      BIT( vector<int> &a){
            n = a.size();
            bit.assign(n,0);
            for( int i = 0; i < n; i++){
                  update(i,a[i]);
            }
      }
      void update(int i,int x){
            while( i < n){
                  bit[i] += x;
                  i = i |(i+1);
            }
      }
      int get(int i){
            int res = 0;
            assert(i < n);
            while( i >= 0){
                 res += bit[i]; 
                 i = (i&(i+1)) - 1;
            }
            return res;
      }
      int sum(int l, int r){
            return get(r) - get(l-1);
      }
};

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n,k; cin >> n >> k;
      BIT fwk(n);
      for( int i = 0; i < n; i++){
            fwk.update(i,1);
      }
      int cur = 0;
      for( int t = 0; t < n; t++){
            int rem = fwk.sum(0,n-1);
            int move = (k+1)%rem;
            if( move == 0) move = rem;
            int l = 0, r = n;
            while( l < r){
                  int w = (l+r)/2;
                  int sum = 0;
                  if( cur + w < n) sum = fwk.sum(cur,cur+w);
                  else{
                        sum = fwk.sum(cur,n-1);
                        sum += fwk.sum(0,cur+w-n);
                  }
                  if( sum < move){
                        l = w+1;
                  }else{
                        r = w;
                  }
            }
            cur += l;
            if( cur >= n) cur -= n;
            fwk.update(cur,-1);
            cout << cur +1 << ' ';
      }
      cout << '\n';
}

