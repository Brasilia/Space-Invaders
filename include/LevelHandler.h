#ifndef LEVELHANDLER_H
#define LEVELHANDLER_H

#include <TextHandler.h>
#include <Level.h>
#include <Screen.h>

using namespace std;


//Processa cada level do jogo (o combate)
class LevelHandler
{
    private:
        Level* level;
        Fighter* fighter;
        Enemy_Troop* troop;
        Bullet* bullet[Bullet::CAP];
        int frame; //Might be used for special events like a special enemy
        int frame_aux;
        Uint8* keystate;
        int result;
        bool finished;
        int level_score;
        TextHandler *text;
        bool playing;
        //SDL_Surface* background;

    public:
        bool paused;

        LevelHandler(){}

        LevelHandler(Fighter* fighter, Level* level) {
            text = new TextHandler(screen);
            this->level = level;
            //The level hasn't been finished - until result presentation
            finished = false;
            //No results to the battle yet
            result = 0;
            //Game is not paused
            paused = false;
            //Level Scoure Counter
            level_score = 0;
            //Setup fighter
            this->fighter = fighter;
            //Setup enemy troop
            this->troop = level->troop;
            //Setup bullets
            for(int i = 0; i < Bullet::CAP; i++){
                bullet[i] = new Bullet();
            }
            //Setup frame counter
            frame = 0;
            frame_aux = frame;
            //Playing SE
            playing = false;
            if( Mix_PausedMusic() == 1 ) Mix_ResumeMusic();
            //Sets background
            //background = FileHandler::image_set[BACKGROUND];
        }

//        void setup_level(Level* level){
//
//        }


        void update_result(){
            if(!result){
                if (troop->is_destroyed()){
                    result = 1;
                }
                if (fighter->get_state() == 0  ||  troop->has_invaded()){
                    result = -1;
                }
            }
        }

        void display_result(){
            //SDL_Surface* result_image;
            int x, y;
            //Slow motion
            if(frame%5==0){
                //------------------ Handle Input
                handle_input();
                //------------------ Check collisions
                check_ship_collision();
                //------------------ Update
                update();
                //------------------ Draw
                draw();
            }
            x = (Screen::WIDTH-500)/2;
            y = (Screen::HEIGHT-250)/2;
            if(result == 1){
                //result_image = FileHandler::image_set[VICTORY]; //500x150
//                if (!playing){
//                    Mix_PauseMusic();
//                    Mix_PlayChannel(-1, FileHandler::se[5], 0);
//                    playing = true;
//                }
                TextHandler *victory_text = new TextHandler(screen, 80);
                victory_text->write_text(Screen::PLAY_MIN_X + Screen::PLAY_WIDTH/2, Screen::PLAY_HEIGHT/2 -80, "Good", 0.5);
                victory_text->write_text(Screen::PLAY_MIN_X + Screen::PLAY_WIDTH/2, Screen::PLAY_HEIGHT/2 +10, "Job!", 0.5);
                delete victory_text;
            }
            if(result == -1){
                //result_image = FileHandler::image_set[DEFEAT]; //500x150
                if (!playing){
                    Mix_HaltMusic();
                    Mix_PlayChannel(-1, FileHandler::se[3], 0);
                    playing = true;
                }
            }
            //apply_surface(x,y,result_image, screen);
            if(frame_aux < frame) frame_aux = frame + 3*Screen::FPS;
            if(frame == frame_aux) finished = true;
//            cout << "Frames: " << frame << " x " << frame_aux << endl << endl;
        }

        int get_result(){
            return result;
        }

        bool is_finished(){
            return finished;
        }

        void handle(){
            frame++;
            if(paused) return;
            //Checks if the game is not over yet
            update_result();
            if(result){
                display_result();
                return;
            }
            if(frame < 80){
                if (frame == 1) present_level();
            }
            else{
                //------------------ Handle Input
                handle_input();
                //------------------ Check collisions
                check_collisions();
                //------------------ Update
                update();
                //------------------ Draw
                draw();
            }
        }

        //Presents the level to begin
        void present_level(){
            if(Mix_PlayingMusic() == 0 ) Mix_PlayMusic( FileHandler::music[1], -1 );
            update();
            draw();
            std::ostringstream string;
            string << "Level ";
            string << level->levelNumber;
            TextHandler level_text = TextHandler(screen, 60);
            level_text.write_text(Screen::PLAY_MIN_X + Screen::PLAY_WIDTH/2, Screen::PLAY_HEIGHT/2 -50, string.str().c_str(), 0.5);
        }

        //Handles keyboard and virtual input - random input for enemy shooters
        void handle_input(){
            //Real (player) Input
            keystate = SDL_GetKeyState(NULL);
            if(fighter->get_state() != 0){
                if(keystate[SDLK_LEFT] || keystate[SDLK_a]){
                    fighter->move_left();
                }
                if(keystate[SDLK_RIGHT] || keystate[SDLK_d]){
                    fighter->move_right();
                }
                if(keystate[SDLK_SPACE]){
                    delete bullet[Bullet::get_counter()];
                    bullet[Bullet::get_counter()] = fighter->shoot();
                }
            }
            //Virtual (game) Input
            for (int m = 00; m<44; m++){
                if(rand()%(int)(3000/level->shootSpeedMod) == 0){
                    if(troop->enemy(m)->get_state() != 0){
                        delete bullet[Bullet::get_counter()];
                        bullet[Bullet::get_counter()] = troop->enemy(m)->shoot();
                    }
                }
            }
        }

        void check_collisions(){
            check_bullets_collision();
            check_ship_collision();
        }

        //Checks all the bullets against the ships and barriers
        void check_bullets_collision(){
            //Bullets collision
            for(int bul = 0; bul < Bullet::CAP; bul++){
                for(int en = 0; en < troop->size(); en++){
                    //Check bullet - enemy
                    if(troop->enemy(en)->collided(bullet[bul]) && bullet[bul]->get_dir_vertical() == -1){
                        //Score for the player
                        level_score += troop->enemy(en)->get_score() * level->scoreMod;
                        fighter->score += troop->enemy(en)->get_score() * level->scoreMod;
                        //Destroy the flying objects
                        bullet[bul]->kill();
                        troop->enemy(en)->kill();
                    }
                }
                //Check bullet - special enemy
                if(level->specialEnemy->collided(bullet[bul]) && bullet[bul]->get_dir_vertical() == -1){
                    //Score for the player
                    level_score += level->specialEnemy->get_score() * level->scoreMod;
                    fighter->score += level->specialEnemy->get_score() * level->scoreMod;
                    //Destroy the flying objects
                    bullet[bul]->kill();
                    level->specialEnemy->kill();
                }
                //Check bullet - fighter
                if(fighter->collided(bullet[bul]) && bullet[bul]->get_dir_vertical() == 1){
                    bullet[bul]->kill();
                    fighter->collide();
                }
                //Check bullet-Barrier
                for(int i = 0; i < level->barrierCount; i++){
                    level->barrier[i]->check_collision(bullet[bul]);
                }
            }
        }

        //Checks all ships against each other and against barriers
        void check_ship_collision(){
            //Ships collision
            for(int en = 0; en < troop->size(); en++){
                //Check enemy - fighetr
                if (troop->enemy(en)->collided(fighter)){
                    fighter->collide();
                    troop->enemy(en)->kill();
                }
                //Check enemy - barriers
                for(int i = 0; i < level->barrierCount; i++){
                    if(level->barrier[i]->check_collision(troop->enemy(en))){
                        level->barrier[i]->destroy();
                    }
                }
            }
            //Special Enemy - Fighter
            if (level->specialEnemy->collided(fighter)){
                    fighter->collide();
                    level->specialEnemy->kill();
            }
        }

        void update(){
            //Fighter
            fighter->update();
            //Troop
            troop->update();
            //Bullets
            for(int bul = 0; bul < Bullet::CAP; bul++){
                bullet[bul]->update();
            }
            //Scripted Enemy
            level->specialEnemy->update();
            if(level->specialEnemy->scriptedFrame == frame) level->specialEnemy->set_state(1);
        }

        void draw(){
            //Draw screen
            SDL_FillRect(screen, NULL, 0x00000000);
            //Roll background
            //roll_bg();
            //Draw bullets
            for(int bul = 0; bul<Bullet::CAP; bul++){
                if(bullet[bul]->get_state() != 0) bullet[bul]->draw(screen);
            }
            //Draw enemies
            troop->draw(screen);
            //Draw fighter
            fighter->draw(screen);
            //Draw Scripted Enemy
            level->specialEnemy->draw(screen);
            //Draw Barriers
            for(int i = 0; i < level->barrierCount; i++){
                    level->barrier[i]->draw(screen);
                }

            //Draw HUD
            apply_surface(0,0, FileHandler::image_set[HUD], screen);
            //Draw Shields
            for(int i = 0; i < fighter->armor; i++){
                apply_surface(24+32*i,678, FileHandler::image_set[SHIELD], screen);
            }
            //Draw Score
            display_score();
        }

        void display_score(){
            //int previous_score = fighter->score - level_score;
            text->write_text(20,20, "SCORE:");
//            std::ostringstream string;
//            string << fighter->score;
            text->write_text(112,50, fighter->score_to_s(), 1);
        }

//        void roll_bg(){
//            bgy += 0.2;
//            if(bgy > Screen::HEIGHT) bgy = 0;
//            apply_surface(0, (int)bgy, background, screen);
//            apply_surface(0, (int)bgy-Screen::HEIGHT, background, screen);
//
//        }


        static SDL_Surface* screen;
        //static float bgy;

};
SDL_Surface* LevelHandler::screen = NULL;
//float LevelHandler::bgy = 0;
//TextHandler* LevelHandler::text = NULL;

#endif // LEVELHANDLER_H
