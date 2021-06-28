#ifndef BULLET_H
#define BULLET_H

#include <Flying_Object.h>

class Bullet : public Flying_Object
{
    private:
        //Stores an index for the bullets vector which will hold all the bullets
        static int counter;

        void initialize_collision_boxes(){
            //Create the necessary SDL_Rects
            box.resize(1);
            //Initialize boxes width and height
            box[0].w = 4; //4
            box[0].h = 10;
            shift_boxes();
        }
        //Gets each box to it's position
        virtual void shift_boxes(){
            box[0].x = get_x(); //get_x()
            box[0].y = get_y()+1;
        }

    public:
        //The bullets number cap - above it, the old bullets will be replaced by the new ones, but it shouldn't happen
        static const int CAP;
        //Not shot bullets
        Bullet() : Flying_Object(){
            initialize_collision_boxes();
        }
        ~Bullet(){
//            cout << "Deleting bullet" << endl;
        }

        //Shot bullets, departing from (x,y), with a vertical direction
        Bullet(int x, int y, int direction) : Flying_Object(x, y) {
            dir_vertical = direction;
            set_speed(0, 8);
            //Handles counter to set it to the right index
            counter ++;
//            cout << "Bullet " << counter << endl;
            if(counter >= CAP) reset_counter();
            //Collision boxes
            initialize_collision_boxes();
            //Sets which image will be used for the bullet
            image = FileHandler::image_set[BULLET1];
            if(direction == -1) image = FileHandler::image_set[BULLET2];
        }

        void update(){
            Flying_Object::update();
            //Prevents the bullets from updating and keep moving through the (int) positions
            if(get_y() < -20 || get_y() > 1000){
              this->kill();
              //delete[] this;
            }
            shift_boxes();
        }

        static void reset_counter(){
            counter = 0;
        }

        static int get_counter(){
            return counter;
        }
};

int Bullet::counter = 0;
const int Bullet::CAP = 50;

#endif // BULLET_H
