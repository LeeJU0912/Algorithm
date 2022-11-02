#include <bits/stdc++.h>
using namespace std;

int N;
string s[10];
int graph[26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s[i];
        int pow = 1;

        for (int j = s[i].length() - 1; j >= 0; j--) {
            graph[s[i][j] - 'A'] += pow;
            pow *= 10;
        }
    }

    sort(graph, graph + 26, greater<>());

    int num = 9;
    int answer = 0;
    for (int i = 0; i < 26; i++) {
        if (graph[i] == 0) break;
        answer += graph[i] * num--;
    }

    cout << answer;

    return 0;
}