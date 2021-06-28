#ifndef BARRIERPIECE_H
#define BARRIERPIECE_H

#include <Flying_Object.h>

#define PIECE_WIDTH 3
#define PIECE_HEIGHT 6

class BarrierPiece : public Flying_Object
{
    private:
        void initialize_collision_boxes(){
            //Creat the necessary SDL_Rects
            box.resize(1);
            //Initialize boxes width and height
            box[0].w = PIECE_WIDTH;
            box[0].h = PIECE_HEIGHT;

            shift_boxes();
        }

        virtual void shift_boxes(){
            box[0].x = get_x();
            box[0].y = get_y();
        }


    public:
        BarrierPiece(){}

        BarrierPiece(int x, int y) : Flying_Object(x, y){
            //state = 0;
            initialize_collision_boxes();
            image = FileHandler::image_set[BARRIERUNIT];
            activate();
        }

        void activate(){
            state = 1;
        }
};

#endif // BARRIERPIECE_H
