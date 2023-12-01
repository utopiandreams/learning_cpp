#include <iostream>


template<typename T>
T max(const T& a, const T& b) {
    return a > b ? a : b;
}

template<typename T>
T bubbleSort(const T& arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i] < arr[j]) arr.swap(i, j); 
        }
    }
}

int main(){
    int m = max(3, 5); // 템플릿 함수는 타입인자를 선언해줄 필요가 없다.
    std::cout << m; 
}