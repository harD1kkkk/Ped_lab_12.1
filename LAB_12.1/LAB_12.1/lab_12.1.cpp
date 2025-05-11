#include <iostream>
using namespace std;

struct Elem {
    Elem* link1;
    Elem* link2;
    int info;
};

int main() {
    Elem* p = new Elem;      
    p->info = 1;

    p->link2 = new Elem;
    p->link2->info = 2;

    p->link1 = new Elem;
    p->link1->info = 4;

    p->link2->link1 = new Elem;
    p->link2->link1->info = 3;

    p->link2->link2 = nullptr;         
    p->link2->link1->link2 = nullptr;           

    p->link2->link1->link1 = p->link2;         
    p->link1->link1 = p->link2;          
    p->link1->link2 = p->link2->link1;  

    Elem* n2 = p->link1;
    Elem* n3 = n2->link1;
    Elem* n4 = p->link2;

    delete n4;    
    delete n3;
    delete n2;
    delete p;

    return 0;
}
/*#include <iostream>
using namespace std;

struct Elem {
    Elem* link1;
    Elem* link2;
    int info;
};

int main() {
    Elem* p = new Elem;      
    p->info = 1;

    p->link1 = new Elem;
    p->link1->info = 2;

    p->link2 = new Elem;
    p->link2->info = 4;

    p->link1->link1 = new Elem;
    p->link1->link1->info = 3;

    p->link1->link2 = nullptr;         
    p->link1->link1->link2 = nullptr;           

    p->link1->link1->link1 = p->link1;         
    p->link2->link1 = p->link1;          
    p->link2->link2 = p->link1->link1;  

    Elem* n2 = p->link1;
    Elem* n3 = n2->link1;
    Elem* n4 = p->link2;

    delete n4;    
    delete n3;
    delete n2;
    delete p;

    return 0;
}
*/
