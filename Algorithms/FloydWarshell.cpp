ll n,m,u,v;
vector<pair<ll,ll>> adj[1005];
ll dist[1005][1005];

void fill(){
    for(ll i=1;i<=n;i++) {
        vis[i]=0; 
    }
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            dist[i][j] = infinite;
}
void FloydWarshell(){
    
    for(ll k = 1; k <= n; k++){
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= n; j++){
                dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
            }
        }
    }
}
void solve(){
    ll i,j,x,y,cost;
    cin >> n >> m;
    fill();
    for(i=0;i<m;i++){
        cin >> x >> y >> cost;
        adj[x].pb(make_pair(y,cost)); //adj[y].pb(make_pair(x,cost));
        dist[x][y] = cost;
    }
    cin >> u >> v;
    FloydWarshell();
    if(dist[u][v] != infinite)
        cout << dist[u][v] << ln;
    else cout << "-1\n";
}


int main()
{
    fastio  
    //ll t,i=0; cin >> t; while(t--) 
        solve();
    return 0;
}
