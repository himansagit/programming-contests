#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n,m; cin >> n >> m;
      vector<int> a(n), b(m), c(m);
      for( int &a:a) cin >> a;
      for( int &b:b) cin >> b;
      for( int &c:c) cin >> c;
      vector<int> y,z;
      vector<pair<int,int>> x;
      for( int i = 0; i <m ;i++){
            if( c[i] == 0){
                  z.push_back(b[i]);
            }else if( c[i]  <= b[i]){
                  y.push_back(b[i]);
            }else{
                  x.push_back({b[i],c[i]});
            }
      }
      sort( a.begin(), a.end());
      sort( z.begin(), z.end());
      sort( y.begin(), y.end());
      sort( x.begin(), x.end());
      int  mm = a[n-1];
      int i = 0, j = 0, k = 0;
      int cnt = 0;
      for( int j = 0; j < z.size(); j++){
            while( i < n and a[i] < z[j]){
                  if( k < x.size() and x[k].first <= a[i]){
                        a[i] = x[k].second;
                        k++;
                  }else{
                        //break;
                        i++;
                  }
            }
            if( i < n and a[i] >= z[j]){
                  cnt++;
                  i++;
            }else if( i < n and a[i] < z[j]){
                  i++;
            }else{
                  break;
            }
      }
      i = 0;
      for(i = 0; i < x.size(); i++){
            if( mm >= x[i].first){
                  mm = max( mm, x[i].second);
            }else{
                  break;
            }
      }
      cnt += i;
      cnt += upper_bound(y.begin(), y.end(), mm) - y.begin();

      cout << cnt << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

