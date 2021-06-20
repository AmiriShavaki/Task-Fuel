#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 500005;

int from[N], to[N], res, depth[N], maxDepth, res2, depth2[N], maxDepth2;
bool mark[N], mark2[N];
vector < int > G[N];

void dfs(int v) {
    for (int i = 0; i < G[v].size(); i++) {
        if (!mark[G[v][i]]) {
            mark[G[v][i]] = true;
            depth[G[v][i]] = depth[v] + 1;
            if (maxDepth < depth[G[v][i]]) {
                maxDepth = depth[G[v][i]];
                res = G[v][i];
            }
            dfs(G[v][i]);
        }
    }
}

void dfs2(int v) {
    for (int i = 0; i < G[v].size(); i++) {
        if (!mark2[G[v][i]]) {
            mark2[G[v][i]] = true;
            depth2[G[v][i]] = depth2[v] + 1;
            if (maxDepth2 < depth2[G[v][i]]) {
                maxDepth2 = depth2[G[v][i]];
                res2 = G[v][i];
            }
            dfs2(G[v][i]);
        }
    }
}

int32_t main() {
    int n, m;
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < n - 1; i++) {
        scanf("%lld %lld", &from[i], &to[i]); from[i]--; to[i]--;
        G[from[i]].push_back(to[i]);
        G[to[i]].push_back(from[i]);
    }
    mark[0] = true;
    dfs(0);
    mark2[res] = true;
    dfs2(res);
    if (m <= maxDepth2) {
        printf("%lld\n", m + 1);
    } else {
        printf("%lld\n", min(maxDepth2 + 1 + (m - maxDepth2) / 2, n));
    }
    return 0;
}
