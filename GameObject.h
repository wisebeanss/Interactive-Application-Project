#pragma once
class GameObject
{
private:
	int x;
	int y;
	char symbol;
public:
	GameObject(int x, int y, char symbol);
	~GameObject();
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
	char getSymbol() const;
	void setSymbol(char symbol);
};

