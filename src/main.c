#include "raylib.h"
#include <stdlib.h>

#include "../include/game.h"
#include "../include/player.h"
#include "../include/enemy.h"
#include "../include/bullet.h"
#include "../include/explosion.h"
#include "../include/collision.h"
#include "../include/enemybullet.h"

float shakeTimer = 0.0f;

int main(void)
{
    bool gameOver = false;
    int score = 0;

    InitWindow(
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        "Galactic Defender");
    

    SetTargetFPS(60);

    Font titleFont =
        LoadFont("assets/fonts/Orbitron-Regular.ttf");

    InitAudioDevice();

    Sound shootSound =
        LoadSound("assets/sounds/shoot.mp3");

    Sound explosionSound =
        LoadSound("assets/sounds/explosion.mp3");

    Texture2D background =
        LoadTexture("assets/images/background.png");

    Texture2D enemyTexture1 =
        LoadTexture("assets/images/enemy1.png");

    Texture2D enemyTexture2 =
        LoadTexture("assets/images/enemy2.png");

    Texture2D bulletTexture =
        LoadTexture("assets/images/bullet.png");

    Texture2D enemyBulletTexture =
        LoadTexture("assets/images/enemyBullet.png");

    Texture2D explosionTexture =
        LoadTexture("assets/images/explosion.png");

    Texture2D playerExplosionTexture =
        LoadTexture("assets/images/playerExplosion.png");

    Player player;
    InitPlayer(&player);

    Bullet bullets[MAX_BULLETS];
    InitBullets(
        bullets,
        MAX_BULLETS);

    Enemy enemies[MAX_ENEMIES];
    InitEnemies(
        enemies,
        MAX_ENEMIES);

    EnemyBullet enemyBullets[MAX_ENEMY_BULLETS];
    InitEnemyBullets(
        enemyBullets);

    Explosion explosions[MAX_EXPLOSIONS];
    InitExplosions(
        explosions);

    while(!WindowShouldClose())
    {
        if(!gameOver)
        {
            UpdatePlayer(
                &player);

            UpdateBullets(
                bullets,
                MAX_BULLETS);

            UpdateEnemies(
                enemies,
                MAX_ENEMIES);

            EnemyShoot(
                enemies,
                MAX_ENEMIES,
                enemyBullets);

            UpdateEnemyBullets(
                enemyBullets);

            for(int i=0;i<MAX_ENEMY_BULLETS;i++)
{
    if(!enemyBullets[i].active)
        continue;

    if(CheckCollisionRecs(
        GetPlayerRect(&player),
        GetEnemyBulletRect(&enemyBullets[i])))
    {
        enemyBullets[i].active = 0;

        player.health -= 10;

        shakeTimer = 0.25f;

        PlaySound(explosionSound);

        if(player.health < 0)
            player.health = 0;

        if(player.health <= 0)
        {
            gameOver = true;
        }
    }
}

            UpdateExplosions(
                explosions);

            if(shakeTimer > 0)
                shakeTimer -= GetFrameTime();

            Rectangle playerRect =
                GetPlayerRect(&player);

            for(int i = 0; i < MAX_ENEMIES; i++)
            {
                if(!enemies[i].active)
                    continue;

                if(CheckCollisionRecs(
                    playerRect,
                    GetEnemyRect(&enemies[i])))
                {
                    player.health -= 20;

                    if(player.health < 0)
                        player.health = 0;

                    shakeTimer = 0.35f;

                    CreateExplosion(
                        explosions,
                        player.x + player.width/2,
                        player.y + player.height/2);

                    CreateExplosion(
                        explosions,
                        enemies[i].x + enemies[i].width/2,
                        enemies[i].y + enemies[i].height/2);

                    PlaySound(
                        explosionSound);

                    enemies[i].active = 0;

                    if(player.health <= 0)
                        gameOver = true;
                }
            }

            CheckBulletEnemyCollision(
                bullets,
                MAX_BULLETS,
                enemies,
                MAX_ENEMIES,
                explosions,
                &score,
                explosionSound);

            if(IsKeyPressed(KEY_SPACE))
            {
                FireBullet(
                    bullets,
                    MAX_BULLETS,
                    player.x + player.width/2,
                    player.y);

                PlaySound(
                    shootSound);
            }
        }

        BeginDrawing();

        ClearBackground(BLACK);

                Camera2D camera = {0};

        if(shakeTimer > 0)
        {
            camera.target = (Vector2){
                GetRandomValue(-6,6),
                GetRandomValue(-6,6)
            };
        }
        else
        {
            camera.target = (Vector2){0,0};
        }

        camera.offset = (Vector2){0,0};
        camera.rotation = 0;
        camera.zoom = 1;

        BeginMode2D(camera);

        DrawTexturePro(
            background,
            (Rectangle){
                0,
                0,
                (float)background.width,
                (float)background.height
            },
            (Rectangle){
                0,
                0,
                SCREEN_WIDTH,
                SCREEN_HEIGHT
            },
            (Vector2){0,0},
            0,
            WHITE);

        DrawEnemies(
            enemies,
            MAX_ENEMIES,
            enemyTexture1,
            enemyTexture2);

        DrawBullets(
            bullets,
            MAX_BULLETS,
            bulletTexture);

        DrawEnemyBullets(
            enemyBullets,
            enemyBulletTexture);

        DrawPlayer(
            &player);

        DrawExplosions(
            explosions,
            explosionTexture);

        EndMode2D();

        DrawTextEx(
            titleFont,
            "GALACTIC DEFENDER",
            (Vector2){20,15},
            34,
            2,
            GOLD);

        Color hpColor;

        if(player.health > 60)
            hpColor = GREEN;
        else if(player.health > 30)
            hpColor = YELLOW;
        else
            hpColor = RED;

        DrawText(
            "HEALTH",
            22,
            56,
            16,
            WHITE);

        DrawRectangle(
            22,
            78,
            140,
            8,
            DARKGRAY);

        DrawRectangle(
            22,
            78,
            player.health * 1.4f,
            8,
            hpColor);

        DrawRectangleLines(
            22,
            78,
            140,
            8,
            WHITE);

        DrawText(
            TextFormat("SCORE : %d",score),
            SCREEN_WIDTH - 220,
            20,
            28,
            YELLOW);

        DrawFPS(
            SCREEN_WIDTH - 100,
            60);

                //==========================
        // PLAYER EXPLOSION
        //==========================

        if(player.health <= 0)
        {
            if(!gameOver)
{
    DrawPlayer(&player);
}
        }

        //==========================
        // GAME OVER SCREEN
        //==========================

        if(gameOver)
        {
            DrawRectangle(
                0,
                0,
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                Fade(BLACK,0.70f));

            DrawText(
                "GAME OVER",
                SCREEN_WIDTH/2 - 170,
                SCREEN_HEIGHT/2 - 80,
                55,
                RED);

            DrawText(
                TextFormat("FINAL SCORE : %d",score),
                SCREEN_WIDTH/2 - 130,
                SCREEN_HEIGHT/2,
                32,
                GOLD);

            DrawText(
                "PRESS ENTER TO PLAY AGAIN",
                SCREEN_WIDTH/2 - 210,
                SCREEN_HEIGHT/2 + 60,
                28,
                WHITE);

            if(IsKeyPressed(KEY_ENTER))
            {
                score = 0;

                gameOver = false;

                shakeTimer = 0;

                InitPlayer(&player);

                InitEnemies(
                    enemies,
                    MAX_ENEMIES);

                InitBullets(
                    bullets,
                    MAX_BULLETS);

                InitEnemyBullets(
                    enemyBullets);

                InitExplosions(
                    explosions);
            }
        }

        EndDrawing();
    }
        //-----------------------------
    // Cleanup
    //-----------------------------

    UnloadTexture(background);

    UnloadTexture(enemyTexture1);

    UnloadTexture(enemyTexture2);

    UnloadTexture(bulletTexture);

    UnloadTexture(enemyBulletTexture);

    UnloadTexture(explosionTexture);

    UnloadTexture(playerExplosionTexture);

    UnloadTexture(player.texture);

    UnloadFont(titleFont);

    UnloadSound(shootSound);

    UnloadSound(explosionSound);

    CloseAudioDevice();

    CloseWindow();

    return 0;
}