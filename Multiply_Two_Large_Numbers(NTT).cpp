#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define rep(i, n) for(int i=0; i<n; i++)
#define repA(i, a, n) for(int i=a; i<n; i++)
#define repD(i, a, n) for(int i=a; i>=n; i--)
#define trav(it, ctr) for(auto it=ctr.begin(); it!=ctr.end(); it++)
#define p(x) cout<<x<<"\n"
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pp(x, y) cout<<x<<" "<<y<<"\n"
#define btc __builtin_popcount
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define int int64_t

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

typedef priority_queue<int> pq;
typedef pair<int, int> ii;
typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;

int N=100001, M=1e9+7;
int n, mm, prime;
const int MAXN =1e7 + 10;

int mod_add(int a, int b)
{
    int sum = a + b;
    return sum >= M ? sum - M : sum;
}

int mod_sub(int a, int b)
{
    int diff = a - b;
    return diff < 0 ? diff + M : diff;
}

int mod_mul(int a, int b)
{
    return ((long long)a*b)%M;
}

int mod_pow(int a, int p)
{
    int result = 1;

    while (p > 0)
    {
        if (p & 1) result = mod_mul(result, a);
        a = mod_mul(a, a);
        p >>= 1;
    }

    return result;
}

vector<pair<int,int>> reverse_it[21];

void prepare_reorder()
{
    for(int gl=1,n=2;gl<=20;gl++,n<<=1)
    {
      vector<int> bit_reverse;

      bit_reverse.assign(n, 0);

      for (int i = 0; i < n; i++)
      {
      bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (gl - 1));
      if(i < bit_reverse[i]) reverse_it[gl].push_back({i,bit_reverse[i]});
      }

    }
}

vector<int> roots = {0, 1};
int max_size = 8388608;
int root = 31;

void prepare_roots()
{
   roots.resize((1<<20));

   for(int length=1;length<20;length++)
   {
    int z = mod_pow(root, max_size >> (length + 1));

    for (int i = 1 << (length - 1); i < 1 << length; i++)
    {
        roots[2 * i] = roots[i];
        roots[2 * i + 1] = mod_mul(roots[i], z);
    }

   }

}


int round_up_power_two(int n)
{
    while (n & (n - 1))
        n = (n | (n - 1)) + 1;

    return n;
}

// Given n (a power of two), finds k such that n == 1 << k.
int get_length(int n)
{
    return __builtin_ctz(n);
}

namespace NTT
{

    void fft_iterative(int N, vector<int> &values) {

        for(auto x : reverse_it[get_length(N)])
            swap(values[x.first],values[x.second]);

        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    int even = values[start + i];
                    int odd = mod_mul(values[start + n + i], roots[n + i]);
                    values[start + n + i] = mod_sub(even, odd);
                    values[start + i] = mod_add(even, odd);
                }
    }

    const int FFT_CUTOFF = 170;

    vector<int> mod_multiply(vector<int> left, vector<int> right)
    {
        int n = left.size();
        int m = right.size();

        // Brute force when either n or m is small enough.
        if (min(n, m) < FFT_CUTOFF) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) M*M;
            vector<uint64_t> result(n + m - 1);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) left[i] * right[j];

                    if (result[i + j] > ULL_BOUND)
                        result[i + j] %= M;
                }

            for (int i = 0; i < (int) result.size(); i++)
                if (result[i] >= (uint64_t) M)
                    result[i] %= M;

            return vector<int>(result.begin(), result.end());
        }

        int N = round_up_power_two(n + m - 1);
        left.resize(N);
        right.resize(N);

        fft_iterative(N, left);
        fft_iterative(N, right);

        int inv_N = mod_pow(N,M-2);

        for (int i = 0; i < N; i++)
            left[i] = mod_mul(mod_mul(left[i], right[i]), inv_N);

        reverse(left.begin() + 1, left.end());
        fft_iterative(N, left);
        left.resize(n + m - 1);

        return left;
    }
};
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, d;
  cin>>t;
  while(t--){
    cin>>n>>d;
    vector<int> a(n), c;
    for(int i = 0 ; i < n; i++){
      a[i]=d;
    }
    c=NTT::mod_multiply(a, a);
    // multiply(a,b);
    n=c.size();
    int num=0, tmp=1;
    for(int i = 0 ; i < n; i++){
      num+=tmp*c[i];
      tmp*=10;
      // cout<<c[i]<<" ";
    }
    p(num);
  }
  return 0;
}
