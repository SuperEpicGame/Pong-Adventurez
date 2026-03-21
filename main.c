#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "player.h"
#include "ball.h"

int main(int argc, char *argv[])
{

    SDL_Window *window = SDL_CreateWindow("Pong", 1000, 800, 0); // Skapar mitt fönster. Namn, bredd, höjd, flaggor.

    SDL_ShowWindow(window);        // Visa mitt fönster

    SDL_Event buttonPressed;    
    SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(window, 0);
    
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,0,0,255);

    renderPlayer(renderer);
    renderBall(renderer);
    SDL_RenderPresent(renderer);
    
    //SDL_SetWindowIcon();

    while (1)
    {
        SDL_PollEvent(&buttonPressed); // Pollad lösning: har något hänt?
        // scanf("%d", &test);
        // SDL_PollEvent(SDL_EVENT_TEXT_INPUT);

        if (buttonPressed.type == SDL_EVENT_QUIT || buttonPressed.key.key == 'q') // Trycker användaren på 'q' eller x
        {
            SDL_DestroyWindow(window); // Stäng fönster
            SDL_Quit();                // Stäng program
            return 0;
        }
    }
}
