
#include <bits/stdc++.h> 
using namespace std; 
#define pb push_back 
deque<int>dq; // Создаем дек (двустороннюю очередь) для хранения чисел.
int main() 
{ 
char flag; // Входим в цикл и считываем символ flag.
 while(cin>>flag) 
 {   
    if(flag=='!') break; // Если символ '!' встречается, выходим из цикла.
    if(flag=='+') // Если символ '+' встречается, считываем число и добавляем его в начало дека.
    { 
    int a; 
    cin>>a; 
    dq.push_front(a); 
    } 
    else if(flag=='-')  // Если символ '-' встречается, считываем число и добавляем его в конец дека.
    { 
        int b; 
        cin>>b; 
        dq.push_back(b); 
    } 
    if(flag =='*'){ // Если символ '*' встречается, выполняем операцию сложения первого и последнего чисел в деке.
    if(!dq.empty() ) // Проверяем, что дек не пуст.
    { 
        cout<<dq.front()+dq.back()<<"\n"; // Вычисляем сумму.
        dq.pop_front();  // Удаляем первый элемент из дека.
        if(!dq.empty()) dq.pop_back(); // Удаляем последний элемент, если дек не пуст.
    } 
    else cout<<"error\n"; // Если дек пуст, выводим сообщение об ошибке.
    } 
} 
  return 0; 
}