#include <iostream>
#include <cstring>
#include <algorithm>

// 1. 문자(char) 로 부터의 문자열 생성, C 문자열 (char *) 로 부터의 생성
// 2. 문자열 길이를 구하는 함수
// 3. 문자열 뒤에 다른 문자열 붙이기
// 4. 문자열 내에 포함되어 있는 문자열 구하기
// 5. 문자열이 같은지 비교
// 6. 문자열 크기 비교 (사전 순) 


// 추가 과제
// + assign 함수
// + mem_capacity 변수
// + reserve 함수 
// + insert 함수
// + erase 함수
// + find 함수    ++ 여러가지 검색 알고리즘(KMP, Boyer - Moore) 들을 이용하는 find 함수를 만들어보세요.
// + compare 함수 (같으면 0 사전순 빠르면 1 늦으면 -1)
// mem_capacity 를 고려해서 구현해보기

class string {
    char* str;
    int len;
    int mem_capacity; // 실제 입력된 문자열의 크기가 아니라 할당 되어있는 메모리의 크기를 가리킨다. 

    public:
    string();
    string(char c);
    string(const char *c);
    string(const string& other);
    ~string();

    // 내부 멤버 변수를 바꾸지 않으면 const 로 선언하기!
    int strlen() const;
    int capacity() const;
    void print() const;
    void info() const;
    void reserve(int size);
    char at(const int& i) const;

    string& assign(const string& str);
    string& assign(const char* str);

    string& insert(int pos, const char* s);
    string& insert(int pos, const string& s);
    string& erase(int pos, int num);

    string& add_string(const string &s);
    string& add_string(const char* s);
    string substring(const int& start, const int& end) const;

    bool operator==(const string& other);
    bool operator<(const string& other);
};

string::string(){
    len = 0;
    mem_capacity = 10;
    str = new char[10];
    str[0] = '\0';
}

string::string(char c){
    len = 1;
    mem_capacity = 10; // 최소값으로 10 을 할당합니다.
    str = new char[2];
    str[0] = c;
    str[1] = '\0';
}

string::string(const char* c){
    len = std::strlen(c);
    mem_capacity = std::max(len*2, 10); // 기본적으로 문자열의 2배 길이를 할당합니다.
    str = new char[len+1];
    strcpy(str, c);
}

string::string(const string& other){
    len = other.len;
    mem_capacity = std::max(len*2, 10);
    str = new char[other.len+1];
    strcpy(str, other.str);
}


string::~string(){
    delete[] str;
}

int string::strlen() const{
    return len;
}

int string::capacity() const{
    return mem_capacity;
}

void string::print() const{
    std::cout << str << std::endl;
}

void string::info() const{
    std::cout << "content : " << str << ", length : " << len << ", capacity : " << mem_capacity << std::endl;
}

string& string::assign(const char* str) {
    int str_len = std::strlen(str);
    if(mem_capacity < str_len + 1) {
        delete[] this->str; // 메모리가 부족한 경우 재 할당 해야한다.
        mem_capacity = std::max(str_len * 2, 10);
        this->str = new char[mem_capacity];
    }
    len = str_len;
    for(int i=0;i<len;i++){
        this->str[i] = str[i];
    } 
    this->str[len] = '\0';
    return *this;
}

string& string::assign(const string& str){
    int str_len = str.strlen();
    if(mem_capacity < str_len + 1) {
        delete[] this->str; // 메모리가 부족한 경우 재 할당 해야한다.
        mem_capacity = std::max(str_len * 2, 10);
        this->str = new char[mem_capacity];
    }
    len = str_len;
    for(int i=0;i<len;i++){
        this->str[i] = str.str[i];
    } 
    this->str[len] = '\0';
    return *this;
}

string& string::insert(int pos, const string& s){
    if(pos < 0 || pos > len) return *this;  // 예외 핸들링 (아무 처리 안함))
    if(mem_capacity < len + s.len + 1) {
        mem_capacity = (len + s.len) * 2;
        char* new_str = new char[mem_capacity];
        for(int i=0;i<pos;i++){
            new_str[i] = str[i];
        }
        for(int i=1;i<=len-pos;i++){
            new_str[len + s.len - i] = str[len-i];
        }
        for(int i=0;i<s.len;i++){
            new_str[pos+i] = s.str[i];
        }
        new_str[len + s.len] = '\0';
        delete[] str;
        str = new_str;
    } else {
        for(int i=1;i<=len-pos;i++){
            str[len + s.len - i] = str[len-i];
        }
        for(int i=0;i<s.len;i++){
            str[pos+i] = s.str[pos+i];
        }
        str[len + s.len] = '\0';
    }
    len += s.len;
    return *this;
}

string& string::insert(int pos, const char* s){
    if(pos < 0 || pos > len) return *this;  // 예외 핸들링 (아무 처리 안함))
    int i_len = std::strlen(s);
    if(mem_capacity < len + i_len + 1) {
        mem_capacity = (len + i_len) * 2;
        char* new_str = new char[mem_capacity];
        for(int i=0;i<pos;i++){
            new_str[i] = str[i];
        }
        for(int i=1;i<=len-pos;i++){  
            new_str[len+i_len-i] = str[len - i];  
        }
        for(int i=0;i<i_len;i++){
            new_str[pos+i] = s[i];
        }
        new_str[len + i_len] = '\0';
        delete[] str;
        str = new_str;
    } else {
        for(int i=1;i<=len-pos;i++){  // 용량이 충분한 경우 먼저 insert 할 공간을 밀어낸다.
            str[len+i_len-i] = str[len - i];   // 뒤에서 부터 넣어줘야 한다.
        }
        for(int i=0;i<i_len;i++){ 
            this->str[pos+i] = s[i];
        }
        str[len + i_len] = '\0';
    }
    len += i_len;
    return *this;
}

string& string::erase(int pos, int num){
    len -= num;
    for(int i=0;i<len-num;i++){
        str[i+pos] = str[i+pos+num];
    }
    str[len] = '\0';
    return *this;
}

string& string::add_string(const string &s){
    if(mem_capacity < len + s.len + 1) {
        mem_capacity = (len + s.len) * 2;
        char* new_str = new char[len + s.len + 1];
        for(int i=0;i<len;i++){
            new_str[i] = str[i];
        }
        for(int i=0;i<s.len;i++){
            new_str[len+i] = s.str[i];
        }
        new_str[len + s.len] = '\0';
        delete[] str;
        str = new_str;
    } else {
        for(int i=0;i<s.len;i++){
            str[len+i] = s.str[i];
        }
    }
    len += s.len;
    return *this;
}

string& string::add_string(const char* s){
    int add_len = std::strlen(s);
    if(mem_capacity < len + add_len + 1) {
        mem_capacity = (len + add_len) * 2;
        char* new_str = new char[len + add_len + 1 ];
        for(int i=0;i<len;i++){
            new_str[i] = str[i];
        }
        for(int i=0;i<add_len;i++){
            new_str[len+i] = s[i];
        }
        new_str[len + add_len] = '\0';
        delete[] str;
        str = new_str;
    } else {
        for(int i=0;i<add_len;i++){
            str[len+i] = s[i];
        }
    }
    len += add_len;
    return *this;
}

string string::substring(const int& start, const int& end) const {
    int sub_len = end - start; 
    char* sub = new char[sub_len+1];
    for(int i=0;i<sub_len;i++){
        sub[i] = str[start+i];
    }
    sub[len] = '\0'; 
    string ret = string(sub); 
    return ret;
}

bool string::operator==(const string& other){
    if(len == other.len){
        for(int i=0;i<len;i++){
            if(str[i] != other.str[i]) return false;
        }
        return true;
    }
    return false;
}

bool string::operator<(const string& other){
    bool is_short_len = false;
    int short_len = other.len;
    if(len > other.len) short_len = len;
    else if(other.len > len) is_short_len = true; 
    for(int i=0;i<short_len;i++){
        char my_char = str[i];
        char other_char = other.str[i];
        if(my_char > other_char) return false; 
        else if(my_char < other_char)  return true;
    }
    return is_short_len;
}


int main(){
    // 생성자 검증
    string a = string('a'); 
    a.info();
    string b = string("abc"); 
    b.info();
    string c = a;
    c.info();

    // assign 함수 검증
    string d;
    d.assign(a);
    d.info();
    d.assign("Hello World");
    d.info();

    // insert 함수 검증
    d.insert(0, "I'm kihong. ");
    d.info();
    d.insert(12, string("It's nice to meet you! "));
    d.info();

    // erase 함수 검증
    string e = string("c++ is not fun");
    e.info();
    e.erase(7,4).info();

    // add_string 함수 검증
    e.add_string(" but difficult to learn").info();

}


