#include <iostream>
#include <string>




// template 은 컴파일 시점에 어떤 type 이 사용되는 지를 보고 각각의 class 를 전부 만들어준다.
template <typename T> // template <class T> 와 동일한 표현임.
class Vector {
    T* data;
    int capacity;
    int length;

    public:
    Vector(int n = 1): data(new T[n]), capacity(n), length(0) {}
    ~Vector(){ if(data) delete[] data;}

    void push_back(const T& t){
        if(capacity <= length) {
            T* new_data = new T[capacity * 2];
            for(int i=0;i<length;i++){
                new_data[i] = data[i];
            }
            delete[] data;
            capacity *= 2;
            data = new_data;
        }
        data[length] = t;
        length ++;
    }

    void remove(int idx){
        if(idx < 0 || idx >= length) return;
        for(int i=0;i<length-idx-1;i++){
            data[idx+i] = data[idx+1+i]; 
        }
    }

    int size(){return length; }
    void print(){
        std::cout << "-------- 원소 출력 --------" << std::endl;
        for(int i=0;i<length;i++){
            std::cout << i << "번째 원소 : "  << data[i] << std::endl;
        }
    }
};

// 템플릿 특수화 : 특정 타입에 대해서 별도로 처리
template <> // 이렇게 하면 bool 에 대해서는 아래와 같이 처리 된다.
class Vector<bool> {
    unsigned int* data;
    int length;
    int capacity;
    
    public:
    Vector(int n = 0): data(new unsigned int[n/32 + 1]), length(0), capacity(n/32 + 1) {}
    ~Vector(){ if(data) delete[] data; }
    
    int size(){return length;}
    bool operator[](const int& idx) const {
        if(data[idx/32] & (1<<(idx%32))) return true;
        else return false;
    }

    void print(){
        std::cout << "-------- 원소 출력 --------" << std::endl;
        for(int i=0;i<length;i++){
            if(data[i/32] & (1<<(i%32))) std::cout << "1";
            else std::cout << "0";
        } 
        std::cout << std::endl;
    }

    void push_back(bool b){
        if(capacity * 32 <= length){
            unsigned int* new_data = new unsigned int[capacity * 2];
            for(int i=0;i<capacity;i++){
                new_data[i] = data[i];
                new_data[i+capacity] = 0;
            }
            delete[] data;
            data = new_data;
            capacity *= 2;
        }
        if(b) data[(length/32)] |= (1<<(length%32));
        length ++;
    }

    void remove(int pos){
        for(int i = pos;i<length-1;i++){
            int now = i;
            int next = i+1;
            if(data[next/32] & (1<<(next%32))){
                data[now/32] |= (1<<(now%32));
            } else if(data[now/32] & (1<<(now%32))){
                data[now/32] ^= (1<<(now%32));
            }
        }
        length--;
    }
};

int main(){
    Vector<int> int_v(10);
    int_v.push_back(5);
    int_v.push_back(10);
    int_v.print();

    Vector<std::string> string_v(10);
    string_v.push_back("안녕");
    string_v.push_back("하세요");
    string_v.print();

    Vector<bool> bool_v(10);
    bool_v.push_back(true);
    bool_v.push_back(false);
    bool_v.push_back(true);
    bool_v.push_back(false);
    bool_v.push_back(true);
    bool_v.push_back(true);
    bool_v.push_back(false);
    bool_v.push_back(true);
    bool_v.push_back(false);
    bool_v.push_back(true);
    bool_v.push_back(false);
    bool_v.push_back(false);
    bool_v.push_back(true);
    bool_v.push_back(false);
    bool_v.push_back(true);
    bool_v.push_back(false);
    bool_v.push_back(false);
    bool_v.push_back(true);
    bool_v.push_back(false);
    bool_v.push_back(false);
    bool_v.push_back(true);
    bool_v.push_back(false);
    bool_v.push_back(true);
    bool_v.push_back(false);
    bool_v.push_back(false);
    bool_v.push_back(true);
    bool_v.push_back(false);
    bool_v.push_back(true);
    bool_v.push_back(false);
    bool_v.print();
    bool_v.remove(4);
    bool_v.print();
}