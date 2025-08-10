#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int x,n; cin >> x >> n;
      vector<int> p(n);
      rep(i,n) cin >> p[i];

      set<int> s;
      priority_queue<pair<int,int>> q;
      q.push( {x,0} );
      int l,r,w;
      rep(i,n){
            s.insert(p[i]);
            while(true){
                  pair<int,int> t = q.top();
                  w = t.first;
                  l = t.second;
                  r = l + w;
                  auto itr = s.lower_bound(l);
                  if( itr != s.end() and *itr <= r){
                        q.pop();
                        int m = *itr;
                        assert( m != l and m != r);
                        q.push({ m-l, l});
                        q.push( { r-m , m} );
                        s.erase(itr);
                  }else{
                        break;
                  }
            }
            cout << q.top().first <<  " ";
      }
}

