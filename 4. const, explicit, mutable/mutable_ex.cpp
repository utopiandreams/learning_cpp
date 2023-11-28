#include <iostream>

class my_class {
    mutable int prev_print_num; // const 함수에서도 값을 변경하고자 하는 경우, mutable 로 선언하면 된다.
    int my_num;

    public:
    explicit my_class(int l);
    void assign(int l){
        my_num = l;
    }

    void print() const {
        std::cout << my_num << std::endl;
        prev_print_num = my_num;  // const 함수 안에서도 변수의 값을 바꿀 수 있다.
    }

    void info(){
        std::cout << "my_num : " << my_num << ", prev_print_num : " << prev_print_num << std::endl;
    }
};

my_class::my_class(int l){
    my_num=l;
}

int main(){
    my_class a = my_class(3);
    a.print();
    a.assign(10);
    a.info();
}