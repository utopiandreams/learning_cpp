#include <iostream>

class Marine {
    static int total_num_of_marine; // static int total_num_of_marine = 0; 이런식으로 초기화 할 수 없음 
    const static int initial = 100; // 멤버 변수 중 const static 만이 이런식으로 초기화가 가능하다. 

    int hp; // 마린 체력
    int coord_x, coord_y; // 마린 위치
    bool is_dead;
    const int default_damage; // 기본 공격력

    public:
    Marine(); // 기본 생성자
    Marine(int x, int y); // x, y 좌표에 마린 생성
    Marine(int x, int y, int default_damage);
    ~Marine();

    int attack(); // 데미지를 리턴한다.
    void be_attacked(int damage_earn); // 입는 데미지
    void move(int x, int y); // 새로운 위치
    void show_status(); // 상태를 보여준다.

    static void show_total_marine(); // 자바와 마찬가지로 c++ 도 static 함수는 객체 생성 없이 호출할 수 있다.
};

Marine::Marine(): hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) { total_num_of_marine++; }
Marine::Marine(int x, int y): coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) { total_num_of_marine++; }
Marine::Marine(int x, int y, int default_damage): coord_x(x),coord_y(y),hp(50),default_damage(default_damage),is_dead(false) { total_num_of_marine++; }
Marine::~Marine(){ total_num_of_marine--; }

int Marine::attack(){ return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "<< std::endl;
    std::cout << " HP : " << hp << std::endl;
    std::cout << " 현재 총 마린 수 : " << total_num_of_marine << std::endl;
}
void Marine::show_total_marine(){
    std::cout << " 현재 총 마린 수 : " << total_num_of_marine << std::endl;
}

int Marine::total_num_of_marine = 0; // static 변수들은 이렇게 선언할 수 있다.

void create_marine() {
    Marine marine3(10, 10, 4);
    marine3.show_status();
}

int main(){
    Marine marine1(2, 3, 5);
    marine1.show_status();
    Marine marine2(3, 5, 10);
    Marine::show_total_marine();
    create_marine();
    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());
    marine1.show_status();
    marine2.show_status();
}