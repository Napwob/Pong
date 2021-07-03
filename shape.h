#ifndef SHAPE_H
#define SHAPE_H

#include <graphics.h>
#include "const.h"

class Shape
{
protected:
    int color;
    int posX;
    int posY;
    int height;
    int width;
    int speedX;
    int speedY;
public:
    Shape(): color(rand() % 15 + 1),
             speedX(MAX_MOVE_SPEED),
             speedY(MAX_MOVE_SPEED),
             posX(rand() % WSX), posY(rand() % WSY)
    {};
    
    int getColor() const;
    void setColor(const int color);
    
    int getPosX() const;
    void setPosX(const int x);

    int getPosY() const;
    void setPosY(const int y);
    
    int getHeight() const;
    void setHeight(const int height);
    
    int getWidth() const;
    void setWidth(const int width);
    
    int getSpeedX() const;
    void setSpeedX(const int speed);
    
    int getSpeedY() const;
    void setSpeedY(const int speed);
    
    int setSpeed(const int speedX, const int speedY);

    int directMove(int y1, int y2);
    
    Shape* makeShape(int s);

    virtual void draw(const int shapeColor = -1) = 0;
};



class Rect: public Shape
{
public:
    Rect() {
        //setCoords(rand() % WSX, rand() % WSY, rand() % WSX, rand() % WSY);
        setCoords(70, 70, 120, 250);
    }
    Rect(const int color, const int x1, const int y1, const int x2, const int y2) {
             
        setColor(color);
        setCoords(x1, y1, x2, y2);
    }
	  
    void setCoords(const int x1, const int y1, const int x2, const int y2);
    void draw(const int shapeColor = 15);
};



class Circle: public Shape
{
public:
    Circle() {
        setCoords(WSX/2, WSY/2, 25);
    }
    Circle(const int color, const int x, const int y,
           const int radius, const int speedX, const int speedY) {    
		  
        setColor(color);
        setCoords(x, y, radius);
        setSpeed(speedX, speedY);
    }
    
    void setCoords(const int x, const int y, const int radius);
    void draw(const int shapeColor = 15);
};

void drawrowsanimation();
void drawrows();

void draw0(int x,int y);
void draw1(int x,int y);
void draw2(int x,int y);
void draw3(int x,int y);

void rightwinner();
void leftwinner();

#endif
