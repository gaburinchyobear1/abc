#include <iostream>
#include <thread> // std::this_thread::sleep_for
#include <chrono>

using namespace std;

int main()
{
    int count = 0;
    const int interval_ms = 1000; // 1초 = 1000 밀리초

    auto start = chrono::steady_clock::now();

    while (count < 100) {
        count++;
        auto now = chrono::steady_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()).count();

        std::cout << "카운트: " << count << ", 출력시간: " << elapsed << " 밀리초" << std::endl;

        // 루프 시작 시점과 현재 시점의 차이를 계산
        auto end = chrono::steady_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        // 1초가 경과하기 위해 남은 시간 계산
        int sleep_time = interval_ms - duration;
        if (sleep_time > 0) {
            this_thread::sleep_for(chrono::milliseconds(sleep_time));
        }

        // 다음 루프 시작 시간 설정
        start = chrono::steady_clock::now();
    }


}