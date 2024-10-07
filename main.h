#pragma  once
#include <iostream>
#include <string.h>
#include <SDL3/SDL.h>



struct vec2 { int x; int y; };
struct vec3 { int x; int y; int z; };



class SDL_Spine {
public:

SDL_Window * window;
SDL_Renderer * renderer;
SDL_Event e;
SDL_Spine();
void SDL_PInit(const char * name, vec2 windimensions, vec2 winmindimensions, SDL_InitFlags initflags, SDL_WindowFlags winflags);
void SDL_PRend(SDL_Color color);
void SDL_PQuit();
std::string osname = "undefined";
};


inline SDL_Spine::SDL_Spine() {
    #ifdef _WIN32
        osname = "windows";
        // #include <windows.h>
    #elif __APPLE__
        osname = "macosx";
        // SDL_SetPointerProperty(SDL_GetWindowProperties(window), "SDL.window.cocoa.window.ignoresMouseEvents", (void * )true);
    #elif __linux__
        osname = "linux";
        // #include <X11/Xlib.h>
        // #include <X11/Xatom.h>
    #elif __unix__
        osname = "Unix";
    #endif
}

inline void SDL_Spine::SDL_PInit(const char * name, vec2 windimensions, vec2 winmindimensions, SDL_InitFlags initflags, SDL_WindowFlags winflags) {
    SDL_Init(initflags);
    SDL_CreateWindowAndRenderer(name, windimensions.x, windimensions.y, winflags, &window, &renderer);
    SDL_SetWindowMinimumSize(window, winmindimensions.x, winmindimensions.y);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
}

inline void SDL_Spine::SDL_PRend(SDL_Color color) {
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}

inline void SDL_Spine::SDL_PQuit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
