#include <iostream>
#include <cstring>

class string {
    char* str;
    int len;

    public:
        string(char c, int n);
        string(const char *c);
        string(const string &s);
        ~string();

    void add_string(const string &s);
    void copy_string(const string &s);
    int strlen();
};

string::string(char c, int n){
    len = n;
    str = new char[n];
    for(int i=0;i<n;i++){
        str[i] = c;
    }
    str[len] = '\0';
}

string::string(const char* c){
    len = std::strlen(c);
    str = new char[len+1];
    strcpy(str, c);
}

string::string(const string &s){
    len = s.len;
    str = new char[len+1];
    str = strcpy(str, s.str);
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


