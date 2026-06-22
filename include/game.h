#ifndef GAME_H
#define GAME_H

/*--------------------------------------------------
    WINDOW
--------------------------------------------------*/
#define SCREEN_WIDTH   1600
#define SCREEN_HEIGHT   900

/*--------------------------------------------------
    PLAYER
--------------------------------------------------*/
#define PLAYER_WIDTH    100
#define PLAYER_HEIGHT   100
#define PLAYER_SPEED    8.0f
#define PLAYER_HEALTH   100

/*--------------------------------------------------
    BULLETS
--------------------------------------------------*/
#define MAX_BULLETS     100

#define BULLET_WIDTH    24
#define BULLET_HEIGHT   48
#define BULLET_SPEED    14.0f

/*--------------------------------------------------
    ENEMIES
--------------------------------------------------*/
#define MAX_ENEMIES     8

#define ENEMY1_WIDTH    110
#define ENEMY1_HEIGHT   110

#define ENEMY2_WIDTH    170
#define ENEMY2_HEIGHT   170

#define ENEMY1_SPEED    3.5f
#define ENEMY2_SPEED    2.0f

#define ENEMY1_HEALTH   1
#define ENEMY2_HEALTH   5

/*--------------------------------------------------
    EXPLOSIONS
--------------------------------------------------*/
#define MAX_EXPLOSIONS  20

#define EXPLOSION_SIZE  170

/*--------------------------------------------------
    GAME
--------------------------------------------------*/
#define SCORE_SMALL     10
#define SCORE_BIG       50

#endif