#pragma comment(lib, "OpenGL32.lib")

#include <GLFW/glfw3.h>
#include <iostream>

//x(x좌표) y(Y좌표) s(사이즈) m(질량) (rg)단위당 적용되는 중력

float player_x =  -0.7f, player_y = -0.5f, player_x_s =  25.0f/400.0f, player_y_s = 25.0f / 300.0f, player_m, box1_real_gravity ; //플레이어
//땅
float Rand_x = 0.0f, Rand_y = -250.0f / 300.0f, Rand_x_s = 1.0f, Rand_y_s = 50.0f/300.0f;
//벽
float high_wall_x = 1.0f, high_wall_y = -150.0f / 300.0f, high_wall_x_s = 25.0f/400.0f, high_wall_y_s = 50.0f/300.0f;
float low_wall_x = 2.0f, low_wall_y = -50.0f/300.0f, low_wall_x_s = 25.0f/400.0f, low_wall_y_s = 150.0f / 300.0f;
//벽의 속도 , 새로 스폰되는 벽의 위치
float wall_speed = 0.02f, wall_start = 1.0f;

float player_speed = 0.0f ; 





float base_gravity = 490.0f/30000.0f; //단위당 중력값
float plus_gravity; //중력가속도

float jump_Power = 0.09f; //점프할때 적용될 힘
float jump_Velocity; //현재 적용되는 점프 힘

bool is_box1_jump = true; //박스1이 공중에 떠있는지의 여부

bool jump1 = true; // 점프가 가능한지 여부


void player_graity() {
    
    player_speed -= base_gravity / 60.0f;
    
    if(!jump1)player_y += player_speed;
    
}

void move_wall() {
    high_wall_x -= wall_speed;
    low_wall_x -= wall_speed;

    if (high_wall_x <= -1.0f) high_wall_x = wall_start;
    if (low_wall_x <= -1.0f) low_wall_x = wall_start;
}


//질량을 구하고 질량에 즁력을 적용함(x크기,y크기,m질량)
//void find_mass(float x, float y, float m,float real_gravity) {
//    //m = x * y * 4;
//    m = (x * 2) * (y * 2);
//    real_gravity = m * base_gravity;
//    plus_gravity += real_gravity;
//}



//네모그리기
void Box_Draw(float x, float y, float x_s, float y_s) {
    glBegin(GL_QUADS);
    glVertex2f(x + x_s, y + y_s);
    glVertex2f(x + x_s, y - y_s);
    glVertex2f(x - x_s, y - y_s);
    glVertex2f(x - x_s, y + y_s);
    glEnd();
}



//박스 콜라이더
bool ground_isCollision(float x1, float y1, float x1_s, float y1_s, float x2, float y2, float x2_s, float y2_s)
{
    float left1 = x1 - x1_s;
    float right1 = x1 + x1_s;
    float top1 = y1 + y1_s;
    float bottom1 = y1 - y1_s;

    float left2 = x2 - x2_s;
    float right2 = x2 + x2_s;
    float top2 = y2 + y2_s;
    float bottom2 = y2 - y2_s;
    if (left1 < right2 && right1 > left2 && bottom1 < top2 && top1 > bottom2) {
        jump1 = true;
        player_speed = 0.0f;
        return true;
    }
    return false;
}

//플레이어와 벽이 충돌하면 종료
bool wall_isCollision(float x1, float y1, float x1_s, float y1_s, float x2, float y2, float x2_s, float y2_s)
{
    float left3 = x1 - x1_s;
    float right3 = x1 + x1_s;
    float top3 = y1 + y1_s;
    float bottom3 = y1 - y1_s;

    float left4 = x2 - x2_s;
    float right4 = x2 + x2_s;
    float top4 = y2 + y2_s;
    float bottom4 = y2 - y2_s;

    if (!(right3 < left4 || left3 > right4 || top3 < bottom4 || bottom3 > top4))
    {
        std::cerr << "충돌 발생! 게임 종료" << std::endl;
        exit(EXIT_FAILURE); // 프로그램 종료
    }

    return false;
}


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    //if (key == GLFW_KEY_D && action == GLFW_REPEAT)player_x += 0.01;
    //if (key == GLFW_KEY_A && action == GLFW_REPEAT)player_x -= 0.01;
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {
        if (jump1) {
            jump_Velocity = jump_Power; // 스페이스 바를 누르면 점프 파워 적용
            jump_Velocity -= player_speed;

            is_box1_jump = true;
            //plus_gravity = 0.0f;
            jump1 = false;
        }

       
        
    }
    if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE) {
         
        jump_Velocity = 0;
        
    }

}

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

int main()
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(800, 600, " Dino Run Copy Game", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    // 수직 동기화 (V-Sync) 설정
    glfwSwapInterval(1); // 0으로 설정하면 V-Sync 비활성화, 1로 설정하면 활성화 (기본값)

    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(135.0f / 255.0f, 206.0f / 255.0f, 235.0f / 255.0f, 1.0f);//하늘색
        glClear(GL_COLOR_BUFFER_BIT);


        glColor3f(1.0f, 0.0f, 1.0f); 
        Box_Draw(player_x, player_y, player_x_s+ 1.5/400.0f, player_y_s+ 1.5f/300.0f);//플레이어를 그리기
        glColor3f(1.0f, 0.0f, 0.0f); // 빨강
        Box_Draw(player_x, player_y, player_x_s, player_y_s);//플레이어를 그리기
        glColor3f(255.0f / 255.0f, 200.0f / 255.0f, 15.0f / 255.0f); // 황색
        Box_Draw(Rand_x, Rand_y, Rand_x_s, Rand_y_s);//땅 끄리기


        //find_mass(player_x_s, player_y_s, player_m,box1_real_gravity);//각각 질량에 중력을 적용함 (반드시 순서를 질량을 구하고 중력을 적용할것)

        
        if (is_box1_jump) {
            player_y += jump_Velocity;
            jump_Velocity +=player_speed; // 점프 힘이 중력에 의해 감소
            //player_y -= plus_gravity;   // 가속도중력적용
        }

        if (ground_isCollision(player_x, player_y, player_x_s, player_y_s, Rand_x, Rand_y, Rand_x_s, Rand_y_s))
        {
      
            player_y = Rand_y + Rand_y_s + player_y_s; // 박스1을 땅 위에 위치시킴
        }
        //std::cout << plus_gravity;
         

        glColor3f(1.0f, 1.0f, 0.0f); // 빨강
        Box_Draw(high_wall_x, high_wall_y, high_wall_x_s, high_wall_y_s);
        Box_Draw(low_wall_x, low_wall_y, low_wall_x_s, low_wall_y_s);

        move_wall();
        //벽과 충돌하면 프로그램 종료
        wall_isCollision(player_x,player_y,player_x_s,player_y_s,high_wall_x,high_wall_y,high_wall_x_s,high_wall_y_s);
         wall_isCollision(player_x, player_y, player_x_s, player_y_s, low_wall_x, low_wall_y, low_wall_x_s, low_wall_y_s);

        player_graity();




        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}