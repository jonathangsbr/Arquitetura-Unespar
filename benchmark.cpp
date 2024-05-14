#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "linkedList.h"

using namespace std;
using namespace sf;

static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 600;
static const int X_CENTER = WINDOW_WIDTH/2;
static const int Y_CENTER = WINDOW_HEIGHT/2;

linkedList *l = new linkedList();
float fpsStage1 = 0, fpsStage2 = 0, fpsStage3 = 0;
float timeElapsedStage1 = 0, timeElapsedStage2 = 0, timeElapsedStage3 = 0;

int main(int argc, char const *argv[]) {
    RenderWindow window(VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), argv[0]+2);

    Texture t1;
    t1.loadFromFile("logo_unespar_branco.png");

    int stageAmount = 10000, count = 0;
    while(count <= stageAmount) {
        node *ns = new node();
        Sprite s;
        s.setTexture(t1);
        s.setScale(0.2, 0.2);
        ns->setSprite(&s);
        l->addLast(ns);
        count++;
    }

    Clock _clock, _clock2;
    float deltaTime;
    float fpsTotal = 0, timeElapsed = 0;

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
            if(event.type == Event::Closed) window.close();
        }
        deltaTime = _clock.restart().asSeconds();
        float fps = 1.0f/deltaTime;
        if(_clock2.getElapsedTime().asSeconds() > 0.1f) {
            cout << fps << endl;
            fpsTotal += fps;
            _clock2.restart();
            timeElapsed++;

        }
        window.clear();
        node *n = l->getHead();
            while(n != nullptr) {
                Sprite s = *n->getSprite();
                s.setPosition(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT);
                window.draw(s);
                n = n->getNext();
            }
        window.display();
    }
        
    cout << "Total de entidades: " << stageAmount << endl << "Média de fps: " << (fpsTotal/timeElapsed) << endl << "Tempo total: " << timeElapsed/10 << " segundos" << endl;
    return 0;
}