struct Bipartite_Matching { // 0-base
  int l, r;
  vector<int> mp, mq, dis, cur;
  vector<vector<int>> G;
  bool dfs(int u) {
    for (int &i = cur[u]; i < SZ(G[u]); ++i) {
      int e = G[u][i];
      if (!~mq[e] or (dis[mq[e]] == dis[u] + 1 and dfs(mq[e])))
        return mp[mq[e] = u] = e, 1;
    }
    dis[u] = -1;
    return 0;
  }
  bool bfs() {
    int rt = 0;
    queue<int> q;
    fill(ALL(dis), -1);
    for (int i = 0; i < l; ++i)
      if (!~mp[i]) dis[i] = 0, q.push(i);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int e : G[u])
        if (!~mq[e])  rt = 1;
        else if (!~dis[mq[e]]) dis[mq[e]] = dis[u] + 1, q.push(mq[e]);
    }
    return rt;
  }
  int matching() {
    fill(ALL(mp), -1), fill(ALL(mq), -1);
    int rt = 0;
    while (bfs()) {
      fill(ALL(cur), 0);
      for (int i = 0; i < l; ++i)
        if (!~mp[i] and dfs(i)) ++rt;
    }
    return rt;
  }
  void add_edge(int s, int t) {
    G[s].eb(t);
  }
  void init(int _l, int _r) {
    l = _l, r = _r;
    mp.resize(l), mq.resize(r);
    dis.resize(l), cur.resize(l);
    G.assign(l, vector<int>());
  }
};
