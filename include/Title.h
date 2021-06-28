#ifndef TITLE_H
#define TITLE_H

#include <FileHandler.h>

class Title
{
    private:
        SDL_Surface* title;
        FileHandler* fileHandler;
        int frame;
        SDL_Surface* screen;
        Uint8* keystate;
        Mix_Music* music;
        int state;
    public:
        Title(SDL_Surface* screen) {
            this->screen = screen;
            fileHandler = new FileHandler();
            title = fileHandler->load_title(); //622x236
            frame = 0;
            state = 0;
        }
        void display(){
            //Draw screen
            SDL_FillRect(screen, NULL, 0x00000000);
            //Draw title
            apply_surface((Screen::WIDTH-622)/2, (Screen::HEIGHT-236)/2, title, screen);
        }

        int handle(){
            frame++;
            if(frame < 20){
                display();
            }
            else{
                keystate = SDL_GetKeyState(NULL);
                if(keystate[SDLK_RETURN] || keystate[SDLK_SPACE]){
                    //Not gone through commands screen yet
                    if(state == 0){
                        show_commands();
                        state = 1;
                        frame = 20;
                    }
                    if(frame > 50){
                        frame = 0;
                        return false;
                    }
                }
            }
            return true;
        }

        void show_commands(){
            //Draw screen
            SDL_FillRect(screen, NULL, 0x00000000);
            //Draw commands
            TextHandler* commands_text = new TextHandler(screen, 30);
            commands_text->write_text(Screen::WIDTH/2, 20, "+--------------------------------------------+", 0.5);
            commands_text->write_text(Screen::WIDTH/2, 400, "+--------------------------------------------+", 0.5);
            commands_text->write_text(1*Screen::WIDTH/5, 120, "Left:  A or <-", 0.5);
            commands_text->write_text(4*Screen::WIDTH/5, 120, "Right:  D or ->", 0.5);
            commands_text->write_text(Screen::WIDTH/2, 280, "Shoot:  Space", 0.5);
            commands_text->write_text(1*Screen::WIDTH/5, 600, "Pause:  Ins", 0.5);
            commands_text->write_text(4*Screen::WIDTH/5, 600, "Restart:  F5", 0.5);
            commands_text->write_text(Screen::WIDTH/2, 650, "Exit:  Esc", 0.5);
            delete commands_text;
        }
};

#endif // TITLE_H
