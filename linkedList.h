#include <SFML/Graphics.hpp>

using namespace sf;

class node {
    private:
        Sprite *_sprite;
        node *next;
        node *previous;

    public:
        node();
        void setSprite(Sprite *sprite);
        Sprite *getSprite();
        void setNext(node *nex);
        node *getNext();
        void setPrevious(node *prev);
        node *getPrevious();
};

class linkedList{
    private:
        node *head;
        node *tail;
        int size;

    public:
        linkedList();
        void addLast(node *node);
        node *getHead();
        node *getTail();
        int getSize();
        void remove(node *node_);

};