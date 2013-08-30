#ifndef GAMESTATE_H
#define GAMESTATE_H

class Gamestate
{
private:
public:
	virtual void update() = 0;
}; // class Gamestate



class Title:Gamestate
{
private:
public:
	virtual void update();
}; // class Title



class Platform:Gamestate
{
private:
public:
	virtual void update();
}; // class Platform

#endif
