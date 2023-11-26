#include <iostream>

class Marine {
    char* name;
    int hp;
    int coord_x, coord_y;
    int damage;
    int is_dead;

    public:
    Marine();
    Marine(int x, int y, const char* name);
    ~Marine();  // Destructor(소멸자) : 객체가 생성될 때 객체가 가리키는 메모리를 자동으로 해제해줍니다.

    int attack(); // 유닛의 공격력을 리턴합니다.
    void be_attacked(int damage_receive);
    void move(int x, int y);

    void show_status();
};

Marine::Marine(){
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = nullptr;
}

Marine::Marine(int x, int y, const char* name){
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

Marine::~Marine(){
    std::cout << "소멸자 호출 : " << name << std::endl;
    if(name != nullptr) delete[] this->name;
}

int Marine::attack(){
    return damage;
}

void Marine::be_attacked(int damage_receive){
    hp -= damage_receive;
    if(hp < 0) is_dead = true;
}

void Marine::move(int x, int y){
    coord_x += x;
    coord_y += y;
}

void Marine::show_status(){
    std::cout << "*** 마린 상태 ***" << std::endl;
    std::cout << "위치 : ( " << coord_x << ", " << coord_y << " )" << std::endl;
    std::cout << "hp : " << hp << std::endl;
}

int main(){
    Marine marine1 = Marine();
    marine1.show_status();
    Marine marine2 = Marine(1, 2, "aaa");
    marine2.show_status();

    std::cout << "마린 2 가 마린 1 에게 공격받음" << std::endl;
    marine2.be_attacked(marine1.attack());
    marine2.show_status();

    std::cout <<  std::endl;
    std::cout <<  std::endl;

    // 마린이 여러 마리라면?
    Marine* marines[12]; // 마린의 포인터 배열 선언
    marines[0] = new Marine(10, 20, "bbb"); // new 키워드를 통한 생성자 호출
    marines[1] = new Marine(15, 30, "ccc");

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << "마린 2 가 마린 1 에게 공격받음" << std::endl;
    marines[1]->be_attacked(marines[0]->attack());
    marines[1]->show_status();


    delete marines[0]; // 동적할당을 한 경우, 마지막에는 메모리를 해제해 주어야 한다.
    delete marines[1]; 

    return 0;
}

