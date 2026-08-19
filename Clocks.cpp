#include "Clocks.h"
Clocks::Clocks()
{

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