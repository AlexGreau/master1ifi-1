#pragma once
#include "IDrawable.h"

# define M_PI           3.14159265358979323846  /* pi */

class DrawableObject : public IDrawable
{
protected:
	float x, y, width, height, r, g, b;

public:
	DrawableObject(float x, float y, float width, float height, float r, float g, float b) 
		: x(x), y(y), width(width), height(height), r(r), g(g), b(b) {};

	~DrawableObject();

	/* virtual void Draw() const = 0; donn't know if i should write this */ 

	// Setters d�claration inline implicite
	void setX		(float x)		{ this->x = x; }
	void setY		(float y)		{ this->y = y; }
	void setWidth	(float width)	{ this->width = width; }
	void setHeight	(float height)	{ this->height = height; }
	void setRGB		(float r, float g, float b) { this->r = r; this->g = g; this->b = b; }
	
	// Getters
	float getX()		{ return x; }
	float getY()		{ return y; }
	float getWidth()	{ return width; }
	float getHeight()	{ return height; }
	float getR()		{ return r; }
	float getG()		{ return g; }
	float getB()		{ return b; }

	//void Rotate(float direction);

};
/*
void DrawableObject::Rotate(float direction) {
	//TODO: implement drawing rotation
}
*/