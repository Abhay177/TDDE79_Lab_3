#include <iostream>
#include "list.hpp"

using namespace std;

int main()
{
    List original{};
    List copied{};

    int value{};
    int index{};

    cout << "Enter values (exit by entering negative number): ";

    while (cin >> value && value >= 0)
    {
        insert(original, value);
    }

    cout << "List: ";
    print(original);
    cout << endl;

    copy(original, copied);

    cout << "Enter indices of elements to remove: ";

    while (cin >> index && index >= 0)
    {
        remove(copied, index);
    }

    cout << "Original list: ";
    print(original);
    cout << endl;

    cout << "Copied list: ";
    print(copied);
    cout << endl;

    clear(original);

    cout << "Cleared the original!" << endl;

    cout << "Original list: ";
    print(original);
    cout << endl;

    cout << "Copied list: ";
    print(copied);
    cout << endl;

    clear(copied);

    return 0;
}