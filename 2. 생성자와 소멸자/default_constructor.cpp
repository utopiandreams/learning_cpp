#include <iostream>

class My_date {
    int year_;
    int month_;
    int day_;

    public:
    void ShowDate();
    My_date(){
        year_ = 2023;
        month_ = 11;
        day_ = 24;
    }
    // 기본 생성자는 굳이 만들지 않아도 자동으로 생성이 되는데,
    // My_date() = default; 라는 식으로 이를 명시적으로 나타낼 수도 있다.
    My_date(int y, int m, int d){
        year_ = y;
        month_ = m;
        day_ = d;
    }
};

void My_date::ShowDate(){
    std::cout << "오늘은 " << year_ << "년 " << month_ << "월 " << day_ << "일 입니다. " << std::endl;
}

int main(){
    My_date date1; // 기본 생성자로 객체 생성
    date1.ShowDate();

    My_date date2 = My_date(); // 기본 생성자로 객체 생성
    date2.ShowDate();
    
    My_date date3(2023, 11, 24); // 별도의 생성자로 객체 생성
    date3.ShowDate();

    // My_date date(); 이건 불가능 하다. 함수의 선언으로 읽힌다.

    My_date date4 = My_date(2023, 11, 24); // 별도의 생성자로 객체 생성
    date4.ShowDate();
    
}