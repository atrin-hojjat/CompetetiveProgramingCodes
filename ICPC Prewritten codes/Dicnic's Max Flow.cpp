
const int MaxN = 1e5 + 6.66;

struct Edge {
  int s, e, w, rev_pos, base_w = 0;

  Edge(int s = -1, int e = -1, int w = 0) : s(s), e(e), w(w) { base_w = w; };
};

class Graph {
  public:
    Graph(int n = MaxN, int m = MaxN) : n(n), m(m) {
      upd = true;
      starts = new int[n + 1];
      levels = new int[n + 1];
      eds = new vector<Edge>[n + 1]();
    }

    Graph(int n, int m, vector<Edge>&Eds) : n(n), m(m) {
      upd = true;
      starts = new int[n + 1];
      levels = new int[n + 1];
      eds = new vector<Edge>[n + 1]();
      int I = 0;
      for(auto x : Eds)
        addEdge(x);
    }

    void addEdge(Edge x) {
      upd = true;
      x.rev_pos = eds[x.e].size();
      Edge y = x;
      y.rev_pos = eds[x.s].size();
      y.w = 0;
      swap(y.e, y.s);
      eds[x.s].push_back(x);
      eds[x.e].push_back(y);
    }

    void addEdge(int u, int v, int w) {
      this->addEdge(Edge(u, v, w));
    }

    void setStart(int x) { start = x, upd = true; }
    void setFinish(int x) { finish = x, upd = true; }

    long long get_max_flow() {
      if(upd) calc_flow();
      return mx_flow;
    }
  private :
    const int n, m;
    bool upd = false;
    long long mx_flow = 0;
    int start = -1, finish = -1;

    vector<Edge> *eds;
    int *starts;
    int *levels;

    bool bfs() {
      if(start == -1) return ;
      memset(levels, 63, sizeof levels);
      levels[start] = 0;
      queue<int> q;
      q.push(start);
      while(q.size()) {
        int v = q.front();
        q.pop();

        for(auto x : eds[v])
          if(levels[x.e] > levels[v] + 1 && x.w > 0) {
            q.push(x.e);
            levels[x.e] = levels[v] + 1;
          }
      }

      return levels[finish] < n;

    }

    long long dfs(int v, long long flow) {
      if(v == finish) return flow;
      for(;starts[v] < eds[v].size(); starts[v]++) {
        Edge&ed = eds[v][starts[v]];
        int u = ed.e;
        if(levels[u] == levels[v] + 1 && ed.w) {
          long long cur = min(flow, ed.w);
          long long tmp = dfs(u, cur);

          if(tmp > 0) {
            ed.w -= tmp;
            eds[ed.e][ed.rev_pos].w += tmp;
            return tmp;
          }
        }
      }
      return 0;
    }

    void calc_flow() {
      upd = false;
      for(int i = 0; i <= n; i++) for(auto&e : eds[i]) e.w = e.base_w;

      while(bfs()) {
        memset(starts, 0, sizeof starts);
        long long x;
        while(x = dfs(start, inf)) mx_flow += x;
      }

    }
};
