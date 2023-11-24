#include <iostream>

class Test{
    char* c;

    public:
    Test(char _c){
        std::cout << "생성자 호출 : " << _c << std::endl;
        c = new char;
        *c = _c;
    }
    ~Test(){
        std::cout << "소멸자 호출 : " << c << std::endl;
        delete c;
    }
};

void test(){
    Test B('b');
}

int main(){
    Test c('a');
    test();
}