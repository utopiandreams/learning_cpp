#include <iostream>

class Complex {
    double real;
    double img;

    private:
    double getNumber(const char* c, int s_idx, int e_idx){
        
    }

    public:
    Complex(): real(0), img(0) {};
    Complex(double a, double b): real(a), img(b) {};
    Complex(const char* c);

    Complex operator+(const Complex& c);
    Complex operator-(const Complex& c);
    Complex operator*(const Complex& c);
    Complex operator/(const Complex& c);
    Complex& operator=(const Complex& c); // 이건 디폴트로 만들어 주긴한다.

    void print(){ std::cout<< "(" << real << ", " << img << ")" << std::endl;  }
};

Complex::Complex(const char* c){
    int len = strlen(c);
    int i_idx = 0;
    int blank_idx = 0;
    for(int i=0;i<len;i++){
        if(c[i] == 'i') i_idx = i; 
    }
    if(!idx){
        
    }
    

}

Complex Complex::operator+(const Complex& c){
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex& c){
    Complex temp(real-c.real, img-c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c){
    Complex temp(real * c.real - real * c.img, real * c.img + c.real * img);
    return temp;
}
Complex Complex::operator/(const Complex& c){
    Complex temp((real * c.real + img * c.img) / (c.real * c.real + c.img * c.img), (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}
Complex& Complex::operator=(const Complex& c){
    real = c.real;
    img = c.img;
    return *this;
}

int main(){
    Complex a = Complex(3, 2);
    Complex b = Complex(6, 3);
    Complex c = a * b;
    Complex d = a/b;
    c.print();
    d.print();
}