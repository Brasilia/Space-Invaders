#ifndef BARRIER_H
#define BARRIER_H

#include <BarrierPiece.h>

#define LAYERS 4
#define BARRIER_SIZE 2*LAYERS*LAYERS*4

class Barrier
{
    private:
        //int x, y;
        BarrierPiece* barrierPiece[BARRIER_SIZE];
        int state;
    public:
        Barrier(){}

        Barrier(int x, int y) {
//            for(int piece = 1; piece <= BARRIER_SIZE/6; piece++){
//                int index = piece -1;
//                int base_y = piece*3;
//                int remain = index%(BARRIER_SIZE/3);
//                int straightFront = 4;
//                if (remain <= straightFront) base_y = piece*3 + 3*(straightFront-remain);
//                //if (index%(BARRIER_SIZE/3) == 0) base_y = piece*3 + 6;
//                barrierPiece[index+0*BARRIER_SIZE/6] = new BarrierPiece(index*3+x,base_y+y);
//                barrierPiece[index+1*BARRIER_SIZE/6] = new BarrierPiece(-index*3+x,base_y+y);
//
//                barrierPiece[index+2*BARRIER_SIZE/6] = new BarrierPiece(index*3+x,base_y+y-6);
//                barrierPiece[index+3*BARRIER_SIZE/6] = new BarrierPiece(-index*3+x,base_y+y-6);
//
//                barrierPiece[index+4*BARRIER_SIZE/6] = new BarrierPiece(index*3+x,base_y+y-12);
//                barrierPiece[index+5*BARRIER_SIZE/6] = new BarrierPiece(-index*3+x,base_y+y-12);
//            }

            //Initialize all barrier pieces
            for(int i=0; i<BARRIER_SIZE; i++){
                barrierPiece[i] = new BarrierPiece();
            }

            int layers = LAYERS;
            int parts = 2*layers;
            for(int i=0; i<BARRIER_SIZE; i++){
                int base_y = (i/parts)*PIECE_WIDTH;
                if(i/parts <= parts+1)  base_y = ((i/parts+1) + (parts-i/parts))*PIECE_WIDTH;
                *barrierPiece[i] =  BarrierPiece((i/parts)*PIECE_WIDTH*((((i%parts)%2)*2)-1)+x, base_y+y - PIECE_HEIGHT*(int)((i%parts)/2));
            }

        }

        bool check_collision(Flying_Object *target){
            bool collision = false;
            for(int i=0; i<BARRIER_SIZE; i++){
                if(target->collided(barrierPiece[i])){
                    barrierPiece[i]->kill();
                    collision = true;
                }
            }
            if(collision) target->kill();
            return collision;
        }

        void destroy(){
            for(int i=0; i<BARRIER_SIZE; i++){
                barrierPiece[i]->kill();
            }
        }

        void draw(SDL_Surface* surface){
            for(int i=0; i < BARRIER_SIZE; i++){
                if(barrierPiece[i] != NULL) barrierPiece[i]->draw(surface);
            }
        }
};

#endif // BARRIER_H
