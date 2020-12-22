#include <bits/stdc++.h>
 
using namespace std;
typedef unsigned int ui;
 
 
 
 
 
int main()
{
    ui n,m;
    cin >> n >> m;
 
    vector<vector<ui>> G(n),rG(n);
    for(ui i = 0; i < m; ++i){
        ui u,v;
        cin >> u >> v;
 
        --u;
        --v;
 
        G[u].push_back(v);
        rG[v].push_back(u);
    }
 
    vector<bool> used(n,false);
 
    vector<ui> t;
    function<void(ui)> dfs1 = [&](ui i){
        used[i] = true;
        for(ui v : G[i]){
            if(!used[v])
                dfs1(v);
        }
        t.push_back(i);
    };
 
 
    for(ui v = 0; v < n; ++v){
        if(!used[v])
            dfs1(v);
    }
 
    vector<ui> ccomponent;
    vector<vector<ui>> components;
    function<void(ui)> dfs2 = [&](ui i){
        used[i] = true;
        ccomponent.push_back(i);
        for(ui v : rG[i])
            if(!used[v])
                dfs2(v);
    };
 
 
    used.assign(n,false);
    for(ui i = t.size(); i >= 1; --i){
        ui s = t[i-1];
        if(used[s]) continue;
 
        ccomponent.clear();
        dfs2(s);
        components.push_back(move(ccomponent));
    }
 
 
    vector<ui> ans(n);
    for(ui i = 0; i < components.size(); ++i){
        auto &cmp = components[i];
        for(ui v : cmp)
            ans[v] = i;
    }
 
 
    cout << components.size() << '\n';
    for(ui c : ans)
        cout << c+1 << ' ';
 
 
 
 
    return 0;
}
