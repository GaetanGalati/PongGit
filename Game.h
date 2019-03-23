#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
typedef struct game{


     SDL_Window *g_pWindow;
     SDL_Renderer *g_pRenderer;
     SDL_Texture *g_texture;
     SDL_Surface *g_surface;


}game;
typedef struct font{

    TTF_Font *g_font;

}font;
typedef struct gameState{

    int g_bRunning;


}gameState;
SDL_Window* SDL_CreateWindow(const char* title,
                              int         x,
                              int         y,
                              int         w,
                              int         h,
                              Uint32      flags);
int SDL_SetRenderTarget(SDL_Renderer* renderer, SDL_Texture*  texture);
int SDL_RenderDrawRect(SDL_Renderer*   renderer,
                   const SDL_Rect* rect);
int init(char *title, int xpos,int ypos,int height, int width,int flags,game *myGame,font *mFont);
void handleEvents(gameState *state, int *Inputplayer1, int *Inputplayer2);

#endif // GAME_H_INCLUDED
