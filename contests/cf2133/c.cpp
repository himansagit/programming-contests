#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)


int ask( vector<int> &a){
      cout << "? " << a[0] << " " << a.size() << " ";
      for(int x:a) cout <<x << " ";
      cout << endl;
      int l;
      cin >> l;
      return l;
}

void solve(){
      int n;
      cin >> n;
      vector<pair<int,int>> v(n);
      rep(i,n){
            cout << "? " << i+1 << " " << n << " ";
            rep(i,n) cout << i+1 << " ";
            cout << endl;
            int l;
            cin >> l;
            v[i] = {l,i};
      }
      sort( v.rbegin(), v.rend());
      vector<int> ans;
      ans.push_back( v[0].second+1);
      for( int i = 1; i < n ; i++){
            ans.push_back( v[i].second+1);
            int l = ask(ans);
            if( l < ans.size()){
                  ans.pop_back();
            }
            assert( l == ans.size());
      }
      cout << "! " << ans.size() << " ";
      for(int x:ans) cout << x << " ";
      cout << endl;
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

