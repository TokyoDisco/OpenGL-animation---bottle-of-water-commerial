#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "glut.h"

int frame = 0;
int scene = 0;
int zoomVer = 1;
int y = 0; //Alarm Clock ver
int winWidth = 600;
int winHeight = 600;
int bottleBody1[4][2];
int bottleBody2[4][2];
int bottleLogo[4][2];
int bottleCap[4][2];
int morphObject1[4][2];
int morphObject2[4][2];
int morphObject3[4][2];
int morphObject4[4][2];
int bottleZ = 0.3;
int counter = 0;
float proportion = 0.0;


// Copied text printing code 
void renderSpacedBitmapString(float x, float y, void *font, char *string) {
	char *c;
	int x1 = x;
	for (c = string; *c != '\0'; c++) {
		glRasterPos2f(x1, y);
		glutBitmapCharacter(font, *c);
		x1 = x1 + glutBitmapWidth(font, *c);
	}
}

//Morph method

void morph(int object[4][2], int type, int morphObject[4][2], int propo)
{
	for (int z = 0; z < 150; z++)
	{
		double placeX;
		double placeY;
		double objectX = object[z][0];
		double objectY = object[z][1];
		if (type == 1) {
			placeX = object[z][0] - 250;
			placeY = object[z][1] - 200;
		}
		if (type == 2) {
			placeX = object[z][0] - 250;
			placeY = object[z][1] + 200;
		}
		if (type == 3) {
			placeX = object[z][0] + 250;
			placeY = object[z][1] + 200;
		}
		if (type == 4) {
			placeX = object[z][0] + 250;
			placeY = object[z][1] - 200;
		}




		double diffX = (placeX - objectX);
		double diffY = (placeY - objectY);

		double morphObjectX = objectX + (diffX*propo);
		double morphObjectY = objectY + (diffY*propo);

		morphObject[z][0] = int(morphObjectX);
		morphObject[z][1] = int(morphObjectY);
	}
}


//scene 0 drawings

// Main frame of Clock Alarm
void mainAlarmFrame()
{

	glColor3f(0.184, 0.310, 0.310);
	glBegin(GL_POLYGON);
	glVertex3f(290.0f, 550.0f, 0.0f);
	glVertex3f(320.0f, 550.0f, 0.0f);
	glVertex3f(320.0f, 570.0f, 0.0f);
	glVertex3f(290.0f, 570.0f, 0.0f);
	glEnd();



	if (frame > 225 && frame <281)
	{
		glPushMatrix();
		glTranslatef(0, -y, 0);
		glBegin(GL_POLYGON);
		glVertex3f(330.0f, 550.0f, 0.0f);
		glVertex3f(360.0f, 550.0f, 0.0f);
		glVertex3f(360.0f, 570.0f, 0.0f);
		glVertex3f(330.0f, 570.0f, 0.0f);
		glEnd();

		glPopMatrix();
		y = y + 1;
	}
	else
	{
		if (frame < 225)
		{
			glBegin(GL_POLYGON);
			glVertex3f(330.0f, 550.0f, 0.0f);
			glVertex3f(360.0f, 550.0f, 0.0f);
			glVertex3f(360.0f, 570.0f, 0.0f);
			glVertex3f(330.0f, 570.0f, 0.0f);
			glEnd();
		}
		else
		{
			glBegin(GL_POLYGON);
			glVertex3f(330.0f, 525.0f, -0.1f);
			glVertex3f(360.0f, 525.0f, -0.1f);
			glVertex3f(360.0f, 560.0f, -0.1f);
			glVertex3f(330.0f, 560.0f, -0.1f);
			glEnd();
		}
	}
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0, 0);
	glVertex3f(10.0f, 50.0f, 0.3f);
	glVertex3f(590.0f, 50.0f, 0.3f);
	glVertex3f(590.0f, 550.0f, 0.3f);
	glVertex3f(10.0f, 550.0f, 0.3f);
	
	
	glEnd();
	
	

}
// Inner Clock Alarm Frame
void innerAlarmFrame()
{
	glColor3f(0.106, 0.141, 0.129);
	
	glBegin(GL_POLYGON);
	
	glVertex3f(100.0f, 150.0f, 0.12f); //x1y1
	glVertex3f(500.0f, 150.0f, 0.12f); //x2y1
	glVertex3f(500.0f, 450.0f, 0.12f); //x2y2
	glVertex3f(100.0f, 450.0f, 0.12f); //x1y2
	glEnd();
}

//Alarm Clock time
void AlarmTime1()
{
	glBegin(GL_LINES);
	if (frame % 10 == 0)
	{
		glColor3f(0.255, 0.412, 0.882);
	}
	else
	{
		glColor3f(0, 0, 1);
	}
	if (frame > 175)
	{
		glColor3f(0.502, 0.502, 0.000);
		if (frame % 5 == 0)
		{
			glColor3f(0, 1, 0);
		}
	}
	//6
	glVertex3f(160.0f, 250.0f, 0.5f);
	glVertex3f(210.0f, 250.0f, 0.5f);
	
	glVertex3f(160.0f, 250.0f, 0.5f);
	glVertex3f(160.0f, 350.0f, 0.5f);
	
	glVertex3f(160.0f, 300.0f, 0.5f);
	glVertex3f(210.0f, 300.0f, 0.5f);

	glVertex3f(210.0f, 300.0f, 0.5f);
	glVertex3f(210.0f, 250.0f, 0.5f);
	
	glVertex3f(160.0f, 350.0f, 0.5f);
	glVertex3f(210.0f, 350.0f, 0.5f);

	
	if (frame < 175) {
	//2
		glVertex3f(300.0f, 350.0f, 0.5f);
		glVertex3f(350.0f, 350.0f, 0.5f);

		glVertex3f(350.0f, 350.0f, 0.5f);
		glVertex3f(350.0f, 300.0f, 0.5f);

		glVertex3f(300.0f, 300.0f, 0.5f);
		glVertex3f(350.0f, 300.0f, 0.5f);

		glVertex3f(300.0f, 300.0f, 0.5f);
		glVertex3f(300.0f, 250.0f, 0.5f);

		glVertex3f(300.0f, 250.0f, 0.5f);
		glVertex3f(350.0f, 250.0f, 0.5f);
	//9
	
		glVertex3f(360.0f, 350.0f, 0.5f);
		glVertex3f(410.0f, 350.0f, 0.5f);

		glVertex3f(410.0f, 350.0f, 0.5f);
		glVertex3f(410.0f, 300.0f, 0.5f);

		glVertex3f(360.0f, 300.0f, 0.5f);
		glVertex3f(410.0f, 300.0f, 0.5f);

		glVertex3f(360.0f, 350.0f, 0.5f);
		glVertex3f(360.0f, 300.0f, 0.5f);

		glVertex3f(410.0f, 300.0f, 0.5f);
		glVertex3f(410.0f, 250.0f, 0.5f);

		glVertex3f(410.0f, 250.0f, 0.5f);
		glVertex3f(360.0f, 250.0f, 0.5f);
	}

	else {
		
		//3
		glVertex3f(300.0f, 350.0f, 0.5f);
		glVertex3f(350.0f, 350.0f, 0.5f);

		glVertex3f(350.0f, 350.0f, 0.5f);
		glVertex3f(350.0f, 250.0f, 0.5f);

		glVertex3f(350.0f, 300.0f, 0.5f);
		glVertex3f(300.0f, 300.0f, 0.5f);

		glVertex3f(350.0f, 250.0f, 0.5f);
		glVertex3f(300.0f, 250.0f, 0.5f);

		
		//0

		glVertex3f(360.0f, 350.0f, 0.5f);
		glVertex3f(410.0f, 350.0f, 0.5f);

		glVertex3f(410.0f, 350.0f, 0.5f);
		glVertex3f(410.0f, 250.0f, 0.5f);

		glVertex3f(360.0f, 250.0f, 0.5f);
		glVertex3f(410.0f, 250.0f, 0.5f);

		glVertex3f(360.0f, 350.0f, 0.5f);
		glVertex3f(360.0f, 250.0f, 0.5f);

		
	}

	glEnd();
	//:
	glPointSize(10.0);
	glBegin(GL_POINTS);
	
		glVertex3f(260.0f, 325.0f, 0.5f);
		glVertex3f(260.0f, 275.0f, 0.5f);
	
	glEnd();
}

//scene 1 drawings

//Fridge door 
void fridgeDoor()
{
	if (frame > 100  )
	{
		glPushMatrix;
		glRotatef(frame - 200, 0.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		glColor3f(0.184, 0.310, 0.310);
		glVertex3f(0, 0, 0);
		glVertex3f(600, 0, 0);
		glColor3f(0.000, 0.000, 0.000);
		glVertex3f(600, 600, 0);
		glVertex3f(0, 600, 0);
		glEnd();
		glColor3f(0, 1, 0);
		renderSpacedBitmapString(270, 550, GLUT_BITMAP_HELVETICA_18, "Russell Joobss The Fridge 2000");
		glPopMatrix;


	}
	else {
		glBegin(GL_POLYGON);
		glColor3f(0.184, 0.310, 0.310);
		glVertex3f(0, 0, 0);
		glVertex3f(600, 0, 0);
		glColor3f(0.000, 0.000, 0.000);
		glVertex3f(600, 600, 0);
		glVertex3f(0, 600, 0);
		glEnd();
		glColor3f(0, 1, 0);
		renderSpacedBitmapString(270, 550, GLUT_BITMAP_HELVETICA_18, "Russell Joobss The Fridge 2000");
	}
}

void fridgeShelves()
{
	glLineWidth(5.0);
	glColor3f(0.753, 0.753, 0.753);
	glBegin(GL_LINES);
	
	glVertex3f(20,100,0.1);
	glVertex3f(580, 100, 0.1);

	glVertex3f(20, 500, 0.1);
	glVertex3f(580, 500, 0.1);
	glEnd();
}

void fridgeBack1()
{
	if (frame < 50) {


		glColor3f(0.352, 0.352, 0.352);
	}
	else
	{
		glColor3f(0.898, 1, 0.8);
	}
	glBegin(GL_POLYGON);
	glVertex3f(20.0f, 20.0f, 0.12f); //x1y1
	glVertex3f(580.0f, 20.0f, 0.12f); //x2y1
	glVertex3f(580.0f, 580.0f, 0.12f); //x2y2
	glVertex3f(20.0f, 580.0f, 0.12f); //x1y2
	glEnd();
	
}
void fridgeFrame()
{
	glColor3f(0.184, 0.310, 0.310);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.05f); //x1y1
	glVertex3f(600.0f, 0.0f, 0.05f); //x2y1
	glVertex3f(600.0f, 600.0f, 0.05f); //x2y2
	glVertex3f(0.0f, 600.0f, 0.05f); //x1y2
	glEnd();
}

void bottle()
{
	glPushMatrix;

	glColor3f(0.968, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(bottleCap[0][0], bottleCap[0][1], bottleZ);
	glVertex3f(bottleCap[1][0], bottleCap[1][1], bottleZ);
	glVertex3f(bottleCap[2][0], bottleCap[2][1], bottleZ);
	glVertex3f(bottleCap[3][0], bottleCap[3][1], bottleZ);
	glEnd();



	
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(bottleBody2[0][0], bottleBody2[0][1], bottleZ);
	glVertex3f(bottleBody2[1][0], bottleBody2[1][1], bottleZ);
	glColor3f(0.268, 0.835, 1);
	glVertex3f(bottleBody2[2][0], bottleBody2[2][1], bottleZ);
	glVertex3f(bottleBody2[3][0], bottleBody2[3][1], bottleZ);
	glEnd();




	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(bottleBody1[0][0], bottleBody1[0][1], bottleZ);
	glVertex3f(bottleBody1[1][0], bottleBody1[1][1], bottleZ);
	glColor3f(0.268, 0.835, 1);
	glVertex3f(bottleBody1[2][0], bottleBody1[2][1], bottleZ);
	glVertex3f(bottleBody1[3][0], bottleBody1[3][1], bottleZ);
	glEnd();


	glColor3f(0.937, 0.505, 0.807);
	glBegin(GL_POLYGON);
	glVertex3f(bottleLogo[0][0], bottleLogo[0][1], bottleZ);
	glVertex3f(bottleLogo[1][0], bottleLogo[1][1], bottleZ);
	glColor3f(0.268, 0.835, 1);
	glVertex3f(bottleLogo[2][0], bottleLogo[2][1], bottleZ);
	glVertex3f(bottleLogo[3][0], bottleLogo[3][1], bottleZ);
	glEnd();

	glPopMatrix();

}
//scene2 drawings
void waterDrops(int xpos, int ypos)
{
	glColor3f(0, 0, 1);
	
	glBegin(GL_POINTS);
	glVertex3f(xpos, ypos, 0.7f);
	glEnd();


}

//scene3 drawings
void textbook1()
{
	glColor3f(0.255, 0.412, 0.882);
	glBegin(GL_POLYGON);

	glVertex3f(150.0f, 100.0f, 0.12f); //x1y1
	glVertex3f(450.0f, 100.0f, 0.12f); //x2y1
	glVertex3f(450.0f, 300.0f, 0.12f); //x2y2
	glVertex3f(150.0f, 300.0f, 0.12f); //x1y2
	glEnd();

	glColor3f(255, 255, 255);
	glBegin(GL_POLYGON);

	glVertex3f(200.0f, 220.0f, 0.12f); //x1y1
	glVertex3f(400.0f, 220.0f, 0.12f); //x2y1
	glVertex3f(400.0f, 280.0f, 0.12f); //x2y2
	glVertex3f(200.0f, 280.0f, 0.12f); //x1y2
	glEnd();

	glColor3f(0, 0, 0);
	renderSpacedBitmapString(210, 250, GLUT_BITMAP_HELVETICA_10, "Mathemathica Rules!");
	renderSpacedBitmapString(220, 235, GLUT_BITMAP_HELVETICA_10, "Middle School Textbook");


}
void backgroundScene3()
{
	
	glColor3f(1.000, 0.973, 0.863);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.05f); //x1y1
	glVertex3f(600.0f, 0.0f, 0.05f); //x2y1
	glVertex3f(600.0f, 600.0f, 0.05f); //x2y2
	glVertex3f(0.0f, 600.0f, 0.05f); //x1y2
	glEnd();

	glColor3f(0.647, 0.165, 0.165);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.05f); //x1y1
	glVertex3f(600.0f, 0.0f, 0.05f); //x2y1
	glVertex3f(600.0f, 110.0f, 0.05f); //x2y2
	glVertex3f(0.0f, 110.0f, 0.05f); //x1y2
	glEnd();


}


//scene4 drawings
void schoolClock()
{



	glColor3f(0.961, 1.000, 0.980);
	glBegin(GL_POLYGON);
	
	glVertex3f(10.0f, 50.0f, 0.3f);
	glVertex3f(590.0f, 50.0f, 0.3f);
	glVertex3f(590.0f, 550.0f, 0.3f);
	glVertex3f(10.0f, 550.0f, 0.3f);
	glEnd();

	glColor3f(0.941, 1.000, 0.941);
	glBegin(GL_POLYGON);

	glVertex3f(100.0f, 150.0f, 0.12f); //x1y1
	glVertex3f(500.0f, 150.0f, 0.12f); //x2y1
	glVertex3f(500.0f, 450.0f, 0.12f); //x2y2
	glVertex3f(100.0f, 450.0f, 0.12f); //x1y2
	glEnd();

	glLineWidth(10.0f);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(300.0f, 300.0f, 0.13f);
	glVertex3f(300.0f, 440.0f, 0.13f);
	if (frame < 60)
	{
		glVertex3f(300.0f, 300.0f, 0.13f);
		glVertex3f(490.0f, 300.0f, 0.13f);
	}
	if (frame > 60 && frame < 120)
	{
		glVertex3f(300.0f, 300.0f, 0.13f);
		glVertex3f(440.0f, 270.0f, 0.13f);
	}
	if (frame > 120 && frame < 180)
	{
		glVertex3f(300.0f, 300.0f, 0.13f);
		glVertex3f(400.0f, 240.0f, 0.13f);
	}

	if (frame > 180 && frame < 240)
	{
		glVertex3f(300.0f, 300.0f, 0.13f);
		glVertex3f(360.0f, 180.0f, 0.13f);
	}
	if (frame > 240 )
	{
		glVertex3f(300.0f, 300.0f, 0.13f);
		glVertex3f(300.0f, 150.0f, 0.13f);
	}
	glEnd();

	

}

void textbook2()
{
	glColor3f(1, 0.412, 0.882);
	glBegin(GL_POLYGON);

	glVertex3f(0.0f, 0.0f, 0.12f); //x1y1
	glVertex3f(600.0f, 0.0f, 0.12f); //x2y1
	glVertex3f(600.0f, 600.0f, 0.12f); //x2y2
	glVertex3f(0.0f, 600.0f, 0.12f); //x1y2
	glEnd();

	glColor3f(255, 255, 255);
	glBegin(GL_POLYGON);

	glVertex3f(200.0f, 220.0f, 0.12f); //x1y1
	glVertex3f(400.0f, 220.0f, 0.12f); //x2y1
	glVertex3f(400.0f, 280.0f, 0.12f); //x2y2
	glVertex3f(200.0f, 280.0f, 0.12f); //x1y2
	glEnd();

	glColor3f(0, 0, 0);
	renderSpacedBitmapString(210, 250, GLUT_BITMAP_HELVETICA_18, "E   n   g   l   i   s   h   ");
//	renderSpacedBitmapString(220, 235, GLUT_BITMAP_HELVETICA_10, "Story of sad programmers");
}

void exam()
{
	glColor3f(255, 255, 255);
	glBegin(GL_POLYGON);

	glVertex3f(0.0f, 0.0f, 0.12f); //x1y1
	glVertex3f(600.0f, 0.0f, 0.12f); //x2y1
	glVertex3f(600.0f, 600.0f, 0.12f); //x2y2
	glVertex3f(0.0f, 600.0f, 0.12f); //x1y2
	glEnd();

	

	glColor3f(1, 0, 0);
	renderSpacedBitmapString(10, 500, GLUT_BITMAP_HELVETICA_10, "E   X   A   M ");
	renderSpacedBitmapString(10, 300, GLUT_BITMAP_HELVETICA_10, "G   R   A   D   E");
	renderSpacedBitmapString(10, 100, GLUT_BITMAP_HELVETICA_18, "A   +");
	
}

void footballField()
{
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);

	glVertex3f(0.0f, 0.0f, 0.12f); //x1y1
	glVertex3f(600.0f, 0.0f, 0.12f); //x2y1
	glVertex3f(600.0f, 600.0f, 0.12f); //x2y2
	glVertex3f(0.0f, 600.0f, 0.12f); //x1y2
	glEnd();

	glColor3f(255, 255, 255);
	glBegin(GL_POLYGON);

	glVertex3f(0.0f, 200.0f, 0.12f); //x1y1
	glVertex3f(100.0f, 200.0f, 0.12f); //x2y1
	glVertex3f(100.0f, 400.0f, 0.12f); //x2y2
	glVertex3f(0.0f, 400.0f, 0.12f); //x1y2
	glEnd();

	glColor3f(255, 255, 255);
	glBegin(GL_POLYGON);

	glVertex3f(500.0f, 200.0f, 0.12f); //x1y1
	glVertex3f(600.0f, 200.0f, 0.12f); //x2y1
	glVertex3f(600.0f, 400.0f, 0.12f); //x2y2
	glVertex3f(500.0f, 400.0f, 0.12f); //x1y2
	glEnd();

	glColor3f(255, 255, 255);
	glBegin(GL_LINES);
	glVertex3f(300.0f,0.0f, 0.12f);
	glVertex3f(300.0f, 600.0f, 0.12f);
	glEnd();
}


//scene5 drawings
void backgroundScene5()
{
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.05f); //x1y1
	glVertex3f(600.0f, 0.0f, 0.05f); //x2y1
	glVertex3f(600.0f, 600.0f, 0.05f); //x2y2
	glVertex3f(0.0f, 600.0f, 0.05f); //x1y2
	glEnd();


	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 320.0f, 0.06f);
	glVertex3f(600.0f, 320.0f, 0.06f);
	glVertex3f(600.0f, 600.0f, 0.06f);
	glVertex3f(0.0f, 600.0f, 0.06f);
	glEnd();

}


//scene6 drawings
void lastText()
{
	glColor3f(1, 1, 0);
	renderSpacedBitmapString(100, 400, GLUT_BITMAP_HELVETICA_18, "Open your day with ");
	glColor3f(1, 0, 1);
	renderSpacedBitmapString(100, 350, GLUT_BITMAP_HELVETICA_18, "GL Water");
	glColor3f(0, 1, 0);
	renderSpacedBitmapString(100, 200, GLUT_BITMAP_HELVETICA_18, "Jakub Zarebski M00507447");
}

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	frame++;
	int i;
	
	
	//glLineWidth(10.0);

	if (scene == 0)
	{
		glPushMatrix;

		mainAlarmFrame();
		innerAlarmFrame();
		AlarmTime1();

		glPopMatrix;
	}
	
	if (scene == 1)
	{
		
		glPushMatrix;
		fridgeFrame();
		fridgeBack1();
		fridgeShelves();
		if (frame > 50)
		{
			
			glPushMatrix();
			glTranslatef(frame / 2, 0.0, 0.0);
			glScaled(1.0 + (frame / 1000), 1.0 + (frame / 1000), 1.0);
			bottle();
			glPopMatrix();

		}
		if (frame < 100)
		{
			fridgeDoor();
		}
		glPopMatrix();
	}

	if (scene == 2)
	{
		
		glPushMatrix();
		
		glTranslatef(150.0f, 150.0f, 0);
		//	glScalef(1.1f, 1.1f, 1.0f);
		
		glTranslatef(0, 0, 0);
		glTranslatef(135.0f, 150.0f, 0);
		if (frame < 100) {
			
			glRotatef(-frame, 0.0, 0.0, 1.0);
			bottle();
		}
		if (frame >= 100) 
		{
			glRotatef(-100, 0.0, 0.0, 1.0);
		//	waterDrops(100, 100);
			
			bottle();
			for (int a = 0; a < 80; a++) {
				waterDrops(rand() % 30 + 550, rand() % 190);
			}
		}
		
		
		
		glPopMatrix();

		

	}

	if (scene == 3)
	{
		glPushMatrix();
		backgroundScene3();
		glPopMatrix();
		
		glPushMatrix();
		glScalef(1.4f, 1.4f, 1.4f);
		bottle();
		glPopMatrix();
		glPushMatrix();
		glScalef(1.3f, 1.3f, 1.0f);
		textbook1();
		glPopMatrix();
	
	
	}

	if (scene == 4)
	{
		if (frame < 60 || frame >240) {
			glViewport(0, 0, 600, 600);
			glPushMatrix();
			glScalef(0.9f, 0.9f, 1.0f);
			schoolClock();
			glPopMatrix();
		}

		if (frame > 60 && frame < 120)
		{
			glViewport(0, 0, 300, 600);
			glPushMatrix();
			glScalef(0.9f, 0.9f, 1.0f);
			schoolClock();
			glPopMatrix();

			glViewport(300, 0, 300, 600);
			glPushMatrix();
			glScalef(0.9f, 0.9f, 1.0f);
			exam();
			glPopMatrix();
		}

		if (frame > 120 && frame < 180)
		{
			glViewport(0, 0, 300, 300);
			glPushMatrix();
			glScalef(0.9f, 0.9f, 1.0f);
			schoolClock();
			glPopMatrix();

			glViewport(300, 0, 300, 300);
			glPushMatrix();
			glScalef(0.9f, 0.9f, 1.0f);
			exam();
			glPopMatrix();

			glViewport(0, 300, 300, 300);
			glPushMatrix();
			glScalef(0.9f, 0.9f, 1.0f);
			textbook2();
			glPopMatrix();
		}

		if (frame > 180 && frame < 240)
		{
			glViewport(0, 0, 300, 300);
			glPushMatrix();
			glScalef(0.9f, 0.9f, 1.0f);
			schoolClock();
			glPopMatrix();

			glViewport(300, 0, 300, 300);
			glPushMatrix();
			glScalef(0.9f, 0.9f, 1.0f);
			exam();
			glPopMatrix();

			glViewport(0, 300, 300, 300);
			glPushMatrix();
			glScalef(0.9f, 0.9f, 1.0f);
			textbook2();
			glPopMatrix();

			glViewport(300, 300, 300, 300);
			glPushMatrix();
			glScalef(0.9f, 0.9f, 1.0f);
			footballField();
			
			glPopMatrix();
		}
		

	}

	if (scene == 6)
	{
		
		
		
		if (frame > 100 && frame < 250) {
			
				morph(bottleBody1, 1, morphObject1, proportion);

				glBegin(GL_LINE_LOOP);

				for (int i = 0; i < 4; i++)
				{
					glVertex2i(morphObject1[i][0], morphObject1[i][1]);

				}
				glEnd();

				morph(bottleBody2, 2, morphObject2, proportion);
				glBegin(GL_LINE_LOOP);

				for (int y = 0; y < 4; y++)
				{
					glVertex2i(morphObject2[y][0], morphObject2[y][1]);

				}
				glEnd();
				morph(bottleCap, 3, morphObject3, proportion);
				glBegin(GL_LINE_LOOP);

				for (int x = 0; x < 4; x++)
				{
					glVertex2i(morphObject3[x][0], morphObject3[x][1]);

				}
				glEnd();
				morph(bottleLogo, 4, morphObject4, proportion);
				glBegin(GL_LINE_LOOP);

				for (int a = 0; a < 4;a++)
				{
					glVertex2i(morphObject4[a][0], morphObject4[a][1]);

				}
				glEnd();
			
			}
		backgroundScene5();
		glPushMatrix();
		glTranslatef(150, 150, 0);
		bottle();
		glPopMatrix();
		
		
	}

	if (scene == 5)
	{
		glPushMatrix();
		
		glTranslatef(450.0f, 0.0f, 0.0f);
		glScalef(1.2f, 1.2f, 1.0f);
		bottle();
		glPopMatrix();
		lastText();
		
	}

	
	fprintf(stdout, "Frame number= %i\n", frame);
	fprintf(stdout, "Scene number= %i\n", scene);
	
	if (frame < 151)
	{
		
		if (scene == 0)
		{
			glLoadIdentity();
			gluOrtho2D(-150 + frame, winWidth + 150 - frame, -150 + frame, winHeight + 150 - frame);
		}
	}

	if (frame > 300)
	{
		frame = 0;
		
		glScalef(1.0f, 1.0f, 1.0f);
		
			scene = scene + 1;
		
	}
	glFlush();
	glutSwapBuffers();
}
void Timer(int value)
{
	if (value) glutPostRedisplay();

	glutTimerFunc(40, Timer, value);
}

void visibility(int state)
{
	switch (state)
	{
	case GLUT_VISIBLE:
		Timer(1);
		break;
	case GLUT_NOT_VISIBLE:
		Timer(0);
		break;
	default:
		break;
	}
}

void init(void)
{
	/* select clearing color */
	//glClearColor(255.0, 100.0, 100.0, 0.0);

	/* initialize viewing values  */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (scene == 0) 
	{
		gluOrtho2D(-300, winWidth + 300, -300, winHeight + 300);
	}
	else
	{
		gluOrtho2D(0, winWidth , 0, winHeight);
	}

	bottleBody1[0][0] = 20;
	bottleBody1[0][1] = 100;
	bottleBody1[1][0] = 100;
	bottleBody1[1][1] = 100;
	bottleBody1[2][0] = 100;
	bottleBody1[2][1] = 200;
	bottleBody1[3][0] = 20;
	bottleBody1[3][1] = 200;

	bottleBody2[0][0] = 20;
	bottleBody2[0][1] = 200;
	bottleBody2[1][0] = 100;
	bottleBody2[1][1] = 200;
	bottleBody2[2][0] = 80;
	bottleBody2[2][1] = 250;
	bottleBody2[3][0] = 40;
	bottleBody2[3][1] = 250;

	bottleCap[0][0] = 40;
	bottleCap[0][1] = 250;
	bottleCap[1][0] = 80;
	bottleCap[1][1] = 250;
	bottleCap[2][0] = 80;
	bottleCap[2][1] = 280;
	bottleCap[3][0] = 40;
	bottleCap[3][1] = 280;

	bottleLogo[0][0] = 20;
	bottleLogo[0][1] = 150;
	bottleLogo[1][0] = 100;
	bottleLogo[1][1] = 150;
	bottleLogo[2][0] = 100;
	bottleLogo[2][1] = 175;
	bottleLogo[3][0] = 20;
	bottleLogo[3][1] = 175;
	



}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(winWidth, winHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("CourseWork2");

	init();
	glutDisplayFunc(display);
	glutVisibilityFunc(visibility);

	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}