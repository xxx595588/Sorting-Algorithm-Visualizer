#include "Rectangle.h"

Rectangle::Rectangle() {
	
}

Rectangle::Rectangle(int h, sf::RectangleShape r) {
	setHeight(h);
	setShape(r);
}

void Rectangle::setHeight(int h) {
	this->height = h;
}

void Rectangle::setShape(sf::RectangleShape r) {
	this->shape = r;
}

int &Rectangle::getHeight() {
	return this->height;
}

sf::RectangleShape &Rectangle::getShape() {
	return this->shape;
}

void Rectangle::setShapePos(int pos, int width) {
	shape.setFillColor(sf::Color::White);
	shape.setScale(1, 2);
	shape.rotate(180);
	updateShapePos((pos + 1) * width, 500);
}

void Rectangle::updateShapePos(int pos, int width) {
	shape.setPosition((pos + 1) * width, 500);
}