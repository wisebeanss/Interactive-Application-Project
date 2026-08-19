#include "Clocks.h"
Clocks::Clocks(string lines,int x , int y) : InteractiveObject()
{
	line = lines;
	setX(x);
	setY(y);
}
Clocks::~Clocks()
{

}
void Clocks::setLine(string lines)
{
	line = lines;
}
void Clocks::use()
{
	cout << line;
}