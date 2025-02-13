#include "main.h"
#include "osmedia.h"


float Scale = .2;
SDL_Rect DPBounds;
bool Loop = true;

/* Program main */
int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GetDisplayBounds(0, &DPBounds);
    SDL_Spine App;


    App.Spine_Init("Media Call", { 720, 425 }, { 0, 0 }, SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_NOT_FOCUSABLE | SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_BORDERLESS);
    while (Loop) {
        while (SDL_PollEvent(&App.e) != 0) {
            switch (App.e.type) {
                case SDL_EVENT_QUIT:
                    Loop = false;
                    break;
            }
        }

        App.Spine_Render({ 32, 32, 32, 255 });
        SDL_Delay(1000);
    }

    App.Spine_Quit();

    return 0;
}


#ifdef _WIN32
/* Windows window subsystem :( */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    return main(__argc, __argv);
}
#endif
