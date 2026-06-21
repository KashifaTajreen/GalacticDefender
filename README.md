# 🚀 Galactic Defender

Galactic Defender is a 2D space shooter game developed in **C** using the **Raylib** graphics library.

The player controls a spaceship, destroys enemy ships, avoids enemy attacks, and survives as long as possible while earning points.

---

## 🎮 Features

- 🚀 Player spaceship movement
- 🔫 Player shooting system
- 👾 Two enemy types
  - Small Enemy
  - Boss Enemy
- ❤️ Health system for player and enemies
- 📊 Enemy health bars
- 💥 Explosion effects
- 🔊 Sound effects
- 📳 Screen shake on collisions
- ⭐ Score system
- ☠️ Game Over screen
- 🔄 Restart game using **ENTER**

---

## 🕹 Controls

| Key | Action |
|------|--------|
| ← | Move Left |
| → | Move Right |
| Space | Shoot |
| Enter | Restart after Game Over |

---

## 🛠 Technologies Used

- C Programming
- Raylib 5.5
- MinGW-w64 GCC
- Visual Studio Code

---

## 📁 Project Structure

```
SpaceShooter/
│
├── assets/
│   ├── fonts/
│   ├── images/
│   └── sounds/
│
├── include/
│
├── src/
│
├── build/
│
├── README.md
└── .gitignore
```

---

## ▶️ Build

Compile the project using GCC and Raylib.

Example:

```bash
gcc src/*.c -o GalacticDefender.exe ^
-Iinclude ^
-I"C:\raylib\include" ^
-L"C:\raylib\lib" ^
-lraylib -lopengl32 -lgdi32 -lwinmm
```

---

## 📷 Gameplay

The player controls a spaceship to destroy incoming enemies while avoiding collisions and enemy bullets. Boss enemies have higher health, fire powerful attacks, and award more points when defeated.

---


Developed as a C programming mini-project using the Raylib game development library.

---
