#include <iostream>
#include <SDL3/SDL.h>



struct vec2 { int x; int y; };
struct vec3 { int x; int y; int z; };



class SDL_Spine {
public:

SDL_Window * window;
SDL_Renderer * renderer;
SDL_Event e;
SDL_Spine();
void SDL_PInit(SDL_InitFlags initflags, const char * name, vec2 size, SDL_WindowFlags winflags);
void SDL_PRend();
void SDL_PQuit();
};


inline SDL_Spine::SDL_Spine() {

}

inline void SDL_Spine::SDL_PInit(SDL_InitFlags initflags, const char * name, vec2 size, SDL_WindowFlags winflags) {
    SDL_Init(initflags);
    SDL_CreateWindowAndRenderer(name, size.x, size.y, winflags, &window, &renderer);
    SDL_RenderClear(renderer);
}

inline void SDL_Spine::SDL_PQuit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
