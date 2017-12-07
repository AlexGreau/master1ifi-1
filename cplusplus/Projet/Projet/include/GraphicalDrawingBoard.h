#pragma once

#include <vector>
#include "GraphicEngineBase.h"
#include "IDrawable.h"

class GraphicalDrawingBoard : public GraphicEngineBase {

	std::vector<IDrawable *>* drawables;

	// Checkboard
	int size;
	float x1, y1, x2, y2;

	virtual float xCoordToPercent(int x);
	virtual float yCoordToPercent(int y);

public:

	GraphicalDrawingBoard(int n, float x1, float y1, float x2, float y2)
		: size(n), x1(x1), y1(y1), x2(x2), y2(y2) {
		drawables = new std::vector<IDrawable *>;
	};

	virtual void Draw();

	virtual void addDrawable(IDrawable* drawable);
	virtual void removeDrawable(IDrawable* drawable);

	virtual int getCheckboardX(float x);
	virtual int getCheckboardY(float y);
	virtual float getXCoordFor(int x);
	virtual float getYCoordFor(int y);

	virtual bool isCheckboard(float x, float y);
	virtual bool isLeftMenu(float x, float y);
	virtual bool isDownMenu(float x, float y);

};