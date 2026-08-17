#pragma once
class Player
{
private:
	int x;
	int y;
public:
	Player();
	~Player();
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	void Interact();
};

