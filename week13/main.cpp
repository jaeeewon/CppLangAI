#include "StudentID.h"
#include <iostream>

// 의도대로 되지 않음
void foo()
{
    int counter = 0;
    ++counter;
    std::cout << counter << std::endl;
    return;
}

void bar()
{
    // static: 현재 소스 파일에서 항상 존재하게 하겠다!
    // 함수가 종료되고도 계속 존재
    // 두 번째 bar 함수 실행시 초기화 미진행
    static int counter = 0; // 처음 실행할 때 0으로 초기화
    ++counter;
    std::cout << counter << std::endl;
    return;
}

int main()
{
    StudentID student1 = StudentID("David", 2025123123, 0);
    // std::cout << student1.name << std::endl; // 컴파일 불가: StudentID::name이 private -> 외부에서 접근 불가능
    std::cout << student1.getName() << std::endl; // StudentID::getName이 public -> 외부에서 호출 가능
    std::cout << student1.getId() << std::endl;

    StudentID student2 = StudentID("David", 2025123123, 0); // a를 공유
    StudentID student3 = StudentID("David", 2025123123, 0); // a를 공유

    // foo();
    // foo();
    // foo();
    // foo();
    // foo();
    // // 1만 계속 출력

    // bar(); // 1
    // bar(); // 2
    // bar(); // 3
    // bar(); // 4
    // bar(); // 5

    return 0;
}