#ifndef LIST_HPP
#define LIST_HPP

struct Node;

struct List
{
    Node* first{};
};

void insert(List& list, int value);

void remove(List& list, int index);

void print(const List& list);

void copy(const List& source, List& destination);

void clear(List& list);

#endif