#include <bits/stdc++.h>

using namespace std;

/*******************DEBUG TEMPLATE*************************/
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
/*******************DEBUG TEMPLATE*************************/

/***************MACROS AND TYPEDEFS************************/
#define tr(container, itr) for (typeof(container.begin()) itr = container.begin(); itr != container.end(); itr++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector <vector <int>> vii;
typedef vector <vector <long long>> vll;
#define ALL(container) container.begin(), container.end()
#define NL cout << "\n";
#define pb push_back
#define mp make_pair
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ff first
#define ss second
/****************MACROS AND TYPEDEFS***********************/

const long long MOD = 1000000007;

/******************* EXTRA FUNCTIONS *********************/
ll inv(ll i) {if (i == 1) return 1; return (MOD - ((MOD / i) * inv(MOD % i)) % MOD) % MOD;}
 
ll MOD_mul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
 
ll MOD_add(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}

ll MOD_sub(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a - b) % MOD) + MOD) % MOD;}
 
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
 
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
 
ll pwr(ll a, ll b) {a %= MOD; ll res = 1; while (b > 0) {if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1;} return res;}
/******************* EXTRA FUNCTIONS *********************/


/*********************MAIN PROGRAM*************************/
bool dfs(int node, int X, vii &adj, vi &a, vector <bool> &vis, vi &xorStore, int &edgesBroken)
{
    vis[node] = true;
    xorStore[node] = a[node];
    for(auto &child : adj[node])
    {
        if(!vis[child])
        {
            if(dfs(child, X, adj, a, vis, xorStore, edgesBroken))return true;
            int xorChildTree = xorStore[child];
            if(xorChildTree == X)edgesBroken++;
            else xorStore[node] ^= xorChildTree;
            if(edgesBroken == 2)return true;
        }
    }
    return false;
}

int main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("../../../../input.txt", "r", stdin);
        freopen("../../../../output.txt", "w", stdout);
    #endif

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        int n, k; 
        cin>>n>>k;
        int X = 0;
        vi a(n + 1);
        for(int i = 1; i <= n; i++)cin>>a[i], X ^= a[i];
        vii adj(n + 1);
        for(int i = 0; i < n - 1; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(X == 0)cout<<"YES\n";
        else 
        {
            if(k == 2)cout<<"NO\n";
            else 
            {
                vi xorStore(n + 1, 0);
                int edgesBroken = 0;
                vector <bool> vis(n + 1, false);
                bool ok = dfs(1, X, adj, a, vis, xorStore, edgesBroken);
                if(ok)cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
    }
    return 0;
}

/*********************MAIN PROGRAM*************************/

