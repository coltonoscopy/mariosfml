#pragma once

#ifndef CORE_H
#define CORE_H

#include "Map.h"

class CCore {
private:
    sf::RenderWindow* window;

    // FPS
    long frameTime;
    static const int MIN_FRAME_TIME = 16;

    unsigned long lFPSTime;
    int iNumOfFPS, iFPS;

    // INPUT
    static bool movePressed, keyMenuPressed, keyS, keyW, keyA, keyD, keyShift;

    static bool keyAPressed, keyDPressed;
    // true = RIGHT, false = LEFT
    bool firstDir;

    static Map* oMap;

    // Methods

    void Input();
    void MouseInput();
    void InputPlayer();
    void InputMenu();

public:
    CCore(void);
    ~CCore(void);

    static bool quitGame;

    void mainLoop();

    void Update();
    void Draw();

    void resetMove();
    static void resetKeys();

    static bool mouseLeftPressed, mouseRightPressed;
    static int mouseX, mouseY;

    // get and set
    static Map* getMap();
};

#endif
