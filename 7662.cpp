#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 최대 연산 개수 K가 1,000,000이므로 배열 크기 넉넉하게 잡음
bool visited[1000001];

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    while (T--) {
        int k;
        cin >> k;

        // 최대 힙: {값, ID}
        priority_queue<pair<int, int>> max_pq;
        // 최소 힙: {값, ID} (greater를 사용하여 오름차순)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;

        // 방문 배열 초기화 (이번 테스트 케이스의 범위만큼만)
        for(int i=0; i<k; i++) visited[i] = false;

        for (int i = 0; i < k; i++) {
            char cmd;
            int n;
            cin >> cmd >> n;

            if (cmd == 'I') {
                // 값과 유일한 ID(i)를 함께 저장
                max_pq.push({n, i});
                min_pq.push({n, i});
                visited[i] = true; // 유효하다고 표시
            }
            else { // cmd == 'D'
                if (n == 1) { // 최댓값 삭제
                    // 이미 다른 쪽에서 삭제된 값(visited가 false)이 top에 있다면 제거 (Lazy Deletion)
                    while (!max_pq.empty() && !visited[max_pq.top().second]) {
                        max_pq.pop();
                    }
                    // 유효한 값이 있다면 실제 삭제 처리
                    if (!max_pq.empty()) {
                        visited[max_pq.top().second] = false; // 삭제 표시
                        max_pq.pop();
                    }
                }
                else { // 최솟값 삭제
                    // 이미 삭제된 값 제거
                    while (!min_pq.empty() && !visited[min_pq.top().second]) {
                        min_pq.pop();
                    }
                    // 유효한 값이 있다면 실제 삭제 처리
                    if (!min_pq.empty()) {
                        visited[min_pq.top().second] = false; // 삭제 표시
                        min_pq.pop();
                    }
                }
            }
        }

        // 모든 연산 후에도 top에 삭제된 값이 남아있을 수 있으므로 최종 청소
        while (!max_pq.empty() && !visited[max_pq.top().second]) max_pq.pop();
        while (!min_pq.empty() && !visited[min_pq.top().second]) min_pq.pop();

        if (max_pq.empty() || min_pq.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << max_pq.top().first << " " << min_pq.top().first << "\n";
        }
    }
    return 0;
}