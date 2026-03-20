#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char *argv[])
{

    SDL_Window *window = SDL_CreateWindow("Testing", 500, 500, 0); // Skapar mitt fönster. Namn, bredd, höjd, flaggor.
    // int test = 0;

    SDL_Event buttonPressed;    

    while (1)
    {
        SDL_ShowWindow(window);        // Visa mitt fönster
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
