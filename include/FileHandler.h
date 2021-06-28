#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <simpleSDLfunctions.h>
#include <Screen.h>
#include <sstream>
#include <string>

//#define IMAGE_ARR_SIZE 19


enum Images{
    BACKGROUND,
    FIGHTER1,
    FIGHTER2,
    FIGHTER3,
    FIGHTER4,
    ENEMY1,
    ENEMY2,
    ENEMY3,
    ENEMY4,
    ENEMY5,
    BULLET1,
    BULLET2,
    BARRIERUNIT,
    SHIELD,
    HUD,
    VICTORY,
    DEFEAT,
    EXPLOSION1,
    EXPLOSION2,
    EXPLOSION3,
    IMG_ARR_SIZE,
};


class FileHandler
{
    public:
        static SDL_Surface* image_set[IMG_ARR_SIZE];
        static Mix_Music* music[2];
        static Mix_Chunk* se[7];

    public:
        FileHandler() {}

        void load_images(SDL_Surface* screen){
            for(int i=0; i<IMG_ARR_SIZE; i++){
                image_set[i] = NULL;
            }
            //Load Images
            //const int  EXPLOSION = 10;
            image_set[BACKGROUND] = load_image("Resources/bg.png");

            image_set[FIGHTER1] = load_image("Resources/Fighter_bronze_50.1.png");
            image_set[FIGHTER2] = load_image("Resources/Fighter_bronze_50.2.png");
            image_set[FIGHTER3] = load_image("Resources/Fighter_gray_50.png");
            image_set[FIGHTER4] = load_image("Resources/Fighter_bronze_50.2_dead.png");

            image_set[ENEMY1] = load_image("Resources/Enemy01_purple_32.png");
            image_set[ENEMY2] = load_image("Resources/Enemy01_copper_32.png");
            image_set[ENEMY3] = load_image("Resources/Enemy01_green_32.png");
            image_set[ENEMY4] = load_image("Resources/Enemy01_blue_32.png");
            image_set[ENEMY5] = load_image("Resources/Enemy01_red_32.png");

            image_set[BULLET1] = load_image("Resources/Bullet2.png");
            image_set[BULLET2] = load_image("Resources/Bullet2_blue.png");

            image_set[BARRIERUNIT] = load_image("Resources/BarrierUnit.png");

            image_set[SHIELD] = load_image("Resources/Shield_blue.png");
            image_set[HUD] = load_image("Resources/HUD.png");
            image_set[VICTORY] = load_image("Resources/Victory.png");
            image_set[DEFEAT] = load_image("Resources/Defeat.png");

            image_set[EXPLOSION1] = load_image("Resources/Explosion03_mag.png");
            image_set[EXPLOSION2] = load_image("Resources/Explosion04_mag.png");
            image_set[EXPLOSION3] = load_image("Resources/Explosion05_mag.png");

        }

        SDL_Surface* load_title(){
            return load_image("Resources/Title2.png");
        }

        void load_sounds(){
            music[0] = Mix_LoadMUS("Resources/music/whistle01.wav");
            music[1] = Mix_LoadMUS("Resources/music/bass02.1.1.wav");
//            music[2] =
//            music[3] =

            //se[0] = Mix_LoadWAV("Resources/se/PANLASER.WAV");
//            se[1] = Mix_LoadWAV("Resources/se/87402^LASER-trimmed.wav");
//            se[2] = Mix_LoadWAV("Resources/se/87402^LASER-trimmed2.wav");
            se[3] = Mix_LoadWAV("Resources/se/30539^explosion.wav");
            se[4] = Mix_LoadWAV("Resources/se/Blast-SoundBible.com-2068539061.wav");
            se[5] = Mix_LoadWAV("Resources/me/victory.wav");
            se[6] = Mix_LoadWAV("Resources/me/sad.wav");


        }


};
SDL_Surface* FileHandler::image_set[IMG_ARR_SIZE];
Mix_Music* FileHandler::music[2];
Mix_Chunk* FileHandler::se[7];

#endif // FILEHANDLER_H
