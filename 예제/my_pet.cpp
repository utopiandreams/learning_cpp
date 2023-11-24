/*
• 동물(struct Animal) 구조체는
 - 이름(char name[30])
 - 나이(int age)
 - 체력(int health)
 - 배부른 정도(int food)
 - 깨끗한 정도의(int clean)
 값을 가진다.
• 처음에 동물 구조체의 포인터 배열(struct Animal* list[30])을 만들어서 사용자가
  동물을 추가할 때 마다 하나씩 생성한다.
• play 라는 함수를 만들어서 동물의 상태를 변경하고 show_stat 함수를 만들어서 지정하는
  동물의 상태를 출력한다.
• 1 턴이 지날 때 마다 동물의 상태를 변경한다.
*/
#include <iostream>

struct Animal
{
    char name[30];
    int age;
    int health;
    int food;
    int clean;
};

void addPet(Animal* pet_list, int pos){
    std::cout << "이름 : ";
    std::cin >> pet_list[pos].name;
    
    std::cout << "나이 : ";
    std::cin >> pet_list[pos].age;

    pet_list[pos].health = 80;
    pet_list[pos].food = 80;
    pet_list[pos].clean = 80;
}

void play(Animal* pet_list, const int& num_of_animal){
    for(int i=0;i<num_of_animal;i++){
        pet_list[i].food -= 30;
        pet_list[i].health += 10;
        pet_list[i].clean -= 20;
    }
}

void feed(Animal* pet_list, const int& num_of_animal){
    for(int i=0;i<num_of_animal;i++){
        pet_list[i].food += 50;
        pet_list[i].clean -= 10;
    }
}

void oneDayPass(Animal* pet_list, const int& num_of_animal){
    for(int i=0;i<num_of_animal;i++){
        pet_list[i].food -= 30;
        pet_list[i].clean += 20;
    }
}

void state(Animal* pet_list, const int& num_of_animal){
    for(int i=0;i<num_of_animal;i++){
        std::cout << "이름 : " << pet_list[i].name << ", 나이 : " << pet_list[i].age << ", 건강 : " << pet_list[i].health << ", 배고픔 : " << pet_list[i].food << ", 청결도 : " << pet_list[i].clean << std::endl;
    }
}

int main(){
    Animal list[10];
    int animal_num = 0;
    while(true){
        std::cout << "다음 중 원하는 행동을 고르세요 >> 1. 애완동물 추가 2. 놀아주기 3. 밥주기 4. 상태보기 " << std::endl;
        int opt;
        std::cin >> opt;
        switch(opt){
            case 1:
                addPet(list, animal_num++);
                break;

            case 2:
                play(list, animal_num);
                break;

            case 3:
                feed(list, animal_num);
                break;
            
            case 4:
                state(list, animal_num);
                break;
        }
        oneDayPass(list, animal_num);
    }

}