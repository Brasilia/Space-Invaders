#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#include <time.h>

#include <Timer.h>

#include <Fighter.h>
#include <Enemy.h>
#include <Enemy_Troop.h>

#include <LevelHandler.h>
#include <FileHandler.h>
#include <TextHandler.h>
#include <Title.h>
#include <ranking.h>

#include <Screen.h>

using namespace std;

#define LEVEL_MAX 22

enum GameEstates{
    NULL_STATE,
    PRETITLE,
    TITLE,
    LEVELS,
    SCORE,
    MENU,
};


class Game
{
    public:
        LevelHandler level_handler;
        FileHandler* file_handler;
        TextHandler* text_handler;
        Fighter *fighter;
        Level* level;
        SDL_Surface *screen;
        Title* title;
        Ranking* ranking;
        int state;
        int cur_level;

        Game() {
            SDL_Init(SDL_INIT_EVERYTHING);
            Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );

            SDL_WM_SetCaption("Space Invaders - Rafael Miranda Lopes", NULL);

            putenv(strdup("SDL_VIDEO_CENTERED=1"));
            screen = SDL_SetVideoMode(Screen::WIDTH, Screen::HEIGHT, Screen::BPP, SDL_SWSURFACE);

            file_handler = new FileHandler();
            file_handler->load_images(screen);
            file_handler->load_sounds();

            fighter = new Fighter(Screen::PLAY_MIN_X+(Screen::PLAY_WIDTH - Screen::IMAGE_SIZE)/2, Screen::HEIGHT - Screen::IMAGE_SIZE - 16);

            cur_level = 1;
            level = new Level(cur_level);
            level_handler =  LevelHandler(fighter, level);

            LevelHandler::screen = screen;
            text_handler = new TextHandler(screen);
            //LevelHandler::text = text_handler;
            title = new Title(screen);
            ranking = new Ranking(screen, fighter);
            state = TITLE;
        }

        void start(){
            //FPS Caps
            bool cap = true;
            Timer timer;
            //The event structure
            SDL_Event event;
            srand(time(NULL));

            //Wait for a quit
            bool quit = false;
            while (quit == false){
                timer.start();
                //Event Poll
                while(SDL_PollEvent(&event)){
                    //Quit the program
                    if (event.type == SDL_QUIT) quit = true;
                    //Key down
                    if(event.type == SDL_KEYDOWN){
                        if(event.key.keysym.sym == SDLK_ESCAPE) quit = true;
                        if(event.key.keysym.sym == SDLK_F6) cap = !cap;
                        if(event.key.keysym.sym == SDLK_KP0 ) level_handler.paused = !level_handler.paused;
                        if(event.key.keysym.sym == SDLK_F5) restart();
                    }
                }

                //State Machine
                switch(state){
                    case TITLE:
                        //If no music is playing, play the title music
                        if(Mix_PlayingMusic() == 0 ) Mix_PlayMusic( FileHandler::music[0], -1 );
//                        cout << "IN TITLE" << endl;
                        if(!title->handle()){
                            restart();
                            state = LEVELS;
                            Mix_HaltMusic();
                        }
                        break;
                    case LEVELS:
//                        cout << "LEVELS" << endl;
                        //cout << level_handler->is_finished() << endl;
                        //Still battling
                        if(!level_handler.is_finished()) level_handler.handle();
                        else{
                            //Won
                            if(level_handler.get_result()==1){
                                cur_level++;
                                //There are still levels to acomplish
//                                cout << cur_level << " x " << LEVEL_MAX << endl;
                                if (cur_level <= LEVEL_MAX){
                                    level->setup_level(cur_level);
                                    //delete[] level_handler;
                                    level_handler = LevelHandler(fighter,level);
                                }
                                //All levels are done
                                else{
                                    //Switch state to the highscore screen
//                                    cout << "All levels done" << endl;
                                    state = SCORE;
                                }

                            }
                            //Lost (-1)
                            else{
                                //Switch state to the highscore screen
                                state = SCORE;
                            }
                        }
                        break;
                    case SCORE:
                        Mix_HaltMusic();
//                        cout << "In score" << endl;
                        if(!ranking->handle()) state = TITLE;
                        break;
                }

//                cout << "flip" << endl;
                SDL_Flip(screen);

                //Caps the fps
                if(cap) while(timer.get_ticks() < 1000/Screen::FPS){/*Wait*/}
            }
        }


        void restart(){
            //*fighter = Fighter(Screen::PLAY_MIN_X+(Screen::PLAY_WIDTH - Screen::IMAGE_SIZE)/2, Screen::HEIGHT - Screen::IMAGE_SIZE - 16);
            fighter->setup(Screen::PLAY_MIN_X+(Screen::PLAY_WIDTH - Screen::IMAGE_SIZE)/2, Screen::HEIGHT - Screen::IMAGE_SIZE - 16);
            cur_level = 1;
            level->setup_level(cur_level);
            //delete[] level_handler;
            level_handler = LevelHandler(fighter, level);
            state = TITLE;
            Mix_HaltMusic();
        }


};

//int Game::types[5] = {0,1,2,3,4};
#endif // GAME_H
