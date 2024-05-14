#include <iostream>
#include <iomanip>
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
int stage = 1, totalStages = 4;

int main(int argc, char const *argv[]) {
    float fpsStage1 = 0, fpsStage2 = 0, fpsStage3 = 0, timeElapsedStage1 = 0, timeElapsedStage2 = 0, timeElapsedStage3 = 0;
    double totalTimeElapsed = 0;
    Clock _clock, _clock2, _clock3;
    Texture t1;
    t1.loadFromFile("logo_unespar_branco.png");

    RenderWindow window(VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), argv[0]+2);

    int stageAmount = 100, count = 0;
    while(count <= stageAmount) {
        node *ns = new node();
        Sprite s;
        s.setTexture(t1);
        s.setScale(0.2, 0.2);
        ns->setSprite(&s);
        l->addLast(ns);
        count++;
    }

    float deltaTime, fpsTotal = 0, fpsTimeElapsed = 0;

    // window.setFramerateLimit(30);
    _clock3.restart();
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) if(event.type == Event::Closed) window.close();

        if (_clock3.getElapsedTime().asSeconds() >= (5*stage)) {
            if (++stage == 5) {
                cout << "Teste completo..." << endl << endl;
                break;
            }
            fpsStage1 = fpsTimeElapsed;
            cout << "Estágio: " << stage << endl;
            cout << "Total de entidades: " << stageAmount << endl;
            cout << "Média de fps: " << (fpsTotal/fpsTimeElapsed) << endl;
            cout << "Tempo: " << (_clock3.getElapsedTime().asSeconds()/stage) << " segundos" << endl;

            fpsTimeElapsed = 0;
            stageAmount *= 10;
            while(count <= stageAmount) {
            node *ns = new node();
            Sprite s;
            s.setTexture(t1);
            s.setScale(0.2, 0.2);
            ns->setSprite(&s);
            l->addLast(ns);
            count++;
            }
            fpsTotal = 0;
            cout << "Iniciando próximo estágio..." << endl;
        }

        deltaTime = _clock.restart().asSeconds();
        float fps = 1.0f/deltaTime;
        if(_clock2.getElapsedTime().asSeconds() > 0.1f) {
            cout << "fps: " <<fixed << setprecision(0) << fps << endl;
            _clock2.restart();
            fpsTotal += fps;
            fpsTimeElapsed++;

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
    totalTimeElapsed = _clock3.getElapsedTime().asSeconds();
    cout << "Total de entidades: " << stageAmount << endl << "Média de fps: " << fixed << (fpsTotal/fpsTimeElapsed) << endl << "Tempo total: " << fixed << setprecision(1) << totalTimeElapsed << " segundos" << endl;
    // cout << "time total :" << totalTimeElapsed << " segundos" << endl;
    return 0;
}