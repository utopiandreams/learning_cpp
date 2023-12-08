#include <iostream>


template<typename T>
struct Comp{
    bool operatro()(const int& a1, const int& a2){
        return a1 > a2;
    }
};

template <typename T, typename Comp>
void bubble_sort(const T& t, Comp& comp){
    for(int i=0;i<t.size();i++){
        for(int j=i+1;j<t.size();j++){
            if(!comp(T[i], T[j])) t.swap(i, j); 
        }
    }
}

int main(){

}