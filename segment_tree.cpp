// Solution to spoj problem: https://www.spoj.com/problems/RMQSQ
#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i<n; i++)
#define hell 1e10

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

const int N=1e6+1;
struct seg_tree{
    vi arr, seg;
    int n;
    seg_tree(vi &a){
        n=a.size();
        arr=a;
        seg.assign(5*n +1, 0);
        fill(0, n-1, 1);
    }
    int fill(int l, int r, int id){
        if(l==r){
            seg[id]=arr[l];
            return seg[id];
        }
        seg[id]=min(fill(l, (l+r)/2, 2*id), fill(((l+r)/2) +1, r, 2*id +1));
        return seg[id];
    }
    ll get_min(int l, int r, int l0, int r0, int id){
        if(l0<=l and r0>=r) // complete overlap
            return seg[id];
        else if((l<=l0 and l0<=r) or (l<=r0 and r0<=r)) // partial overlap
            return min(get_min(l, (l+r)/2, l0, r0, 2*id), get_min((l+r)/2 +1, r, l0, r0, 2*id +1));
        else // no overlap
            return hell;
    }
    ll query(int l, int r){
        return get_min(0, n-1, l, r, 1);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, l, r;
    cin>>n;
    vi a(n);
    rep(i, n)
        cin>>a[i];
    seg_tree seg(a);
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<seg.query(l, r)<<"\n";
    }
    return 0;
}
