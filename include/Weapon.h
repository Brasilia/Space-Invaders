#ifndef WEAPON_H
#define WEAPON_H

#include <bullet.h>

class Weapon{

    private:
        int type;
        int pos_x;
        int pos_y;
        int delay;
        int frame_counter;
        bool state; //ON or OFF

    public:
        Weapon(){}

        Weapon(int type, bool state){
            this->state = state;
            this->type = type;
            set_delay();
            frame_counter = delay*(rand()%5/5.0);
        }
        //Sets the ammount of frames between each possible shot
        void set_delay(){
            if(type == 0) delay = 32; //32
            else if(type < 0) delay = type*type*30;
            else delay = 0;
        }

        void set_coords(int x, int y){
            pos_x = x;
            pos_y = y;
        }

        void set_state(bool state){
            this->state = state;
        }

        void update(int x, int y){
            set_coords(x, y);
            frame_counter++;
        }

        Bullet* shoot(){
            if(state == false) return new Bullet();
            if(frame_counter >= delay){
                frame_counter = 0;
                int inversion = -1;
                if(type <0){
                    inversion = 1;
                    Mix_PlayChannel( -1, FileHandler::se[2], 0 );
                }
                else{
                    Mix_PlayChannel( -1, FileHandler::se[1], 0 );
                }
                return new Bullet(pos_x, pos_y, inversion);
            }
            else{
                return new Bullet();
            }
        }

};

#endif // WEAPON_H
