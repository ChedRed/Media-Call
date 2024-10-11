#include "main.h"
#include <X11/Xlib.h>


float Scale = .2;


bool Loop = true;

/* Program main */
int main() {
    SDL_Spine App;


    App.Spine_Init("Media Call", { 720, 425 }, { 720, 425 }, SDL_INIT_VIDEO, SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_UTILITY);
    while (Loop) {
        while (SDL_PollEvent(&App.e) != 0) {
            switch (App.e.type) {
                case SDL_EVENT_QUIT:
                    Loop = false;
                    break;
            }
        }

        App.Spine_Render({ 32, 32, 32, 255 });
    }

    App.Spine_Quit();

    return 0;
}
