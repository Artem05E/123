#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M; 

    vector<int> costumes(N);

    cout << "Введите костюмы для каждой вечеринки (в порядке 1, 2, ...): ";
    for (int i = 0; i < N; i++) {
        cin >> costumes[i];
    }

    set<int> nс;

    for (int i = 0; i < N; i++) {
        nс.insert(costumes[i]); 
    }

    cout << "Минимальное количество костюмов: " << nс.size() << endl;

    return 0;
}
