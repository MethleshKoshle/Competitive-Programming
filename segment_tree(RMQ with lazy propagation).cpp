#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i<n; i++)
#define hell 1e9
#define int long long

using namespace std;

typedef vector<int> vi;
typedef long long ll;

const int N=1e6+1;
struct seg_tree{
    vi arr, seg, lazy;
    int n, msize;
    seg_tree(vi &a){
        n=a.size();
        arr=a;
        seg.assign(5*n +1, 0);
        lazy.assign(5*n +1, 0);
        msize=5*n;
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
        if(lazy[id]){
            seg[id]+=lazy[id];
            lazy[2*id]+=lazy[id];
            lazy[2*id +1]+=lazy[id];
            lazy[id]=0;
        }
        if(l0<=l and r0>=r){ // complete overlap
          return seg[id];
        }
        else if((l<=l0 and l0<=r) or (l<=r0 and r0<=r)){ // partial overlap
            return min(get_min(l, (l+r)/2, l0, r0, 2*id), get_min((l+r)/2 +1, r, l0, r0, 2*id +1));
        }
        else{ // no overlap
          return hell;
        }
    }
    ll query(int l, int r){
        return get_min(0, n-1, l, r, 1);
    }
    ll update_lazy(int l, int r, int l0, int r0, int id, int val){
      if(lazy[id]){
        seg[id]+=lazy[id];
        lazy[2*id]+=lazy[id];
        lazy[2*id +1]+=lazy[id];
        lazy[id]=0;
      }
      if(l0<=l and r0>=r){ // complete overlap
        if(not lazy[id]){
          if(2*id<=msize)
            lazy[2*id]+=val;
          if(2*id +1<=msize)
            lazy[2*id +1]+=val;
          seg[id]+=val;
          return seg[id];
        }
        if(2*id<=msize)
          lazy[2*id]=lazy[id];
        if(2*id +1<=msize)
          lazy[2*id +1]=lazy[id];
        seg[id]+=lazy[id];
        seg[id]+=val;
        lazy[id]=0;
        return seg[id];
      }
      else if((l<=l0 and l0<=r) or (l<=r0 and r0<=r)){ // partial overlap
        seg[id]=min(update_lazy(l, (l+r)/2, l0, r0, 2*id, val), update_lazy((l+r)/2 +1, r, l0, r0, 2*id +1, val));
        return seg[id];
      }
      else{ // no overlap
        if(lazy[id]){
          if(2*id<=msize)
            lazy[2*id]=lazy[id];
          if(2*id +1<=msize)
            lazy[2*id +1]=lazy[id];
          seg[id]+=lazy[id];
          lazy[id]=0;
        }
        return seg[id];
      }
    }
    void update(int l, int r, int val){
      update_lazy(0, n-1, l, r, 1, val);
    }
};
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, q, l, r, x;
  cin>>n;
  vi a(n);
  rep(i, n)
    cin>>a[i];
  seg_tree seg(a);
  cin>>q;
  while(q--)
  {
    cin>>m>>l>>r;
    if(m==0){
      cin>>x;
      seg.update(l, r, x);
      continue;
    }
    cout<<seg.query(l, r)<<"\n";
  }
  return 0;
}
