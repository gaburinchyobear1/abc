#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

const int WIDTH = 800;
const int HEIGHT = 600;

const float SUN_RADIUS = 120.0f;
const float SUN_RADIUS_1 = 40.0f;
const float EARTH_SIDE = 20.0f;
const float MOON_RADIUS = 5.0f;

float earthRotationAngle = 0.0f;
float earthRevolutionAngle = 0.0f;
float moonRotationAngle = 0.0f;
float moonRevolutionAngle = 0.0f;

// 지구의 자전 및 공전 주기 변수
const float EARTH_ROTATION_PERIOD = 36.0f;
const float EARTH_REVOLUTION_PERIOD = 6.0f;

// 달의 자전 및 공전 주기 변수
const float MOON_ROTATION_PERIOD = 120.0f;
const float MOON_REVOLUTION_PERIOD = 120.0f;

const float SUN_ROTATION_PERIOD = 120.0f;





// 원 그리기 함수
void drawCircle(float x, float y, float radius, float angle) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; ++i) {
        glVertex2f(x + radius * cos((i + angle) * 3.14159265f / 180.0f), y + radius * sin((i + angle) * 3.14159265f / 180.0f));
    }
    glEnd();
}

//찌그러진 무늬
void drawCircle_1(float x, float y, float radius, float angle) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; ++i) {
        float cosVal = cos((i + angle) * 3.14159265f / 180.0f);
        float sinVal = sin((i + angle) * 3.14159265f / 180.0f);
        glVertex2f(x + radius * cosVal, y + 0.3f * radius * sinVal); // y 좌표에 0.5를 곱하여 찌그러지게 만듭니다.
    }
    glEnd();
}

//동그란 무늬
void drawCircle_2() {
    drawCircle((WIDTH / 2) - 60, HEIGHT / 2, 40, 0.0f);
   

}




// 별 모양 그리기 함수
void drawStar(float x, float y, float radius, float angle) {
    glColor3f(1.0f, 1.0f, 0.0f); // 흰색
    glPushMatrix(); // 현재 행렬 상태 저장
    glTranslatef(x, y, 0.0f); // 별 중심으로 이동
    glRotatef(angle * 180.0f / 3.14159265f, 0.0f, 0.0f, 1.0f); // 별 회전
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 5; ++i) {
        float starAngle = (i * 4 * 3.14159265f / 5) - 3.14159265f / 2;
        glVertex2f(radius * cos(starAngle), radius * sin(starAngle));
        starAngle = ((i + 0.5f) * 4 * 3.14159265f / 5) - 3.14159265f / 2;
        glVertex2f(radius * 0.5f * cos(starAngle), radius * 0.5f * sin(starAngle));
    }
    glEnd();
    glPopMatrix(); // 이전 행렬 상태 복원
}

// 태양 그리기 함수
void drawSun() {
    glColor3f(1.0f, 1.0f, 0.0f); // 노란색
    drawCircle(WIDTH / 2, HEIGHT / 2, SUN_RADIUS, 0.0f); 
    glColor3f(0.0f, 1.0f, 0.0f); 
    
    
    
}




// 지구 그리기 함수
void drawEarth() {
    glColor3f(0.0f, 0.0f, 1.0f); // 파란색
    float earthX = WIDTH / 2 + 200.0f * cos(earthRevolutionAngle); // 태양 주위를 공전하는 지구의 X 좌표
    float earthY = HEIGHT / 2 + 200.0f * sin(earthRevolutionAngle); // 태양 주위를 공전하는 지구의 Y 좌표
    glPushMatrix(); // 현재 행렬 상태 저장
    glTranslatef(earthX, earthY, 0.0f); // 지구 중심으로 이동
    glRotatef(earthRotationAngle * 180.0f / 3.14159265f, 0.0f, 0.0f, 1.0f); // 지구 회전
    glRectf(-EARTH_SIDE / 2, -EARTH_SIDE / 2, EARTH_SIDE / 2, EARTH_SIDE / 2); // 정사각형으로 지구를 그림
    glPopMatrix(); // 이전 행렬 상태 복원
}

// 달 그리기 함수
void drawMoon() {
    glColor3f(0.7f, 0.7f, 0.7f); // 회색
    float moonX = WIDTH / 2 + 200.0f * cos(earthRevolutionAngle) + 50.0f * cos(moonRevolutionAngle); // 지구 주위를 공전하는 달의 X 좌표
    float moonY = HEIGHT / 2 + 200.0f * sin(earthRevolutionAngle) + 50.0f * sin(moonRevolutionAngle); // 지구 주위를 공전하는 달의 Y 좌표
    drawStar(moonX, moonY, MOON_RADIUS, moonRotationAngle * 180.0f / 3.14159265f); // 별 모양으로 달을 그림
}

// 화면 그리기 함수
void draw() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT); // 이전의 그림을 지움
    drawSun(); // 태양 그리기
    //태양무늬1
    drawCircle_1((WIDTH / 2) + 60, (HEIGHT / 2) + 60, 40, 45.0f); // 45도 회전하여 출력
    //태양무늬2
    drawCircle_2();
    
    drawEarth(); // 지구 그리기
    drawMoon(); // 달 그리기


}

// 업데이트 함수
void update() {
    earthRotationAngle += (36.0f / EARTH_ROTATION_PERIOD) * (1.0f / 60.0f); // 지구의 자전
    earthRevolutionAngle += (0.60f / EARTH_REVOLUTION_PERIOD) * (1.0f / 60.0f); // 지구의 공전ㄴ


    moonRotationAngle -= (120.0f / MOON_ROTATION_PERIOD) * (1.0f / 60.0f);;   // 달의 자전
    moonRevolutionAngle -= (120.0f / MOON_REVOLUTION_PERIOD) * (1.0f / 60.0f);;  // 달으ㅟ 공전

    

}

int main() {
    GLFWwindow* window;

    if (!glfwInit()) // GLFW 초기화
        return -1;

    window = glfwCreateWindow(WIDTH, HEIGHT, "태양계", NULL, NULL); // 윈도우 생성
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); // 현재 컨텍스트를 윈도우로 설정

    glOrtho(0, WIDTH, HEIGHT, 0, 0, 1); // 2D 좌표 시스템 설정

    while (!glfwWindowShouldClose(window)) {
        update(); // 업데이트
        draw(); // 그리기
        glfwSwapBuffers(window); // 버퍼 교체
        glfwPollEvents(); // 이벤트 처리
    }

    glfwTerminate(); // GLFW 종료
    return 0;
}