#ifndef FLYING_OBJECT_H
#define FLYING_OBJECT_H

#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <vector>

#include <simpleSDLfunctions.h>
#include <FileHandler.h>

#define NO_CHANGE -999999
#define DIR_UP -1
#define DIR_DOWN 1
#define DIR_LEFT -1
#define DIR_RIGHT 1
#define DIR_NEUTRAL 0


#include <iostream>
using namespace std;

class Flying_Object{

    private:
        float pos_x;
        float pos_y;
        int width;

    protected:
        int state;
        float speed_x;
        float speed_y;
        int dir_horizontal;
        int dir_vertical;
        SDL_Surface* image;

        std::vector<SDL_Rect> box;

        virtual void initialize_collision_boxes(){}

        virtual void shift_boxes(){}

    public:

        Flying_Object(){
            pos_x = 0;
            pos_y = 0;
            state = 0;
            dir_horizontal = 0;
            dir_vertical = 0;
            initialize_collision_boxes();
        }
        Flying_Object(float x, float y){
            setup(x, y);
            initialize_collision_boxes();
        }

        virtual void setup(float x, float y){
            pos_x = x;
            pos_y = y;
            state = 1;
            speed_x = 0;
            speed_y = 0;
            dir_horizontal = 0;
            dir_vertical = 0;
        }

        virtual void update(){
            if(state != 0){
                pos_x += speed_x*dir_horizontal;
                pos_y += speed_y*dir_vertical;
            }
        }

        void set_speed(float sx, float sy){
            if(sx != NO_CHANGE) speed_x = sx;
            if(sy != NO_CHANGE) speed_y = sy;
        }

        void push_horizontal(int dir){
            dir_horizontal = dir;
        }
        void push_vertical(int dir){
            dir_vertical = dir;
        }
        int get_dir_vertical(){
            return dir_vertical;
        }
        int get_dir_horizontal(){
            return dir_horizontal;
        }

        virtual void switch_animation_state(){}

        int get_state(){
            return this->state;
        }

        void set_state(int st){
            state = st;
        }

        void kill(){
            set_state(0);
        }

        void set_x(float x){
            pos_x = x;
        }

        void set_y(float y){
            pos_y = y;
        }

        int get_x(){
            return (int)round(pos_x);;
        }

        int get_y(){
            return (int)round(pos_y);
        }

        int get_width(){
            return width;
        }
        void set_width(int width){
            this->width = width;
        }

        //Move in a specific direction using base directional speed
        void move_up(){
            pos_y -= fabs(speed_y);
        }
        void move_down(){
            pos_y += fabs(speed_y);
        }
        void move_right(){
            pos_x += fabs(speed_x);
        }
        void move_left(){
            pos_x -= fabs(speed_x);
        }
        //Move in a specific direction with a specified speed
        void move_up(float speed_y){
            pos_y -= fabs(speed_y);
        }
        void move_down(float speed_y){
            pos_y += fabs(speed_y);
        }
        void move_right(float speed_x){
            pos_x += fabs(speed_x);
        }
        void move_left(float speed_x){
            pos_x -= fabs(speed_x);
        }

        //Gets the collision boxes
        std::vector<SDL_Rect> &get_rects(){
            return box;
        }

        bool check_collision(std::vector<SDL_Rect> &A, std::vector<SDL_Rect> &B){
            int rightA, rightB;
            int leftA, leftB;
            int topA, topB;
            int bottomA, bottomB;

            //Go through A boxes
            for(unsigned int Abox=0; Abox < A.size(); Abox++){
                //Calculate the sides of rect A
                leftA = A[Abox].x;
                rightA = A[Abox].x + A[Abox].w;
                topA = A[Abox].y;
                bottomA = A[Abox].y + A[Abox].h;

                //Go through B boxes
                for(unsigned int Bbox=0; Bbox < B.size(); Bbox++){
                    //Calculate the sides of rect A
                    leftB = B[Bbox].x;
                    rightB = B[Bbox].x + B[Bbox].w;
                    topB = B[Bbox].y;
                    bottomB = B[Bbox].y + B[Bbox].h;

                    //If no sides from A are outside of B
                    if( ( (bottomA < topB) || (topA > bottomB) || (rightA < leftB) || (leftA > rightB) ) == false){
                        //Collision detected
                        return true;
                    }
                }
            }
            //No boxes touched
            return false;
        }

        bool collided(Flying_Object *target){
            if(this->state * target->state == 0) return false;
            return check_collision(this->get_rects(), target->get_rects());
        }

        //Subclasses may use more then one image to choose from
        void set_image(int index){
            image = FileHandler::image_set[index];
        }

        //Draws the object's image in a surface (screen, mostly)
        void draw(SDL_Surface* surface){
            if(state != 0) apply_surface(pos_x, pos_y, image, surface);
        }
};

#endif // FLYING_OBJECT_H

