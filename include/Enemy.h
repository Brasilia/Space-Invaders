#ifndef ENEMY_H
#define ENEMY_H

#include <SpaceShip.h>

class Enemy : public SpaceShip{
    private:
        int type;
        int points;

        void initialize_collision_boxes(){
            //Creat the necessary SDL_Rects
            box.resize(3);
            //Initialize boxes width and height
            box[0].w = 32;
            box[0].h = 21;

            box[1].w = 6;
            box[1].h = 6;

            box[2].w = 6;
            box[2].h = 6;

            shift_boxes();
        }

        virtual void shift_boxes(){
            box[0].x = get_x();
            box[0].y = get_y()+3;

            box[1].x = get_x()+4;
            box[1].y = get_y()+24;

            box[2].x = get_x()+22;
            box[2].y = get_y()+24;
        }

    public:
        int scriptedFrame;

        Enemy() : SpaceShip(){
            set_width(32);
            initialize_collision_boxes();
        }

        Enemy(int x, int y, int type) : SpaceShip(x, y){
            set_width(32);
            initialize_collision_boxes();
            setup(x, y, type);
        }

        void setup(float x, float y, int type){
            SpaceShip::setup(x, y);
            this->type = type;
            set_speed(0.9,0);
            set_weapon(-(type+1), false);
            push_horizontal(DIR_RIGHT);
            image = FileHandler::image_set[ENEMY1+type];
            scriptedFrame = -1;
            setup_points();
        }

        void set_scripted_frame(int frame){
            scriptedFrame = frame;
        }

        void setup_points(){
            points = 10-type;
        }

        void set_score(int score){
            this->points = score;
        }
        int get_score(){
            return points;
        }

        void update(){
            SpaceShip::update();
            shift_boxes();
        }
};

#endif // ENEMY_H
