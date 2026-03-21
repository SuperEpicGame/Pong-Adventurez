#include <SDL3/SDL.h>

SDL_FRect ball = {470, 370, 30, 30};

void renderBall(SDL_Renderer * renderer){
    SDL_RenderRect(renderer,&ball);
}