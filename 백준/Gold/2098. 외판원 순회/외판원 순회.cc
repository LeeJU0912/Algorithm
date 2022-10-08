#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <array>
#include <climits>
#include <cstdlib>
#include <utility>
#include <regex>
#include <numeric>
#include <cctype>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include <unordered_map>
#include <cfloat>

using namespace std;

#define INF 1000000000

int N;
int W[16][16];
int all_visited;
int cost[16][1 << 16];

int DFS (int now, int visited) {
    if (visited == all_visited) { // 지금까지 모든 곳들을 방문했을 경우
        if (W[now][0] == 0) return INF; // 근데 여기서 0번쨰 도시로 다시 되돌아 갈 방법이 없으면 제외
        else return W[now][0]; // 0번쨰로 돌아갈 값이 있다면 그 값을 반환한다.
    }

    if (cost[now][visited] != -1) return cost[now][visited]; // cost가 갱신이 이미 되었을 경우, 그 값을 반환한다.
    cost[now][visited] = INF; // 만약 cost를 한번도 안 건들였다면, 지금의 위치에서 맨 처음 무조건 갱신을 할 수 있게끔 INT_MAX를 넣는다.

    for (int i = 0; i < N; i++) {
        if (W[now][i] == 0) continue; // 연결 지점이 아니면 패스
        if ((visited & (1 << i)) == (1 << i)) continue; // 이미 방문한 곳이면 패스

        // 지금 위치에서의 비용 갱신 = (기존의 지금 위치의 값, 지금-다음 위치 가중치 + 다음 위치로 가서 그 위치의 최소 순회 값) 최솟값
        cost[now][visited] = min(cost[now][visited], W[now][i] + DFS(i, visited | 1 << i));
    }
    return cost[now][visited];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }

    all_visited = (1 << N) - 1; // 모든 비트가 1로 채워지면 (모든 도시 방문 체크가 1로 바뀌면) 정답.

    memset(cost, -1, sizeof(cost));

    cout << DFS(0, 1); // 0번째 도시부터 순회 시작. 00001 비트 켜짐(0번째 도시 비트 위치)



    return 0;
}