#include <iostream>

class ref{
    int a;
    int b;

    public:
    ref(int a, int b): a(a), b(b) {};
    ref(const ref& r){
        std::cout << "복사 생성자 호출" << std::endl;
        a = r.a;
        b = r.b;
    }
    int getA(){return a;}
    int& getRefB(){return b;} 
    ref getThis(){return *this;}
    ref& getRefThis(){return *this;}
    void show(){ std::cout << " a : " << a << ", b : " << b << std::endl; }
};

int main(){
    ref r = ref(10, 20);
    int a = r.getA(); 
    int& b = r.getRefB(); // 이렇게 하면 r 객체의 멤버변수 b의 레퍼런스를 받는다.
    r.show();
    a = 100;
    b = 200;
    r.show();
    r.getRefB() = 20; // 이런식으로도 접근이 가능하다.
    r.show();

    // 아래는 오류가 뜬다.
    // non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
    // int& 는 lvalue 레퍼런스이고, getA 는 우측값이라서 오류가 생기는 것이다.
    // int& a_ = r.getA();

    ref rr = ref(123, 456);
    ref rrr1 = rr.getThis(); // 이렇게 레퍼런스 리턴이 아닌 경우에는 복사 생성자가 호출이 된다.
    ref& rrr2 = rr.getRefThis(); // 이건 rr의 레퍼런스를 그대로 받는다.
}