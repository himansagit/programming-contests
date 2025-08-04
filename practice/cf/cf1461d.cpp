#include<bits/stdc++.h>

using namespace std;


using i64 = long long;
#define rep(i,b) for( int i = 0; i < (b); ++i)

void solve(){
      int n,q;
      cin >> n >> q;
       vector<i64> a(n+1),pre(n+1);
       rep(i,n) cin >> a[i+1];
       sort( a.begin(), a.end());
       rep(i,n) pre[i+1] += pre[i]+a[i+1];
       set<i64> s;
       auto dfs = [&](auto self,int l,int r)->void{
             if( r < l)
                   return;
            s.insert(pre[r] - pre[l-1]);     
            i64 m = (a[l] + a[r])/2;
            int itr = upper_bound(a.begin()+l, a.begin()+r+1,m) - a.begin();
            if( itr == r+1)
                  return;
            self(self,l,itr-1);
            self(self,itr,r);
       };
      dfs(dfs,1,n);
       while(q--){
             i64 x;
             cin >> x;
             if( s.find(x) == s.end()){
                   cout << "No\n";
             }else{
                   cout << "Yes\n";
             }
       }
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
      //TIME
}

