#include <string.h>
#include <iostream>

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;
    char* name;

    public:
    Photon_Cannon(int x, int y, char* name);
    ~Photon_Cannon();
    // Photon_Cannon(const Photon_Cannon &pc);

    void show_status();
    char* get_name();
};

Photon_Cannon::Photon_Cannon(int x, int y, char* name){
    std::cout <<  "생성자 호출" << std::endl;
    hp = shield = 100;
    coord_x = x; coord_y = y;
    damage = 20;
    this->name = name;
}


// 복사 생성자
// 사실 복사 생성자는 굳이 생성하지 않아도 기본적으로 생성이 됨 (아래와 같이)
// const 로 선언하여 참조 대상을 변경하지 못하게 막습니다.
// Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc) { 
//     std::cout << "복사 생성자 호출" << std::endl;
//     hp = pc.hp;
//     shield = pc.shield;
//     coord_x = pc.coord_x;
//     coord_y = pc.coord_y;
//     damage = pc.damage;
// }

Photon_Cannon::~Photon_Cannon(){
    if(name != nullptr)
    delete[] name;
}

void Photon_Cannon::show_status(){
    std::cout << "*** 포톤 캐논 상태 ***" << std::endl;
    std::cout << "hp : " << hp << std::endl;
    std::cout << "location : (" << coord_x << ", " << coord_y << ")" << std::endl;
}

char* Photon_Cannon::get_name(){
    return name;
}

int main(){
    Photon_Cannon pc1(3, 4, "캐논");
    Photon_Cannon pc2 = pc1; // 이 경우에 복사 생성자가 사용된다.
    pc2.show_status();
    // pointer being freed was not allocated 예외가 뜬다.
    // 기본생성자만 가지고 있는 경우 포인터 형태의 멤버변수를 복사할때 깊은 복사가 아닌 얕은 복사만 일어난다.
    // 따라서 pc2 을 deconstruct 할때 이미 해당 포인터는 free 상태가 되어버려서 
    // pc1 을 deconstruct 시, 메모리가 할당되지 않은 포인터를 다시 delete 를 시도하여 예외가 발생한다.
    // 이런 경우에는 꼭 복사 생성자를 직접 작성해서 넣어주어야 한다.
}