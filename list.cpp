#include <iostream>
#include "list.hpp"

using namespace std;

struct Node
{
    int value{};
    Node* next{};
};

void insert(List& list, int value)
{
    Node* new_node{new Node{value, nullptr}};

    if (list.first == nullptr || value < list.first->value)
    {
        new_node->next = list.first;
        list.first = new_node;
        return;
    }

    Node* current{list.first};

    while (current->next != nullptr &&
           current->next->value <= value)
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void remove(List& list, int index)
{
    if (index < 0 || list.first == nullptr)
    {
        return;
    }

    Node* current{list.first};
    Node* previous{};
    int current_index{};

    while (current != nullptr && current_index < index)
    {
        previous = current;
        current = current->next;
        ++current_index;
    }

    if (current == nullptr)
    {
        return;
    }

    if (previous == nullptr)
    {
        list.first = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    delete current;
}

void print(const List& list)
{
    Node* current{list.first};
    bool first_value{true};

    while (current != nullptr)
    {
        if (!first_value)
        {
            cout << " ";
        }

        cout << current->value;

        first_value = false;
        current = current->next;
    }
}

void copy(const List& source, List& destination)
{
    if (&source == &destination)
    {
        return;
    }

    clear(destination);

    Node* current{source.first};

    while (current != nullptr)
    {
        insert(destination, current->value);
        current = current->next;
    }
}

void clear_nodes(Node* current)
{
    if (current == nullptr)
    {
        return;
    }

    clear_nodes(current->next);

    delete current;
}

void clear(List& list)
{
    clear_nodes(list.first);
    list.first = nullptr;
}