#ifndef TEXTHANDLER_H
#define TEXTHANDLER_H

#include "SDL/SDL_ttf.h"
#include <sstream>
#include <string>

class TextHandler
{
    private:
        SDL_Surface *text_surface; //Surface for applying text
        TTF_Font *font; //Text font
        int font_size;
        SDL_Color textcolor; //Text Color
        SDL_Surface* screen;

    public:
        TextHandler(SDL_Surface* screen, int font_size = 18) {
            TTF_Init();
            text_surface = NULL;
            this->font_size = font_size;
            font = TTF_OpenFont("ttf/Topaz-8.ttf", font_size);
            textcolor.r = 255;
            textcolor.g = 231;
            textcolor.b = 28;
            this->screen = screen;
        }

        ~TextHandler(){
            SDL_FreeSurface(text_surface);
            TTF_CloseFont(font);
        }

        void write_text(int x, int y, const char text[], float push = 0)
        {
            //Load text surface into memory, after cleaning previously used memory
//            cout << "text surface: " <<text_surface << endl;
            if(text_surface != NULL){
                SDL_FreeSurface(text_surface);
                text_surface = NULL;
            }
            text_surface = TTF_RenderText_Solid(font, text, textcolor);
            //Apply surface
            apply_surface(x, y, text_surface, screen, NULL, push);
            //Free memory
            //SDL_FreeSurface(text_surface);
//            cout << "Applied text" << endl;
        }
};

#endif // TEXTHANDLER_H
