#include <iostream>

class my_class {
    char* string;
    int length;

    public:
    explicit my_class(int l);
    my_class(const my_class& mc);
    my_class(const char* c);
    ~my_class();

    char* getString() const {
        return string;
    }
};

my_class::my_class(int l){
    std::cout << "생성자 호출1" << std::endl;
    length = l;
    string = new char[l+1];
}

my_class::my_class(const my_class& mc){
    std::cout << "생성자 호출2" << std::endl;
    length = mc.length;
    string = new char[length + 1];
    strcpy(string, mc.string);
}

my_class::my_class(const char* c){
    std::cout << "생성자 호출3" << std::endl;
    length = strlen(c) + 1;
    string = new char[length + 1];
    strcpy(string, c);
}

my_class::~my_class(){
    delete[] string;
}

void print(const my_class& mc){
    std::cout << mc.getString() << std::endl;
}

int main(){
    // 암시적 변환(implicit conversion) 이 일어난다.
    print("asdf"); // 자동으로 my_class(const char* c) 생성자가 호출 된다.
    
    // explicit 을 붙이면 자동으로 변환이 일어나지 않아 오류가 발생한다.
    print(15); // explicit 을 붙이면 자동으로 my_class(int i) 생성자가 호출된다. ==> 잘못썼음에도 문제없이 처리가 될 수 있다.
}