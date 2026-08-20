#pragma once
#include "InteractiveObject.h"
#include<string>
using namespace std;
class Doors :
    public InteractiveObject
{
    private:
        string line;
        int roomID = 0;
        int question = 0;


    public:
         Doors(string lines, int X, int Y, int id);
        ~Doors();
   
        void setLine(string line);
        void use();
};

