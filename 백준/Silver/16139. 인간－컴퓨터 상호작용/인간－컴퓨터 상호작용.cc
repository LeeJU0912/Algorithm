#include <bits/stdc++.h>
using namespace std;

int save[26][200001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    save[s[0] - 'a'][0]++;
    for (int i = 1; i < s.length(); i++) {
        save[s[i] - 'a'][i]++;
        for (int j = 0; j < 26; j++) {
            save[j][i] += save[j][i - 1];
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int ans = 0;
        char a;
        int b, c;
        cin >> a >> b >> c;



        cout << save[a - 'a'][c] - save[a - 'a'][b - 1] << '\n';
    }

    return 0;
}