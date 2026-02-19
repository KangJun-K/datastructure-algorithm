#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;
vector<int> graph[1005];
bool visited[1005] = {false};

void dfs(int cur){
    visited[cur] = true;
    cout << cur << " ";

    for(int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if(!visited[next]){
            dfs(next);
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main()
{
    int N, M, V;
    cin >> N >> M >> V;
    
    while(M--){
        int s, e;
        cin >> s >> e;
        graph[s].emplace_back(e);
        graph[e].emplace_back(s);
    }
    for(int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    
    visited[0] = true;
    dfs(V);
    cout << "\n";
    memset(visited, false, sizeof(visited));
    bfs(V);

    return 0;
}