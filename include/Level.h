#ifndef LEVEL_H
#define LEVEL_H

#include <Barrier.h>

#define MAX_BARRIERS 10

//Enemy troop, barriers, special ships... all that might be unique to each level
class Level
{
    public:
        Enemy_Troop* troop;
        Enemy* specialEnemy;
        //std::vector<Barrier*>
        Barrier* barrier[MAX_BARRIERS];
        int barrierCount;
        float scoreMod;
        float speedMod;
        float shootSpeedMod;
        int levelNumber;

        Level(int levelNumber) {
//            troop = new Enemy_Troop();
            troop = NULL;
            specialEnemy = new Enemy();
            for(int i=0; i<MAX_BARRIERS; i++){
                barrier[i] = new Barrier();
            }
            setup_level(levelNumber);
        }

        void setup_level(int levelNumber){
            this->levelNumber = levelNumber;
            int init_x = Screen::PLAY_MIN_X;
            int init_y = 72;
            int troopVec[5];
            switch (levelNumber){
                case 1:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 1;
                    speedMod = 1;
                    shootSpeedMod = 1;
                    *specialEnemy = Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
//                    specialEnemy->set_scripted_frame(600);
//                    specialEnemy->set_speed(1,0);
//                    specialEnemy->set_image(16);
                    barrierCount = 0;
                    break;
                }
                case 2:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 1.05;
                    speedMod = 1.05;
                    shootSpeedMod = 1;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
                    specialEnemy->set_scripted_frame(600);
                    specialEnemy->set_speed(1,0);
                    specialEnemy->set_image(ENEMY5);
                    specialEnemy->set_score(80);
                    barrierCount = 0;
                    break;
                }
                case 3:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 1.1;
                    speedMod = 1.1;
                    shootSpeedMod = 1.05;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
//                    specialEnemy->set_scripted_frame(600);
//                    specialEnemy->set_speed(1,0);
//                    specialEnemy->set_image(ENEMY5);
//                    specialEnemy->set_score(80);
                    barrierCount = 1;
                    break;
                }
                case 4:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 1.2;
                    speedMod = 1.1;
                    shootSpeedMod = 1.1;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
                    specialEnemy->set_scripted_frame(300);
                    specialEnemy->set_speed(1,0);
                    specialEnemy->set_image(ENEMY5);
                    specialEnemy->set_score(100);
                    barrierCount = 2;
                    break;
                }
                case 5:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 1.3;
                    speedMod = 1.2;
                    shootSpeedMod = 1.4;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
//                    specialEnemy->set_scripted_frame(300);
//                    specialEnemy->set_speed(1,0);
//                    specialEnemy->set_image(ENEMY5);
//                    specialEnemy->set_score(80);
                    barrierCount = 0;
                    break;
                }
                case 6:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 1.4;
                    speedMod = 1.25;
                    shootSpeedMod = 1.6;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
//                    specialEnemy->set_scripted_frame(300);
//                    specialEnemy->set_speed(1,0);
//                    specialEnemy->set_image(ENEMY5);
//                    specialEnemy->set_score(80);
                    barrierCount = 5;
                    break;
                }
                case 7:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 1.6;
                    speedMod = 1.3;
                    shootSpeedMod = 2.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
                    specialEnemy->set_scripted_frame(1100);
                    specialEnemy->set_speed(1.3,0);
                    specialEnemy->set_image(ENEMY5);
                    specialEnemy->set_score(120);
                    barrierCount = 5;
                    break;
                }
                case 8:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 1.8;
                    speedMod = 1.3;
                    shootSpeedMod = 3.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
                    specialEnemy->set_scripted_frame(200);
                    specialEnemy->set_speed(1.8,0);
                    specialEnemy->set_image(ENEMY5);
                    specialEnemy->set_score(150);
                    barrierCount = 0;
                    break;
                }
                case 9:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 2.0;
                    speedMod = 1.35;
                    shootSpeedMod = 4.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
//                    specialEnemy->set_scripted_frame(200);
//                    specialEnemy->set_speed(1.8,0);
//                    specialEnemy->set_image(ENEMY5);
//                    specialEnemy->set_score(280);
                    barrierCount = 8;
                    break;
                }
                case 10:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 2.5;
                    speedMod = 1.35;
                    shootSpeedMod = 5.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
//                    specialEnemy->set_scripted_frame(200);
//                    specialEnemy->set_speed(1.8,0);
//                    specialEnemy->set_image(ENEMY5);
//                    specialEnemy->set_score(280);
                    barrierCount = 0;
                    break;
                }
                case 11:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 2.8;
                    speedMod = 1.4;
                    shootSpeedMod = 6.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
                    specialEnemy->set_scripted_frame(2000);
                    specialEnemy->set_speed(1.8,0);
                    specialEnemy->set_image(ENEMY5);
                    specialEnemy->set_score(180);
                    barrierCount = 6;
                    break;
                }
                case 12:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 3.5;
                    speedMod = 1.4;
                    shootSpeedMod = 7.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
//                    specialEnemy->set_scripted_frame(2000);
//                    specialEnemy->set_speed(1.8,0);
//                    specialEnemy->set_image(ENEMY5);
//                    specialEnemy->set_score(580);
                    barrierCount = 1;
                    break;
                }
                case 13:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 4.0;
                    speedMod = 1.45;
                    shootSpeedMod = 8.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
                    specialEnemy->set_scripted_frame(200);
                    specialEnemy->set_speed(1.9,0);
                    specialEnemy->set_image(ENEMY5);
                    specialEnemy->set_score(200);
                    barrierCount = 3;
                    break;
                }
                case 14:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 5.0;
                    speedMod = 1.5;
                    shootSpeedMod = 10.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
                    specialEnemy->set_scripted_frame(500);
                    specialEnemy->set_speed(1.5,0);
                    specialEnemy->set_image(ENEMY5);
                    specialEnemy->set_score(220);
                    barrierCount = 0;
                    break;
                }
                case 15:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 6.0;
                    speedMod = 1.5;
                    shootSpeedMod = 12.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
//                    specialEnemy->set_scripted_frame(500);
//                    specialEnemy->set_speed(1.5,0);
//                    specialEnemy->set_image(ENEMY5);
//                    specialEnemy->set_score(1080);
                    barrierCount = 0;
                    break;
                }
                case 16:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 8.0;
                    speedMod = 1.55;
                    shootSpeedMod = 15.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
                    specialEnemy->set_scripted_frame(1500);
                    specialEnemy->set_speed(2.0,0);
                    specialEnemy->set_image(ENEMY5);
                    specialEnemy->set_score(250);
                    barrierCount = 7;
                    break;
                }
                case 17:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 10.0;
                    speedMod = 1.6;
                    shootSpeedMod = 16.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
//                    specialEnemy->set_scripted_frame(1500);
//                    specialEnemy->set_speed(2.0,0);
//                    specialEnemy->set_image(ENEMY5);
//                    specialEnemy->set_score(1780);
                    barrierCount = 2;
                    break;
                }
                case 18:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 12.0;
                    speedMod = 1.65;
                    shootSpeedMod = 18.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
//                    specialEnemy->set_scripted_frame(1500);
//                    specialEnemy->set_speed(2.0,0);
//                    specialEnemy->set_image(ENEMY5);
//                    specialEnemy->set_score(1780);
                    barrierCount = 2;
                    break;
                }
                case 19:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 15.0;
                    speedMod = 1.7;
                    shootSpeedMod = 20.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
                    specialEnemy->set_scripted_frame(1500);
                    specialEnemy->set_speed(1.0,0);
                    specialEnemy->set_image(ENEMY5);
                    specialEnemy->set_score(300);
                    barrierCount = 4;
                    break;
                }
                case 20:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 2;
                    troopVec[3] = 3;
                    troopVec[4] = 4;
                    scoreMod = 18.0;
                    speedMod = 1.8;
                    shootSpeedMod = 22.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
                    specialEnemy->set_scripted_frame(2500);
                    specialEnemy->set_speed(1.8,0);
                    specialEnemy->set_image(ENEMY5);
                    specialEnemy->set_score(350);
                    barrierCount = 1;
                    break;
                }
                case 21:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 1;
                    troopVec[3] = 0;
                    troopVec[4] = 4;
                    scoreMod = 20.0;
                    speedMod = 2.0;
                    shootSpeedMod = 25.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
                    specialEnemy->set_scripted_frame(450);
                    specialEnemy->set_speed(2.2,0);
                    specialEnemy->set_image(ENEMY5);
                    specialEnemy->set_score(400);
                    barrierCount = 1;
                    break;
                }
                case 22:
                {
                    troopVec[0] = 0;
                    troopVec[1] = 1;
                    troopVec[2] = 1;
                    troopVec[3] = 0;
                    troopVec[4] = 4;
                    scoreMod = 22.0;
                    speedMod = 2.2;
                    shootSpeedMod = 26.0;
                    specialEnemy = new Enemy(init_x-80, init_y-40, 0);
                    specialEnemy->kill();
                    specialEnemy->set_scripted_frame(850);
                    specialEnemy->set_speed(1.7,0);
                    specialEnemy->set_image(ENEMY5);
                    specialEnemy->set_score(600);
                    barrierCount = 4;
                    break;
                }











            }
            //Barriers placement
            for (int i = 0; i<barrierCount; i++){
                *barrier[i] = Barrier(Screen::PLAY_MIN_X + (Screen::PLAY_WIDTH/(barrierCount+1))*(i%barrierCount+1) -1 ,590);
            }
            //Troop initialization
            troop = new Enemy_Troop(init_x, init_y, troopVec, speedMod);
        }

};

#endif // LEVEL_H
