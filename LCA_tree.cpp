#include <bits/stdc++.h>
using namespace std;
#include <functional>
class LCA_Tree {
    int n, LOG;
    vector<vector<int>> parent;
    vector<vector<long long>> func;
    vector<vector<pair<long long, long long>>> adj;
    vector<int> depth;

    function<long long(long long, long long)> mergeFunc;
    long long identity;  // Identity value for mergeFunc: sum -> 0, min -> INF, etc.

    void dfs(int node, int par) {
        for (auto &p : adj[node]) {
            int neighbor = p.first;
            long long weight = p.second;
            if (neighbor == par) continue;

            depth[neighbor] = depth[node] + 1;
            parent[neighbor][0] = node;
            func[neighbor][0] = weight;

            for (int i = 1; i < LOG; ++i) {
                int mid = parent[neighbor][i - 1];
                if (mid == -1) break;
                parent[neighbor][i] = parent[mid][i - 1];
                func[neighbor][i] = mergeFunc(func[neighbor][i - 1], func[mid][i - 1]);
            }
            dfs(neighbor, node);
        }
    }

    long long getFuncValue(int u, int lca) {
        long long res = identity;
        int d = depth[u] - depth[lca];
        for (int i = LOG - 1; i >= 0; --i) {
            if ((d >> i) & 1) {
                res = mergeFunc(res, func[u][i]);
                u = parent[u][i];
            }
        }
        return res;
    }

    int getKthAncestor(int node, int k) {
        for (int i = LOG - 1; i >= 0; i--)
            if ((k >> i) & 1) {
                if (node == -1) return -1;
                node = parent[node][i];
            }
        return node;
    }

public:
    LCA_Tree(int nodes,
             const vector<vector<int>>& edges,
             function<long long(long long, long long)> mergeFunc,
             long long identity)
        : n(nodes), mergeFunc(mergeFunc), identity(identity) {

        LOG = 32;
        parent.assign(n, vector<int>(LOG, -1));
        func.assign(n, vector<long long>(LOG, identity));
        adj.assign(n, {});
        depth.assign(n, 0);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            long long w = edge[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        dfs(0, -1);
    }

    int getLCA(int u, int v) const {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = LOG - 1; i >= 0; i--)
            if ((diff >> i) & 1)
                u = parent[u][i];
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; i--)
            if (parent[u][i] != parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
            }
        return parent[u][0];
    }

    long long getFuncBetween(int u, int v) {
        int lca = getLCA(u, v);
        return mergeFunc(getFuncValue(u, lca), getFuncValue(v, lca));
    }

    pair<long long, int> getKthNodeAndFunc(int u, int k, int v) {
        int lca = getLCA(u, v);
        int d1 = depth[u] - depth[lca], d2 = depth[v] - depth[lca];

        if (k <= d1) {
            int node = getKthAncestor(u, k);
            return {getFuncValue(u, node), node};
        } else {
            k -= d1;
            int node = getKthAncestor(v, d2 - k);
            long long val1 = getFuncValue(u, lca);
            long long val2 = getFuncValue(v, lca);
            long long val3 = getFuncValue(v, node);
            return {mergeFunc(mergeFunc(val1, val2), -val3), node};
        }
    }

    int getKthNodeInPath(int u, int v, int k) {
        int lca = getLCA(u, v);
        int d1 = depth[u] - depth[lca];
        if (k <= d1) return getKthAncestor(u, k);
        int d2 = depth[v] - depth[lca];
        return getKthAncestor(v, d2 - (k - d1));
    }

    int getDepth(int u) const { return depth[u]; }

    long long getDistance(int u, int v) const {
        int lca = getLCA(u, v);
        return depth[u] + depth[v] - 2LL * depth[lca];
    }
};

int main(){
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 2},
        {1, 3, 4},
        {3, 4, 1}
    };

    // Create LCA tree with SUM
    LCA_Tree tree(n, edges, [](long long a, long long b) { return a + b; }, 0LL);

    // With MAX
    // LCA_Tree tree(n, edges, [](long long a, long long b) { return max(a, b); }, LLONG_MIN);

    // With MIN
    // LCA_Tree tree(n, edges, [](long long a, long long b) { return min(a, b); }, LLONG_MAX);

    int u = 2, v = 4;
    int lca = tree.getLCA(u, v);
    cout << "LCA of " << u << " and " << v << ": " << lca << "\n";

    long long total_weight = tree.getFuncBetween(u, v);
    cout << "Total weight between " << u << " and " << v << ": " << total_weight << "\n";
}