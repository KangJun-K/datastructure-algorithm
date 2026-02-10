#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int> visited;


int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    int ans = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < graph[v].size(); i++) {
            int w = graph[v][i];
            if (!visited[w]) {
                visited[w] = visited[v] + 1;
                q.push(w);
            }
        }
        ans += visited[v] - 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    graph.assign(N + 1, vector<int>(0, 0));
    visited.assign(N + 1, 0);
    while (M--) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    int min = 2147483647;
    int min_hu = 0;
    for (int i = 1; i <= N; i++) {
        int temp = bfs(i);
        if ( temp < min ) {
            min = temp;
            min_hu = i;
        }
        visited.assign(N + 1, 0);
    }
    cout << min_hu << "\n";
    return 0;
}
