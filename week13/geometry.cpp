#include "geometry.h"
#include <iostream>
#include <vector>

int main()
{
    // Shape를 상속받는 두 Circle, Rectangle
    Circle c1 = Circle(1.5);
    std::cout << c1.area() << std::endl;

    Rectangle r1 = Rectangle(2.0, 3.0);
    std::cout << r1.area() << std::endl;

    // vector에 Circle도.. Rectangle도 넣고 싶어!
    std::vector<Shape> v1;
    v1.emplace_back(Circle(2.5));
    v1.emplace_back(Rectangle(2.0, 5.0));
    // Shape라는 vector가 존재, Circle과 Rectangle을 Shape로 type casting (Shape로 취급)

    for (const auto &i : v1)
    {
        std::cout << i.area() << std::endl;
    }

    return 0;
}