#include <string>

class StudentID
{
private:
    std::string name;
    int idNumber;

    static int a; // 모든 StudentID들이 공유

    int *p;

public:
    StudentID();
    StudentID(std::string name, int idNumber, int n); // 클래스가 Object로 만들어질 때 값들을 설정해주기 위함
    ~StudentID();

    std::string getName();
    int getId();
};