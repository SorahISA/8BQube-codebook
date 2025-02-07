// all coord. is even, you may want to call halfPlaneInter after then
vector<vector<Line>> vec;
void build_voronoi_line(int n, pii *arr) {
  tool.init(n, arr); // Delaunay
  vec.clear(), vec.resize(n);
  for (int i = 0; i < n; ++i)
    for (auto e : tool.head[i]) {
      int u = tool.oidx[i], v = tool.oidx[e.id];
      pii m = (arr[v] + arr[u]) / 2LL, d = perp(arr[v] - arr[u]);
      vec[u].eb(Line(m, m + d));
    }
}