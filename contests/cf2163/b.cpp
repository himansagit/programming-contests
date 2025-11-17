#include<bits/stdc++.h>

using namespace std;

void solve(){
      int n; cin >> n;
      vector<int> a(n);
      for(int &e:a) cin >> e;
      int x = find(a.begin(), a.end(),1) - a.begin();
      int y = find(a.begin(), a.end(),n) - a.begin();
      string s; cin >> s;
      if( s[0] == '1' or s[n-1] == '1' or s[x] == '1' or s[y] == '1'){
            cout << "-1\n";
            return;
      }
      cout << 5 << '\n';
      x++;
      y++;
      cout << min(x,y) << " " << max(x,y) << '\n';
      cout << min(1,y) << " " << max(1,y) << '\n';
      cout << min(x,1) << " " << max(x,1) << '\n';
      cout << min(n,y) << " " << max(n,y) << '\n';
      cout << min(x,n) << " " << max(x,n) << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

