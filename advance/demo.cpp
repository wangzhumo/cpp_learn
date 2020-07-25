#include "Complex.h"
#include <iostream>

int main(){
    Complex c(1.0,2.0);
    Complex x(2.0,4.0);

    Complex r = c + x;
    std::cout << "real = " << r.getReal() << "  image = " << r.getImage() << std::endl;
    return 0;
}