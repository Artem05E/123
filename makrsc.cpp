#include <iostream>
#define CREATE_FUNCTION(name, value) \
    int fun_##name() { return value; }

CREATE_FUNCTION(abcd, 12)

int main() {
    std::cout << "fun_abcd(): " << fun_abcd() << std::endl;
    
    return 0;
}
