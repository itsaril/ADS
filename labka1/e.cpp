#include <iostream> 
#include <deque> 
using namespace std; 
 
// объявление двух колод для игроков Бориса и Нурсика, каждая с пятью картами.
deque<int> Boris(5); 
deque<int> Nursic(5);

int main(){ 
    // игроки вводят свои карты по одной и сохраняют их в соответствующих колодах.
    for(int i = 0; i < 5; i++){ 
        cin>>Boris[i]; 
    } 
    for(int i = 0; i < 5; i++){ 
        cin>>Nursic[i]; 
    } 
    // для отслеживания количества сделанных ходов.
    int moves = 0; 

    // Игра продолжается до тех пор, пока не закончатся карты у одного из игроков 
    // или до достижения лимита ходов (не более 1 000 000 ходов).
    while(!Nursic.empty() && !Boris.empty() && moves < 1000000){ 
        moves++; 
         
        int first = Boris.front(); 
        int second = Nursic.front(); 
        Boris.pop_front(); 
        Nursic.pop_front(); 
        if(first == 0 && second == 9){ 
            Boris.push_back(first); 
            Boris.push_back(second); 
        } 
        else if(first == 9 && second == 0){ 
            Nursic.push_back(first); 
            Nursic.push_back(second); 
        } 
        else if(first > second){ 
            Boris.push_back(first); 
            Boris.push_back(second); 
        } 
        else{ 
            Nursic.push_back(first); 
            Nursic.push_back(second); 
        } 
       
    } 
    if(Nursic.empty()){ 
        cout<<"Boris"<<" "<<moves; 
    } 
    else if(Boris.empty()){ 
        cout<<"Nursik"<<" "<<moves; 
    } 
    else{ 
        cout<<"blin nichya"; 
    } 
     
}
