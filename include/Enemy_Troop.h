#ifndef ENEMY_TROOP_H
#define ENEMY_TROOP_H

#include <enemy.h>
#include <FileHandler.h>

#define ROWS 4 //set to 5 later
#define ROW_SIZE 11
#define ENEMY_DIST_X 64
#define ENEMY_DIST_Y 48

#include<iostream>

using namespace std;


class Enemy_Troop
{
    private:
        Enemy troop[ROWS][ROW_SIZE];
        float pos_x, pos_y;
        float left_x, right_x;
        float top_y, bottom_y;
        unsigned int rows;
        unsigned int row_size;
        float base_speed, cur_speed;
        int max_size, cur_size;
        bool invaded;

    public:
        Enemy_Troop(){}

        Enemy_Troop(int init_x, int init_y, int types[ROWS], float speedMod = 1) {
            invaded = false;
            rows = ROWS;
            row_size = ROW_SIZE;
            max_size = rows*row_size;
            left_x = init_x;
            top_y = init_y;
            base_speed = 0.5*speedMod;
            cur_speed = base_speed;
            //Initializes each enemy on the troop
            for(unsigned int row = 0; row<rows; row++){
                for(unsigned int column = 0; column < row_size; column++){
                    troop[row][column] = Enemy(left_x +column*ENEMY_DIST_X, top_y +row*ENEMY_DIST_Y, types[row]);
                    troop[row][column].set_speed(cur_speed,0);
                }

            }
            update_dimensions();
            max_size = cur_size;
        }

        //One-index enemy[]
        Enemy* enemy(int array_offset){
            return &troop[0][array_offset];
        }

        //Troop size
        int size(){
            return rows*row_size;
        }

        //No enemies left on the troop?
        bool is_destroyed(){
            if(cur_size == 0) return true;
            return false;
        }

        //Have enemies reached the bottom of the screen?
        bool has_invaded(){
            return invaded;
        }

        //Chooses who can shoot - those who don't have another friendly ship in front of it
        void update_shooters(){
            for(int col = 0; col < (int)row_size; col++){
                int row = rows-1;
                while(troop[row][col].get_state() == 0 && row >= 0){
                    row--;
                }
                if(row >= 0)troop[row][col].turn_weapon(true);
            }
        }

        void update_dimensions(){
            int first_left = row_size;
            int last_right = -1;
            cur_size = 0;
            //Each column
            for(int col = 0; col < (int)row_size; col++){
                //Each enemy for that column
                int enemy_count = 0;
                for (int row = 0; row < (int)rows; row++){
                    if(troop[row][col].get_state() > 0){
                        enemy_count++;
                        cur_size++;
                        //Checks if an enemy has reached the bottom
                        if(troop[row][col].get_y() > 710-32) invaded = true;
                    }
                }
                //Not all enemies from that column are dead
                if(enemy_count > 0){
                    if(col > last_right) last_right = col;
                    if(col < first_left) first_left = col;
                }
            }

            //Here I must check if the troop isn't all dead and set it's state accordingly - or not

            //Limits the left and right x of the troop
            for(int row = 0; row < (int)rows; row++){
                if(troop[row][first_left].get_state() > 0) left_x = troop[row][first_left].get_x();
                if(troop[row][last_right].get_state() > 0) right_x = troop[row][last_right].get_x() + 32;
            }
        }

        void update_speed(){
            cur_speed = 1.0*base_speed*(max_size+5)/(cur_size+5) + 0.0*base_speed;
        }

        void jump(){
            for(int i = 0; i<size(); i++){
                if(enemy(i)->get_state() > 0) enemy(i)->move_down(ENEMY_DIST_Y);
            }
        }

        void update(){
            update_shooters();
            update_dimensions();
            if(left_x < Screen::PLAY_MIN_X || right_x > Screen::PLAY_MAX_X){
                base_speed *= -1;
                jump();
            }
            update_speed();

            for(unsigned int row = 0; row<rows; row++){
                for(unsigned int column = 0; column < row_size; column++){
                    troop[row][column].set_speed(cur_speed,0);
                    troop[row][column].update();
                }
            }
        }

        void draw(SDL_Surface* surface){
            for(unsigned int row = 0; row<rows; row++){
                for(unsigned int column = 0; column < row_size; column++){
                    troop[row][column].draw(surface);
                }
            }
        }

};

#endif // ENEMY_TROOP_H
