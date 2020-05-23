struct seg_tree{
    vi arr, seg_min, seg_max, lazy;
    int n, msize;
    seg_tree(vi &a){
        n=a.size();
        arr=a;
        seg_min.assign(5*n +1, 0);
        seg_max.assign(5*n +1, 0);
        msize=5*n;
        fill_min(0, n-1, 1);
        fill_max(0, n-1, 1);
    }
    int fill_min(int l, int r, int id){
        if(l==r){
            seg_min[id]=arr[l];
            return seg_min[id];
        }
        seg_min[id]=min(fill_min(l, (l+r)/2, 2*id), fill_min(((l+r)/2) +1, r, 2*id +1));
        return seg_min[id];
    }
    int fill_max(int l, int r, int id){
        if(l==r){
            seg_max[id]=arr[l];
            return seg_max[id];
        }
        seg_max[id]=max(fill_max(l, (l+r)/2, 2*id), fill_max(((l+r)/2) +1, r, 2*id +1));
        return seg_max[id];
    }
    ll get_min(int l, int r, int l0, int r0, int id){
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
    ll get_max(int l, int r, int l0, int r0, int id){
        if(l0<=l and r0>=r){ // complete overlap
          return seg[id];
        }
        else if((l<=l0 and l0<=r) or (l<=r0 and r0<=r)){ // partial overlap
            return max(get_max(l, (l+r)/2, l0, r0, 2*id), get_max((l+r)/2 +1, r, l0, r0, 2*id +1));
        }
        else{ // no overlap
          return -hell;
        }
    }
    ll query_min(int l, int r){
        return get_min(0, n-1, l, r, 1);
    }
    ll query_max(int l, int r){
        return get_max(0, n-1, l, r, 1);
    }
};
