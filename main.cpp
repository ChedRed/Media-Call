#include "main.h"
#include <X11/Xlib.h>


int w, h;
bool loop = true;

/* Program main */
int main() {
    SDL_Spine app;


    app.SDL_PInit("Media Call", { 720, 425 }, { 720, 425 }, SDL_INIT_VIDEO, SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_UTILITY);
    while (loop) {
        while (SDL_PollEvent(&app.e) != 0) {
            switch (app.e.type) {
                case SDL_EVENT_QUIT:
                    loop = false;
                    break;

                case SDL_EVENT_WINDOW_RESIZED:
                    SDL_GetWindowSize(app.window, &w, &h);
                    break;
            }
        }

        app.SDL_PRend({ 32, 32, 32, 255 });
    }

    app.SDL_PQuit();

    return 0;
}
