#ifndef RANKING_H
#define RANKING_H

#include <FileHandler.h>
#include <TextHandler.h>
//#include <Fighter.h>

class Ranking
{
    private:
        TextHandler* text;
        int frame;
        SDL_Surface* screen;
        Uint8* keystate;
        Fighter* fighter;

    public:
        Ranking(SDL_Surface* screen, Fighter* fighter) {
            this->screen = screen;
            this->fighter = fighter;
            text = new TextHandler(screen, 110);
            frame = 0;
        }
        void display(){
//            cout << "ranking display" << endl;
            //Draw screen
            SDL_FillRect(screen, NULL, 0x00000000);
            //Write on the screen
            text->write_text(Screen::WIDTH/2, 120, "SCORE", 0.5); //400, 120
            text->write_text(Screen::WIDTH/2, 300, fighter->score_to_s(), 0.5); //645, 300
        }

        int handle(){
            frame++;
            if(frame < 60){
                display();
            }
            else{
                keystate = SDL_GetKeyState(NULL);
                if(keystate[SDLK_RETURN] || keystate[SDLK_SPACE]){
                    frame = 0;
                    return false;
                }
            }
            return true;
        }

};

#endif // RANKING_H
