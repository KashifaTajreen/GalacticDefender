#include "../include/player.h"
#include "../include/game.h"

void InitPlayer(Player *player)
{
    player->texture = LoadTexture("assets/images/player.png");

    player->width = PLAYER_WIDTH;
    player->height = PLAYER_HEIGHT;

    player->x = (SCREEN_WIDTH - PLAYER_WIDTH) / 2;
    player->y = SCREEN_HEIGHT - PLAYER_HEIGHT - 30;

    player->health = PLAYER_HEALTH;

    player->speed = PLAYER_SPEED;
}

void UpdatePlayer(Player *player)
{
    // Left
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        player->x -= player->speed;

    // Right
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        player->x += player->speed;

    // Up
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        player->y -= player->speed;

    // Down
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        player->y += player->speed;

    // Keep player inside screen
    if (player->x < 0)
        player->x = 0;

    if (player->x > SCREEN_WIDTH - player->width)
        player->x = SCREEN_WIDTH - player->width;

    if (player->y < 0)
        player->y = 0;

    if (player->y > SCREEN_HEIGHT - player->height)
        player->y = SCREEN_HEIGHT - player->height;
}

void DrawPlayer(Player *player)
{
    Rectangle source = {
        0,
        0,
        (float)player->texture.width,
        (float)player->texture.height
    };

    Rectangle destination = {
        player->x,
        player->y,
        player->width,
        player->height
    };

    DrawTexturePro(
        player->texture,
        source,
        destination,
        (Vector2){0, 0},
        0.0f,
        WHITE
    );
}

Rectangle GetPlayerRect(Player *player)
{
    Rectangle rect;

    rect.x = player->x + 10;
    rect.y = player->y + 10;

    rect.width = player->width - 20;
    rect.height = player->height - 20;

    return rect;
}