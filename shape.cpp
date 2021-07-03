#include "shape.h"
#include <iostream>
#include <ctime>

using namespace std;

// ---------- Shape ---------- //

int Shape::getColor() const { return color; }
void Shape::setColor(const int color) { Shape::color = color; }

int Shape::getPosX() const { return posX; }
void Shape::setPosX(const int x) { posX = x; }

int Shape::getPosY() const { return posY; }
void Shape::setPosY(const int y) { posY = y; }

int Shape::getHeight() const { return height; }
void Shape::setHeight(const int height) { Shape::height = height; }

int Shape::getWidth() const { return width; }
void Shape::setWidth(const int width) { Shape::width = width; }

int Shape::getSpeedX() const { return speedX; }
void Shape::setSpeedX(const int speed) { speedX = speed; }

int Shape::getSpeedY() const { return speedY; }
void Shape::setSpeedY(const int speed) { speedY = speed; }

int Shape::setSpeed(const int speedX, const int speedY) {
    setSpeedX(speedX); setSpeedY(speedY);
}

int Shape::directMove(int y1,int y2)
{
	if (width >= 0) {
		if (posX < 50 && speedX < 0) {//left
			speedX = -speedX; 
			cleardevice();
			return 1;
		}
		if (posX + width >= WSX-50 && speedX > 0) {//right
		    speedX = -speedX; 
		    cleardevice();
			return 2;
    	}	
	}

    if ((height < 0) && ((posY + height < 50 && speedY < 0) || (posY >= WSY-50 && speedY > 0))) {
        speedY = -speedY; 
    }
    if ((height >= 0) && ((posY  < 50 && speedY < 0) || (posY + height  >= WSY-50 && speedY > 0))) {
        speedY = -speedY; 
    }
    
    
    if(posY>y1 && posY<y1+180 && (posX>120 && posX<140)) {
    speedX = -speedX;
	}
	
	if(posY>y2 && posY<y2+180 && (posX>1750 && posX<1790)) {
    speedX = -speedX;
	}
    posX += speedX;
    posY += speedY;
    
}

Shape* Shape::makeShape(int s)
{
    switch(s) {
        case 0: return new Circle;
        case 1: return new Rect;
    }
}

// ---------- Rect ---------- //

void Rect::setCoords(const int x1, const int y1, const int x2, const int y2)
{
    setPosX(x1); setPosY(y1);
    setWidth(x2 - x1); setHeight(y2 - y1);
}

void Rect::draw(const int shapeColor)
{
    if (shapeColor != -1) setcolor(shapeColor);
    else setcolor(color);
    rectangle(posX, posY, posX + width, posY + height);
    for(int i=posX;i<posX+width;i++){
    	line(i,posY,i,posY + height);
    	//cout<<i<<" "<<posY<<" "<<i<<" "<<posY + height<<endl;
	}
	//cout<<endl;
    
    
}



// ---------- Circle ---------- //

void Circle::setCoords(const int x, const int y, const int radius)
{
    setPosX(x - radius); setPosY(y - radius);
    setWidth(radius * 2); setHeight(radius * 2);
}

void Circle::draw(const int shapeColor)
{
    if (shapeColor != -1) setcolor(shapeColor);
    else setcolor(15);
    circle(posX + width / 2, posY + height / 2, width / 2);
    for(int i=0;i<width/2;i++)
    {
    	circle(posX + width / 2, posY + height / 2, i);	
	}
}

void drawrows()
{
	setcolor(15);
	
	for (int i=0;i<50;i++){
		line(0,i,WSX,i);
	}	
	
	for (int i=0;i<50;i++){
		line(i,0,i,WSY);
	}

	
	for (int i=50;i>=0;i--){
		line(0,WSY-i,WSX,WSY-i);
	}
	
	
	for (int i=0;i<50;i++){
		line(WSX-i,0,WSX-i,WSY);
	}
	
	
	for (int i=0;i<25;i++){
		line(WSX/2-i,0,WSX/2-i,WSY);
	}
}

void drawrowsanimation()
{
	setcolor(15);
	
	settextstyle(3, 0, 4); 
	for (int i=0;i<50;i++){
		delay(1);
		line(0,i,WSX,i);
	}	
	
	for (int i=0;i<50;i++){
		delay(1);
		line(i,0,i,WSY);
	}

	
	for (int i=0;i<50;i++){
		delay(1);
		line(0,WSY-i,WSX,WSY-i);
	}
	
	
	for (int i=0;i<50;i++){
		delay(1);
		line(WSX-i,0,WSX-i,WSY);
	}
	
	
	for (int i=0;i<25;i++){
		delay(1);
		line(WSX/2-i,0,WSX/2-i,WSY);
	}
	cleardevice();
	drawrows();
	draw3(452,230);
	draw3(1357,230);
	outtextxy(372, 330, "W is for UP");
	outtextxy(1247, 330, "UP KEY is for UP");
	delay(1000);
	cleardevice();
	drawrows();
	draw2(452,230);
	draw2(1357,230);
	outtextxy(372, 330, "S is for DOWN");
	outtextxy(1247, 330, "DOWN KEY is for DOWN");
	delay(1000);
	cleardevice();
	drawrows();
	draw1(452,230);
	draw1(1357,230);
	outtextxy(367, 330, "GOOD LUCK");
	outtextxy(1257, 330, "GOOD LUCK");
	delay(1000);
	cleardevice();
	drawrows();
	draw0(452,230);
	draw0(1357,230);
	delay(1000);
	cleardevice();
}


void draw0(int x,int y)
{	
	setcolor(15);
	bar(x-50,y-50,x+50,y-25);
	bar(x-50,y-50,x-25,y+50);
	bar(x+50,y+50,x+25,y-50);
	bar(x+50,y+50,x-50,y+25);
	
}

void draw1(int x,int y)
{	
	setcolor(15);
	bar(x-12,y-50,x+12,y+50);
	bar(x-25,y+25,x+25,y+50);
	bar(x-25,y-25,x,y-50);
}

void draw2(int x,int y)
{	
	setcolor(15);
	bar(x-25,y-25,x,y-50);
	bar(x,y-50,x+25,y);
	bar(x-25,y-12,x,y+25);
	bar(x-25,y+12,x+25,y+25);
	
}

void draw3(int x,int y)
{	
	setcolor(15);
	bar(x-25,y-37,x+25,y-24);
	bar(x-25,y-6,x+25,y+6);
	bar(x-25,y+37,x+25,y+24);
	bar(x+12,y-24,x+25,y+24);
	
}

void rightwinner()
{	
	settextstyle(3, 0, 9); 
	outtextxy(150, 400, "RIGHT PERSON IS WINNER!!!");
	settextstyle(3, 0, 4); 
	outtextxy(WSX/2-210, WSY/2, "PRESS ANY KEY TO EXIT");
}

void leftwinner()
{	
	settextstyle(3, 0, 9); 
	outtextxy(150, 400, "LEFT PERSON IS WINNER!!!");
	settextstyle(3, 0, 4); 
	outtextxy(WSX/2-210, WSY/2, "PRESS ANY KEY TO EXIT");
}
