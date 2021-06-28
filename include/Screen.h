#ifndef SCREEN_H
#define SCREEN_H

using namespace std;

namespace Screen{
    const int WIDTH = 1280;
    const int HEIGHT = 720;
    const int BPP = 32;
    const int IMAGE_SIZE = 50;
    const int FPS = 60;
    const int PLAY_MIN_X = 130 +10;
    const int PLAY_MIN_Y =  10 +10;
    const int PLAY_WIDTH = 1140 -20;
    const int PLAY_HEIGHT = 700 -20;
    const int PLAY_MAX_X = PLAY_MIN_X + PLAY_WIDTH;
    const int PLAY_MAX_Y = PLAY_MIN_Y + PLAY_HEIGHT;
}


#endif // SCREEN_H
