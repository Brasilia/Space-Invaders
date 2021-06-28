#ifndef FIGHTER_H
#define FIGHTER_H

#include <SpaceShip.h>

#define TEMP_SCREEN_WIDTH 1280

using namespace std;

class Fighter : public SpaceShip{

    private:
        void initialize_collision_boxes(){
            //Creat the necessary SDL_Rects
            box.resize(4);
            //Initialize boxes width and height
            box[0].w = 50;
            box[0].h = 7;

            box[1].w = 38;
            box[1].h = 9;

            box[2].w = 18;
            box[2].h = 10;

            box[3].w = 10;
            box[3].h = 11;

            shift_boxes();
        }

        virtual void shift_boxes(){
            box[0].x = get_x();
            box[0].y = get_y()+31;

            box[1].x = get_x()+6;
            box[1].y = get_y()+22;

            box[2].x = get_x()+16;
            box[2].y = get_y()+12;

            box[3].x = get_x()+20;
            box[3].y = get_y()+1;
        }

        void switch_animation_state(){
            switch(state){
                case 0:
                    image = FileHandler::image_set[FIGHTER4];
                    break;
                case 1:
                    state = 2;
                    image = FileHandler::image_set[FIGHTER2];
                    break;
                case 2:
                    state = 1;
                    image = FileHandler::image_set[FIGHTER1];
                    break;
                case 3:
                    state = 1;
                    image = FileHandler::image_set[FIGHTER3];
                    break;
            }
            if(state > 3){
                state--;
                image = FileHandler::image_set[FIGHTER3];
            }
        }

    public:
        int armor;
        int score;

        Fighter(int x, int y) : SpaceShip(x, y){
            setup(x, y);
            set_width(50);
            image = FileHandler::image_set[FIGHTER1];
            initialize_collision_boxes();
        }

        void setup(float x, float y){
            SpaceShip::setup(x, y);
            set_weapon(0);
            set_speed(3.5,0);
            armor = 3;
            score = 0;
        }

        void update(){
            SpaceShip::update();
            if(get_x() < 144) set_x(144);
            if(get_x() > TEMP_SCREEN_WIDTH-50-20) set_x(TEMP_SCREEN_WIDTH-50-20);
            shift_boxes();
            switch_animation_state();
        }

        void collide(){
            armor--;
            state = 15;
            if(armor <= 0) state = 0;
        }

        char* score_to_s(){
//            cout << score << endl;
            std::ostringstream string;
            string << score;
            return (char*)string.str().c_str();
        }
};

#endif // FIGHTER_H
