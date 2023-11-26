#include<iostream>


// 값을 포인터로 받기
void changeValue(int* v, int num){
    std::cout << "v 의 주소값 : " << v << std::endl; // 포인터는 단순히 "주소값" 이다.
    *v = num; // 포인터가 가리키는 주소에 접근하기 위해서는 역참조 연산자를 쓴다.
    std::cout << "v 가 가리키는 값 : " << *v << std::endl; // num 출력
}

// 배열을 포인터로 받기 
void changeArrayValue(int* arr, int pos, int num)
{
    arr = new int; // 포인터에 메모리를 할당한다.
    *arr = 100; // 배열의 첫번째 요소를 가리킨다.
    std::cout << arr[0] << std::endl; // 100 출력
    *(arr + 2) = 200; // 배열의 2 번째 요소를 가리킨다. (메모리가 자동으로 할당 됨)
    std::cout << arr[2] << std::endl; // 200 출력
    arr[pos] = num; // 배열의 pos 번째 요소를 가리킨다.
    std::cout << arr[pos] << std::endl; // num(5) 출력
}

// 포인터 배열을 인수로 받기
void changePVrrayValue(int** parr, int pos, int num){
    *(*parr) = 123; // 포인터 배열의 첫번째 값을 역참조하여 첫번째 포인터에 접근하고 거기에 다시 역참조로 접근할 수 있다. (메모리가 자동으로 할당 됨)
    std::cout << "포인터 배열의 0번째 포인터 주소 : " << parr[0] << std::endl;
    std::cout << "포인터 배열의 0번째 포인터가 가리키는 값 : " << *parr[0] << std::endl;
    
    *(parr+pos) = new int; // 여기서는 메모리가 자동으로 할당이 되지 않는다.
    *(*(parr+pos)) = 3;
    std::cout << "포인터 배열의 pos번째 포인터 주소 : " << parr[pos] << std::endl;
    std::cout << "포인터 배열의 pos번째 포인터가 가리키는 값 : " << *parr[pos] << std::endl;
}

int main(){

    // 1. 단순 값
    int value;
    int* pvalue = &value;
    std::cout << "pvalue : " << pvalue << std::endl;
    std::cout << "&value : " << &value << std::endl;
    changeValue(pvalue, 29);

    // 2. 배열
    int int_array[10];
    changeArrayValue(int_array, 3, 5);

    // 3. 포인터 배열
    int* pint_array[10];
    changePVrrayValue(pint_array, 5, 6);
}

