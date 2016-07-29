#include "header.hpp"
#include "Core.hpp"
#include "IMG.hpp"
#include "CFG.hpp"
#include "Text.hpp"

Map* CCore::oMap = new Map();
bool CCore::mouseLeftPressed = false;
bool CCore::mouseRightPressed = false;
int CCore::mouseX = 0;
int CCore::mouseY = 0;
bool CCore::quitGame = false;

bool CCore::movePressed = false;
bool CCore::keyMenuPressed = false;
bool CCore::keyS = false;
bool CCore::keyW = false;
bool CCore::keyA = false;
bool CCore::keyD = false;
bool CCore::keyShift = false;
bool CCore::keyAPressed = false;
bool CCore::keyDPressed = false;

CCore::CCore(void) {
    this->quitGame = false;
    this->iFPS = 0;
    this->iNumOfFPS = 0;
    this->lFPSTime = 0;

    window = sf::RenderWindow(sf::VideoMode(CCFG::GAMEWIDTH, CCFG::GAMEHEIGHT), "uMario SFML");

    // ICO
    sf::Image iconImage;
    iconImage.loadFromFile("files/images/ico.bmp");
    iconImage.createMaskFromColor(sf::Color(255, 0, 255));
    window.setIcon(iconImage.getSize().x, iconImage.getSize().y, iconImage.getPixelsPtr());

    oMap = new Map(window);
    CCFG::getMM()->setActiveOption(window);
    CCFG::getSMBLOGO()->setIMG("super_mario_bros", window);

    CCFG::getMusic()->PlayMusic();

    this->keyMenuPressed = this->movePressed = this->keyS = this->keyW = this->keyA = this->keyD = this->keyShift = false;

    this->keyAPressed = this->keyDPressed = this->firstDir = false;

    this->mouseX = this->mouseY = 0;


}

CCore::~CCore() {
    delete oMap;
}

CCore::mainLoop() {
    while (window.isOpen()) {
        Input();
        MouseInput();
        Update();
        window.clear();
        window.display();
        Draw();
    }
}

void CCore::Input() {
    switch (CCFG::getMM()->getViewID()) {
        case 2: case 7:
            if (!oMap->getInEvent()) {
                InputPlayer();
            } else {
                resetMove();
            }
            break;
        default:
            InputMenu();
            break;
    }
}

void CCore::InputMenu() {
    sf::Event e;
    while (window.pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            window.close();
        }
        if (e.type == sf::Event::KeyPressed) {
            switch (e.key.code) {
                case sf::Keyboard::Down: case sf::Keyboard::S:
                    if (!keyMenuPressed) {
                        CCFG::getMM()->keyPressed(2);
                        keyMenuPressed = true;
                    }
                    break;
                case sf::Keyboard::Up: case sf::Keyboard::W:
                    if (!keyMenuPressed) {
                        CCFG::getMM()->keyPressed(0);
                        keyMenuPressed = true;
                    }
                    break;
                case sf::Keyboard::Enter: case sf::Keyboard::Return:
                    if (!keyMenuPressed) {
                        CCFG::getMM()->enter();
                        keyMenuPressed = true;
                    }
                    break;
                case sf::Keyboard::Escape:
                    if (!keyMenuPressed) {
                        CCFG::getMM()->escape();
                        keyMenuPressed = true;
                    }
                    break;
                case sf::Keyboard::Left: case sf::Keyboard:D:
                    if (!keyMenuPressed) {
                        CCFG::getMM()->keyPressed(3);
                        keyMenuPressed = true;
                    }
                    break;
                case sf::Keyboard::Right: case sf::Keyboard::A:
                    if (!keyMenuPressed) {
                        CCFG::getMM()->keyPressed(1);
                        keyMenuPressed = true;
                    }
                    break;
            }
        }

        if (e.type == sf::Event::KeyReleased) {
            switch (e.key.code) {
                case sf::Keyboard::S: case sf::Keyboard::Down: case sf::Keyboard::W:
                case sf::Keyboard::Up: case sf::Keyboard::Enter: case sf::Keyboard::Return:
                case sf::Keyboard::Escape: case sf::Keyboard::A: case sf::Keyboard::Right:
                case sf::Keyboard::Left: case sf::Keyboard::D:
                    keyMenuPressed = false;
                    break;
                default:
                    break;
            }
        }
    }
}

void CCore::InputPlayer() {
    sf::Event e;
    while (window.pollEvent(e)) {
        
    }
}
