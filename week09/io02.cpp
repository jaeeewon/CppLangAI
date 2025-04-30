// 파일을 복사하는 프로그램

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    // ./io02.exe [src=argv[1]] [dest=argv[2]]

    // 파일을 복사
    // (1) 파일 읽어오기 - ifstream
    ifstream src(argv[1], ios::binary); // binary 모드로
    // (2) 읽은 데이터를 다른 파일에 쓰기기
    ofstream dst(argv[2], ios::binary);

    // 예외처리는 넘기쟝 헤헤

    dst << src.rdbuf(); // src의 파일 버퍼를 ofstream 버퍼에 써주기
    dst.close();        // flush

    return 0;
}