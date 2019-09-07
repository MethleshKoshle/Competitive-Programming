//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<sstream>
//some common functionn
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define FORs(i,a,b)             for(int i=a;i>=b;i--)
#define fill(a,v)               memset(a,v,sizeof a)
#define abS(x)                  ((x)<0?-(x):(x))
#define mP                      make_pair
#define pB                      push_back
#define error(x)                cout << #x << " : " << (x) << endl
#define all(c)                  (c).begin(),(c).end()
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)

#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Output macros
#define p(n)                        printf("%d",n)
#define pc(n)                       printf("%c",n)
#define pf(n)                       printf("%lf",n)
#define ps(n)                       printf("%s",n)

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;

using namespace std;

////////////////////set 2
#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(false)
#define fout cin.tie(NULL);cout.tie(NULL)
#define phb(elm) push_back(elm)
#define ppb(elm) pop_back(elm)
#define sclock() time(NULL)
#define eclock() time(NULL)
#define ivec(x) vector<int>x
#define svec(x) vector<string>x
#define pvec(x) vector<pair<int, int>>x
#define iset(x) set<int>x
#define sset(x) set<string>x
#define mkp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
#define sum(range, init) accumulate(range, init)
#define vsort(vec) sort(all(vec))
#define lb(v, e) lower_bound(all(v), e)
#define ub(v, e) upper_bound(all(v), e)
#define slb(s, e) s.lower_bound(e)
#define sub(s, e) s.upper_bound(e)
#define fill(ctr, x) memset(ctr,val,sizeof(ctr))
#define loop(i, a, b) for(int i=a;i<b;i++)
#define wf(i, a, b, step) for(int i=a;i<b;i+=step)
#define wb(i, a, b, step) for(int i=a;i>=b;i-=step)
#define iter(i, ctr) for(auto i:ctr)
#define getv(v, n) loop(i, 0, n)cin>>v[i]
#define print(x) cout<<x<<"\n"
#define printp(x, y) cout<<x<<" "<<y<<"\n"
#define pprecise(d, n) cout<<setprecision(n+1)<<d<<"\n";
#define flush cout<<flush
#define lbr cout<<"\n"
#define debug print("wtf")
#define ull unsigned long long
#define mod int(1e9+7);
#define inf ull(1e18);
#define tlimit 1
using namespace std;

#include <ext/rope> ////set 3
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp>
#define p(x) cout<<x<<"\n"
#define rep(i, n) for(int i=0; i<n; i++)
#define repA(i, a, n) for(int i=a; i<n; i++)
#define repD(i, a, n) for(int i=a; i>=n; i--)
#define trav(it, ctr) for(auto it=ctr.begin(); it!=ctr.end(); it++)
#define travD(it, ctr) for(auto it=ctr.rbegin(); it!=ctr.rend(); it++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define N 200001
#define tle 1001

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds; 

typedef priority_queue<int> pq;
typedef map<int, int> mii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;
typedef long long int ll;

int mod=1e9+7;
