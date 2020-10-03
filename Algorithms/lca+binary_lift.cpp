// Code by : Nikhil Chopra
// Lowest Comman Ancestor using binary lifting
// k = ceil(log2(n));
// where n are number of nodes

const int N = 1e5+9;
vector<int> v[N];
int level[N] = {0};
int k;
int dp[N][21] ;

void dfs(int cur,int par){
    dp[cur][0] = par;
    for(int i=1;i<=k;i++){
        dp[cur][i] = dp[dp[cur][i-1]][i-1]; 
    }
    for(auto i:v[cur]){
        if(i != par){
            // cerr<<i<<"\n";
            level[i] = level[cur] + 1;
            dfs(i,cur);
        }
    }
    
}

int lca(int u,int v){
    if(level[u] < level[v]) swap(u,v);
    for(int i=k;i>=0;i--){
        if((level[u] - pow(2,i)) >= level[v]) u = dp[u][i];
    }
    if(u == v) return v;
    for(int i=k;i>=0;i--){
        if(dp[u][i] != dp[v][i]){
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}
