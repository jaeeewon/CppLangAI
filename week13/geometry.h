class Shape
{
public:
    // virtual은 개형만, 상속받는 클래스에서 구현하는 virtual 함수
    virtual double area() const = 0;
};

class Circle : Shape
{
private:
    double _radius;

public:
    Circle(double radius) : _radius{radius} {};
    /**
     * const는 뭐지? "함수에다 적용하는 constant!"
     * constant: 수정하지 않겠다는 선언
     *
     * const int a = 0;
     * int read() { return a; }
     *
     * const int read(); << 리턴값이 const
     * int read() const << 변수의 수정이 일어나지 않는다를 표시
     * 시험에는 나오지 않슴미다 헤헤
     */
    //
    double area() const
    {
        return 3.14 * _radius * _radius;
    }
};

class Rectangle : Shape
{
private:
    double _width, _height; // 왜 _? "private에는 언더바 적는 정통, 별다른 의미는 없음"

public:
    Rectangle(double width, double height) : _width{width}, _height{height} {};
    double area() const
    {
        return _width * _height;
    }
};

// // Shape: 부모, Square: 자식
// class Square : Shape
// {
//     void info()
//     {
//         area();
//     }
// };