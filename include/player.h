#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct
{
    Texture2D texture;

    float x;
    float y;

    float width;
    float height;

    int health;

    float speed;

} Player;

void InitPlayer(Player *player);

void UpdatePlayer(Player *player);

void DrawPlayer(Player *player);

Rectangle GetPlayerRect(Player *player);

#endif