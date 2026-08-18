#pragma once
class GameObject
{
private:
	int x;
	int y;
public:
	GameObject(int x, int y);
	~GameObject();
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
};

