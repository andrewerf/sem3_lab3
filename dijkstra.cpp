#include <bits/stdc++.h>
 
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
 
 
const ui INF = 2009000999;
 
int main()
{
    ui n,m,s;
    cin >> n >> m >> s;
 
    vector<vector<pair<ui,ui>>> G(n);
 
    for (ui i = 0; i < m; ++i) {
        ui u,v,t;
        cin >> u >> v >> t;
 
        G[u].push_back({v,t});
        G[v].push_back({u,t});
    }
 
 
    auto cmp = [](pair<ui,ui> &a, pair<ui,ui> &b){
        return a.second > b.second;
    };
 
    std::priority_queue<pair<ui,ui>,vector<pair<ui,ui>>,function<bool(pair<ui,ui>&,pair<ui,ui>&)>> q(cmp);
    vector<ui> d(n, INF);
    vector<bool> used(n,false);
 
    d[s] = 0;
    q.push({s,0});
 
    for(ui i = 0; i < n; ++i)
        if(i != s)
            q.push({i,INF});
 
    while(q.size() != 0){
        auto p = q.top();
        q.pop();
        if(used[p.first])
            continue;
 
        used[p.first] = true;
 
        ui v = p.first;
        for(auto pu : G[v]){
            ui u = pu.first;
            ui len = pu.second;
 
            if(d[u] > d[v]+len){
                d[u] = d[v]+len;
                q.push({u,d[u]});
            }
        }
    }
 
 
 
    for(ui k : d)
        cout << k << ' ';
 
 
 
 
 
 
 
    return 0;
}
