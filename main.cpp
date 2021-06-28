#include <Game.h>

using namespace std;



int main(int argc, char* args[]){

    Game* game = new Game();
    game->start();

    //Quit SDL
    SDL_Quit();
    return 0;
}

















//const int SCREEN_WIDTH = 1280;
//const int SCREEN_HEIGHT = 720;
//const int SCREEN_BPP = 32;

//const int IMAGE_SIZE = 50;

//const int FPS = 120;







//    //SDL Images
//    SDL_Surface* screen = NULL;
//    SDL_Surface* fighter = NULL;
//    SDL_Surface* fighter_st2 = NULL;
//    SDL_Surface* fighter_st3 = NULL;
//    SDL_Surface* bullet = NULL;
//    SDL_Surface* enemy1 = NULL;
//    SDL_Surface* enemy2 = NULL;
//    SDL_Surface* enemy3 = NULL;
//    SDL_Surface* enemy4 = NULL;
//    SDL_Surface* explo1 = NULL;
//    SDL_Surface* explo2 = NULL;
//    SDL_Surface* explo3 = NULL;

    //Start SDL
//    SDL_Init(SDL_INIT_EVERYTHING);
    //Set up Screen
//    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    //Load Image
//    fighter = load_image("Resources/Fighter_bronze_50.1.png");
//    if (fighter == NULL) return -2;
//    fighter_st2 = load_image("Resources/Fighter_bronze_50.2.png");
//    if (fighter_st2 == NULL) return -2;
//    fighter_st3 = load_image("Resources/Fighter_gray_50.png");
//    bullet = load_image("Resources/Bullet2.png");
//    if (fighter_st2 == NULL) return -2;
//    enemy1 = load_image("Resources/Enemy01_purple_32.png");
//    enemy2 = load_image("Resources/Enemy01_copper_32.png");
//    enemy3 = load_image("Resources/Enemy01_green_32.png");
//    enemy4 = load_image("Resources/Enemy01_blue_32.png");
//    explo1 = load_image("Resources/Explosion03_mag.png");
//    explo2 = load_image("Resources/Explosion04_mag.png");
//    explo3 = load_image("Resources/Explosion05_mag.png");


    //int img_count = 11;
    //SDL_Surface* image_array[] = {fighter, fighter_st2, fighter_st3, bullet, enemy1, enemy2, enemy3, enemy4, explo1, explo2, explo3};
    //Game::image_set.assign(image_array, image_array+img_count);

    //Set the offset
//    SDL_Rect offset;
//    offset.x = (SCREEN_WIDTH-IMAGE_SIZE)/2;
//    offset.y = SCREEN_HEIGHT - IMAGE_SIZE - 1;

    //SDL_Delay(3000);

//    Fighter  *f1 = new Fighter(offset.x, offset.y);
    //Bullet *bullets = new Bullet[Bullet::CAP];
//    Bullet *bullets[Bullet::CAP];
//    for(int i = 0; i < Bullet::CAP; i++){
//        bullets[i] = new Bullet();
//    }


//    int types[5] = {0,1,2,3,4};
//    Enemy_Troop* troop = new Enemy_Troop(32, 32, types);

