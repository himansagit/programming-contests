#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

bool comp(pair<int,int> a, pair<int,int> b){
      if( a.first == b.first)
            return a.second > b.second;
      else
            return a.first < b.first;
}
void solve(int){
      int n,m;
      cin >> n >> m;
      int z= n*m;
      vector< pair<int,int> > a(z),b(z);
      rep(i,z){
            int x;
            cin >> x;
            a[i] = {i+1,x};
            b[i] = {x,i+1};
      }
      sort( b.begin(), b.end() );
      map<int,int> ids;
      ids[b[0].first] = 1;
      int j = 1;
      vector<int> cnt(z+1);
      cnt[1]++;
      rep(i,z-1){
            if( b[i].first < b[i+1].first) j++;
            ids[b[i+1].first] = j;
            cnt[j]++;
      }
      vector<pair<int,int>> pos(z+1);
      j = 0;
      rep(i,z+1){
            int x = cnt[i];
            while(x--){
                  pos[i].push_back({ j/m,j%m});
                  j++;
            }
      }
      rep(i,z+1){
            sort(pos[i].begin(),pos[i].end(),comp);
      }
      int res = 0;

      for( pair<int,int> p: a){
            int i = ids[p.second];

      }

      
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc = 1;
      cin>>tc;
      for(int i = 1; i <= tc; i++){
            solve(i);
      }
      //TIME
}

