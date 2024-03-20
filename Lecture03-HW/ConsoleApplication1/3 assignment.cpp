#include <iostream>
using namespace std;



enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

int main()
{
    cout << "화면에 그림을 그리는 프로그랩입니다. \n학번:202127013\n이름:양문혁\n";
    int code;
    

    while (true)
    {
        cout << "입력---";
        cin >> code;
        if (code & 0b01)
        {
            cout << "\x1b[037m";
            for (int i = 0;i < 5;i++) {
                for (int j = 0;j < 5;j++) {
                    printf("*");
                }
                printf("\n");
            }
        }

        if (code & 0b10)
        {
            cout << "\x1b[031m";
            for (int i = 0;i < 5;i++) {
                for (int j = 0;j < 5;j++) {
                    printf("*");
                }
                printf("\n");
            }
        }

        if (code & 0b100)
        {
            cout << "\x1b[032m";
            for (int i = 0;i < 5;i++) {
                for (int j = 0;j < 5;j++) {
                    printf("*");
                }
                printf("\n");
            }
        }

        if (code & 0b1000)
        {
            cout << "\x1b[033m";
            for (int i = 0;i < 5;i++) {
                for (int j = 0;j < 5;j++) {
                    printf("*");
                }
                printf("\n");
            }
        }

        if (code & 0b10000) {
            cout << "\x1b[034m";
            for (int i = 0;i < 5;i++) {
                for (int j = 0;j < 5;j++) {
                    printf("*");
                }
                printf("\n");
            }
        }

        if (code & 0b100000) {
            cout << "\x1b[035m";
            for (int i = 0;i < 5;i++) {
                for (int j = 0;j < 5;j++) {
                    printf("*");
                }
                printf("\n");
            }


        }

       
        if (code == 64) {
            break;
       }
    }


    
 


}












/* {
    int code;
    std::cout << "입력";
    std::cin >> code;


    std::cout << "\x1b[" << code << "m" << "아름다운 색!! 우왕" << std::endl;

    return 0;
}
*/
