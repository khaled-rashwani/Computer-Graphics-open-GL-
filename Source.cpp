/*
 *		This Code Was Created By Jeff Molofee 2000
 *		A HUGE Thanks To Fredric Echols For Cleaning Up
 *		And Optimizing This Code, Making It More Flexible!
 *		If You've Found This Code Useful, Please Let Me Know.
 *		Visit My Site At nehe.gamedev.net
 */

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
//#include <gl\glaux.h>		// Header File For The Glaux Library
#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <texture.h>

HDC			hDC=NULL;		// Private GDI Device Context
HGLRC		hRC=NULL;		// Permanent Rendering Context
HWND		hWnd=NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active=TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen=TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default

/*
GLfloat LightAmbient []={0.5f,0.5f,0.5f,1.0f};
GLfloat LightDiffuse []={1.0f,1.0f,1.0f,1.0f};
GLfloat LightPosition []={0.0f,1.0f,5.0f,1.0f}; //light

*/



LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc


GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,210.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}
int wall2;
int wall1;
int roof;
int door1;
int door2;
int redcarpet;
int back;
int left;
int top;
int front;
int right;
int ground;
int wall3;
int painting;
int brick;
int baby;
int baby1;
int cat;
int bear;
int owl;
int girrafe;
int cat2;
int sekkah;
int iron;
int wood;
int st;
int blue;
int block;
int block2;
int secondtop;
int secondleft;
int secondright;
int secondground;
int stop;
GLfloat LightPos[] = {0.0f,5.0f,4.0f,1.0f};
GLfloat LightAmb[] = {1.0f,1.0f,1.0f,1.0f};
GLfloat LightDiff[] = {0.6f,0.6f,0.6f,1.0f};
GLfloat LightSpec[] = {-0.2f,-0.2f,-0.2f,1.0f};
GLfloat MatAmb[] = {1.0f,0.0f,0.0f,1.0f};
GLfloat MatDif[] = {0.2f,0.6f,0.9f,1.0f};
GLfloat MatSpec[] = {0.0f,0.0f,0.0f,1.0f};
GLfloat MatShn[] = {128.0f};
int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	glEnable(GL_TEXTURE_2D);
	wall1 = LoadTexture("wall1.bmp", 255);

	glEnable(GL_TEXTURE_2D);
	wall2 = LoadTexture("wall2.bmp", 255);

	glEnable(GL_TEXTURE_2D);
	wall3 = LoadTexture("wall3.bmp", 255);

	glEnable(GL_TEXTURE_2D);
	roof = LoadTexture("roof.bmp", 255);

	glEnable(GL_TEXTURE_2D);
	door1 = LoadTexture("door1.bmp", 255);

	glEnable(GL_TEXTURE_2D);
	door2 = LoadTexture("door2.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	secondtop = LoadTexture("secondtop.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	secondright = LoadTexture("secondright.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	secondleft = LoadTexture("secondleft.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	secondground = LoadTexture("secondground.bmp", 255);
	
	glEnable(GL_TEXTURE_2D);
	stop = LoadTexture("stop.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	redcarpet = LoadTexture("redcarpet.bmp", 255);

	glEnable(GL_TEXTURE_2D);
	back = LoadTexture("back.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	blue= LoadTexture("blue.bmp", 255);

	glEnable(GL_TEXTURE_2D);
	left = LoadTexture("left2.bmp", 255);

	glEnable(GL_TEXTURE_2D);
	top = LoadTexture("top.bmp", 255);

	glEnable(GL_TEXTURE_2D);
	right = LoadTexture("right2.bmp", 255);

	glEnable(GL_TEXTURE_2D);
	front = LoadTexture("front.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	baby1 = LoadTexture("baby1.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	ground = LoadTexture("ground.bmp", 255);

	glEnable(GL_TEXTURE_2D);
	painting = LoadTexture("painting.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	brick = LoadTexture("brick.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	baby = LoadTexture("baby.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	owl = LoadTexture("owl.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	bear = LoadTexture("bear.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	girrafe = LoadTexture("girrafe.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	cat2 = LoadTexture("i.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	wood = LoadTexture("wood.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	block = LoadTexture("block.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	block2 = LoadTexture("block2.bmp", 255);
	cat = LoadTexture("cat.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	sekkah = LoadTexture("sekkah.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	iron = LoadTexture("iron.bmp", 255);
	glEnable(GL_TEXTURE_2D);
	st = LoadTexture("steinsgate.bmp", 255);


	 glLightfv(GL_LIGHT1,GL_POSITION,LightPos);
    glLightfv(GL_LIGHT1,GL_AMBIENT,LightAmb);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,LightDiff);
    glLightfv(GL_LIGHT1,GL_SPECULAR,LightSpec);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHTING);
    glMaterialfv(GL_FRONT,GL_AMBIENT,MatAmb);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,MatDif);
    glMaterialfv(GL_FRONT,GL_SPECULAR,MatSpec);
    glMaterialfv(GL_FRONT,GL_SHININESS,MatShn);
    glEnable(GL_COLOR_MATERIAL);
	

	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return TRUE;
	// Initialization Went OK
}

double i=0;
double j=0;
double k=0;
double y=0;
double w=-200;
double angle =0;
bool open = false;
bool first = false;
bool lp = false ;

void key(bool * keys){
	double i1=i;
	double j1=j;
	angle +=0.004;
	if(keys['W']){
		i-=0.1;
		if(  (i  < -200) || (i  >  0 )  ){
			i=i1;
		}
		if(  ((j  > -1) && (j  <  -2 ))  || ((j  <  -2 )  &&  (j  <  1 ))  ){
			
			if((i<-10) && (i>-10.1)){
				i=i1;
			}
		}
		if(!open){
			if(   (i<-10) && (i>-10.1) && (j>-2)  && (j<2)  ){
				i=i1;
			}
		}
		else if (open){
			if(   (i<-10) && (i>-10.1) && (j>-2)  && (j<-1)  ){
				i=i1;
			}
			if(   (i<-10) && (i>-10.1) && (j>1)  && (j<2)  ){
				i=i1;
			}
		}
		y=0.3*fabs(cos(angle));


	}

	if(keys['S'])
	{
		i+=0.1;
		if(  (i  < -200) || (i  >  0 )  ){
			i=i1;
		}
		if(  ((j  > -1) && (j  <  -2 ))  || ((j  >  2 )  &&  (j  <  1 ))  ){
			
			if((i<-10) && (i>-10.1)){
				i=i1;
			}
		}
		if(!open){
			if(   (i<-10) && (i>-10.1) && (j>-2)  && (j<2)  ){
				i=i1;
			}
		}
		else if (open){
			if(   (i<-10) && (i>-10.1) && (j>-2)  && (j<-1)  ){
				i=i1;
			}
			if(   (i<-10) && (i>-10.1) && (j>1)  && (j<2)  ){
				i=i1;
			}
		}
		y=0.3*fabs(cos(angle));


	}//S

	if(keys['D']){
		j+=0.1;
		if(j>10){
			j=j1;
		}
		if(  (j>1) && (j<1.1)  && (i<-10) && (i>-200)   ){
			j=j1;
		}
		if(  (j<-1) && (j>-1.1)  && (i<-10) && (i>-200)   ){
			j=j1;
		}
		y=0.3*fabs(cos(angle));
	
	
	}//D


	if(keys['A']){
		j-=0.1;
		if(j<-10){
			j=j1;
		}
		if(  (j>1) && (j<1.1)  && (i<-10) && (i>-200)   ){
			j=j1;
		}
		if(  (j<-1) && (j>-1.1)  && (i<-10) && (i>-200)   ){
			j=j1;
		}
		y=0.3*fabs(cos(angle));
	
	}//A

	if(keys[VK_RIGHT]){
		k+=0.5*cos(0.01);
		w+=0.5*sin(0.01);

	}//right
	
	if(keys[VK_LEFT]){
		k-=0.5*cos(0.01);
		w-=0.5*sin(0.01);

	}//left


	/*if(keys[VK_UP]){
		//y+=0.5*cos(0.01);
		//w+=0.5*sin(0.01);
		y+=0.1;

	}//up*/

	if( (keys['O'])  &&  (!lp)  ){
		//PlaySound("C:\\Users\\pc\\Documents\\Visual Studio 2012\\Projects\\Project1\\Project1\\door-1-open.wav",NULL,SND_ASYNC);
		lp=true;
		open =!open;
	}

	if( (!(keys['O']))   ){
		lp=false;
	}
	;



}
void chair(){
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);//ÇáæÌå Çáíãíäí ááßÑÓí
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3d(1,0.5,-36);
	glTexCoord2d(1,0);
	glVertex3d(1,0.01,-36);
	glTexCoord2d(1,1);
	glVertex3d(1,0.01,-37);
	glTexCoord2d(0,1);
	glVertex3d(1,0.5,-37);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);//ÇáæÌå ÇáÎáÝí ááßÑÓí
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3d(1,0.01,-37);
	glTexCoord2d(1,0);
	glVertex3d(1,0.5,-37);
	glTexCoord2d(1,1);
	glVertex3d(0,0.5,-37);
	glTexCoord2d(0,1);
	glVertex3d(0,0.01,-37);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);//ÇáæÌå ÇáÇãÇãí ááßÑÓí
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3d(0,0.5,-36);
	glTexCoord2d(1,0);
	glVertex3d(0,0.01,-36);
	glTexCoord2d(1,1);
	glVertex3d(1,0.01,-36);
	glTexCoord2d(0,1);
	glVertex3d(1,0.5,-36);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,redcarpet);
	glBegin(GL_QUADS);//ÞÚÏÉ ÇáßÑÓí
	glColor3f(1,1,1);
	glVertex3d(0,0.5,-36);
	glTexCoord2d(0,0);
	glVertex3d(1,0.5,-36);
	glTexCoord2d(1,0);
	glVertex3d(1,0.5,-36);
	glTexCoord2d(1,1);
	glVertex3d(0,0.5,-36);
	glTexCoord2d(0,1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);//ÞÚÏÉ ÇáßÑÓí
	glColor3f(1, 1, 1);
	glVertex3d(0, 0.7, -36);
	glTexCoord2d(0, 0);
	glVertex3d(1, 0.7, -36);
	glTexCoord2d(1, 0);
	glVertex3d(1, 0.7, -37);
	glTexCoord2d(1, 1);
	glVertex3d(0, 0.7, -37);
	glTexCoord2d(0, 1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,redcarpet);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÍãÑ
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3d(0.99,0.5,-36);
	glTexCoord2d(1,0);
	glVertex3d(0.99,0.5,-37);
	glTexCoord2d(1,1);
	glVertex3d(0.99,1.8,-37);
	glTexCoord2d(0,1);
	glVertex3d(0.99,1.8,-36);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÍãÑ
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(0.8, 0.5, -36);
	glTexCoord2d(1, 0);
	glVertex3d(0.8, 0.5, -37);
	glTexCoord2d(1, 1);
	glVertex3d(0.8, 1.8, -37);
	glTexCoord2d(0, 1);
	glVertex3d(0.8, 1.8, -36);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÍãÑ
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(0.99, 1.8, -36);
	glTexCoord2d(1, 0);
	glVertex3d(0.99, 1.8, -37);
	glTexCoord2d(1, 1);
	glVertex3d(0.8, 1.8, -37);
	glTexCoord2d(0, 1);
	glVertex3d(0.8, 1.8, -36);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÍãÑ
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(0.99, 0, -37);
	glTexCoord2d(1, 0);
	glVertex3d(0.99, 1.8, -37);
	glTexCoord2d(1, 1);
	glVertex3d(0.8, 1.8, -37);
	glTexCoord2d(0, 1);
	glVertex3d(0.8, 0, -37);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÍãÑ
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(0.99, 0, -36);
	glTexCoord2d(1, 0);
	glVertex3d(0.99, 1.8, -36);
	glTexCoord2d(1, 1);
	glVertex3d(0.8, 1.8, -36);
	glTexCoord2d(0, 1);
	glVertex3d(0.8, 0, -36);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÍãÑ
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0.5, -37);
	glTexCoord2d(1, 0);
	glVertex3d(0, 0.7, -37);
	glTexCoord2d(1, 1);
	glVertex3d(0, 0.7, -36);
	glTexCoord2d(0, 1);
	glVertex3d(0, 0.5, -36);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÍãÑ
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(0.99, 0.7, -37);
	glTexCoord2d(1, 0);
	glVertex3d(0, 0.7, -37);
	glTexCoord2d(1, 1);
	glVertex3d(0, 0.5, -37);
	glTexCoord2d(0, 1);
	glVertex3d(0.99, 0.5, -37);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÍãÑ
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(0.99, 0.7, -36);
	glTexCoord2d(1, 0);
	glVertex3d(0, 0.7, -36);
	glTexCoord2d(1, 1);
	glVertex3d(0, 0.5, -36);
	glTexCoord2d(0, 1);
	glVertex3d(0.99, 0.5, -36);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3d(1,0.5,-36);
	glTexCoord2d(1,0);
	glVertex3d(1,0.5,-37);
	glTexCoord2d(1,1);
	glVertex3d(1,1.8,-37);
	glTexCoord2d(0,1);
	glVertex3d(1,1.8,-36);
	glEnd();
	glPopMatrix();




};

void chair1() {
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÇáæÌå Çáíãíäí áÑÌá ÇáßÑÓí
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(1, 0.5, -56);
	glTexCoord2d(1, 0);
	glVertex3d(1, 0.01, -56);
	glTexCoord2d(1, 1);
	glVertex3d(1, 0.01, -57);
	glTexCoord2d(0, 1);
	glVertex3d(1, 0.5, -57);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÇáæÌå ÇáÎáÝí áÑÌá ÇáßÑÓí
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(1, 0.01, -57);
	glTexCoord2d(1, 0);
	glVertex3d(1, 0.5, -57);
	glTexCoord2d(1, 1);
	glVertex3d(0, 0.5, -57);
	glTexCoord2d(0, 1);
	glVertex3d(0, 0.01, -57);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÇáæÌå ÇáÇãÇãí áÑÌá ÇáßÑÓí
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0.5, -56);
	glTexCoord2d(1, 0);
	glVertex3d(0, 0.01, -56);
	glTexCoord2d(1, 1);
	glVertex3d(1, 0.01, -56);
	glTexCoord2d(0, 1);
	glVertex3d(1, 0.5, -56);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);//ÞÚÏÉ ÇáßÑÓí áæä ÇÒÑÞ
	glColor3f(1, 1, 1);
	glVertex3d(0, 0.5, -56);
	glTexCoord2d(0, 0);
	glVertex3d(1, 0.5, -56);
	glTexCoord2d(1, 0);
	glVertex3d(1, 0.5, -57);
	glTexCoord2d(1, 1);
	glVertex3d(0, 0.5, -57);
	glTexCoord2d(0, 1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);//ÞÚÏÉ ÇáßÑÓí áæä ÇÒÑÞ
	glColor3f(1, 1, 1);
	glVertex3d(0, 0.7, -56);
	glTexCoord2d(0, 0);
	glVertex3d(1, 0.7, -56);
	glTexCoord2d(1, 0);
	glVertex3d(1, 0.7, -57);
	glTexCoord2d(1, 1);
	glVertex3d(0, 0.7, -57);
	glTexCoord2d(0, 1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÞÚÏÉ ÇáßÑÓí áæä ÇÒÑÞ
	glColor3f(1, 1, 1);
	glVertex3d(0, 0.7, -56);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0.7, -57);
	glTexCoord2d(1, 0);
	glVertex3d(0, 0.5, -57);
	glTexCoord2d(1, 1);
	glVertex3d(0, 0.5, -56);
	glTexCoord2d(0, 1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÞÚÏÉ ÇáßÑÓí áæä ÇÒÑÞ
	glColor3f(1, 1, 1);
	glVertex3d(1, 0.7, -56);
	glTexCoord2d(0, 0);
	glVertex3d(1, 0.7, -57);
	glTexCoord2d(1, 0);
	glVertex3d(1, 0.5, -57);
	glTexCoord2d(1, 1);
	glVertex3d(1, 0.5, -56);
	glTexCoord2d(0, 1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÞÚÏÉ ÇáßÑÓí áæä ÇÒÑÞ
	glColor3f(1, 1, 1);
	glVertex3d(0, 0.7, -57);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0.5, -57);
	glTexCoord2d(1, 0);
	glVertex3d(1, 0.5, -57);
	glTexCoord2d(1, 1);
	glVertex3d(1, 0.7, -57);
	glTexCoord2d(0, 1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÒÑÞ 
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0.5, -56.1);
	glTexCoord2d(1, 0);
	glVertex3d(1, 0.5, -56.1);
	glTexCoord2d(1, 1);
	glVertex3d(1, 1.8, -56.1);
	glTexCoord2d(0, 1);
	glVertex3d(0, 1.8, -56.1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÒÑÞ 
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0.5, -56.3);
	glTexCoord2d(1, 0);
	glVertex3d(1, 0.5, -56.3);
	glTexCoord2d(1, 1);
	glVertex3d(1, 1.8, -56.3);
	glTexCoord2d(0, 1);
	glVertex3d(0, 1.8, -56.3);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÒÑÞ 
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, -56.3);
	glTexCoord2d(1, 0);
	glVertex3d(0, 1.8, -56.3);
	glTexCoord2d(1, 1);
	glVertex3d(0, 1.8, -56);
	glTexCoord2d(0, 1);
	glVertex3d(0, 0, -56);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÒÑÞ 
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(1, 0, -56.3);
	glTexCoord2d(1, 0);
	glVertex3d(1, 1.8, -56.3);
	glTexCoord2d(1, 1);
	glVertex3d(1, 1.8, -56);
	glTexCoord2d(0, 1);
	glVertex3d(1, 0, -56);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÒÑÞ 
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(1, 0, -57);
	glTexCoord2d(1, 0);
	glVertex3d(1, 0.5, -57);
	glTexCoord2d(1, 1);
	glVertex3d(1, 0.5, -56);
	glTexCoord2d(0, 1);
	glVertex3d(1, 0, -56);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÒÑÞ 
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0, -57);
	glTexCoord2d(1, 0);
	glVertex3d(0, 0.5, -57);
	glTexCoord2d(1, 1);
	glVertex3d(0, 0.5, -56);
	glTexCoord2d(0, 1);
	glVertex3d(0, 0, -56);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ áæä ÇÒÑÞ 
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(0, 1.8, -56);
	glTexCoord2d(1, 0);
	glVertex3d(1, 1.8, -56);
	glTexCoord2d(1, 1);
	glVertex3d(1, 1.8, -56.3);
	glTexCoord2d(0, 1);
	glVertex3d(0, 1.8, -56.3);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÓäÇÏÉ ÇáÙåÑ
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3d(0, 0.5, -56);
	glTexCoord2d(1, 0);
	glVertex3d(1, 0.5, -56);
	glTexCoord2d(1, 1);
	glVertex3d(1, 1.8, -56);
	glTexCoord2d(0, 1);
	glVertex3d(0, 1.8, -56);
	glEnd();
	glPopMatrix();



};
void skybox(){
	/*
	glColor3f(1,1,1);//Back Sky Box
	glBindTexture(GL_TEXTURE_2D,back);
	glBegin(GL_QUADS);
	glColor3f(0, 0.3, 0);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-194.1);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-194.1);
	glTexCoord2d(1,1);
	glVertex3f(10,10,-194.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-194.1);
	glEnd();
	*/
	glColor3f(1,1,1);//left Sky Box
	glBindTexture(GL_TEXTURE_2D,left);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,10);
	glTexCoord2d(1,0);
	glVertex3f(-10,-1.5,-14.1);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-14.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,10);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-7,-1.5,-14);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-34.1);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-34.1);
	glTexCoord2d(0,1);
	glVertex3f(-7,10,-14);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-14);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-14);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-14);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-14);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-74);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-74);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-74);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-74);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 3
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-7,-1.5,-34);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-54.1);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-54.1);
	glTexCoord2d(0,1);
	glVertex3f(-7,10,-34);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-7,-1.5,-54);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-74.1);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-74.1);
	glTexCoord2d(0,1);
	glVertex3f(-7,10,-54);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,secondleft);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-74);
	glTexCoord2d(1,0);
	glVertex3f(-10,-1.5,-94.1);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-94.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-74);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-7,-1.5,-94);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-114.1);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-114.1);
	glTexCoord2d(0,1);
	glVertex3f(-7,10,-94);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-94);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-94);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-94);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-94);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-154);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-154);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-154);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-154);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-7,-1.5,-114);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-134.1);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-134.1);
	glTexCoord2d(0,1);
	glVertex3f(-7,10,-114);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-7,-1.5,-134);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-154.1);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-154.1);
	glTexCoord2d(0,1);
	glVertex3f(-7,10,-134);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,secondleft);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-154);
	glTexCoord2d(1,0);
	glVertex3f(-10,-1.5,-174.1);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-174.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-154);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-7,-1.5,-174);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-194.1);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-194.1);
	glTexCoord2d(0,1);
	glVertex3f(-7,10,-174);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-174);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-174);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-174);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-174);
	glEnd();
	
	glColor3f(1,1,1);//right Sky Box
	glBindTexture(GL_TEXTURE_2D,right);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,10);
	glTexCoord2d(0,0);
	glVertex3f(10,-1.5,-14.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-14.1);
	glTexCoord2d(1,1);
	glVertex3f(10,10,10);
	glEnd();
	
	glColor3f(1,1,1);//right Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(7,-1.5,-14);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-34.1);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-34.1);
	glTexCoord2d(1,1);
	glVertex3f(7,10,-14);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,1);
	glVertex3f(10,-1.5,-14);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-14);
	glTexCoord2d(1,0);
	glVertex3f(7,10,-14);
	glTexCoord2d(1,1);
	glVertex3f(10,10,-14);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,1);
	glVertex3f(11,-1.5,-73.8);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-73.8);
	glTexCoord2d(1,0);
	glVertex3f(7,10.1,-73.8);
	glTexCoord2d(1,1);
	glVertex3f(11,10.1,-73.8);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 3
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-54.1);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-34);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-34);
	glTexCoord2d(1,0);
	glVertex3f(7,10,-54.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-74.1);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-54);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-54);
	glTexCoord2d(1,0);
	glVertex3f(7,10,-74.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,secondright);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(10,-1.5,-94.1);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-74);
	glTexCoord2d(1,1);
	glVertex3f(10,10,-74);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-94.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-114.1);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-94);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-94);
	glTexCoord2d(1,0);
	glVertex3f(7,10,-114.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(10,-1.5,-94);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-94);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-94);
	glTexCoord2d(1,0);
	glVertex3f(10,10,-94);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(10,-1.5,-154);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-154);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-154);
	glTexCoord2d(1,0);
	glVertex3f(10,10,-154);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-134.1);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-114);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-114);
	glTexCoord2d(1,0);
	glVertex3f(7,10,-134.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-154.1);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-134);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-134);
	glTexCoord2d(1,0);
	glVertex3f(7,10,-154.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,secondright);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(10,-1.5,-174.1);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-154);
	glTexCoord2d(1,1);
	glVertex3f(10,10,-154);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-174.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-194.1);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-174);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-174);
	glTexCoord2d(1,0);
	glVertex3f(7,10,-194.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(10,-1.5,-174);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-174);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-174);
	glTexCoord2d(1,0);
	glVertex3f(10,10,-174);
	glEnd();


	glColor3f(1,1,1);//Top Sky Box
	glBindTexture(GL_TEXTURE_2D,top);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-14.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-14.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,10);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,10);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-34.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-34.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-14);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-14);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,9,-14);
	glTexCoord2d(0,0);
	glVertex3f(10,9,-14);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-14);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-14);
	glEnd();
	//glPopMatrix();
	glColor3f(1,1,1);//Top Sky Box 3
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-54.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-54.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-34);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-34);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-74.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-74.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-54);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-54);
	glEnd();/*
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,9,-74.1);
	glTexCoord2d(0,0);
	glVertex3f(10,9,-74.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-74.1);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-74.1);
	glEnd();*/
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,secondtop);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-94.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-94.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-74);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-74);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-114.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-114.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-94);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-94);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-134.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-134.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-114);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-114);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-154.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-154.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-134);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-134);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,secondtop);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-174.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-174.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-154);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-154);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-194.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-194.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-174);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-174);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D,ground);
	glBegin(GL_QUADS); //ground
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,10);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,10);
	glTexCoord2d(1,1);
	glVertex3f(10,-1.5,-14.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,-1.5,-14.1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS); //ground 2
	glColor3f(0,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-14);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-14);
	glTexCoord2d(1,1);
	glVertex3f(10,-1.5,-34.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,-1.5,-34.1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS); //ground 3
	glColor3f(0,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-34);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-34);
	glTexCoord2d(1,1);
	glVertex3f(10,-1.5,-54.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,-1.5,-54.1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS); //ground 4
	glColor3f(0,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-54);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-54);
	glTexCoord2d(1,1);
	glVertex3f(10,-1.5,-74.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,-1.5,-74.1);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,secondground);
	glBegin(GL_QUADS); //ground 4
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-74);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-74);
	glTexCoord2d(1,1);
	glVertex3f(10,-1.5,-94.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,-1.5,-94.1);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS); //ground 4
	glColor3f(0,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-94);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-94);
	glTexCoord2d(1,1);
	glVertex3f(10,-1.5,-154.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,-1.5,-154.1);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,secondground);
	glBegin(GL_QUADS); //ground 4
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-154);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-154);
	glTexCoord2d(1,1);
	glVertex3f(10,-1.5,-174.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,-1.5,-174.1);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah             taaaaaaaaaadiiiiiiiilllllllll
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.6,-190);
	glTexCoord2d(1,0);
	glVertex3f(-4,-1.6,-1);
	glTexCoord2d(1,1);
	glVertex3f(-2,-1.6,-1);
	glTexCoord2d(0,1);
	glVertex3f(-2,-1.6,-190);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from above
	glTexCoord2d(0,0);
	glVertex3f(-4,-1,-190);
	glTexCoord2d(1,0);
	glVertex3f(-4,-1,-1);
	glTexCoord2d(1,1);
	glVertex3f(-2,-1,-1);
	glTexCoord2d(0,1);
	glVertex3f(-2,-1,-190);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from side
	glTexCoord2d(0,0);
	glVertex3f(-4,-1,-190);
	glTexCoord2d(1,0);
	glVertex3f(-4,-1.9,-190);
	glTexCoord2d(1,1);
	glVertex3f(-4,-1.9,-1);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1,-1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from side
	glTexCoord2d(0,0);
	glVertex3f(-2,-1,-190);
	glTexCoord2d(1,0);
	glVertex3f(-2,-1.6,-190);
	glTexCoord2d(1,1);
	glVertex3f(-2,-1.6,-1);
	glTexCoord2d(0,1);
	glVertex3f(-2,-1,-1);
	glEnd();
	
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah
	glTexCoord2d(0,0);
	glVertex3f(2,-1.6,-190);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.6,-1);
	glTexCoord2d(1,1);
	glVertex3f(4,-1.6,-1);
	glTexCoord2d(0,1);
	glVertex3f(4,-1.6,-190);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from above
	glTexCoord2d(0,0);
	glVertex3f(2,-1,-190);
	glTexCoord2d(1,0);
	glVertex3f(2,-1,-1);
	glTexCoord2d(1,1);
	glVertex3f(4,-1,-1);
	glTexCoord2d(0,1);
	glVertex3f(4,-1,-190);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from side
	glTexCoord2d(0,0);
	glVertex3f(2,-1,-190);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.6,-190);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.6,-1);
	glTexCoord2d(0,1);
	glVertex3f(2,-1,-1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from side
	glTexCoord2d(0,0);
	glVertex3f(4,-1,-190);
	glTexCoord2d(1,0);
	glVertex3f(4,-1.6,-190);
	glTexCoord2d(1,1);
	glVertex3f(4,-1.6,-1);
	glTexCoord2d(0,1);
	glVertex3f(4,-1,-1);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from front
	glTexCoord2d(0,0);
	glVertex3f(4,-1.6,-1);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.6,-1);
	glTexCoord2d(1,1);
	glVertex3f(2,-1,-1);
	glTexCoord2d(0,1);
	glVertex3f(4,-1,-1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from front
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.6,-1);
	glTexCoord2d(1,0);
	glVertex3f(-2,-1.6,-1);
	glTexCoord2d(1,1);
	glVertex3f(-2,-1,-1);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1,-1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from front
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-2);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-2);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-1);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-5);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-5);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-4);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-4);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-8);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-8);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-7);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-7);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-11);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-11);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-10);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-10);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-14);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-14);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-13);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-13);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-17);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-17);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-16);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-16);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-20);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-20);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-19);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-19);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-23);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-23);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-22);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-22);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-26);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-26);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-25);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-25);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-29);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-29);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-28);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-28);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-32);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-32);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-31);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-31);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-35);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-35);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-34);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-34);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-38);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-38);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-37);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-37);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-41);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-41);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-40);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-40);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-44);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-44);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-43);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-43);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-47);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-47);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-46);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-46);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-50);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-50);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-49);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-49);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-53);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-53);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-52);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-52);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-56);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-56);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-55);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-55);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-59);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-59);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-58);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-58);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-62);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-62);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-61);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-61);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-65);
	glTexCoord2d(1,0);
	glVertex3f(4,-1.1,-65);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-64);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-64);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-68);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-68);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-67);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-67);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-71);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-71);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-70);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-70);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-74);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-74);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-73);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-73);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-77);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-77);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-76);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-76);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-80);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-80);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-79);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-79);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-83);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-83);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-82);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-82);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-86);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-86);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-85);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-85);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-89);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-89);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-88);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-88);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-92);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-92);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-91);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-91);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-95);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-95);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-94);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-94);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-98);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-98);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-97);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-97);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-101);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-101);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-100);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-100);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-104);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-104);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-103);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-103);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-107);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-107);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-106);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-106);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-110);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-110);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-109);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-109);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-113);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-113);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-112);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-112);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-116);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-116);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-115);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-115);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-119);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-119);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-118);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-118);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-122);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-122);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-121);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-121);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-125);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-125);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-124);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-124);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-128);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-128);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-127);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-127);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-131);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-131);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-130);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-130);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-134);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-134);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-133);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-133);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-137);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-137);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-136);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-136);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-140);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-140);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-139);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-139);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-143);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-143);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-142);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-142);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-146);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-146);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-145);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-145);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-149);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-149);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-148);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-148);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-152);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-152);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-151);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-151);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-155);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-155);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-154);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-154);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-158);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-158);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-157);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-157);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-161);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-161);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-160);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-160);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-164);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-164);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-163);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-163);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-167);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-167);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-166);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-166);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-170);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-170);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-169);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-169);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-173);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-173);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-172);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-172);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-176);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-176);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-175);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-175);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-179);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-179);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-178);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-178);
	glEnd();
	glPushMatrix();
	glTranslated(0,0,-164.1);
	
	glColor3f(1,1,1);//Back Sky Box
	glBindTexture(GL_TEXTURE_2D,back);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-194.1);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-194.1);
	glTexCoord2d(1,1);
	glVertex3f(10,10,-194.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-194.1);
	glEnd();
	glColor3f(1,1,1);//left Sky Box
	glBindTexture(GL_TEXTURE_2D,left);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,10);
	glTexCoord2d(1,0);
	glVertex3f(-10,-1.5,-14.1);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-14.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,10);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-7,-1.5,-14);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-34.1);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-34.1);
	glTexCoord2d(0,1);
	glVertex3f(-7,10,-14);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-14);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-14);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-14);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-14);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-74);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-74);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-74);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-74);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 3
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-7,-1.5,-34);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-54.1);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-54.1);
	glTexCoord2d(0,1);
	glVertex3f(-7,10,-34);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-7,-1.5,-54);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-74.1);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-74.1);
	glTexCoord2d(0,1);
	glVertex3f(-7,10,-54);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,secondleft);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-74);
	glTexCoord2d(1,0);
	glVertex3f(-10,-1.5,-94.1);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-94.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-74);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-7,-1.5,-94);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-114.1);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-114.1);
	glTexCoord2d(0,1);
	glVertex3f(-7,10,-94);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-94);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-94);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-94);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-94);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-154);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-154);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-154);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-154);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-7,-1.5,-114);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-134.1);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-134.1);
	glTexCoord2d(0,1);
	glVertex3f(-7,10,-114);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-7,-1.5,-134);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-154.1);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-154.1);
	glTexCoord2d(0,1);
	glVertex3f(-7,10,-134);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,secondleft);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-154);
	glTexCoord2d(1,0);
	glVertex3f(-10,-1.5,-174.1);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-174.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-154);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-7,-1.5,-174);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-194.1);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-194.1);
	glTexCoord2d(0,1);
	glVertex3f(-7,10,-174);
	glEnd();
	glColor3f(1,1,1);//left Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-174);
	glTexCoord2d(1,0);
	glVertex3f(-7,-1.5,-174);
	glTexCoord2d(1,1);
	glVertex3f(-7,10,-174);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-174);
	glEnd();
	
	glColor3f(1,1,1);//right Sky Box
	glBindTexture(GL_TEXTURE_2D,right);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,10);
	glTexCoord2d(0,0);
	glVertex3f(10,-1.5,-14.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-14.1);
	glTexCoord2d(1,1);
	glVertex3f(10,10,10);
	glEnd();
	
	glColor3f(1,1,1);//right Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(7,-1.5,-14);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-34.1);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-34.1);
	glTexCoord2d(1,1);
	glVertex3f(7,10,-14);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,1);
	glVertex3f(10,-1.5,-14);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-14);
	glTexCoord2d(1,0);
	glVertex3f(7,10,-14);
	glTexCoord2d(1,1);
	glVertex3f(10,10,-14);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,1);
	glVertex3f(11,-1.5,-73.8);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-73.8);
	glTexCoord2d(1,0);
	glVertex3f(7,10.1,-73.8);
	glTexCoord2d(1,1);
	glVertex3f(11,10.1,-73.8);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 3
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-54.1);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-34);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-34);
	glTexCoord2d(1,0);
	glVertex3f(7,10,-54.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-74.1);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-54);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-54);
	glTexCoord2d(1,0);
	glVertex3f(7,10,-74.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,secondright);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(10,-1.5,-94.1);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-74);
	glTexCoord2d(1,1);
	glVertex3f(10,10,-74);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-94.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-114.1);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-94);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-94);
	glTexCoord2d(1,0);
	glVertex3f(7,10,-114.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(10,-1.5,-94);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-94);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-94);
	glTexCoord2d(1,0);
	glVertex3f(10,10,-94);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(10,-1.5,-154);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-154);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-154);
	glTexCoord2d(1,0);
	glVertex3f(10,10,-154);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-134.1);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-114);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-114);
	glTexCoord2d(1,0);
	glVertex3f(7,10,-134.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-154.1);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-134);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-134);
	glTexCoord2d(1,0);
	glVertex3f(7,10,-154.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,secondright);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(10,-1.5,-174.1);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-154);
	glTexCoord2d(1,1);
	glVertex3f(10,10,-154);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-174.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(7,-1.5,-194.1);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-174);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-174);
	glTexCoord2d(1,0);
	glVertex3f(7,10,-194.1);
	glEnd();
	glColor3f(1,1,1);//right Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(10,-1.5,-174);
	glTexCoord2d(1,1);
	glVertex3f(7,-1.5,-174);
	glTexCoord2d(0,1);
	glVertex3f(7,10,-174);
	glTexCoord2d(1,0);
	glVertex3f(10,10,-174);
	glEnd();


	glColor3f(1,1,1);//Top Sky Box
	glBindTexture(GL_TEXTURE_2D,top);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-14.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-14.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,10);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,10);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-34.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-34.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-14);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-14);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 2
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,9,-14);
	glTexCoord2d(0,0);
	glVertex3f(10,9,-14);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-14);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-14);
	glEnd();
	//glPopMatrix();
	glColor3f(1,1,1);//Top Sky Box 3
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-54.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-54.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-34);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-34);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-74.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-74.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-54);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-54);
	glEnd();/*
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,9,-74.1);
	glTexCoord2d(0,0);
	glVertex3f(10,9,-74.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-74.1);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-74.1);
	glEnd();*/
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,secondtop);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-94.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-94.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-74);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-74);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-114.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-114.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-94);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-94);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-134.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-134.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-114);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-114);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-154.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-154.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-134);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-134);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,secondtop);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-174.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-174.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-154);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-154);
	glEnd();
	glColor3f(1,1,1);//Top Sky Box 4
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-10,10,-194.1);
	glTexCoord2d(0,0);
	glVertex3f(10,10,-194.1);
	glTexCoord2d(0,1);
	glVertex3f(10,10,-174);
	glTexCoord2d(1,1);
	glVertex3f(-10,10,-174);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D,ground);
	glBegin(GL_QUADS); //ground
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,10);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,10);
	glTexCoord2d(1,1);
	glVertex3f(10,-1.5,-14.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,-1.5,-14.1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS); //ground 2
	glColor3f(0,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-14);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-14);
	glTexCoord2d(1,1);
	glVertex3f(10,-1.5,-34.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,-1.5,-34.1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS); //ground 3
	glColor3f(0,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-34);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-34);
	glTexCoord2d(1,1);
	glVertex3f(10,-1.5,-54.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,-1.5,-54.1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS); //ground 4
	glColor3f(0,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-54);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-54);
	glTexCoord2d(1,1);
	glVertex3f(10,-1.5,-74.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,-1.5,-74.1);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,secondground);
	glBegin(GL_QUADS); //ground 4
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-74);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-74);
	glTexCoord2d(1,1);
	glVertex3f(10,-1.5,-94.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,-1.5,-94.1);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,block);
	glBegin(GL_QUADS); //ground 4
	glColor3f(0,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-94);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-94);
	glTexCoord2d(1,1);
	glVertex3f(10,-1.5,-154.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,-1.5,-154.1);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,secondground);
	glBegin(GL_QUADS); //ground 4
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-10,-1.5,-154);
	glTexCoord2d(1,0);
	glVertex3f(10,-1.5,-154);
	glTexCoord2d(1,1);
	glVertex3f(10,-1.5,-174.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,-1.5,-174.1);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah             taaaaaaaaaadiiiiiiiilllllllll
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.6,-190);
	glTexCoord2d(1,0);
	glVertex3f(-4,-1.6,-1);
	glTexCoord2d(1,1);
	glVertex3f(-2,-1.6,-1);
	glTexCoord2d(0,1);
	glVertex3f(-2,-1.6,-190);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from above
	glTexCoord2d(0,0);
	glVertex3f(-4,-1,-190);
	glTexCoord2d(1,0);
	glVertex3f(-4,-1,-1);
	glTexCoord2d(1,1);
	glVertex3f(-2,-1,-1);
	glTexCoord2d(0,1);
	glVertex3f(-2,-1,-190);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from side
	glTexCoord2d(0,0);
	glVertex3f(-4,-1,-190);
	glTexCoord2d(1,0);
	glVertex3f(-4,-1.9,-190);
	glTexCoord2d(1,1);
	glVertex3f(-4,-1.9,-1);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1,-1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from side
	glTexCoord2d(0,0);
	glVertex3f(-2,-1,-190);
	glTexCoord2d(1,0);
	glVertex3f(-2,-1.6,-190);
	glTexCoord2d(1,1);
	glVertex3f(-2,-1.6,-1);
	glTexCoord2d(0,1);
	glVertex3f(-2,-1,-1);
	glEnd();
	
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah
	glTexCoord2d(0,0);
	glVertex3f(2,-1.6,-190);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.6,-1);
	glTexCoord2d(1,1);
	glVertex3f(4,-1.6,-1);
	glTexCoord2d(0,1);
	glVertex3f(4,-1.6,-190);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from above
	glTexCoord2d(0,0);
	glVertex3f(2,-1,-190);
	glTexCoord2d(1,0);
	glVertex3f(2,-1,-1);
	glTexCoord2d(1,1);
	glVertex3f(4,-1,-1);
	glTexCoord2d(0,1);
	glVertex3f(4,-1,-190);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from side
	glTexCoord2d(0,0);
	glVertex3f(2,-1,-190);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.6,-190);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.6,-1);
	glTexCoord2d(0,1);
	glVertex3f(2,-1,-1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from side
	glTexCoord2d(0,0);
	glVertex3f(4,-1,-190);
	glTexCoord2d(1,0);
	glVertex3f(4,-1.6,-190);
	glTexCoord2d(1,1);
	glVertex3f(4,-1.6,-1);
	glTexCoord2d(0,1);
	glVertex3f(4,-1,-1);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from front
	glTexCoord2d(0,0);
	glVertex3f(4,-1.6,-1);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.6,-1);
	glTexCoord2d(1,1);
	glVertex3f(2,-1,-1);
	glTexCoord2d(0,1);
	glVertex3f(4,-1,-1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from front
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.6,-1);
	glTexCoord2d(1,0);
	glVertex3f(-2,-1.6,-1);
	glTexCoord2d(1,1);
	glVertex3f(-2,-1,-1);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1,-1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah from front
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-2);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-2);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-1);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-5);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-5);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-4);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-4);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-8);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-8);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-7);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-7);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-11);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-11);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-10);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-10);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-14);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-14);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-13);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-13);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-17);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-17);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-16);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-16);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-20);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-20);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-19);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-19);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-23);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-23);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-22);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-22);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-26);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-26);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-25);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-25);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-29);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-29);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-28);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-28);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-32);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-32);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-31);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-31);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-35);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-35);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-34);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-34);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-38);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-38);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-37);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-37);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-41);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-41);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-40);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-40);
	glEnd();
		glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-44);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-44);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-43);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-43);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-47);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-47);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-46);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-46);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-50);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-50);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-49);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-49);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-53);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-53);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-52);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-52);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-56);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-56);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-55);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-55);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-59);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-59);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-58);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-58);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-62);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-62);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-61);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-61);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-65);
	glTexCoord2d(1,0);
	glVertex3f(4,-1.1,-65);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-64);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-64);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-68);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-68);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-67);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-67);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-71);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-71);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-70);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-70);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-74);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-74);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-73);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-73);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-77);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-77);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-76);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-76);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-80);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-80);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-79);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-79);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-83);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-83);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-82);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-82);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-86);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-86);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-85);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-85);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-89);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-89);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-88);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-88);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-92);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-92);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-91);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-91);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-95);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-95);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-94);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-94);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-98);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-98);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-97);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-97);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-101);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-101);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-100);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-100);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-104);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-104);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-103);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-103);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-107);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-107);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-106);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-106);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-110);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-110);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-109);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-109);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-113);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-113);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-112);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-112);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-116);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-116);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-115);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-115);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-119);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-119);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-118);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-118);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-122);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-122);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-121);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-121);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-125);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-125);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-124);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-124);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-128);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-128);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-127);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-127);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-131);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-131);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-130);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-130);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-134);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-134);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-133);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-133);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-137);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-137);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-136);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-136);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-140);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-140);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-139);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-139);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-143);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-143);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-142);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-142);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-146);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-146);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-145);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-145);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-149);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-149);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-148);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-148);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-152);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-152);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-151);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-151);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-155);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-155);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-154);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-154);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-158);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-158);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-157);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-157);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-161);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-161);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-160);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-160);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-164);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-164);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-163);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-163);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-167);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-167);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-166);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-166);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-170);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-170);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-169);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-169);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-173);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-173);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-172);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-172);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-176);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-176);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-175);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-175);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);//Sekkah small
	glTexCoord2d(0,0);
	glVertex3f(-4,-1.1,-179);
	glTexCoord2d(1,0);
	glVertex3f(2,-1.1,-179);
	glTexCoord2d(1,1);
	glVertex3f(2,-1.1,-178);
	glTexCoord2d(0,1);
	glVertex3f(-4,-1.1,-178);
	glEnd();
	glPopMatrix();
}


int mouseX =0  , mouseY=0;
bool isClicked = false , isRClicked = false;
void mouse (int , int , bool , bool);
double d=0;
float a2=90;
float z5;
float move=0;
void DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	if(open){
		if(!first){
			d+=0.01;
			if(d>1){
				first = true;
			}
		}
	}
	else{
		if(first){
			d-=0.01;
			if(d<0){
				first = false;
			}
		}
	}




	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glLoadIdentity();	
	//PlaySound("C:\\Users\\pc\\Documents\\Visual Studio 2012\\Projects\\Project1\\Project1\\Shot.wav",NULL,SND_ASYNC);
	key(keys);
	if(keys['J'])
	{
	PlaySound(TEXT("door-1-open.wav"),NULL,SND_ASYNC);
	}
	gluLookAt(j,y,i,k,y,w,0,1,0);
	glTranslated(0,-2,-10);
	glPushMatrix();
	glColor3f(1,1,1);

	glPushMatrix();
	glTranslated(0,0,move);
	if(keys['M'])
		move+=0.1;
	skybox();
	glPopMatrix();
	
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,bear);
	glBegin(GL_QUADS);//inner wall
	glTexCoord2d(0,0);
	glVertex3f(1,2.3,-10.0);
	glTexCoord2d(1,0);
	glVertex3f(2.7,2.3,-10.0);
	glTexCoord2d(1,1);
	glVertex3f(2.7,5,-10.0);
	glTexCoord2d(0,1);
	glVertex3f(1,5,-10.0);
	glEnd();
	

	glColor3f(1,1,1);//Side wall
	glBindTexture(GL_TEXTURE_2D,baby);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(3,0,-10);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-10);
	glTexCoord2d(0,1);
	glVertex3f(3,6,0);
	glTexCoord2d(0,0);
	glVertex3f(3,0,0);
	glEnd();
	glColor3f(1,1,1);//Side wall
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(3.1,0,-10);
	glTexCoord2d(1,1);
	glVertex3f(3.1,6,-10);
	glTexCoord2d(0,1);
	glVertex3f(3.1,6,0);
	glTexCoord2d(0,0);
	glVertex3f(3.1,0,0);
	glEnd();



	glColor3f(1,1,1);//Side wall 2
	glBindTexture(GL_TEXTURE_2D,baby);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-3,0,-10);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-10);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,0);
	glTexCoord2d(0,0);
	glVertex3f(-3,0,0);
	glEnd();
	glColor3f(1,1,1);
	glColor3f(1,1,1);//Side wall 2
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-3.1,0,-10);
	glTexCoord2d(1,1);
	glVertex3f(-3.1,6,-10);
	glTexCoord2d(0,1);
	glVertex3f(-3.1,6,0);
	glTexCoord2d(0,0);
	glVertex3f(-3.1,0,0);
	glEnd();
	glColor3f(1,1,1);


	glBindTexture(GL_TEXTURE_2D,baby1);
	glBegin(GL_QUADS);//roof
	glTexCoord2d(0,0);
	glVertex3f(-3,6,-10);
	glTexCoord2d(1,0);
	glVertex3f(3,6,-10);
	glTexCoord2d(1,1);
	glVertex3f(3,6,0);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,0);
	glEnd();

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3.1,0,0);
	glTexCoord2d(1,1);
	glVertex3f(-3.1,6,0);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,0);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,0);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,baby);
	glBegin(GL_QUADS);//wall from inside
	glTexCoord2d(0,1);
	glVertex3f(-3.1,0,-10);
	glTexCoord2d(1,1);
	glVertex3f(-3.1,6,-10);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-10);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-10);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//wall from inside
	glTexCoord2d(0,1);
	glVertex3f(-3.1,0,-10.1);
	glTexCoord2d(1,1);
	glVertex3f(-3.1,6,-10.1);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-10.1);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-10.1);
	glEnd();
	glColor3f(1,1,1);
	


	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//outside door
	glTexCoord2d(0,0);
	glVertex3f(2,0,0);
	glTexCoord2d(1,0);
	glVertex3f(2,6,0);
	glTexCoord2d(1,1);
	glVertex3f(3.1,6,0);
	glTexCoord2d(0,1);
	glVertex3f(3.1,0,0);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,baby);
	glBegin(GL_QUADS);//outside door
	glTexCoord2d(0,0);
	glVertex3f(2,0,-10);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-10);
	glTexCoord2d(1,1);
	glVertex3f(3.1,6,-10);
	glTexCoord2d(0,1);
	glVertex3f(3.1,0,-10);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//outside door
	glTexCoord2d(0,0);
	glVertex3f(2,0,-10.1);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-10.1);
	glTexCoord2d(1,1);
	glVertex3f(3.2,6,-10.1);
	glTexCoord2d(0,1);
	glVertex3f(3.2,0,-10.1);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//inside wall above door
	glTexCoord2d(0,0);
	glVertex3f(-2,4,0);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,0);
	glTexCoord2d(1,1);
	glVertex3f(2,6,0);
	glTexCoord2d(1,0);
	glVertex3f(2,4,0);
	glEnd();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,baby);
	glBegin(GL_QUADS);//inside wall above door
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-10);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-10);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-10);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-10);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//inside wall above door
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-10.1);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-10.1);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-10.1);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-10.1);
	glEnd();




	glColor3f(1,1,1);//redcarpet
	glBindTexture(GL_TEXTURE_2D,baby1);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-3,0.01,0);
	glTexCoord2d(0,1);
	glVertex3f(-3,0.01,-10);
	glTexCoord2d(1,1);
	glVertex3f(3,0.01,-10);
	glTexCoord2d(1,0);
	glVertex3f(3,0.01,0);
	glEnd();

	
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from down
	glTexCoord2d(0,0);
	glVertex3f(3,0.1,-9);
	glTexCoord2d(0,1);
	glVertex3f(2,0.1,-9);
	glTexCoord2d(1,1);
	glVertex3f(2,0.1,-6);
	glTexCoord2d(1,0);
	glVertex3f(3,0.1,-6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from up
	glTexCoord2d(0,0);
	glVertex3f(3,1,-9);
	glTexCoord2d(0,1);
	glVertex3f(2,1,-9);
	glTexCoord2d(1,1);
	glVertex3f(2,1,-6);
	glTexCoord2d(1,0);
	glVertex3f(3,1,-6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,redcarpet);
	glBegin(GL_QUADS);//bed from up farsheh
	glTexCoord2d(0,0);
	glVertex3f(3,1.5,-9);
	glTexCoord2d(0,1);
	glVertex3f(2,1.5,-9);
	glTexCoord2d(1,1);
	glVertex3f(2,1.5,-6);
	glTexCoord2d(1,0);
	glVertex3f(3,1.5,-6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side
	
	glTexCoord2d(0,0);
	glVertex3f(2,0.1,-6);
	glTexCoord2d(0,1);
	glVertex3f(2,1,-6);
	glTexCoord2d(1,1);
	glVertex3f(3,1,-6);
	glTexCoord2d(1,0);
	glVertex3f(3,0.1,-6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,redcarpet);
	glBegin(GL_QUADS);//bed from side farsheh
	
	glTexCoord2d(0,0);
	glVertex3f(2,1,-6);
	glTexCoord2d(0,1);
	glVertex3f(2,1.5,-6);
	glTexCoord2d(1,1);
	glVertex3f(3,1.5,-6);
	glTexCoord2d(1,0);
	glVertex3f(3,1,-6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side
	glTexCoord2d(0,0);
	glVertex3f(2,0.1,-6);
	glTexCoord2d(0,1);
	glVertex3f(2,1,-6);
	glTexCoord2d(1,1);
	glVertex3f(2,1,-9);
	glTexCoord2d(1,0);
	glVertex3f(2,0.1,-9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,redcarpet);
	glBegin(GL_QUADS);//bed from side farsheh
	glTexCoord2d(0,0);
	glVertex3f(2,1,-6);
	glTexCoord2d(0,1);
	glVertex3f(2,1.5,-6);
	glTexCoord2d(1,1);
	glVertex3f(2,1.5,-9);
	glTexCoord2d(1,0);
	glVertex3f(2,1,-9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(2,1,-6);
	glTexCoord2d(0,1);
	glVertex3f(2,2,-6);
	glTexCoord2d(1,1);
	glVertex3f(2,2,-6.5);
	glTexCoord2d(1,0);
	glVertex3f(2,1,-6.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(2,1,-7);
	glTexCoord2d(0,1);
	glVertex3f(2,2,-7);
	glTexCoord2d(1,1);
	glVertex3f(2,2,-7.5);
	glTexCoord2d(1,0);
	glVertex3f(2,1,-7.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(2,1,-8);
	glTexCoord2d(0,1);
	glVertex3f(2,2,-8);
	glTexCoord2d(1,1);
	glVertex3f(2,2,-8.5);
	glTexCoord2d(1,0);
	glVertex3f(2,1,-8.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(2,1.8,-6);
	glTexCoord2d(0,1);
	glVertex3f(2,2,-6);
	glTexCoord2d(1,1);
	glVertex3f(2,2,-9);
	glTexCoord2d(1,0);
	glVertex3f(2,1.8,-9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(2,1.8,-6);
	glTexCoord2d(0,1);
	glVertex3f(2,2,-6);
	glTexCoord2d(1,1);
	glVertex3f(3,2,-6);
	glTexCoord2d(1,0);
	glVertex3f(3,1.8,-6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(2,1,-6);
	glTexCoord2d(0,1);
	glVertex3f(2,2,-6);
	glTexCoord2d(1,1);
	glVertex3f(2.2,2,-6);
	glTexCoord2d(1,0);
	glVertex3f(2.2,1,-6);
	glEnd();
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(2.4,1,-6);
	glTexCoord2d(0,1);
	glVertex3f(2.4,2,-6);
	glTexCoord2d(1,1);
	glVertex3f(2.6,2,-6);
	glTexCoord2d(1,0);
	glVertex3f(2.6,1,-6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(2.8,1,-6);
	glTexCoord2d(0,1);
	glVertex3f(2.8,2,-6);
	glTexCoord2d(1,1);
	glVertex3f(3,2,-6);
	glTexCoord2d(1,0);
	glVertex3f(3,1,-6);
	glEnd();/*
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(2.6,1,-7);
	glTexCoord2d(0,1);
	glVertex3f(2.6,2,-7);
	glTexCoord2d(1,1);
	glVertex3f(2.8,2,-7);
	glTexCoord2d(1,0);
	glVertex3f(2.8,1,-7);
	glEnd();
	/*glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(3.6,1,-7);
	glTexCoord2d(0,1);
	glVertex3f(3.6,2,-7);
	glTexCoord2d(1,1);
	glVertex3f(3.8,2,-7);
	glTexCoord2d(1,0);
	glVertex3f(3.8,1,-7);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(4.5,1,-7);
	glTexCoord2d(0,1);
	glVertex3f(4.5,2,-7);
	glTexCoord2d(1,1);
	glVertex3f(4.7,2,-7);
	glTexCoord2d(1,0);
	glVertex3f(4.7,1,-7);
	glEnd();*/
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(3,1.5,-6);
	glTexCoord2d(0,1);
	glVertex3f(3,2,-6);
	glTexCoord2d(1,1);
	glVertex3f(3,2,-9);
	glTexCoord2d(1,0);
	glVertex3f(3,1.5,-9);
	glEnd();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(3,1.5,-9);
	glTexCoord2d(0,1);
	glVertex3f(3,2,-9);
	glTexCoord2d(1,1);
	glVertex3f(3,2,-9);
	glTexCoord2d(1,0);
	glVertex3f(3,1.5,-9);
	glEnd();
	glPopMatrix();
	/*glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(3.8,1.5,-9);
	glTexCoord2d(0,1);
	glVertex3f(3.8,2,-9);
	glTexCoord2d(1,1);
	glVertex3f(3.5,2,-9);
	glTexCoord2d(1,0);
	glVertex3f(3.5,1.5,-9);
	glEnd();*/
	/*
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(2.9,1.5,-9);
	glTexCoord2d(0,1);
	glVertex3f(2.9,2,-9);
	glTexCoord2d(1,1);
	glVertex3f(2.6,2,-9);
	glTexCoord2d(1,0);
	glVertex3f(2.6,1.5,-9);
	glEnd();*/
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(3,1.5,-9);
	glTexCoord2d(0,1);
	glVertex3f(3,2,-9);
	glTexCoord2d(1,1);
	glVertex3f(2.8,2,-9);
	glTexCoord2d(1,0);
	glVertex3f(2.8,1.5,-9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(2.6,1.5,-9);
	glTexCoord2d(0,1);
	glVertex3f(2.6,2,-9);
	glTexCoord2d(1,1);
	glVertex3f(2.4,2,-9);
	glTexCoord2d(1,0);
	glVertex3f(2.4,1.5,-9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(2.2,1.5,-9);
	glTexCoord2d(0,1);
	glVertex3f(2.2,2,-9);
	glTexCoord2d(1,1);
	glVertex3f(2,2,-9);
	glTexCoord2d(1,0);
	glVertex3f(2,1.5,-9);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//bed from side Eidan
	glTexCoord2d(0,0);
	glVertex3f(2,1.7,-9);
	glTexCoord2d(0,1);
	glVertex3f(2,2,-9);
	glTexCoord2d(1,1);
	glVertex3f(3,2,-9);
	glTexCoord2d(1,0);
	glVertex3f(3,1.7,-9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,cat);
	glBegin(GL_QUADS);//tent
	glTexCoord2d(0,0);
	glVertex3f(2.8,0.1,-4);
	glTexCoord2d(0,1);
	glVertex3f(2.6,1.2,-4);
	glTexCoord2d(1,1);
	glVertex3f(1,1.2,-4);
	glTexCoord2d(1,0);
	glVertex3f(1.2,0.1,-4);
	glEnd();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D,cat);
	glBegin(GL_QUADS);//tent
	glTexCoord2d(0,0);
	glVertex3f(2.8,0.1,-6);
	glTexCoord2d(0,1);
	glVertex3f(2.6,1.2,-4);
	glTexCoord2d(1,1);
	glVertex3f(1,1.2,-4);
	glTexCoord2d(1,0);
	glVertex3f(1.2,0.1,-6);
	glEnd();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D,redcarpet);
	glBegin(GL_QUADS);//tent
	glTexCoord2d(0,0);
	glVertex3f(3,0.1,-3.7);
	glTexCoord2d(0,1);
	glVertex3f(1,0.1,-6.2);
	glTexCoord2d(1,1);
	glVertex3f(3,0.1,-6.2);
	glTexCoord2d(1,0);
	glVertex3f(1,0.1,-3.7);
	glEnd();
	glPopMatrix();
  glBindTexture(GL_TEXTURE_2D,redcarpet);
	glBegin(GL_QUADS);//play area
	glTexCoord2d(0,0);
	glVertex3f(-3,0.1,-5);
	glTexCoord2d(0,1);
	glVertex3f(-3,0.1,-9);
	glTexCoord2d(1,1);
	glVertex3f(-1,0.1,-9);
	glTexCoord2d(1,0);
	glVertex3f(-1,0.1,-5);
	glEnd();
	glPopMatrix();
	 glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-3,0.1,-9);
	glTexCoord2d(0,1);
	glVertex3f(-2.7,0.1,-9);
	glTexCoord2d(1,1);
	glVertex3f(-2.7,1,-9);
	glTexCoord2d(1,0);
	glVertex3f(-3,1,-9);
	glEnd();
	/*
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-2.1,0.1,-9);
	glTexCoord2d(0,1);
	glVertex3f(-1.8,0.1,-9);
	glTexCoord2d(1,1);
	glVertex3f(-1.8,1,-9);
	glTexCoord2d(1,0);
	glVertex3f(-2.1,1,-9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-1.2,0.1,-9);
	glTexCoord2d(0,1);
	glVertex3f(-2.9,0.1,-9);
	glTexCoord2d(1,1);
	glVertex3f(-2.9,1,-9);
	glTexCoord2d(1,0);
	glVertex3f(-3.2,1,-9);
	glEnd();*/
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-2.3,0.1,-9);
	glTexCoord2d(0,1);
	glVertex3f(-2,0.1,-9);
	glTexCoord2d(1,1);
	glVertex3f(-2,1,-9);
	glTexCoord2d(1,0);
	glVertex3f(-2.3,1,-9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-1.3,0.1,-9);
	glTexCoord2d(0,1);
	glVertex3f(-1,0.1,-9);
	glTexCoord2d(1,1);
	glVertex3f(-1,1,-9);
	glTexCoord2d(1,0);
	glVertex3f(-1.3,1,-9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-3,0.7,-9);
	glTexCoord2d(0,1);
	glVertex3f(-1,0.7,-9);
	glTexCoord2d(1,1);
	glVertex3f(-1,1,-9);
	glTexCoord2d(1,0);
	glVertex3f(-3,1,-9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-1,0.7,-9);
	glTexCoord2d(0,1);
	glVertex3f(-1,1,-9);
	glTexCoord2d(1,1);
	glVertex3f(-1,1,-6);
	glTexCoord2d(1,0);
	glVertex3f(-1,0.7,-6);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-1,0.1,-9);
	glTexCoord2d(0,1);
	glVertex3f(-1,1,-9);
	glTexCoord2d(1,1);
	glVertex3f(-1,1,-9);
	glTexCoord2d(1,0);
	glVertex3f(-1,0.1,-9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-1,0.1,-8.1);
	glTexCoord2d(0,1);
	glVertex3f(-1,1,-8.1);
	glTexCoord2d(1,1);
	glVertex3f(-1,1,-7.8);
	glTexCoord2d(1,0);
	glVertex3f(-1,0.1,-7.8);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-1,0.1,-7.2);
	glTexCoord2d(0,1);
	glVertex3f(-1,1,-7.2);
	glTexCoord2d(1,1);
	glVertex3f(-1,1,-6.9);
	glTexCoord2d(1,0);
	glVertex3f(-1,0.1,-6.9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-1,0.1,-6.3);
	glTexCoord2d(0,1);
	glVertex3f(-1,1,-6.3);
	glTexCoord2d(1,1);
	glVertex3f(-1,1,-6);
	glTexCoord2d(1,0);
	glVertex3f(-1,0.1,-6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-1,0.1,-5.3);
	glTexCoord2d(0,1);
	glVertex3f(-1,1,-5.3);
	glTexCoord2d(1,1);
	glVertex3f(-1,1,-5);
	glTexCoord2d(1,0);
	glVertex3f(-1,0.1,-5);
	glEnd();/*
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-5,0.1,-5);
	glTexCoord2d(0,1);
	glVertex3f(-4.7,0.1,-5);
	glTexCoord2d(1,1);
	glVertex3f(-4.7,1,-5);
	glTexCoord2d(1,0);
	glVertex3f(-5,1,-5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-4.1,0.1,-5);
	glTexCoord2d(0,1);
	glVertex3f(-3.8,0.1,-5);
	glTexCoord2d(1,1);
	glVertex3f(-3.8,1,-5);
	glTexCoord2d(1,0);
	glVertex3f(-4.1,1,-5);
	glEnd();*/
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-3,0.1,-5);
	glTexCoord2d(0,1);
	glVertex3f(-2.8,0.1,-5);
	glTexCoord2d(1,1);
	glVertex3f(-2.8,1,-5);
	glTexCoord2d(1,0);
	glVertex3f(-3,1,-5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-2.6,0.1,-5);
	glTexCoord2d(0,1);
	glVertex3f(-2.4,0.1,-5);
	glTexCoord2d(1,1);
	glVertex3f(-2.4,1,-5);
	glTexCoord2d(1,0);
	glVertex3f(-2.6,1,-5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-2.2,0.1,-5);
	glTexCoord2d(0,1);
	glVertex3f(-2,0.1,-5);
	glTexCoord2d(1,1);
	glVertex3f(-2,1,-5);
	glTexCoord2d(1,0);
	glVertex3f(-2.2,1,-5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-1.8,0.1,-5);
	glTexCoord2d(0,1);
	glVertex3f(-1.6,0.1,-5);
	glTexCoord2d(1,1);
	glVertex3f(-1.6,1,-5);
	glTexCoord2d(1,0);
	glVertex3f(-1.8,1,-5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-1.4,0.1,-5);
	glTexCoord2d(0,1);
	glVertex3f(-1.2,0.1,-5);
	glTexCoord2d(1,1);
	glVertex3f(-1.2,1,-5);
	glTexCoord2d(1,0);
	glVertex3f(-1.4,1,-5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-3,0.7,-5);
	glTexCoord2d(0,1);
	glVertex3f(-1,0.7,-5);
	glTexCoord2d(1,1);
	glVertex3f(-1,1,-5);
	glTexCoord2d(1,0);
	glVertex3f(-3,1,-5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-3,0.7,-9);
	glTexCoord2d(0,1);
	glVertex3f(-3,1,-9);
	glTexCoord2d(1,1);
	glVertex3f(-3,1,-5);
	glTexCoord2d(1,0);
	glVertex3f(-3,0.7,-5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-3,0.1,-9);
	glTexCoord2d(0,1);
	glVertex3f(-3,1,-9);
	glTexCoord2d(1,1);
	glVertex3f(-3,1,-9);
	glTexCoord2d(1,0);
	glVertex3f(-3,0.1,-9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-3,0.1,-9);
	glTexCoord2d(0,1);
	glVertex3f(-3,1,-9);
	glTexCoord2d(1,1);
	glVertex3f(-3,1,-6.8);
	glTexCoord2d(1,0);
	glVertex3f(-3,0.1,-6.8);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-3,0.1,-6.2);
	glTexCoord2d(0,1);
	glVertex3f(-3,1,-6.2);
	glTexCoord2d(1,1);
	glVertex3f(-3,1,-6.9);
	glTexCoord2d(1,0);
	glVertex3f(-3,0.1,-6.9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-3,0.1,-6.3);
	glTexCoord2d(0,1);
	glVertex3f(-3,1,-6.3);
	glTexCoord2d(1,1);
	glVertex3f(-3,1,-6);
	glTexCoord2d(1,0);
	glVertex3f(-3,0.1,-6);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//play area wood
	glTexCoord2d(0,0);
	glVertex3f(-3,0.1,-5.3);
	glTexCoord2d(0,1);
	glVertex3f(-3,1,-5.3);
	glTexCoord2d(1,1);
	glVertex3f(-3,1,-5);
	glTexCoord2d(1,0);
	glVertex3f(-3,0.1,-5);
	glEnd();
	

	glPopMatrix();





	glPushMatrix();
	glTranslated(-d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door1);
	glBegin(GL_QUADS);//left
	glTexCoord2d(0,0);
	glVertex3f(-2,0,0.01);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,0.01);
	glTexCoord2d(1,1);
	glVertex3f(0,4,0.01);
	glTexCoord2d(1,0);
	glVertex3f(0,0,0.01);
	glEnd();
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslated(d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(0,0,0.01);
	glTexCoord2d(1,0);
	glVertex3f(2,0,0.01);
	glTexCoord2d(1,1);
	glVertex3f(2,4,0.01);
	glTexCoord2d(0,1);
	glVertex3f(0,4,0.01);
	glEnd();
	glPopMatrix();
	


	
	glPushMatrix();
	glTranslated(-d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door1);
	glBegin(GL_QUADS);//left
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-9.9);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,-9.9);
	glTexCoord2d(1,1);
	glVertex3f(0,4,-9.9);
	glTexCoord2d(1,0);
	glVertex3f(0,0,-9.9);
	glEnd();
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslated(d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(0,0,-9.9);
	glTexCoord2d(1,0);
	glVertex3f(2,0,-9.9);
	glTexCoord2d(1,1);
	glVertex3f(2,4,-9.9);
	glTexCoord2d(0,1);
	glVertex3f(0,4,-9.9);
	glEnd();
	glPopMatrix();

	glPushMatrix();
glTranslated(3,-0.4,-1);

glBegin(GL_POLYGON);//FIRST WHEEL
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(-5,0,0);//SECOND WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(0.5,0,-9);//THIRD WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(6,0,0);//FOURTH WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glPopMatrix();
	


	//nehaaaaaaiaaaaaat       taaaaaadiiiiiiiiil
	

	//Second room
	glBindTexture(GL_TEXTURE_2D, redcarpet);


	glBegin(GL_QUADS); //bed
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 1, -29);
	glTexCoord2d(1, 0);
	glVertex3f(-1, 1, -29);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -24);
	glTexCoord2d(0, 1);
	glVertex3f(-3, 1, -24);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 0.1, -24);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 1, -24);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -24);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 0.1, -24);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1, 0.1, -29);
	glTexCoord2d(1, 0);
	glVertex3f(-1, 1, -29);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -24);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 0.1, -24);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 1, -29);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 1.5, -29);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1.5, -29);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -29);
	glEnd();
	/*
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-4.9, 1, -29);
	glTexCoord2d(1, 0);
	glVertex3f(-4.9, 1.5, -29);
	glTexCoord2d(1, 1);
	glVertex3f(-4.9, 1.5, -24);
	glTexCoord2d(0, 1);
	glVertex3f(-4.9, 1, -24);
	glEnd();*/
	glBindTexture(GL_TEXTURE_2D, brick);//wordrobe
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(1.8, 0.1, -28);
	glTexCoord2d(1, 0);
	glVertex3f(1.8, 3, -28);
	glTexCoord2d(1, 1);
	glVertex3f(2.8, 3, -28);
	glTexCoord2d(0, 1);
	glVertex3f(2.8, 0.1, -28);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,wood);//wordrobe
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(1.8, 0.1, -28);
	glTexCoord2d(1, 0);
	glVertex3f(1.8, 3, -28);
	glTexCoord2d(1, 1);
	glVertex3f(1.8, 3, -29);
	glTexCoord2d(0, 1);
	glVertex3f(1.8, 0.1, -29);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);//wordrobe
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(1.9, 1.5, -28);
	glTexCoord2d(1, 0);
	glVertex3f(1.9, 1.6, -28);
	glTexCoord2d(1, 1);
	glVertex3f(2.1, 1.6, -28);
	glTexCoord2d(0, 1);
	glVertex3f(2.1, 1.5, -28);
	glEnd();
	



	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3f(-1, 0.6, -29);
	glTexCoord2d(1, 0);
	glVertex3f(-1, 1, -29);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -24);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 0.6, -24);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 0.6, -24);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 1, -24);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -24);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 0.6, -24);
	glEnd();


	/*
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,painting);
	glBegin(GL_QUADS);//ÇááæÍÉ ÇáÏÇÎíáíÉ
	glTexCoord2d(0,0);
	glVertex3f(-4.5,2,-29.9);
	glTexCoord2d(1,0);
	glVertex3f(-3,2,-29.9);
	glTexCoord2d(1,1);
	glVertex3f(-3,3,-29.9);
	glTexCoord2d(0,1);
	glVertex3f(-4.5,3,-29.9);
	glEnd();
	*/






	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(3,0,-30);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-30);
	glTexCoord2d(0,1);
	glVertex3f(3,6,-20);
	glTexCoord2d(0,0);
	glVertex3f(3,0,-20);
	glEnd();



	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-3,0,-30);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-30);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-20);
	glTexCoord2d(0,0);
	glVertex3f(-3,0,-20);
	glEnd();
	glColor3f(1,1,1);


	glBindTexture(GL_TEXTURE_2D,roof);
	glBegin(GL_QUADS);//ÇáÓÞÝ
	glTexCoord2d(0,0);
	glVertex3f(-3,6,-30);
	glTexCoord2d(1,0);
	glVertex3f(3,6,-30);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-20);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-20);
	glEnd();

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-20);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-20);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-20);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-20);
	glEnd();
	glColor3f(1, 1, 1);
 glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);
	glVertex3f(-3, 0, -30);
	glTexCoord2d(1, 1);
	glVertex3f(-3, 6, -30);
	glTexCoord2d(1, 0);
	glVertex3f(-2, 6, -30);
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0,-30);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-20);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-20);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-20);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-20);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(2, 0, -30);
	glTexCoord2d(1, 0);
	glVertex3f(2, 6, -30);
	glTexCoord2d(1, 1);
	glVertex3f(3, 6, -30);
	glTexCoord2d(0, 1);
	glVertex3f(3, 0, -30);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-20);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-20);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-20);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-20);
	glEnd();

	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ
	glTexCoord2d(0, 0);
	glVertex3f(-2, 4, -30);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 6, -30);
	glTexCoord2d(1, 1);
	glVertex3f(2, 6, -30);
	glTexCoord2d(1, 0);
	glVertex3f(2, 4, -30);
	glEnd();


	glColor3f(1,1,1);//ÃÑÖíÉ ÇáãÞÕæÑÉ
	glBindTexture(GL_TEXTURE_2D,redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-3,0.01,-20);
	glTexCoord2d(0,1);
	glVertex3f(-3,0.01,-29.8);
	glTexCoord2d(1,1);
	glVertex3f(3,0.01,-29.8);
	glTexCoord2d(1,0);
	glVertex3f(3,0.01,-20);
	glEnd();


	/*glColor3f(1,1,1);//Back Sky Box
	glBindTexture(GL_TEXTURE_2D,back);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,0,-30.1);
	glTexCoord2d(1,0);
	glVertex3f(10,0,-30.1);
	glTexCoord2d(1,1);
	glVertex3f(10,10,-30.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-30.1);
	glEnd();*/
glPushMatrix();
	glTranslated(-d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door1);
	glBegin(GL_QUADS);//ÇáÈÇÈ ÇáíÓÇÑ
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-19.8);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,-19.8);
	glTexCoord2d(1,1);
	glVertex3f(0,4,-19.8);
	glTexCoord2d(1,0);
	glVertex3f(0,0,-19.8);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-d, 0, 0);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, door1);
	glBegin(GL_QUADS);//ÇáÈÇÈ ÇáíÓÇÑ
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -29.8);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 4, -29.8);
	glTexCoord2d(1, 1);
	glVertex3f(0, 4,-29.8);
	glTexCoord2d(1, 0);
	glVertex3f(0, 0,-29.8);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslated(d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(0,0,-19.8);
	glTexCoord2d(1,0);
	glVertex3f(2,0,-19.8);
	glTexCoord2d(1,1);
	glVertex3f(2,4,-19.8);
	glTexCoord2d(0,1);
	glVertex3f(0,4,-19.8);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(d, 0, 0);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(0, 0, -29.8);
	glTexCoord2d(1, 0);
	glVertex3f(2, 0, -29.8);
	glTexCoord2d(1, 1);
	glVertex3f(2, 4, -29.8);
	glTexCoord2d(0, 1);
	glVertex3f(0, 4, -29.8);
	glEnd();
	glPopMatrix();
	glPushMatrix();
glTranslated(3,-0.4,-21);

glBegin(GL_POLYGON);//FIRST WHEEL
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(-5,0,0);//SECOND WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(0.5,0,-9);//THIRD WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(6,0,0);//FOURTH WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glPopMatrix();
	//THE END OF THE SECOND ROOM
	//THIRD ROOM
	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÇæá
	glTranslated(1,0,-4.5);
	chair();
	glTranslated(0,0,-1.2);
	chair();
	glTranslated(0,0,-1.2);
	chair();
	glTranslated(0,0,-1.2);
	chair();
	glTranslated(0,0,-1.2);
	chair();
	glTranslated(0,0,-1.2);
	chair();
	/*
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair();
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,0,-1);
	chair();
	glPopMatrix();
	
    glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,-1);
	chair();
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,0,-1);
	*/
	/*
	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáËÇäí
	glTranslated(2,0,-6);
	chair();
	
	chair();
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair();
	glPopMatrix();

    glPopMatrix();

	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáËÇáË
	glTranslated(2,0,-7.5);
	chair();
	
	chair();
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair();
	glPopMatrix();

    glPopMatrix();
    

	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÑÇÈÚ
	glTranslated(2,0,-9);
	chair();
	
	chair();
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair();
	glPopMatrix();

    glPopMatrix();

	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÎÇãÓ
	glTranslated(2,0,-10.5);
	chair();
	
	chair();
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair();
	glPopMatrix();

    glPopMatrix();

	glPushMatrix();
	glTranslated(2,0,-12);
	chair();
	
	chair();
	glPushMatrix();
	
	glTranslated(1.5,0,0);
	chair();
	glPopMatrix();
	*/

    glPopMatrix();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-50.2);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-50.2);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-50.2);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-50.2);
	glEnd();
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáíÓÇÑ
	glTexCoord2d(0, 1);
	glVertex3f(-3, 0, -50);
	glTexCoord2d(1, 1);
	glVertex3f(-3, 6, -50);
	glTexCoord2d(1, 0);
	glVertex3f(-2, 6, -50);
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -50);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-50.2);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-50.2);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-50.2);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-50.2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(2, 0, -50);
	glTexCoord2d(1, 0);
	glVertex3f(2, 6, -50);
	glTexCoord2d(1, 1);
	glVertex3f(3, 6, -50);
	glTexCoord2d(0, 1);
	glVertex3f(3, 0, -50);
	glEnd();

	

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ ãÚ ÛáÇÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-50.3);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-50.3);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-50.3);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-50.3);
	glEnd();
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ ãÚ ÛáÇÝ
	glTexCoord2d(0, 0);
	glVertex3f(-2, 4, -50);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 6, -50);
	glTexCoord2d(1, 1);
	glVertex3f(2, 6, -50);
	glTexCoord2d(1, 0);
	glVertex3f(2, 4, -50);
	glEnd();

	glPushMatrix();
	glTranslated(-d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door1);
	glBegin(GL_QUADS);// ÇáÈÇÈ ÇáíÓÇÑÇáÎáÝí
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-50);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,-50);
	glTexCoord2d(1,1);
	glVertex3f(0,4,-50);
	glTexCoord2d(1,0);
	glVertex3f(0,0,-50);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glTranslated(d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä ÇáÎáÝí
	glTexCoord2d(0,0);
	glVertex3f(0,0,-50);
	glTexCoord2d(1,0);
	glVertex3f(2,0,-50);
	glTexCoord2d(1,1);
	glVertex3f(2,4,-50);
	glTexCoord2d(0,1);
	glVertex3f(0,4,-50);
	
	glEnd();
	glPopMatrix();




	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(3,0,-50);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-50);
	glTexCoord2d(0,1);
	glVertex3f(3,6,-40);
	glTexCoord2d(0,0);
	glVertex3f(3,0,-40);
	glEnd();
	glColor3f(1, 1, 1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(2.8, 0, -50);
	glTexCoord2d(1, 1);
	glVertex3f(2.8, 6, -50);
	glTexCoord2d(0, 1);
	glVertex3f(2.8, 6, -40);
	glTexCoord2d(0, 0);
	glVertex3f(2.8, 0, -40);
	glEnd();







	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-3,0,-50);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-50);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-40);
	glTexCoord2d(0,0);
	glVertex3f(-3,0,-40);
	glEnd();
	glColor3f(1,1,1);


	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí ãÚ ÛáÇÝ
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-2.8,0,-50);
	glTexCoord2d(1,1);
	glVertex3f(-2.8,6,-50);
	glTexCoord2d(0,1);
	glVertex3f(-2.8,6,-40);
	glTexCoord2d(0,0);
	glVertex3f(-2.8,0,-40);
	glEnd();
	glColor3f(1,1,1);

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,st);
	glBegin(GL_QUADS);//ÇÔÇÔÉ
	glTexCoord2d(1,0);
	glVertex3f(-2.77,0.5,-49.5);
	glTexCoord2d(1,1);
	glVertex3f(-2.77,5.5,-49.5);
	glTexCoord2d(0,1);
	glVertex3f(-2.77,5.5,-40.5);
	glTexCoord2d(0,0);
	glVertex3f(-2.77,0.5,-40.5);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,roof);
	glBegin(GL_QUADS);//ÇáÓÞÝ
	glTexCoord2d(0,0);
	glVertex3f(-3,6,-50);
	glTexCoord2d(1,0);
	glVertex3f(3,6,-50);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-40);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-40);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//ÇáÓÞÝ ãÚ ÛáÇÝ 
	glTexCoord2d(0,0);
	glVertex3f(-3,5.9,-50);
	glTexCoord2d(1,0);
	glVertex3f(3,5.9,-50);
	glTexCoord2d(1,1);
	glVertex3f(3,5.9,-40);
	glTexCoord2d(0,1);
	glVertex3f(-3,5.9,-40);
	glEnd();

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-40);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-40);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-40);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-40);
	glEnd();
	/*
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑ
	glTexCoord2d(0, 1);
	glVertex3f(-3, 0, -40.2);
	glTexCoord2d(1, 1);
	glVertex3f(-3, 6, -40.2);
	glTexCoord2d(1, 0);
	glVertex3f(-2, 6, -40.2);
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -40.2);
	glEnd();
	*/

	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-40);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-40);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-40);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-40);
	glEnd();
	/*
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(2, 0, -40.2);
	glTexCoord2d(1, 0);
	glVertex3f(2, 6, -40.2);
	glTexCoord2d(1, 1);
	glVertex3f(3, 6, -40.2);
	glTexCoord2d(0, 1);
	glVertex3f(3, 0, -40.2);
	glEnd();
	*/

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-40);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-40);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-40);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-40);
	glEnd();
	glColor3f(1, 1, 1);/*
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ
	glTexCoord2d(0, 0);
	glVertex3f(-2, 4, -40.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 6, -40.5);
	glTexCoord2d(1, 1);
	glVertex3f(2, 6, -40.5);
	glTexCoord2d(1, 0);
	glVertex3f(2, 4, -40.5);
	glEnd();
	*/
	glColor3f(0,0,0);//ÃÑÖíÉ ÇáãÞÕæÑÉ
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-3,0.01,-40);
	glTexCoord2d(0,1);
	glVertex3f(-3,0.01,-50);
	glTexCoord2d(1,1);
	glVertex3f(3,0.01,-50);
	glTexCoord2d(1,0);
	glVertex3f(3,0.01,-40);
	glEnd();






	glPushMatrix();
	glTranslated(-d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door1);
	glBegin(GL_QUADS);//ÇáÈÇÈ ÇáíÓÇÑ
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-39.8);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,-39.8);
	glTexCoord2d(1,1);
	glVertex3f(0,4,-39.8);
	glTexCoord2d(1,0);
	glVertex3f(0,0,-39.8);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glTranslated(d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(0,0,-39.8);
	glTexCoord2d(1,0);
	glVertex3f(2,0,-39.8);
	glTexCoord2d(1,1);
	glVertex3f(2,4,-39.8);
	glTexCoord2d(0,1);
	glVertex3f(0,4,-39.8);
	glEnd();
	glPopMatrix();


	glPushMatrix();
glTranslated(3,-0.4,-41);

glBegin(GL_POLYGON);//FIRST WHEEL
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(-5,0,0);//SECOND WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(0.5,0,-9);//THIRD WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(6,0,0);//FOURTH WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glPopMatrix();
	//end of third room
	//fourth room
	//glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÇæá ÇáÌÇäÈ Çáíãíä 
	
	//glTranslated(2.2,0,-4.5);
	
	
	//chair1();
	
	
	glPushMatrix();
	glTranslated(0.8,0,-5);
	chair1();
	
	glTranslated(0,0,-2);
	chair1();
	glTranslated(0,0,-2);
	chair1();
	glTranslated(0,0,-2);
	chair1();
	glTranslated(-2.5,0,0);
	chair1();
	glTranslated(0,0,2);
	chair1();
	glTranslated(0,0,2);
	chair1();
	glTranslated(0,0,2);
	chair1();

	

    glPopMatrix();
	/*
	glPushMatrix();// ßÑÇÓí ÇáÕÝ ÇáËÇäí ÇáÌÇäÈ Çáíãíä
	
	glTranslated(2.2,0,-6);
	
	
	chair1();
	
	
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();
	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáËÇáË ÇáÌÇäÈ Çáíãíä 
	
	glTranslated(2.2,0,-7.5);

	
	
	chair1();
	
	
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();
	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÑÇÈÚ ÇáÌÇäÈ Çáíãíä
	
	glTranslated(2.2,0,-9);
	
	
	chair1();
	
	
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();
	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÎÇãÓ ÇáÌÇäÈ Çáíãíä 
	
	glTranslated(2.2,0,-10.5);
	
	
	chair1();
	
	
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();
	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÓÇÏÓ ÇáÌÇäÈ Çáíãíä 
	
	glTranslated(2.2,0,-12);
	
	
	chair1();
	
	
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();

	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÇæá ÇáÌÇäÈ ÇáíÓÇÑ
	
	glTranslated(-5,0,-4.5);
	
	
	chair1();
	
	
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();

	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáËÇäí ÇáÌÇäÈ ÇáíÓÇÑ
	
	glTranslated(-5,0,-6);
	
	
	chair1();
	
	
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();

	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáËÇáË ÇáÌÇäÈ ÇáíÓÇÑ
	
	glTranslated(-5,0,-7.5);
	
	
	chair1();
	
	
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();

	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÑÇÈÚ ÇáÌÇäÈ ÇáíÓÇÑ
	
	glTranslated(-5,0,-9);
	
	
	chair1();
	
	
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();

	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÎÇãÓ ÇáÌÇäÈ ÇáíÓÇÑ
	
	glTranslated(-5,0,-10.5);
	
	
	chair1();
	
	chair1();
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();

	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÓÇÏÓ ÇáÌÇäÈ ÇáíÓÇÑ
	
	glTranslated(-5,0,-12);
	
	
	chair1();
	
	chair1();
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();
	
	
	*/

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-70.01);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-70.01);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-70.01);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-70.01);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-70.01);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-70.01);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-70.01);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-70.01);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-70.01);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-70.01);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-70.01);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-70.01);
	glEnd();


/*

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáíÓÇÑ ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,1);
	glVertex3f(-5,0,-10.005);
	glTexCoord2d(1,1);
	glVertex3f(-5,6,-10.005);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-10.005);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-10.00);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí Çáíãíä ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(2,0,-10.005);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-10.005);
	glTexCoord2d(1,1);
	glVertex3f(5,6,-10.005);
	glTexCoord2d(0,1);
	glVertex3f(5,0,-10.005);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-10.005);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-10.005);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-10.005);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-10.005);
	glEnd();
*/
	glPushMatrix();
	glTranslated(-d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door1);
	glBegin(GL_QUADS);// ÇáÈÇÈ ÇáíÓÇÑÇáÎáÝí
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-70);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,-70);
	glTexCoord2d(1,1);
	glVertex3f(0,4,-70);
	glTexCoord2d(1,0);
	glVertex3f(0,0,-70);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glTranslated(d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä ÇáÎáÝí
	glTexCoord2d(0,0);
	glVertex3f(0,0,-70);
	glTexCoord2d(1,0);
	glVertex3f(2,0,-70);
	glTexCoord2d(1,1);
	glVertex3f(2,4,-70);
	glTexCoord2d(0,1);
	glVertex3f(0,4,-70);
	
	glEnd();
	glPopMatrix();




	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(3,0,-70);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-70);
	glTexCoord2d(0,1);
	glVertex3f(3,6,-60);
	glTexCoord2d(0,0);
	glVertex3f(3,0,-60);
	glEnd();
/*
	glColor3f(1,1,1);// ÇáÍíØ ÇáÌÇäÈí Çáíãíä æÔ ÏÇÎáí
	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(4.99,0,-10);
	glTexCoord2d(1,1);
	glVertex3f(4.99,6,-10);
	glTexCoord2d(0,1);
	glVertex3f(4.99,6,0);
	glTexCoord2d(0,0);
	glVertex3f(4.99,0,0);
	glEnd();



*/

	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-3,0,-70);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-70);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-60);
	glTexCoord2d(0,0);
	glVertex3f(-3,0,-60);
	glEnd();
	glColor3f(1,1,1);
/*
	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí æÔ ÏÇÎáí
	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-4.99,0,-10);
	glTexCoord2d(1,1);
	glVertex3f(-4.99,6,-10);
	glTexCoord2d(0,1);
	glVertex3f(-4.99,6,0);
	glTexCoord2d(0,0);
	glVertex3f(-4.99,0,0);
	glEnd();
	glColor3f(1,1,1);
*/


	glBindTexture(GL_TEXTURE_2D,roof);
	glBegin(GL_QUADS);//ÇáÓÞÝ
	glTexCoord2d(0,0);
	glVertex3f(-3,6,-70);
	glTexCoord2d(1,0);
	glVertex3f(3,6,-70);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-60);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-60);
	glEnd();
/*
	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);// ÇáÓÞÝ æÔ ÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(-5,5.99,-10);
	glTexCoord2d(1,0);
	glVertex3f(5,5.99,-10);
	glTexCoord2d(1,1);
	glVertex3f(5,5.99,0);
	glTexCoord2d(0,1);
	glVertex3f(-5,5.99,0);
	glEnd();
*/
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-60);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-60);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-60);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-60);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-60);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-60);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-60);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-60);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-60);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-60);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-60);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-60);
	glEnd();

/*

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,1);
	glVertex3f(-5,0,-0.005);
	glTexCoord2d(1,1);
	glVertex3f(-5,6,-0.005);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-0.005);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-0.005);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(2,0,-0.005);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-0.005);
	glTexCoord2d(1,1);
	glVertex3f(5,6,-0.005);
	glTexCoord2d(0,1);
	glVertex3f(5,0,-0.005);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-0.005);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-0.005);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-0.005);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-0.005);
	glEnd();

*/
	glColor3f(1,1,1);//ÃÑÖíÉ ÇáãÞÕæÑÉ
	glBindTexture(GL_TEXTURE_2D,redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-3,0.01,-60);
	glTexCoord2d(0,1);
	glVertex3f(-3,0.01,-70);
	glTexCoord2d(1,1);
	glVertex3f(3,0.01,-70);
	glTexCoord2d(1,0);
	glVertex3f(3,0.01,-60);
	glEnd();


	
	glPushMatrix();
	glTranslated(-d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door1);
	glBegin(GL_QUADS);//ÇáÈÇÈ ÇáíÓÇÑ
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-59.9);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,-59.9);
	glTexCoord2d(1,1);
	glVertex3f(0,4,-59.9);
	glTexCoord2d(1,0);
	glVertex3f(0,0,-59.9);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glTranslated(d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(0,0,-59.9);
	glTexCoord2d(1,0);
	glVertex3f(2,0,-59.9);
	glTexCoord2d(1,1);
	glVertex3f(2,4,-59.9);
	glTexCoord2d(0,1);
	glVertex3f(0,4,-59.9);
	glEnd();
	glPopMatrix();

glPushMatrix();
glTranslated(3,-0.4,-61);

glBegin(GL_POLYGON);//FIRST WHEEL
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(-5,0,0);//SECOND WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(0.5,0,-9);//THIRD WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(6,0,0);//FOURTH WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glPopMatrix();
	
	//fifth room dining room
	
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-90.01);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-90.01);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-90.01);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-90.01);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-90.01);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-90.01);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-90.01);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-90.01);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-90.01);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-90.01);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-90.01);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-90.01);
	glEnd();




	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáíÓÇÑ ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-89.9);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-89.9);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-89.9);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-89.9);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí Çáíãíä ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(2,0,-89.9);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-89.9);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-89.9);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-89.9);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-89.9);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-89.9);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-89.9);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-89.9);
	glEnd();

	glPushMatrix();
	glTranslated(-d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door1);
	glBegin(GL_QUADS);// ÇáÈÇÈ ÇáíÓÇÑÇáÎáÝí
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-89.8);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,-89.8);
	glTexCoord2d(1,1);
	glVertex3f(0,4,-89.8);
	glTexCoord2d(1,0);
	glVertex3f(0,0,-89.8);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glTranslated(d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä ÇáÎáÝí
	glTexCoord2d(0,0);
	glVertex3f(0,0,-89.8);
	glTexCoord2d(1,0);
	glVertex3f(2,0,-89.8);
	glTexCoord2d(1,1);
	glVertex3f(2,4,-89.8);
	glTexCoord2d(0,1);
	glVertex3f(0,4,-89.8);
	
	glEnd();
	glPopMatrix();




	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(3,0,-90);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-90);
	glTexCoord2d(0,1);
	glVertex3f(3,6,-80);
	glTexCoord2d(0,0);
	glVertex3f(3,0,-80);
	glEnd();
	
	glColor3f(1,1,1);// ÇáÍíØ ÇáÌÇäÈí Çáíãíä æÔ ÏÇÎáí
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(2.9,0,-90);
	glTexCoord2d(1,1);
	glVertex3f(2.9,6,-90);
	glTexCoord2d(0,1);
	glVertex3f(2.9,6,-80);
	glTexCoord2d(0,0);
	glVertex3f(2.9,0,-80);
	glEnd();

	



	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-3,0,-90);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-90);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-80);
	glTexCoord2d(0,0);
	glVertex3f(-3,0,-80);
	glEnd();
	glColor3f(1,1,1);

	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí æÔ ÏÇÎáí
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-2.9,0,-90);
	glTexCoord2d(1,1);
	glVertex3f(-2.9,6,-90);
	glTexCoord2d(0,1);
	glVertex3f(-2.9,6,-80);
	glTexCoord2d(0,0);
	glVertex3f(-2.9,0,-80);
	glEnd();
	glColor3f(1,1,1);



	glBindTexture(GL_TEXTURE_2D,roof);
	glBegin(GL_QUADS);//ÇáÓÞÝ
	glTexCoord2d(0,0);
	glVertex3f(-3,6,-90);
	glTexCoord2d(1,0);
	glVertex3f(3,6,-90);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-80);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-80);
	glEnd();

	
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-80);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-80);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-80);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-80);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-80);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-80);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-80);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-80);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-80);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-80);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-80);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-80);
	glEnd();


	/*
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-80.1);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-80.1);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-80.1);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-80.1);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(2,0,-80.1);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-80.1);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-80.1);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-80.1);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-80.1);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-80.1);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-80.1);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-80.1);
	glEnd();

	*/
	glColor3f(1,1,1);//ÃÑÖíÉ ÇáãÞÕæÑÉ
	glBindTexture(GL_TEXTURE_2D,blue);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-3,0.01,-80);
	glTexCoord2d(0,1);
	glVertex3f(-3,0.01,-90);
	glTexCoord2d(1,1);
	glVertex3f(3,0.01,-90);
	glTexCoord2d(1,0);
	glVertex3f(3,0.01,-80);
	glEnd();

	//the begining of the stuff
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-2.9, 0.1, -87);
	glTexCoord2d(1, 0);
	glVertex3f(-2.9, 0.1, -84);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 0.1, -84);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 0.1, -87);
	glEnd();
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-2.9, 1, -87);
	glTexCoord2d(1, 0);
	glVertex3f(-2.9, 1, -84);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -84);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -87);
	glEnd();
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1, 0.1, -87);
	glTexCoord2d(1, 0);
	glVertex3f(-1, 0.1, -84);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -84);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -87);
	glEnd();
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1, 0.1, -84);
	glTexCoord2d(1, 0);
	glVertex3f(-2.9, 0.1, -84);
	glTexCoord2d(1, 1);
	glVertex3f(-2.9, 1, -84);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -84);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);//chair
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -83.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 0.5, -82.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 0.5, -82.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -83.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -83.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 0.5, -82.5);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.1, -82.5);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 0.1, -83.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.1, -82.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -82.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -82.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.1, -82.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -82.8);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -82.8);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -82.8);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -82.8);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -82.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -82.8);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -82.8);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 1.5, -82.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -82.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -82.8);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.5, -82.8);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 0.5, -82.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);//second chair
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -88.2);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -88.5);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.5, -88.5);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 0.5, -88.2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);//chair
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -88.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 0.5, -87.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 0.5, -87.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -88.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -88.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 0.5, -87.5);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.1, -87.5);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 0.1, -88.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.1, -88.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -88.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -88.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.1, -88.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -88.2);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -88.2);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -88.2);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -88.2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -88.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -88.2);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -88.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 1.5, -88.2);
	glEnd();
	glPushMatrix();
	glTranslated(4, 0, 0);
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-2.9, 0.1, -87);
	glTexCoord2d(1, 0);
	glVertex3f(-2.9, 0.1, -84);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 0.1, -84);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 0.1, -87);
	glEnd();
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-2.9, 1, -87);
	glTexCoord2d(1, 0);
	glVertex3f(-2.9, 1, -84);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -84);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -87);
	glEnd();
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-2.9, 0.1, -87);
	glTexCoord2d(1, 0);
	glVertex3f(-2.9, 0.1, -84);
	glTexCoord2d(1, 1);
	glVertex3f(-2.9, 1, -84);
	glTexCoord2d(0, 1);
	glVertex3f(-2.9, 1, -87);
	glEnd();
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1, 0.1, -84);
	glTexCoord2d(1, 0);
	glVertex3f(-2.9, 0.1, -84);
	glTexCoord2d(1, 1);
	glVertex3f(-2.9, 1, -84);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -84);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);//chair
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -83.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 0.5, -82.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 0.5, -82.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -83.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-2.7, 0.5, -83.5);
	glTexCoord2d(1, 0);
	glVertex3f(-2.7, 0.5, -82.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 0.1, -82.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.1, -83.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.1, -82.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -82.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -82.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.1, -82.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -82.8);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -82.8);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -82.8);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -82.8);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -82.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -82.8);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -82.8);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 1.5, -82.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -82.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -82.8);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.5, -82.8);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 0.5, -82.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);//second chair
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -88.2);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -88.5);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.5, -88.5);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 0.5, -88.2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);//chair
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -88.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 0.5, -87.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 0.5, -87.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -88.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -88.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 0.5, -87.5);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.1, -87.5);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 0.1, -88.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.1, -88.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -88.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -88.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.1, -88.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -88.2);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -88.2);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -88.2);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -88.2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -88.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -88.2);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -88.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 1.5, -88.2);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(3, -0.4, -81);
	glBegin(GL_POLYGON);//FIRST WHEEL
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(-5, 0, 0);//SECOND WHEEL
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(0.5, 0, -9);//THIRD WHEEL
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(6, 0, 0);//FOURTH WHEEL
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-d, 0, 0);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, door1);
	glBegin(GL_QUADS);//ÇáÈÇÈ ÇáíÓÇÑ
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -79.9);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 4, -79.9);
	glTexCoord2d(1, 1);
	glVertex3f(0, 4, -79.9);
	glTexCoord2d(1, 0);
	glVertex3f(0, 0, -79.9);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glTranslated(d, 0, 0);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(0, 0, -79.9);
	glTexCoord2d(1, 0);
	glVertex3f(2, 0, -79.9);
	glTexCoord2d(1, 1);
	glVertex3f(2, 4, -79.9);
	glTexCoord2d(0, 1);
	glVertex3f(0, 4, -79.9);
	glEnd();
	glPopMatrix();
	//end of fifth room
	//sixth room
	glBindTexture(GL_TEXTURE_2D, redcarpet);


	glBegin(GL_QUADS); //bed
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 1, -109);
	glTexCoord2d(1, 0);
	glVertex3f(-1, 1, -109);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -104);
	glTexCoord2d(0, 1);
	glVertex3f(-3, 1, -104);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 0.1, -104);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 1, -104);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -104);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 0.1, -104);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1, 0.1, -109);
	glTexCoord2d(1, 0);
	glVertex3f(-1, 1, -109);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -104);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 0.1, -104);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 1, -109);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 1.5, -109);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1.5, -109);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -109);
	glEnd();
	/*
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-4.9, 1, -29);
	glTexCoord2d(1, 0);
	glVertex3f(-4.9, 1.5, -29);
	glTexCoord2d(1, 1);
	glVertex3f(-4.9, 1.5, -24);
	glTexCoord2d(0, 1);
	glVertex3f(-4.9, 1, -24);
	glEnd();*/
	glBindTexture(GL_TEXTURE_2D, brick);//wordrobe
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(1.8, 0.1, -108);
	glTexCoord2d(1, 0);
	glVertex3f(1.8, 3, -108);
	glTexCoord2d(1, 1);
	glVertex3f(2.8, 3, -108);
	glTexCoord2d(0, 1);
	glVertex3f(2.8, 0.1, -108);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,wood);//wordrobe
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(1.8, 0.1, -108);
	glTexCoord2d(1, 0);
	glVertex3f(1.8, 3, -108);
	glTexCoord2d(1, 1);
	glVertex3f(1.8, 3, -109);
	glTexCoord2d(0, 1);
	glVertex3f(1.8, 0.1, -109);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);//wordrobe
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(1.9, 1.5, -108);
	glTexCoord2d(1, 0);
	glVertex3f(1.9, 1.6, -108);
	glTexCoord2d(1, 1);
	glVertex3f(2.1, 1.6, -108);
	glTexCoord2d(0, 1);
	glVertex3f(2.1, 1.5, -108);
	glEnd();
	



	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3f(-1, 0.6, -109);
	glTexCoord2d(1, 0);
	glVertex3f(-1, 1, -109);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -104);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 0.6, -104);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 0.6, -104);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 1, -104);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -104);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 0.6, -104);
	glEnd();


	/*
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,painting);
	glBegin(GL_QUADS);//ÇááæÍÉ ÇáÏÇÎíáíÉ
	glTexCoord2d(0,0);
	glVertex3f(-4.5,2,-29.9);
	glTexCoord2d(1,0);
	glVertex3f(-3,2,-29.9);
	glTexCoord2d(1,1);
	glVertex3f(-3,3,-29.9);
	glTexCoord2d(0,1);
	glVertex3f(-4.5,3,-29.9);
	glEnd();
	*/






	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(3,0,-110);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-110);
	glTexCoord2d(0,1);
	glVertex3f(3,6,-100);
	glTexCoord2d(0,0);
	glVertex3f(3,0,-100);
	glEnd();



	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-3,0,-110);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-110);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-100);
	glTexCoord2d(0,0);
	glVertex3f(-3,0,-100);
	glEnd();
	glColor3f(1,1,1);


	glBindTexture(GL_TEXTURE_2D,roof);
	glBegin(GL_QUADS);//ÇáÓÞÝ
	glTexCoord2d(0,0);
	glVertex3f(-3,6,-110);
	glTexCoord2d(1,0);
	glVertex3f(3,6,-110);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-100);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-100);
	glEnd();

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-100);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-100);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-100);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-100);
	glEnd();
	glColor3f(1, 1, 1);
 glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);
	glVertex3f(-3, 0, -110);
	glTexCoord2d(1, 1);
	glVertex3f(-3, 6, -110);
	glTexCoord2d(1, 0);
	glVertex3f(-2, 6, -110);
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0,-110);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-100);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-100);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-100);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-100);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(2, 0, -110);
	glTexCoord2d(1, 0);
	glVertex3f(2, 6, -110);
	glTexCoord2d(1, 1);
	glVertex3f(3, 6, -110);
	glTexCoord2d(0, 1);
	glVertex3f(3, 0, -110);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-100);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-100);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-100);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-100);
	glEnd();

	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ
	glTexCoord2d(0, 0);
	glVertex3f(-2, 4, -110);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 6, -110);
	glTexCoord2d(1, 1);
	glVertex3f(2, 6, -110);
	glTexCoord2d(1, 0);
	glVertex3f(2, 4, -110);
	glEnd();


	glColor3f(1,1,1);//ÃÑÖíÉ ÇáãÞÕæÑÉ
	glBindTexture(GL_TEXTURE_2D,blue);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-3,0.01,-100);
	glTexCoord2d(0,1);
	glVertex3f(-3,0.01,-109.8);
	glTexCoord2d(1,1);
	glVertex3f(3,0.01,-109.8);
	glTexCoord2d(1,0);
	glVertex3f(3,0.01,-100);
	glEnd();


	/*glColor3f(1,1,1);//Back Sky Box
	glBindTexture(GL_TEXTURE_2D,back);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-10,0,-30.1);
	glTexCoord2d(1,0);
	glVertex3f(10,0,-30.1);
	glTexCoord2d(1,1);
	glVertex3f(10,10,-30.1);
	glTexCoord2d(0,1);
	glVertex3f(-10,10,-30.1);
	glEnd();*/
glPushMatrix();
	glTranslated(-d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door1);
	glBegin(GL_QUADS);//ÇáÈÇÈ ÇáíÓÇÑ
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-99.8);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,-99.8);
	glTexCoord2d(1,1);
	glVertex3f(0,4,-99.8);
	glTexCoord2d(1,0);
	glVertex3f(0,0,-99.8);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-d, 0, 0);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, door1);
	glBegin(GL_QUADS);//ÇáÈÇÈ ÇáíÓÇÑ
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -109.8);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 4, -109.8);
	glTexCoord2d(1, 1);
	glVertex3f(0, 4,-109.8);
	glTexCoord2d(1, 0);
	glVertex3f(0, 0,-109.8);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslated(d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(0,0,-99.8);
	glTexCoord2d(1,0);
	glVertex3f(2,0,-99.8);
	glTexCoord2d(1,1);
	glVertex3f(2,4,-99.8);
	glTexCoord2d(0,1);
	glVertex3f(0,4,-99.8);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(d, 0, 0);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(0, 0, -109.8);
	glTexCoord2d(1, 0);
	glVertex3f(2, 0, -109.8);
	glTexCoord2d(1, 1);
	glVertex3f(2, 4, -109.8);
	glTexCoord2d(0, 1);
	glVertex3f(0, 4, -109.8);
	glEnd();
	glPopMatrix();
	glPushMatrix();
glTranslated(3,-0.4,-101);

glBegin(GL_POLYGON);//FIRST WHEEL
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(-5,0,0);//SECOND WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(0.5,0,-9);//THIRD WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(6,0,0);//FOURTH WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glPopMatrix();
	//the end of the sixth room
	//seventh room
	glPushMatrix();
	glTranslated(0.8,0,-65);
	chair1();
	
	glTranslated(0,0,-2);
	chair1();
	glTranslated(0,0,-2);
	chair1();
	glTranslated(0,0,-2);
	chair1();
	glTranslated(-2.5,0,0);
	chair1();
	glTranslated(0,0,2);
	chair1();
	glTranslated(0,0,2);
	chair1();
	glTranslated(0,0,2);
	chair1();

	

    glPopMatrix();
	/*
	glPushMatrix();// ßÑÇÓí ÇáÕÝ ÇáËÇäí ÇáÌÇäÈ Çáíãíä
	
	glTranslated(2.2,0,-6);
	
	
	chair1();
	
	
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();
	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáËÇáË ÇáÌÇäÈ Çáíãíä 
	
	glTranslated(2.2,0,-7.5);

	
	
	chair1();
	
	
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();
	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÑÇÈÚ ÇáÌÇäÈ Çáíãíä
	
	glTranslated(2.2,0,-9);
	
	
	chair1();
	
	
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();
	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÎÇãÓ ÇáÌÇäÈ Çáíãíä 
	
	glTranslated(2.2,0,-10.5);
	
	
	chair1();
	
	
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();
	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÓÇÏÓ ÇáÌÇäÈ Çáíãíä 
	
	glTranslated(2.2,0,-12);
	
	
	chair1();
	
	
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair1();
	glPopMatrix();

    glPopMatrix();

	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÇæá ÇáÌÇäÈ ÇáíÓÇÑ
	
	glTranslated(-5,0,-4.5);
	
	
	glPopMatrix();

    glPopMatrix();

	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáËÇáË ÇáÌÇäÈ ÇáíÓÇÑ
	
	glTranslated(-5,0,-7.5);
	
	
	
	
	*/

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-130.01);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-130.01);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-130.01);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-130.01);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-130.01);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-130.01);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-130.01);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-130.01);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-130.01);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-130.01);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-130.01);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-130.01);
	glEnd();


/*

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáíÓÇÑ ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,1);
	glVertex3f(-5,0,-10.005);
	glTexCoord2d(1,1);
	glVertex3f(-5,6,-10.005);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-10.005);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-10.00);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí Çáíãíä ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(2,0,-10.005);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-10.005);
	glTexCoord2d(1,1);
	glVertex3f(5,6,-10.005);
	glTexCoord2d(0,1);
	glVertex3f(5,0,-10.005);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-10.005);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-10.005);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-10.005);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-10.005);
	glEnd();
*/
	glPushMatrix();
	glTranslated(-d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door1);
	glBegin(GL_QUADS);// ÇáÈÇÈ ÇáíÓÇÑÇáÎáÝí
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-130);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,-130);
	glTexCoord2d(1,1);
	glVertex3f(0,4,-130);
	glTexCoord2d(1,0);
	glVertex3f(0,0,-130);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glTranslated(d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä ÇáÎáÝí
	glTexCoord2d(0,0);
	glVertex3f(0,0,-130);
	glTexCoord2d(1,0);
	glVertex3f(2,0,-130);
	glTexCoord2d(1,1);
	glVertex3f(2,4,-130);
	glTexCoord2d(0,1);
	glVertex3f(0,4,-130);
	
	glEnd();
	glPopMatrix();




	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(3,0,-130);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-130);
	glTexCoord2d(0,1);
	glVertex3f(3,6,-120);
	glTexCoord2d(0,0);
	glVertex3f(3,0,-120);
	glEnd();
/*
	glColor3f(1,1,1);// ÇáÍíØ ÇáÌÇäÈí Çáíãíä æÔ ÏÇÎáí
	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(4.99,0,-10);
	glTexCoord2d(1,1);
	glVertex3f(4.99,6,-10);
	glTexCoord2d(0,1);
	glVertex3f(4.99,6,0);
	glTexCoord2d(0,0);
	glVertex3f(4.99,0,0);
	glEnd();



*/

	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-3,0,-130);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-130);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-120);
	glTexCoord2d(0,0);
	glVertex3f(-3,0,-120);
	glEnd();
	glColor3f(1,1,1);
/*
	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí æÔ ÏÇÎáí
	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-4.99,0,-10);
	glTexCoord2d(1,1);
	glVertex3f(-4.99,6,-10);
	glTexCoord2d(0,1);
	glVertex3f(-4.99,6,0);
	glTexCoord2d(0,0);
	glVertex3f(-4.99,0,0);
	glEnd();
	glColor3f(1,1,1);
*/


	glBindTexture(GL_TEXTURE_2D,roof);
	glBegin(GL_QUADS);//ÇáÓÞÝ
	glTexCoord2d(0,0);
	glVertex3f(-3,6,-130);
	glTexCoord2d(1,0);
	glVertex3f(3,6,-130);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-120);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-120);
	glEnd();
/*
	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);// ÇáÓÞÝ æÔ ÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(-5,5.99,-10);
	glTexCoord2d(1,0);
	glVertex3f(5,5.99,-10);
	glTexCoord2d(1,1);
	glVertex3f(5,5.99,0);
	glTexCoord2d(0,1);
	glVertex3f(-5,5.99,0);
	glEnd();
*/
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-120);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-120);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-120);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-120);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-120);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-120);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-120);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-120);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-120);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-120);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-120);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-120);
	glEnd();

/*

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,1);
	glVertex3f(-5,0,-0.005);
	glTexCoord2d(1,1);
	glVertex3f(-5,6,-0.005);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-0.005);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-0.005);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(2,0,-0.005);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-0.005);
	glTexCoord2d(1,1);
	glVertex3f(5,6,-0.005);
	glTexCoord2d(0,1);
	glVertex3f(5,0,-0.005);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,st9);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-0.005);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-0.005);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-0.005);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-0.005);
	glEnd();

*/
	glColor3f(1,1,1);//ÃÑÖíÉ ÇáãÞÕæÑÉ
	glBindTexture(GL_TEXTURE_2D,redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-3,0.01,-120);
	glTexCoord2d(0,1);
	glVertex3f(-3,0.01,-130);
	glTexCoord2d(1,1);
	glVertex3f(3,0.01,-130);
	glTexCoord2d(1,0);
	glVertex3f(3,0.01,-120);
	glEnd();


	
	glPushMatrix();
	glTranslated(-d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door1);
	glBegin(GL_QUADS);//ÇáÈÇÈ ÇáíÓÇÑ
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-119.9);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,-119.9);
	glTexCoord2d(1,1);
	glVertex3f(0,4,-119.9);
	glTexCoord2d(1,0);
	glVertex3f(0,0,-119.9);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glTranslated(d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(0,0,-119.9);
	glTexCoord2d(1,0);
	glVertex3f(2,0,-119.9);
	glTexCoord2d(1,1);
	glVertex3f(2,4,-119.9);
	glTexCoord2d(0,1);
	glVertex3f(0,4,-119.9);
	glEnd();
	glPopMatrix();

glPushMatrix();
glTranslated(3,-0.4,-121);

glBegin(GL_POLYGON);//FIRST WHEEL
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(-5,0,0);//SECOND WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(0.5,0,-9);//THIRD WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(6,0,0);//FOURTH WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glPopMatrix();
	// the end of the seventh room
	//eighth room
	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÇæá
	glTranslated(1,0,-104.5);
	chair();
	glTranslated(0,0,-1.2);
	chair();
	glTranslated(0,0,-1.2);
	chair();
	glTranslated(0,0,-1.2);
	chair();
	glTranslated(0,0,-1.2);
	chair();
	glTranslated(0,0,-1.2);
	chair();
	/*
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair();
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,0,-1);
	chair();
	glPopMatrix();
	
    glPopMatrix();
	
	glPushMatrix();
	glTranslated(0,0,-1);
	chair();
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,0,-1);
	*/
	/*
	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáËÇäí
	glTranslated(2,0,-6);
	chair();
	
	chair();
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair();
	glPopMatrix();

    glPopMatrix();

	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáËÇáË
	glTranslated(2,0,-7.5);
	chair();
	
	chair();
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair();
	glPopMatrix();

    glPopMatrix();
    

	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÑÇÈÚ
	glTranslated(2,0,-9);
	chair();
	
	chair();
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair();
	glPopMatrix();

    glPopMatrix();

	glPushMatrix();//ßÑÇÓí ÇáÕÝ ÇáÎÇãÓ
	glTranslated(2,0,-10.5);
	chair();
	
	chair();
	glPushMatrix();
	glTranslated(1.5,0,0);
	chair();
	glPopMatrix();

    glPopMatrix();

	glPushMatrix();
	glTranslated(2,0,-12);
	chair();
	
	chair();
	glPushMatrix();
	
	glTranslated(1.5,0,0);
	chair();
	glPopMatrix();
	*/

    glPopMatrix();
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-150.2);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-150.2);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-150.2);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-150.2);
	glEnd();
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáíÓÇÑ
	glTexCoord2d(0, 1);
	glVertex3f(-3, 0, -150);
	glTexCoord2d(1, 1);
	glVertex3f(-3, 6, -150);
	glTexCoord2d(1, 0);
	glVertex3f(-2, 6, -150);
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -150);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-150.2);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-150.2);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-150.2);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-150.2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(2, 0, -150);
	glTexCoord2d(1, 0);
	glVertex3f(2, 6, -150);
	glTexCoord2d(1, 1);
	glVertex3f(3, 6, -150);
	glTexCoord2d(0, 1);
	glVertex3f(3, 0, -150);
	glEnd();

	

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ ãÚ ÛáÇÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-150.3);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-150.3);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-150.3);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-150.3);
	glEnd();
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ ãÚ ÛáÇÝ
	glTexCoord2d(0, 0);
	glVertex3f(-2, 4, -150);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 6, -150);
	glTexCoord2d(1, 1);
	glVertex3f(2, 6, -150);
	glTexCoord2d(1, 0);
	glVertex3f(2, 4, -150);
	glEnd();

	glPushMatrix();
	glTranslated(-d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door1);
	glBegin(GL_QUADS);// ÇáÈÇÈ ÇáíÓÇÑÇáÎáÝí
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-150);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,-150);
	glTexCoord2d(1,1);
	glVertex3f(0,4,-150);
	glTexCoord2d(1,0);
	glVertex3f(0,0,-150);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glTranslated(d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä ÇáÎáÝí
	glTexCoord2d(0,0);
	glVertex3f(0,0,-150);
	glTexCoord2d(1,0);
	glVertex3f(2,0,-150);
	glTexCoord2d(1,1);
	glVertex3f(2,4,-150);
	glTexCoord2d(0,1);
	glVertex3f(0,4,-150);
	
	glEnd();
	glPopMatrix();




	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(3,0,-150);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-150);
	glTexCoord2d(0,1);
	glVertex3f(3,6,-140);
	glTexCoord2d(0,0);
	glVertex3f(3,0,-140);
	glEnd();
	glColor3f(1, 1, 1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(2.8, 0, -150);
	glTexCoord2d(1, 1);
	glVertex3f(2.8, 6, -150);
	glTexCoord2d(0, 1);
	glVertex3f(2.8, 6, -140);
	glTexCoord2d(0, 0);
	glVertex3f(2.8, 0, -140);
	glEnd();







	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-3,0,-150);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-150);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-140);
	glTexCoord2d(0,0);
	glVertex3f(-3,0,-140);
	glEnd();
	glColor3f(1,1,1);


	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí ãÚ ÛáÇÝ
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-2.8,0,-150);
	glTexCoord2d(1,1);
	glVertex3f(-2.8,6,-150);
	glTexCoord2d(0,1);
	glVertex3f(-2.8,6,-140);
	glTexCoord2d(0,0);
	glVertex3f(-2.8,0,-140);
	glEnd();
	glColor3f(1,1,1);

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,st);
	glBegin(GL_QUADS);//ÇÔÇÔÉ
	glTexCoord2d(1,0);
	glVertex3f(-2.77,0.5,-149.5);
	glTexCoord2d(1,1);
	glVertex3f(-2.77,5.5,-149.5);
	glTexCoord2d(0,1);
	glVertex3f(-2.77,5.5,-140.5);
	glTexCoord2d(0,0);
	glVertex3f(-2.77,0.5,-140.5);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,roof);
	glBegin(GL_QUADS);//ÇáÓÞÝ
	glTexCoord2d(0,0);
	glVertex3f(-3,6,-150);
	glTexCoord2d(1,0);
	glVertex3f(3,6,-150);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-140);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-140);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//ÇáÓÞÝ ãÚ ÛáÇÝ 
	glTexCoord2d(0,0);
	glVertex3f(-3,5.9,-150);
	glTexCoord2d(1,0);
	glVertex3f(3,5.9,-150);
	glTexCoord2d(1,1);
	glVertex3f(3,5.9,-140);
	glTexCoord2d(0,1);
	glVertex3f(-3,5.9,-140);
	glEnd();

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-140);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-140);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-140);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-140);
	glEnd();
	/*
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑ
	glTexCoord2d(0, 1);
	glVertex3f(-3, 0, -40.2);
	glTexCoord2d(1, 1);
	glVertex3f(-3, 6, -40.2);
	glTexCoord2d(1, 0);
	glVertex3f(-2, 6, -40.2);
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -40.2);
	glEnd();
	*/

	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-140);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-140);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-140);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-140);
	glEnd();
	/*
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(2, 0, -40.2);
	glTexCoord2d(1, 0);
	glVertex3f(2, 6, -40.2);
	glTexCoord2d(1, 1);
	glVertex3f(3, 6, -40.2);
	glTexCoord2d(0, 1);
	glVertex3f(3, 0, -40.2);
	glEnd();
	*/

	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-140);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-140);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-140);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-140);
	glEnd();
	glColor3f(1, 1, 1);/*
	glBindTexture(GL_TEXTURE_2D, brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ
	glTexCoord2d(0, 0);
	glVertex3f(-2, 4, -40.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 6, -40.5);
	glTexCoord2d(1, 1);
	glVertex3f(2, 6, -40.5);
	glTexCoord2d(1, 0);
	glVertex3f(2, 4, -140.5);
	glEnd();
	*/
	glColor3f(0,0,0);//ÃÑÖíÉ ÇáãÞÕæÑÉ
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-3,0.01,-140);
	glTexCoord2d(0,1);
	glVertex3f(-3,0.01,-150);
	glTexCoord2d(1,1);
	glVertex3f(3,0.01,-150);
	glTexCoord2d(1,0);
	glVertex3f(3,0.01,-140);
	glEnd();






	glPushMatrix();
	glTranslated(-d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door1);
	glBegin(GL_QUADS);//ÇáÈÇÈ ÇáíÓÇÑ
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-139.8);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,-139.8);
	glTexCoord2d(1,1);
	glVertex3f(0,4,-139.8);
	glTexCoord2d(1,0);
	glVertex3f(0,0,-139.8);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glTranslated(d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(0,0,-139.8);
	glTexCoord2d(1,0);
	glVertex3f(2,0,-139.8);
	glTexCoord2d(1,1);
	glVertex3f(2,4,-139.8);
	glTexCoord2d(0,1);
	glVertex3f(0,4,-139.8);
	glEnd();
	glPopMatrix();


	glPushMatrix();
glTranslated(3,-0.4,-141);

glBegin(GL_POLYGON);//FIRST WHEEL
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(-5,0,0);//SECOND WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(0.5,0,-9);//THIRD WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(6,0,0);//FOURTH WHEEL
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5,0,0);
glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();	

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glPopMatrix();
	//the end of the eighth room
	//ninth room
	
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-170.01);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-170.01);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-170.01);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-170.01);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-170.01);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-170.01);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-170.01);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-170.01);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-170.01);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-170.01);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-170.01);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-170.01);
	glEnd();




	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáíÓÇÑ ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-169.9);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-169.9);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-169.9);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-169.9);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí Çáíãíä ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(2,0,-169.9);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-169.9);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-169.9);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-169.9);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-169.9);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-169.9);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-169.9);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-169.9);
	glEnd();

	glPushMatrix();
	glTranslated(-d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door1);
	glBegin(GL_QUADS);// ÇáÈÇÈ ÇáíÓÇÑÇáÎáÝí
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-169.8);
	glTexCoord2d(0,1);
	glVertex3f(-2,4,-169.8);
	glTexCoord2d(1,1);
	glVertex3f(0,4,-169.8);
	glTexCoord2d(1,0);
	glVertex3f(0,0,-169.8);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glTranslated(d,0,0);
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä ÇáÎáÝí
	glTexCoord2d(0,0);
	glVertex3f(0,0,-169.8);
	glTexCoord2d(1,0);
	glVertex3f(2,0,-169.8);
	glTexCoord2d(1,1);
	glVertex3f(2,4,-169.8);
	glTexCoord2d(0,1);
	glVertex3f(0,4,-169.8);
	
	glEnd();
	glPopMatrix();




	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(3,0,-170);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-170);
	glTexCoord2d(0,1);
	glVertex3f(3,6,-160);
	glTexCoord2d(0,0);
	glVertex3f(3,0,-160);
	glEnd();
	
	glColor3f(1,1,1);// ÇáÍíØ ÇáÌÇäÈí Çáíãíä æÔ ÏÇÎáí
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(2.9,0,-170);
	glTexCoord2d(1,1);
	glVertex3f(2.9,6,-170);
	glTexCoord2d(0,1);
	glVertex3f(2.9,6,-160);
	glTexCoord2d(0,0);
	glVertex3f(2.9,0,-160);
	glEnd();

	



	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí
	glBindTexture(GL_TEXTURE_2D,wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-3,0,-170);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-170);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-160);
	glTexCoord2d(0,0);
	glVertex3f(-3,0,-160);
	glEnd();
	glColor3f(1,1,1);

	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí æÔ ÏÇÎáí
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(-2.9,0,-170);
	glTexCoord2d(1,1);
	glVertex3f(-2.9,6,-170);
	glTexCoord2d(0,1);
	glVertex3f(-2.9,6,-160);
	glTexCoord2d(0,0);
	glVertex3f(-2.9,0,-160);
	glEnd();
	glColor3f(1,1,1);



	glBindTexture(GL_TEXTURE_2D,roof);
	glBegin(GL_QUADS);//ÇáÓÞÝ
	glTexCoord2d(0,0);
	glVertex3f(-3,6,-170);
	glTexCoord2d(1,0);
	glVertex3f(3,6,-170);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-160);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-160);
	glEnd();

	
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-160);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-160);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-160);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-160);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-160);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-160);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-160);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-160);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-160);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-160);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-160);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-160);
	glEnd();


	/*
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-80.1);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-80.1);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-80.1);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-80.1);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(2,0,-80.1);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-80.1);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-80.1);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-80.1);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ ÇáæÔ ÇáÏÇÎáí
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-80.1);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-80.1);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-80.1);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-80.1);
	glEnd();

	*/
	glColor3f(1,1,1);//ÃÑÖíÉ ÇáãÞÕæÑÉ
	glBindTexture(GL_TEXTURE_2D,blue);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-3,0.01,-160);
	glTexCoord2d(0,1);
	glVertex3f(-3,0.01,-170);
	glTexCoord2d(1,1);
	glVertex3f(3,0.01,-170);
	glTexCoord2d(1,0);
	glVertex3f(3,0.01,-160);
	glEnd();

	//the begining of the stuff
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-2.9, 0.1, -167);
	glTexCoord2d(1, 0);
	glVertex3f(-2.9, 0.1, -164);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 0.1, -164);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 0.1, -167);
	glEnd();
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-2.9, 1, -167);
	glTexCoord2d(1, 0);
	glVertex3f(-2.9, 1, -164);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -164);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -167);
	glEnd();
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1, 0.1, -167);
	glTexCoord2d(1, 0);
	glVertex3f(-1, 0.1, -164);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -164);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -167);
	glEnd();
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1, 0.1, -164);
	glTexCoord2d(1, 0);
	glVertex3f(-2.9, 0.1, -164);
	glTexCoord2d(1, 1);
	glVertex3f(-2.9, 1, -164);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -164);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);//chair
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -163.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 0.5, -162.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 0.5, -162.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -163.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -163.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 0.5, -162.5);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.1, -162.5);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 0.1, -163.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.1, -162.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -162.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -162.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.1, -162.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -162.8);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -162.8);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -162.8);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -162.8);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -162.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -162.8);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -162.8);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 1.5, -162.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -162.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -162.8);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.5, -162.8);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 0.5, -162.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);//second chair
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -168.2);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -168.5);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.5, -168.5);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 0.5, -168.2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);//chair
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -168.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 0.5, -167.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 0.5, -167.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -168.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -168.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 0.5, -167.5);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.1, -167.5);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 0.1, -168.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.1, -168.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -168.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -168.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.1, -168.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -168.2);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -168.2);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -168.2);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -168.2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -168.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -168.2);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -168.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 1.5, -168.2);
	glEnd();
	glPushMatrix();
	glTranslated(4, 0, 0);
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-2.9, 0.1, -167);
	glTexCoord2d(1, 0);
	glVertex3f(-2.9, 0.1, -164);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 0.1, -164);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 0.1, -167);
	glEnd();
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-2.9, 1, -167);
	glTexCoord2d(1, 0);
	glVertex3f(-2.9, 1, -164);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1, -164);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -167);
	glEnd();
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-2.9, 0.1, -167);
	glTexCoord2d(1, 0);
	glVertex3f(-2.9, 0.1, -164);
	glTexCoord2d(1, 1);
	glVertex3f(-2.9, 1, -164);
	glTexCoord2d(0, 1);
	glVertex3f(-2.9, 1, -167);
	glEnd();
	glColor3f(1, 1, 1);//table
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1, 0.1, -164);
	glTexCoord2d(1, 0);
	glVertex3f(-2.9, 0.1, -164);
	glTexCoord2d(1, 1);
	glVertex3f(-2.9, 1, -164);
	glTexCoord2d(0, 1);
	glVertex3f(-1, 1, -164);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);//chair
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -163.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 0.5, -162.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 0.5, -162.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -163.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-2.7, 0.5, -163.5);
	glTexCoord2d(1, 0);
	glVertex3f(-2.7, 0.5, -162.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 0.1, -162.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.1, -163.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.1, -162.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -162.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -162.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.1, -162.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -162.8);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -162.8);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -162.8);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -162.8);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -162.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -162.8);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -162.8);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 1.5, -162.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -162.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -162.8);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.5, -162.8);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 0.5, -162.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);//second chair
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -168.2);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -168.5);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.5, -168.5);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 0.5, -168.2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);//chair
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -168.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 0.5, -167.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 0.5, -167.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -168.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -168.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 0.5, -167.5);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.1, -167.5);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 0.1, -168.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.1, -168.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -168.5);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -168.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.1, -168.5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 0.5, -168.2);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -168.2);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -168.2);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 0.5, -168.2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -168.5);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -168.2);
	glTexCoord2d(1, 1);
	glVertex3f(-2.7, 1.5, -168.5);
	glTexCoord2d(0, 1);
	glVertex3f(-2.7, 1.5, -168.2);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(3, -0.4, -161);
	glBegin(GL_POLYGON);//FIRST WHEEL
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(-5, 0, 0);//SECOND WHEEL
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(0.5, 0, -9);//THIRD WHEEL
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(6, 0, 0);//FOURTH WHEEL
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-d, 0, 0);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, door1);
	glBegin(GL_QUADS);//ÇáÈÇÈ ÇáíÓÇÑ
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -159.9);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 4, -159.9);
	glTexCoord2d(1, 1);
	glVertex3f(0, 4, -159.9);
	glTexCoord2d(1, 0);
	glVertex3f(0, 0, -159.9);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glTranslated(d, 0, 0);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(0, 0, -159.9);
	glTexCoord2d(1, 0);
	glVertex3f(2, 0, -159.9);
	glTexCoord2d(1, 1);
	glVertex3f(2, 4, -159.9);
	glTexCoord2d(0, 1);
	glVertex3f(0, 4, -159.9);
	glEnd();
	glPopMatrix();
	//the end of the ninth room
	// the driver room
	
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ
	glTexCoord2d(0,0);
	glVertex3f(-3,5,-186.1);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-186.1);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-186.1);
	glTexCoord2d(1,0);
	glVertex3f(3,5,-186.1);
	glEnd();

	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ
	glTexCoord2d(0, 0);
	glVertex3f(-3, 0, -186.1);
	glTexCoord2d(0, 1);
	glVertex3f(-3, 2, -186.1);
	glTexCoord2d(1, 1);
	glVertex3f(3, 2, -186.1);
	glTexCoord2d(1, 0);
	glVertex3f(3, 0, -186.1);
	glEnd();
	//front window
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 1, 1, 0.5);
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ
	glTexCoord2d(0, 0);
	glVertex3f(-3, 2, -186.1);
	glTexCoord2d(0, 1);
	glVertex3f(3, 2, -186.1);
	glTexCoord2d(1, 1);
	glVertex3f(3, 5, -186.1);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 5, -186.1);
	glEnd();
	glDisable(GL_BLEND);
	

	glPushMatrix();
	glTranslated(-d, 0, 0);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, door1);
	glBegin(GL_QUADS);//ÇáÈÇÈ ÇáíÓÇÑ
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -179.9);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 4,-179.9);
	glTexCoord2d(1, 1);
	glVertex3f(0, 4, -179.9);
	glTexCoord2d(1, 0);
	glVertex3f(0, 0,-179.9);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glTranslated(d, 0, 0);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, door2);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(0, 0, -179.9);
	glTexCoord2d(1, 0);
	glVertex3f(2, 0, -179.9);
	glTexCoord2d(1, 1);
	glVertex3f(2, 4, -179.9);
	glTexCoord2d(0, 1);
	glVertex3f(0, 4, -179.9);
	glEnd();
	glPopMatrix();



	glColor3f(1,1,1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);
	glTexCoord2d(1,0);
	glVertex3f(3,0,-186.1);
	glTexCoord2d(1,1);
	glVertex3f(3,2,-186.1);
	glTexCoord2d(0,1);
	glVertex3f(3,2,-180);
	glTexCoord2d(0,0);
	glVertex3f(3,0,-180);
	glEnd();
	
	glColor3f(1, 1, 1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(3, 5, -186.1);
	glTexCoord2d(1, 1);
	glVertex3f(3, 6, -186.1);
	glTexCoord2d(0, 1);
	glVertex3f(3, 6, -180);
	glTexCoord2d(0, 0);
	glVertex3f(3, 5, -180);
	glEnd();
	
	//right window
	/*
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 1, 1, 0.5);
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(3, 2, -186.1);
	glTexCoord2d(1, 1);
	glVertex3f(3, 5, -186.1);
	glTexCoord2d(0, 1);
	glVertex3f(3, 5, -180);
	glTexCoord2d(0, 0);
	glVertex3f(3, 2, -180);
	glEnd();
	glDisable(GL_BLEND);*/
	glColor3f(1, 1, 1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(3, 2, -186.1);
	glTexCoord2d(1, 1);
	glVertex3f(3, 6, -186.1);
	glTexCoord2d(0, 1);
	glVertex3f(3, 6, -185.1);
	glTexCoord2d(0, 0);
	glVertex3f(3, 2, -185.1);
	glEnd();
	glColor3f(1, 1, 1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(3, 2, -181);
	glTexCoord2d(1, 1);
	glVertex3f(3, 6, -181);
	glTexCoord2d(0, 1);
	glVertex3f(3, 6, -180);
	glTexCoord2d(0, 0);
	glVertex3f(3, 2, -180);
	glEnd();


	//right window
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 1, 1, 0.5);
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ
	glTexCoord2d(0, 0);
	glVertex3f(3, 2, -180.1);
	glTexCoord2d(0, 1);
	glVertex3f(3, 2, -186.1);
	glTexCoord2d(1, 1);
	glVertex3f(3, 5, -186.1);
	glTexCoord2d(1, 0);
	glVertex3f(3, 5, -180.1);
	glEnd();
	glDisable(GL_BLEND);
//



		glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 1, 1, 0.5);
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÎáÝí ÇáãäÊÕÝ
	glTexCoord2d(0, 0);
	glVertex3f(-3, 2, -180.1);
	glTexCoord2d(0, 1);
	glVertex3f(-3, 2, -186.1);
	glTexCoord2d(1, 1);
	glVertex3f(-3, 5, -186.1);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 5, -180.1);
	glEnd();
	glDisable(GL_BLEND);
//
	glColor3f(1, 1, 1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 2, -181);
	glTexCoord2d(1, 1);
	glVertex3f(-3, 6, -181);
	glTexCoord2d(0, 1);
	glVertex3f(-3, 6, -180);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 2, -180);
	glEnd();
	glColor3f(1, 1, 1);//ÇáÍíØ ÇáÌÇäÈí Çáíãíä
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 2, -186.1);
	glTexCoord2d(1, 1);
	glVertex3f(-3, 6, -186.1);
	glTexCoord2d(0, 1);
	glVertex3f(-3, 6, -185.1);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 2, -185.1);
	glEnd();
	

	glColor3f(1,1,1);
	glColor3f(1, 1, 1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 5, -186.1);
	glTexCoord2d(1, 1);
	glVertex3f(-3, 6, -186.1);
	glTexCoord2d(0, 1);
	glVertex3f(-3, 6, -180);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 5, -180);
	glEnd();
	glColor3f(1, 1, 1);

	glColor3f(1, 1, 1);
	glColor3f(1, 1, 1);//ÇáÍíØ ÇáÌÇäÈí ÇáíÓÇÑí
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 0, -186.1);
	glTexCoord2d(1, 1);
	glVertex3f(-3, 2, -186.1);
	glTexCoord2d(0, 1);
	glVertex3f(-3, 2, -180);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 0, -180);
	glEnd();
	glColor3f(1, 1, 1);



	glBindTexture(GL_TEXTURE_2D,roof);
	glBegin(GL_QUADS);//ÇáÓÞÝ
	glTexCoord2d(0,0);
	glVertex3f(-3,6,-186.1);
	glTexCoord2d(1,0);
	glVertex3f(3,6,-186.1);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-180);
	glTexCoord2d(0,1);
	glVertex3f(-3,6,-180);
	glEnd();

	
	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáíÓÇÑ
	glTexCoord2d(0,1);
	glVertex3f(-3,0,-180);
	glTexCoord2d(1,1);
	glVertex3f(-3,6,-180);
	glTexCoord2d(1,0);
	glVertex3f(-2,6,-180);
	glTexCoord2d(0,0);
	glVertex3f(-2,0,-180);
	glEnd();


	glBindTexture(GL_TEXTURE_2D,wall1);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí Çáíãíä
	glTexCoord2d(0,0);
	glVertex3f(2,0,-180);
	glTexCoord2d(1,0);
	glVertex3f(2,6,-180);
	glTexCoord2d(1,1);
	glVertex3f(3,6,-180);
	glTexCoord2d(0,1);
	glVertex3f(3,0,-180);
	glEnd();


	glColor3f(1,1,1);
	glBindTexture(GL_TEXTURE_2D,wall3);
	glBegin(GL_QUADS);//ÞÓã ÇáÍíØ ÇáÃãÇãí ÇáãäÊÕÝ
	glTexCoord2d(0,0);
	glVertex3f(-2,4,-180);
	glTexCoord2d(0,1);
	glVertex3f(-2,6,-180);
	glTexCoord2d(1,1);
	glVertex3f(2,6,-180);
	glTexCoord2d(1,0);
	glVertex3f(2,4,-180);
	glEnd();



	glColor3f(1,1,1);//ÃÑÖíÉ ÇáãÞÕæÑÉ
	glBindTexture(GL_TEXTURE_2D,brick);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-3,0.01,-180);
	glTexCoord2d(0,1);
	glVertex3f(-3,0.01,-188.1);
	glTexCoord2d(1,1);
	glVertex3f(3,0.01,-188.1);
	glTexCoord2d(1,0);
	glVertex3f(3,0.01,-180);
	glEnd();

	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(3, 0, -186.1);
	glTexCoord2d(0, 1);
	glVertex3f(3, 2, -186.1);
	glTexCoord2d(1, 1);
	glVertex3f(3, 2, -190);
	glTexCoord2d(1, 0);
	glVertex3f(3, 0, -190);
	glEnd();
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 0, -186.1);
	glTexCoord2d(0, 1);
	glVertex3f(-3, 2, -186.1);
	glTexCoord2d(1, 1);
	glVertex3f(-3, 2, -190);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 0, -190);
	glEnd();
	//raml1
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 1, -190.1);
	glTexCoord2d(0, 1);
	glVertex3f(-3, 1.5, -190.1);
	glTexCoord2d(1, 1);
	glVertex3f(-1, 1.5, -190.1);
	glTexCoord2d(1, 0);
	glVertex3f(-1, 1, -190.1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glTexCoord2d(0, 0);
	glVertex3f(1, 1, -190.1);
	glTexCoord2d(0, 1);
	glVertex3f(1, 1.5, -190.1);
	glTexCoord2d(1, 1);
	glVertex3f(3, 1.5, -190.1);
	glTexCoord2d(1, 0);
	glVertex3f(3, 1, -190.1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 0, -190);
	glTexCoord2d(0, 1);
	glVertex3f(-3, 2, -190);
	glTexCoord2d(1, 1);
	glVertex3f(3, 2, -190);
	glTexCoord2d(1, 0);
	glVertex3f(3, 0, -190);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 2, -190);
	glTexCoord2d(0, 1);
	glVertex3f(-3, 2, -186.1);
	glTexCoord2d(1, 1);
	glVertex3f(3, 2, -186.1);
	glTexCoord2d(1, 0);
	glVertex3f(3, 2, -190);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 1.5, -185.1);
	glTexCoord2d(0, 0);
	glVertex3f(3, 1.5, -185.1);
	glTexCoord2d(0, 1);
	glVertex3f(3, 0, -185.1);
	glTexCoord2d(1, 1);
	glVertex3f(-3, 0, -185.1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3f(-3, 2, -186.1);
	glTexCoord2d(0, 1);
	glVertex3f(3, 2, -186.1);
	glTexCoord2d(1, 1);
	glVertex3f(3, 1.5, -185.1);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 1.5, -185.1);
	glEnd();
	//the body f the man
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3f(-2.5, 1.5, -184.1);
	glTexCoord2d(0, 1);
	glVertex3f(-2.5, 2.5, -184.1);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 2.5, -184.1);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -184.1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3f(-2.5, 1.5, -183.9);
	glTexCoord2d(0, 1);
	glVertex3f(-2.5, 2.5, -183.9);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 2.5, -183.9);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -183.9);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3f(-1.5, 1.5, -183.9);
	glTexCoord2d(0, 1);
	glVertex3f(-1.5, 2.5, -183.9);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 2.5, -184.1);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -184.1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3f(-2.5, 1.5, -183.9);
	glTexCoord2d(0, 1);
	glVertex3f(-2.5, 2.5, -183.9);
	glTexCoord2d(1, 1);
	glVertex3f(-2.5, 2.5, -184.1);
	glTexCoord2d(1, 0);
	glVertex3f(-2.5, 1.5, -184.1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3f(-2.4, 2.3, -184);
	glTexCoord2d(0, 1);
	glVertex3f(-2.4, 2.5, -184);
	glTexCoord2d(1, 1);
	glVertex3f(-2.4, 2, -185);
	glTexCoord2d(1, 0);
	glVertex3f(-2.4, 1.8, -185);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, redcarpet);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);
	glVertex3f(-1.6, 2.3, -184);
	glTexCoord2d(0, 1);
	glVertex3f(-1.6, 2.5, -184);
	glTexCoord2d(1, 1);
	glVertex3f(-1.6, 2.1, -185);
	glTexCoord2d(1, 0);
	glVertex3f(-1.6, 1.8, -185);
	glEnd();
	glPushMatrix();
	glTranslated(-2.5,0,-127.1);
	chair1();
	glTranslated(4,0,0);
	chair1();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, wall1);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 1);
	glTexCoord2d(0, 0);
	glVertex3f(-2.5, 1.5, -184.1);
	glTexCoord2d(0, 1);
	glVertex3f(-2.5, 0.3, -184.1);
	glTexCoord2d(1, 1);
	glVertex3f(-1.5, 0.3, -184.1);
	glTexCoord2d(1, 0);
	glVertex3f(-1.5, 1.5, -184.1);
	glEnd();
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(-2, 3, -184);
	glBegin(GL_POLYGON);//FIRST WHEEL
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1, 1, 1);
		glVertex3f(x, y, 0);
	}
	glEnd();

	glTranslated(0, 0, 0.1);
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1, 1, 0);
		glVertex3f(x, y, 0);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(1, 1, 0);
		glVertex3f(x, y, 0.1);
		glVertex3f(x, y, 0);
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();

	glTranslated(-2, 3.4, -184);
	glBegin(GL_POLYGON);//FIRST WHEEL
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.1f * cos(angle);
		float x = 0.1f * sin(angle);
		glColor3f(1, 1, 1);
		glVertex3f(x, 0, y);
	}
	glEnd();

	glTranslated(0, -0.5, 0);
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.1f * cos(angle);
		float y = 0.1f * sin(angle);
		glColor3f(1, 1, 1);
		glVertex3f(x, 0, y);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.1f * cos(angle);
		float y = 0.1f * sin(angle);
		glColor3f(1, 1, 1);
		glVertex3f(x, -0.5, y);
		glVertex3f(x, 0, y);
	}
	glEnd();

	glPopMatrix();
	/*//ahmadl
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, st);
	glBegin(GL_QUADS);
	glColor4f(1, 1, 1, 0.5);
	glTexCoord2d(0, 0);
	glVertex3f(3, 2, -6.1);
	glTexCoord2d(0, 1);
	glVertex3f(3, 5, -6.1);
	glTexCoord2d(1, 1);
	glVertex3f(-3, 5, -6.1);
	glTexCoord2d(1, 0);
	glVertex3f(-3, 2, -6.1);
	glEnd();
	glPopMatrix();
    glDisable(GL_BLEND);
	*/
	//THE MAN
	
	//THE END OF THE MAN

	glPushMatrix();
	glTranslated(-2, 1.8, -185);

	glBegin(GL_POLYGON);//driving wheel
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(x, y, 0);
	}
	glEnd();
	glPopMatrix();



	//the begining of the stuff
	glPushMatrix();
	glTranslated(3, -0.4, -180);
	glBegin(GL_POLYGON);//FIRST WHEEL
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(-5, 0, 0);//SECOND WHEEL
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(0.5, 0, -9);//THIRD WHEEL
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glTranslated(6, 0, 0);//FOURTH WHEEL
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float y = 0.4f * cos(angle);
		float x = 0.4f * sin(angle);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glTranslated(-0.5, 0, 0);
	glBegin(GL_POLYGON);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0, x, y);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP);
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.1f)
	{
		float x = 0.4f * cos(angle);
		float y = 0.4f * sin(angle);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.5, x, y);
		glVertex3f(0, x, y);
	}
	glEnd();
	glPopMatrix();

	






	//the connection
	glColor3f(1, 1, 1);//first one
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -9.9);
	glTexCoord2d(1, 0);
	glVertex3f(2, 0, -9.9);
	glTexCoord2d(1, 1);
	glVertex3f(2, 0, -20);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 0, -20);
	glEnd();
	glColor3f(1, 1, 1);
	
	glColor3f(1, 1, 1);//second one
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -29.9);
	glTexCoord2d(1, 0);
	glVertex3f(2, 0, -29.9);
	glTexCoord2d(1, 1);
	glVertex3f(2, 0, -40);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 0, -40);
	glEnd();
	
	glColor3f(1, 1, 1);//third one
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -49.9);
	glTexCoord2d(1, 0);
	glVertex3f(2, 0, -49.9);
	glTexCoord2d(1, 1);
	glVertex3f(2, 0, -60);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 0, -60);
	glEnd();
	glColor3f(1, 1, 1);//fourth one
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -69.9);
	glTexCoord2d(1, 0);
	glVertex3f(2, 0, -69.9);
	glTexCoord2d(1, 1);
	glVertex3f(2, 0, -80);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 0, -80);
	glEnd();
	glColor3f(1, 1, 1);//fifth one
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -89.9);
	glTexCoord2d(1, 0);
	glVertex3f(2, 0, -89.9);
	glTexCoord2d(1, 1);
	glVertex3f(2, 0, -100);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 0, -100);
	glEnd();
	glColor3f(1, 1, 1);//six one
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -109.9);
	glTexCoord2d(1, 0);
	glVertex3f(2, 0, -109.9);
	glTexCoord2d(1, 1);
	glVertex3f(2, 0, -120);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 0, -120);
	glEnd();
	glColor3f(1, 1, 1);//seventh one
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -129.9);
	glTexCoord2d(1, 0);
	glVertex3f(2, 0, -129.9);
	glTexCoord2d(1, 1);
	glVertex3f(2, 0, -140);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 0, -140);
	glEnd();
	glColor3f(1, 1, 1);//eighth one
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -149.9);
	glTexCoord2d(1, 0);
	glVertex3f(2, 0, -149.9);
	glTexCoord2d(1, 1);
	glVertex3f(2, 0, -160);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 0, -160);
	glEnd();
	glColor3f(1, 1, 1);//ninth one
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -169.9);
	glTexCoord2d(1, 0);
	glVertex3f(2, 0, -169.9);
	glTexCoord2d(1, 1);
	glVertex3f(2, 0, -180);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 0, -180);
	glEnd();
	/*/*
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(2, 0, -49.9);
	glTexCoord2d(1, 0);
	glVertex3f(2, 2, -49.9);
	glTexCoord2d(1, 1);
	glVertex3f(2, 2, -60);
	glTexCoord2d(0, 1);
	glVertex3f(2, 0, -60);
	glEnd();
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);//ÇáÈÇÈ Çáíãíä
	glTexCoord2d(0, 0);
	glVertex3f(-2, 0, -49.9);
	glTexCoord2d(1, 0);
	glVertex3f(-2, 2, -49.9);
	glTexCoord2d(1, 1);
	glVertex3f(-2, 2, -60);
	glTexCoord2d(0, 1);
	glVertex3f(-2, 0, -60);
	glEnd();*/
	// end of coonneeectiiooon


	glPopMatrix();
    glFlush();											// Done Drawing The Quad	

    //DO NOT REMOVE THIS
	SwapBuffers(hDC);			
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL,NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd,hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL",hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/
 
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left=(long)0;			// Set Left Value To 0
	WindowRect.right=(long)width;		// Set Right Value To Requested Width
	WindowRect.top=(long)0;				// Set Top Value To 0
	WindowRect.bottom=(long)height;		// Set Bottom Value To Requested Height

	fullscreen=fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC) WndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}
	
	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","NeHe GL",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				fullscreen=FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle=WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle=WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								0, 0,								// Window Position
								WindowRect.right-WindowRect.left,	// Calculate Window Width
								WindowRect.bottom-WindowRect.top,	// Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};
	
	if (!(hDC=GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC=wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!wglMakeCurrent(hDC,hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd,SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(	HWND	hWnd,			// Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)			// Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg)									// Check For Windows Messages
	{
		case WM_PAINT: 
			DrawGLScene();
			BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			return 0;
	
		case WM_TIMER:
			DrawGLScene();
			return 0;

		case WM_ACTIVATE:							// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))					// Check Minimization State
			{
				active=TRUE;						// Program Is Active
			}
			else
			{
				active=FALSE;						// Program Is No Longer Active
			}

			return 0;								// Return To The Message Loop
		}

		case WM_SYSCOMMAND:							// Intercept System Commands
		{
			switch (wParam)							// Check System Calls
			{
				case SC_SCREENSAVE:					// Screensaver Trying To Start?
				case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
				return 0;							// Prevent From Happening
			}
			break;									// Exit
		}

		case WM_CLOSE:								// Did We Receive A Close Message?
		{
			PostQuitMessage(0);						// Send A Quit Message
			return 0;								// Jump Back
		}

		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
			keys[wParam] = TRUE;					// If So, Mark It As TRUE
			return 0;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			keys[wParam] = FALSE;					// If So, Mark It As FALSE
			return 0;								// Jump Back
		}

		case WM_SIZE:								// Resize The OpenGL Window
		{
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
			return 0;								// Jump Back
		}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

int WINAPI WinMain(	HINSTANCE	hInstance,			// Instance
					HINSTANCE	hPrevInstance,		// Previous Instance
					LPSTR		lpCmdLine,			// Command Line Parameters
					int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done=FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen=FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Madhat NeHe Template",640,480,16,fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}


	//Set drawing timer to 20 frame per second
	UINT timer=SetTimer(hWnd,0,1,(TIMERPROC) NULL);

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
			TranslateMessage(&msg);	
			DispatchMessage(&msg);



	}

	return 0;

}
