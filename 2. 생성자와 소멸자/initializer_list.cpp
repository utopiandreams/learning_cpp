#include <iostream>

class Init {
    int a;

    // 멤버 변수를 const 로 고정 시키면 변동될 여지가 없다.
    // const 변수는 생성과 동시에 초기화가 되어야 한다.
    const int b; 

    public:
    Init();
    Init(int a, int b);
    Init(const Init& init);

    void show_status();
};

// 아래 같은 생성자는 디폴트 생성자 호출후 값을 복사하는 연산이 일어난다.
// 따라서 생성과 동시에 초기화 되어야 하는 const 변수의 경우 오류가 생긴다.
// Init::Init(int a, int b){
//     this->a = a;
//     this->b = b;
// }

// 초기화 리스트 생성자를 쓰면 생성과 동시에 값이 할당 된다.
Init::Init(): a(10), b(5) {}; 
Init::Init(int a, int b): a(a), b(b) {}; 
Init::Init(const Init& init): a(init.a), b(init.b) {}; 

void Init::show_status(){
    std::cout << "b : " << this->b << std::endl;;
}

int main(){
    Init i1;
    Init i2 = i1;
    i2.show_status();
}