#include "Clocks.h"
Clocks::Clocks(string lines)
{
	line = lines;
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