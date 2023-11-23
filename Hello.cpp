#include "raylib.h"

int main() 
{
    int width{2000};
    int height{1000};
    InitWindow(width, height, "Run!");

    //Circle Area
    int Circle_x{200};
    int Circle_y{125};
    int Circle_r{40};

    //Circle Collision Edges
    int L_Circle{Circle_x - Circle_r};
    int R_Circle{Circle_x + Circle_r};
    int U_Circle{Circle_y - Circle_r};
    int B_Circle{Circle_y + Circle_r};

    //Rectangle Area
    int Rect_x{120};
    int Rect_y{300};
    int Rect_h{100};
    int Rect_l{100};

    //Rectangle Collision Edges
    int L_Rect{Rect_x};
    int R_Rect{Rect_x + Rect_l};
    int U_Rect{Rect_y};
    int B_Rect{Rect_y + Rect_h};

    int Direction = 5;

    bool collisionWithRectangle = 
                            (B_Rect >= U_Circle) && 
                            (U_Rect <= B_Circle) &&
                            (L_Rect <= R_Circle) &&
                            (R_Rect >= L_Circle);

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

    if (collisionWithRectangle)
    {
        DrawText ("Game Over!", 1000, 500, 100, RED);
    }
    else
    {
    
        //Updates edges for moving edges
        L_Circle = Circle_x - Circle_r;
        R_Circle = Circle_x + Circle_r;
        U_Circle = Circle_y - Circle_r;
        B_Circle = Circle_y + Circle_r;
        L_Rect = Rect_x;
        R_Rect = Rect_x + Rect_l;
        B_Rect = Rect_y + Rect_h;
        U_Rect = Rect_y;
        // update collision with Rectangle
        collisionWithRectangle = 
                            (B_Rect >= U_Circle) && 
                            (U_Rect <= B_Circle) &&
                            (L_Rect <= R_Circle) &&
                            (R_Rect >= L_Circle);

        DrawCircle(Circle_x, Circle_y, Circle_r, GREEN);

        if (IsKeyDown(KEY_D) && Circle_x < width)
        {
            Circle_x += 10;
        }
         if (IsKeyDown(KEY_A) && Circle_x > (width - width))
         {
            Circle_x -= 10;
         }
        if (IsKeyDown(KEY_S) && Circle_y < height)
        {
            Circle_y += 10;
        }
        if (IsKeyDown(KEY_W) && Circle_y > (height - height))
         {
            Circle_y -= 10;
         }

        DrawRectangle(Rect_x, Rect_y, Rect_l, Rect_h, BLUE);
        Rect_y += Direction;
        if (Rect_y > 1000 || Rect_y < 0)
        {
            Direction = -Direction;
        }
    }
       EndDrawing();
    }
} 

//DrawRectangle(Rect_x, Rect_y, 200, Rect_h, BLUE);
//       if (IsKeyDown(KEY_S) && Rect_y < 800)
//        {
//            Rect_y += 10;
//        }
//         if (IsKeyDown(KEY_W) && Rect_y > 0)
//        {
//            Rect_y -= 10;
//         }