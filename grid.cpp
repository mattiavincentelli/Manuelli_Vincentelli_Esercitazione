#include "grid.h"
#include <iostream>

using namespace std;

grid::grid(float w, float h) {
    if(w > 0 && h > 0 )
        width = w, height = h, cout << "grid - constructor" << endl;
    else 
        cout << "invalid height and/or width";
}

grid::grid(const grid &r) {
    cout << "grid - copy constructor";
    width = r.width;
    height = r.height;
}

float grid::GetHeight(){
    return height;
}

float grid::GetWidth(){
    return width;
}
