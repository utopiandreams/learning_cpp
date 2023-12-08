#include <iostream>
#include <string>

class Employee {
    protected: // protected 접근 제어자를 해놓아야 자식 클래스에서 접근이 가능하다.
    std::string name;
    int age;

    std::string position;
    int rank;

    public:
    Employee(std::string name, int age, std::string position, int rank)
    : name(name), age(age), position(position), rank(rank){}

    // 복사생성자
    Employee(const Employee& employee){
        name = employee.name;
        age = employee.age;
        position = employee.position;
        rank = employee.rank;
    }

    // 디폴트 생성자
    Employee(){}

    void print_info(){
        std::cout << name << " (" << position << ", " << age << ") ==> " << calculate_pay() << std::endl;
    }

    int calculate_pay(){return 200 + 50 * rank;}
};

class Manager : public Employee { // 상속
    int year_of_service;
    
    public:
    Manager(std::string name, int age, std::string position, int rank, int year_of_service):
    Employee(name, age, position, rank), year_of_service(year_of_service){}

    Manager(const Manager& manager): Employee(manager.name, manager.age, manager.position, manager.rank){
        year_of_service = manager.year_of_service;
    }

    Manager() : Employee(){}

    int calculate_pay(){return 200 + rank * 50 + 5 * year_of_service; }
    void print_info(){
        std::cout << name << " (" << position << ", " << age << ", " << year_of_service << " 년차) ==> " << calculate_pay() << std::endl;
    }
};

class EmployeeList {
    Employee** employee_list;
    Manager** manager_list;
    int alloc_employee;
    int current_employee;
    int current_manager;

    public:
    EmployeeList(int size){
        alloc_employee = size*2;
        current_employee = 0;
        current_manager = 0;
        employee_list = new Employee*[10];
        manager_list = new Manager*[10];
    }

    ~EmployeeList(){
        for(int i=0;i<current_employee;i++){
            delete employee_list[i];
        }
        for(int i=0;i<current_manager;i++){
            delete manager_list[i];
        }
        delete[] employee_list;
    }

    void add_employee(Employee* employee){
        employee_list[current_employee] = employee;
        current_employee++;
    }

    void add_manager(Manager* manager){
        manager_list[current_manager] = manager;
        current_manager++;
    }
    
    int current_employee_num(){return current_employee; }
    void print_employee_info(){
        int total_pay = 0;
        for(int i=0;i<current_employee;i++){
            employee_list[i]->print_info();
            total_pay += employee_list[i]->calculate_pay();
        }
        for(int i=0;i<current_manager;i++){
            manager_list[i]->print_info();
            total_pay += manager_list[i]->calculate_pay();
        }
        std::cout << "총 월급 합계 : " << total_pay << " 만원" << std::endl;
    }
};

int main(){
    EmployeeList employ_list(10);
    employ_list.add_employee(new Employee("기홍", 33, "사원", 1));
    employ_list.add_employee(new Employee("지영", 30, "실장", 3));
    employ_list.add_manager(new Manager("바보", 50, "사장", 3, 4));
    employ_list.print_employee_info();
}
