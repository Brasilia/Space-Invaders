#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <Flying_Object.h>
#include <Weapon.h>

class SpaceShip : public Flying_Object{
    private:
        Weapon *weapon;

    protected:
        virtual void initialize_collision_boxes(){}
        virtual void shift_boxes(){}

    public:
        SpaceShip() : Flying_Object() {}

        SpaceShip(int x, int y) : Flying_Object(x, y){
            weapon = new Weapon();
        }

        virtual void setup(float x, float y){
            Flying_Object::setup(x, y);
        }

        void set_weapon(int type, bool state = true){
            *weapon = Weapon(type, state);
            update_weapon();
        }

        void turn_weapon(bool state){
            weapon->set_state(state);
        }

        void update_weapon(){
            weapon->update(this->get_x()+ get_width()/2 -2, this->get_y());
        }

        virtual void update(){
            Flying_Object::update();
            update_weapon();
        }

        Bullet* shoot(){
            //if(this->get_state() == 0) weapon->shoot().kill();
            return weapon->shoot();
        }


        //Subclasses may use more then one image to choose from
//        virtual void set_image(SDL_Surface** image_set){
//            Flying_Object::set_image();
//        }

};

#endif // SPACESHIP_H
