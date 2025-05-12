#include <iostream>
using namespace std;

struct Elem {
    Elem* link1;
    Elem* link2;
    int info;
};

int main() {
    Elem* p = new Elem; // 1
    p->info = 1;  

    p->link2 = new Elem; // 2
    p->link2->info = 2; // 3

    p->link1 = new Elem; // 4
    p->link1->info = 4; // 5

    p->link2->link1 = new Elem; // 6
    p->link2->link1->info = 3; // 7

    p->link2->link2 = nullptr; // 8
    p->link2->link1->link2 = nullptr; // 9

    p->link2->link1->link1 = p->link2; // 10
    p->link1->link1 = p->link2; // 11
    p->link1->link2 = p->link2->link1; // 12



    delete p->link2->link1;
    delete p->link1;
    delete p->link2;
    delete p;

    return 0;
}
