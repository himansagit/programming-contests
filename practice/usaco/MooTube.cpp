#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

struct DSU{
     vector<int> a;
     void init(int n) { a = vector<int>(n,-1); }
     int get(int x){
           if( a[x] < 0) return x;
           else return a[x] = get(a[x]);
     }
     bool same(int x, int y) {return get(x) == get(y);}
     int size(int x){ return -a[get(x)]; };
     int join(int x, int y){
           x = get(x), y = get(y); if( x == y) return 0;
           if( a[x] > a[y]) swap(x,y);
           a[x] += a[y]; a[y] = x; return 1;
     }
};

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
#ifndef LOCAL
      freopen("mootube.in","r",stdin);
      freopen("mootube.out","w",stdout);
#endif
      
      int n,q; cin >> n >> q;
      vector<pair<int,pair<int,int>>> E(n-1);
      rep(i,n-1){
            cin >> E[i].second.first >> E[i].second.second >> E[i].first;
      }
      sort(E.rbegin(), E.rend());
      vector<pair<int,pair<int,int>>> Q(q);
      rep(i,q){
            cin >> Q[i].first >> Q[i].second.first;
            Q[i].second.second = i;
      }
      sort(Q.rbegin(), Q.rend());
      DSU a; a.init(n+1);
      int j = 0;
      vector<int> ans(q);
      rep(i,q){
            int &k = Q[i].first;
            while( j < n-1 and E[j].first >= k){
                  a.join(E[j].second.first, E[j].second.second);
                  j++;
            }
           ans[Q[i].second.second] = a.size( Q[i].second.first);
      }
      rep(i,q) cout << ans[i]-1 << '\n';
}

