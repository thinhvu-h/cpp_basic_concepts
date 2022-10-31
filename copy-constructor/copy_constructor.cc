#include <iostream>

class base {
private:
    int data1, data2, *p;
public:
    base() {
        std::cout << "constructor" << std::endl;
        p = new int;
    }
    
    // copy constructor -> it is responsible for deep copy.
    base(base& b) {
        std::cout << "copy constructor" << std::endl;
        data1 = b.data1;
        data2 = b.data2;
        p = new int;
        *p = *(b.p);
    }

    void display() {
        std::cout << "data1: " << data1 << " ,data2: " << data2 << " ,p: " << *p << std::endl;
    }
    void getvalues(int a, int b, int c) {
        data1 = a;
        data2 = b;
        *p = c;
    }
};

int main() {
    base obj1;
    obj1.getvalues(10, 20, 30);
    obj1.display();

    // copy constructor (created by compiler) will came in action here.
    base obj2 = obj1;
    obj2.display();
    obj2.getvalues(10, 20, 40);

    obj1.display();
    obj2.display();
}