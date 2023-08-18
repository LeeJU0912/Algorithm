#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int parent[300001];

int Find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    int a_parent = Find(a);
    int b_parent = Find(b);

    if (a_parent < b_parent) {
        parent[b_parent] = a_parent;
    }
    else if (a_parent > b_parent) {
        parent[a_parent] = b_parent;
    }
}

int main() {
    FastIO

    cin >> N;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < N - 2; i++) {
        int a, b;
        cin >> a >> b;

        Union(a, b);
    }

    for (int i = 1; i <= N; i++) {
        if (parent[i] == i) {
            cout << i << ' ';
        }
    }

    return 0;
}