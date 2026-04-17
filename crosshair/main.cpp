#include <iostream>
#include <cassert>

#include "SDL.h"

namespace
{
constexpr uint16_t g_crosshairWidth = 2;
constexpr uint16_t g_crosshairHeight = 2;
} // namespace

int main(int argc, char* argv[])
{
    assert(SDL_Init(SDL_INIT_VIDEO) == 0 && "Couldn't initialize SDL VIDEO\n");


    SDL_Window* menuWindow = SDL_CreateWindow(
        "Crosshair",
        100,
        100,
        400,
        300,
        0);
    assert(menuWindow != nullptr && "Couldn't create SDL_CreateWindow()\n");


    SDL_DisplayMode monitorInfo;
    SDL_GetCurrentDisplayMode(0, &monitorInfo);

    uint16_t windowPosX = (monitorInfo.w - g_crosshairWidth) / 2;
    uint16_t windowPosY = (monitorInfo.h - g_crosshairHeight) / 2;

    SDL_Window *crosshairWindow = SDL_CreateWindow(
        "Crosshair",
        windowPosX,
        windowPosY,
        g_crosshairWidth,
        g_crosshairHeight,
        SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP);
    assert(crosshairWindow != nullptr && "Couldn't create SDL_CreateWindow()\n");



    //SDL_Surface *screen_surface = SDL_GetWindowSurface(window);
    //SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 255, 0, 0));
    //SDL_UpdateWindowSurface(window);

    SDL_Delay(20000);

    SDL_DestroyWindow(crosshairWindow);
    SDL_DestroyWindow(menuWindow);
    SDL_Quit();

    return 0;
}
