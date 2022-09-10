#include "SBDL.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

double speed = 4;
double  angle = 0;
int score = 0;
int highscore = 10058;
int halateroobah = 0;
int paranderast = 0;
int fallingninja = 0;
char state = 'm';
bool rastboodan = false; // true bashe ba charkhesh bazi ro shroo mikone
bool chapboodan = true;
bool shielddashtanrast = false;  // bara intrsection shield
bool shielddashtanchap = false;
bool musicgame = true;
bool soundgame = true;
Font * font;
Music * moosighigame;
Sound * soundbazi;

Texture wall;
Texture ghasr;  // ghasr e aval e bazi e
Texture background;  // background e bazi
Texture rakhtaviz;
Texture balcon;
Texture balconkoochike;
Texture ninja;
Texture ninja2;
Texture ninja3;
Texture leftninja;
Texture leftninja2;
Texture leftninja3;
Texture ninjajump;
Texture ninjajump2;
Texture ninjajump3;
Texture ninjajump4;
Texture tighe;
Texture tigherast;
Texture badninja;
Texture roobah;
Texture roobah2;
Texture roobah3;
Texture roobah4;
Texture shield;
Texture blade;
Texture blade2;
Texture gameover;
Texture play;
Texture quit;
Texture scoreboard;
Texture rightshieldninja;
Texture rightshieldninja2;
Texture rightshieldninja3;
Texture leftshieldninja;
Texture leftshieldninja2;
Texture leftshieldninja3;
Texture charkheshshieldninja;
Texture charkheshshieldninja2;
Texture charkheshshieldninja3;
Texture menuwallpper;
Texture settingbtn;
Texture settingpage;
Texture sound;
Texture music;
Texture backbtn;
Texture rightbird;
Texture rightbird2;
Texture rightbird3;
Texture falling;
Texture falling2;
Texture falling3;
Texture quitbtn;

SDL_Rect backgroundRect = {40 , 0 , 420 , 500};
SDL_Rect wallRect={0,-500,500,1000};
SDL_Rect balconRect = {40 , -510 , 50 , 50};
SDL_Rect balconkoochikeRect = {410 , -900 , 50 , 50};
SDL_Rect ninjaRect = {40/* 410 */ , 350 , 50 ,50};
SDL_Rect leftninjaRect = {40 , 350 , 50 , 50};
SDL_Rect ninjajumpRect = {410 , 350 , 50 , 50};
SDL_Rect tigheRect = {40 , -510 , 50 , 50};
SDL_Rect tigherastRect = {410 , -900 , 50 , 50};
SDL_Rect badninjaRect = {25 , -510 , 50 , 50};
SDL_Rect roobahRect = {40 , -45 , 60 , 50};
SDL_Rect shieldRect = {40 , 350 , 50 ,50};
SDL_Rect bladeRect = {27 , -510 , 30 , 30};
SDL_Rect blade2Rect = {35 , -610 , 30 , 30};
SDL_Rect rakhtavizRect = {40 , 5 , 420 , 50};
SDL_Rect gameoverpanelRect = {100 , 100 , 300 , 300};
SDL_Rect playRect = {210 , 230 , 80 , 80};
SDL_Rect quitRect = {205 , 310 , 100 , 50};
SDL_Rect scoreboardRect = {0 , 0 , 500 , 80};
SDL_Rect rightninjashieldRect = {40/* 410 */ , 350 , 50 ,50};
SDL_Rect leftninjashieldRect = {40/* 410 */ , 350 , 50 ,50};
SDL_Rect menuwallpaperRect = {0 , 0 , 500 , 500};
SDL_Rect settingbtnRect = {210 , 350 , 80 , 80};
SDL_Rect settingpageRect = {0 , 0 , 500 , 500};
SDL_Rect soundRect = {100 , 200 , 100 , 100};
SDL_Rect musicRect = {250 , 200 , 100 , 100};
SDL_Rect backbtnRect = {0 , 0 , 60 , 60};
SDL_Rect rightbirdRect = {-100 , -100 , 60 , 60};
SDL_Rect fallingRect = {250 , 250 , 50 , 50};
SDL_Rect quitbtnRect = {205 , 430 , 90 , 70};

void loadtexture() {
    wall = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/background/back1.png");
    ghasr = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/background/foreground.png");
    background = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/img/background.png");
    rakhtaviz = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/img/laundry.png");
    balcon = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/obstacles/houses/balcony.png");
    balconkoochike = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/obstacles/houses/balcony2.png");
    ninja = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/run/1.png");
    ninja2 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/run/2.png");
    ninja3 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/run/3.png");
    leftninja = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/run/4.png");
    leftninja2 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/run/5.png");
    leftninja3 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/run/6.png");
    ninjajump = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/run/7.png");
    ninjajump2 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/run/8.png");
    ninjajump3 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/run/9.png");
    ninjajump4 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/run/10.png");
    tighe = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/obstacles/spike/SPIKES.png");
    badninja = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/obstacles/thrower/thrower.png");
    roobah = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/obstacles/squirrels/SQ1.png");
    roobah2 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/obstacles/squirrels/SQ2.png");
    roobah3 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/obstacles/squirrels/SQ3.png");
    roobah4 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/obstacles/squirrels/SQ4.png");
    font = SBDL::loadFont("C:/Users/lenovo/Desktop/assets/Font/Azuki Regular.ttf",20);
    shield = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/Shield/shield.png");
    blade = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/obstacles/blade/3.png");
    //blade2 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/obstacles/blade/4.png");
    gameover = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/menu/gameover_panel.png");
    play = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/img/play_btn.png");
    quit = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/menu/QUITBTN.png");
    scoreboard = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/menu/top_hud.png");
    rightshieldninja = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/ShieldRunning/b4.png");
    rightshieldninja2 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/ShieldRunning/b5.png");
    rightshieldninja3 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/ShieldRunning/b6.png");
    leftshieldninja = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/ShieldRunning/b1.png");
    leftshieldninja2 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/ShieldRunning/b2.png");
    leftshieldninja3 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/ShieldRunning/b3.png");
    charkheshshieldninja = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/ShieldRunning/b7.png");
    charkheshshieldninja2 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/ShieldRunning/b8.png");
    charkheshshieldninja3 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/ShieldRunning/b9.png");
    menuwallpper = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/menu/back2.png");
    settingbtn = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/menu/options.png");
    settingpage = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/menu/PAUSEMENU.png");
    sound = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/menu/sound_btn.png");
    music = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/menu/music_btn.png");
    backbtn = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/img/TL_backbutton.png");
    moosighigame = SBDL::loadMusic("C:/Users/lenovo/Desktop/assets/sound/music.mp3");
    rightbird = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/obstacles/bird/bird4.png");
    rightbird2 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/obstacles/bird/bird4.png");
    //rightbird2 = SBDL::loadTexture("C:/Users/lenovo/Desktop/bird2.png");
    rightbird3 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/obstacles/bird/bird6.png");
    falling = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/falling(emtiyazi)/falling1.png");
    falling2 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/falling(emtiyazi)/falling2.png");
    falling3 = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/falling(emtiyazi)/falling3.png");
    soundbazi = SBDL::loadSound("C:/Users/lenovo/Desktop/assets/sound/fall_1.wav");
    quitbtn = SBDL::loadTexture("C:/Users/lenovo/Desktop/assets/menu/QUITBTN.png");
}

void hasintersection(){
    if(SBDL::hasIntersectionRect(ninjaRect,balconRect)) {
        state = 'f';
    }
    if(SBDL::hasIntersectionRect(ninjaRect,balconkoochikeRect)){
        state = 'f';
    }
    if(SBDL::hasIntersectionRect(ninjaRect,badninjaRect)){
        state = 'f';
    }
    if((ninjaRect.x == 40 || ninjaRect.x == 420) && SBDL::hasIntersectionRect(ninjaRect,tigheRect)){
        state = 'f';
    }
    if((ninjaRect.x == 40 || ninjaRect.x == 420) && SBDL::hasIntersectionRect(ninjaRect,bladeRect)){
        state = 'f';
    }
    if((ninjaRect.x == 40 || ninjaRect.x == 420) && SBDL::hasIntersectionRect(ninjaRect,rightbirdRect)){
        state = 'f';
    }
    if((ninjaRect.x == 40 || ninjaRect.x == 420) && SBDL::hasIntersectionRect(ninjaRect,roobahRect)){
        state = 'f';
    }
}

void emtiazgereftn(){
    if((ninjaRect.x > 40 && ninjaRect.x < 420) && SBDL::hasIntersectionRect(ninjaRect,rightbirdRect)){

        score += 200;
        rightbirdRect = {-100 , -100 , 60 , 60};
    }
    if((ninjaRect.x > 40 && ninjaRect.x < 420) && SBDL::hasIntersectionRect(ninjaRect,roobahRect)){
        score += 200;
        roobahRect = {40 , -45 , 60 , 50};
    }
    if((ninjaRect.x > 40 && ninjaRect.x < 420) && SBDL::hasIntersectionRect(ninjaRect,bladeRect)){
        score += 100;
        bladeRect = {27 , -510 , 30 , 30};
    }
}

void scorebox(){
    SBDL::showTexture(scoreboard,scoreboardRect);
    Texture scoreText = SBDL::createFontTexture(font, "your score is   " + to_string(score), 0, 0, 0);
    SBDL::showTexture(scoreText, 177, 50);
}

void showfalling(){
    SBDL::playSound(soundbazi,1);
    SBDL::showTexture(wall, wallRect);
    wallRect.y += speed;
    if(wallRect.y==0) wallRect.y=-500;
        fallingninja++;

    SBDL::showTexture(background, backgroundRect);

    SBDL::showTexture(balcon,balconRect);
    balconRect.y += speed;
    if(balconRect.y > 600)                   //tarjihan random bashad
        balconRect.y = -600;

    SBDL::showTexture(balconkoochike,balconkoochikeRect);
    balconkoochikeRect.y += speed;
    if(balconkoochikeRect.y > 900)              // tarjihan random bashad
        balconkoochikeRect.y = -900;

        int n = fallingninja % 36;

        if (n < 6) { SBDL::showTexture(falling, fallingRect); }
        if (n > 5 && n < 12) { SBDL::showTexture(falling2, fallingRect); }
        if (n > 11 && n < 18) { SBDL::showTexture(falling3, fallingRect); }
        if (n > 17 && n < 24) { SBDL::showTexture(falling, fallingRect); }
        if (n > 23 && n < 30) { SBDL::showTexture(falling2, fallingRect); }
        if (n > 29 && n < 36) {
            SBDL::showTexture(falling3, fallingRect);
            state = 'l';
        }

        fallingRect.y += 7;
}

void harekatninja() {
    // harekat roo divar chap
    if (SBDL::getTime() % 300 >= 0 && SBDL::getTime() % 300 < 100)
        if (ninjaRect.x == 40) {
            SBDL::showTexture(leftninja, leftninjaRect);
            //if(SBDL::hasIntersectionRect(ninjaRect,shieldRect)){
            // SBDL::showTexture(leftshieldninja,leftninjaRect);
        }

    if (SBDL::getTime() % 300 >= 100 && SBDL::getTime() % 300 < 200)
        if (ninjaRect.x == 40) {
            SBDL::showTexture(leftninja2, ninjaRect);
            // if(SBDL::hasIntersectionRect(ninjaRect,shieldRect)){
            // SBDL::showTexture(leftshieldninja2,ninjaRect);
        }
    if (SBDL::getTime() % 300 >= 200 && SBDL::getTime() % 300 <= 300)
        if (ninjaRect.x == 40) {
            SBDL::showTexture(leftninja3, ninjaRect);
            //if(SBDL::hasIntersectionRect(ninjaRect,shieldRect)){
            // SBDL::showTexture(leftshieldninja3,ninjaRect);
        }

    // harekat roo divar rast
    if (SBDL::getTime() % 300 >= 0 && SBDL::getTime() % 300 < 100)
        if (ninjaRect.x == 420) {
            SBDL::showTexture(ninja, ninjaRect);
            // if(SBDL::hasIntersectionRect(ninjaRect,shieldRect)){
            // SBDL::showTexture(rightshieldninja,ninjaRect);
        }
    if (SBDL::getTime() % 300 >= 100 && SBDL::getTime() % 300 < 200)
        if (ninjaRect.x == 420) {
            SBDL::showTexture(ninja2, ninjaRect);
            //if(SBDL::hasIntersectionRect(ninjaRect,shieldRect)){
            //SBDL::showTexture(rightshieldninja2,ninjaRect);
        }
    if (SBDL::getTime() % 300 >= 200 && SBDL::getTime() % 300 <= 300)
        if (ninjaRect.x == 420) {
            SBDL::showTexture(ninja3, ninjaRect);
            //if(SBDL::hasIntersectionRect(ninjaRect,shieldRect)){
            // SBDL::showTexture(rightshieldninja3,ninjaRect);
        }

    // harekat ninja dar heine charkhesh
    if (SBDL::getTime() % 375 >= 0 && SBDL::getTime() % 375 < 75)
        if (ninjaRect.x > 40 && ninjaRect.x < 420) {
            SBDL::showTexture(ninjajump, ninjaRect);
            // if(SBDL::hasIntersectionRect(ninjaRect,shieldRect)){
            // SBDL::showTexture(charkheshshieldninja,ninjaRect);
        }
    if (SBDL::hasIntersectionRect(ninjaRect, roobahRect))   // scor gereftan az roobaH
        score += 10;

    if (SBDL::getTime() % 375 >= 75 && SBDL::getTime() % 375 < 150)
        if (ninjaRect.x > 40 && ninjaRect.x < 420) {
            SBDL::showTexture(ninjajump2, ninjaRect);
            //if(SBDL::hasIntersectionRect(ninjaRect,shieldRect)){
            // SBDL::showTexture(charkheshshieldninja2,ninjaRect);
        }
    if (SBDL::hasIntersectionRect(ninjaRect, roobahRect))  // scor gereftan az roobah
        score += 10;

    if (SBDL::getTime() % 375 >= 150 && SBDL::getTime() % 375 < 225)
        if (ninjaRect.x > 40 && ninjaRect.x < 420) {
            SBDL::showTexture(ninjajump3, ninjaRect);
            //if(SBDL::hasIntersectionRect(ninjaRect,shieldRect)){
            //SBDL::showTexture(charkheshshieldninja3,ninjaRect);
        }
    if(SBDL::hasIntersectionRect(ninjaRect,roobahRect))   // scor gereftan az roobah
        score+= 10;

    if(SBDL::getTime() % 375 >= 225 && SBDL::getTime() % 375 <= 300)
        if(ninjaRect.x > 40 && ninjaRect.x < 420){
            SBDL::showTexture(ninjajump4,ninjaRect);
    //if(SBDL::hasIntersectionRect(ninjaRect,shieldRect)){
        //SBDL::showTexture(charkheshshieldninja,ninjaRect);
    }
    if(SBDL::hasIntersectionRect(ninjaRect,roobahRect))  // scor gereftan az roobah
        score+= 10;


     if(ninjaRect.x == 420)
         chapboodan = false;
     if(ninjaRect.x == 40)
         chapboodan = true;


     if(rastboodan) {
         ninjaRect.w = 70;
         ninjaRect.h = 60;
     }

     if(!rastboodan){
         ninjaRect.w = 40;
         ninjaRect.h = 60;
     }


     if (SBDL::keyPressed(SDL_SCANCODE_SPACE))
         rastboodan = true;

     if(rastboodan && chapboodan)
         ninjaRect.x +=5;

     if(rastboodan && !chapboodan)
         ninjaRect.x -= 5;

     if(ninjaRect.x == 40 || ninjaRect.x == 420)
         rastboodan = false;
}

void harekatbashield(){
    // harekat roo divar chap
    if(SBDL::getTime() % 300 >= 0 && SBDL::getTime() % 300 < 100)
        if(ninjaRect.x == 40 && SBDL::hasIntersectionRect(ninjaRect,shieldRect))
            SBDL::showTexture(leftshieldninja,leftninjaRect);

    if(SBDL::getTime() % 300 >= 100 && SBDL::getTime() % 300 < 200)
        if(ninjaRect.x == 40 && SBDL::hasIntersectionRect(ninjaRect,shieldRect))
            SBDL::showTexture(leftshieldninja2,ninjaRect);

    if(SBDL::getTime() % 300 >= 200 && SBDL::getTime() % 300 <= 300)
        if(ninjaRect.x == 40 && SBDL::hasIntersectionRect(ninjaRect,shieldRect))
            SBDL::showTexture(leftshieldninja3,ninjaRect);

    // harekat roo divar rast
    if(SBDL::getTime() % 300 >= 0 && SBDL::getTime() % 300 < 100)
        if(ninjaRect.x == 420 && SBDL::hasIntersectionRect(ninjaRect,shieldRect))
            SBDL::showTexture(rightshieldninja,ninjaRect);

    if(SBDL::getTime() % 300 >= 100 && SBDL::getTime() % 300 < 200)
        if(ninjaRect.x == 420 && SBDL::hasIntersectionRect(ninjaRect,shieldRect))
            SBDL::showTexture(rightshieldninja2,ninjaRect);

    if(SBDL::getTime() % 300 >= 200 && SBDL::getTime() % 300 <= 300)
        if(ninjaRect.x == 420 && SBDL::hasIntersectionRect(ninjaRect,shieldRect))
            SBDL::showTexture(rightshieldninja3,ninjaRect);

    // harekat ninja dar heine charkhesh
    if(SBDL::getTime() % 375 >= 0 && SBDL::getTime() % 375 < 75)
        if((ninjaRect.x > 40 && ninjaRect.x < 420) && SBDL::hasIntersectionRect(ninjaRect,shieldRect))
            SBDL::showTexture(charkheshshieldninja,ninjaRect);

       // naboodi shield ba barkhord


    if(SBDL::getTime() % 375 >= 75 && SBDL::getTime() % 375 < 150)
        if((ninjaRect.x > 40 && ninjaRect.x < 420) && SBDL::hasIntersectionRect(ninjaRect,shieldRect))
            SBDL::showTexture(charkheshshieldninja2,ninjaRect);

      // scor gereftan az roobah


    if(SBDL::getTime() % 375 >= 150 && SBDL::getTime() % 375 < 225)
        if((ninjaRect.x > 40 && ninjaRect.x < 420) && SBDL::hasIntersectionRect(ninjaRect,shieldRect))
            SBDL::showTexture(charkheshshieldninja3,ninjaRect);

       // scor gereftan az roobah


    if(SBDL::getTime() % 375 >= 225 && SBDL::getTime() % 375 <= 300)
        if((ninjaRect.x > 40 && ninjaRect.x < 420) && SBDL::hasIntersectionRect(ninjaRect,shieldRect))
            SBDL::showTexture(charkheshshieldninja,ninjaRect);

        // roobah

    if(ninjaRect.x == 420 && SBDL::hasIntersectionRect(ninjaRect,shieldRect))
        shielddashtanrast = true;
    if(ninjaRect.x == 40 && SBDL::hasIntersectionRect(ninjaRect,shieldRect))
        shielddashtanchap = true;


    if(!shielddashtanrast) {
        ninjaRect.w = 70;
        ninjaRect.h = 60;
    }

    if(shielddashtanrast){
        ninjaRect.w = 40;
        ninjaRect.h = 60;
    }


   // if (SBDL::keyPressed(SDL_SCANCODE_SPACE))
       // shielddashtanrast = true;

    if(shielddashtanrast && shielddashtanchap)
        ninjaRect.x +=5;

    if(shielddashtanrast && !shielddashtanchap)
        ninjaRect.x -= 5;

    if(ninjaRect.x == 40 || ninjaRect.x == 420)
        shielddashtanrast = false;
}   // bug dare

void showbird(){
        paranderast++;
        int b = paranderast % 36;

        rightbirdRect.y += 5;
        rightbirdRect.x -= 6;

        if (b < 6) { SBDL::showTexture(rightbird, rightbirdRect); }
        if (b > 5 && b < 12) { SBDL::showTexture(rightbird2, rightbirdRect); }
        if (b > 11 && b < 18) { SBDL::showTexture(rightbird3, rightbirdRect); }
        if (b > 17 && b < 24) { SBDL::showTexture(rightbird, rightbirdRect); }
        if (b > 23 && b < 30) { SBDL::showTexture(rightbird2, rightbirdRect); }
        if (b > 29 && b < 36) { SBDL::showTexture(rightbird3, rightbirdRect); }
        if (rightbirdRect.x <= -500) {
            rightbirdRect.x = 500;
            rightbirdRect.y = -60;
        }
}

void showroobah(){
    if(abs(rakhtavizRect.y) < 5 && rand() % 4 == 1)
    {
        halateroobah = 1;
    }
    if(halateroobah != 0)
    {
        if(halateroobah <= 10)
        {
            SBDL::showTexture(roobah,roobahRect);
        }
        else if(halateroobah <= 20)
        {
            SBDL::showTexture(roobah2,roobahRect);
        }
        else if(halateroobah <= 30)
        {
            SBDL::showTexture(roobah3,roobahRect);
        }
        else if(halateroobah <= 40)
        {
            SBDL::showTexture(roobah4,roobahRect);
        }
        else if(halateroobah <= 50)
        {
            SBDL::showTexture(roobah,roobahRect);
        }
        else if(halateroobah <= 60)
        {
            SBDL::showTexture(roobah2,roobahRect);
        }
        else if(halateroobah <= 70)
        {
            SBDL::showTexture(roobah3,roobahRect);
        } else if(halateroobah <= 80)
        {
            SBDL::showTexture(roobah4,roobahRect);
        }
        else if(halateroobah <= 90)
        {
            SBDL::showTexture(roobah,roobahRect);
        }
        halateroobah++;
        roobahRect.x += 5;
        roobahRect.y += speed;
        if(halateroobah == 91)
        {
            halateroobah = 0;
            roobahRect.x = 0;
            roobahRect.y = -30;
            //scoreroobah = false;
        }
    }
}

void showshield(){
   // srand(time(NULL));
    //shieldX = rand() % 41;
    //shieldY = rand() % 1000;
    //shieldRect = {38 , shieldY , 40 , 40};
    SBDL::showTexture(shield,shieldRect);
    shieldRect.y += speed;
    if(shieldRect.y > 500)
        shieldRect.y = -(rand()%3000 + 3000);
}

void showbadninja(){
    SBDL::showTexture(badninja,badninjaRect);
    badninjaRect.y += speed;
    if(badninjaRect.y > 500)                // 630
        badninjaRect.y = -(rand()%1000 + 1000);

}

void showblade() {
   badninjaRect.y += 2;

   if(badninjaRect.y >= 230) {
       SBDL::showTexture(blade, angle += 35, bladeRect);
       bladeRect.y = 20 + badninjaRect.y;                       // vaghti badninja be ye jayi resid tigh part kone
       bladeRect.x += 6;

       SBDL::showTexture(badninja, badninjaRect);
       if (badninjaRect.y > 500) {               // 630
           badninjaRect.y = -(rand() % 1000 + 1000);                 // partabe mojadade tighe
           bladeRect.y = 20 + badninjaRect.y;
           bladeRect.x = badninjaRect.x;
       }
   }
}

void showtighe(){
    SBDL::showTexture(tighe,tigheRect);
    tigheRect.y += speed;
    if(tigheRect.y > 500)                  // 1200
        tigheRect.y = -(rand()%5500 + 5500);
}

void showbalcony(){
    SBDL::showTexture(balcon,balconRect);
    balconRect.y += speed;
    if(balconRect.y > 900)                   //tarjihan random bashad
        balconRect.y = -(rand()%900 + 900);
}

void showbalconkoochika(){
    SBDL::showTexture(balconkoochike,balconkoochikeRect);
    balconkoochikeRect.y += speed;
    if(balconkoochikeRect.y > 900)              // tarjihan random bashad
        balconkoochikeRect.y = -(rand()%2000 + 2000);
}

void buildrakhtaviz(){
    // random bashad
    int bandY = -300; // rand() % 40
    rakhtavizRect = {40 /*bandX*/, bandY , 420 , 50};
}

void showrakhtaviz(){
    SBDL::showTexture(rakhtaviz,rakhtavizRect);
    rakhtavizRect.y += speed;
    if(rakhtavizRect.y == 500)
        rakhtavizRect.y = -500;
}

struct showghasr{
    SDL_Rect ghasrRect = {0 , 0 , 500 , 500};
};

showghasr castle;

void showghasr(){
    SBDL::showTexture(ghasr,castle.ghasrRect);
    castle.ghasrRect.y += speed; //2
}

void showwall(){
    SBDL::showTexture(wall, wallRect);
    wallRect.y += speed;
    if(wallRect.y==0) wallRect.y=-500;
}

void show_wallpaper(){
    // SBDL::showTexture(wallpaper,wallpaperRect);
    SBDL::showTexture(background, backgroundRect);
   // SBDL::showTexture(rakhtaviz,rakhtavizRect);
   //SBDL::showTexture(ninja,ninjaRect);
   //SBDL::showTexture(ninja2,ninja2Rect);
   //SBDL::showTexture(ninja3,ninja3Rect);
}

void loose(){
    SBDL::showTexture(gameover,gameoverpanelRect);
    Texture scoreText = SBDL::createFontTexture(font, " score :   " + to_string(score), 0, 0, 0);
    SBDL::showTexture(scoreText, 200, 130);
    Texture highscoreText = SBDL::createFontTexture(font, " highscore :  " + to_string(highscore), 0, 0, 0);
    SBDL::showTexture(highscoreText, 170, 180);
    SBDL::showTexture(play,playRect);
    SBDL::showTexture(quit,quitRect);
    if(SBDL::mouseInRect(playRect) && SBDL::Mouse.clicked()){
        state = 'g';
        score = 0;
        balconRect = {40 , -510 , 50 , 50};
        balconkoochikeRect = {410 , -900 , 50 , 50};
        tigheRect = {40 , -510 , 50 , 50};
        badninjaRect = {25 , -510 , 50 , 50};
        roobahRect = {40 , -45 , 60 , 50};
        bladeRect = {27 , -510 , 50 , 50};
        castle.ghasrRect = {0 , 0 , 500 , 500};
        rightbirdRect = {-100 , -100 , 60 , 60};
        fallingRect = {250 , 250 , 50 , 50};
    }
    if(SBDL::mouseInRect(quitRect) && SBDL::Mouse.clicked()){
        state = 'm';
    }
}

void menu(){
    SBDL::showTexture(menuwallpper,menuwallpaperRect);
    SBDL::showTexture(play,playRect);
    SBDL::showTexture(settingbtn,settingbtnRect);
    SBDL::showTexture(quitbtn,quitbtnRect);
    if(SBDL::mouseInRect(playRect) && SBDL::Mouse.clicked()){
        state = 'g';
    }
    if(SBDL::mouseInRect(settingbtnRect) && SBDL::Mouse.clicked()){
        state = 's';
    }
    if(SBDL::mouseInRect(quitbtnRect) && SBDL::Mouse.clicked()){
        SBDL::stop();
    }
}

void setting(){
    SBDL::showTexture(settingpage,settingpageRect);
    SBDL::showTexture(sound,soundRect);
    SBDL::showTexture(music,musicRect);
    SBDL::showTexture(backbtn,backbtnRect);
    if(SBDL::mouseInRect(backbtnRect) && SBDL::Mouse.clicked()){
        state = 'm';
    }
    if(musicgame) {
        if (SBDL::mouseInRect(musicRect) && SBDL::Mouse.clicked()) {
            // musicgame = false;
            SBDL::stopMusic();
        }
    }
    if(!musicgame){
        if(SBDL::mouseInRect(musicRect) && SBDL::Mouse.clicked()){
            SBDL::playMusic(moosighigame, -1);
        }
    }
    if(soundgame) {
        if (SBDL::mouseInRect(soundRect) && SBDL::Mouse.clicked()) {
            // musicgame = false;
            SBDL::stopAllSounds();
        }
    }
    if(!soundgame){
        if(SBDL::mouseInRect(soundRect) && SBDL::Mouse.clicked()){
            SBDL::playSound(soundbazi, 1);
        }
    }
}

void pause(){
    SBDL::showTexture(settingpage,settingpageRect);
    SBDL::showTexture(play,playRect);
    SBDL::showTexture(quit,quitRect);
    if(SBDL::mouseInRect(playRect) && SBDL::Mouse.clicked()){
        state = 'g';
    }
    if(SBDL::mouseInRect(quitRect) && SBDL::Mouse.clicked()){
        state = 'm';
    }
}

int main(int argc, char *argv[]) {
    const int window_width = 500;
    const int window_height = 500;
    SBDL::InitEngine("SBDL Test", window_width, window_height);

    const int FPS = 60; //frame per second
    const int delay = 1000 / FPS; //delay we need at each frame


    loadtexture();
    buildrakhtaviz();


    SBDL::playMusic(moosighigame, -1);


    srand(time(NULL));
    while (SBDL::isRunning()) {
           int startTime = SBDL::getTime();

            SBDL::updateEvents();
            SBDL::clearRenderScreen();

            //game logic code
            if(state == 'f'){
                showfalling();
            }
            if(state == 's'){
                setting();
            }
            if(state == 'l'){
                loose();
            }
            if(state == 'm'){
                menu();
            }
            if(state == 'p'){
                pause();
            }
            if(state == 'g') {
                score++;
                showwall();
                show_wallpaper();
                showblade();
                showbird();
                showroobah();
                showrakhtaviz();
                showtighe();
                showbadninja();
                harekatninja();
                harekatbashield();
                showshield();
                showghasr();
                showbalcony();
                showbalconkoochika();
                scorebox();
                hasintersection();
                emtiazgereftn();
               // showfalling();
                if(SBDL::keyPressed((SDL_SCANCODE_P)))
                    state = 'p';
            }

        SBDL::updateRenderScreen();

           int elapsedTime = SBDL::getTime() - startTime;
           if (elapsedTime < delay)
               SBDL::delay(delay - elapsedTime);

       }

    return 0;
}