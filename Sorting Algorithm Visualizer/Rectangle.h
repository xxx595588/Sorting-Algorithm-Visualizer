#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>

class Rectangle {

private:
	int height;
	sf::RectangleShape shape;

	void setHeight(int);
	void setShape(sf::RectangleShape);

public:

	Rectangle();
	Rectangle(int, sf::RectangleShape);
	void setShapePos(int, int);
	void updateShapePos(int, int);
	int &getHeight();
	sf::RectangleShape &getShape();
};


#endif

