#include <bits/stdc++.h>
using namespace std;
#define fastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll              long long
#define double          long double
#define rep(i,a)        for(ll i = 0 ; i < a ; i++)
#define repe(i,a,b)     for(ll i = a ; i < b ; i++)
#define bac(i,a)        for(ll i = a ; i >= 0 ; i--)
#define bace(i,a,b)     for(ll i = a ; i >= b ; i--)
#define pb              push_back
#define mp              make_pair
#define in              insert
#define ff              first
#define ss              second
#define vv              vector
#define vll             vector <ll>
#define pll             pair <ll,ll>
#define vpll            vector <pll>
#define umap            unordered_map
#define uset            unordered_set
#define mset            multiset
#define pqueue          priority_queue
#define stk             stack<ll>
#define que             queue<ll>
#define setbit(x)       __builtin_popcountll(x)
#define init(c,a)       memset(c,a,sizeof(c))
#define all(c)          c.begin(),c.end()
#define lb              lower_bound
#define ub              upper_bound
#define maxe            *max_element
#define mine            *min_element
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)        a/__gcd(a,b)*b
#define Y               "YES"
#define N               "NO"
#define endl            "\n"
#define debug(x)        cout << #x << " : " << x << nl;
const ll mod = 1000000007;
const ll MOD = 998244353;
const ll inf = 1e18;
const ll MAX = 2e5 + 1;

inline ll add(ll a,ll b) {return ((a%mod)+(b%mod))%mod;}
inline ll sub(ll a,ll b) {return ((a%mod)-(b%mod)+mod)%mod;}
inline ll mul(ll a,ll b) {return ((a%mod)*(b%mod))%mod;}

ll pwr(ll x,ll n){
	x=x%mod;
    if(!n) return 1;
    if(n&1) return mul(x, pwr(mul(x,x),(n-1)/2));
    else return pwr(mul(x,x),n/2);
}
// O(nlogn) for [1,n]
ll modinv(ll n){  
    return pwr(n,mod - 2); 
}
// O(logn) for[1,n]
ll inv(ll i){
    if(i==1) return 1;
    return (mod-(mod/i)*inv(mod%i)%mod)%mod;
}
// =============================
bool f(int a,int b)
{
	return a>b;
}
struct cmp{
	bool operator()(const int &k1, const int &k2){
        return k1>k2;
    }
};
// ==============================
// ==============================
// ======Useful Code Begins====== 

int body[1001][1001];
int n,p;
int r = INT_MAX, c = INT_MAX;

int dfs(int i, int j)
{
	if(i >= n or j >= n or i < 0 or j < 0 or body[i][j] == 0) return 0;
	
	body[i][j] = 0;
	
	if(r > i){
		r = i;
		c = j;
	}
	else if(r == i)
	{
		if(c > j){
			r = i;
			c = j;
		}
	}
	
	int cnt = 1;
	
	cnt += dfs(i+1, j);
	cnt += dfs(i-1, j);
	cnt += dfs(i, j+1);
	cnt += dfs(i, j-1);
	
	return cnt;
}

int main()
{
	fastIO;
	int tt = 1;
	cin>>tt;
	
	// Return the cell(min row and min column) for asked element if it belongs to an island with that much elements
	while(tt--)
	{
		cin>>n;
		
		rep(i,n) rep(j,n) cin>>body[i][j];
		
		cin>>p;
		 
		int flag = 0;
		pair<int,int> count[1001];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(body[i][j] == 1)
				{
					r = i;
					c = j;
					int val = dfs(i,j);
			
					count[val] = {r, c};
					
					if(val == p) {
						flag = 1;
						break;
					} 
				}
			}
			
			if(flag) break;
		}
		
		if(flag) cout<<count[p].first<<" "<<count[p].second<<endl;
		else cout<<"-1 -1\n";
		
	}
	
	return 0;
}
