//LIS(NlogN)
#include <iostream>
#include <vector>
using namespace std;

void fio() { cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); }

int arr[1000000];
vector <int> v;
int main() {
    fio();

    int N; cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    
    v.push_back(arr[0]);
    for (int i=1; i<N; i++) {
        int now = arr[i];
        if (v.back() < now) {
            v.push_back(now);
        }
        else {
            v[lower_bound(v.begin(), v.end(), now) - v.begin()] = now;
        }
    }
    cout << v.size();
    return 0;
}