

#ifndef GAMEOBSERVER_H
#define GAMEOBSERVER_H


class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void update() = 0;
};

//part1 : trun observers
/*
Using the Observer design pattern, implement a view that displays information happening in the
current turn.It should first display a
header showing what playerand what is currently being
played, example: The active player 2 : plays a Harvest Tile by placing it on the Game Board,

this play,
i) will generate resources collected that will be indicated by an increase of Resource Markers.

Then, this active player will construct Buildings in his / her Village using the corresponding
resources.

ii) Which will update the village buildings count of the player.

For every building played

iii) It will result in a decrease of corresponding Resources Marker by the number of the played
Building

	*/




#endif // !GAMEOBSERVER_H
