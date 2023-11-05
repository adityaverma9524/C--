#include <iostream>
using namespace std;
#include "Template.h"

int main() {
    /*
    Pair<int> p1;

    p1.setX(10);
    p1.setY(20);
    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<double> p2;

    p2.setX(100.34);
    p2.setY(34.21);
    cout << p2.getX() << " " << p2.getY() << endl;
    */
   
   /*
   Pair<int, double> p1;

   p1.setX(5);
   p1.setY(5.5);
   cout << p1.getX() << " " << p1.getY() << endl;
   */

    Pair<Pair<int, int>, int> p1;
    p1.setY(10);

    Pair<int, int> p2;
    p2.setX(5);
    p2.setY(16);

    p1.setX(p2);

    cout << p1.getX().getX() << " " << p1.getX().getY() << " " << p1.getY() << endl;
}