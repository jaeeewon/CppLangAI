#include <string>
#include <iostream>
#include "StudentID.h"

// 기본 생성자
StudentID::StudentID()
{
    name = "John Wick";
    idNumber = 20001;
}

// 오버로딩
StudentID::StudentID(std::string name, int idNumber, int n)
{
    // 입력으로 들어온 변수들을 class field에 할당
    this->name = name; // name은 가장 가까운 애 -> 구분을 위해 this 키워드를 이용해 명시적으로 나타냄
    // 이름이 다를 경우에는 this를 안 써도 됨

    if (idNumber > 0)
        this->idNumber = idNumber;

    p = new int[n];
    /**
     * 50개짜리 int 배열이 만들어지고, 그 포인터가 p에 들어감
     * 모든 배열은 포인터로
     * 지금까지 불가능했던
     * stack 메모리에서는 개수가 **상수로** 정해졌어야
     * but, new 키워드로 동적 할당을 진행하면
     * 코드가 실행될 때 몇 개를 사용할지 지정 가능
     * Heap 메모리 영역에
     *
     * ** 나중에 반드시 반환해줘야 **
     * -> delete
     *
     * 사용이 다 끝나면 delete[] p(리턴) 해줘야
     * 그렇지 않으면 메모리 누수
     *
     * 최대한 이런 코드 안 쓰는 게 좋음
     * 동적인 배열 쓸 거면 std::vector을 쓰는 게
     *
     * 꼭 필요하면 new, delete!!!!!!!!!!!!!
     *
     * unique_ptr, shared_ptr
     * 포인터를 class 형태로 만든 것
     * 이 포인터를 통해 동적 할당을 받을 때 생성자(동적 할당), 소멸자(반환) 호출하도록
     */
}

/**
 * 조금 더 간단히 생성자 정의
 * StudentID::StudentID(std::string name, int idNumber):
 *      name{name}, idNumber{idNumber} {};
 */

// 동적 할당 등의 과정에서 자원 반납 등의 코드
StudentID::~StudentID()
{
    delete[] p;
    std::cout << "This object is deleted." << std::endl;
}

std::string StudentID::getName()
{
    return this->name;
}

int StudentID::getId()
{
    return this->idNumber;
}