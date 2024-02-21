#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    int ans = 0;

    cin >> N >> M;

    set <string> s;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if (s.find(str) != s.end()) ans++;
    }

    cout << ans;

    return 0;
}
