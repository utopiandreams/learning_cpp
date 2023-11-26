#include <iostream>
#include <cstring>

// 1. 문자(char) 로 부터의 문자열 생성, C 문자열 (char *) 로 부터의 생성
// 2. 문자열 길이를 구하는 함수
// 3. 문자열 뒤에 다른 문자열 붙이기
// 4. 문자열 내에 포함되어 있는 문자열 구하기
// 5. 문자열이 같은지 비교
// 6. 문자열 크기 비교 (사전 순)

class string {
    char* str;
    int len;

    public:
    string(char c);
    string(const char *c);
    ~string();

    int strlen();
    void add_string(const string &s);
    char* substring(const string &s);
    bool operator==(const string& other);
    bool operator<(const string& other);
};

string::string(char c){
    len = 1;
    str = new char[2];
    str[0] = c;
    str[1] = '\0';
}

string::string(const char* c){
    len = std::strlen(c);
    str = new char[len+1];
    strcpy(str, c);
}


string::~string(){
    delete[] str;
}

void string::add_string(const string &s){
    len += s.len;
    char* newStr = new char[len + s.len + 1];
    std::strcpy(newStr, str);
    std::strcpy(newStr + len, s.str);
    delete[] str;
    str = newStr;
}

void string::copy_string(const string &s){
    len = s.len;
    char* newStr = new char[len+1];
    std::strcpy(newStr, s.str);
    delete[] str;
    str = newStr;
}

int string::strlen(){
    return len;
}

int main(){
    char* a = new char[100];
    std::cout << "문자열 1 입력 : " << "\n";
    std::cin >> a;
    string my_str(a);
    std::cout << "문자열 2 입력 : " << "\n";
    std::cin >> a;
    my_str.add_string(a);
    std::cout << "1 + 2 : " << my_str.strlen() << "\n";
}


