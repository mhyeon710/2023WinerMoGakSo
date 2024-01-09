//LIS(NlogN) + 출력
#include <iostream>
#include <vector>
using namespace std;

void fio() { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); }

int arr[1000000], index[1000000];
vector <int> len, p;
int main() {
    fio();

    int N; cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    
    len.push_back(arr[0]);
    index[0] = 0;
    for (int i=1; i<N; i++) {
        int now = arr[i];
        if (len.back() < now) {
            len.push_back(now);
            index[i] = len.size() - 1;
        }
        else {
            int idx = lower_bound(len.begin(), len.end(), now) - len.begin();
            len[idx] = now;
            index[i] = idx;
        }
    }
    cout << len.size() << '\n';

    int vsize = len.size() - 1;
    p.push_back(1000000001);
    for (int i=N-1; i>=0; i--) {
        if (index[i] == vsize && arr[i] < p.back()) {
            p.push_back(arr[i]);
            vsize--;
        }
    }
    
    while (p.size() > 1) {
        cout << p.back() << ' ';
        p.pop_back();
    }
    return 0;
}