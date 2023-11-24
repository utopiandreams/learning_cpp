#include<iostream>

// 값을 참조자로 받기
void changeValue(int& v, int num){
    std::cout << "v 의 주소값 : " << &v << std::endl; // 참조자는 같은 주소를 가리킨다.
    v = num; // 참조자는 자바의 call by reference 와 같은 식으로 작동한다.
    std::cout << "v 가 가리키는 값 : " << v << std::endl; // num 출력
}

// 배열을 참조자로 받기 
void changeArrayValue(int (&arr)[10], int pos, int num) // 배열의 크기를 명시해야한다.
{
    arr[0] = 123;
    std::cout << arr[0] << std::endl;
    // 배열은 기본적으로 포인터이다.
    // c++ 에서는 포인터보다는 참조자를, 배열보다는 vector 를 쓰는 것을 권장한다.
}

int main(){

    // 1. 단순 값
    int value;
    changeValue(value, 29);

    // 2. 배열
    int int_array[10];
    changeArrayValue(int_array, 3, 5);
    std::cout << int_array[0] << std::endl;
}

