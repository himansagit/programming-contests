#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define all(x) (x).begin(),(x).end()
#define rep(i, a, b) for( int i = a; i < (b); ++i)

//RNG

void solve(int){
      int n,l,r,s;
      cin >> n >> l >> r >> s;
      int sum = 0;
      int w = r-l+1;
      int i = 0;
      set<int> a;
      for(; i < w; i++){
            sum += i;
            a.insert(i);
      }
      if( sum + w > s){
             cout << "-1\n";
             return;
      }
      assert(i == w);
      for(; i <= n; i++){
            a.insert(i);
            a.erase(a.find(i-w));
            sum += w;
            if( sum >= s)
                  break;
      }
      if(sum < s){
            cout << "-1\n";
            return;
      }
      assert(sum - s <= w);
      assert( (*a.begin()) == i-w+1);
      if(sum > s){
            a.erase(a.find(i-w+sum -s));
            a.insert(i-w);
      }
      assert(a.size() == w);
      set<int> b;
      for(int j = 1; j <= n; j++){
            if( a.find(j) == a.end()) b.insert(j);
      }
      assert( a.size() + b.size() == n);
      for(int j = 1; j <= n; j++){
            if( j < l or j > r){
                  cout << *b.begin() << " ";
                  b.erase(b.begin());
            }else{
                  cout << *a.begin() << " ";
                  a.erase(a.begin());
            }
      }
      cout << "\n";
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

