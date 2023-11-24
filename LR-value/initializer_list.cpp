#include <iostream>

class Marine {
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;

    public:
    Marine();
    Marine(int x, int y);

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);
    
    void show_status();
};

Marine::Marine(): hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {} // 생성자 리스트가 더 효율적이다. 
Marine::Marine(int x, int y): hp(50), coord_x(x), coord_y(y), damage(0), is_dead(false) {} 
int Marine::attack(){ return damage; }
void Marine::be_attacked(int damage_earn){ this->hp -= damage_earn; if(hp<=0) is_dead = true; }
void Marine::move(int x, int y){coord_x += x; coord_y += y; }
void Marine::show_status(){
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main(){
    Marine marine1(2, 3);
    Marine marine2(3, 5);
    marine1.show_status();
    marine2.show_status();
}