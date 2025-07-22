#include<bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define debug(...) 42
#endif

using i64 = long long;
#define all(x) (x).begin(),(x).end()
#define sz(x)	(int)(x).size() 
#define pb push_back
#define rep(i, a, b) for( int i = a; i < (b); ++i)

//RNG

const i64 MOD = 998244353;
i64 POW(i64 a,i64 b){
	// i64 a = MOD;
	i64 c = 1;
	while(b > 1){
		if(b%2 == 0){
			a = (a * a) %MOD;
			b /= 2;
		}
		else{
			c = (c*a)%MOD;
			b--;
		}
	}
	return (a*c)%MOD;
}
i64 inv(i64 a){
	return POW(a,MOD-2);
}
using P = array<i64,4>;
bool comp(P a, P b){
	if(a[0] == b[0])
		return a[1] < b[1];
	else
		return a[0] < b[0];
}
void solve(){
	i64 n,m;
	cin >> n >> m;
	vector<P> a(n);
	i64 neg = 1;
	rep(i,0,n){
		cin >> a[i][0] >> a[i][1];
		i64 p,q;
		cin >> p >> q;
		// a[i][2] = (p*inv(q))%MOD;
		a[i][2] = p;
		a[i][3] = q;
		neg = (neg*(q-p))%MOD;
            neg = (neg*inv(q))%MOD;
	}
	sort(all(a),comp);
	debug(a);
	vector<i64>  dp(m+1);
	dp[0] = neg;
	rep(i,0,n){
		i64 l = a[i][0];
		i64 r = a[i][1];
		i64 p = a[i][2];
		i64 q = a[i][3];
		// dp[r] = (dp[r] + dp[l-1]*a[i][2])%MOD;
		i64 nv = inv( ((q-p)*inv(q))%MOD);
		i64 d = (dp[l-1]*nv)%MOD;
		d = (d*p)%MOD;
		d = (d*inv(q))%MOD;
		dp[r] = (dp[r] + d)%MOD;
		debug(dp);

	}
	cout<<dp[m]<<"\n";
}

int32_t main()
{ 
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      solve();
      //TIME
}

