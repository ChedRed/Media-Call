#pragma once
#include "incontrol.h"



struct vec2 { int x; int y; };
struct vec3 { int x; int y; int z; };



class SDL_Spine {
public:

SDL_Window * Window;
SDL_Renderer * Renderer;
SDL_Event e;
SDL_Spine();
void Spine_Init(const char * Name, vec2 WinDimensions, vec2 WinMinDimensions, SDL_WindowFlags winFlags);
void Spine_Render(SDL_Color Color);
void Spine_Quit();
std::string osname = "undefined";
};


inline SDL_Spine::SDL_Spine() {
    #ifdef _WIN32
        osname = "windows";
    #elif __APPLE__
        osname = "macosx";
        // SDL_SetPointerProperty(SDL_GetWindowProperties(window), "SDL.window.cocoa.window.ignoresMouseEvents", (void * )true);
    #elif __linux__
        osname = "linux";
    #elif __unix__
        osname = "Unix";
    #endif
}

inline void SDL_Spine::Spine_Init(const char * Name, vec2 WinDimensions, vec2 WinMinDimensions, SDL_WindowFlags winFlags) {
    SDL_CreateWindowAndRenderer(Name, WinDimensions.x, WinDimensions.y, winFlags, &Window, &Renderer);
    SDL_SetWindowMinimumSize(Window, WinMinDimensions.x, WinMinDimensions.y);
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
    SDL_RenderClear(Renderer);
}

inline void SDL_Spine::Spine_Render(SDL_Color Color) {
    SDL_RenderPresent(Renderer);
    SDL_SetRenderDrawColor(Renderer, Color.r, Color.g, Color.b, Color.a);
    SDL_RenderClear(Renderer);
}

inline void SDL_Spine::Spine_Quit() {
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}
