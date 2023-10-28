#include<bits/stdc++.h>
using namespace std;

vector<char>v;
void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int l, int h){
    int pivot = v[h];
    int i = l-1;
    for(int j = l;j<h;j++){
        if(v[j]<pivot){
            i++;
            swap(&v[i], &v[j]);
        }
    }
    i++;
    swap(&v[i], &v[h]);
    return i;
}

void quickSort(int l, int h){
    if(l<h){
        int pi = partition(l, h);
        quickSort(l, pi-1);
        quickSort(pi+1, h);
    }
}

int main(){
    int n;cin>>n;
    for(int i = 0;i<n;i++){
        char a;cin>>a;
        v.push_back(a);
    }
    char temp;cin>>temp;
    v.push_back(temp);
    quickSort(0, v.size()-1);
    if(v[v.size()-1]==temp){
        cout<<v[0];
        return 0;
    }
    for(int i = 0;i<v.size();i++){
        if(v[i]==temp && v[i+1]!=temp){
            cout<<v[i+1];
        }
    }
}
