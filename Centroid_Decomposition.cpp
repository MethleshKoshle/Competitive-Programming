const int mod=1e9+7, N=100001;

int sub[N], parentCentroid[N], nodes=0;
set<int> adj[N];
vi cdt[N];

// Centroid Decomposition - Divide and Conquer on Trees
// credits: https://github.com/Ashishgup1/Competitive-Coding/blob/master/Centroid%20Decomposition.cpp
void dfs(int u, int parent){
    nodes++;
    sub[u]=1;
    for(int v:adj[u]){
        if(v==parent)
            continue;
        dfs(v, u);
        sub[u]+=sub[v];
    }
}

int centroid(int u, int parent){
    for(int v:adj[u]){
        if(v==parent)
            continue;
        if(sub[v]>(nodes>>1))
            return centroid(v, u);
    }
    return u;
}
void decompose(int u, int par){
    nodes = 0;
    dfs(u, u);
    int node = centroid(u, u);
    parentCentroid[node] = par;
    if(par!=-1){
        cdt[par].pb(node);
        cdt[node].pb(par);
    }
    for(int v:adj[node]){
        adj[v].erase(node);
        decompose(v, node);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, u, v;
    cin>>n;
    rep(i, n-1){
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    decompose(1, -1);
    repA(i, 1, n+1)pp(i, parentCentroid[i]);
    return 0;
}

/*
https://www.quora.com/q/threadsiiithyderabad/Centroid-Decomposition-of-a-Tree
15
1 2
3 2
4 2
5 2
6 5
8 5
7 6
9 8
9 10
9 13
13 14
13 15
10 11
10 12
*/
