#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
const int N = 2e6+1;
int tree[N];
int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      int n; cin >> n;
      vector<int> a(n);
      for( int &x:a) cin >>x;
      memset(tree,0,sizeof(tree));
      auto add = [&]( int i)->void{
            while( i <= n){
                  tree[i]++;
                  i = (i | (i+1));
            }
      };
      auto sum = [&](int i)->i64{
            i64 res = 0;
            while( i >= 0){
                  res += tree[i];
                  i = (i&(i+1)) -1;
            }
            return res;
      };
      i64 c = 0;
      for( int i = 0; i < n; i++){
            c += sum(n) - sum(a[i]);
            add(a[i]);
      }
      if( c%2 == n%2) cout << "Petr\n";
      else cout << "Um_nik\n";
}

