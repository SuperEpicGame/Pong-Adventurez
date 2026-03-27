#include <SDL3/SDL.h>
#include <math.h>
#include "ball.h"
#include "player.h"


float ballVelX = 4.0f; // hastighet
float ballVelY = 0.0f;
int startCounter = 0;

void checkCollision()
{

    if (ballVelX < 0 && SDL_HasRectIntersectionFloat(&ball, &rectangle1)) // Har bollen träffat p1?
    {
        startCounter = 1;
        int relY = rectangle1.y;

        if(relY + rectangle1.h/3 >= ball.y) 
        {
            ballVelX = -ballVelX;
            ballVelY = -1.0f;
        }
        else if(relY + 2*(rectangle1.h/3) >= ball.y) 
        {
            ballVelX = -ballVelX;
            ballVelY = 0;
        }
        else if(relY + rectangle1.h >= ball.y) 
        {
            ballVelX = -ballVelX;
            ballVelY = 1.0f;
        }
        

        // ballVelX = -ballVelX;           //bounce right
    }

    else if (ballVelX > 0 && SDL_HasRectIntersectionFloat(&ball, &rectangle2)) // Har bollen träffat p2?
    {
        startCounter = 1;
        int relY = rectangle2.y;
        if(relY + rectangle2.h/3 >= ball.y) 
        {
            ballVelX = -ballVelX;
            ballVelY = -1.0f;
        }
        else if(relY + 2*(rectangle2.h/3) >= ball.y) 
        {
            ballVelX = -ballVelX;
            ballVelY = 0;
        }
        else if(relY + rectangle2.h >= ball.y) 
        {
            ballVelX = -ballVelX;
            ballVelY = 1.0f;
        }
        
    }
}
