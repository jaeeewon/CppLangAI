// 1. 정사각형 그리기
// 크기, 표현, 알고리즘적인 단계

// 함수 단위의 과정: 입력 -> 출력
// 입력(한 변의 길이) -> 출력(콘솔에 네모 모양)

// ctrl + . -> 함수로 추출

// 2. 직사각형
// 3. 직각이등변삼각형
// 4. 피라미드
// 5. 다이아몬드

// 알고리즘 활용 능력 --> 코딩 테스트,, 자료구조 / 알고리즘
// 원 그리기 (원의 방정식, 좌표평면, 이중 for문 (i, j) -> 좌표처럼 다룰 수 있는가?, 원의 내부 판정)
// 파도 모양 그리기 (sin 함수의 방정식 -> 원과 비슷하게 영역에 대한 판정)
// 체크문양 그리기 (칸 별로 i + j = 짝수/홀수?)
// X자 그리기 (알아서 잘 해보기를..)

#include <iostream>

using namespace std;

char SQR = 'O';

void drawPyramid()
{
    int level;
    cout << "높이를 입력: ";
    cin >> level;

    for (int i = 0; i < level; i++)
    {
        for (int j = 0; j < level - 1 - i; j++, cout << ' ')
            // height - 1 - i
            ;
        for (int k = 0; k <= 2 * i; k++, cout << SQR)
            // 2 * i + 1
            ;
        cout << endl;
    }
}

void drawTriangle()
{
    int side;

    cout << "한 변의 길이를 입력: ";
    cin >> side;

    for (int i = 0; i < side; i++, cout << endl)
        for (int j = 0; j <= i; j++, cout << SQR)
            ;
}
void drawRectangle()
{
    int width, height;
    cout << "가로 세로 크기를 입력: ";

    cin >> width >> height;

    for (int h = 0; h < height; h++, cout << endl)
        for (int w = 0; w < width; w++, cout << SQR)
            ;
}

void drawSquare()
{
    int side;

    // 한 변의 길이 입력받기
    cout << "한 변의 길이를 입력: ";
    cin >> side;

    for (int i = 0; i < side; i++, cout << endl)
        // side번 수행
        for (int j = 0; j < side; j++, cout << SQR)
            // side^2번 수행
            ;
}

void drawDiamond()
{
    /**
     * i = 0 |    O // 공백 2칸 (n - 1 - i), 네모 1칸
     * i = 1 |   OOO
     * i = 2 |  OOOOO
     *
     *
     * i = 3 |   OOO // 공백 1칸, 네모 3칸
     * i = 4 |    O // 공백 2칸, 네모 1칸
     *
     * i = 0 ~ i = 2는 drawPyramid 그대로로
     */
    int level;
    cout << "높이를 입력: ";
    cin >> level;

    for (int i = 0; i < level; i++)
    {
        for (int j = 0; j < level - 1 - i; j++, cout << ' ')
            // height - 1 - i
            ;
        for (int k = 0; k <= 2 * i; k++, cout << SQR)
            // 2 * i + 1
            ;
        cout << endl;
    }

    // drawPyramid 이외의 부분
    // for loop 내부는 바꾸지 않음
    for (int i = level - 2; i >= 0; i--)
    {
        for (int j = 0; j < level - 1 - i; j++, cout << ' ')
            // height - 1 - i
            ;
        for (int k = 0; k <= 2 * i; k++, cout << SQR)
            // 2 * i + 1
            ;
        cout << endl;
    }
}

int main()
{
    return 0;
}
