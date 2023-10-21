#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N; // Количество массивов
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq; // Мин-куча

    // Чтение длин массивов и добавление их в очередь
    for (int i = 0; i < N; ++i) {
        int length;
        cin >> length;
        pq.push(length);
    }

    int total_cost = 0;

    // Пока в очереди не останется только один элемент
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int cost = a + b;
        total_cost += cost;
        pq.push(cost); // Добавляем результат обратно в очередь
    }

    cout << total_cost << endl;

    return 0;
}
