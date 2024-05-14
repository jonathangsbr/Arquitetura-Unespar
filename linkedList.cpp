#include <iostream>
#include "linkedList.h"

using namespace std;

node::node() {
    _sprite = nullptr;
    next = nullptr;
    previous = nullptr;
}

void node::setSprite(Sprite *sprite) {
    _sprite = sprite;
}

Sprite *node::getSprite() {
    return _sprite;
}

void node::setNext(node *nex) {
    next = nex;
}

node *node::getNext() {
    return next;
}

void node::setPrevious(node *prev) {
    previous = prev;
}

node *node::getPrevious() {
    return previous;
}

linkedList::linkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void linkedList::addLast(node *node) {
    size++;
    if(head == nullptr) {
        head = node;
        tail = node;
        return;

    }
    tail->setNext(node);
    node->setPrevious(tail);
    tail = node;
}

node *linkedList::getHead() {
    return head;
}

node *linkedList::getTail() {
    return tail;
}

int linkedList::getSize() {
    return size;
}

void linkedList::remove(node *node_) {
    if(size == 0) {
        return;
    }
    size--;
    if (node_ == head && node_ == tail) {
        head = nullptr;
        tail = nullptr;
        delete node_;
        return;
    }
    node *nodeP = node_->getPrevious();
    node *nodeN = node_->getNext();
    if (tail == node_) {
        tail = nodeP;
        tail->setNext(nullptr);
        return;
        
    } else if (head == node_) {
        head = nodeN;
        head->setPrevious(nullptr);
        return;
    }
    nodeP->setNext(nodeN);
    nodeN->setPrevious(nodeP);
    delete node_;
}