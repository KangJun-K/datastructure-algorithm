#include<bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int DP[N + 1];
    int score[N + 1];
    for(int i = 1; i <= N; i++)
    {
        cin >> score[i];
    }
    DP[1] = score[1];
    DP[2] = score[1] + score[2];
    DP[3] = max(score[1], score[2]) + score[3];

    for(int i = 4; i <= N; i++)
    {
        DP[i] = max(DP[i-2], DP[i-3] + score[i-1]) + score[i];
    }

    cout << DP[N] << "\n";


    return 0;
}

