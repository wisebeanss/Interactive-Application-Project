#include "Doors.h"
Doors::Doors(string lines, int x, int y, int id) : InteractiveObject("Doors", id)
{
	line = lines;
	setX(x);
	setY(y);
}
Doors::~Doors()
{

}
void Doors::setLine(string lines)
{
	line = lines;
}
void Doors::use()
{
	cout << line;
}