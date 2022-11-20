#include <iostream>

class Shape {
public:
    virtual double area() = 0;
};

class Circle: public Shape 
{
private:
    double dimension;
public:
    Circle(double m_dimension): 
        dimension(m_dimension) {}
    
    double area() {
        return 3.14 * dimension * dimension;
    }
};

class Triangle: public Shape 
{
private:
    double base, height;
public:
    Triangle(double m_base, double m_height): 
        base(m_base), height(m_height) {}
    
    double area() {
        return 0.5 * base * height;
    }
};

class Square: public Shape 
{
private:
    double side;
public:
    Square(double m_side): side(m_side) {}
    
    double area() {
        return side * side;
    }
};

int main() {
    Shape *shape[] = {
        new Circle(5),
        new Square(2),
        new Triangle(3,4)
    };
    
    for (unsigned i = 0; i < 3; i++) {
        std::cout << "area: " << shape[i]->area() << std::endl;
    }
}