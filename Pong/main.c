#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"
#include "SDL_ttf.h"
#include "Game.h"



int main(int argc, char* argv[])
{

    int Inputplayer1 =200;
    int Inputplayer2 =200;
    gameState state;
    game mygame;
    font mFont;

    if(init("PING",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&mygame,&mFont)){
        state.g_bRunning=1;
    }else{
        return 1;
    }

    mygame.g_pRenderer = SDL_CreateRenderer(mygame.g_pWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(mygame.g_pRenderer, 0, 0, 0, 255);

    while(state.g_bRunning){
        handleEvents(&state,&Inputplayer1,&Inputplayer2);
        SDL_RenderClear(mygame.g_pRenderer);
       // printf("%d\n",Inputplayer1);
        SDL_Rect rectPlayeur1;
        rectPlayeur1.x = 0;
        rectPlayeur1.y = 200;
        rectPlayeur1.w = 50;
        rectPlayeur1.h = 100;

        SDL_SetRenderDrawColor(mygame.g_pRenderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(mygame.g_pRenderer, &rectPlayeur1);
        SDL_RenderFillRect(mygame.g_pRenderer, &rectPlayeur1);
        SDL_SetRenderDrawColor(mygame.g_pRenderer, 0, 0, 0, 255);
        SDL_RenderPresent(mygame.g_pRenderer);
        SDL_RenderPresent(mygame.g_pRenderer);

        SDL_Rect rectPlayeur2;
        rectPlayeur2.x = 590;
        rectPlayeur2.y = 200;
        rectPlayeur2.w = 50;
        rectPlayeur2.h = 100;

        SDL_SetRenderDrawColor(mygame.g_pRenderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(mygame.g_pRenderer, &rectPlayeur2);
        SDL_RenderFillRect(mygame.g_pRenderer, &rectPlayeur2);
        SDL_SetRenderDrawColor(mygame.g_pRenderer, 0, 0, 0, 255);
        if (Inputplayer1 <= 0){
            Inputplayer1=0;
            }
        if (Inputplayer2 <= 0){
            Inputplayer2=0;
            }
        if (Inputplayer1 >= 400){
            Inputplayer1=400;
            }
        if (Inputplayer2 >= 400){
            Inputplayer2=400;
            }

        SDL_RenderPresent(mygame.g_pRenderer);

        }




    SDL_DestroyRenderer(mygame.g_pRenderer);
    SDL_DestroyWindow(mygame.g_pWindow);
    SDL_Quit();//on quitte la SDL
    return 0;
}




int init(char *title, int xpos,int ypos,int height, int width,int flags,game *myGame, font *mFont){



    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
    {
            myGame->g_pWindow=SDL_CreateWindow(title,xpos,ypos,height,width,flags);
            printf("Window created");
            if(myGame->g_pWindow!=NULL){
                myGame->g_pRenderer=SDL_CreateRenderer(myGame->g_pWindow,-1,SDL_RENDERER_ACCELERATED);

            }

    }else{


        return 0;
    }

    /*if(TTF_Init() == -1)
    {
        printf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    mFont->g_font=TTF_OpenFont("./Fonts/verdana.ttf",65);

    if(!mFont->g_font) {    printf("%d",Inputplayer1);
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        SDL_Delay(5000);
        exit(EXIT_FAILURE);
    }

     SDL_Color fontColor={255,0,0};

     myGame->g_surface=TTF_RenderText_Blended(mFont->g_font, "PONG", fontColor);//Charge la police*/


    return 1;


}


void handleEvents(gameState *state, int *Inputplayer1, int *Inputplayer2){

    SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
              state->g_bRunning=0;break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
                    {
                    case SDLK_z: Inputplayer1 = Inputplayer1-10 ; break;
                    case SDLK_s: Inputplayer1 = Inputplayer1+10 ; break;
                    case SDLK_UP: Inputplayer2 = Inputplayer2-10 ; break;
                    case SDLK_DOWN: Inputplayer2 = Inputplayer2+10; break;
                    case SDLK_ESCAPE: state->g_bRunning = 0;break;

                }break;

        default:break;
        }
    }
}



