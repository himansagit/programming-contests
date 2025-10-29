#include<bits/stdc++.h>

using namespace std;
#define rep(i,b) for( int i = 0; i < (b); ++i)
#define int long long

void solve(){
      int n,k,l,r; cin >> n >> k >> l >> r;
      vector<int> a(n);
      rep(i,n) cin >> a[i];
      int left = 0, mid = 0, right = 0;
      map<int,int> cnt1,cnt2;
      int dist1 = 0,dist2 = 0;
      int ans = 0;
      while( right < n){
            cnt1[a[right]]++;
            cnt2[a[right]]++;
            if( cnt1[a[right]] == 1) dist1++;
            if( cnt2[a[right]] == 1) dist2++;
            while(right-left+1 > r or dist1 > k){
                  cnt1[a[left]]--;
                  if( cnt1[a[left]] == 0) dist1--;
                  left++;
            }
            while( right-mid+1 >= l and dist2 >= k){
                  cnt2[a[mid]]--;
                  if( cnt2[a[mid]] == 0) dist2--;
                  mid++;
            }
            if(right-left+1 <= r and right-left+1 >= l and dist1 == k){
                  ans += mid-left;
            }
            right++;
      }
      cout << ans << '\n';
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tc; cin >> tc;
      while(tc--) solve();
}

