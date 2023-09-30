#include <iostream>
#include <stack>
using namespace std;

bool prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    stack<int> v;
    int n, i = 2; // Объявляем переменную i и инициализируем её значением 2
    cin >> n;

    if (n == 1) {
        cout << 2;
        return 0;
    }

    while (true) { // Заменяем цикл for на бесконечный цикл
        if (prime(i)) {
            v.push(i);
            if (n == v.size()) {
                break; // Выходим из цикла, когда наберем n простых чисел
            }
        }
        i++; // Увеличиваем i для проверки следующего числа
    }

    cout << v.top();

    return 0;
}
