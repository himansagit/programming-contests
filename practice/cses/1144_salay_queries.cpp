#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

//int compress( vector<int> &a, map<int,int> &m){
//      int n = a.size();
//      vector<int> d = a;
//      sort( d.begin(), d.end() );
//      d.resize( unique( d.begin(), d.end()) - d.begin());
//      for( int i = 0; i < n; i++){
//            int t = lower_bound( d.begin(), d.end(), a[i]) - d.begin();
//            m[a[i]] = t;
//            a[i] = t;
//      }
//      return d.back();
//}

//using Q = array<int,3>;

const int N = 2e6+10;
int q[(int)2e5+10][3];
int sz_t;

int tree[N];

void update(int i, int x){
      i += sz_t;
      tree[i] += x;
      while( i > 1){
            i /= 2;
            tree[i] = tree[2*i] + tree[2*i+1];
      }
}

int find(int l,int r){
      l += sz_t;
      r += sz_t;
      int res = 0;
      while(l<=r){
            if( l%2 == 1){
                  res += tree[l];
                  l++;
            }
            if( r%2 == 0){
                  res += tree[r];
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
      
      //memset(tree,0,sizeof(tree));
      int n, t; cin >> n >> t;
      vector<int> a(n);
      vector<int> d;
      rep(i,n){
            cin >> a[i];
            d.push_back(a[i]);
      }
      //vector<Q> q(t);
      rep(i,t){
            char c;
            cin >> c >> q[i][1] >> q[i][2];
            d.push_back(q[i][2]);
            if( c == '?'){
                  q[i][0] = 1;
                  d.push_back( q[i][1]);
            }
      }
      map<int,int> m;
      int id = 0;
      sort( d.begin(), d.end());
      sz_t = d.size();
      rep(i,sz_t){
            m[ d[i]] = id++;
      }
      
      rep(i,n){
            a[i] = m[ a[i]];
      }
      rep(i,t){
            q[i][2] = m[ q[i][2]];
            if( q[i][0] == 1){
                  q[i][1] = m[ q[i][1]];
            }
      }

      rep(i,n){
            tree[ sz_t + a[i]]++;
      }
      for(int i = sz_t -1; i > 0; i--){
            tree[i] = tree[2*i] + tree[2*i+1];
      }
      rep(i,t){
            if( q[i][0] == 0){
                  update( a[q[i][1]-1],-1);
                  update(q[i][2], 1);
                  a[q[i][1]-1] = q[i][2];
            }else{
                  cout << find( q[i][1], q[i][2]) << '\n';
            }
      }
}

