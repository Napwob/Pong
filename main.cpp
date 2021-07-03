#include <graphics.h>
#include <ctime>
#include "const.h"
#include "shape.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    srand(time(NULL));
    initwindow(WSX, WSY);
    setbkcolor(BGCOLOR);
    cleardevice();
    
    Rect rect1;
    Rect rect2;
    Circle circle;
    int i1=rect1.getPosY();
    
    rect2.setCoords(1790,70,1840,250);
    int i2=rect2.getPosY();
	
	int w=0,wl=0,wr=0;

	drawrowsanimation();
	
    while(true) {
    	drawrows();
        int keypressed = 0;
        if (kbhit()) keypressed = getch();
       	if (keypressed == VK_ESCAPE) break;
		if (keypressed == 119) //w//72-up
		{
			if(i1>=70)i1+=-20;
				rect1.draw(BGCOLOR);
				rect1.setPosY(i1); 
		}
        if (keypressed == 115)//s//80-down
		{
			if(i1<WSY-240)i1+=20;
			 	rect1.draw(BGCOLOR);
				rect1.setPosY(i1); 
		}
		
		if (keypressed == 72) //w//72-up
		{
			if(i2>=70)i2+=-20;
				rect2.draw(BGCOLOR);
				rect2.setPosY(i2); 
		}
        if (keypressed == 80)//s//80-down
		{
			if(i2<WSY-240)i2+=20;
			 	rect2.draw(BGCOLOR);
				rect2.setPosY(i2); 
		}
		
	/*	if(w==1) //wl++; 
		cout<<1;
		if(w==2) //wr++;
		cout<<2;*/
			switch(wr)
			{
				case 0: {
					draw0(452,230);
					break;
				}
				case 1: {
					draw1(452,230);
					break;
				}
				case 2: {
					draw2(452,230);
					break;
				}
				case 3: {
					draw3(452,230);
					break;
				}
				case 4: {
					w=3;
					break;
				}	
			}
			
			switch(wl)
			{
				case 0: {
					draw0(1357,230);
					break;
				}
				case 1: {
					draw1(1357,230);
					break;
				}
				case 2: {
					draw2(1357,230);
					break;
				}
				case 3: {
					draw3(1357,230);
					break;
				}
				case 4: {
					w=3;
					break;
				} 	
			}
		if(w==3) break;
		w=0;
		rect1.draw();
		rect2.draw();
       	circle.draw(BGCOLOR);
        w=circle.directMove(rect1.getPosY(),rect2.getPosY());
        if(w==1) 
		{
			wl++;
			circle.setCoords(WSX/2, WSY/2, 25);
		}
		if(w==2) 
		{
			wr++;
			circle.setCoords(WSX/2, WSY/2, 25);
		}
        circle.draw();
        delay(1);
    }
    cleardevice();
    if(wr>wl) rightwinner(); else leftwinner();
    getch();
    closegraph();
	return 0;
}



