

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include<math.h>

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#define WINDOW_TITLE "OpenGL Window"
#define CLASS_TITLE "OpenGL Window Class"

GLuint logo1 = 0;
BITMAP BMP1;
HBITMAP hBMP1 = (HBITMAP)LoadImage(GetModuleHandle(NULL), "logo1.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

GLuint logo2 = 0;
BITMAP BMP2;
HBITMAP hBMP2 = (HBITMAP)LoadImage(GetModuleHandle(NULL), "logo2.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

GLuint logo3 = 0;
BITMAP BMP3;
HBITMAP hBMP3 = (HBITMAP)LoadImage(GetModuleHandle(NULL), "logo3.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

GLuint logo4 = 0;
BITMAP BMP4;
HBITMAP hBMP4 = (HBITMAP)LoadImage(GetModuleHandle(NULL), "logo4.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

GLuint logo5 = 0;
BITMAP BMP5;
HBITMAP hBMP5 = (HBITMAP)LoadImage(GetModuleHandle(NULL), "space2.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);


int transform = -1;

//float eyeX = 0.0f;
//float eyeY = 0.0f;
//float eyeZ = 1.0f;

float radius = 0.075f;
float pi = 3.142f;

float rotation = 0.0f;
float rotationSpeed = 0.00;

float rotation2 = 0.0f;
float rotationSpeed2 = 0.00;

float rotation3 = 0.0f;
float rotationSpeed3 = 0.00;

float colorr = 0.7;
float colorg = 0.7;
float colorb = 0.7;

float color2r = 0.9;
float color2g = 0.9;
float color2b = 0.9;

float rotationhorna = 0.0f;
float rotationhornb = 0.0f;
float rotationSpeedhorn = 0.00;//0.02

float rotationheadsidea = 0.0f;
float rotationheadsideb = 0.0f;
float rotationheadsidespeed = 0.00f;//0.04

float rotationfacea = 0.0;
float rotationfaceb = 75.0;
float rotationSpeedfacea = 0.00;//0.02
float rotationSpeedfaceb = 0.00;//0.02

float rotationdoor = 0.0f;
float rotationSpeeddoor = 0.00;//0.02

float rotationarmor = 0;
float rotationSpeedarmor = 0;

float rotationbra = 0;
float rotationSpeedbra = 0;

float rotationwaist = 0;
float rotationSpeedwaist = 0;

float rotationshouder1 = 0;
float rotationSpeedshouder1 = 0;

float rotationshouder2 = 0;
float rotationSpeedshouder2 = 0;

float rotationshouder3 = 0;
float rotationSpeedshouder3 = 0;

float rotationshouder4 = 0;
float rotationSpeedshouder4 = 0;

float rotationhandleft = 0;
float rotationhandright = 0;

float rotationhandleft2 = 0;
float rotationhandright2 = 0;

float rotationhandleft3 = 0;
float rotationhandright3 = 0;

float rotationhandleft4 = 0;
float rotationhandright4 = 0;

float rotationhandlefts = 0;
float rotationhandrights = 0;

float rotationhandleft2s = 0;
float rotationhandright2s = 0;

float rotationhandleft3s = 0;
float rotationhandright3s = 0;

float rotationhandleft4s = 0;
float rotationhandright4s = 0;

float rotationfan = 0;
float rotationSpeedfan = 0;

float rotationsheild = 0;
float rotationSpeedsheild = 0;

float rotationbelt1 = 0;
float rotationSpeedbelt1 = 0;

float rotationbelt2 = 0;
float rotationSpeedbelt2 = 0;

float rotationbelt3 = 0;
float rotationSpeedbelt3 = 0;

float rotationbelt4 = 0;
float rotationSpeedbelt4 = 0;

float rotationbelt5 = 0;
float rotationSpeedbelt5 = 0;

float rotationbelt6 = 0;
float rotationSpeedbelt6 = 0;

float updown = 1;
float rotaionhead1 = 0;
float rotaionhead1s = 0;
float rotaionhead2 = 0;
float rotaionhead2s = 0;
float handsaber1 = 0;
float handsaber2 = 0;
float handsaber1speed = 0;
float handsaber2speed = 0;
float leftshield = 0;
float rightshield = 0;

GLUquadricObj* headtop = gluNewQuadric();
GLUquadricObj* neck1 = gluNewQuadric();
GLUquadricObj* neck2 = gluNewQuadric();
GLUquadricObj* neck3 = gluNewQuadric();
GLUquadricObj* ball1 = gluNewQuadric();
GLUquadricObj* ball2 = gluNewQuadric();
GLUquadricObj* tiang1 = gluNewQuadric();
GLUquadricObj* tiang2 = gluNewQuadric();
GLUquadricObj* space = gluNewQuadric();


float rotationSpeedfoot = 0.00;
float rotationFoot = 0.0f;
float whiteLockerY = 0.0f;
float whiteLockerZ = 0.0f;
float whiteLocker = 0.0f;
float whiteLockerSpeedY = 0.0f;
float whiteLockerSpeedZ = 0.0f;

float lowerLegBreak = 0.0f;
float lowerLegBreakSpeed = 0.0f;
float upperLegBreak = 0.0f;
float upperLegBreakSpeed = 0.0f;

float redThrusterRotation = 0.0f;
float redThrusterRotationSpeed = 0.0f;
float thrusterRotation = 0.0f;
float thrusterRotationSpeed = 0.0f;

float lowerHandBreak = 0.0f;
float lowerHandBreakSpeed = 0.0f;

float saberRotation = 0.0f;
float saberRotationSpeed = 0.0f;
float saberY = -0.16f;
float saberYSpeed = 0.0f;

float leftSaberRotation = 0.0f;
float leftSaberRotationSpeed = 0.0f;
float leftSaberY = -0.16f;
float leftSaberYSpeed = 0.0f;

float upKneeRotation = 0.0f;
float upKneeRotationSpeed = 0.0f;

float downKneeBreak = 0.0f;
float downKneeBreakSpeed = 0.0f;

GLUquadricObj* leftLegBone = gluNewQuadric();
GLUquadricObj* leftLegRedBone = gluNewQuadric();
GLUquadricObj* leftLegUpperJoint = gluNewQuadric();
GLUquadricObj* leftLegUpperJointInner = gluNewQuadric();

GLUquadricObj* leftLegLowerJoint = gluNewQuadric();
GLUquadricObj* leftLegLowerJointInner = gluNewQuadric();

GLUquadricObj* rightArmJoint = gluNewQuadric();
GLUquadricObj* rightArmJointInner = gluNewQuadric();


float eyeX = 0.0f;
float eyeY = 0.0f;
float eyeZ = 1.0f;


int rightSaberB = -1;
int leftSaberB = -1;


float rightLeg1 = 0.0f;
float rightLeg2 = 0.0f;
float rightLeg3 = 0.0f;
float rightLeg4 = 0.0f;
float rightLeg5 = 0.0f;
float rightLeg6 = 0.0f;
float rightLeg1s = 0.0f;
float rightLeg2s = 0.0f;
float rightLeg3s = 0.0f;
float rightLeg4s = 0.0f;
float rightLeg5s = 0.0f;
float rightLeg6s = 0.0f;

float leftLeg1 = 0.0f;
float leftLeg2 = 0.0f;
float leftLeg3 = 0.0f;
float leftLeg4 = 0.0f;
float leftLeg5 = 0.0f;
float leftLeg6 = 0.0f;
float leftLeg1s = 0.0f;
float leftLeg2s = 0.0f;
float leftLeg3s = 0.0f;
float leftLeg4s = 0.0f;
float leftLeg5s = 0.0f;
float leftLeg6s = 0.0f;

GLuint texture = 0;

int pose1 = -1;
int pose2 = -1;


LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			PostQuitMessage(0);

		/*if (wParam == VK_F2) {
			if (question < 6) {
				question++;
			}
		}
		if (wParam == VK_F1) {
			if (question > 1) {
				question--;
			}
		}*/

		if (wParam == VK_UP) {
			//eyeY += 0.08f;
			rotation2 += 2;
		}

		if (wParam == VK_DOWN) {
			//eyeY -= 0.08f;
			rotation2 -= 2;
		}

		if (wParam == VK_LEFT) {
			rotation -= 2;
			//eyeX -= 0.08f;
		}

		if (wParam == VK_RIGHT) {
			rotation += 2;
			//eyeX += 0.08f;
		}

		if (wParam == VK_SPACE) {


			if (transform == -1) {
				transform = 1;
			}
			else if (transform == 1) {
				transform = 0;
			}
			else if (transform == 0) {
				transform = 1;
			}




		}

		if (wParam == 0x5A) {  //Z
			if (rotationSpeeddoor == -0.04f) {
				rotationSpeeddoor = +0.06f;
			}
			else {
				rotationSpeeddoor = -0.06f;
			}
		}

		if (wParam == VK_SHIFT) {  //SHIFT
			updown = updown * -1;
		}


		if (wParam == 0x52) {  //R

		}

		if (wParam == 0x47) {  //G

		}

		if (wParam == 0x50) {  //P
			rotaionhead1 -= 2 * updown;
		}

		if (wParam == 0x4C) {  //L
			rotaionhead2 += 2 * updown;
		}

		if (wParam == 0x51) {  //Q  
			rotationhandleft -= 2 * updown;
		}

		if (wParam == 0x41) {  //A  
			rotationhandright -= 2 * updown;
		}

		if (wParam == 0x57) {  //W  right hand up
			rotationhandleft2 += 2 * updown;
		}

		if (wParam == 0x53) {  //S  right hand down
			rotationhandright2 += 2 * updown;
		}

		if (wParam == 0x45) {  //E
			rotationhandleft3 += 2 * updown;
		}

		if (wParam == 0x44) {  //D
			rotationhandright3 += 2 * updown;
		}

		if (wParam == 0x52) {  //R
			rotationhandleft4 += 2 * updown;
		}

		if (wParam == 0x46) {  //F
			rotationhandright4 += 2 * updown;
		}

		if (wParam == 0x54) {  //T

		}

		if (wParam == 0x47) {  //G

		}

		if (wParam == 0x59) {  //Y

		}

		if (wParam == 0x48) {  //H
		}

		if (wParam == 0x55) {  //U

		}

		if (wParam == 0x4A) {  //J
		}

		if (wParam == 0x49) {  //I

		}

		if (wParam == 0x4B) {  //K

		}

		if (wParam == 0x59) {  //Y

		}



		if (wParam == 0x58) {  //X
			//pose 1
			if (pose1 == -1) {
				pose1 = 1;
			}
			else if (pose1 == 1) {
				pose1 = 0;
			}
			else if (pose1 == 0) {
				pose1 = 1;
			}

		}

		if (wParam == 0x43) {  //C
			//pose 2
			if (pose2 == -1) {
				pose2 = 1;
			}
			else if (pose2 == 1) {
				pose2 = 0;
			}
			else if (pose2 == 0) {
				pose2 = 1;
			}

		}

		if (wParam == 0x56) {  //V

		}

		if (wParam == 0x31) {  //1
			if (leftSaberB == -1) {
				leftSaberB = 1;
			}
			else if (leftSaberB == 1) {
				leftSaberB = 0;
			}
			else if (leftSaberB == 0) {
				leftSaberB = 1;
			}
		}

		if (wParam == 0x32) {  //2

			if (rightSaberB == -1) {
				rightSaberB = 1;
			}
			else if (rightSaberB == 1) {
				rightSaberB = 0;
			}
			else if (rightSaberB == 0) {
				rightSaberB = 1;
			}



		}


		if (wParam == 0x33) {  //3

			if (handsaber1 == 0) {
				handsaber1 = 1;
			}

			else {
				handsaber1 = 0;
			}
		}

		if (wParam == 0x34) {  //4
			if (handsaber2 == 0) {
				handsaber2 = 1;
			}

			else {
				handsaber2 = 0;
			}
		}

		if (wParam == 0x35) {  //5
			if (leftshield == 0) {
				leftshield = 1;
			}

			else {
				leftshield = 0;
			}
		}

		if (wParam == 0x36) {  //6
			if (rightshield == 0) {
				rightshield = 1;
			}

			else {
				rightshield = 0;
			}
		}

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//--------------------------------------------------------------------

void pose1a() {
	leftLeg3s = -0.1f;
	leftLeg6s = 0.1f;
	rightLeg1s = -0.1f;
	rightLeg3s = 0.1f;
	rightLeg4s = 0.1f;
	rightLeg6s = -0.1f;

	rotaionhead1s = 0.05f;
	rotaionhead2s = 0.05f;

	rotationhandlefts = 0.1f;
	rotationhandleft2s = 0.1f;
	rotationhandleft3s = 0.1f;
	rotationhandleft4s = 0.1f;

	rotationhandrights = -0.1f;
	rotationhandright2s = -0.1f;
	rotationhandright3s = -0.1f;

	if (leftLeg3 <= -30) {
		leftLeg3 = -30;
		leftLeg3s = 0.0f;
	}
	if (leftLeg6 >= 30) {
		leftLeg6 = 30;
		leftLeg6s = 0.0f;
	}
	if (rightLeg1 <= -40) {
		rightLeg1 = -40;
		rightLeg1s = 0.0f;
	}
	if (rightLeg3 >= 40) {
		rightLeg3 = 40;
		rightLeg3s = 0.0f;
	}
	if (rightLeg4 >= 40) {
		rightLeg4 = 40;
		rightLeg4s = 0.0f;
	}
	if (rightLeg6 <= -30) {
		rightLeg6 = -30;
		rightLeg6s = 0.0f;
	}
	if (rotaionhead1 >= 20) {
		rotaionhead1 = 20;
		rotaionhead1s = 0.0f;
	}
	if (rotaionhead2 >= 40) {
		rotaionhead2 = 40;
		rotaionhead2s = 0.0f;
	}
	if (rotationhandleft >= 40) {
		rotationhandleft = 40;
		rotationhandlefts = 0.0f;
	}
	if (rotationhandleft2 >= 50) {
		rotationhandleft2 = 50;
		rotationhandleft2s = 0.0f;
	}
	if (rotationhandleft3 >= 50) {
		rotationhandleft3 = 50;
		rotationhandleft3s = 0.0f;
	}
	if (rotationhandleft4 >= 50) {
		rotationhandleft4 = 50;
		rotationhandleft4s = 0.0f;
	}
	if (rotationhandright <= -70) {
		rotationhandright = -70;
		rotationhandrights = 0.0f;
	}
	if (rotationhandright2 <= -10) {
		rotationhandright2 = -10;
		rotationhandright2s = 0.0f;
	}
	if (rotationhandright3 <= -20) {
		rotationhandright3 = -20;
		rotationhandright3s = 0.0f;
	}
}

void pose1ab() {
	leftLeg3s = 0.1f;
	leftLeg6s = -0.1f;
	rightLeg1s = 0.1f;
	rightLeg3s = -0.1f;
	rightLeg4s = -0.1f;
	rightLeg6s = 0.1f;

	rotaionhead1s = -0.05f;
	rotaionhead2s = -0.05f;

	rotationhandlefts = -0.1f;
	rotationhandleft2s = -0.1f;
	rotationhandleft3s = -0.1f;
	rotationhandleft4s = -0.1f;

	rotationhandrights = 0.1f;
	rotationhandright2s = 0.1f;
	rotationhandright3s = 0.1f;

	if (leftLeg3 > 0) {
		leftLeg3 = 0;
		leftLeg3s = 0.0f;
	}
	if (leftLeg6 < 0) {
		leftLeg6 = 0;
		leftLeg6s = 0.0f;
	}
	if (rightLeg1 > 0) {
		rightLeg1 = 0;
		rightLeg1s = 0.0f;
	}
	if (rightLeg3 < 0) {
		rightLeg3 = 0;
		rightLeg3s = 0.0f;
	}
	if (rightLeg4 <0) {
		rightLeg4 = 0;
		rightLeg4s = 0.0f;
	}
	if (rightLeg6 > 0) {
		rightLeg6 = 0;
		rightLeg6s = 0.0f;
	}
	if (rotaionhead1 < 0) {
		rotaionhead1 = 0;
		rotaionhead1s = 0.0f;
	}
	if (rotaionhead2 < 0) {
		rotaionhead2 = 0;
		rotaionhead2s = 0.0f;
	}
	if (rotationhandleft < 0) {
		rotationhandleft = 0;
		rotationhandlefts = 0.0f;
	}
	if (rotationhandleft2 < 0) {
		rotationhandleft2 = 0;
		rotationhandleft2s = 0.0f;
	}
	if (rotationhandleft3 < 0) {
		rotationhandleft3 = 0;
		rotationhandleft3s = 0.0f;
	}
	if (rotationhandleft4 < 0) {
		rotationhandleft4 = 0;
		rotationhandleft4s = 0.0f;
	}
	if (rotationhandright > 0) {
		rotationhandright = 0;
		rotationhandrights = 0.0f;
	}
	if (rotationhandright2 > 0) {
		rotationhandright2 = 0;
		rotationhandright2s = 0.0f;
	}
	if (rotationhandright3 > 0) {
		rotationhandright3 = 0;
		rotationhandright3s = 0.0f;
	}
}

void pose2a() {
	leftLeg1 = 20;
	leftLeg3 = -10;
	leftLeg4 = 20;
	leftLeg5 = 30; //1
	rightLeg1 = -50;
	rightLeg3 = 10;
	rightLeg4 = 80;
	rightLeg5 = 50;

	rotaionhead2 = -30;

	rotationhandleft = -40;
	rotationhandleft2 = -45;
	

	rotationhandright = -100;
	rotationhandright3 = -90;
	rotationhandright4 = -80;

	/*if (leftLeg1 >= 20) {
		leftLeg3 = -30;
		leftLeg3s = 0.0f;
	}
	if (leftLeg3 <= -10) {
		leftLeg6 = 30;
		leftLeg6s = 0.0f;
	}
	if (leftLeg4 <= 20) {
		leftLeg3 = -30;
		leftLeg3s = 0.0f;
	}
	if (leftLeg6 >= 30) {
		leftLeg6 = 30;
		leftLeg6s = 0.0f;
	}
	if (rightLeg1 <= -40) {
		rightLeg1 = -40;
		rightLeg1s = 0.0f;
	}
	if (rightLeg3 >= 40) {
		rightLeg3 = 40;
		rightLeg3s = 0.0f;
	}
	if (rightLeg4 >= 40) {
		rightLeg4 = 40;
		rightLeg4s = 0.0f;
	}
	if (rightLeg6 <= -30) {
		rightLeg6 = -30;
		rightLeg6s = 0.0f;
	}
	if (rotaionhead1 >= 20) {
		rotaionhead1 = 20;
		rotaionhead1s = 0.0f;
	}
	if (rotaionhead2 >= 40) {
		rotaionhead2 = 40;
		rotaionhead2s = 0.0f;
	}
	if (rotationhandleft >= 40) {
		rotationhandleft = 40;
		rotationhandlefts = 0.0f;
	}
	if (rotationhandleft2 >= 50) {
		rotationhandleft2 = 50;
		rotationhandleft2s = 0.0f;
	}
	if (rotationhandleft3 >= 50) {
		rotationhandleft3 = 50;
		rotationhandleft3s = 0.0f;
	}
	if (rotationhandleft4 >= 50) {
		rotationhandleft4 = 50;
		rotationhandleft4s = 0.0f;
	}
	if (rotationhandright <= -70) {
		rotationhandright = -70;
		rotationhandrights = 0.0f;
	}
	if (rotationhandright2 <= -10) {
		rotationhandright2 = -10;
		rotationhandright2s = 0.0f;
	}
	if (rotationhandright3 <= -20) {
		rotationhandright3 = -20;
		rotationhandright3s = 0.0f;
	}*/
}

void pose2ab() {
	leftLeg1 = 0;
	leftLeg3 = 0;
	leftLeg4 = 0;
	leftLeg5 = 0; //1
	rightLeg1 = 0;
	rightLeg3 = 0;
	rightLeg4 = 0;
	rightLeg5 = 0;

	rotaionhead2 = 0;

	rotationhandleft = 0;
	rotationhandleft2 = 0;


	rotationhandright = 0;
	rotationhandright3 = 0;
	rotationhandright4 = 0;

	/*if (leftLeg3 > 0) {
		leftLeg3 = 0;
		leftLeg3s = 0.0f;
	}
	if (leftLeg6 < 0) {
		leftLeg6 = 0;
		leftLeg6s = 0.0f;
	}
	if (rightLeg1 > 0) {
		rightLeg1 = 0;
		rightLeg1s = 0.0f;
	}
	if (rightLeg3 < 0) {
		rightLeg3 = 0;
		rightLeg3s = 0.0f;
	}
	if (rightLeg4 < 0) {
		rightLeg4 = 0;
		rightLeg4s = 0.0f;
	}
	if (rightLeg6 > 0) {
		rightLeg6 = 0;
		rightLeg6s = 0.0f;
	}
	if (rotaionhead1 < 0) {
		rotaionhead1 = 0;
		rotaionhead1s = 0.0f;
	}
	if (rotaionhead2 < 0) {
		rotaionhead2 = 0;
		rotaionhead2s = 0.0f;
	}
	if (rotationhandleft < 0) {
		rotationhandleft = 0;
		rotationhandlefts = 0.0f;
	}
	if (rotationhandleft2 < 0) {
		rotationhandleft2 = 0;
		rotationhandleft2s = 0.0f;
	}
	if (rotationhandleft3 < 0) {
		rotationhandleft3 = 0;
		rotationhandleft3s = 0.0f;
	}
	if (rotationhandleft4 < 0) {
		rotationhandleft4 = 0;
		rotationhandleft4s = 0.0f;
	}
	if (rotationhandright > 0) {
		rotationhandright = 0;
		rotationhandrights = 0.0f;
	}
	if (rotationhandright2 > 0) {
		rotationhandright2 = 0;
		rotationhandright2s = 0.0f;
	}
	if (rotationhandright3 > 0) {
		rotationhandright3 = 0;
		rotationhandright3s = 0.0f;
	}*/
}

void head()
{
	//face1--------------------------------------------------------------
	glPushMatrix();

	glTranslatef(0.0f, 0.10f, 0.06f);

	if (rotationfacea >= 75) {
		rotationfacea = 75;
	}

	if (rotationfacea < 0) {
		rotationfacea = 0;
	}

	rotationfacea += rotationSpeedfacea;
	glRotatef(rotationfacea, 1.0f, 0.0f, 0.0f);

	glTranslatef(0.0f, -0.10f, -0.06f);

	glPushMatrix();


	glBegin(GL_QUADS);//eye

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.05f, 0.00f, 0.04f);
	glVertex3f(0.05f, 0.00f, 0.04f);
	glVertex3f(0.05f, 0.1f, 0.06f);
	glVertex3f(-0.05f, 0.1f, 0.06f);
	glEnd();

	glBegin(GL_QUADS);//left left eye shadow

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.045f, 0.01f, 0.04f);
	glVertex3f(-0.045f, 0.09f, 0.06f);
	glVertex3f(-0.055f, 0.09f, 0.06f);
	glVertex3f(-0.054f, 0.09f, 0.04f);
	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.02f, 0.00f, 0.06f);
	glVertex3f(-0.05f, 0.00f, 0.04f);
	glVertex3f(-0.06f, 0.07f, 0.05f);
	glVertex3f(-0.02f, 0.06f, 0.08f);
	glEnd();

	glBegin(GL_QUADS);//mid

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.02f, 0.00f, 0.06f);
	glVertex3f(0.02f, 0.00f, 0.06f);
	glVertex3f(0.02f, 0.06f, 0.08f);
	glVertex3f(-0.02f, 0.06f, 0.08f);
	glEnd();

	glBegin(GL_QUADS);//right right eye shadow

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.045f, 0.01f, 0.04f);
	glVertex3f(0.045f, 0.09f, 0.06f);
	glVertex3f(0.055f, 0.09f, 0.06f);
	glVertex3f(0.054f, 0.09f, 0.04f);
	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.02f, 0.00f, 0.06f);
	glVertex3f(0.05f, 0.00f, 0.04f);
	glVertex3f(0.06f, 0.07f, 0.05f);
	glVertex3f(0.02f, 0.06f, 0.08f);
	glEnd();

	glBegin(GL_QUADS);//up

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.02f, 0.06f, 0.08f);
	glVertex3f(-0.06f, 0.07f, 0.05f);
	glVertex3f(0.06f, 0.07f, 0.05f);
	glVertex3f(0.02f, 0.06f, 0.08f);
	glEnd();


	glBegin(GL_QUADS);//down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.02f, 0.00f, 0.06f);
	glVertex3f(-0.05f, 0.00f, 0.04f);
	glVertex3f(0.05f, 0.00f, 0.04f);
	glVertex3f(0.02f, 0.00f, 0.06f);
	glEnd();

	glPopMatrix();
	glPopMatrix();

	//face2--------------------------------------------------------------

	glPushMatrix();

	glTranslatef(0.0f, 0.10f, 0.06f);

	if (rotationfaceb >= 75) {
		rotationfaceb = 75;
	}

	if (rotationfaceb < 0) {
		rotationfaceb = 0;
	}

	rotationfaceb += rotationSpeedfaceb;
	glRotatef(rotationfaceb, 1.0f, 0.0f, 0.0f);

	glTranslatef(0.0f, -0.10f, -0.06f);

	glBegin(GL_QUADS);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.01f, 0.0375f, 0.075f);
	glVertex3f(0.01f, 0.0375f, 0.075f);
	glVertex3f(0.01f, 0.035f, 0.075f);
	glVertex3f(-0.01f, 0.035f, 0.075f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.01f, 0.0425f, 0.077f);
	glVertex3f(0.01f, 0.0425f, 0.077f);
	glVertex3f(0.01f, 0.040f, 0.077f);
	glVertex3f(-0.01f, 0.040f, 0.077f);

	glEnd();

	glPushMatrix();

	glBegin(GL_QUADS);//down

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.01f, 0.00f, 0.06f);
	glVertex3f(-0.04f, 0.00f, 0.04f);
	glVertex3f(0.04f, 0.00f, 0.04f);
	glVertex3f(0.01f, 0.00f, 0.06f);
	glEnd();

	glBegin(GL_QUADS);//left eye shadow

	glColor3f(0.8f, 0.1f, 0.1f);
	glVertex3f(-0.0f, 0.00f, 0.04f);
	glVertex3f(-0.04f, 0.00f, 0.04f);
	glVertex3f(-0.05f, 0.1f, 0.06f);
	glVertex3f(-0.0f, 0.1f, 0.08f);
	glEnd();

	glBegin(GL_QUADS);//left left eye shadow

	glColor3f(0.8f, 0.1f, 0.1f);
	glVertex3f(-0.04f, 0.00f, 0.04f);
	glVertex3f(-0.045f, 0.09f, 0.06f);
	glVertex3f(-0.045f, 0.09f, 0.04f);
	glVertex3f(-0.045f, 0.09f, 0.04f);
	glEnd();

	glBegin(GL_POLYGON);//left eye 

	glColor3f(color2r, color2g, color2b);

	glVertex3f(-0.04f, 0.067f, 0.06f);//left down
	glVertex3f(-0.03f, 0.060f, 0.065f);//left down
	glVertex3f(-0.02f, 0.062f, 0.065f);//right down
	glVertex3f(-0.02f, 0.068f, 0.07f);//right up
	glVertex3f(-0.04f, 0.073f, 0.06f);//left up
	glEnd();

	glBegin(GL_QUADS);//right eye shadow

	glColor3f(0.8f, 0.1f, 0.1f);
	glVertex3f(0.0f, 0.00f, 0.04f);
	glVertex3f(0.04f, 0.00f, 0.04f);
	glVertex3f(0.05f, 0.1f, 0.06f);
	glVertex3f(0.0f, 0.1f, 0.08f);
	glEnd();

	glBegin(GL_QUADS);//right right eye shadow

	glColor3f(0.8f, 0.1f, 0.1f);
	glVertex3f(0.04f, 0.00f, 0.04f);
	glVertex3f(0.045f, 0.09f, 0.06f);
	glVertex3f(0.045f, 0.09f, 0.04f);
	glVertex3f(0.045f, 0.09f, 0.04f);
	glEnd();

	glBegin(GL_POLYGON);//right eye 

	glColor3f(color2r, color2g, color2b);

	glVertex3f(0.04f, 0.067f, 0.06f);//left down
	glVertex3f(0.03f, 0.060f, 0.065f);//left down
	glVertex3f(0.02f, 0.062f, 0.065f);//right down
	glVertex3f(0.02f, 0.068f, 0.07f);//right up
	glVertex3f(0.04f, 0.073f, 0.06f);//left up
	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.01f, 0.00f, 0.06f);
	glVertex3f(-0.04f, 0.00f, 0.04f);
	glVertex3f(-0.05f, 0.06f, 0.05f);
	glVertex3f(-0.01f, 0.05f, 0.08f);
	glEnd();

	glBegin(GL_QUADS);//mid

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.01f, 0.00f, 0.06f);
	glVertex3f(0.01f, 0.00f, 0.06f);
	glVertex3f(0.01f, 0.05f, 0.08f);
	glVertex3f(-0.01f, 0.05f, 0.08f);
	glEnd();

	glBegin(GL_QUADS);//mouth back

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.01f, -0.01f, 0.05f);
	glVertex3f(0.01f, -0.01f, 0.05f);
	glVertex3f(0.01f, 0.02f, 0.07f);
	glVertex3f(-0.01f, 0.02f, 0.07f);
	glEnd();

	glBegin(GL_QUADS);//mouth front

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.01f, -0.01f, 0.08f);
	glVertex3f(0.01f, -0.01f, 0.08f);
	glVertex3f(0.01f, 0.02f, 0.08f);
	glVertex3f(-0.01f, 0.02f, 0.08f);
	glEnd();

	glBegin(GL_QUADS);//mouth left

	glColor3f(0.9f, 0.0f, 0.0f);
	glVertex3f(-0.01f, -0.01f, 0.05f);
	glVertex3f(-0.01f, -0.01f, 0.08f);
	glVertex3f(-0.01f, 0.02f, 0.08f);
	glVertex3f(-0.01f, 0.02f, 0.07f);
	glEnd();

	glBegin(GL_QUADS);//mouth right

	glColor3f(0.9f, 0.0f, 0.0f);
	glVertex3f(0.01f, -0.01f, 0.05f);
	glVertex3f(0.01f, -0.01f, 0.08f);
	glVertex3f(0.01f, 0.02f, 0.08f);
	glVertex3f(0.01f, 0.02f, 0.07f);
	glEnd();

	glBegin(GL_QUADS);//mouth up

	glColor3f(0.9f, 0.0f, 0.0f);
	glVertex3f(-0.01f, 0.02f, 0.08f);
	glVertex3f(0.01f, 0.02f, 0.08f);
	glVertex3f(0.01f, 0.02f, 0.07f);
	glVertex3f(-0.01f, 0.02f, 0.07f);

	glEnd();

	glBegin(GL_QUADS);//mouth down

	glColor3f(0.8f, 0.1f, 0.1f);
	glVertex3f(-0.01f, -0.01f, 0.05f);
	glVertex3f(-0.01f, -0.01f, 0.08f);
	glVertex3f(0.01f, -0.01f, 0.08f);
	glVertex3f(0.01f, -0.01f, 0.05f);

	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.01f, 0.00f, 0.06f);
	glVertex3f(0.04f, 0.00f, 0.04f);
	glVertex3f(0.05f, 0.06f, 0.05f);
	glVertex3f(0.01f, 0.05f, 0.08f);
	glEnd();

	glPopMatrix();
	glPopMatrix();

	//back head---------------------------------------------------------
	glPushMatrix();

	//inside
	//middle
	glBegin(GL_QUADS);//front

	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-0.06f, 0.00f, 0.0401f);
	glVertex3f(0.06f, 0.0f, 0.0401f);
	glVertex3f(0.06f, 0.08f, 0.0401f);
	glVertex3f(-0.06f, 0.08f, 0.0401f);
	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.06f, 0.06f, -0.08f);
	glVertex3f(0.06f, 0.06f, -0.08f);
	glVertex3f(0.06f, 0.10f, -0.08f);
	glVertex3f(-0.06f, 0.10f, -0.08f);
	glEnd();

	glBegin(GL_QUADS);//up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.06f, 0.08f, 0.04f);
	glVertex3f(0.06f, 0.08f, 0.04f);
	glVertex3f(0.06f, 0.10f, -0.08f);
	glVertex3f(-0.06f, 0.10f, -0.08f);
	glEnd();

	glBegin(GL_QUADS);//down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.06f, 0.00f, 0.04f);
	glVertex3f(0.06f, 0.0f, 0.04f);
	glVertex3f(0.06f, 0.06f, -0.08f);
	glVertex3f(-0.06f, 0.06f, -0.08f);
	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.06f, 0.00f, 0.04f);
	glVertex3f(-0.06f, 0.08f, 0.04f);
	glVertex3f(-0.06f, 0.10f, -0.08f);
	glVertex3f(-0.06f, 0.06f, -0.08f);
	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.06f, 0.00f, 0.04f);
	glVertex3f(0.06f, 0.08f, 0.04f);
	glVertex3f(0.06f, 0.10f, -0.08f);
	glVertex3f(0.06f, 0.06f, -0.08f);
	glEnd();

	//lower

	glBegin(GL_QUADS);//front

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.06f, 0.00f, 0.04f);
	glVertex3f(0.06f, 0.00f, 0.04f);
	glVertex3f(0.06f, 0.06f, 0.04f);
	glVertex3f(-0.06f, 0.06f, 0.04f);
	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.06f, 0.02f, -0.06f);
	glVertex3f(0.06f, 0.02f, -0.06f);
	glVertex3f(0.06f, 0.06f, -0.06f);
	glVertex3f(-0.06f, 0.06f, -0.06f);
	glEnd();

	glBegin(GL_QUADS);//up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.06f, 0.0f, 0.04f);
	glVertex3f(0.06f, 0.0f, 0.04f);
	glVertex3f(0.06f, 0.06f, -0.06f);
	glVertex3f(-0.06f, 0.06f, -0.06f);
	glEnd();

	glBegin(GL_QUADS);//down

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.06f, 0.00f, 0.04f);
	glVertex3f(0.06f, 0.0f, 0.04f);
	glVertex3f(0.06f, 0.02f, -0.06f);
	glVertex3f(-0.06f, 0.02f, -0.06f);
	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.06f, 0.00f, 0.04f);
	glVertex3f(-0.06f, 0.06f, 0.04f);
	glVertex3f(-0.06f, 0.06f, -0.06f);
	glVertex3f(-0.06f, 0.02f, -0.06f);
	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.06f, 0.00f, 0.04f);
	glVertex3f(0.06f, 0.06f, 0.04f);
	glVertex3f(0.06f, 0.06f, -0.06f);
	glVertex3f(0.06f, 0.02f, -0.06f);
	glEnd();

	//upper
	glBegin(GL_QUADS);//up

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.06f, 0.10f, -0.08f);
	glVertex3f(0.06f, 0.10f, -0.08f);
	glVertex3f(0.00f, 0.12f, -0.05f);
	glVertex3f(0.00f, 0.12f, -0.05f);
	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.06f, 0.10f, -0.08f);
	glVertex3f(0.00f, 0.12f, -0.05f);
	glVertex3f(-0.059f, 0.12f, 0.0f);
	glVertex3f(-0.059f, 0.12f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.06f, 0.10f, -0.08f);
	glVertex3f(0.00f, 0.12f, -0.05f);
	glVertex3f(0.059f, 0.12f, 0.0f);
	glVertex3f(0.059f, 0.12f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);//left left

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.06f, 0.10f, -0.08f);
	glVertex3f(-0.059f, 0.12f, 0.0f);
	glVertex3f(-0.06f, 0.08f, 0.04f);
	glVertex3f(-0.06f, 0.08f, 0.04f);

	glEnd();

	glBegin(GL_QUADS);//right right

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.06f, 0.10f, -0.08f);
	glVertex3f(0.059f, 0.12f, 0.0f);
	glVertex3f(0.06f, 0.08f, 0.04f);
	glVertex3f(0.06f, 0.08f, 0.04f);

	glEnd();

	glPopMatrix();

	//left head---------------------------------------------------------
	glPushMatrix();
	glTranslatef(0.0f, 0.05f, 0.0f);
	rotationheadsidea += rotationheadsidespeed;
	glRotatef(rotationheadsidea, 1.0f, 0.0f, 0.0f);
	if (rotationheadsidea >= 180) {
		rotationheadsidea = 180;
	}

	if (rotationheadsidea < 0) {
		rotationheadsidea = 0;
		rotationheadsidespeed = 0;
	}

	glPushMatrix();
	glTranslatef(0.0f, -0.05f, 0.0f);
	//1

	glLineWidth(1.5);
	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.10f, 0.05f, 0.0f);
	glVertex3f(-0.10f, 0.12f, 0.0f);
	glVertex3f(-0.07f, 0.1f, 0.06f);
	glVertex3f(-0.07f, 0.05f, 0.06f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.07f, 0.0f, 0.06f);
	glVertex3f(-0.07f, 0.05f, 0.06f);
	glVertex3f(-0.10f, 0.05f, 0.0f);
	glVertex3f(-0.10f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.10f, 0.0f, 0.0f);
	glVertex3f(-0.07f, 0.05f, -0.06f);
	glVertex3f(-0.07f, 0.1f, -0.06f);
	glVertex3f(-0.10f, 0.12f, 0.0f);

	glEnd();

	//---------------------------------------------------------

	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.07f, 0.0f, 0.0f);
	glVertex3f(-0.07f, 0.12f, 0.0f);
	glVertex3f(-0.06f, 0.1f, 0.06f);
	glVertex3f(-0.06f, 0.0f, 0.06f);
	glEnd();

	//up cube
	glBegin(GL_QUADS);

	glColor3f(colorr, colorg, colorb);//front

	glVertex3f(-0.06f, 0.05f, 0.06f);
	glVertex3f(-0.06f, 0.1f, 0.06f);
	glVertex3f(-0.07f, 0.1f, 0.06f);
	glVertex3f(-0.07f, 0.05f, 0.06f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.8f, 0.8f, 0.8f);//left

	glVertex3f(-0.10f, 0.05f, 0.0f);
	glVertex3f(-0.10f, 0.12f, 0.0f);
	glVertex3f(-0.07f, 0.1f, 0.06f);
	glVertex3f(-0.07f, 0.05f, 0.06f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.9f, 0.9f, 0.9f);//up

	glVertex3f(-0.06f, 0.1f, 0.06f);
	glVertex3f(-0.07f, 0.1f, 0.06f);
	glVertex3f(-0.10f, 0.12f, 0.0f);
	glVertex3f(-0.07f, 0.12f, 0.0f);

	glEnd();

	//down cube

	glBegin(GL_QUADS);

	glColor3f(colorr, colorg, colorb);//front

	glVertex3f(-0.06f, 0.0f, 0.06f);
	glVertex3f(-0.07f, 0.0f, 0.06f);
	glVertex3f(-0.07f, 0.05f, 0.06f);
	glVertex3f(-0.06f, 0.05f, 0.06f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.9f, 0.9f, 0.9f);//left

	glVertex3f(-0.07f, 0.0f, 0.06f);
	glVertex3f(-0.07f, 0.05f, 0.06f);
	glVertex3f(-0.10f, 0.05f, 0.0f);
	glVertex3f(-0.10f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.9f, 0.9f, 0.9f);//down

	glVertex3f(-0.06f, 0.0f, 0.06f);
	glVertex3f(-0.07f, 0.0f, 0.06f);
	glVertex3f(-0.10f, 0.0f, 0.0f);
	glVertex3f(-0.07f, 0.0f, 0.0f);

	glEnd();


	//2
	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.07f, 0.0f, 0.0f);
	glVertex3f(-0.06f, 0.05f, -0.06f);
	glVertex3f(-0.06f, 0.1f, -0.06f);
	glVertex3f(-0.07f, 0.12f, 0.0f);
	glEnd();

	//back cube

	glBegin(GL_QUADS);

	glColor3f(0.9f, 0.9f, 0.9f);//up
	glVertex3f(-0.07f, 0.12f, 0.0f);
	glVertex3f(-0.06f, 0.1f, -0.06f);
	glVertex3f(-0.07f, 0.1f, -0.06f);
	glVertex3f(-0.10f, 0.12f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.9f, 0.9f, 0.9f);//down
	glVertex3f(-0.07f, 0.0f, 0.0f);
	glVertex3f(-0.06f, 0.05f, -0.06f);
	glVertex3f(-0.07f, 0.05f, -0.06f);
	glVertex3f(-0.10f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(colorr, colorg, colorb);//back
	glVertex3f(-0.06f, 0.1f, -0.06f);
	glVertex3f(-0.06f, 0.05f, -0.06f);
	glVertex3f(-0.07f, 0.05f, -0.06f);
	glVertex3f(-0.07f, 0.1f, -0.06f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);//left

	glVertex3f(-0.10f, 0.0f, 0.0f);
	glVertex3f(-0.07f, 0.05f, -0.06f);
	glVertex3f(-0.07f, 0.1f, -0.06f);
	glVertex3f(-0.10f, 0.12f, 0.0f);

	glEnd();

	glPopMatrix();
	glPopMatrix();

	//right head---------------------------------------------------------
	glPushMatrix();
	glTranslatef(0.0f, 0.05f, 0.0f);
	rotationheadsideb += rotationheadsidespeed;
	glRotatef(rotationheadsideb, 1.0f, 0.0f, 0.0f);

	if (rotationheadsideb >= 180) {
		rotationheadsideb = 180;
	}

	if (rotationheadsideb < 0) {
		rotationheadsideb = 0;
		rotationheadsidespeed = 0;
	}
	glPushMatrix();
	glTranslatef(0.0f, -0.05f, 0.0f);

	glLineWidth(1.5);
	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.10f, 0.05f, 0.0f);
	glVertex3f(0.10f, 0.12f, 0.0f);
	glVertex3f(0.07f, 0.1f, 0.06f);
	glVertex3f(0.07f, 0.05f, 0.06f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.07f, 0.0f, 0.06f);
	glVertex3f(0.07f, 0.05f, 0.06f);
	glVertex3f(0.10f, 0.05f, 0.0f);
	glVertex3f(0.10f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.10f, 0.0f, 0.0f);
	glVertex3f(0.07f, 0.05f, -0.06f);
	glVertex3f(0.07f, 0.1f, -0.06f);
	glVertex3f(0.10f, 0.12f, 0.0f);

	glEnd();

	//--------------------------------------------
	//1
	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.07f, 0.0f, 0.0f);
	glVertex3f(0.07f, 0.12f, 0.0f);
	glVertex3f(0.06f, 0.1f, 0.06f);
	glVertex3f(0.06f, 0.0f, 0.06f);
	glEnd();

	//up cube
	glBegin(GL_QUADS);

	glColor3f(colorr, colorg, colorb);//front

	glVertex3f(0.06f, 0.05f, 0.06f);
	glVertex3f(0.06f, 0.1f, 0.06f);
	glVertex3f(0.07f, 0.1f, 0.06f);
	glVertex3f(0.07f, 0.05f, 0.06f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.8f, 0.8f, 0.8f);//left

	glVertex3f(0.10f, 0.05f, 0.0f);
	glVertex3f(0.10f, 0.12f, 0.0f);
	glVertex3f(0.07f, 0.1f, 0.06f);
	glVertex3f(0.07f, 0.05f, 0.06f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.9f, 0.9f, 0.9f);//up

	glVertex3f(0.06f, 0.1f, 0.06f);
	glVertex3f(0.07f, 0.1f, 0.06f);
	glVertex3f(0.10f, 0.12f, 0.0f);
	glVertex3f(0.07f, 0.12f, 0.0f);

	glEnd();

	//down cube

	glBegin(GL_QUADS);

	glColor3f(colorr, colorg, colorb);//front

	glVertex3f(0.06f, 0.0f, 0.06f);
	glVertex3f(0.07f, 0.0f, 0.06f);
	glVertex3f(0.07f, 0.05f, 0.06f);
	glVertex3f(0.06f, 0.05f, 0.06f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.9f, 0.9f, 0.9f);//left

	glVertex3f(0.07f, 0.0f, 0.06f);
	glVertex3f(0.07f, 0.05f, 0.06f);
	glVertex3f(0.10f, 0.05f, 0.0f);
	glVertex3f(0.10f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.9f, 0.9f, 0.9f);//down

	glVertex3f(0.06f, 0.0f, 0.06f);
	glVertex3f(0.07f, 0.0f, 0.06f);
	glVertex3f(0.10f, 0.0f, 0.0f);
	glVertex3f(0.07f, 0.0f, 0.0f);

	glEnd();


	//2
	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.07f, 0.0f, 0.0f);
	glVertex3f(0.06f, 0.05f, -0.06f);
	glVertex3f(0.06f, 0.1f, -0.06f);
	glVertex3f(0.07f, 0.12f, 0.0f);
	glEnd();

	//back cube

	glBegin(GL_QUADS);

	glColor3f(0.9f, 0.9f, 0.9f);//up
	glVertex3f(0.07f, 0.12f, 0.0f);
	glVertex3f(0.06f, 0.1f, -0.06f);
	glVertex3f(0.07f, 0.1f, -0.06f);
	glVertex3f(0.10f, 0.12f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.9f, 0.9f, 0.9f);//down
	glVertex3f(0.07f, 0.0f, 0.0f);
	glVertex3f(0.06f, 0.05f, -0.06f);
	glVertex3f(0.07f, 0.05f, -0.06f);
	glVertex3f(0.10f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(colorr, colorg, colorb);//back
	glVertex3f(0.06f, 0.1f, -0.06f);
	glVertex3f(0.06f, 0.05f, -0.06f);
	glVertex3f(0.07f, 0.05f, -0.06f);
	glVertex3f(0.07f, 0.1f, -0.06f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);//left

	glVertex3f(0.10f, 0.0f, 0.0f);
	glVertex3f(0.07f, 0.05f, -0.06f);
	glVertex3f(0.07f, 0.1f, -0.06f);
	glVertex3f(0.10f, 0.12f, 0.0f);

	glEnd();

	glPopMatrix();
	glPopMatrix();

	//helmet---------------------------------------------------------
	glPushMatrix();

	glTranslatef(0.0f, 0.0f, -0.01f);
	glRotatef(20, 1.0f, 0.0f, 0.0f);
	glRotatef(-45, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.1f, -0.0f);

	glPushMatrix();
	glTranslatef(0.0f, 0.025f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	gluSphere(headtop, 0.05, 10, 10);
	glPopMatrix();

	glBegin(GL_QUADS);//0

	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(0.0f, 0.0f, 0.075f);
	glVertex3f(0.06f, 0.0f, 0.06f);
	glVertex3f(0.075f, 0.0f, 0.00f);
	glVertex3f(0.00f, -0.015f, 0.00f);

	glEnd();

	glBegin(GL_QUADS);//0 left

	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-0.06f, 0.0f, 0.06f);
	glVertex3f(0.0f, 0.0f, 0.075f);
	glVertex3f(0.06f, 0.0f, 0.06f);
	glVertex3f(0.00f, -0.015f, 0.00f);//inside

	glEnd();

	glBegin(GL_QUADS);//0 left

	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(0.06f, 0.0f, 0.06f);
	glVertex3f(0.075f, 0.0f, 0.0f);
	glVertex3f(0.06f, 0.0f, -0.06f);
	glVertex3f(0.00f, -0.015f, 0.00f);//inside

	glEnd();

	glBegin(GL_QUADS);//1

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.0f, 0.0f, 0.075f);
	glVertex3f(0.06f, 0.0f, 0.06f);
	glVertex3f(0.03f, 0.05f, 0.03f);
	glVertex3f(0.0f, 0.05f, 0.04f);

	glEnd();

	glBegin(GL_QUADS);//2

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.06f, 0.0f, 0.06f);
	glVertex3f(0.075f, 0.0f, 0.0f);
	glVertex3f(0.04f, 0.05f, 0.0f);
	glVertex3f(0.03f, 0.05f, 0.03f);

	glEnd();

	glBegin(GL_QUADS);//3

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.075f, 0.0f, 0.0f);
	glVertex3f(0.06f, 0.0f, -0.06f);
	glVertex3f(0.03f, 0.05f, -0.03f);
	glVertex3f(0.04f, 0.05f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);//4

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.06f, 0.0f, -0.06f);
	glVertex3f(0.0f, 0.0f, -0.075f);
	glVertex3f(0.0f, 0.05f, -0.04f);
	glVertex3f(0.03f, 0.05f, -0.03f);

	glEnd();

	glBegin(GL_QUADS);//5

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, -0.075f);
	glVertex3f(-0.06f, 0.0f, -0.06f);
	glVertex3f(-0.03f, 0.05f, -0.03f);
	glVertex3f(0.0f, 0.05f, -0.04f);

	glEnd();

	glBegin(GL_QUADS);//6

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.06f, 0.0f, -0.06f);
	glVertex3f(-0.075f, 0.0f, 0.0f);
	glVertex3f(-0.04f, 0.05f, 0.0f);
	glVertex3f(-0.03f, 0.05f, -0.03f);

	glEnd();

	glBegin(GL_QUADS);//7

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.075f, 0.0f, 0.0f);
	glVertex3f(-0.06f, 0.0f, 0.06f);
	glVertex3f(-0.03f, 0.05f, 0.03f);
	glVertex3f(-0.04f, 0.05f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);//8

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.06f, 0.0f, 0.06f);
	glVertex3f(0.0f, 0.0f, 0.075f);
	glVertex3f(0.0f, 0.05f, 0.04f);
	glVertex3f(-0.03f, 0.05f, 0.03f);

	glEnd();

	glPopMatrix();

	//head top---------------------------------------------------------
	glPushMatrix();

	//0

	glPushMatrix();

	glBegin(GL_QUADS);//down left

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.015f, 0.072f, 0.10f);
	glVertex3f(0.000f, 0.065f, 0.105f);
	glVertex3f(0.000f, 0.075f, 0.118f);
	glVertex3f(-0.010f, 0.08f, 0.118f);

	glEnd();

	glBegin(GL_QUADS);//down right

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(0.015f, 0.072f, 0.10f);
	glVertex3f(0.000f, 0.065f, 0.105f);
	glVertex3f(0.000f, 0.075f, 0.118f);
	glVertex3f(0.010f, 0.08f, 0.118f);

	glEnd();

	glBegin(GL_QUADS);//up

	glColor3f(0.95f, 0.95f, 0.95f);
	glVertex3f(-0.015f, 0.09f, 0.09f);
	glVertex3f(0.015f, 0.09f, 0.09f);
	glVertex3f(0.010f, 0.095f, 0.118f);
	glVertex3f(-0.010f, 0.095f, 0.118f);

	glEnd();

	glBegin(GL_POLYGON);//front

	glColor3f(0.95f, 0.95f, 0.95f);
	glVertex3f(-0.01f, 0.08f, 0.118f);
	glVertex3f(0.000f, 0.065f, 0.105f);
	glVertex3f(0.01f, 0.08f, 0.118f);
	glVertex3f(0.01f, 0.095f, 0.118f);
	glVertex3f(-0.01f, 0.095f, 0.118f);

	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.01f, 0.095f, 0.118f);
	glVertex3f(-0.01f, 0.08f, 0.118f);
	glVertex3f(-0.015f, 0.072f, 0.10f);
	glVertex3f(-0.015f, 0.09f, 0.09f);
	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.01f, 0.095f, 0.118f);
	glVertex3f(0.01f, 0.08f, 0.118f);
	glVertex3f(0.015f, 0.072f, 0.10f);
	glVertex3f(0.015f, 0.09f, 0.09f);
	glEnd();

	//1
	glPushMatrix();
	glBegin(GL_QUADS);//front

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.015f, 0.14f, 0.075f);
	glVertex3f(0.015f, 0.14f, 0.075f);
	glVertex3f(0.01f, 0.18f, 0.1f);
	glVertex3f(-0.01f, 0.18f, 0.1f);

	glEnd();

	glPushMatrix();
	glBegin(GL_QUADS);//front

	glColor3f(color2r, color2g, color2b);
	glVertex3f(-0.015f, 0.14f, 0.0751f);
	glVertex3f(0.015f, 0.14f, 0.0751f);
	glVertex3f(0.008f, 0.16f, 0.0876f);
	glVertex3f(-0.008f, 0.16f, 0.0876f);

	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.015f, 0.165f, 0.02f);
	glVertex3f(0.015f, 0.165f, 0.02f);
	glVertex3f(0.015f, 0.205f, 0.045f);
	glVertex3f(-0.015f, 0.205f, 0.045f);

	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.015f, 0.165f, 0.02f);
	glVertex3f(-0.015f, 0.14f, 0.075f);
	glVertex3f(-0.01f, 0.18f, 0.1f);
	glVertex3f(-0.015f, 0.205f, 0.045f);
	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.015f, 0.14f, 0.075f);
	glVertex3f(0.015f, 0.165f, 0.02f);
	glVertex3f(0.015f, 0.205f, 0.045f);
	glVertex3f(0.01f, 0.18f, 0.1f);
	glColor3f(0.0f, 0.0f, 1.0f);

	glBegin(GL_QUADS);//up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.01f, 0.18f, 0.1f);
	glVertex3f(0.01f, 0.18f, 0.1f);
	glVertex3f(0.015f, 0.205f, 0.045f);
	glVertex3f(-0.015f, 0.205f, 0.045f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//2

	glBegin(GL_QUADS);//up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.015f, 0.205f, 0.045f);
	glVertex3f(0.015f, 0.205f, 0.045f);
	glVertex3f(0.015f, 0.205f, -0.005f);
	glVertex3f(-0.015f, 0.205f, -0.005f);
	glEnd();

	glBegin(GL_QUADS);//front

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.015f, 0.16f, 0.02f);
	glVertex3f(0.015f, 0.16f, 0.02f);
	glVertex3f(0.015f, 0.205f, 0.045f);
	glVertex3f(-0.015f, 0.205f, 0.045f);

	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.015f, 0.16f, 0.02f);
	glVertex3f(0.015f, 0.16f, 0.02f);
	glVertex3f(0.015f, 0.205f, -0.005f);
	glVertex3f(-0.015f, 0.205f, -0.005f);

	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.015f, 0.205f, 0.045f);
	glVertex3f(-0.015f, 0.205f, -0.005f);
	glVertex3f(-0.015f, 0.16f, 0.02f);
	glVertex3f(-0.015f, 0.16f, 0.02f);
	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.015f, 0.205f, -0.005f);
	glVertex3f(0.015f, 0.205f, 0.045f);
	glVertex3f(0.015f, 0.16f, 0.02f);
	glVertex3f(0.015f, 0.16f, 0.02f);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	//3
	glLineWidth(1.5);
	glBegin(GL_LINE_LOOP);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.015f, 0.16f, 0.02f);
	glVertex3f(-0.015f, 0.205f, -0.005f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.015f, 0.16f, 0.02f);
	glVertex3f(0.015f, 0.205f, -0.005f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.015f, 0.205f, -0.005f);
	glVertex3f(0.015f, 0.205f, -0.005f);

	glEnd();

	glBegin(GL_QUADS);//front

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.015f, 0.16f, 0.02f);
	glVertex3f(0.015f, 0.16f, 0.02f);
	glVertex3f(0.015f, 0.205f, -0.005f);
	glVertex3f(-0.015f, 0.205f, -0.005f);

	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.015f, 0.12f, -0.05f);
	glVertex3f(0.015f, 0.12f, -0.05f);
	glVertex3f(0.010f, 0.15f, -0.080f);
	glVertex3f(-0.010f, 0.15f, -0.080f);

	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(color2r, color2g, color2b);
	glVertex3f(-0.0075f, 0.12f, -0.053f);
	glVertex3f(0.0075f, 0.12f, -0.053f);
	glVertex3f(0.005f, 0.135f, -0.067f);
	glVertex3f(-0.005f, 0.135f, -0.067f);

	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.015f, 0.16f, 0.02f);
	glVertex3f(-0.015f, 0.205f, -0.005f);
	glVertex3f(-0.010f, 0.15f, -0.080f);
	glVertex3f(-0.015f, 0.12f, -0.05f);
	glEnd();


	glBegin(GL_QUADS);//right

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.015f, 0.205f, -0.005f);
	glVertex3f(0.015f, 0.16f, 0.02f);
	glVertex3f(0.015f, 0.12f, -0.05f);
	glVertex3f(0.010f, 0.15f, -0.080f);
	glEnd();

	glBegin(GL_QUADS);//top

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.015f, 0.205f, -0.005f);
	glVertex3f(0.015f, 0.205f, -0.005f);
	glVertex3f(0.010f, 0.15f, -0.080f);
	glVertex3f(-0.010f, 0.15f, -0.080f);

	glEnd();

	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	//horn part---------------------------------------------------------
	glPushMatrix();


	glTranslatef(0.0f, 0.12f, 0.095f);
	glRotatef(-10, 1.0f, 0.0f, 0.0f);

	//head middle horn

	glBegin(GL_QUADS);//front left
	glColor3f(0.15f, 0.15f, 0.15f);

	glVertex3f(0.0f, -.02f, .015f);
	glVertex3f(.015f, -.01f, .015f);
	glVertex3f(.015f, .02f, .010f);
	glVertex3f(0.0f, .02f, .010f);

	glEnd();

	glBegin(GL_QUADS);//front right
	glColor3f(0.15f, 0.15f, 0.15f);

	glVertex3f(0.0f, -.02f, .015f);
	glVertex3f(-.015f, -.01f, .015f);
	glVertex3f(-.015f, .02f, .010f);
	glVertex3f(0.0f, .02f, .010f);

	glEnd();

	glBegin(GL_QUADS);//back left
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex3f(0.0f, -.02f, -.015f);
	glVertex3f(.015f, -.01f, -.015f);
	glVertex3f(.015f, .02f, -.010f);
	glVertex3f(0.0f, .02f, -.010f);

	glEnd();

	glBegin(GL_QUADS);//back right
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(0.0f, -.02f, -.015f);
	glVertex3f(-.015f, -.01f, -.015f);
	glVertex3f(-.015f, .02f, -.010f);
	glVertex3f(0.0f, .02f, -.010f);

	glEnd();

	glBegin(GL_QUADS);//left
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(-.015f, -.01f, .015f);
	glVertex3f(-.015f, -.02f, -.015f);
	glVertex3f(-.015f, .02f, -.015f);
	glVertex3f(-.015f, .02f, .010f);

	glEnd();

	glBegin(GL_QUADS);//right
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(.015f, -.01f, .015f);
	glVertex3f(.015f, -.02f, -.015f);
	glVertex3f(.015f, .02f, -.015f);
	glVertex3f(.015f, .02f, .010f);

	glEnd();

	glBegin(GL_QUADS);//up
	glColor3f(0.0f, 0.0f, 0.0f);


	glVertex3f(.015f, .02f, .010f);
	glVertex3f(-.015f, .02f, .010f);
	glVertex3f(-.015f, .02f, -.015f);
	glVertex3f(.015f, .02f, -.015f);

	glEnd();

	glBegin(GL_QUADS);//bottom left
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(0.0f, -.02f, .015f);
	glVertex3f(-.015f, -.01f, .015f);
	glVertex3f(-.015f, -.02f, -.015f);
	glVertex3f(0.0f, -.026f, -.015f);

	glEnd();

	glBegin(GL_QUADS);//bottom right
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(0.0f, -.02f, .015f);
	glVertex3f(.015f, -.01f, .015f);
	glVertex3f(.015f, -.02f, -.015f);
	glVertex3f(0.0f, -.026f, -.015f);

	glEnd();

	glTranslatef(0.0f, 0.0f, -0.005f);

	//head left horn

	glPushMatrix();
	rotationhorna -= rotationSpeedhorn;
	glRotatef(rotationhorna, 0.0f, 1.0f, 0.0f);

	if (rotationhorna <= -90) {
		rotationhorna = -90;
		rotationSpeedhorn = 0;
	}

	if (rotationhorna > 0) {
		rotationhorna = 0;
		rotationSpeedhorn = 0;
	}

	glLineWidth(1.5);
	glBegin(GL_LINE_LOOP);

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-.0f, .18f, .18f);
	glVertex3f(-.01f, .0f, .02f);
	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-.01f, .0f, .02f);
	glVertex3f(-.0f, -.02f, .025f);
	glEnd();



	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-.0f, -.02f, .025f);
	glVertex3f(-.0f, -.02f, .015f);
	glVertex3f(-.0f, .02f, .015f);
	glVertex3f(-.0f, .18f, .18f);

	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-.0f, .02f, .015f);
	glVertex3f(-.01f, .0f, .02f);
	glVertex3f(-.0f, .18f, .18f);
	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-.01f, .0f, .02f);
	glVertex3f(-.0f, -.02f, .025f);
	glVertex3f(-.0f, .18f, .18f);
	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-.01f, .0f, .02f);
	glVertex3f(-.0f, -.02f, .025f);
	glVertex3f(-.0f, -.02f, .015f);
	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-.01f, .0f, .02f);
	glVertex3f(-.0f, -.02f, .015f);
	glVertex3f(-.0f, .02f, .015f);
	glEnd();

	glPopMatrix();


	//head right horn
	glPushMatrix();
	rotationhornb += rotationSpeedhorn;
	glRotatef(rotationhornb, 0.0f, 1.0f, 0.0f);

	if (rotationhornb >= 90) {
		rotationhornb = 90;
		rotationSpeedhorn = 0;
	}

	if (rotationhornb < 0) {
		rotationhornb = 0;
		rotationSpeedhorn = 0;
	}

	glBegin(GL_LINE_LOOP);

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(.0f, .18f, .18f);
	glVertex3f(.01f, .0f, .02f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(.0f, -.02f, .025f);
	glVertex3f(.01f, .0f, .02f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(.0f, -.02f, .025f);
	glVertex3f(.0f, -.02f, .015f);
	glVertex3f(.0f, .02f, .015f);
	glVertex3f(.0f, .18f, .18f);

	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(.0f, .02f, .015f);
	glVertex3f(.01f, .0f, .02f);
	glVertex3f(.0f, .18f, .18f);
	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(.01f, .0f, .02f);
	glVertex3f(.0f, -.02f, .025f);
	glVertex3f(.0f, .18f, .18f);
	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(.01f, .0f, .02f);
	glVertex3f(.0f, -.02f, .025f);
	glVertex3f(.0f, -.02f, .015f);
	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(.01f, .0f, .02f);
	glVertex3f(.0f, -.02f, .015f);
	glVertex3f(.0f, .02f, .015f);
	glEnd();

	glPopMatrix();
	glPopMatrix();
}

void waist()
{

	glPushMatrix();

	glLineWidth(1.5);
	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.05f, 0.1f, 0.1275f);
	glVertex3f(-0.05f, 0.1f, 0.1275f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.05f, 0.1f, 0.1275f);
	glVertex3f(-0.12375f, 0.15f, 0.12125f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.05f, 0.1f, 0.1275f);
	glVertex3f(0.12375f, 0.15f, 0.12125f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.05f, 0.1f, 0.1275f);
	glVertex3f(-0.12375f, 0.15f, 0.12125f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.12379f, 0.15f, 0.12125f);
	glVertex3f(-0.12379f, 0.15f, -0.07075f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.12379f, 0.15f, 0.12125f);
	glVertex3f(0.12379f, 0.15f, -0.07075f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.05f, 0.1f, -0.069f);
	glVertex3f(0.05f, 0.1f, -0.069f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.05f, 0.1f, -0.069f);
	glVertex3f(-0.12375f, 0.15f, -0.07075f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.05f, 0.1f, -0.069f);
	glVertex3f(0.12375f, 0.15f, -0.07075f);

	glEnd();

	glBegin(GL_QUADS);// front mid

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-0.13f, 0.0f, 0.14f);
	glVertex3f(0.13f, 0.0f, 0.14f);
	glVertex3f(0.05f, 0.1f, 0.1275f);
	glVertex3f(-0.05f, 0.1f, 0.1275f);

	glEnd();

	glBegin(GL_QUADS);// front left

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-0.13f, 0.0f, 0.14f);
	glVertex3f(-0.05f, 0.1f, 0.1275f);
	glVertex3f(-0.12375f, 0.15f, 0.12125f);
	glVertex3f(-0.12375f, 0.15f, 0.12125f);

	glEnd();

	glBegin(GL_QUADS);// front right

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(0.13f, 0.0f, 0.14f);
	glVertex3f(0.05f, 0.1f, 0.1275f);
	glVertex3f(0.12375f, 0.15f, 0.12125f);
	glVertex3f(0.12375f, 0.15f, 0.12125f);

	glEnd();

	glBegin(GL_QUADS);// left

	glColor3f(0.45f, 0.45f, 0.45f);
	glVertex3f(-0.13f, 0.0f, -0.08f);
	glVertex3f(-0.13f, 0.0f, 0.14f);
	glVertex3f(-0.12375f, 0.15f, 0.12125f);
	glVertex3f(-0.12375f, 0.15f, -0.07075f);

	glEnd();

	glBegin(GL_QUADS);// right

	glColor3f(0.45f, 0.45f, 0.45f);
	glVertex3f(0.13f, 0.0f, -0.08f);
	glVertex3f(0.13f, 0.0f, 0.14f);
	glVertex3f(0.12375f, 0.15f, 0.12125f);
	glVertex3f(0.12375f, 0.15f, -0.07075f);

	glEnd();

	glBegin(GL_QUADS);// back mid

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(0.13f, 0.0f, -0.08f);
	glVertex3f(-0.13f, 0.0f, -0.08f);
	glVertex3f(-0.05f, 0.1f, -0.069f);
	glVertex3f(0.05f, 0.1f, -0.069f);

	glEnd();

	glBegin(GL_QUADS);// back left

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-0.13f, 0.0f, -0.08f);
	glVertex3f(-0.05f, 0.1f, -0.069f);
	glVertex3f(-0.05f, 0.1f, -0.069f);
	glVertex3f(-0.12375f, 0.15f, -0.07075f);

	glEnd();

	glBegin(GL_QUADS);// back right

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(0.13f, 0.0f, -0.08f);
	glVertex3f(0.05f, 0.1f, -0.069f);
	glVertex3f(0.05f, 0.1f, -0.069f);
	glVertex3f(0.12375f, 0.15f, -0.07075f);

	glEnd();

	glPopMatrix();

}

void body()
{
	//waist lower armor


	//waist upper armor
	glPushMatrix();

	glLineWidth(1.5);
	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.05f, 0.1f, 0.1275f);
	glVertex3f(-0.05f, 0.1f, 0.1275f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.05f, 0.1f, 0.1275f);
	glVertex3f(-0.12375f, 0.15f, 0.12125f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.05f, 0.1f, 0.1275f);
	glVertex3f(0.12375f, 0.15f, 0.12125f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.05f, 0.1f, 0.1275f);
	glVertex3f(-0.12375f, 0.15f, 0.12125f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.12379f, 0.15f, 0.12125f);
	glVertex3f(-0.12379f, 0.15f, -0.07075f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.12379f, 0.15f, 0.12125f);
	glVertex3f(0.12379f, 0.15f, -0.07075f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.05f, 0.1f, -0.069f);
	glVertex3f(0.05f, 0.1f, -0.069f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.05f, 0.1f, -0.069f);
	glVertex3f(-0.12375f, 0.15f, -0.07075f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.05f, 0.1f, -0.069f);
	glVertex3f(0.12375f, 0.15f, -0.07075f);

	glEnd();

	glBegin(GL_QUADS);//left up

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-0.05f, 0.18f, -0.069f);
	glVertex3f(-0.125f, 0.19f, -0.069f);
	glVertex3f(-0.125f, 0.19f, 0.115f);
	glVertex3f(-0.04f, 0.19f, 0.13f);

	glEnd();

	glBegin(GL_QUADS);//right up

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(0.05f, 0.18f, -0.069f);
	glVertex3f(0.125f, 0.19f, -0.069f);
	glVertex3f(0.125f, 0.19f, 0.115f);
	glVertex3f(0.04f, 0.19f, 0.13f);

	glEnd();

	glBegin(GL_QUADS);// up

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-0.125f, 0.19f, -0.069f);
	glVertex3f(0.125f, 0.19f, -0.069f);
	glVertex3f(0.125f, 0.19f, 0.115f);
	glVertex3f(-0.125f, 0.19f, 0.115f);

	glEnd();

	glBegin(GL_QUADS);// left 

	glColor3f(0.45f, 0.45f, 0.45f);
	glVertex3f(-0.125f, 0.19f, -0.069f);
	glVertex3f(-0.125f, 0.19f, 0.115f);
	glVertex3f(-0.12375f, 0.15f, 0.12125f);
	glVertex3f(-0.12375f, 0.15f, -0.07075f);

	glEnd();

	glBegin(GL_QUADS);// front left

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-0.04f, 0.19f, 0.13f);
	glVertex3f(-0.125f, 0.19f, 0.115f);
	glVertex3f(-0.12375f, 0.15f, 0.12125f);
	glVertex3f(-0.05f, 0.1f, 0.1275f);

	glEnd();

	glBegin(GL_QUADS);// back left 

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-0.12375f, 0.15f, -0.07075f);
	glVertex3f(-0.125f, 0.19f, -0.069f);
	glVertex3f(-0.05f, 0.18f, -0.069f);
	glVertex3f(-0.05f, 0.1f, -0.069f);

	glEnd();

	glBegin(GL_QUADS);// right 

	glColor3f(0.45f, 0.45f, 0.45f);
	glVertex3f(0.125f, 0.19f, -0.069f);
	glVertex3f(0.125f, 0.19f, 0.115f);
	glVertex3f(0.12375f, 0.15f, 0.12125f);
	glVertex3f(0.12375f, 0.15f, -0.07075f);

	glEnd();

	glBegin(GL_QUADS);// front right

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(0.04f, 0.19f, 0.13f);
	glVertex3f(0.125f, 0.19f, 0.115f);
	glVertex3f(0.12375f, 0.15f, 0.12125f);
	glVertex3f(0.05f, 0.1f, 0.1275f);

	glEnd();

	glBegin(GL_QUADS);// back right 

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(0.12375f, 0.15f, -0.07075f);
	glVertex3f(0.125f, 0.19f, -0.069f);
	glVertex3f(0.05f, 0.18f, -0.069f);
	glVertex3f(0.05f, 0.1f, -0.069f);

	glEnd();

	glPopMatrix();

	//left bra
	glPushMatrix();

	if (rotationbra >= 100) {
		rotationbra = 100;
	}
	if (rotationbra < 0) {
		rotationbra = 0;
		rotationSpeedbra = 0;
	}

	glTranslatef(-0.0821875f, +0.225f, +0.1348125f);
	glRotatef(-11, 0.0f, 1.0f, 0.0f);
	glRotatef(-6.5, 0.0f, 0.0f, 1.0f);

	rotationbra += rotationSpeedbra;
	glRotatef(rotationbra, 1.0f, 0.0f, 0.0f);

	glRotatef(6.5, 0.0f, 0.0f, 1.0f);
	glRotatef(11, 0.0f, 1.0f, 0.0f);
	glTranslatef(+0.0821875f, -0.225f, -0.1348125f);

	if (rotationbra == 90) {
		glTranslatef(-0.0f, +0.05f, -0.05f);
	}

	glLineWidth(1.5);
	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.1496875f, 0.295f, 0.1448125f);
	glVertex3f(-0.118125f, 0.29f, 0.158f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.118125f, 0.29f, 0.158f);
	glVertex3f(-0.0865625f, 0.285f, 0.1599375f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.1565625f, 0.235f, 0.1194375f);
	glVertex3f(-0.1496875f, 0.295f, 0.1448125f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.0865625f, 0.285f, 0.1599375f);
	glVertex3f(-0.0821875f, 0.225f, 0.1348125f);

	glEnd();

	glBegin(GL_QUADS);//left front down

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.1565625f, 0.235f, 0.1194375f);
	glVertex3f(-0.1496875f, 0.295f, 0.1448125f);
	glVertex3f(-0.0865625f, 0.285f, 0.1599375f);
	glVertex3f(-0.0821875f, 0.225f, 0.1348125f);

	glEnd();

	glBegin(GL_QUADS);//left front down(down 1/4)

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.1565625f, 0.235f, 0.1194375f);
	glVertex3f(-0.1496875f, 0.295f, 0.1448125f);
	glVertex3f(-0.118125f, 0.29f, 0.158f);
	glVertex3f(-0.119375f, 0.23f, 0.133f);

	glEnd();

	glBegin(GL_QUADS);//left front down(down 1/4)

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.119375f, 0.23f, 0.133f);
	glVertex3f(-0.118125f, 0.29f, 0.158f);
	glVertex3f(-0.0865625f, 0.285f, 0.1599375f);
	glVertex3f(-0.0821875f, 0.225f, 0.1348125f);

	glEnd();

	glPopMatrix();

	//right bra
	glPushMatrix();

	if (rotationbra >= 100) {
		rotationbra = 100;
	}
	if (rotationbra < 0) {
		rotationbra = 0;
		rotationSpeedbra = 0;
	}

	glTranslatef(+0.0821875f, +0.225f, +0.1348125f);
	glRotatef(11, 0.0f, 1.0f, 0.0f);
	glRotatef(6.5, 0.0f, 0.0f, 1.0f);

	rotationbra += rotationSpeedbra;
	glRotatef(rotationbra, 1.0f, 0.0f, 0.0f);

	glRotatef(-6.5, 0.0f, 0.0f, 1.0f);
	glRotatef(-11, 0.0f, 1.0f, 0.0f);
	glTranslatef(-0.0821875f, -0.225f, -0.1348125f);

	glLineWidth(1.5);
	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.1496875f, 0.295f, 0.1448125f);
	glVertex3f(0.118125f, 0.29f, 0.158f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.118125f, 0.29f, 0.158f);
	glVertex3f(0.0865625f, 0.285f, 0.1599375f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.1565625f, 0.235f, 0.1194375f);
	glVertex3f(0.1496875f, 0.295f, 0.1448125f);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.0865625f, 0.285f, 0.1599375f);
	glVertex3f(0.0821875f, 0.225f, 0.1348125f);

	glEnd();

	glBegin(GL_QUADS);//left front down

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.1565625f, 0.235f, 0.1194375f);
	glVertex3f(0.1496875f, 0.295f, 0.1448125f);
	glVertex3f(0.0865625f, 0.285f, 0.1599375f);
	glVertex3f(0.0821875f, 0.225f, 0.1348125f);

	glEnd();

	glBegin(GL_QUADS);//left front down(down 1/4)

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.1565625f, 0.235f, 0.1194375f);
	glVertex3f(0.1496875f, 0.295f, 0.1448125f);
	glVertex3f(0.118125f, 0.29f, 0.158f);
	glVertex3f(0.119375f, 0.23f, 0.133f);

	glEnd();

	glBegin(GL_QUADS);//left front down(down 1/4)

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.119375f, 0.23f, 0.133f);
	glVertex3f(0.118125f, 0.29f, 0.158f);
	glVertex3f(0.0865625f, 0.285f, 0.1599375f);
	glVertex3f(0.0821875f, 0.225f, 0.1348125f);

	glEnd();

	glPopMatrix();

	//left armor
	glPushMatrix();

	glLineWidth(1.5);
	glBegin(GL_LINE_LOOP); //front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.110f, 0.39f, 0.090f);
	glVertex3f(-0.090f, 0.315f, 0.173f);

	glEnd();

	glBegin(GL_LINE_LOOP); //front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.110f, 0.39f, 0.090f);
	glVertex3f(-0.082f, 0.39f, 0.090f);
	glVertex3f(-0.06f, 0.31f, 0.180f);
	glVertex3f(-0.090f, 0.315f, 0.173f);

	glEnd();

	glBegin(GL_LINE_LOOP); //front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.100f, 0.36f, 0.122f);
	glVertex3f(-0.123f, 0.37f, 0.110f);

	glEnd();


	glBegin(GL_LINE_LOOP); //front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.105f, 0.39f, 0.090f);
	glVertex3f(-0.125f, 0.39f, 0.090f);

	glEnd();

	glBegin(GL_LINE_LOOP); //front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.123f, 0.37f, 0.110f);
	glVertex3f(-0.125f, 0.39f, 0.090f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.082f, 0.39f, 0.090f);
	glVertex3f(-0.125f, 0.39f, 0.090f);
	glVertex3f(-0.125f, 0.39f, -0.099f);
	glVertex3f(-0.082f, 0.39f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left back

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.125f, 0.39f, -0.099f);
	glVertex3f(-0.080f, 0.39f, -0.099f);
	glVertex3f(-0.05f, 0.25f, -0.099f);
	glVertex3f(-0.125f, 0.27f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left front down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.08875f, 0.315f, 0.1725f);
	glVertex3f(-0.06f, 0.31f, 0.180f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left front down(up)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.14625f, 0.325f, 0.1575f);
	glVertex3f(-0.08875f, 0.315f, 0.1725f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left front down(up)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.1496875f, 0.295f, 0.1448125f);
	glVertex3f(-0.0865625f, 0.285f, 0.1599375f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left front down(up)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.14625f, 0.325f, 0.1575f);
	glVertex3f(-0.1496875f, 0.295f, 0.1448125f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left front down(down)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.1565625f, 0.235f, 0.1194375f);
	glVertex3f(-0.16f, 0.205f, 0.10675f);

	glEnd();

	//--------------------------------------------------
	glBegin(GL_QUADS);//left front up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.110f, 0.39f, 0.090f);
	glVertex3f(-0.082f, 0.39f, 0.090f);
	glVertex3f(-0.06f, 0.31f, 0.180f);
	glVertex3f(-0.090f, 0.315f, 0.173f);

	glEnd();

	glBegin(GL_QUADS);//left front up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.105f, 0.39f, 0.090f);
	glVertex3f(-0.100f, 0.36f, 0.122f);
	glVertex3f(-0.123f, 0.37f, 0.110f);
	glVertex3f(-0.125f, 0.39f, 0.090f);

	glEnd();

	glBegin(GL_QUADS);//left up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.082f, 0.39f, 0.090f);
	glVertex3f(-0.125f, 0.39f, 0.090f);
	glVertex3f(-0.125f, 0.39f, -0.099f);
	glVertex3f(-0.082f, 0.39f, -0.099f);

	glEnd();

	glBegin(GL_QUADS);//left back

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.125f, 0.39f, -0.099f);
	glVertex3f(-0.080f, 0.39f, -0.099f);
	glVertex3f(-0.05f, 0.25f, -0.099f);
	glVertex3f(-0.125f, 0.27f, -0.099f);

	glEnd();

	glBegin(GL_QUADS);//left front down

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.08875f, 0.315f, 0.1725f);
	glVertex3f(-0.06f, 0.31f, 0.180f);
	glVertex3f(-0.04f, 0.19f, 0.13f);
	glVertex3f(-0.08f, 0.195f, 0.12225f);

	glEnd();

	glBegin(GL_QUADS);//left front down(down)

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.1565625f, 0.235f, 0.1194375f);
	glVertex3f(-0.16f, 0.205f, 0.10675f);
	glVertex3f(-0.08f, 0.195f, 0.12225f);
	glVertex3f(-0.0821875f, 0.225f, 0.1348125f);

	glEnd();

	glBegin(GL_QUADS);//left front down(up)

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.14625f, 0.325f, 0.1575f);
	glVertex3f(-0.1496875f, 0.295f, 0.1448125f);
	glVertex3f(-0.0865625f, 0.285f, 0.1599375f);
	glVertex3f(-0.08875f, 0.315f, 0.1725f);

	glEnd();

	glPopMatrix();

	//right armor
	glPushMatrix();

	glLineWidth(1.5);
	glBegin(GL_LINE_LOOP); //front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.110f, 0.39f, 0.090f);
	glVertex3f(0.090f, 0.315f, 0.173f);

	glEnd();

	glBegin(GL_LINE_LOOP); //front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.110f, 0.39f, 0.090f);
	glVertex3f(0.082f, 0.39f, 0.090f);
	glVertex3f(0.06f, 0.31f, 0.180f);
	glVertex3f(0.090f, 0.315f, 0.173f);

	glEnd();

	glBegin(GL_LINE_LOOP); //front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.100f, 0.36f, 0.122f);
	glVertex3f(0.123f, 0.37f, 0.110f);

	glEnd();


	glBegin(GL_LINE_LOOP); //front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.105f, 0.39f, 0.090f);
	glVertex3f(0.125f, 0.39f, 0.090f);

	glEnd();

	glBegin(GL_LINE_LOOP); //front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.123f, 0.37f, 0.110f);
	glVertex3f(0.125f, 0.39f, 0.090f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.082f, 0.39f, 0.090f);
	glVertex3f(0.125f, 0.39f, 0.090f);
	glVertex3f(0.125f, 0.39f, -0.099f);
	glVertex3f(0.082f, 0.39f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right back

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.125f, 0.39f, -0.099f);
	glVertex3f(0.080f, 0.39f, -0.099f);
	glVertex3f(0.05f, 0.25f, -0.099f);
	glVertex3f(0.125f, 0.27f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right front down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.08875f, 0.315f, 0.1725f);
	glVertex3f(0.06f, 0.31f, 0.180f);

	glEnd();


	glBegin(GL_LINE_LOOP);//right front down(up)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.14625f, 0.325f, 0.1575f);
	glVertex3f(0.08875f, 0.315f, 0.1725f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right front down(up)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.1496875f, 0.295f, 0.1448125f);
	glVertex3f(0.0865625f, 0.285f, 0.1599375f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right front down(up)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.14625f, 0.325f, 0.1575f);
	glVertex3f(0.1496875f, 0.295f, 0.1448125f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right front down(down)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.1565625f, 0.235f, 0.1194375f);
	glVertex3f(0.16f, 0.205f, 0.10675f);

	glEnd();


	//-------------------------------------------------

	glBegin(GL_QUADS);//right front up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.110f, 0.39f, 0.090f);
	glVertex3f(0.082f, 0.39f, 0.090f);
	glVertex3f(0.06f, 0.31f, 0.180f);
	glVertex3f(0.090f, 0.315f, 0.173f);

	glEnd();

	glBegin(GL_QUADS);//right front up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.105f, 0.39f, 0.090f);
	glVertex3f(0.100f, 0.36f, 0.122f);
	glVertex3f(0.123f, 0.37f, 0.110f);
	glVertex3f(0.125f, 0.39f, 0.090f);

	glEnd();

	glBegin(GL_QUADS);//right up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.082f, 0.39f, 0.090f);
	glVertex3f(0.125f, 0.39f, 0.090f);
	glVertex3f(0.125f, 0.39f, -0.099f);
	glVertex3f(0.082f, 0.39f, -0.099f);

	glEnd();

	glBegin(GL_QUADS);//right back

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.125f, 0.39f, -0.099f);
	glVertex3f(0.080f, 0.39f, -0.099f);
	glVertex3f(0.05f, 0.25f, -0.099f);
	glVertex3f(0.125f, 0.27f, -0.099f);

	glEnd();

	glBegin(GL_QUADS);//right front down

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.08875f, 0.315f, 0.1725f);
	glVertex3f(0.06f, 0.31f, 0.180f);
	glVertex3f(0.04f, 0.19f, 0.13f);
	glVertex3f(0.08f, 0.195f, 0.12225f);

	glEnd();

	glBegin(GL_QUADS);//right front down(down)

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.1565625f, 0.235f, 0.1194375f);
	glVertex3f(0.16f, 0.205f, 0.10675f);
	glVertex3f(0.08f, 0.195f, 0.12225f);
	glVertex3f(0.0821875f, 0.225f, 0.1348125f);

	glEnd();

	glBegin(GL_QUADS);//right front down(up)

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.14625f, 0.325f, 0.1575f);
	glVertex3f(0.1496875f, 0.295f, 0.1448125f);
	glVertex3f(0.0865625f, 0.285f, 0.1599375f);
	glVertex3f(0.08875f, 0.315f, 0.1725f);

	glEnd();

	glPopMatrix();

	//move left armor
	glPushMatrix();

	if (rotationarmor >= 0.01) {
		rotationarmor = 0.01;
	}

	if (rotationarmor < 0.0) {
		rotationarmor = 0.0;
		rotationSpeedarmor = 0;
	}

	rotationarmor += rotationSpeedarmor;
	glTranslatef(-rotationarmor, rotationarmor / 2, 0.0f);

	glLineWidth(1.5);


	glBegin(GL_LINE_LOOP);//left front down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.175f, 0.33f, 0.15f);
	glVertex3f(-0.14625f, 0.325f, 0.1575f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left front down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.175f, 0.33f, 0.15f);
	glVertex3f(-0.20f, 0.21f, 0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left front down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.14625f, 0.325f, 0.1575f);
	glVertex3f(-0.16f, 0.205f, 0.10675f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left front down(tri)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.04f, 0.19f, 0.13f);
	glVertex3f(-0.125f, 0.19f, 0.115f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left front down(tri)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.20f, 0.21f, 0.099f);
	glVertex3f(-0.125f, 0.19f, 0.115f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.200f, 0.21f, 0.10f);
	glVertex3f(-0.125f, 0.19f, 0.115f);
	glVertex3f(-0.123f, 0.19f, -0.099f);
	glVertex3f(-0.200f, 0.21f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.05f, 0.17f, -0.099f);
	glVertex3f(-0.200f, 0.21f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.05f, 0.17f, -0.069f);
	glVertex3f(-0.05f, 0.17f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.125f, 0.39f, 0.090f);
	glVertex3f(-0.123f, 0.37f, 0.110f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.175f, 0.39f, 0.09f);
	glVertex3f(-0.125f, 0.39f, 0.090f);

	glEnd();


	glBegin(GL_LINE_LOOP);//left front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.175f, 0.33f, 0.15f);
	glVertex3f(-0.175f, 0.39f, 0.09f);

	glEnd();


	glBegin(GL_LINE_LOOP);//left front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.123f, 0.37f, 0.110f);
	glVertex3f(-0.100f, 0.36f, 0.122f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.175f, 0.33f, 0.15f);
	glVertex3f(-0.090f, 0.315f, 0.173f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.100f, 0.36f, 0.122f);
	glVertex3f(-0.090f, 0.315f, 0.173f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.125f, 0.39f, 0.090f);
	glVertex3f(-0.175f, 0.39f, 0.090f);
	glVertex3f(-0.175f, 0.39f, -0.099f);
	glVertex3f(-0.125f, 0.39f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left back

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.125f, 0.39f, -0.099f);
	glVertex3f(-0.125f, 0.27f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left back

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.175f, 0.39f, -0.099f);
	glVertex3f(-0.200f, 0.21f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left back

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.05f, 0.25f, -0.099f);
	glVertex3f(-0.05f, 0.17f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//left back

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.05f, 0.17f, -0.099f);
	glVertex3f(-0.125f, 0.19f, -0.099f);

	glEnd();

	//----------------------------------------------------

	glBegin(GL_QUADS);//left front down

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.175f, 0.33f, 0.15f);
	glVertex3f(-0.14625f, 0.325f, 0.1575f);
	glVertex3f(-0.16f, 0.205f, 0.10675f);
	glVertex3f(-0.20f, 0.21f, 0.099f);

	glEnd();

	glBegin(GL_QUADS);//left front down(tri)

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.04f, 0.19f, 0.13f);
	glVertex3f(-0.20f, 0.21f, 0.099f);
	glVertex3f(-0.125f, 0.19f, 0.115f);
	glVertex3f(-0.125f, 0.19f, 0.115f);

	glEnd();

	glBegin(GL_QUADS);//left down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.200f, 0.21f, 0.10f);
	glVertex3f(-0.125f, 0.19f, 0.115f);
	glVertex3f(-0.123f, 0.19f, -0.099f);
	glVertex3f(-0.200f, 0.21f, -0.099f);

	glEnd();

	glBegin(GL_QUADS);//left down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.200f, 0.21f, -0.069f);
	glVertex3f(-0.05f, 0.17f, -0.069f);
	glVertex3f(-0.05f, 0.17f, -0.099f);
	glVertex3f(-0.200f, 0.21f, -0.099f);

	glEnd();

	glBegin(GL_QUADS);//left front up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.175f, 0.33f, 0.15f);
	glVertex3f(-0.175f, 0.39f, 0.09f);
	glVertex3f(-0.125f, 0.39f, 0.090f);
	glVertex3f(-0.123f, 0.37f, 0.110f);

	glEnd();

	glBegin(GL_QUADS);//left front up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.175f, 0.33f, 0.15f);
	glVertex3f(-0.123f, 0.37f, 0.110f);
	glVertex3f(-0.100f, 0.36f, 0.122f);
	glVertex3f(-0.090f, 0.315f, 0.173f);


	glEnd();

	glBegin(GL_QUADS);//left up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.125f, 0.39f, 0.090f);
	glVertex3f(-0.175f, 0.39f, 0.090f);
	glVertex3f(-0.175f, 0.39f, -0.099f);
	glVertex3f(-0.125f, 0.39f, -0.099f);

	glEnd();

	glBegin(GL_QUADS);//left back

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.175f, 0.39f, -0.099f);
	glVertex3f(-0.125f, 0.39f, -0.099f);
	glVertex3f(-0.125f, 0.19f, -0.099f);
	glVertex3f(-0.200f, 0.21f, -0.099f);

	glEnd();

	glBegin(GL_QUADS);//left back

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.125f, 0.27f, -0.099f);
	glVertex3f(-0.05f, 0.25f, -0.099f);
	glVertex3f(-0.05f, 0.17f, -0.099f);
	glVertex3f(-0.125f, 0.19f, -0.099f);

	glEnd();

	glBegin(GL_POLYGON);//left

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.175f, 0.39f, 0.090f);
	glVertex3f(-0.175f, 0.39f, -0.099f);
	glVertex3f(-0.20f, 0.21f, -0.099f);
	glVertex3f(-0.20f, 0.21f, 0.099f);
	glVertex3f(-0.175f, 0.33f, 0.150f);

	glEnd();

	glPopMatrix();

	//move right armor
	glPushMatrix();

	rotationarmor += rotationSpeedarmor;
	glTranslatef(rotationarmor, rotationarmor / 2, 0.0f);

	glLineWidth(1.5);


	glBegin(GL_LINE_LOOP);//right front down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.175f, 0.33f, 0.15f);
	glVertex3f(0.14625f, 0.325f, 0.1575f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right front down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.175f, 0.33f, 0.15f);
	glVertex3f(0.20f, 0.21f, 0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right front down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.14625f, 0.325f, 0.1575f);
	glVertex3f(0.16f, 0.205f, 0.10675f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right front down(tri)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.04f, 0.19f, 0.13f);
	glVertex3f(0.125f, 0.19f, 0.115f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right front down(tri)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.20f, 0.21f, 0.099f);
	glVertex3f(0.125f, 0.19f, 0.115f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.200f, 0.21f, 0.10f);
	glVertex3f(0.125f, 0.19f, 0.115f);
	glVertex3f(0.123f, 0.19f, -0.099f);
	glVertex3f(0.200f, 0.21f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.05f, 0.17f, -0.099f);
	glVertex3f(0.200f, 0.21f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.05f, 0.17f, -0.069f);
	glVertex3f(0.05f, 0.17f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.125f, 0.39f, 0.090f);
	glVertex3f(0.123f, 0.37f, 0.110f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.175f, 0.39f, 0.09f);
	glVertex3f(0.125f, 0.39f, 0.090f);

	glEnd();


	glBegin(GL_LINE_LOOP);//right front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.175f, 0.33f, 0.15f);
	glVertex3f(0.175f, 0.39f, 0.09f);

	glEnd();


	glBegin(GL_LINE_LOOP);//right front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.123f, 0.37f, 0.110f);
	glVertex3f(0.100f, 0.36f, 0.122f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.175f, 0.33f, 0.15f);
	glVertex3f(0.090f, 0.315f, 0.173f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right front up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.100f, 0.36f, 0.122f);
	glVertex3f(0.090f, 0.315f, 0.173f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right up

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.125f, 0.39f, 0.090f);
	glVertex3f(0.175f, 0.39f, 0.090f);
	glVertex3f(0.175f, 0.39f, -0.099f);
	glVertex3f(0.125f, 0.39f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right back

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.125f, 0.39f, -0.099f);
	glVertex3f(0.125f, 0.27f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right back

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.175f, 0.39f, -0.099f);
	glVertex3f(0.200f, 0.21f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right back

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.05f, 0.25f, -0.099f);
	glVertex3f(0.05f, 0.17f, -0.099f);

	glEnd();

	glBegin(GL_LINE_LOOP);//right back

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.05f, 0.17f, -0.099f);
	glVertex3f(0.125f, 0.19f, -0.099f);

	glEnd();

	//----------------------------------------------------

	glBegin(GL_QUADS);//right front down

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.175f, 0.33f, 0.15f);
	glVertex3f(0.14625f, 0.325f, 0.1575f);
	glVertex3f(0.16f, 0.205f, 0.10675f);
	glVertex3f(0.20f, 0.21f, 0.099f);

	glEnd();

	glBegin(GL_QUADS);//right front down(tri)

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.04f, 0.19f, 0.13f);
	glVertex3f(0.20f, 0.21f, 0.099f);
	glVertex3f(0.125f, 0.19f, 0.115f);
	glVertex3f(0.125f, 0.19f, 0.115f);

	glEnd();

	glBegin(GL_QUADS);//right down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.200f, 0.21f, 0.10f);
	glVertex3f(0.125f, 0.19f, 0.115f);
	glVertex3f(0.123f, 0.19f, -0.099f);
	glVertex3f(0.200f, 0.21f, -0.099f);

	glEnd();

	glBegin(GL_QUADS);//right down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.200f, 0.21f, -0.06f);
	glVertex3f(0.05f, 0.17f, -0.06f);
	glVertex3f(0.05f, 0.17f, -0.099f);
	glVertex3f(0.200f, 0.21f, -0.099f);

	glEnd();

	glBegin(GL_QUADS);//right front up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.175f, 0.33f, 0.15f);
	glVertex3f(0.175f, 0.39f, 0.09f);
	glVertex3f(0.125f, 0.39f, 0.090f);
	glVertex3f(0.123f, 0.37f, 0.110f);

	glEnd();

	glBegin(GL_QUADS);//right front up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.175f, 0.33f, 0.15f);
	glVertex3f(0.123f, 0.37f, 0.110f);
	glVertex3f(0.100f, 0.36f, 0.122f);
	glVertex3f(0.090f, 0.315f, 0.173f);


	glEnd();

	glBegin(GL_QUADS);//right up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.125f, 0.39f, 0.090f);
	glVertex3f(0.175f, 0.39f, 0.090f);
	glVertex3f(0.175f, 0.39f, -0.099f);
	glVertex3f(0.125f, 0.39f, -0.099f);

	glEnd();

	glBegin(GL_QUADS);//right back

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.175f, 0.39f, -0.099f);
	glVertex3f(0.125f, 0.39f, -0.099f);
	glVertex3f(0.125f, 0.19f, -0.099f);
	glVertex3f(0.200f, 0.21f, -0.099f);

	glEnd();

	glBegin(GL_QUADS);//right back

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.125f, 0.27f, -0.099f);
	glVertex3f(0.05f, 0.25f, -0.099f);
	glVertex3f(0.05f, 0.17f, -0.099f);
	glVertex3f(0.125f, 0.19f, -0.099f);

	glEnd();

	glBegin(GL_POLYGON);//right

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.175f, 0.39f, 0.090f);
	glVertex3f(0.175f, 0.39f, -0.099f);
	glVertex3f(0.20f, 0.21f, -0.099f);
	glVertex3f(0.20f, 0.21f, 0.099f);
	glVertex3f(0.175f, 0.33f, 0.150f);

	glEnd();

	glPopMatrix();


	//waist
	glPushMatrix();

	glBegin(GL_QUADS);//red up

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.105f, 0.20f, 0.105f);
	glVertex3f(0.105f, 0.20f, 0.105f);
	glVertex3f(0.105f, 0.20f, -0.055f);
	glVertex3f(-0.105f, 0.20f, -0.055f);

	glEnd();

	glBegin(GL_QUADS);//red down

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.12f, 0.0f, 0.13f);
	glVertex3f(0.12f, 0.0f, 0.13f);
	glVertex3f(0.12f, 0.0f, -0.07f);
	glVertex3f(-0.12f, 0.0f, -0.07f);

	glEnd();

	glBegin(GL_QUADS);//red front

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.105f, 0.20f, 0.105f);
	glVertex3f(-0.105f, 0.20f, 0.105f);
	glVertex3f(-0.12f, 0.0f, 0.13f);
	glVertex3f(0.12f, 0.0f, 0.13f);

	glEnd();

	glBegin(GL_QUADS);//red back

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.105f, 0.20f, -0.055f);
	glVertex3f(0.105f, 0.20f, -0.055f);
	glVertex3f(0.12f, 0.0f, -0.07f);
	glVertex3f(-0.12f, 0.0f, -0.07f);

	glEnd();

	glBegin(GL_QUADS);//red left

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.105f, 0.20f, -0.055f);
	glVertex3f(-0.105f, 0.20f, 0.105f);
	glVertex3f(-0.12f, 0.0f, 0.13f);
	glVertex3f(-0.12f, 0.0f, -0.07f);

	glEnd();

	glBegin(GL_QUADS);//red right 

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.105f, 0.20f, -0.055f);
	glVertex3f(0.105f, 0.20f, 0.105f);
	glVertex3f(0.12f, 0.0f, 0.13f);
	glVertex3f(0.12f, 0.0f, -0.07f);

	glEnd();



	glPopMatrix();


	//body
	glPushMatrix();

	//1 room

	glBegin(GL_QUADS);//up

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.1f, 0.40f, 0.1f);
	glVertex3f(0.1f, 0.40f, 0.1f);
	glVertex3f(0.1f, 0.40f, -0.1f);
	glVertex3f(-0.1f, 0.40f, -0.1f);

	glEnd();

	glBegin(GL_QUADS);//down

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-0.075f, 0.3625f, 0.1375f);
	glVertex3f(0.075f, 0.3625f, 0.1375f);
	glVertex3f(0.075f, 0.3625f, -0.1f);
	glVertex3f(-0.075f, 0.3625f, -0.1f);

	glEnd();

	glBegin(GL_QUADS);//front

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(0.1f, 0.40f, 0.1f);
	glVertex3f(-0.1f, 0.40f, 0.1f);
	glVertex3f(-0.075f, 0.3625f, 0.1375f);
	glVertex3f(0.075f, 0.3625f, 0.1375f);

	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-0.1f, 0.40f, -0.1f);
	glVertex3f(0.1f, 0.40f, -0.1f);
	glVertex3f(0.075f, 0.3625f, -0.1f);
	glVertex3f(-0.075f, 0.3625f, -0.1f);

	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(-0.075f, 0.3625f, 0.1375f);
	glVertex3f(-0.1f, 0.40f, 0.1f);
	glVertex3f(-0.1f, 0.40f, -0.1f);
	glVertex3f(-0.075f, 0.3625f, -0.1f);

	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(0.075f, 0.3625f, 0.1375f);
	glVertex3f(0.1f, 0.40f, 0.1f);
	glVertex3f(0.1f, 0.40f, -0.1f);
	glVertex3f(0.075f, 0.3625f, -0.1f);

	glEnd();

	//2 room


	glBegin(GL_QUADS);//front

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.05f, 0.25f, 0.0275f);
	glVertex3f(-0.075f, 0.3625f, 0.05f);
	glVertex3f(0.075f, 0.3625f, 0.05f);
	glVertex3f(0.05f, 0.25f, 0.0275f);

	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.075f, 0.3625f, -0.1f);
	glVertex3f(-0.075f, 0.3625f, -0.1f);
	glVertex3f(-0.05f, 0.25f, -0.1f);
	glVertex3f(0.05f, 0.25f, -0.1f);

	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.05f, 0.25f, -0.1f);
	glVertex3f(-0.075f, 0.3625f, -0.1f);
	glVertex3f(-0.075f, 0.3625f, 0.1375f);
	glVertex3f(-0.05f, 0.25f, 0.18f);

	glEnd();

	glBegin(GL_QUADS);//inside left

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.05f, 0.25f, -0.1f);
	glVertex3f(-0.05f, 0.3625f, -0.1f);
	glVertex3f(-0.05f, 0.3625f, 0.1375f);
	glVertex3f(-0.05f, 0.25f, 0.18f);

	glEnd();


	glBegin(GL_QUADS);//right

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(0.05f, 0.25f, -0.1f);
	glVertex3f(0.075f, 0.3625f, -0.1f);
	glVertex3f(0.075f, 0.3625f, 0.1375f);
	glVertex3f(0.05f, 0.25f, 0.18f);

	glEnd();

	glBegin(GL_QUADS);//inside left

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.05f, 0.25f, -0.1f);
	glVertex3f(-0.05f, 0.3625f, -0.1f);
	glVertex3f(-0.05f, 0.3625f, 0.1375f);
	glVertex3f(-0.05f, 0.25f, 0.18f);

	glEnd();

	glBegin(GL_QUADS);//inside front

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.05f, 0.25f, 0.18f);
	glVertex3f(-0.075f, 0.3625f, 0.1375f);
	glVertex3f(-0.05f, 0.3625f, 0.1375f);
	glVertex3f(-0.05f, 0.25f, 0.18f);

	glEnd();

	glBegin(GL_QUADS);//inside front

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.05f, 0.25f, 0.18f);
	glVertex3f(0.075f, 0.3625f, 0.1375f);
	glVertex3f(0.05f, 0.3625f, 0.1375f);
	glVertex3f(0.05f, 0.25f, 0.18f);

	glEnd();

	//3 room

	glBegin(GL_QUADS);//mid front

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.05f, 0.25f, 0.18f);
	glVertex3f(-0.05f, 0.20f, 0.234f);
	glVertex3f(0.05f, 0.20f, 0.234f);
	glVertex3f(0.05f, 0.25f, 0.18f);

	glEnd();

	glBegin(GL_QUADS);//mid back

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(0.05f, 0.25f, -0.1f);
	glVertex3f(-0.05f, 0.25f, -0.1f);
	glVertex3f(-0.05f, 0.201f, -0.1f);
	glVertex3f(0.05f, 0.201f, -0.1f);

	glEnd();

	glBegin(GL_QUADS);//mid down

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.05f, 0.20f, 0.234f);
	glVertex3f(0.05f, 0.20f, 0.234f);
	glVertex3f(0.05f, 0.20f, -0.1f);
	glVertex3f(-0.05f, 0.20f, -0.1f);

	glEnd();

	glBegin(GL_QUADS);//mid up

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.05f, 0.25f, 0.18f);
	glVertex3f(0.05f, 0.25f, 0.18f);
	glVertex3f(0.05f, 0.25f, -0.1f);
	glVertex3f(-0.05f, 0.25f, -0.1f);

	glEnd();


	glBegin(GL_QUADS);//mid left

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.05f, 0.20f, -0.1f);
	glVertex3f(-0.05f, 0.20f, 0.234f);
	glVertex3f(-0.05f, 0.25f, 0.18f);
	glVertex3f(-0.05f, 0.25f, -0.1f);

	glEnd();

	glBegin(GL_QUADS);//mid right

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(0.05f, 0.20f, -0.1f);
	glVertex3f(0.05f, 0.20f, 0.234f);
	glVertex3f(0.05f, 0.25f, 0.18f);
	glVertex3f(0.05f, 0.25f, -0.1f);

	glEnd();


	//4 room

	glBegin(GL_QUADS);// left

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.05f, 0.20f, 0.234f);
	glVertex3f(-0.05f, 0.20f, -0.1f);
	glVertex3f(-0.05f, 0.1f, -0.1f);
	glVertex3f(-0.05f, 0.1f, 0.17f);

	glEnd();

	glBegin(GL_QUADS);// right

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(0.05f, 0.20f, 0.234f);
	glVertex3f(0.05f, 0.20f, -0.1f);
	glVertex3f(0.05f, 0.1f, -0.1f);
	glVertex3f(0.05f, 0.1f, 0.17f);

	glEnd();

	glBegin(GL_QUADS);// front

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(-0.05f, 0.1f, 0.17f);
	glVertex3f(-0.05f, 0.20f, 0.234f);
	glVertex3f(0.05f, 0.20f, 0.234f);
	glVertex3f(0.05f, 0.1f, 0.17f);

	glEnd();

	glBegin(GL_QUADS);// back

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.05f, 0.1f, -0.1f);
	glVertex3f(-0.05f, 0.201f, -0.1f);
	glVertex3f(0.05f, 0.201f, -0.1f);
	glVertex3f(0.05f, 0.1f, -0.1f);

	glEnd();

	glBegin(GL_QUADS);// up

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.05f, 0.199f, 0.234f);
	glVertex3f(0.05f, 0.199f, 0.234f);
	glVertex3f(0.05f, 0.199f, -0.1f);
	glVertex3f(-0.05f, 0.199f, -0.1f);

	glEnd();

	glBegin(GL_QUADS);// down

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.05f, 0.1f, 0.17f);
	glVertex3f(0.05f, 0.1f, 0.17f);
	glVertex3f(0.05f, 0.1f, -0.1f);
	glVertex3f(-0.05f, 0.1f, -0.1f);

	glEnd();


	//red box
	glBegin(GL_QUADS);//up

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.165f, 0.38f, 0.08f);
	glVertex3f(0.165f, 0.38f, 0.08f);
	glVertex3f(0.165f, 0.38f, -0.08f);
	glVertex3f(-0.165f, 0.38f, -0.08f);

	glEnd();

	glBegin(GL_QUADS);//left down

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.19f, 0.22f, 0.10f);
	glVertex3f(-0.03f, 0.19f, 0.13f);
	glVertex3f(-0.03f, 0.19f, -0.08f);
	glVertex3f(-0.19f, 0.22f, -0.08f);

	glEnd();

	glBegin(GL_QUADS);//right down

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.19f, 0.22f, 0.10f);
	glVertex3f(0.03f, 0.19f, 0.13f);
	glVertex3f(0.03f, 0.19f, -0.08f);
	glVertex3f(0.19f, 0.22f, -0.08f);

	glEnd();

	glBegin(GL_POLYGON);//left

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.165f, 0.38f, 0.08f);
	glVertex3f(-0.165f, 0.38f, -0.08f);
	glVertex3f(-0.19f, 0.22f, -0.08f);
	glVertex3f(-0.19f, 0.22f, 0.10f);
	glVertex3f(-0.165f, 0.32f, 0.14f);

	glEnd();

	glBegin(GL_POLYGON);//right

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.165f, 0.38f, 0.08f);
	glVertex3f(0.165f, 0.38f, -0.08f);
	glVertex3f(0.19f, 0.22f, -0.08f);
	glVertex3f(0.19f, 0.22f, 0.10f);
	glVertex3f(0.165f, 0.32f, 0.14f);

	glEnd();

	glBegin(GL_QUADS);//left front up

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.165f, 0.38f, 0.08f);
	glVertex3f(-0.082f, 0.38f, 0.08f);
	glVertex3f(-0.06f, 0.3f, 0.17f);
	glVertex3f(-0.165f, 0.32f, 0.14f);
	glEnd();


	glBegin(GL_QUADS);//left front down

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.165f, 0.32f, 0.14f);
	glVertex3f(-0.06f, 0.3f, 0.17f);
	glVertex3f(-0.03f, 0.19f, 0.13f);
	glVertex3f(-0.19f, 0.22f, 0.10f);
	glEnd();

	glBegin(GL_QUADS);//right front up

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.165f, 0.38f, 0.08f);
	glVertex3f(0.082f, 0.38f, 0.08f);
	glVertex3f(0.06f, 0.3f, 0.17f);
	glVertex3f(0.165f, 0.32f, 0.14f);
	glEnd();


	glBegin(GL_QUADS);//right front down

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.165f, 0.32f, 0.14f);
	glVertex3f(0.06f, 0.3f, 0.17f);
	glVertex3f(0.03f, 0.19f, 0.13f);
	glVertex3f(0.19f, 0.22f, 0.10f);
	glEnd();

	glBegin(GL_QUADS);//left back

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.03f, 0.19f, -0.08f);
	glVertex3f(-0.19f, 0.22f, -0.08f);
	glVertex3f(-0.165f, 0.38f, -0.08f);
	glVertex3f(-0.082f, 0.38f, -0.08f);

	glEnd();

	glBegin(GL_QUADS);//right back

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.03f, 0.19f, -0.08f);
	glVertex3f(0.19f, 0.22f, -0.08f);
	glVertex3f(0.165f, 0.38f, -0.08f);
	glVertex3f(0.082f, 0.38f, -0.08f);

	glEnd();

	glPopMatrix();


	//door
	glPushMatrix();

	if (rotationdoor <= -40) {
		rotationdoor = -40;
	}

	if (rotationdoor > 0) {
		rotationdoor = 0;
		rotationSpeeddoor = 0;
	}

	glTranslatef(0.0f, 0.3625f, 0.1375f);

	rotationdoor += rotationSpeeddoor;
	glRotatef(rotationdoor, 1.0f, 0.0f, 0.0f);

	glTranslatef(0.0f, -0.3625f, -0.1375f);

	glLineWidth(1.5);
	glBegin(GL_LINE_LOOP);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.065f, 0.3625f, 0.1375f);
	glVertex3f(0.065f, 0.3625f, 0.1375f);
	glVertex3f(0.04f, 0.26f, 0.24f);
	glVertex3f(-0.04f, 0.26f, 0.24f);

	glEnd();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, logo1);
	glBegin(GL_QUADS);//outside up

	glColor3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.31f, 0.80f);
	glVertex3f(-0.075f, 0.3625f, 0.1375f);
	glTexCoord2f(0.71f, 0.80f);
	glVertex3f(0.075f, 0.3625f, 0.1375f);
	glTexCoord2f(0.61f, 0.0f);
	glVertex3f(0.05f, 0.25f, 0.25f);
	glTexCoord2f(0.41f, 0.0f);
	glVertex3f(-0.05f, 0.25f, 0.25f);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);//outside down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.05f, 0.25f, 0.25f);
	glVertex3f(-0.05f, 0.25f, 0.25f);
	glVertex3f(-0.05f, 0.20f, 0.234f);
	glVertex3f(0.05f, 0.20f, 0.234f);

	glEnd();

	glBegin(GL_QUADS);//inside inside up

	glColor3f(0.35f, 0.35f, 0.35f);
	glVertex3f(-0.07f, 0.3525f, 0.1375f);
	glVertex3f(0.07f, 0.3525f, 0.1375f);
	glVertex3f(0.045f, 0.25f, 0.24f);
	glVertex3f(-0.045f, 0.25f, 0.24f);

	glEnd();

	glBegin(GL_QUADS);//inside down

	glColor3f(0.35f, 0.35f, 0.35f);
	glVertex3f(0.05f, 0.25f, 0.24f);
	glVertex3f(-0.05f, 0.25f, 0.24f);
	glVertex3f(-0.05f, 0.21f, 0.224f);
	glVertex3f(0.05f, 0.21f, 0.224f);

	//glEnd();

	glBegin(GL_QUADS);//inside  left

	glColor3f(0.35f, 0.35f, 0.35f);
	glVertex3f(-0.045f, 0.201f, 0.234f);
	glVertex3f(-0.045f, 0.25f, 0.18f);
	glVertex3f(-0.07f, 0.352f, 0.1375f);
	glVertex3f(-0.044f, 0.25f, 0.25f);

	glEnd();

	glBegin(GL_QUADS);//inside right

	glColor3f(0.35f, 0.35f, 0.35f);
	glVertex3f(0.045f, 0.201f, 0.234f);
	glVertex3f(0.045f, 0.25f, 0.18f);
	glVertex3f(0.07f, 0.352f, 0.1375f);
	glVertex3f(0.044f, 0.25f, 0.25f);

	glEnd();


	glBegin(GL_QUADS);

	glColor3f(0.9f, 0.9f, 0.9f);//outside left
	glVertex3f(-0.05f, 0.201f, 0.234f);
	glVertex3f(-0.05f, 0.25f, 0.18f);
	glVertex3f(-0.075f, 0.3625f, 0.1375f);
	glVertex3f(-0.05f, 0.25f, 0.25f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.9f, 0.9f, 0.9f);//0utside right
	glVertex3f(0.05f, 0.201f, 0.234f);
	glVertex3f(0.05f, 0.25f, 0.18f);
	glVertex3f(0.075f, 0.3625f, 0.1375f);
	glVertex3f(0.05f, 0.25f, 0.25f);

	glEnd();

	glBegin(GL_QUADS);//wall mid

	glColor3f(0.55f, 0.55f, 0.55f);
	glVertex3f(-0.05f, 0.201f, 0.234f);
	glVertex3f(0.05f, 0.201f, 0.234f);
	glVertex3f(0.05f, 0.21f, 0.224f);
	glVertex3f(-0.05f, 0.21f, 0.224f);

	glEnd();

	glBegin(GL_QUADS);//wall left front

	glColor3f(0.55f, 0.55f, 0.55f);
	glVertex3f(-0.05f, 0.201f, 0.234f);
	glVertex3f(-0.05f, 0.25f, 0.18f);
	glVertex3f(-0.045f, 0.25f, 0.18f);
	glVertex3f(-0.045f, 0.201f, 0.234f);
	glEnd();

	glBegin(GL_QUADS);//wall left back

	glColor3f(0.55f, 0.55f, 0.55f);
	glVertex3f(-0.075f, 0.3625f, 0.1375f);
	glVertex3f(-0.05f, 0.25f, 0.18f);
	glVertex3f(-0.045f, 0.25f, 0.18f);
	glVertex3f(-0.07f, 0.3525f, 0.1375f);
	glEnd();

	glBegin(GL_QUADS);//wall right front

	glColor3f(0.55f, 0.55f, 0.55f);
	glVertex3f(0.05f, 0.201f, 0.234f);
	glVertex3f(0.05f, 0.25f, 0.18f);
	glVertex3f(0.045f, 0.25f, 0.18f);
	glVertex3f(0.045f, 0.201f, 0.234f);
	glEnd();

	glBegin(GL_QUADS);//wall right back

	glColor3f(0.55f, 0.55f, 0.55f);
	glVertex3f(0.075f, 0.3625f, 0.1375f);
	glVertex3f(0.05f, 0.25f, 0.18f);
	glVertex3f(0.045f, 0.25f, 0.18f);
	glVertex3f(0.07f, 0.3525f, 0.1375f);
	glEnd();

	glPopMatrix();

}

void neck()
{
	glPushMatrix();

	glBegin(GL_QUADS);//down

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.05f, 0.40f, 0.01f);
	glVertex3f(0.05f, 0.40f, 0.01f);
	glVertex3f(0.05f, 0.40f, -0.06f);
	glVertex3f(-0.05f, 0.40f, -0.06f);

	glEnd();

	glBegin(GL_QUADS);//up

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.04f, 0.43f, 0.01f);
	glVertex3f(0.04f, 0.43f, 0.01f);
	glVertex3f(0.04f, 0.45f, -0.04f);
	glVertex3f(-0.04f, 0.45f, -0.04f);

	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.04f, 0.45f, -0.04f);
	glVertex3f(-0.04f, 0.43f, 0.01f);
	glVertex3f(-0.05f, 0.40f, 0.01f);
	glVertex3f(-0.05f, 0.40f, -0.06f);

	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.04f, 0.45f, -0.04f);
	glVertex3f(0.04f, 0.43f, 0.01f);
	glVertex3f(0.05f, 0.40f, 0.01f);
	glVertex3f(0.05f, 0.40f, -0.06f);

	glEnd();

	glBegin(GL_QUADS);//front

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.05f, 0.40f, 0.01f);
	glVertex3f(0.05f, 0.40f, 0.01f);
	glVertex3f(0.04f, 0.43f, 0.01f);
	glVertex3f(-0.04f, 0.43f, 0.01f);

	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.05f, 0.40f, -0.06f);
	glVertex3f(0.05f, 0.40f, -0.06f);
	glVertex3f(0.04f, 0.45f, -0.04f);
	glVertex3f(-0.04f, 0.45f, -0.04f);

	glEnd();

	//tube 1
	glPushMatrix();

	glTranslatef(0.044f, 0.395f, 0.045f);
	glRotatef(45, -1.0f, 1.0f, 0.0f);
	glRotatef(-90, 1.0f, 0.0f, 0.0f);

	glColor3f(0.9f, 0.9f, 0.9f);
	gluCylinder(neck1, 0.0075, 0.0075, 0.05, 10, 10);

	glPopMatrix();

	//tube 2
	glPushMatrix();

	glTranslatef(-0.044f, 0.395f, 0.045f);
	glRotatef(45, -1.0f, -1.0f, 0.0f);
	glRotatef(-90, 1.0f, 0.0f, 0.0f);

	glColor3f(0.9f, 0.9f, 0.9f);
	gluCylinder(neck1, 0.0075, 0.0075, 0.05, 10, 10);

	glPopMatrix();

	//tube 3
	glPushMatrix();

	glTranslatef(00.00f, 0.395f, 0.00f);
	glRotatef(-90, 1.0f, 0.0f, 0.0f);

	glColor3f(0.25f, 0.25f, 0.25f);
	gluCylinder(neck3, 0.03, 0.03, 0.05, 10, 10);

	glPopMatrix();

	glPopMatrix();
}

void shouderLeft()
{
	glPushMatrix();

	if (rotationshouder3 > 5.0f) {
		rotationshouder3 = 5.0f;
	}

	if (rotationshouder3 < 0.0) {
		rotationshouder3 = 0.0;
	}

	glTranslatef(-0.175f, 0.40f, 0.0f);

	rotationshouder3 += rotationSpeedshouder3;

	glRotatef(-rotationshouder3, 0.0f, 0.0f, 1.0f);

	glTranslatef(0.175f, -0.40f, 0.0f);

	//up armo

	glPushMatrix();

	if (rotationshouder1 > 0.02) {
		rotationshouder1 = 0.02;
		rotationSpeedshouder1 = 0;
	}

	if (rotationshouder1 < 0.0) {
		rotationshouder1 = 0.0;
		rotationSpeedshouder1 = 0;
	}

	rotationshouder1 += rotationSpeedshouder1;
	glTranslatef(0.0f, rotationshouder1, 0.0f);

	glBegin(GL_QUADS);//armo up (outside)

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(-0.275, 0.425f, 0.070f);
	glVertex3f(-0.275, 0.425f, -0.070f);
	glVertex3f(-0.225, 0.4225f, -0.070f);
	glVertex3f(-0.225, 0.4225f, 0.070f);

	glEnd();

	glBegin(GL_QUADS);//armo up (inside)

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(-0.225, 0.4225f, 0.070f);
	glVertex3f(-0.225, 0.4225f, -0.070f);
	glVertex3f(-0.175, 0.400f, -0.070f);
	glVertex3f(-0.175, 0.400f, 0.070f);

	glEnd();

	glBegin(GL_QUADS);//armo down

	glColor3f(0.60f, 0.60f, 0.60f);
	glVertex3f(-0.275, 0.415f, 0.070f);
	glVertex3f(-0.275, 0.415f, -0.070f);
	glVertex3f(-0.175, 0.390f, -0.070f);
	glVertex3f(-0.175, 0.390f, 0.070f);

	glEnd();

	glBegin(GL_QUADS);//armo outside

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.275, 0.425f, 0.070f);
	glVertex3f(-0.275, 0.425f, -0.070f);
	glVertex3f(-0.275, 0.415f, -0.070f);
	glVertex3f(-0.275, 0.415f, 0.070f);

	glEnd();

	glBegin(GL_QUADS);//armo inside

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.175, 0.400f, -0.070f);
	glVertex3f(-0.175, 0.400f, 0.070f);
	glVertex3f(-0.175, 0.390f, 0.070f);
	glVertex3f(-0.175, 0.390f, -0.070f);

	glEnd();

	glBegin(GL_POLYGON);//armo front

	glColor3f(0.90f, 0.90f, 0.90f);
	glVertex3f(-0.275, 0.415f, 0.070f);
	glVertex3f(-0.275, 0.425f, 0.070f);
	glVertex3f(-0.225, 0.4225f, 0.070f);
	glVertex3f(-0.175, 0.400f, 0.070f);
	glVertex3f(-0.175, 0.390f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//armo back

	glColor3f(0.90f, 0.90f, 0.90f);
	glVertex3f(-0.275, 0.415f, -0.070f);
	glVertex3f(-0.275, 0.425f, -0.070f);
	glVertex3f(-0.225, 0.4225f, -0.070f);
	glVertex3f(-0.175, 0.400f, -0.070f);
	glVertex3f(-0.175, 0.390f, -0.070f);

	glEnd();

	glBegin(GL_QUADS);//red up

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.265, 0.415f, 0.055f);
	glVertex3f(-0.265, 0.415f, -0.055f);
	glVertex3f(-0.175, 0.390f, -0.055f);
	glVertex3f(-0.175, 0.390f, 0.055f);

	glEnd();


	glBegin(GL_QUADS);//red front

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.265, 0.415f, 0.055f);
	glVertex3f(-0.185, 0.390f, 0.055f);
	glVertex3f(-0.185, 0.360f, 0.055f);
	glVertex3f(-0.265, 0.385f, 0.055f);

	glEnd();

	glBegin(GL_QUADS);//red back

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.265, 0.415f, -0.055f);
	glVertex3f(-0.185, 0.390f, -0.055f);
	glVertex3f(-0.185, 0.360f, -0.055f);
	glVertex3f(-0.265, 0.385f, -0.055f);

	glEnd();

	glBegin(GL_QUADS);//red outside

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.265, 0.415f, 0.055f);
	glVertex3f(-0.265, 0.415f, -0.055f);
	glVertex3f(-0.265, 0.385f, -0.055f);
	glVertex3f(-0.265, 0.385f, 0.055f);

	glEnd();

	glBegin(GL_QUADS);//red inside

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.185, 0.390f, -0.055f);
	glVertex3f(-0.185, 0.390f, 0.055f);
	glVertex3f(-0.185, 0.360f, 0.055f);
	glVertex3f(-0.185, 0.360f, -0.055f);

	glEnd();

	glPopMatrix();


	//upper
	glPushMatrix();

	if (rotationshouder4 > 0.01) {
		rotationshouder4 = 0.01;
		rotationSpeedshouder4 = 0;
	}

	if (rotationshouder4 < 0.0) {
		rotationshouder4 = 0.0;
		rotationSpeedshouder4 = 0;
	}

	rotationshouder4 += rotationSpeedshouder4;
	glTranslatef(rotationshouder4, rotationshouder4, 0.0f);

	glBegin(GL_POLYGON);//front 

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.175, 0.37f, 0.100f);
	glVertex3f(-0.375, 0.42f, 0.100f);
	glVertex3f(-0.375, 0.39f, 0.100f);
	glVertex3f(-0.350, 0.39f, 0.100f);
	glVertex3f(-0.325, 0.365f, 0.100f);
	glVertex3f(-0.225, 0.34f, 0.100f);
	glVertex3f(-0.200, 0.315f, 0.100f);
	glVertex3f(-0.175, 0.315f, 0.100f);

	glEnd();

	glBegin(GL_POLYGON);//back 

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.175, 0.37f, -0.100f);
	glVertex3f(-0.375, 0.42f, -0.100f);
	glVertex3f(-0.375, 0.39f, -0.100f);
	glVertex3f(-0.350, 0.39f, -0.100f);
	glVertex3f(-0.325, 0.365f, -0.100f);
	glVertex3f(-0.225, 0.34f, -0.100f);
	glVertex3f(-0.200, 0.315f, -0.100f);
	glVertex3f(-0.175, 0.315f, -0.100f);

	glEnd();

	glBegin(GL_POLYGON);//inside front 

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.175, 0.39f, 0.070f);
	glVertex3f(-0.375, 0.44f, 0.070f);
	glVertex3f(-0.375, 0.39f, 0.070f);
	glVertex3f(-0.350, 0.39f, 0.070f);
	glVertex3f(-0.325, 0.365f, 0.070f);
	glVertex3f(-0.225, 0.34f, 0.070f);
	glVertex3f(-0.200, 0.315f, 0.070f);
	glVertex3f(-0.175, 0.315f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//inside back 

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.175, 0.39f, -0.070f);
	glVertex3f(-0.375, 0.44f, -0.070f);
	glVertex3f(-0.375, 0.39f, -0.070f);
	glVertex3f(-0.350, 0.39f, -0.070f);
	glVertex3f(-0.325, 0.365f, -0.070f);
	glVertex3f(-0.225, 0.34f, -0.070f);
	glVertex3f(-0.200, 0.315f, -0.070f);
	glVertex3f(-0.175, 0.315f, -0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside front (outside wall)

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.375, 0.39f, 0.100f);
	glVertex3f(-0.375, 0.42f, 0.100f);
	glVertex3f(-0.375, 0.44f, 0.070f);
	glVertex3f(-0.375, 0.39f, 0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside front down (outside wall)

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.375, 0.39f, 0.100f);
	glVertex3f(-0.350, 0.39f, 0.100f);
	glVertex3f(-0.350, 0.39f, 0.070f);
	glVertex3f(-0.375, 0.39f, 0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside front down (outside wall)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.350, 0.39f, 0.100f);
	glVertex3f(-0.325, 0.365f, 0.100f);
	glVertex3f(-0.325, 0.365f, 0.070f);
	glVertex3f(-0.350, 0.39f, 0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside back down (outside wall)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.350, 0.39f, -0.100f);
	glVertex3f(-0.325, 0.365f, -0.100f);
	glVertex3f(-0.325, 0.365f, -0.070f);
	glVertex3f(-0.350, 0.39f, -0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside back down (outside wall)

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.375, 0.39f, -0.100f);
	glVertex3f(-0.350, 0.39f, -0.100f);
	glVertex3f(-0.350, 0.39f, -0.070f);
	glVertex3f(-0.375, 0.39f, -0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside front down (outside wall)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.325, 0.365f, 0.100f);
	glVertex3f(-0.225, 0.34f, 0.100f);
	glVertex3f(-0.225, 0.34f, 0.070f);
	glVertex3f(-0.325, 0.365f, 0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside back down (outside wall)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.325, 0.365f, -0.100f);
	glVertex3f(-0.225, 0.34f, -0.100f);
	glVertex3f(-0.225, 0.34f, -0.070f);
	glVertex3f(-0.325, 0.365f, -0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside front down (outside wall)

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.225, 0.34f, 0.100f);
	glVertex3f(-0.200, 0.315f, 0.100f);
	glVertex3f(-0.200, 0.315f, 0.070f);
	glVertex3f(-0.225, 0.34f, 0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside back down (outside wall)

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.225, 0.34f, -0.100f);
	glVertex3f(-0.200, 0.315f, -0.100f);
	glVertex3f(-0.200, 0.315f, -0.070f);
	glVertex3f(-0.225, 0.34f, -0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside front down (outside wall)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.200, 0.315f, 0.100f);
	glVertex3f(-0.175, 0.315f, 0.100f);
	glVertex3f(-0.175, 0.315f, 0.070f);
	glVertex3f(-0.200, 0.315f, 0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside back down (outside wall)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.200, 0.315f, -0.100f);
	glVertex3f(-0.175, 0.315f, -0.100f);
	glVertex3f(-0.175, 0.315f, -0.070f);
	glVertex3f(-0.200, 0.315f, -0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside front down (outside wall)

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.175, 0.315f, 0.100f);
	glVertex3f(-0.175, 0.37f, 0.100f);
	glVertex3f(-0.175, 0.37f, 0.070f);
	glVertex3f(-0.175, 0.315f, 0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside back down (outside wall)

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.175, 0.315f, -0.100f);
	glVertex3f(-0.175, 0.37f, -0.100f);
	glVertex3f(-0.175, 0.37f, -0.070f);
	glVertex3f(-0.175, 0.315f, -0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside front (inside wall)

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.375, 0.39f, -0.100f);
	glVertex3f(-0.375, 0.42f, -0.100f);
	glVertex3f(-0.375, 0.44f, -0.070f);
	glVertex3f(-0.375, 0.39f, -0.070f);

	glEnd();

	glBegin(GL_QUADS);//up 

	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex3f(-0.375, 0.44f, 0.070f);
	glVertex3f(-0.275, 0.415f, 0.070f);
	glVertex3f(-0.275, 0.415f, -0.070f);
	glVertex3f(-0.375, 0.44f, -0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside up 

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.375, 0.43f, 0.070f);
	glVertex3f(-0.275, 0.405f, 0.070f);
	glVertex3f(-0.275, 0.405f, -0.070f);
	glVertex3f(-0.375, 0.43f, -0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside up (outside wall)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.375, 0.44f, -0.070f);
	glVertex3f(-0.375, 0.44f, 0.070f);
	glVertex3f(-0.375, 0.43f, 0.070f);
	glVertex3f(-0.375, 0.43f, -0.070f);

	glEnd();

	glBegin(GL_QUADS);//inside up (inside wall)

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.275, 0.415f, -0.070f);
	glVertex3f(-0.275, 0.415f, 0.070f);
	glVertex3f(-0.275, 0.405f, 0.070f);
	glVertex3f(-0.275, 0.405f, -0.070f);

	glEnd();

	glBegin(GL_QUADS);//front up 

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.375, 0.42f, 0.100f);
	glVertex3f(-0.175, 0.37f, 0.100f);
	glVertex3f(-0.175, 0.39f, 0.070f);
	glVertex3f(-0.375, 0.44f, 0.070f);

	glEnd();

	glBegin(GL_QUADS);//back up 

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.375, 0.42f, -0.100f);
	glVertex3f(-0.175, 0.37f, -0.100f);
	glVertex3f(-0.175, 0.39f, -0.070f);
	glVertex3f(-0.375, 0.44f, -0.070f);

	glEnd();

	glPopMatrix();

	glPopMatrix();

	//middle
	glPushMatrix();

	if (rotationshouder2 > 0.01) {
		rotationshouder2 = 0.01;
		rotationSpeedshouder2 = 0;
	}

	if (rotationshouder2 < 0.0) {
		rotationshouder2 = 0.0;
		rotationSpeedshouder2 = 0;
	}

	rotationshouder2 += rotationSpeedshouder2;
	glTranslatef(-rotationshouder2, rotationshouder2, 0.0f);

	glBegin(GL_POLYGON);//front

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.375, 0.39f, 0.100f);
	glVertex3f(-0.350, 0.39f, 0.100f);
	glVertex3f(-0.325, 0.365f, 0.100f);
	glVertex3f(-0.350, 0.34f, 0.100f);
	glVertex3f(-0.375, 0.34f, 0.100f);

	glEnd();

	glBegin(GL_POLYGON);//back

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.375, 0.39f, -0.100f);
	glVertex3f(-0.350, 0.39f, -0.100f);
	glVertex3f(-0.325, 0.365f, -0.100f);
	glVertex3f(-0.350, 0.34f, -0.100f);
	glVertex3f(-0.375, 0.34f, -0.100f);

	glEnd();

	glBegin(GL_POLYGON);//inside front

	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex3f(-0.375, 0.39f, 0.070f);
	glVertex3f(-0.350, 0.39f, 0.070f);
	glVertex3f(-0.325, 0.365f, 0.070f);
	glVertex3f(-0.350, 0.34f, 0.070f);
	glVertex3f(-0.375, 0.34f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//inside front

	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex3f(-0.375, 0.39f, -0.070f);
	glVertex3f(-0.350, 0.39f, -0.070f);
	glVertex3f(-0.325, 0.365f, -0.070f);
	glVertex3f(-0.350, 0.34f, -0.070f);
	glVertex3f(-0.375, 0.34f, -0.070f);

	glEnd();

	glBegin(GL_POLYGON);//inside front wall

	glColor3f(0.65f, 0.65f, 0.65f);
	glVertex3f(-0.375, 0.34f, 0.100f);
	glVertex3f(-0.375, 0.39f, 0.100f);
	glVertex3f(-0.375, 0.39f, 0.070f);
	glVertex3f(-0.375, 0.34f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//inside back wall

	glColor3f(0.65f, 0.65f, 0.65f);
	glVertex3f(-0.375, 0.34f, -0.100f);
	glVertex3f(-0.375, 0.39f, -0.100f);
	glVertex3f(-0.375, 0.39f, -0.070f);
	glVertex3f(-0.375, 0.34f, -0.070f);

	glEnd();

	glBegin(GL_POLYGON);//inside front wall

	glColor3f(0.65f, 0.65f, 0.65f);
	glVertex3f(-0.375, 0.39f, 0.100f);
	glVertex3f(-0.350, 0.39f, 0.100f);
	glVertex3f(-0.350, 0.39f, 0.070f);
	glVertex3f(-0.375, 0.39f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//inside back wall

	glColor3f(0.65f, 0.65f, 0.65f);
	glVertex3f(-0.375, 0.39f, -0.100f);
	glVertex3f(-0.350, 0.39f, -0.100f);
	glVertex3f(-0.350, 0.39f, -0.070f);
	glVertex3f(-0.375, 0.39f, -0.070f);

	glEnd();

	glBegin(GL_POLYGON);//inside front wall

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.350, 0.39f, 0.100f);
	glVertex3f(-0.325, 0.365f, 0.100f);
	glVertex3f(-0.325, 0.365f, 0.070f);
	glVertex3f(-0.350, 0.39f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//inside back wall

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.350, 0.39f, -0.100f);
	glVertex3f(-0.325, 0.365f, -0.100f);
	glVertex3f(-0.325, 0.365f, -0.070f);
	glVertex3f(-0.350, 0.39f, -0.070f);

	glEnd();

	glBegin(GL_POLYGON);//inside front wall

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.325, 0.365f, 0.100f);
	glVertex3f(-0.350, 0.34f, 0.100f);
	glVertex3f(-0.350, 0.34f, 0.070f);
	glVertex3f(-0.325, 0.365f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//inside back wall

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.325, 0.365f, -0.100f);
	glVertex3f(-0.350, 0.34f, -0.100f);
	glVertex3f(-0.350, 0.34f, -0.070f);
	glVertex3f(-0.325, 0.365f, -0.070f);

	glEnd();

	glBegin(GL_POLYGON);//inside front wall

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.350, 0.34f, 0.100f);
	glVertex3f(-0.375, 0.34f, 0.100f);
	glVertex3f(-0.375, 0.34f, 0.070f);
	glVertex3f(-0.350, 0.34f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//inside front wall

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.350, 0.34f, -0.100f);
	glVertex3f(-0.375, 0.34f, -0.100f);
	glVertex3f(-0.375, 0.34f, -0.070f);
	glVertex3f(-0.350, 0.34f, -0.070f);

	glEnd();

	glPopMatrix();




	//lower
	glPushMatrix();

	glBegin(GL_POLYGON);//front 

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.200, 0.315f, 0.100f);
	glVertex3f(-0.175, 0.315f, 0.100f);
	glVertex3f(-0.175, 0.26f, 0.100f);
	glVertex3f(-0.375, 0.31f, 0.100f);
	glVertex3f(-0.375, 0.34f, 0.100f);
	glVertex3f(-0.350, 0.34f, 0.100f);
	glVertex3f(-0.325, 0.365f, 0.100f);
	glVertex3f(-0.225, 0.34f, 0.100f);

	glEnd();

	glBegin(GL_POLYGON);//back

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.200, 0.315f, -0.100f);
	glVertex3f(-0.175, 0.315f, -0.100f);
	glVertex3f(-0.175, 0.26f, -0.100f);
	glVertex3f(-0.375, 0.31f, -0.100f);
	glVertex3f(-0.375, 0.34f, -0.100f);
	glVertex3f(-0.350, 0.34f, -0.100f);
	glVertex3f(-0.325, 0.365f, -0.100f);
	glVertex3f(-0.225, 0.34f, -0.100f);

	glEnd();

	glBegin(GL_POLYGON);//inside front 

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.200, 0.315f, 0.070f);
	glVertex3f(-0.175, 0.315f, 0.070f);
	glVertex3f(-0.175, 0.24f, 0.070f);
	glVertex3f(-0.375, 0.29f, 0.070f);
	glVertex3f(-0.375, 0.34f, 0.070f);
	glVertex3f(-0.350, 0.34f, 0.070f);
	glVertex3f(-0.325, 0.365f, 0.070f);
	glVertex3f(-0.225, 0.34f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//inside back 

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.200, 0.315f, -0.070f);
	glVertex3f(-0.175, 0.315f, -0.070f);
	glVertex3f(-0.175, 0.24f, -0.070f);
	glVertex3f(-0.375, 0.29f, -0.070f);
	glVertex3f(-0.375, 0.34f, -0.070f);
	glVertex3f(-0.350, 0.34f, -0.070f);
	glVertex3f(-0.325, 0.365f, -0.070f);
	glVertex3f(-0.225, 0.34f, -0.070f);

	glEnd();

	glBegin(GL_POLYGON);//front wall 1

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.200, 0.315f, 0.100f);
	glVertex3f(-0.225, 0.34f, 0.100f);
	glVertex3f(-0.225, 0.34f, 0.070f);
	glVertex3f(-0.200, 0.315f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//back wall 1

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.200, 0.315f, -0.100f);
	glVertex3f(-0.225, 0.34f, -0.100f);
	glVertex3f(-0.225, 0.34f, -0.070f);
	glVertex3f(-0.200, 0.315f, -0.070f);

	glEnd();

	glBegin(GL_POLYGON);//front wall 2

	glColor3f(0.95f, 0.95f, 0.95f);
	glVertex3f(-0.200, 0.315f, 0.100f);
	glVertex3f(-0.175, 0.315f, 0.100f);
	glVertex3f(-0.175, 0.315f, 0.070f);
	glVertex3f(-0.200, 0.315f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//back wall 2

	glColor3f(0.95f, 0.95f, 0.95f);
	glVertex3f(-0.200, 0.315f, -0.100f);
	glVertex3f(-0.175, 0.315f, -0.100f);
	glVertex3f(-0.175, 0.315f, -0.070f);
	glVertex3f(-0.200, 0.315f, -0.070f);

	glEnd();

	glBegin(GL_POLYGON);//front wall 3

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.175, 0.315f, 0.100f);
	glVertex3f(-0.175, 0.26f, 0.100f);
	glVertex3f(-0.175, 0.24f, 0.070f);
	glVertex3f(-0.175, 0.315f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//back wall 3

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.175, 0.315f, -0.100f);
	glVertex3f(-0.175, 0.26f, -0.100f);
	glVertex3f(-0.175, 0.24f, -0.070f);
	glVertex3f(-0.175, 0.315f, -0.070f);

	glEnd();

	glBegin(GL_POLYGON);//front wall 4

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-0.175, 0.26f, 0.100f);
	glVertex3f(-0.375, 0.31f, 0.100f);
	glVertex3f(-0.375, 0.29f, 0.070f);
	glVertex3f(-0.175, 0.24f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//back wall 4

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-0.175, 0.26f, -0.100f);
	glVertex3f(-0.375, 0.31f, -0.100f);
	glVertex3f(-0.375, 0.29f, -0.070f);
	glVertex3f(-0.175, 0.24f, -0.070f);

	glEnd();

	glBegin(GL_POLYGON);//front wall 5

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.375, 0.31f, 0.100f);
	glVertex3f(-0.375, 0.34f, 0.100f);
	glVertex3f(-0.375, 0.34f, 0.070f);
	glVertex3f(-0.375, 0.29f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//back wall 5

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.375, 0.31f, -0.100f);
	glVertex3f(-0.375, 0.34f, -0.100f);
	glVertex3f(-0.375, 0.34f, -0.070f);
	glVertex3f(-0.375, 0.29f, -0.070f);

	glEnd();

	glBegin(GL_POLYGON);//front wall 6

	glColor3f(0.95f, 0.95f, 0.95f);
	glVertex3f(-0.375, 0.34f, 0.100f);
	glVertex3f(-0.350, 0.34f, 0.100f);
	glVertex3f(-0.350, 0.34f, 0.070f);
	glVertex3f(-0.375, 0.34f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//back wall 6

	glColor3f(0.95f, 0.95f, 0.95f);
	glVertex3f(-0.375, 0.34f, -0.100f);
	glVertex3f(-0.350, 0.34f, -0.100f);
	glVertex3f(-0.350, 0.34f, -0.070f);
	glVertex3f(-0.375, 0.34f, -0.070f);

	glEnd();

	glBegin(GL_POLYGON);//front wall 7

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.350, 0.34f, 0.100f);
	glVertex3f(-0.325, 0.365f, 0.100f);
	glVertex3f(-0.325, 0.365f, 0.070f);
	glVertex3f(-0.350, 0.34f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//back wall 7

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.350, 0.34f, -0.100f);
	glVertex3f(-0.325, 0.365f, -0.100f);
	glVertex3f(-0.325, 0.365f, -0.070f);
	glVertex3f(-0.350, 0.34f, -0.070f);

	glEnd();

	glBegin(GL_POLYGON);//front wall 8

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.325, 0.365f, 0.100f);
	glVertex3f(-0.225, 0.34f, 0.100f);
	glVertex3f(-0.225, 0.34f, 0.070f);
	glVertex3f(-0.325, 0.365f, 0.070f);

	glEnd();

	glBegin(GL_POLYGON);//back wall 8

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.325, 0.365f, -0.100f);
	glVertex3f(-0.225, 0.34f, -0.100f);
	glVertex3f(-0.225, 0.34f, -0.070f);
	glVertex3f(-0.325, 0.365f, -0.070f);

	glEnd();

	glPopMatrix();

	//connect
	glPushMatrix();

	glBegin(GL_QUADS);//up 

	glColor3f(0.20f, 0.20f, 0.20f);
	glVertex3f(-0.275, 0.405f, 0.060f);
	glVertex3f(-0.275, 0.405f, -0.060f);
	glVertex3f(-0.170, 0.380f, -0.060f);
	glVertex3f(-0.170, 0.380f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//down

	glColor3f(0.10f, 0.10f, 0.10f);
	glVertex3f(-0.170, 0.31f, 0.060f);
	glVertex3f(-0.275, 0.31f, 0.060f);
	glVertex3f(-0.275, 0.31f, -0.060f);
	glVertex3f(-0.170, 0.31f, -0.060f);

	glEnd();

	glBegin(GL_QUADS);//front

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.275, 0.405f, 0.060f);
	glVertex3f(-0.170, 0.380f, 0.060f);
	glVertex3f(-0.170, 0.31f, 0.060f);
	glVertex3f(-0.275, 0.31f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.275, 0.405f, -0.060f);
	glVertex3f(-0.170, 0.380f, -0.060f);
	glVertex3f(-0.170, 0.31f, -0.060f);
	glVertex3f(-0.275, 0.31f, -0.060f);

	glEnd();


	glBegin(GL_QUADS);//front 2

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.275, 0.395f, 0.060f);
	glVertex3f(-0.375, 0.430f, 0.060f);
	glVertex3f(-0.375, 0.31f, 0.060f);
	glVertex3f(-0.275, 0.31f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//back 2

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.275, 0.395f, -0.060f);
	glVertex3f(-0.375, 0.430f, -0.060f);
	glVertex3f(-0.375, 0.31f, -0.060f);
	glVertex3f(-0.275, 0.31f, -0.060f);

	glEnd();

	glBegin(GL_QUADS);//up 2

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.275, 0.395f, 0.060f);
	glVertex3f(-0.375, 0.430f, 0.060f);
	glVertex3f(-0.375, 0.430f, -0.060f);
	glVertex3f(-0.275, 0.395f, -0.060f);

	glEnd();

	glBegin(GL_QUADS);//down 2

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.375, 0.31f, 0.060f);
	glVertex3f(-0.275, 0.31f, 0.060f);
	glVertex3f(-0.275, 0.31f, -0.060f);
	glVertex3f(-0.375, 0.31f, -0.060f);

	glEnd();

	glBegin(GL_QUADS);//outside 2

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.375, 0.430f, 0.060f);
	glVertex3f(-0.375, 0.31f, 0.060f);
	glVertex3f(-0.375, 0.31f, -0.060f);
	glVertex3f(-0.375, 0.430f, -0.060f);

	glEnd();

	glBegin(GL_QUADS);//inside 2

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.275, 0.395f, 0.060f);
	glVertex3f(-0.275, 0.31f, 0.060f);
	glVertex3f(-0.275, 0.31f, -0.060f);
	glVertex3f(-0.275, 0.395f, -0.060f);

	glEnd();

	glBegin(GL_QUADS);//inside

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.170, 0.380f, 0.060f);
	glVertex3f(-0.170, 0.31f, 0.060f);
	glVertex3f(-0.170, 0.31f, -0.060f);
	glVertex3f(-0.170, 0.380f, -0.060f);

	glEnd();

	glBegin(GL_QUADS);//outside

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.275, 0.405f, 0.060f);
	glVertex3f(-0.275, 0.31f, 0.060f);
	glVertex3f(-0.275, 0.31f, -0.060f);
	glVertex3f(-0.275, 0.405f, -0.060f);

	glEnd();

	glBegin(GL_QUADS);//armo inside

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.375, 0.415f, 0.050f);
	glVertex3f(-0.375, 0.28f, 0.050f);
	glVertex3f(-0.375, 0.28f, -0.050f);
	glVertex3f(-0.375, 0.415f, -0.050f);

	glEnd();

	glBegin(GL_QUADS);//armo outside

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.395, 0.405f, 0.040f);
	glVertex3f(-0.385, 0.30f, 0.040f);
	glVertex3f(-0.385, 0.30f, -0.040f);
	glVertex3f(-0.395, 0.405f, -0.040f);

	glEnd();

	glBegin(GL_QUADS);//armo front

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.375, 0.28f, 0.050f);
	glVertex3f(-0.375, 0.415f, 0.050f);
	glVertex3f(-0.395, 0.405f, 0.040f);
	glVertex3f(-0.385, 0.30f, 0.040f);

	glEnd();

	glBegin(GL_QUADS);//armo back

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.375, 0.28f, -0.050f);
	glVertex3f(-0.375, 0.415f, -0.050f);
	glVertex3f(-0.395, 0.405f, -0.040f);
	glVertex3f(-0.385, 0.30f, -0.040f);

	glEnd();

	glBegin(GL_QUADS);//armo up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.375, 0.415f, 0.050f);
	glVertex3f(-0.375, 0.415f, -0.050f);
	glVertex3f(-0.395, 0.405f, -0.040f);
	glVertex3f(-0.395, 0.405f, 0.040f);

	glEnd();

	glBegin(GL_QUADS);//armo down

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.375, 0.28f, 0.050f);
	glVertex3f(-0.375, 0.28f, -0.050f);
	glVertex3f(-0.385, 0.30f, -0.040f);
	glVertex3f(-0.385, 0.30f, 0.040f);

	glEnd();

	glBegin(GL_QUADS);//red inside

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.180, 0.370f, 0.065f);
	glVertex3f(-0.180, 0.310f, 0.065f);
	glVertex3f(-0.180, 0.310f, -0.065f);
	glVertex3f(-0.180, 0.370f, -0.065f);

	glEnd();

	glBegin(GL_QUADS);//red outside

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.355, 0.420f, 0.065f);
	glVertex3f(-0.355, 0.320f, 0.065f);
	glVertex3f(-0.355, 0.320f, -0.065f);
	glVertex3f(-0.355, 0.420f, -0.065f);

	glEnd();

	glBegin(GL_QUADS);//red front

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.180, 0.370f, 0.065f);
	glVertex3f(-0.180, 0.310f, 0.065f);
	glVertex3f(-0.355, 0.310f, 0.065f);
	glVertex3f(-0.355, 0.420f, 0.065f);

	glEnd();

	glBegin(GL_QUADS);//red back

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.180, 0.370f, -0.065f);
	glVertex3f(-0.180, 0.310f, -0.065f);
	glVertex3f(-0.355, 0.310f, -0.065f);
	glVertex3f(-0.355, 0.420f, -0.065f);

	glEnd();

	glPopMatrix();

}

void shield()
{
	//fan
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -0.01f);
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.2f, 0.2f);
	for (int angle = 0; angle <= 360; angle++) {
		float tempx = radius * cos(angle * pi / 180);
		float tempy = radius * sin(angle * pi / 180);
		glVertex2f(tempx, tempy);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.00f);
	glTranslatef(0.0f, 0.0f, -0.01f);
	glRotatef(0, 0.0f, 0.0f, 0.0f);
	gluCylinder(tiang1, radius, radius, 0.071, 20, 2);//base radius,top radius,height,slices,stacks
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.061f);
	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.2f, 0.2f);
	for (int angle = 0; angle <= 360; angle++) {
		float tempx = radius * cos(angle * pi / 180);
		float tempy = radius * sin(angle * pi / 180);
		glVertex2f(tempx, tempy);
	}
	glEnd();
	glPopMatrix();

	if (rotationfan >= 30) {
		rotationfan = 30;
	}

	if (rotationfan < 0) {
		rotationfan = 0;
	}

	rotationfan += rotationSpeedfan;

	//fan1
	glPushMatrix();
	glRotatef(-rotationfan, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);//fan left down


	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.00f, 0.0f, -0.005f);
	glVertex3f(0.00f, -0.4f, -0.005f);
	glVertex3f(-0.06, -0.5f, -0.005f);
	glVertex3f(-0.13, -0.1f, -0.005f);

	glEnd();

	glBegin(GL_QUADS);//fan left down wall front


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(-0.11f, -0.08f, 0.0f);
	glVertex3f(-0.04f, -0.47f, 0.0f);
	glVertex3f(-0.06, -0.5f, 0.0f);
	glVertex3f(-0.13, -0.1f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);//fan left down wall back


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(-0.11f, -0.08f, -0.01f);
	glVertex3f(-0.04f, -0.47f, -0.01f);
	glVertex3f(-0.06, -0.5f, -0.01f);
	glVertex3f(-0.13, -0.1f, -0.01f);

	glEnd();

	glBegin(GL_QUADS);//fan left down wall out


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(-0.06, -0.5f, 0.0f);
	glVertex3f(-0.13, -0.1f, 0.0f);
	glVertex3f(-0.13, -0.1f, -0.01f);
	glVertex3f(-0.06, -0.5f, -0.01f);

	glEnd();

	glBegin(GL_QUADS);//fan left down wall up


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(-0.04f, -0.47f, 0.0f);
	glVertex3f(-0.06, -0.5f, 0.0f);
	glVertex3f(-0.06, -0.5f, -0.01f);
	glVertex3f(-0.04f, -0.47f, -0.01f);

	glEnd();

	glBegin(GL_QUADS);//fan left down wall down


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(-0.11f, -0.08f, -0.01f);
	glVertex3f(-0.13, -0.1f, -0.01f);
	glVertex3f(-0.13, -0.1f, 0.0f);
	glVertex3f(-0.11f, -0.08f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);//fan right up


	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.00f, 0.0f, -0.005f);
	glVertex3f(0.00f, 0.4f, -0.005f);
	glVertex3f(0.06, 0.5f, -0.005f);
	glVertex3f(0.13, 0.1f, -0.005f);

	glEnd();

	glBegin(GL_QUADS);//fan right up wall front


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(0.11f, 0.08f, 0.0f);
	glVertex3f(0.04f, 0.47f, 0.0f);
	glVertex3f(0.06, 0.5f, 0.0f);
	glVertex3f(0.13, 0.1f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);//fan right up wall back


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(0.11f, 0.08f, -0.01f);
	glVertex3f(0.04f, 0.47f, -0.01f);
	glVertex3f(0.06, 0.5f, -0.01f);
	glVertex3f(0.13, 0.1f, -0.01f);

	glEnd();

	glBegin(GL_QUADS);//fan right up wall out

	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(0.06, 0.5f, 0.0f);
	glVertex3f(0.13, 0.1f, 0.0f);
	glVertex3f(0.13, 0.1f, -0.01f);
	glVertex3f(0.06, 0.5f, -0.01f);

	glEnd();

	glBegin(GL_QUADS);//fan right up wall up


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(0.04f, 0.47f, 0.0f);
	glVertex3f(0.06, 0.5f, 0.0f);
	glVertex3f(0.06, 0.5f, -0.01f);
	glVertex3f(0.04f, 0.47f, -0.01f);

	glEnd();

	glBegin(GL_QUADS);//fan right up wall down

	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(0.11f, 0.08f, -0.01f);
	glVertex3f(0.13, 0.1f, -0.01f);
	glVertex3f(0.13, 0.1f, 0.0f);
	glVertex3f(0.11f, 0.08f, 0.0f);

	glEnd();

	glPopMatrix();

	//fan2
	glPushMatrix();
	glRotatef(rotationfan, 0.0f, 0.0f, 1.0f);

	glBegin(GL_QUADS);//fan left up

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.00f, 0.0f, -0.005f);
	glVertex3f(0.00f, 0.4f, -0.005f);
	glVertex3f(-0.06, 0.5f, -0.005f);
	glVertex3f(-0.13, 0.1f, -0.005f);

	glEnd();

	glBegin(GL_QUADS);//fan left up wall front


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(-0.11f, 0.08f, 0.0f);
	glVertex3f(-0.04f, 0.47f, 0.0f);
	glVertex3f(-0.06, 0.5f, 0.0f);
	glVertex3f(-0.13, 0.1f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);//fan left up wall back


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(-0.11f, 0.08f, -0.01f);
	glVertex3f(-0.04f, 0.47f, -0.01f);
	glVertex3f(-0.06, 0.5f, -0.01f);
	glVertex3f(-0.13, 0.1f, -0.01f);

	glEnd();

	glBegin(GL_QUADS);//fan left up wall out


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(-0.06, 0.5f, 0.0f);
	glVertex3f(-0.13, 0.1f, 0.0f);
	glVertex3f(-0.13, 0.1f, -0.01f);
	glVertex3f(-0.06, 0.5f, -0.01f);

	glEnd();

	glBegin(GL_QUADS);//fan left up wall up


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(-0.04f, 0.47f, 0.0f);
	glVertex3f(-0.06, 0.5f, 0.0f);
	glVertex3f(-0.06, 0.5f, -0.01f);
	glVertex3f(-0.04f, 0.47f, -0.01f);

	glEnd();

	glBegin(GL_QUADS);//fan left up wall down

	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(-0.11f, 0.08f, -0.01f);
	glVertex3f(-0.13, 0.1f, -0.01f);
	glVertex3f(-0.13, 0.1f, 0.0f);
	glVertex3f(-0.11f, 0.08f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);//fan right down

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.00f, 0.0f, -0.005f);
	glVertex3f(0.00f, -0.4f, -0.005f);
	glVertex3f(0.06, -0.5f, -0.005f);
	glVertex3f(0.13, -0.1f, -0.005f);

	glEnd();

	glBegin(GL_QUADS);//fan right down wall front


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(0.11f, -0.08f, 0.0f);
	glVertex3f(0.04f, -0.47f, 0.0f);
	glVertex3f(0.06, -0.5f, 0.0f);
	glVertex3f(0.13, -0.1f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);//fan right down wall back


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(0.11f, -0.08f, -0.01f);
	glVertex3f(0.04f, -0.47f, -0.01f);
	glVertex3f(0.06, -0.5f, -0.01f);
	glVertex3f(0.13, -0.1f, -0.01f);

	glEnd();

	glBegin(GL_QUADS);//fan right down wall out

	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(0.06, -0.5f, 0.0f);
	glVertex3f(0.13, -0.1f, 0.0f);
	glVertex3f(0.13, -0.1f, -0.01f);
	glVertex3f(0.06, -0.5f, -0.01f);

	glEnd();

	glBegin(GL_QUADS);//fan right down wall up


	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(0.04f, -0.47f, 0.0f);
	glVertex3f(0.06, -0.5f, 0.0f);
	glVertex3f(0.06, -0.5f, -0.01f);
	glVertex3f(0.04f, -0.47f, -0.01f);

	glEnd();

	glBegin(GL_QUADS);//fan right down wall down

	glColor3f(1.00f, 1.00f, 1.00f);
	glVertex3f(0.11f, -0.08f, -0.01f);
	glVertex3f(0.13, -0.1f, -0.01f);
	glVertex3f(0.13, -0.1f, 0.0f);
	glVertex3f(0.11f, -0.08f, 0.0f);

	glEnd();

	glPopMatrix();


	glPopMatrix();

	//upper shield
	glPushMatrix();

	glBegin(GL_QUADS);//down back

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(-0.05, 0.00f, 0.000f);
	glVertex3f(-0.15, 0.20f, 0.000f);
	glVertex3f(0.15, 0.20f, 0.000f);
	glVertex3f(0.05, 0.00f, 0.000f);

	glEnd();

	glBegin(GL_QUADS);//down front out 1

	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex3f(-0.05, 0.00f, 0.060f);
	glVertex3f(-0.1, 0.10f, 0.060f);
	glVertex3f(0.1, 0.10f, 0.060f);
	glVertex3f(0.05, 0.00f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//down front out 2

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(-0.05, 0.20f, 0.050f);
	glVertex3f(-0.1, 0.10f, 0.060f);
	glVertex3f(0.1, 0.10f, 0.060f);
	glVertex3f(0.05, 0.20f, 0.050f);

	glEnd();

	glBegin(GL_QUADS);//down front out 2 left

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.05, 0.20f, 0.050f);
	glVertex3f(-0.1, 0.10f, 0.060f);
	glVertex3f(-0.1, 0.10f, 0.030f);
	glVertex3f(-0.05, 0.20f, 0.050f);

	glEnd();

	glBegin(GL_QUADS);//down front out 2 right

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.05, 0.20f, 0.050f);
	glVertex3f(0.1, 0.10f, 0.060f);
	glVertex3f(0.1, 0.10f, 0.030f);
	glVertex3f(0.05, 0.20f, 0.050f);

	glEnd();

	glBegin(GL_QUADS);//down front out left

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.05, 0.00f, 0.060f);
	glVertex3f(-0.1, 0.10f, 0.060f);
	glVertex3f(-0.1, 0.10f, 0.030f);
	glVertex3f(-0.05, 0.00f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//down front out right

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(0.05, 0.00f, 0.060f);
	glVertex3f(0.1, 0.10f, 0.060f);
	glVertex3f(0.1, 0.10f, 0.030f);
	glVertex3f(0.05, 0.00f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//down left

	glColor3f(0.60f, 0.60f, 0.60f);
	glVertex3f(-0.15, 0.20f, 0.000f);
	glVertex3f(-0.05, 0.00f, 0.000f);
	glVertex3f(-0.05, 0.00f, 0.060f);
	glVertex3f(-0.05, 0.00f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//down right

	glColor3f(0.60f, 0.60f, 0.60f);
	glVertex3f(0.15, 0.20f, 0.000f);
	glVertex3f(0.05, 0.00f, 0.000f);
	glVertex3f(0.05, 0.00f, 0.060f);
	glVertex3f(0.05, 0.00f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//up back

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(-0.15, 0.20f, 0.000f);
	glVertex3f(-0.1, 0.45f, 0.000f);
	glVertex3f(0.1, 0.45f, 0.000f);
	glVertex3f(0.15, 0.20f, 0.000f);

	glEnd();

	glBegin(GL_QUADS);//up front (middle)

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(-0.05, 0.45f, 0.02f);
	glVertex3f(-0.05, 0.10f, 0.060f);
	glVertex3f(0.05, 0.10f, 0.060f);
	glVertex3f(0.05, 0.45f, 0.02f);

	glEnd();

	glBegin(GL_POLYGON);//up front (left)
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.1, 0.45f, 0.00f);
	glVertex3f(-0.05, 0.45f, 0.02f);
	glVertex3f(-0.05, 0.10f, 0.060f);
	glVertex3f(-0.05, 0.0f, 0.060f);
	glVertex3f(-0.15, 0.20f, 0.00f);

	glEnd();

	glBegin(GL_POLYGON);//up front (right)
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.1, 0.45f, 0.00f);
	glVertex3f(0.05, 0.45f, 0.02f);
	glVertex3f(0.05, 0.10f, 0.060f);
	glVertex3f(0.05, 0.0f, 0.060f);
	glVertex3f(0.15, 0.20f, 0.00f);

	glEnd();

	glBegin(GL_QUADS);//up hole back

	glColor3f(0.90f, 0.90f, 0.90f);
	glVertex3f(-0.1, 0.45f, 0.000f);
	glVertex3f(-0.075, 0.5f, 0.000f);
	glVertex3f(0.075, 0.5f, 0.000f);
	glVertex3f(0.1, 0.45f, 0.000f);

	glEnd();

	glBegin(GL_POLYGON);//up hole front 

	glColor3f(0.95f, 0.95f, 0.95f);
	glVertex3f(-0.05, 0.45f, 0.02f);
	glVertex3f(-0.1, 0.45f, 0.00f);
	glVertex3f(-0.075, 0.5f, 0.000f);
	glVertex3f(0.075, 0.5f, 0.000f);
	glVertex3f(0.1, 0.45f, 0.00f);
	glVertex3f(0.05, 0.45f, 0.02f);

	glEnd();

	glPopMatrix();


	//lower shield
	glPushMatrix();

	if (rotationsheild >= 0.28f) {
		rotationsheild = 0.28f;

		rotationSpeedfan = 0.2;
	}
	else {
		rotationSpeedfan = -0.2;
	}

	if (rotationsheild < 0.0) {
		rotationsheild = 0.0;
	}

	rotationsheild += rotationSpeedsheild;
	glTranslatef(0.0f, -rotationsheild, 0.0f);



	glTranslatef(0.0f, 0.28f, 0.0f);

	glBegin(GL_QUADS);//up back

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(0.05, 0.0f, 0.000f);
	glVertex3f(0.16, -0.3f, 0.000f);
	glVertex3f(-0.16, -0.3f, 0.000f);
	glVertex3f(-0.05, 0.0f, 0.000f);

	glEnd();


	glBegin(GL_QUADS);//up front

	glColor3f(0.60f, 0.60f, 0.60f);


	glVertex3f(0.05, 0.0f, 0.045f);


	glVertex3f(0.105, -0.15f, 0.060f);


	glVertex3f(-0.105, -0.15f, 0.060f);


	glVertex3f(-0.05, 0.0f, 0.045f);

	glEnd();


	glBegin(GL_QUADS);//up left

	glColor3f(0.65f, 0.65f, 0.65f);
	glVertex3f(-0.16, -0.3f, 0.000f);
	glVertex3f(-0.05, 0.0f, 0.000f);
	glVertex3f(-0.05, 0.0f, 0.045f);
	glVertex3f(-0.105, -0.15f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//up right

	glColor3f(0.65f, 0.65f, 0.65f);
	glVertex3f(0.16, -0.3f, 0.000f);
	glVertex3f(0.05, 0.0f, 0.000f);
	glVertex3f(0.05, 0.0f, 0.045f);
	glVertex3f(0.105, -0.15f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//up out front 1 logo

	glColor3f(1.000f, 1.000f, 1.000f);
	glVertex3f(0.05, 0.0f, 0.070f);
	glVertex3f(0.105, -0.15f, 0.070f);
	glVertex3f(-0.105, -0.15f, 0.070f);
	glVertex3f(-0.05, 0.0f, 0.070f);

	glEnd();

	glBegin(GL_QUADS);//up out back 1

	glColor3f(0.900f, 0.900f, 0.900f);
	glVertex3f(0.05, 0.0f, 0.060f);
	glVertex3f(0.105, -0.15f, 0.060f);
	glVertex3f(-0.105, -0.15f, 0.060f);
	glVertex3f(-0.05, 0.0f, 0.060f);

	glEnd();


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, logo2);
	glBegin(GL_QUADS);//logo

	glColor3f(1.00f, 1.00f, 1.00f);

	glTexCoord2f(0.60f, 0.0f);
	glVertex3f(0.05, -0.30f, 0.0701f);//down right
	glTexCoord2f(0.40f, 0.0f);
	glVertex3f(-0.05, -0.30f, 0.0701f);//down left
	glTexCoord2f(0.40f, 1.0f);
	glVertex3f(-0.05, 0.0f, 0.0701f);//up left
	glTexCoord2f(0.60f, 1.0f);
	glVertex3f(0.05, 0.0f, 0.0701f);//up right

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);//up out front 2 logo

	glColor3f(1.000f, 1.000f, 1.000f);

	glVertex3f(0.05, -0.30f, 0.070f);
	glVertex3f(0.105, -0.15f, 0.070f);
	glVertex3f(-0.105, -0.15f, 0.070f);
	glVertex3f(-0.05, -0.30f, 0.070f);

	glEnd();

	glBegin(GL_QUADS);//up out front 2

	glColor3f(0.900f, 0.900f, 0.900f);
	glVertex3f(0.05, -0.30f, 0.060f);
	glVertex3f(0.105, -0.15f, 0.060f);
	glVertex3f(-0.105, -0.15f, 0.060f);
	glVertex3f(-0.05, -0.30f, 0.060f);

	glEnd();


	glBegin(GL_QUADS);//up out front 1 up

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(0.05, 0.0f, 0.070f);
	glVertex3f(-0.05, 0.0f, 0.070f);
	glVertex3f(-0.05, 0.0f, 0.060f);
	glVertex3f(0.05, 0.0f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//up out front 1 left

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(-0.105, -0.15f, 0.070f);
	glVertex3f(-0.05, 0.0f, 0.070f);
	glVertex3f(-0.05, 0.0f, 0.060f);
	glVertex3f(-0.105, -0.15f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//up out front 1 right

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(0.105, -0.15f, 0.070f);
	glVertex3f(0.05, 0.0f, 0.070f);
	glVertex3f(0.05, 0.0f, 0.060f);
	glVertex3f(0.105, -0.15f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//up out front 2 down

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(0.05, -0.30f, 0.070f);
	glVertex3f(-0.05, -0.30f, 0.070f);
	glVertex3f(-0.05, -0.30f, 0.060f);
	glVertex3f(0.05, -0.30f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//up out front 2 left

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(-0.105, -0.15f, 0.070f);
	glVertex3f(-0.05, -0.30f, 0.070f);
	glVertex3f(-0.05, -0.30f, 0.060f);
	glVertex3f(-0.105, -0.15f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//up out front 2 right

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(0.105, -0.15f, 0.070f);
	glVertex3f(0.05, -0.30f, 0.070f);
	glVertex3f(0.05, -0.30f, 0.060f);
	glVertex3f(0.105, -0.15f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//down

	glColor3f(0.80f, 0.80f, 0.80f);
	glVertex3f(0.16, -0.3f, 0.000f);
	glVertex3f(0.05, -0.88f, 0.000f);
	glVertex3f(-0.05, -0.88f, 0.000f);
	glVertex3f(-0.16, -0.3f, 0.000f);

	glEnd();

	glBegin(GL_QUADS);//down front (middle)

	glColor3f(0.60f, 0.60f, 0.60f);
	glVertex3f(0.105, -0.15f, 0.060f);
	glVertex3f(0.05, -0.88f, 0.000f);
	glVertex3f(-0.05, -0.88f, 0.000f);
	glVertex3f(-0.105, -0.15f, 0.060f);

	glEnd();

	glBegin(GL_QUADS);//down front (left)

	glColor3f(0.90f, 0.90f, 0.90f);
	glVertex3f(-0.05, -0.88f, 0.000f);
	glVertex3f(-0.105, -0.15f, 0.060f);
	glVertex3f(-0.16, -0.3f, 0.000f);
	glVertex3f(-0.05, -0.88f, 0.000f);

	glEnd();

	glBegin(GL_QUADS);//down front (right)

	glColor3f(0.90f, 0.90f, 0.90f);
	glVertex3f(0.05, -0.88f, 0.000f);
	glVertex3f(0.105, -0.15f, 0.060f);
	glVertex3f(0.16, -0.3f, 0.000f);
	glVertex3f(0.05, -0.88f, 0.000f);

	glEnd();

	glPopMatrix();

}

void sifat()
{

	//left butt armor
	glPushMatrix();

	glBegin(GL_QUADS);//back

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.045f, 0.0f, -0.125f);
	glVertex3f(-0.16f, 0.0f, -0.125f);
	glVertex3f(-0.20f, -0.10f, -0.125f);
	glVertex3f(-0.045f, -0.18f, -0.125f);
	glEnd();

	glBegin(GL_QUADS);//front

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.14f, 0.0f, -0.165f);
	glVertex3f(-0.16f, 0.0f, -0.165f);
	glVertex3f(-0.20f, -0.10f, -0.165f);
	glVertex3f(-0.14f, -0.13f, -0.165f);
	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.16f, 0.0f, -0.165f);
	glVertex3f(-0.20f, -0.10f, -0.165f);
	glVertex3f(-0.20f, -0.10f, -0.125f);
	glVertex3f(-0.16f, 0.0f, -0.123f);
	glEnd();

	glBegin(GL_QUADS);//back 2

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.045f, 0.0f, -0.125f);
	glVertex3f(-0.14f, 0.0f, -0.125f);
	glVertex3f(-0.14f, -0.20f, -0.125f);
	glVertex3f(-0.045f, -0.25f, -0.125f);
	glEnd();


	glBegin(GL_QUADS);//left 2

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.14f, 0.0f, -0.125f);
	glVertex3f(-0.14f, -0.20f, -0.125f);
	glVertex3f(-0.14f, -0.20f, -0.185f);
	glVertex3f(-0.14f, 0.0f, -0.185f);
	glEnd();

	glBegin(GL_QUADS);//right 2

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.045f, 0.0f, -0.125f);
	glVertex3f(-0.045f, -0.25f, -0.125f);
	glVertex3f(-0.045f, -0.25f, -0.185f);
	glVertex3f(-0.045f, 0.0f, -0.185f);
	glEnd();


	glPopMatrix();

	//right butt armor
	glPushMatrix();

	glBegin(GL_QUADS);//back

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.045f, 0.0f, -0.125f);
	glVertex3f(0.16f, 0.0f, -0.125f);
	glVertex3f(0.20f, -0.10f, -0.125f);
	glVertex3f(0.045f, -0.18f, -0.125f);
	glEnd();

	glBegin(GL_QUADS);//front

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(0.14f, 0.0f, -0.165f);
	glVertex3f(0.16f, 0.0f, -0.165f);
	glVertex3f(0.20f, -0.10f, -0.165f);
	glVertex3f(0.14f, -0.13f, -0.165f);
	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.16f, 0.0f, -0.165f);
	glVertex3f(0.20f, -0.10f, -0.165f);
	glVertex3f(0.20f, -0.10f, -0.125f);
	glVertex3f(0.16f, 0.0f, -0.123f);
	glEnd();

	glBegin(GL_QUADS);//back 2

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.045f, 0.0f, -0.125f);
	glVertex3f(0.14f, 0.0f, -0.125f);
	glVertex3f(0.14f, -0.20f, -0.125f);
	glVertex3f(0.045f, -0.25f, -0.125f);
	glEnd();


	glBegin(GL_QUADS);//left 2

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.14f, 0.0f, -0.125f);
	glVertex3f(0.14f, -0.20f, -0.125f);
	glVertex3f(0.14f, -0.20f, -0.185f);
	glVertex3f(0.14f, 0.0f, -0.185f);
	glEnd();

	glBegin(GL_QUADS);//right 2

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.045f, 0.0f, -0.125f);
	glVertex3f(0.045f, -0.25f, -0.125f);
	glVertex3f(0.045f, -0.25f, -0.185f);
	glVertex3f(0.045f, 0.0f, -0.185f);
	glEnd();

	glPopMatrix();

	//tube left
	glPushMatrix();
	glColor3f(colorr, colorg, colorb);
	glTranslatef(-0.090f, -0.02f, -0.155f);
	glRotatef(rotationbelt6 / 2, 1.0f, 0.0f, 0.0f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	gluCylinder(tiang2, 0.02, 0.03, 0.175, 10, 10);
	glPopMatrix();


	//tube right
	glPushMatrix();
	glColor3f(colorr, colorg, colorb);
	glTranslatef(0.090f, -0.02f, -0.155f);
	glRotatef(rotationbelt6 / 2, 1.0f, 0.0f, 0.0f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	gluCylinder(tiang2, 0.02, 0.03, 0.175, 10, 10);
	glPopMatrix();

	//move left butt armor
	glPushMatrix();

	if (rotationbelt6 > 40) {
		rotationbelt6 = 40;
		rotationSpeedbelt6 = 0;
	}

	if (rotationbelt6 < 0.0) {
		rotationbelt6 = 0.0;
		rotationSpeedbelt6 = 0;
	}

	glTranslatef(0.0f, 0.00f, -0.185f);

	rotationbelt6 += rotationSpeedbelt6;
	glRotatef(rotationbelt6, 1.0f, 0.0f, 0.0f);

	glTranslatef(0.0f, 0.00f, 0.185f);

	glBegin(GL_QUADS);//front 2

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.045f, 0.0f, -0.185f);
	glVertex3f(-0.14f, 0.0f, -0.185f);
	glVertex3f(-0.14f, -0.20f, -0.185f);
	glVertex3f(-0.045f, -0.25f, -0.185f);
	glEnd();


	glBegin(GL_QUADS);//up 2

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.045f, 0.0f, -0.125f);
	glVertex3f(-0.14f, 0.0f, -0.125f);
	glVertex3f(-0.14f, 0.0f, -0.185f);
	glVertex3f(-0.045f, 0.0f, -0.185f);
	glEnd();

	glBegin(GL_QUADS);//left 2

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.14f, 0.0f, -0.185f);
	glVertex3f(-0.139f, -0.20f, -0.185f);
	glVertex3f(-0.14f, 0.0f, -0.125f);
	glVertex3f(-0.14f, 0.0f, -0.185f);
	glEnd();

	glBegin(GL_QUADS);//right 2

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.045f, 0.0f, -0.185f);
	glVertex3f(-0.046f, -0.20f, -0.185f);
	glVertex3f(-0.045f, 0.0f, -0.125f);
	glVertex3f(-0.045f, 0.0f, -0.185f);
	glEnd();

	glBegin(GL_QUADS);//up 3

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.045f, 0.045f, -0.132f);
	glVertex3f(-0.14f, 0.045f, -0.132f);
	glVertex3f(-0.14f, 0.00f, -0.185f);
	glVertex3f(-0.045f, 0.00f, -0.185f);
	glEnd();

	glBegin(GL_QUADS);//right 3

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.14f, 0.0f, -0.125f);
	glVertex3f(-0.14f, 0.0f, -0.185f);
	glVertex3f(-0.14f, 0.00f, -0.185f);
	glVertex3f(-0.14f, 0.045f, -0.132f);
	glEnd();

	glBegin(GL_QUADS);//left 3

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.045f, 0.0f, -0.125f);
	glVertex3f(-0.045f, 0.0f, -0.185f);
	glVertex3f(-0.045f, 0.00f, -0.185f);
	glVertex3f(-0.045f, 0.045f, -0.132f);
	glEnd();

	glPopMatrix();

	//move right butt armor
	glPushMatrix();

	if (rotationbelt6 > 40) {
		rotationbelt6 = 40;
		rotationSpeedbelt6 = 0;
	}

	if (rotationbelt6 < 0.0) {
		rotationbelt6 = 0.0;
		rotationSpeedbelt6 = 0;
	}

	glTranslatef(0.0f, 0.00f, -0.185f);

	rotationbelt6 += rotationSpeedbelt6;
	glRotatef(rotationbelt6, 1.0f, 0.0f, 0.0f);

	glTranslatef(0.0f, 0.00f, 0.185f);

	glBegin(GL_QUADS);//front 2

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.045f, 0.0f, -0.185f);
	glVertex3f(0.14f, 0.0f, -0.185f);
	glVertex3f(0.14f, -0.20f, -0.185f);
	glVertex3f(0.045f, -0.25f, -0.185f);
	glEnd();


	glBegin(GL_QUADS);//up 2

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(0.045f, 0.0f, -0.125f);
	glVertex3f(0.14f, 0.0f, -0.125f);
	glVertex3f(0.14f, 0.0f, -0.185f);
	glVertex3f(0.045f, 0.0f, -0.185f);
	glEnd();

	glBegin(GL_QUADS);//left 2

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(0.14f, 0.0f, -0.185f);
	glVertex3f(0.139f, -0.20f, -0.185f);
	glVertex3f(0.14f, 0.0f, -0.125f);
	glVertex3f(0.14f, 0.0f, -0.185f);
	glEnd();

	glBegin(GL_QUADS);//right 2

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(0.045f, 0.0f, -0.185f);
	glVertex3f(0.046f, -0.20f, -0.185f);
	glVertex3f(0.045f, 0.0f, -0.125f);
	glVertex3f(0.045f, 0.0f, -0.185f);
	glEnd();

	glBegin(GL_QUADS);//up 3

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(0.045f, 0.045f, -0.132f);
	glVertex3f(0.14f, 0.045f, -0.132f);
	glVertex3f(0.14f, 0.00f, -0.185f);
	glVertex3f(0.045f, 0.00f, -0.185f);
	glEnd();

	glBegin(GL_QUADS);//right 3

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.14f, 0.0f, -0.125f);
	glVertex3f(0.14f, 0.0f, -0.185f);
	glVertex3f(0.14f, 0.00f, -0.185f);
	glVertex3f(0.14f, 0.045f, -0.132f);
	glEnd();

	glBegin(GL_QUADS);//left 3

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.045f, 0.0f, -0.125f);
	glVertex3f(0.045f, 0.0f, -0.185f);
	glVertex3f(0.045f, 0.00f, -0.185f);
	glVertex3f(0.045f, 0.045f, -0.132f);
	glEnd();

	glPopMatrix();

	//butt plug
	glPushMatrix();

	glBegin(GL_QUADS);//up

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.04f, -0.01f, -0.15f);
	glVertex3f(-0.04f, -0.01f, -0.15f);
	glVertex3f(-0.04f, -0.01f, -0.05f);
	glVertex3f(0.04f, -0.01f, -0.05f);
	glEnd();

	glBegin(GL_QUADS);//down

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(0.04f, -0.16f, -0.15f);
	glVertex3f(-0.04f, -0.16f, -0.15f);
	glVertex3f(-0.04f, -0.20f, -0.05f);
	glVertex3f(0.04f, -0.20f, -0.05f);
	glEnd();

	glBegin(GL_QUADS);//front

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.04f, -0.01f, -0.15f);
	glVertex3f(-0.04f, -0.01f, -0.15f);
	glVertex3f(-0.04f, -0.16f, -0.15f);
	glVertex3f(0.04f, -0.16f, -0.15f);
	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.04f, -0.01f, -0.05f);
	glVertex3f(0.04f, -0.01f, -0.05f);
	glVertex3f(0.04f, -0.20f, -0.05f);
	glVertex3f(-0.04f, -0.20f, -0.05f);
	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex3f(-0.04f, -0.01f, -0.15f);
	glVertex3f(-0.04f, -0.16f, -0.15f);
	glVertex3f(-0.04f, -0.20f, -0.05f);
	glVertex3f(-0.04f, -0.01f, -0.05f);
	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex3f(0.04f, -0.01f, -0.15f);
	glVertex3f(0.04f, -0.16f, -0.15f);
	glVertex3f(0.04f, -0.20f, -0.05f);
	glVertex3f(0.04f, -0.01f, -0.05f);
	glEnd();

	glBegin(GL_QUADS);//up2

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.02f, 0.005f, -0.16f);
	glVertex3f(-0.02f, 0.005f, -0.16f);
	glVertex3f(-0.02f, 0.005f, -0.12f);
	glVertex3f(0.02f, 0.005f, -0.12f);
	glEnd();

	glBegin(GL_QUADS);//down2

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.02f, -0.05f, -0.16f);
	glVertex3f(-0.02f, -0.05f, -0.16f);
	glVertex3f(-0.02f, -0.05f, -0.12f);
	glVertex3f(0.02f, -0.05f, -0.12f);
	glEnd();

	glBegin(GL_QUADS);//left2

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.02f, 0.005f, -0.16f);
	glVertex3f(-0.02f, 0.005f, -0.12f);
	glVertex3f(-0.02f, -0.05f, -0.12f);
	glVertex3f(-0.02f, -0.05f, -0.16f);
	glEnd();

	glBegin(GL_QUADS);//right2

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.02f, 0.005f, -0.16f);
	glVertex3f(0.02f, 0.005f, -0.12f);
	glVertex3f(0.02f, -0.05f, -0.12f);
	glVertex3f(0.02f, -0.05f, -0.16f);
	glEnd();

	glBegin(GL_QUADS);//front2

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.02f, 0.005f, -0.16f);
	glVertex3f(-0.02f, 0.005f, -0.16f);
	glVertex3f(-0.02f, -0.05f, -0.16f);
	glVertex3f(0.02f, -0.05f, -0.16f);
	glEnd();

	glPopMatrix();

	//black sifat
	glPushMatrix();
	glBegin(GL_QUADS);//up

	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(0.15f, 0.0f, 0.12f);
	glVertex3f(-0.15f, 0.0f, 0.12f);
	glVertex3f(-0.15f, 0.0f, -0.12f);
	glVertex3f(0.15f, 0.0f, -0.12f);
	glEnd();

	glBegin(GL_QUADS);//down

	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(0.19f, -0.1f, 0.12f);
	glVertex3f(-0.19f, -0.1f, 0.12f);
	glVertex3f(-0.19f, -0.1f, -0.12f);
	glVertex3f(0.19f, -0.1f, -0.12f);
	glEnd();

	glBegin(GL_QUADS);//front

	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(0.15f, 0.0f, 0.12f);
	glVertex3f(-0.15f, 0.0f, 0.12f);
	glVertex3f(-0.19f, -0.1f, 0.12f);
	glVertex3f(0.19f, -0.1f, 0.12f);
	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(0.15f, 0.0f, -0.12f);
	glVertex3f(-0.15f, 0.0f, -0.12f);
	glVertex3f(-0.19f, -0.1f, -0.12f);
	glVertex3f(0.19f, -0.1f, -0.12f);
	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.15f, 0.0f, 0.12f);
	glVertex3f(-0.19f, -0.1f, 0.12f);
	glVertex3f(-0.19f, -0.1f, -0.12f);
	glVertex3f(-0.15f, 0.0f, -0.12f);
	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.15f, 0.0f, 0.12f);
	glVertex3f(0.19f, -0.1f, 0.12f);
	glVertex3f(0.19f, -0.1f, -0.12f);
	glVertex3f(0.15f, 0.0f, -0.12f);
	glEnd();
	glPopMatrix();

	//left armor
	glPushMatrix();
	glBegin(GL_POLYGON);//right

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.20f, -0.1f, 0.075f);
	glVertex3f(-0.24f, -0.2f, 0.05f);
	glVertex3f(-0.24f, -0.2f, -0.05f);
	glVertex3f(-0.20f, -0.1f, -0.075f);
	glVertex3f(-0.16f, 0.0f, -0.05f);
	glVertex3f(-0.16f, 0.0f, 0.05f);
	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.23f, -0.08f, 0.075f);//middle line----
	glVertex3f(-0.23f, -0.08f, -0.075f);
	glVertex3f(-0.19f, 0.02f, -0.05f);
	glVertex3f(-0.19f, 0.02f, 0.05f);
	glEnd();

	glBegin(GL_QUADS);//up

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.16f, 0.0f, -0.05f);
	glVertex3f(-0.16f, 0.0f, 0.05f);
	glVertex3f(-0.19f, 0.02f, 0.05f);
	glVertex3f(-0.19f, 0.02f, -0.05f);
	glEnd();

	glBegin(GL_QUADS);//up left

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.23f, -0.08f, -0.075f);
	glVertex3f(-0.20f, -0.1f, -0.075f);
	glVertex3f(-0.16f, 0.0f, -0.05f);
	glVertex3f(-0.19f, 0.02f, -0.05f);

	glEnd();

	glBegin(GL_POLYGON);//up left

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.23f, -0.08f, 0.075f);
	glVertex3f(-0.20f, -0.1f, 0.075f);
	glVertex3f(-0.16f, 0.0f, 0.05f);
	glVertex3f(-0.19f, 0.02f, 0.05f);

	glEnd();

	glBegin(GL_POLYGON);//red front

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.16f, 0.0f, 0.05f);
	glVertex3f(-0.19f, 0.02f, 0.05f);
	glVertex3f(-0.27f, -0.18f, 0.05f);
	glVertex3f(-0.24f, -0.2f, 0.05f);

	glEnd();

	glBegin(GL_POLYGON);//red back

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.16f, 0.0f, -0.05f);
	glVertex3f(-0.19f, 0.02f, -0.05f);
	glVertex3f(-0.27f, -0.18f, -0.05f);
	glVertex3f(-0.24f, -0.2f, -0.05f);

	glEnd();

	glBegin(GL_POLYGON);//red left

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.189f, 0.02f, 0.05f);
	glVertex3f(-0.189f, 0.02f, -0.05f);
	glVertex3f(-0.269f, -0.18f, -0.05f);
	glVertex3f(-0.269f, -0.18f, 0.05f);

	glEnd();

	glPopMatrix();

	//right armor
	glPushMatrix();
	glBegin(GL_POLYGON);//right

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.20f, -0.1f, 0.075f);
	glVertex3f(0.24f, -0.2f, 0.05f);
	glVertex3f(0.24f, -0.2f, -0.05f);
	glVertex3f(0.20f, -0.1f, -0.075f);
	glVertex3f(0.16f, 0.0f, -0.05f);
	glVertex3f(0.16f, 0.0f, 0.05f);
	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(0.23f, -0.08f, 0.075f);//middle line----
	glVertex3f(0.23f, -0.08f, -0.075f);
	glVertex3f(0.19f, 0.02f, -0.05f);
	glVertex3f(0.19f, 0.02f, 0.05f);
	glEnd();

	glBegin(GL_QUADS);//up

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.16f, 0.0f, -0.05f);
	glVertex3f(0.16f, 0.0f, 0.05f);
	glVertex3f(0.19f, 0.02f, 0.05f);
	glVertex3f(0.19f, 0.02f, -0.05f);
	glEnd();

	glBegin(GL_QUADS);//up left

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.23f, -0.08f, -0.075f);
	glVertex3f(0.20f, -0.1f, -0.075f);
	glVertex3f(0.16f, 0.0f, -0.05f);
	glVertex3f(0.19f, 0.02f, -0.05f);

	glEnd();

	glBegin(GL_POLYGON);//up left

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.23f, -0.08f, 0.075f);
	glVertex3f(0.20f, -0.1f, 0.075f);
	glVertex3f(0.16f, 0.0f, 0.05f);
	glVertex3f(0.19f, 0.02f, 0.05f);

	glEnd();

	glBegin(GL_POLYGON);//red front

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.16f, 0.0f, 0.05f);
	glVertex3f(0.19f, 0.02f, 0.05f);
	glVertex3f(0.27f, -0.18f, 0.05f);
	glVertex3f(0.24f, -0.2f, 0.05f);

	glEnd();

	glBegin(GL_POLYGON);//red back

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.16f, 0.0f, -0.05f);
	glVertex3f(0.19f, 0.02f, -0.05f);
	glVertex3f(0.27f, -0.18f, -0.05f);
	glVertex3f(0.24f, -0.2f, -0.05f);

	glEnd();

	glBegin(GL_POLYGON);//red left

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.189f, 0.02f, 0.05f);
	glVertex3f(0.189f, 0.02f, -0.05f);
	glVertex3f(0.269f, -0.18f, -0.05f);
	glVertex3f(0.269f, -0.18f, 0.05f);

	glEnd();

	glPopMatrix();

	//move left armor
	glPushMatrix();

	if (rotationbelt5 > 0.01f) {
		rotationbelt5 = 0.01f;
		rotationSpeedbelt5 = 0;
	}

	if (rotationbelt5 < 0.0) {
		rotationbelt5 = 0.0;
		rotationSpeedbelt5 = 0;
	}

	rotationbelt5 += rotationSpeedbelt5;

	glTranslatef(-rotationbelt5, -rotationbelt5 * 2, 0.0f);

	glBegin(GL_QUADS);//left

	glColor3f(0.55f, 0.55f, 0.55f);
	glVertex3f(-0.23f, -0.08f, 0.075f);//middle line----
	glVertex3f(-0.27f, -0.18f, 0.05f);
	glVertex3f(-0.27f, -0.18f, -0.05f);
	glVertex3f(-0.23f, -0.08f, -0.075f);

	glEnd();

	glBegin(GL_QUADS);//front

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.23f, -0.08f, 0.075f);//middle line----
	glVertex3f(-0.27f, -0.18f, 0.05f);
	glVertex3f(-0.24f, -0.2f, 0.05f);
	glVertex3f(-0.20f, -0.1f, 0.075f);

	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.23f, -0.08f, -0.075f);//middle line----
	glVertex3f(-0.27f, -0.18f, -0.05f);
	glVertex3f(-0.24f, -0.2f, -0.05f);
	glVertex3f(-0.20f, -0.1f, -0.075f);

	glEnd();

	glBegin(GL_QUADS);//down

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.27f, -0.18f, -0.05f);
	glVertex3f(-0.24f, -0.2f, -0.05f);
	glVertex3f(-0.24f, -0.2f, 0.05f);
	glVertex3f(-0.27f, -0.18f, 0.05f);

	glEnd();

	glBegin(GL_POLYGON);//right

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.20f, -0.1f, 0.075f);
	glVertex3f(-0.24f, -0.2f, 0.05f);
	glVertex3f(-0.24f, -0.2f, -0.05f);
	glVertex3f(-0.20f, -0.1f, -0.075f);

	glVertex3f(-0.16f, 0.0f, -0.05f);
	glVertex3f(-0.16f, 0.0f, 0.05f);
	glEnd();

	glPopMatrix();

	//move right armor
	glPushMatrix();

	if (rotationbelt5 > 0.01f) {
		rotationbelt5 = 0.01f;
		rotationSpeedbelt5 = 0;
	}

	if (rotationbelt5 < 0.0) {
		rotationbelt5 = 0.0;
		rotationSpeedbelt5 = 0;
	}

	rotationbelt5 += rotationSpeedbelt5;

	glTranslatef(rotationbelt5, -rotationbelt5 * 2, 0.0f);

	glBegin(GL_QUADS);//left

	glColor3f(0.55f, 0.55f, 0.55f);
	glVertex3f(0.23f, -0.08f, 0.075f);//middle line----
	glVertex3f(0.27f, -0.18f, 0.05f);
	glVertex3f(0.27f, -0.18f, -0.05f);
	glVertex3f(0.23f, -0.08f, -0.075f);

	glEnd();

	glBegin(GL_QUADS);//front

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.23f, -0.08f, 0.075f);//middle line----
	glVertex3f(0.27f, -0.18f, 0.05f);
	glVertex3f(0.24f, -0.2f, 0.05f);
	glVertex3f(0.20f, -0.1f, 0.075f);

	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.23f, -0.08f, -0.075f);//middle line----
	glVertex3f(0.27f, -0.18f, -0.05f);
	glVertex3f(0.24f, -0.2f, -0.05f);
	glVertex3f(0.20f, -0.1f, -0.075f);

	glEnd();

	glBegin(GL_QUADS);//down

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.27f, -0.18f, -0.05f);
	glVertex3f(0.24f, -0.2f, -0.05f);
	glVertex3f(0.24f, -0.2f, 0.05f);
	glVertex3f(0.27f, -0.18f, 0.05f);

	glEnd();

	glBegin(GL_POLYGON);//right

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.20f, -0.1f, 0.075f);
	glVertex3f(0.24f, -0.2f, 0.05f);
	glVertex3f(0.24f, -0.2f, -0.05f);
	glVertex3f(0.20f, -0.1f, -0.075f);

	glVertex3f(0.16f, 0.0f, -0.05f);
	glVertex3f(0.16f, 0.0f, 0.05f);
	glEnd();

	glPopMatrix();



	//left underwear
	glPushMatrix();

	glBegin(GL_POLYGON);//back

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-0.045f, 0.0f, 0.125f);
	glVertex3f(-0.18f, 0.0f, 0.125f);
	glVertex3f(-0.20f, -0.12f, 0.125f);
	glVertex3f(-0.045f, -0.2f, 0.125f);
	glEnd();

	glBegin(GL_POLYGON);//front

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.045f, 0.0f, 0.145f);
	glVertex3f(-0.15f, 0.0f, 0.145f);
	glVertex3f(-0.12f, -0.055f, 0.145f);
	glVertex3f(-0.045f, -0.085f, 0.145f);
	glEnd();

	glBegin(GL_POLYGON);//red

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.045f, 0.0f, 0.135f);
	glVertex3f(-0.15f, 0.0f, 0.135f);
	glVertex3f(-0.17f, -0.11f, 0.135f);
	glVertex3f(-0.045f, -0.17f, 0.135f);
	glEnd();

	glBegin(GL_POLYGON);//left

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.18f, 0.0f, 0.125f);
	glVertex3f(-0.20f, -0.12f, 0.125f);
	glVertex3f(-0.17f, -0.11f, 0.145f);
	glVertex3f(-0.15f, 0.0f, 0.145f);
	glEnd();

	glBegin(GL_POLYGON);//right

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.045f, 0.0f, 0.125f);
	glVertex3f(-0.045f, -0.2f, 0.125f);
	glVertex3f(-0.045f, -0.17f, 0.145f);
	glVertex3f(-0.045f, 0.0f, 0.145f);
	glEnd();

	glBegin(GL_POLYGON);//up

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.045f, 0.0f, 0.125f);
	glVertex3f(-0.18f, 0.0f, 0.125f);
	glVertex3f(-0.15f, 0.0f, 0.145f);
	glVertex3f(-0.045f, 0.0f, 0.145f);
	glEnd();

	glBegin(GL_POLYGON);//down

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(-0.20f, -0.12f, 0.125f);
	glVertex3f(-0.045f, -0.2f, 0.125f);
	glVertex3f(-0.045f, -0.17f, 0.145f);
	glVertex3f(-0.17f, -0.11f, 0.145f);
	glEnd();

	glPopMatrix();

	//right underwear
	glPushMatrix();

	glBegin(GL_POLYGON);//back

	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(0.045f, 0.0f, 0.125f);
	glVertex3f(0.18f, 0.0f, 0.125f);
	glVertex3f(0.20f, -0.12f, 0.125f);
	glVertex3f(0.045f, -0.2f, 0.125f);
	glEnd();

	glBegin(GL_POLYGON);//front

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(0.045f, 0.0f, 0.145f);
	glVertex3f(0.15f, 0.0f, 0.145f);
	glVertex3f(0.12f, -0.055f, 0.145f);
	glVertex3f(0.045f, -0.085f, 0.145f);
	glEnd();

	glBegin(GL_POLYGON);//red

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.045f, 0.0f, 0.135f);
	glVertex3f(0.15f, 0.0f, 0.135f);
	glVertex3f(0.17f, -0.11f, 0.135f);
	glVertex3f(0.045f, -0.17f, 0.135f);
	glEnd();

	glBegin(GL_POLYGON);//left

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.18f, 0.0f, 0.125f);
	glVertex3f(0.20f, -0.12f, 0.125f);
	glVertex3f(0.17f, -0.11f, 0.145f);
	glVertex3f(0.15f, 0.0f, 0.145f);
	glEnd();

	glBegin(GL_POLYGON);//right

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.045f, 0.0f, 0.125f);
	glVertex3f(0.045f, -0.2f, 0.125f);
	glVertex3f(0.045f, -0.17f, 0.145f);
	glVertex3f(0.045f, 0.0f, 0.145f);
	glEnd();

	glBegin(GL_POLYGON);//up

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.045f, 0.0f, 0.125f);
	glVertex3f(0.18f, 0.0f, 0.125f);
	glVertex3f(0.15f, 0.0f, 0.145f);
	glVertex3f(0.045f, 0.0f, 0.145f);
	glEnd();

	glBegin(GL_POLYGON);//down

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.20f, -0.12f, 0.125f);
	glVertex3f(0.045f, -0.2f, 0.125f);
	glVertex3f(0.045f, -0.17f, 0.145f);
	glVertex3f(0.17f, -0.11f, 0.145f);
	glEnd();

	glPopMatrix();

	//move left underwear
	glPushMatrix();

	if (rotationbelt4 > 0.015) {
		rotationbelt4 = 0.015;
		rotationSpeedbelt4 = 0;
	}

	if (rotationbelt4 < 0.0) {
		rotationbelt4 = 0.0;
		rotationSpeedbelt4 = 0;
	}

	rotationbelt4 += rotationSpeedbelt4;
	glTranslatef(-rotationbelt4 * 2, rotationbelt4, rotationbelt4 / 2);

	glBegin(GL_POLYGON);//front

	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex3f(-0.12f, -0.055f, 0.145f);
	glVertex3f(-0.15f, 0.0f, 0.145f);
	glVertex3f(-0.17f, -0.11f, 0.145f);
	glVertex3f(-0.045f, -0.17f, 0.145f);
	glVertex3f(-0.045f, -0.085f, 0.145f);

	glEnd();

	glPopMatrix();

	//move right underwear
	glPushMatrix();

	if (rotationbelt4 > 0.015) {
		rotationbelt4 = 0.015;
		rotationSpeedbelt4 = 0;
	}

	if (rotationbelt4 < 0.0) {
		rotationbelt4 = 0.0;
		rotationSpeedbelt4 = 0;
	}

	rotationbelt4 += rotationSpeedbelt4;
	glTranslatef(rotationbelt4 * 2, rotationbelt4, rotationbelt4 / 2);

	glBegin(GL_POLYGON);//front

	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex3f(0.12f, -0.055f, 0.145f);
	glVertex3f(0.15f, 0.0f, 0.145f);
	glVertex3f(0.17f, -0.11f, 0.145f);
	glVertex3f(0.045f, -0.17f, 0.145f);
	glVertex3f(0.045f, -0.085f, 0.145f);

	glEnd();

	glPopMatrix();

	//black lajiao
	glPushMatrix();

	glBegin(GL_QUADS);//up

	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(0.04f, 0.0f, 0.12f);
	glVertex3f(-0.04f, 0.0f, 0.12f);
	glVertex3f(-0.04f, 0.0f, 0.02f);
	glVertex3f(0.04f, 0.0f, 0.02f);
	glEnd();

	glBegin(GL_QUADS);//down

	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(0.04f, -0.20f, 0.12f);
	glVertex3f(-0.04f, -0.20f, 0.12f);
	glVertex3f(-0.04f, -0.20f, 0.02f);
	glVertex3f(0.04f, -0.20f, 0.02f);
	glEnd();

	glBegin(GL_QUADS);//front

	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(0.04f, 0.0f, 0.12f);
	glVertex3f(-0.04f, 0.0f, 0.12f);
	glVertex3f(-0.04f, -0.20f, 0.12f);
	glVertex3f(0.04f, -0.20f, 0.12f);
	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-0.04f, 0.0f, 0.02f);
	glVertex3f(0.04f, 0.0f, 0.02f);
	glVertex3f(0.04f, -0.20f, 0.02f);
	glVertex3f(-0.04f, -0.20f, 0.02f);
	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(-0.04f, 0.0f, 0.12f);
	glVertex3f(-0.04f, -0.20f, 0.12f);
	glVertex3f(-0.04f, -0.20f, 0.02f);
	glVertex3f(-0.04f, 0.0f, 0.02f);
	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.04f, 0.0f, 0.12f);
	glVertex3f(0.04f, -0.20f, 0.12f);
	glVertex3f(0.04f, -0.20f, 0.02f);
	glVertex3f(0.04f, 0.0f, 0.02f);
	glEnd();

	glPopMatrix();


	//white lanjiao upper
	glPushMatrix();

	if (rotationbelt2 > 40) {
		rotationbelt2 = 40;
		rotationSpeedbelt2 = 0;
	}

	if (rotationbelt2 < 0.0) {
		rotationbelt2 = 0.0;
		rotationSpeedbelt2 = 0;
	}

	glTranslatef(0.0f, 0.0f, +0.12f);

	rotationbelt2 += rotationSpeedbelt2;
	glRotatef(-rotationbelt2, 1.0f, 0.0f, 0.0f);

	glTranslatef(0.0f, 0.0f, -0.12f);

	glBegin(GL_QUADS);//up

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.03f, -0.01f, 0.17f);
	glVertex3f(-0.03f, -0.01f, 0.17f);
	glVertex3f(-0.04f, 0.00f, 0.12f);
	glVertex3f(0.04f, 0.00f, 0.12f);
	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.03f, -0.01f, 0.17f);
	glVertex3f(-0.04f, 0.00f, 0.12f);
	glVertex3f(-0.04f, -0.10f, 0.12f);
	glVertex3f(-0.03f, -0.055f, 0.18f);

	glEnd();

	glBegin(GL_QUADS);//left 2

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.04f, -0.01f, 0.07f);
	glVertex3f(-0.04f, 0.00f, 0.12f);
	glVertex3f(-0.04f, -0.10f, 0.12f);
	glVertex3f(-0.04f, -0.055f, 0.07f);

	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.03f, -0.01f, 0.17f);
	glVertex3f(0.04f, 0.00f, 0.12f);
	glVertex3f(0.04f, -0.10f, 0.12f);
	glVertex3f(0.03f, -0.055f, 0.18f);

	glEnd();

	glBegin(GL_QUADS);//right 2

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.04f, -0.01f, 0.07f);
	glVertex3f(0.04f, 0.00f, 0.12f);
	glVertex3f(0.04f, -0.10f, 0.12f);
	glVertex3f(0.04f, -0.055f, 0.07f);

	glEnd();

	glBegin(GL_QUADS);//front

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.03f, -0.01f, 0.17f);
	glVertex3f(-0.03f, -0.01f, 0.17f);
	glVertex3f(-0.03f, -0.10f, 0.19f);
	glVertex3f(0.03f, -0.10f, 0.19f);
	glEnd();

	glBegin(GL_QUADS);//front(front wall)

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.02f, -0.02f, 0.175f);
	glVertex3f(-0.02f, -0.02f, 0.175f);
	glVertex3f(-0.02f, -0.08f, 0.195f);
	glVertex3f(0.02f, -0.08f, 0.195f);
	glEnd();


	glBegin(GL_QUADS);//front(left wall)

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.03f, -0.01f, 0.17f);
	glVertex3f(-0.03f, -0.10f, 0.19f);
	glVertex3f(-0.02f, -0.08f, 0.195f);
	glVertex3f(-0.02f, -0.02f, 0.175f);

	glEnd();

	glBegin(GL_QUADS);//front(right wall)

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.03f, -0.01f, 0.17f);
	glVertex3f(0.03f, -0.10f, 0.19f);
	glVertex3f(0.02f, -0.08f, 0.195f);
	glVertex3f(0.02f, -0.02f, 0.175f);

	glEnd();

	glBegin(GL_QUADS);//front(down wall)

	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex3f(-0.03f, -0.10f, 0.19f);
	glVertex3f(-0.02f, -0.08f, 0.195f);
	glVertex3f(0.02f, -0.08f, 0.195f);
	glVertex3f(0.03f, -0.10f, 0.19f);

	glEnd();

	glBegin(GL_QUADS);//front(up wall)

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.03f, -0.01f, 0.17f);
	glVertex3f(-0.02f, -0.02f, 0.175f);
	glVertex3f(0.02f, -0.08f, 0.195f);
	glVertex3f(0.03f, -0.10f, 0.19f);

	glEnd();

	glPopMatrix();


	//white lanjiao lowwer
	glPushMatrix();

	if (rotationbelt1 > 30) {
		rotationbelt1 = 30;
		rotationSpeedbelt1 = 0;
	}

	if (rotationbelt1 < 0.0) {
		rotationbelt1 = 0.0;
		rotationSpeedbelt1 = 0;
	}

	glTranslatef(0.0f, -0.20f, 0.12f);

	rotationbelt1 += rotationSpeedbelt1;
	glRotatef(rotationbelt1, 1.0f, 0.0f, 0.0f);

	glTranslatef(0.0f, 0.20f, -0.12f);

	glBegin(GL_QUADS);//front

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.03f, -0.10f, 0.19f);
	glVertex3f(0.03f, -0.10f, 0.19f);
	glVertex3f(0.03f, -0.18f, 0.17f);
	glVertex3f(-0.03f, -0.18f, 0.17f);
	glEnd();

	glBegin(GL_QUADS);//front (front wall)

	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex3f(-0.02f, -0.11f, 0.195f);
	glVertex3f(0.02f, -0.11f, 0.195f);
	glVertex3f(0.02f, -0.17f, 0.18f);
	glVertex3f(-0.02f, -0.17f, 0.18f);
	glEnd();

	glBegin(GL_QUADS);//front (left wall)

	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex3f(-0.02f, -0.11f, 0.195f);
	glVertex3f(-0.02f, -0.17f, 0.18f);
	glVertex3f(-0.03f, -0.18f, 0.17f);
	glVertex3f(-0.03f, -0.10f, 0.19f);
	glEnd();

	glBegin(GL_QUADS);//front (right wall)

	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex3f(0.02f, -0.11f, 0.195f);
	glVertex3f(0.02f, -0.17f, 0.18f);
	glVertex3f(0.03f, -0.18f, 0.17f);
	glVertex3f(0.03f, -0.10f, 0.19f);
	glEnd();

	glBegin(GL_QUADS);//front (up wall)

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.02f, -0.17f, 0.18f);
	glVertex3f(-0.03f, -0.18f, 0.17f);
	glVertex3f(-0.03f, -0.18f, 0.17f);
	glVertex3f(-0.02f, -0.17f, 0.18f);
	glEnd();

	glBegin(GL_QUADS);//front (down wall)

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.02f, -0.11f, 0.195f);
	glVertex3f(0.03f, -0.10f, 0.19f);
	glVertex3f(-0.03f, -0.10f, 0.19f);
	glVertex3f(-0.02f, -0.11f, 0.195f);
	glEnd();

	glBegin(GL_QUADS);//down

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.03f, -0.18f, 0.17f);
	glVertex3f(-0.03f, -0.18f, 0.17f);
	glVertex3f(-0.04f, -0.20f, 0.12f);
	glVertex3f(0.04f, -0.20f, 0.12f);
	glEnd();

	glBegin(GL_POLYGON);//left

	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex3f(-0.04f, -0.10f, 0.12f);
	glVertex3f(-0.03f, -0.055f, 0.18f);
	glVertex3f(-0.03f, -0.10f, 0.19f);
	glVertex3f(-0.03f, -0.18f, 0.17f);
	glVertex3f(-0.04f, -0.20f, 0.12f);

	glEnd();

	glBegin(GL_QUADS);//left 2

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.04f, -0.10f, 0.12f);
	glVertex3f(-0.04f, -0.20f, 0.12f);
	glVertex3f(-0.0375f, -0.20f, 0.07f);
	glVertex3f(-0.0375f, -0.15f, 0.07f);

	glEnd();

	glBegin(GL_POLYGON);//right

	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex3f(0.04f, -0.10f, 0.12f);
	glVertex3f(0.03f, -0.055f, 0.18f);
	glVertex3f(0.03f, -0.10f, 0.19f);
	glVertex3f(0.03f, -0.18f, 0.17f);
	glVertex3f(0.04f, -0.20f, 0.12f);

	glEnd();

	glBegin(GL_QUADS);//right 2

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.04f, -0.10f, 0.12f);
	glVertex3f(0.04f, -0.20f, 0.12f);
	glVertex3f(0.0375f, -0.20f, 0.07f);
	glVertex3f(0.0375f, -0.15f, 0.07f);

	glEnd();

	glPopMatrix();


	//red lanjiao
	glPushMatrix();

	if (rotationbelt3 > 0.03) {
		rotationbelt3 = 0.03;
		rotationSpeedbelt3 = 0;
	}

	if (rotationbelt3 < 0.0) {
		rotationbelt3 = 0.0;
		rotationSpeedbelt3 = 0;
	}

	rotationbelt3 += rotationSpeedbelt3;

	glTranslatef(0.0f, rotationbelt3, rotationbelt3);

	glBegin(GL_QUADS);//front

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.028f, -0.04f, 0.1700f);
	glVertex3f(-0.028f, -0.04f, 0.1700f);
	glVertex3f(-0.028f, -0.16f, 0.180f);
	glVertex3f(0.028f, -0.16f, 0.180f);

	glEnd();

	glBegin(GL_QUADS);//back

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.028f, -0.04f, 0.07f);
	glVertex3f(-0.028f, -0.04f, 0.07f);
	glVertex3f(-0.028f, -0.16f, 0.07f);
	glVertex3f(0.028f, -0.16f, 0.07f);

	glEnd();

	glBegin(GL_QUADS);//left

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.028f, -0.04f, 0.1700f);
	glVertex3f(-0.028f, -0.16f, 0.180f);
	glVertex3f(-0.028f, -0.16f, 0.07f);
	glVertex3f(-0.028f, -0.04f, 0.07f);

	glEnd();

	glBegin(GL_QUADS);//right

	glColor3f(colorr, colorg, colorb);
	glVertex3f(0.028f, -0.04f, 0.1700f);
	glVertex3f(0.028f, -0.16f, 0.180f);
	glVertex3f(0.028f, -0.16f, 0.07f);
	glVertex3f(0.028f, -0.04f, 0.07f);

	glEnd();

	glBegin(GL_QUADS);//up

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.028f, -0.04f, 0.1700f);
	glVertex3f(-0.028f, -0.04f, 0.07f);
	glVertex3f(0.028f, -0.04f, 0.07f);
	glVertex3f(0.028f, -0.04f, 0.1700f);

	glEnd();

	glBegin(GL_QUADS);//down

	glColor3f(colorr, colorg, colorb);
	glVertex3f(-0.028f, -0.16f, 0.180f);
	glVertex3f(-0.028f, -0.16f, 0.07f);
	glVertex3f(0.028f, -0.16f, 0.07f);
	glVertex3f(0.028f, -0.16f, 0.180f);

	glEnd();

	glPopMatrix();


}


void rightSaberAnimation() {

	saberRotationSpeed = 0.1f;

	if (saberRotation == 180) {
		saberYSpeed = 0.002f;
	}

}

void rightSaberAnimationBack() {

	saberYSpeed = -0.002f;

	if (saberY == -0.16f) {
		saberRotationSpeed = -0.1f;
	}

}

void leftSaberAnimation() {

	leftSaberRotationSpeed = 0.1f;

	if (leftSaberRotation == 180) {
		leftSaberYSpeed = 0.0002f;
	}

}

void leftSaberAnimationBack() {

	leftSaberYSpeed = -0.0002f;

	if (leftSaberY == -0.16f) {
		leftSaberRotationSpeed = -0.1f;
	}

}

void animation() {

	rotationSpeedsheild = 0.0015;

	if (rotationFoot < 27.5) {
		rotationSpeedfoot = 0.06f;
		whiteLockerSpeedY = 0.0005f;
		whiteLockerSpeedZ = 0.00010f;
	}

	if (rotationFoot == 27.5f) {
		lowerLegBreakSpeed = 0.0001f;
	}

	if (lowerLegBreak == 0.03f) {
		thrusterRotationSpeed = 0.05f;
		redThrusterRotationSpeed = 0.02f;

	}

	if (thrusterRotation == 30) {
		downKneeBreakSpeed = 0.0001f;
	}

	if (downKneeBreak == 0.02f) {
		upKneeRotationSpeed = 0.05f;
	}

	if (upKneeRotation == 25) {
		upperLegBreakSpeed = 0.0001f;
	}

	if (upperLegBreak == 0.035f) {
		rotationSpeedbelt1 = 0.12;
		rotationSpeedbelt2 = 0.12;
		rotationSpeedbelt3 = 0.00004f;
		rotationSpeedbelt4 = 0.00004f;
		rotationSpeedbelt5 = 0.00004f;
		rotationSpeedbelt6 = 0.12;
	}

	if (rotationbelt2 == 40) {

		rotationSpeedwaist = 0.0002f;

	}

	if (rotationwaist >= 0.03f) {
		rotationSpeedbra = 0.18;
		rotationSpeedarmor = 0.00006f;
	}

	if (rotationbra >= 100) {
		lowerHandBreakSpeed = 0.00010f;
	}

	if (lowerHandBreak >= 0.03f) {
		rotationSpeedshouder1 = 0.0004f;
		rotationSpeedshouder2 = 0.00004f;
		rotationSpeedshouder4 = 0.00004f;
		rotationSpeedshouder3 = 0.12f;

		if (rotationshouder1 >= 0.02f) {
			rotationheadsidespeed = 0.6f;
			rotationSpeedfacea = 0.24f;
			rotationSpeedfaceb = -0.24f;
		}

		if (rotationheadsidea == 180) {
			rotationSpeedhorn = 0.6f;

			colorr = 1.0f;
			colorg = 0.2f;
			colorb = 0.2f;

			color2r = 0.0f;
			color2g = 1.0f;
			color2b = 1.0f;
		}
	}

	//head





}

void backAnimation() {

	rotationSpeedsheild = -0.002;

	rotationSpeedshouder1 = -0.0004f;
	rotationSpeedshouder2 = -0.00004f;
	rotationSpeedshouder3 = -0.12f;
	rotationSpeedshouder4 = -0.00004f;

	if (rotationshouder1 == 0) {
		lowerHandBreakSpeed = -0.00010f;

		colorr = 0.7;
		colorg = 0.7;
		colorb = 0.7;

		color2r = 0.5f;
		color2g = 0.5f;
		color2b = 0.5f;
	}

	if (lowerHandBreak == -0.0f) {
		rotationSpeedbra = -0.18;
		rotationSpeedarmor = -0.00006f;
	}

	if (rotationarmor == 0.00f) {

		rotationSpeedwaist = -0.0002f;

	}

	if (rotationwaist == 0.00f) {

		rotationSpeedbelt1 = -0.12;
		rotationSpeedbelt2 = -0.12;
		rotationSpeedbelt3 = -0.0010f;
		rotationSpeedbelt4 = -0.00004f;
		rotationSpeedbelt5 = -0.00004f;
		rotationSpeedbelt6 = -0.12;

	}

	if (rotationbelt6 == 0.0) {
		upperLegBreakSpeed = -0.00010f;
	}

	if (upperLegBreak == 0.0) {
		upKneeRotationSpeed = -0.05f;

	}

	if (upKneeRotation == 0) {
		downKneeBreakSpeed = -0.0001f;
	}

	if (downKneeBreak == 0.0f) {
		thrusterRotationSpeed = -0.050f;
		redThrusterRotationSpeed = -0.02f;
	}

	if (redThrusterRotation == 0.0) {
		lowerLegBreakSpeed = -0.00010f;
	}

	if (lowerLegBreak == 0.0) {
		if (rotationFoot > 0) {
			rotationSpeedfoot = -0.06f;
			whiteLockerSpeedY = -0.0005f;
			whiteLockerSpeedZ = -0.00010f;


		}


	}

	if (rotationFoot == 0.0f) {

		rotationheadsidespeed = -0.3f;
		rotationSpeedfacea = -0.12f;
		rotationSpeedfaceb = 0.12f;
		rotationSpeedhorn = -0.3f;


	}



	//---------------------------------------


}

void leftSaber() {
	//saber
	glPushMatrix();

	glTranslatef(0.1, -0.2, 0);

	leftSaberY += leftSaberYSpeed;
	leftSaberRotation += leftSaberRotationSpeed;
	glRotatef(-leftSaberRotation, 0, 0, 1);
	glTranslatef(-0.1, 0.2, 0);

	if (leftSaberRotation >= 180) {
		leftSaberRotation = 180;
		leftSaberRotationSpeed = 0.0f;
	}
	else if (leftSaberRotation <= 0) {
		leftSaberRotation = 0;
		leftSaberRotationSpeed = 0.0f;
	}

	if (leftSaberY >= 0.5f) {
		leftSaberY = 0.5f;
		leftSaberYSpeed = 0.0f;
	}
	else if (leftSaberY < -0.16f) {
		leftSaberY = -0.16f;
		leftSaberYSpeed = 0.0f;
	}

	glColor3f(0.4, 0.4, 0.4);
	//front
	glBegin(GL_QUADS);
	glVertex3f(0.1, -0.21, 0.01);
	glVertex3f(0.1, -0.21, -0.01);
	glVertex3f(0.1, -0.16, -0.01);
	glVertex3f(0.1, -0.16, 0.01);
	glEnd();

	//back
	glBegin(GL_QUADS);
	glVertex3f(0.08, -0.21, 0.01);
	glVertex3f(0.08, -0.21, -0.01);
	glVertex3f(0.08, -0.16, -0.01);
	glVertex3f(0.08, -0.16, 0.01);
	glEnd();

	//left
	glBegin(GL_QUADS);
	glVertex3f(0.08, -0.21, 0.01);
	glVertex3f(0.1, -0.21, 0.01);
	glVertex3f(0.1, -0.16, 0.01);
	glVertex3f(0.08, -0.16, 0.01);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glVertex3f(0.08, -0.21, -0.01);
	glVertex3f(0.1, -0.21, -0.01);
	glVertex3f(0.1, -0.16, -0.01);
	glVertex3f(0.08, -0.16, -0.01);
	glEnd();

	//back
	glBegin(GL_QUADS);
	glVertex3f(0.08, -0.21, 0.01);
	glVertex3f(0.1, -0.21, 0.01);
	glVertex3f(0.1, -0.21, -0.01);
	glVertex3f(0.08, -0.21, -0.01);
	glEnd();

	//pyramid
	glColor3f(0.898, 0.388, 1);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.1, -0.16, 0.01);
	glVertex3f(0.1, -0.16, -0.01);
	glVertex3f(0.09, leftSaberY, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.08, -0.16, 0.01);
	glVertex3f(0.08, -0.16, -0.01);
	glVertex3f(0.09, leftSaberY, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.08, -0.16, 0.01);
	glVertex3f(0.1, -0.16, 0.01);
	glVertex3f(0.09, leftSaberY, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.08, -0.16, -0.01);
	glVertex3f(0.1, -0.16, -0.01);
	glVertex3f(0.09, leftSaberY, 0);
	glEnd();

	glPopMatrix();
}

void rightSaber() {
	//saber
	glPushMatrix();

	glTranslatef(0.1, -0.2, 0);

	saberY += saberYSpeed;
	saberRotation += saberRotationSpeed;
	glRotatef(-saberRotation, 0, 0, 1);
	glTranslatef(-0.1, 0.2, 0);

	if (saberRotation >= 180) {
		saberRotation = 180;
		saberRotationSpeed = 0.0f;
	}
	else if (saberRotation <= 0) {
		saberRotation = 0;
		saberRotationSpeed = 0.0f;
	}

	if (saberY >= 0.5f) {
		saberY = 0.5f;
		saberYSpeed = 0.0f;
	}
	else if (saberY < -0.16f) {
		saberY = -0.16f;
		saberYSpeed = 0.0f;
	}

	glColor3f(0.4, 0.4, 0.4);
	//front
	glBegin(GL_QUADS);
	glVertex3f(0.1, -0.21, 0.01);
	glVertex3f(0.1, -0.21, -0.01);
	glVertex3f(0.1, -0.16, -0.01);
	glVertex3f(0.1, -0.16, 0.01);
	glEnd();

	//back
	glBegin(GL_QUADS);
	glVertex3f(0.08, -0.21, 0.01);
	glVertex3f(0.08, -0.21, -0.01);
	glVertex3f(0.08, -0.16, -0.01);
	glVertex3f(0.08, -0.16, 0.01);
	glEnd();

	//left
	glBegin(GL_QUADS);
	glVertex3f(0.08, -0.21, 0.01);
	glVertex3f(0.1, -0.21, 0.01);
	glVertex3f(0.1, -0.16, 0.01);
	glVertex3f(0.08, -0.16, 0.01);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glVertex3f(0.08, -0.21, -0.01);
	glVertex3f(0.1, -0.21, -0.01);
	glVertex3f(0.1, -0.16, -0.01);
	glVertex3f(0.08, -0.16, -0.01);
	glEnd();

	//back
	glBegin(GL_QUADS);
	glVertex3f(0.08, -0.21, 0.01);
	glVertex3f(0.1, -0.21, 0.01);
	glVertex3f(0.1, -0.21, -0.01);
	glVertex3f(0.08, -0.21, -0.01);
	glEnd();

	//pyramid
	glColor3f(0.898, 0.388, 1);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.1, -0.16, 0.01);
	glVertex3f(0.1, -0.16, -0.01);
	glVertex3f(0.09, saberY, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.08, -0.16, 0.01);
	glVertex3f(0.08, -0.16, -0.01);
	glVertex3f(0.09, saberY, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.08, -0.16, 0.01);
	glVertex3f(0.1, -0.16, 0.01);
	glVertex3f(0.09, saberY, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.08, -0.16, -0.01);
	glVertex3f(0.1, -0.16, -0.01);
	glVertex3f(0.09, saberY, 0);
	glEnd();

	glPopMatrix();
}

void legThruster() {
	//red
	glPushMatrix();



	glTranslatef(0, 0.52, 0.02);
	redThrusterRotation += redThrusterRotationSpeed;
	glRotatef(redThrusterRotation, 1, 0, 0);
	//glRotatef(5, 1, 0, 0);
	glTranslatef(0, -0.52, -0.02);

	if (redThrusterRotation >= 15) {
		redThrusterRotation = 15;
		redThrusterRotationSpeed = 0.0f;
	}
	else if (redThrusterRotation <= 0) {
		redThrusterRotation = 0;
		redThrusterRotationSpeed = 0.0f;
	}

	//left
	glColor3f(colorr, colorg, colorb);
	glBegin(GL_POLYGON);
	glVertex3f(-0.025, 0.3, 0.03);
	glVertex3f(-0.035, 0.5, 0.03);
	glVertex3f(-0.035, 0.52, 0.01);
	glVertex3f(-0.025, 0.32, 0.025);
	glEnd();

	//right
	glBegin(GL_POLYGON);
	glVertex3f(0.025, 0.3, 0.03);
	glVertex3f(0.035, 0.5, 0.03);
	glVertex3f(0.035, 0.52, 0.01);
	glVertex3f(0.025, 0.32, 0.025);
	glEnd();

	//up
	glBegin(GL_POLYGON);
	glVertex3f(0.025, 0.32, 0.025);
	glVertex3f(-0.025, 0.32, 0.025);
	glVertex3f(-0.035, 0.52, 0.01);
	glVertex3f(0.035, 0.52, 0.01);
	glEnd();

	//down
	glColor3f(colorr, colorg, colorb);
	glBegin(GL_POLYGON);
	glVertex3f(0.025, 0.3, 0.03);
	glVertex3f(-0.025, 0.3, 0.03);
	glVertex3f(-0.025, 0.32, 0.025);
	glVertex3f(0.025, 0.32, 0.025);
	glEnd();

	glPopMatrix();

	//white
	//left
	glPushMatrix();

	glTranslatef(0, 0.5, 0.02);
	thrusterRotation += thrusterRotationSpeed;
	glRotatef(thrusterRotation, 1, 0, 0);
	glTranslatef(0, -0.5, -0.02);

	if (thrusterRotation >= 30) {
		thrusterRotation = 30;
		thrusterRotationSpeed = 0.0f;
	}
	else if (thrusterRotation <= 0) {
		thrusterRotation = 0;
		thrusterRotationSpeed = 0.0f;
	}


	glColor3f(0.98, 0.98, 0.98);
	glBegin(GL_POLYGON);
	glVertex3f(-0.05, 0.45, -0.035);
	glVertex3f(-0.05, 0.43, -0.015); //2
	glVertex3f(-0.05, 0.43, 0.03);
	glVertex3f(-0.05, 0.47, 0.03);
	glVertex3f(-0.05, 0.48, 0.04);
	glVertex3f(-0.05, 0.55, 0.04);
	glVertex3f(-0.05, 0.62, -0.045);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.04, 0.24, 0.015);
	glVertex3f(-0.04, 0.22, 0.03);
	glVertex3f(-0.05, 0.43, 0.03);
	glVertex3f(-0.05, 0.43, -0.015);
	glEnd();

	//right
	glBegin(GL_POLYGON);
	glVertex3f(0.05, 0.45, -0.035);
	glVertex3f(0.05, 0.43, -0.015); //2
	glVertex3f(0.05, 0.43, 0.03);
	glVertex3f(0.05, 0.47, 0.03);
	glVertex3f(0.05, 0.48, 0.04);
	glVertex3f(0.05, 0.55, 0.04);
	glVertex3f(0.05, 0.62, -0.045);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.04, 0.24, 0.015);
	glVertex3f(0.04, 0.22, 0.03);
	glVertex3f(0.05, 0.43, 0.03);
	glVertex3f(0.05, 0.43, -0.015);
	glEnd();

	//connector
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(0.05, 0.62, -0.045);
	glVertex3f(-0.05, 0.62, -0.045);
	glVertex3f(-0.05, 0.55, 0.04);
	glVertex3f(0.05, 0.55, 0.04);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.05, 0.45, -0.035);
	glVertex3f(-0.05, 0.45, -0.035);
	glVertex3f(-0.05, 0.62, -0.045);
	glVertex3f(0.05, 0.62, -0.045);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.05, 0.43, -0.015);
	glVertex3f(-0.05, 0.43, -0.015);
	glVertex3f(-0.05, 0.45, -0.035);
	glVertex3f(0.05, 0.45, -0.035);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.05, 0.43, -0.015);
	glVertex3f(-0.05, 0.43, -0.015);
	glVertex3f(-0.04, 0.24, 0.015);
	glVertex3f(0.04, 0.24, 0.015);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.04, 0.24, 0.015);
	glVertex3f(-0.04, 0.24, 0.015);
	glVertex3f(-0.04, 0.22, 0.03);
	glVertex3f(0.04, 0.22, 0.03);
	glEnd();

	glPopMatrix();
}

void smallLegShield() {
	//left
	//up
	glColor3f(0.960, 0.960, 0.960);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.06, 0.57, 0.04);
	glVertex3f(-0.08, 0.54, 0.1);
	glVertex3f(-0.06, 0.62, 0.07);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.06, 0.57, 0.16);
	glVertex3f(-0.08, 0.54, 0.1);
	glVertex3f(-0.06, 0.62, 0.13);
	glEnd();

	glColor3f(0.980, 0.980, 0.980);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.06, 0.62, 0.07);
	glVertex3f(-0.08, 0.54, 0.1);
	glVertex3f(-0.06, 0.62, 0.13);
	glEnd();

	//down
	glColor3f(0.960, 0.960, 0.960);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.06, 0.48, 0.04);
	glVertex3f(-0.08, 0.5, 0.1);
	glVertex3f(-0.06, 0.39, 0.07);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.06, 0.48, 0.16);
	glVertex3f(-0.08, 0.5, 0.1);
	glVertex3f(-0.06, 0.39, 0.13);
	glEnd();

	glColor3f(0.980, 0.980, 0.980);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.06, 0.39, 0.07);
	glVertex3f(-0.08, 0.5, 0.1);
	glVertex3f(-0.06, 0.39, 0.13);
	glEnd();

	//middle
	glColor3f(0.940, 0.940, 0.940);
	glBegin(GL_POLYGON);
	glVertex3f(-0.06, 0.57, 0.04);
	glVertex3f(-0.08, 0.54, 0.1);
	glVertex3f(-0.08, 0.5, 0.1);
	glVertex3f(-0.06, 0.48, 0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.06, 0.57, 0.16);
	glVertex3f(-0.08, 0.54, 0.1);
	glVertex3f(-0.08, 0.5, 0.1);
	glVertex3f(-0.06, 0.48, 0.16);
	glEnd();

	glColor3f(0.309, 0.309, 0.309);
	glBegin(GL_QUADS);
	glVertex3f(-0.081, 0.54, 0.1025);
	glVertex3f(-0.081, 0.54, 0.0975);
	glVertex3f(-0.081, 0.5, 0.0975);
	glVertex3f(-0.081, 0.5, 0.1025);
	glEnd();

	//right
	//up
	glColor3f(0.960, 0.960, 0.960);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.06, 0.57, 0.04);
	glVertex3f(0.08, 0.54, 0.1);
	glVertex3f(0.06, 0.62, 0.07);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.06, 0.57, 0.16);
	glVertex3f(0.08, 0.54, 0.1);
	glVertex3f(0.06, 0.62, 0.13);
	glEnd();

	glColor3f(0.980, 0.980, 0.980);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.06, 0.62, 0.07);
	glVertex3f(0.08, 0.54, 0.1);
	glVertex3f(0.06, 0.62, 0.13);
	glEnd();

	//down
	glColor3f(0.960, 0.960, 0.960);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.06, 0.48, 0.04);
	glVertex3f(0.08, 0.5, 0.1);
	glVertex3f(0.06, 0.39, 0.07);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.06, 0.48, 0.16);
	glVertex3f(0.08, 0.5, 0.1);
	glVertex3f(0.06, 0.39, 0.13);
	glEnd();

	glColor3f(0.980, 0.980, 0.980);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.06, 0.39, 0.07);
	glVertex3f(0.08, 0.5, 0.1);
	glVertex3f(0.06, 0.39, 0.13);
	glEnd();

	//middle
	glColor3f(0.940, 0.940, 0.940);
	glBegin(GL_POLYGON);
	glVertex3f(0.06, 0.57, 0.04);
	glVertex3f(0.08, 0.54, 0.1);
	glVertex3f(0.08, 0.5, 0.1);
	glVertex3f(0.06, 0.48, 0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.06, 0.57, 0.16);
	glVertex3f(0.08, 0.54, 0.1);
	glVertex3f(0.08, 0.5, 0.1);
	glVertex3f(0.06, 0.48, 0.16);
	glEnd();

	glColor3f(0.309, 0.309, 0.309);
	glBegin(GL_QUADS);
	glVertex3f(0.081, 0.54, 0.1025);
	glVertex3f(0.081, 0.54, 0.0975);
	glVertex3f(0.081, 0.5, 0.0975);
	glVertex3f(0.081, 0.5, 0.1025);
	glEnd();

	//back
	glColor3f(0.935, 0.935, 0.935);
	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.57, 0.04);
	glVertex3f(0.06, 0.57, 0.04);
	glVertex3f(0.06, 0.48, 0.04);
	glVertex3f(-0.06, 0.48, 0.04);
	glEnd();

	glColor3f(0.955, 0.955, 0.955);
	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.57, 0.04);
	glVertex3f(0.06, 0.57, 0.04);
	glVertex3f(0.06, 0.62, 0.07);
	glVertex3f(-0.06, 0.62, 0.07);
	glEnd();

	//front
	glColor3f(0.935, 0.935, 0.935);
	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.57, 0.16);
	glVertex3f(0.06, 0.57, 0.16);
	glVertex3f(0.06, 0.48, 0.16);
	glVertex3f(-0.06, 0.48, 0.16);
	glEnd();

	glColor3f(0.955, 0.955, 0.955);
	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.57, 0.16);
	glVertex3f(0.06, 0.57, 0.16);
	glVertex3f(0.06, 0.62, 0.13);
	glVertex3f(-0.06, 0.62, 0.13);
	glEnd();
}

void leftSmallLeg() {
	//front
	glPushMatrix();
	glTranslatef(0, -0.02, 0);

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.42, 0.17);
	glVertex3f(-0.03, 0.42, 0.17);
	glVertex3f(-0.02, 0.44, 0.17);
	glVertex3f(-0.06, 0.44, 0.17);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.06, 0.42, 0.17);
	glVertex3f(0.03, 0.42, 0.17);
	glVertex3f(0.02, 0.44, 0.17);
	glVertex3f(0.06, 0.44, 0.17);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.44, 0.17);
	glVertex3f(0.06, 0.44, 0.17);
	glVertex3f(0.06, 0.5, 0.17);
	glVertex3f(-0.06, 0.5, 0.17);
	glEnd();

	//back
	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.42, 0.03);
	glVertex3f(-0.03, 0.42, 0.03);
	glVertex3f(-0.02, 0.44, 0.03);
	glVertex3f(-0.06, 0.44, 0.03);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.06, 0.42, 0.03);
	glVertex3f(0.03, 0.42, 0.03);
	glVertex3f(0.02, 0.44, 0.03);
	glVertex3f(0.06, 0.44, 0.03);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.44, 0.03);
	glVertex3f(0.06, 0.44, 0.03);
	glVertex3f(0.06, 0.5, 0.03);
	glVertex3f(-0.06, 0.5, 0.03);
	glEnd();

	//left
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.06, 0.42, 0.03);
	glVertex3f(-0.06, 0.45, 0.06);
	glVertex3f(-0.06, 0.45, 0.03);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.06, 0.42, 0.17);
	glVertex3f(-0.06, 0.45, 0.17);
	glVertex3f(-0.06, 0.45, 0.14);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.45, 0.03);
	glVertex3f(-0.06, 0.45, 0.17);
	glVertex3f(-0.06, 0.5, 0.17);
	glVertex3f(-0.06, 0.5, 0.03);
	glEnd();

	//right
	glBegin(GL_TRIANGLES);
	glVertex3f(0.06, 0.42, 0.03);
	glVertex3f(0.06, 0.45, 0.06);
	glVertex3f(0.06, 0.45, 0.03);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.06, 0.42, 0.17);
	glVertex3f(0.06, 0.45, 0.17);
	glVertex3f(0.06, 0.45, 0.14);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.06, 0.45, 0.03);
	glVertex3f(0.06, 0.45, 0.17);
	glVertex3f(0.06, 0.5, 0.17);
	glVertex3f(0.06, 0.5, 0.03);
	glEnd();


	//bent inside
	//front
	glColor3f(0.95, 0.95, 0.95);
	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.5, 0.17);
	glVertex3f(0.06, 0.5, 0.17);
	glVertex3f(0.05, 0.52, 0.15);
	glVertex3f(-0.05, 0.52, 0.15);
	glEnd();

	//back
	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.5, 0.03);
	glVertex3f(0.06, 0.5, 0.03);
	glVertex3f(0.05, 0.52, 0.05);
	glVertex3f(-0.05, 0.52, 0.05);
	glEnd();

	glColor3f(0.92, 0.92, 0.92);
	//left
	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.5, 0.03);
	glVertex3f(-0.06, 0.5, 0.17);
	glVertex3f(-0.05, 0.52, 0.15);
	glVertex3f(-0.05, 0.52, 0.05);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glVertex3f(0.06, 0.5, 0.03);
	glVertex3f(0.06, 0.5, 0.17);
	glVertex3f(0.05, 0.52, 0.15);
	glVertex3f(0.05, 0.52, 0.05);
	glEnd();

	glPopMatrix();
}

void leftBigLegDown() {

	glColor3f(0.960, 0.960, 0.960);
	glTranslatef(0, 0, 0.02);
	//below curve inside part
	//front
	glBegin(GL_QUADS);
	glVertex3f(-0.07, 0.68, 0.155);
	glVertex3f(0.07, 0.68, 0.155);
	glVertex3f(0.078, 0.75, 0.18);
	glVertex3f(-0.078, 0.75, 0.18);
	glEnd();

	//back
	glBegin(GL_QUADS);
	glVertex3f(-0.07, 0.68, 0.04);
	glVertex3f(0.07, 0.68, 0.04);
	glVertex3f(0.078, 0.75, 0.02);
	glVertex3f(-0.078, 0.75, 0.02);
	glEnd();

	//below
	glColor3f(0.941, 0.941, 0.941);
	glBegin(GL_QUADS);
	glVertex3f(-0.07, 0.68, 0.155);
	glVertex3f(0.07, 0.68, 0.155);
	glVertex3f(0.07, 0.68, 0.04);
	glVertex3f(-0.07, 0.68, 0.04);
	glEnd();

	//right
	glColor3f(0.921, 0.921, 0.921);
	glBegin(GL_QUADS);
	glVertex3f(0.07, 0.68, 0.155);
	glVertex3f(0.07, 0.68, 0.04);
	glVertex3f(0.078, 0.75, 0.02);
	glVertex3f(0.078, 0.75, 0.18);
	glEnd();

	//left
	glColor3f(0.941, 0.941, 0.941);
	glBegin(GL_QUADS);
	glVertex3f(-0.07, 0.68, 0.155);
	glVertex3f(-0.07, 0.68, 0.04);
	glVertex3f(-0.078, 0.75, 0.02);
	glVertex3f(-0.078, 0.75, 0.18);
	glEnd();

	//bigleg body
	//front
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(-0.078, 0.75, 0.18);
	glVertex3f(-0.058, 0.75, 0.18);
	glVertex3f(-0.058, 0.8, 0.18);
	glVertex3f(-0.078, 0.79, 0.18); //connect to left
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.058, 0.75, 0.18);
	glVertex3f(0.058, 0.75, 0.18);
	glVertex3f(0.058, 0.88, 0.18);
	glVertex3f(-0.058, 0.82, 0.18);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.058, 0.75, 0.18);
	glVertex3f(0.078, 0.75, 0.18);
	glVertex3f(0.078, 0.91, 0.18);  //connect to right
	glVertex3f(0.058, 0.9, 0.18);
	glEnd();

	//back
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(-0.078, 0.75, 0.02);
	glVertex3f(-0.058, 0.75, 0.02);
	glVertex3f(-0.058, 0.8, 0.02);
	glVertex3f(-0.078, 0.79, 0.02);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.058, 0.75, 0.02);
	glVertex3f(0.058, 0.75, 0.02);
	glVertex3f(0.058, 0.88, 0.02);
	glVertex3f(-0.058, 0.82, 0.02);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.058, 0.75, 0.02);
	glVertex3f(0.078, 0.75, 0.02);
	glVertex3f(0.078, 0.91, 0.02);
	glVertex3f(0.058, 0.9, 0.02);
	glEnd();

	//left
	glColor3f(0.858, 0.858, 0.858);
	glBegin(GL_QUADS);
	glVertex3f(-0.078, 0.75, 0.02);
	glVertex3f(-0.078, 0.75, 0.18);
	glVertex3f(-0.078, 0.79, 0.18);
	glVertex3f(-0.078, 0.79, 0.02);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.078, 0.79, 0.02);
	glVertex3f(-0.078, 0.79, 0.1);
	glVertex3f(-0.078, 0.81, 0.1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.078, 0.79, 0.1);
	glVertex3f(-0.078, 0.79, 0.18);
	glVertex3f(-0.078, 0.81, 0.1);
	glEnd();

	//right
	glColor3f(0.858, 0.858, 0.858);
	glBegin(GL_QUADS);
	glVertex3f(0.078, 0.75, 0.02);
	glVertex3f(0.078, 0.75, 0.18);
	glVertex3f(0.078, 0.89, 0.18);
	glVertex3f(0.078, 0.89, 0.02);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.078, 0.89, 0.02);
	glVertex3f(0.078, 0.89, 0.1);
	glVertex3f(0.078, 0.91, 0.02);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.078, 0.89, 0.1);
	glVertex3f(0.078, 0.89, 0.18);
	glVertex3f(0.078, 0.91, 0.18);
	glEnd();














	//lines
	glLineWidth(1.5);
	glColor3f(0.74, 0.74, 0.74);

	glBegin(GL_LINES);
	glVertex3f(-0.058, 0.75, 0.1801);
	glVertex3f(-0.058, 1, 0.1801);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.058, 0.75, 0.1801);
	glVertex3f(0.058, 1.0, 0.1801);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-0.058, 0.75, 0.0199);
	glVertex3f(-0.058, 1, 0.0199);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.058, 0.75, 0.0199);
	glVertex3f(0.058, 1.0, 0.0199);
	glEnd();


}

void rightBigLegDown() {

	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, -0.25);
	leftBigLegDown();

}

void leftBigLegUp() {
	glColor3f(0.90, 0.90, 0.90);
	glTranslatef(0, 0, 0.02);

	//red inside
	glColor3f(colorr, colorg, colorb);
	glBegin(GL_QUADS);
	glVertex3f(-0.068, 0.75, 0.17);
	glVertex3f(0.068, 0.75, 0.17);
	glVertex3f(0.068, 0.95, 0.17);
	glVertex3f(-0.068, 0.95, 0.17);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.068, 0.75, 0.03);
	glVertex3f(0.068, 0.75, 0.03);
	glVertex3f(0.068, 0.95, 0.03);
	glVertex3f(-0.068, 0.95, 0.03);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.068, 0.75, 0.03);
	glVertex3f(-0.068, 0.75, 0.17);
	glVertex3f(-0.068, 0.95, 0.17);
	glVertex3f(-0.068, 0.95, 0.03);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.068, 0.75, 0.03);
	glVertex3f(0.068, 0.75, 0.17);
	glVertex3f(0.068, 0.95, 0.17);
	glVertex3f(0.068, 0.95, 0.03);
	glEnd();

	//bigleg body
	//front
	glColor3f(0.90, 0.90, 0.90);
	glBegin(GL_QUADS);
	glVertex3f(-0.078, 0.79, 0.18); //connect to left
	glVertex3f(-0.058, 0.8, 0.18);
	glVertex3f(-0.058, 1.0, 0.18);
	glVertex3f(-0.078, 1, 0.18);
	glEnd();

	glBegin(GL_QUADS);

	glVertex3f(-0.058, 0.82, 0.18);
	glVertex3f(0.058, 0.88, 0.18);
	glVertex3f(0.058, 1, 0.18);
	glVertex3f(-0.058, 1, 0.18);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.058, 0.9, 0.18);
	glVertex3f(0.078, 0.91, 0.18);  //connect to right
	glVertex3f(0.078, 1, 0.18);
	glVertex3f(0.058, 1, 0.18);
	glEnd();


	//back
	glColor3f(0.90, 0.90, 0.90);
	glBegin(GL_QUADS);
	glVertex3f(-0.078, 0.79, 0.02); //connect to left
	glVertex3f(-0.058, 0.8, 0.02);
	glVertex3f(-0.058, 1.0, 0.02);
	glVertex3f(-0.078, 1, 0.02);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.058, 0.82, 0.02);
	glVertex3f(0.058, 0.88, 0.02);
	glVertex3f(0.058, 1, 0.02);
	glVertex3f(-0.058, 1, 0.02);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.058, 0.9, 0.02);
	glVertex3f(0.078, 0.91, 0.02);  //connect to right
	glVertex3f(0.078, 1, 0.02);
	glVertex3f(0.058, 1, 0.02);
	glEnd();

	//left
	glColor3f(0.80, 0.80, 0.80);
	glBegin(GL_QUADS);
	glVertex3f(-0.078, 0.81, 0.02);
	glVertex3f(-0.078, 0.81, 0.18);
	glVertex3f(-0.078, 1, 0.18);
	glVertex3f(-0.078, 1, 0.02);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.078, 0.79, 0.02);
	glVertex3f(-0.078, 0.81, 0.1);
	glVertex3f(-0.078, 0.81, 0.02);
	glEnd();

	glBegin(GL_TRIANGLES);

	glVertex3f(-0.078, 0.79, 0.18);
	glVertex3f(-0.078, 0.81, 0.1);
	glVertex3f(-0.078, 0.81, 0.18);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glVertex3f(0.078, 0.91, 0.02);
	glVertex3f(0.078, 0.91, 0.18);
	glVertex3f(0.078, 1, 0.18);
	glVertex3f(0.078, 1, 0.02);
	glEnd();

	glBegin(GL_TRIANGLES);

	glVertex3f(0.078, 0.89, 0.1);
	glVertex3f(0.078, 0.91, 0.02);
	glVertex3f(0.078, 0.91, 0.1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(0.078, 0.89, 0.1);
	glVertex3f(0.078, 0.91, 0.18);
	glVertex3f(0.078, 0.91, 0.1);
	glEnd();
}

void rightBigLegUp() {
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, -0.25);
	leftBigLegUp();
}

void leftLegUpJoint() {
	//joint
	glPushMatrix();
	glColor3f(0.2, 0.2, 0.2);

	glTranslatef(-0.07, 0.65, 0.1);
	glRotatef(90, 0, 1, 0);
	gluQuadricDrawStyle(leftLegUpperJoint, GLU_FILL);
	gluCylinder(leftLegUpperJoint, 0.05, 0.05, 0.14, 100, 1);

	//circle
	//left
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);
	for (int angle = 0; angle <= 360; angle++)
	{
		float tempz = 0.05 * cos(angle * 3.142 / 180);
		float tempy = 0.05 * sin(angle * 3.142 / 180);
		glVertex3f(0, tempy, tempz);

	}
	glEnd();

	//right
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(0.14, 0, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);
	for (int angle = 0; angle <= 360; angle++)
	{
		float tempz = 0.05 * cos(angle * 3.142 / 180);
		float tempy = 0.05 * sin(angle * 3.142 / 180);
		glVertex3f(0, tempy, tempz);

	}
	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

	//inner joint
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);

	glTranslatef(-0.04, 0.65, 0.1);
	glRotatef(90, 0, 1, 0);
	gluQuadricDrawStyle(leftLegUpperJointInner, GLU_FILL);
	gluCylinder(leftLegUpperJointInner, 0.07, 0.07, 0.08, 100, 1);

	//circle
	//left
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);
	for (int angle = 0; angle <= 360; angle++)
	{
		float tempz = 0.07 * cos(angle * 3.142 / 180);
		float tempy = 0.07 * sin(angle * 3.142 / 180);
		glVertex3f(0, tempy, tempz);

	}
	glEnd();

	//right
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(0.08, 0, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);
	for (int angle = 0; angle <= 360; angle++)
	{
		float tempz = 0.07 * cos(angle * 3.142 / 180);
		float tempy = 0.07 * sin(angle * 3.142 / 180);
		glVertex3f(0, tempy, tempz);

	}
	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

void leftLegDownJoint() {
	//joint
	glPushMatrix();
	glColor3f(0.2, 0.2, 0.2);

	glTranslatef(-0.1, 0.25, 0.1);
	glRotatef(90, 0, 1, 0);
	gluQuadricDrawStyle(leftLegLowerJoint, GLU_FILL);
	gluCylinder(leftLegLowerJoint, 0.04, 0.04, 0.2, 100, 1);

	//circle
	//left
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);
	for (int angle = 0; angle <= 360; angle++)
	{
		float tempz = 0.04 * cos(angle * 3.142 / 180);
		float tempy = 0.04 * sin(angle * 3.142 / 180);
		glVertex3f(0, tempy, tempz);

	}
	glEnd();

	//right
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(0.2, 0, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);
	for (int angle = 0; angle <= 360; angle++)
	{
		float tempz = 0.04 * cos(angle * 3.142 / 180);
		float tempy = 0.04 * sin(angle * 3.142 / 180);
		glVertex3f(0, tempy, tempz);

	}
	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

	//inner joint
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);

	glTranslatef(-0.061, 0.25, 0.1);
	glRotatef(90, 0, 1, 0);
	gluQuadricDrawStyle(leftLegLowerJointInner, GLU_FILL);
	gluCylinder(leftLegLowerJointInner, 0.07, 0.07, 0.122, 100, 1);

	//circle
	//left
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);
	for (int angle = 0; angle <= 360; angle++)
	{
		float tempz = 0.07 * cos(angle * 3.142 / 180);
		float tempy = 0.07 * sin(angle * 3.142 / 180);
		glVertex3f(0, tempy, tempz);

	}
	glEnd();

	//right
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(0.122, 0, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);
	for (int angle = 0; angle <= 360; angle++)
	{
		float tempz = 0.07 * cos(angle * 3.142 / 180);
		float tempy = 0.07 * sin(angle * 3.142 / 180);
		glVertex3f(0, tempy, tempz);

	}
	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

void leftFoot() {
	glColor3f(0.129, 0.137, 0.329);
	//foot blue inside
	//down
	glBegin(GL_POLYGON);
	glVertex3f(-0.05, 0, 0.5);
	glVertex3f(0.05, 0, 0.5);
	glVertex3f(0.1, 0, 0.3);
	glVertex3f(0.1, 0, 0);
	glVertex3f(-0.1, 0, 0);
	glVertex3f(-0.1, 0, 0.3);
	glEnd();

	//back
	glBegin(GL_QUADS);
	glVertex3f(-0.1, 0, 0.0);
	glVertex3f(0.1, 0, 0);
	glVertex3f(0.1, 0.2, 0);
	glVertex3f(-0.1, 0.2, 0);

	glEnd();

	//front
	glColor3f(0.229, 0.237, 0.429);
	glBegin(GL_POLYGON);
	glVertex3f(-0.05, 0, 0.5);
	glVertex3f(0.05, 0, 0.5);
	glVertex3f(0.03, 0.05, 0.47);
	glVertex3f(-0.03, 0.05, 0.47);
	glEnd();

	//right
	glColor3f(0.429, 0.437, 0.629);
	glBegin(GL_POLYGON);
	glVertex3f(0.05, 0, 0.5);
	glVertex3f(0.1, 0, 0.3);
	glVertex3f(0.1, 0.2, 0.2);
	glVertex3f(0.03, 0.05, 0.47);
	glEnd();

	glColor3f(0.529, 0.537, 0.729);
	glBegin(GL_POLYGON);
	glVertex3f(0.1, 0, 0.3);
	glVertex3f(0.1, 0, 0);
	glVertex3f(0.1, 0.2, 0);
	glVertex3f(0.1, 0.2, 0.2);
	glEnd();

	//left
	glColor3f(0.429, 0.437, 0.629);
	glBegin(GL_POLYGON);
	glVertex3f(-0.05, 0, 0.5);
	glVertex3f(-0.1, 0, 0.3);
	glVertex3f(-0.1, 0.2, 0.2);
	glVertex3f(-0.03, 0.05, 0.47);
	glEnd();

	glColor3f(0.529, 0.537, 0.729);
	glBegin(GL_POLYGON);
	glVertex3f(-0.1, 0, 0.3);
	glVertex3f(-0.1, 0, 0);
	glVertex3f(-0.1, 0.2, 0);
	glVertex3f(-0.1, 0.2, 0.2);
	glEnd();

	//up
	glColor3f(0.109, 0.107, 0.309);
	glBegin(GL_POLYGON);
	glVertex3f(-0.03, 0.05, 0.47);
	glVertex3f(0.03, 0.05, 0.47);

	glVertex3f(0.1, 0.2, 0.2);
	glVertex3f(-0.1, 0.2, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.1, 0.2, 0.2);
	glVertex3f(0.1, 0.2, 0);
	glVertex3f(-0.1, 0.2, 0);
	glVertex3f(-0.1, 0.2, 0.2);

	glEnd();



	//upper foot white locker


	glPushMatrix();

	whiteLockerY += whiteLockerSpeedY;
	whiteLockerZ -= whiteLockerSpeedZ;
	glTranslatef(0, whiteLockerY, whiteLockerZ);

	//glTranslatef(0.0f, 0.172f, 0.04f);
	rotationFoot += rotationSpeedfoot;
	glRotatef(rotationFoot, 1.0f, 0.0f, 0.0f);

	if (rotationFoot >= 27.5f) {
		rotationFoot = 27.5f;
		whiteLockerSpeedY = 0.0f;
		whiteLockerSpeedZ = 0.0f;

	}

	if (rotationFoot <= 0.0f) {
		rotationFoot = 0.0f;
		whiteLockerSpeedY = 0.0f;
		whiteLockerSpeedZ = 0.0f;
		rotationSpeedfoot = 0.0f;

	}

	//inside de small shell
	glColor3f(0.95, 0.95, 0.95);
	glBegin(GL_QUADS);
	glVertex3f(-0.07, 0.135, 0.32);
	glVertex3f(0.07, 0.135, 0.32);
	glVertex3f(0.11, 0.214, 0.18);
	glVertex3f(-0.11, 0.214, 0.18);

	glEnd();

	//right
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.07, 0.135, 0.32);
	glVertex3f(0.0968, 0.15, 0.26);
	glVertex3f(0.11, 0.214, 0.18);
	glEnd();

	//left
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.07, 0.135, 0.32);
	glVertex3f(-0.0968, 0.15, 0.26);
	glVertex3f(-0.11, 0.214, 0.18);
	glEnd();

	glPopMatrix();

	

	leftLegDownJoint();

	//back low circle
	//left
	glColor3f(0.95, 0.95, 0.95);
	glBegin(GL_POLYGON);
	glVertex3f(-0.11, 0.15, -0.02);
	glVertex3f(-0.11, 0.105, 0.04);
	glVertex3f(-0.11, 0.105, 0.188);
	glVertex3f(-0.11, 0.22, 0.06);
	glVertex3f(-0.11, 0.22, -0.02);
	glEnd();

	//right
	glBegin(GL_POLYGON);
	glVertex3f(0.11, 0.15, -0.02);
	glVertex3f(0.11, 0.105, 0.04);
	glVertex3f(0.11, 0.105, 0.188);
	glVertex3f(0.11, 0.22, 0.06);
	glVertex3f(0.11, 0.22, -0.02);
	glEnd();

	//back
	glColor3f(0.92, 0.92, 0.92);
	glBegin(GL_QUADS);
	glVertex3f(0.11, 0.15, -0.02);
	glVertex3f(-0.11, 0.15, -0.02);
	glVertex3f(-0.11, 0.22, -0.02);
	glVertex3f(0.11, 0.22, -0.02);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.11, 0.15, -0.01);
	glVertex3f(-0.11, 0.15, -0.01);
	glVertex3f(-0.11, 0.22, -0.01);
	glVertex3f(0.11, 0.22, -0.01);
	glEnd();

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_QUADS);
	glVertex3f(0.11, 0.22, -0.02);
	glVertex3f(-0.11, 0.22, -0.02);
	glVertex3f(-0.11, 0.22, -0.01);
	glVertex3f(0.11, 0.22, -0.01);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.11, 0.15, -0.02);
	glVertex3f(-0.11, 0.15, -0.02);
	glVertex3f(-0.11, 0.15, -0.01);
	glVertex3f(0.11, 0.15, -0.01);
	glEnd();
}

void leftSmallLegBreakDown() {
	//inner de
	//front
	glPushMatrix();
	glTranslatef(0, -0.02, 0);
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.33, 0.17);
	glVertex3f(0.06, 0.33, 0.17);
	glVertex3f(0.06, 0.42, 0.17);
	glVertex3f(-0.06, 0.42, 0.17);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.03, 0.42, 0.17);
	glVertex3f(0.03, 0.42, 0.17);
	glVertex3f(0.02, 0.44, 0.17);
	glVertex3f(-0.02, 0.44, 0.17);
	glEnd();

	//back
	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.33, 0.03);
	glVertex3f(0.06, 0.33, 0.03);
	glVertex3f(0.06, 0.42, 0.03);
	glVertex3f(-0.06, 0.42, 0.03);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.03, 0.42, 0.03);
	glVertex3f(0.03, 0.42, 0.03);
	glVertex3f(0.02, 0.44, 0.03);
	glVertex3f(-0.02, 0.44, 0.03);
	glEnd();

	//left
	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.33, 0.03);
	glVertex3f(-0.06, 0.33, 0.17);
	glVertex3f(-0.06, 0.42, 0.17);
	glVertex3f(-0.06, 0.42, 0.03);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.06, 0.42, 0.03);
	glVertex3f(-0.06, 0.42, 0.17);
	glVertex3f(-0.06, 0.45, 0.14);
	glVertex3f(-0.06, 0.45, 0.06);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glVertex3f(0.06, 0.33, 0.03);
	glVertex3f(0.06, 0.33, 0.17);
	glVertex3f(0.06, 0.42, 0.17);
	glVertex3f(0.06, 0.42, 0.03);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.06, 0.42, 0.03);
	glVertex3f(0.06, 0.42, 0.17);
	glVertex3f(0.06, 0.45, 0.14);
	glVertex3f(0.06, 0.45, 0.06);
	glEnd();
	glPopMatrix();

	//small leg front down
	//front
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_QUADS);
	glVertex3f(-0.095, 0.25, 0.18);
	glVertex3f(0.095, 0.25, 0.18);
	glVertex3f(0.095, 0.32, 0.21);
	glVertex3f(-0.095, 0.32, 0.21);
	glEnd();

	glColor3f(0.9, 0.9, 0.9);
	//left
	glBegin(GL_QUADS);
	glVertex3f(-0.095, 0.23, 0.16);
	glVertex3f(-0.095, 0.25, 0.18);
	glVertex3f(-0.095, 0.32, 0.21);
	glVertex3f(-0.095, 0.32, 0.11);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glVertex3f(0.095, 0.23, 0.16);
	glVertex3f(0.095, 0.25, 0.18);
	glVertex3f(0.095, 0.32, 0.21);
	glVertex3f(0.095, 0.32, 0.11);
	glEnd();

	//upper bit
	//front
	glColor3f(0.85, 0.85, 0.85);
	glBegin(GL_QUADS);
	glVertex3f(-0.095, 0.32, 0.21);
	glVertex3f(0.095, 0.32, 0.21);
	glVertex3f(0.095, 0.45, 0.195);
	glVertex3f(-0.095, 0.45, 0.195);
	glEnd();

	//left
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_POLYGON);
	glVertex3f(-0.095, 0.32, 0.11);
	glVertex3f(-0.095, 0.32, 0.21);
	glVertex3f(-0.095, 0.45, 0.195);
	glVertex3f(-0.095, 0.44, 0.16);
	glEnd();


	//right
	glBegin(GL_POLYGON);
	glVertex3f(0.095, 0.32, 0.11);
	glVertex3f(0.095, 0.32, 0.21);
	glVertex3f(0.095, 0.45, 0.195);
	glVertex3f(0.095, 0.44, 0.16);
	glEnd();




	//lower back 
	//back
	glColor3f(0.9, 0.9, 0.9);


	//left
	glBegin(GL_POLYGON);
	glVertex3f(-0.095, 0.27, 0.02);
	glVertex3f(-0.095, 0.24, 0.042);
	glVertex3f(-0.095, 0.32, 0.09);
	glVertex3f(-0.095, 0.38, 0.05);
	glVertex3f(-0.095, 0.4, -0.02);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.085, 0.27, 0.02);
	glVertex3f(-0.085, 0.24, 0.042);
	glVertex3f(-0.085, 0.32, 0.085);
	glVertex3f(-0.085, 0.38, 0.05);
	glVertex3f(-0.085, 0.4, -0.02);
	glEnd();

	//left thick
	glColor3f(0.85, 0.85, 0.85);
	glBegin(GL_POLYGON);
	glVertex3f(-0.085, 0.27, 0.02);
	glVertex3f(-0.095, 0.27, 0.02);
	glVertex3f(-0.095, 0.24, 0.042);
	glVertex3f(-0.085, 0.24, 0.042);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.085, 0.24, 0.042);
	glVertex3f(-0.095, 0.24, 0.042);
	glVertex3f(-0.095, 0.32, 0.09);
	glVertex3f(-0.085, 0.32, 0.09);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.085, 0.32, 0.09);
	glVertex3f(-0.095, 0.32, 0.09);
	glVertex3f(-0.095, 0.38, 0.05);
	glVertex3f(-0.085, 0.38, 0.05);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.085, 0.38, 0.05);
	glVertex3f(-0.095, 0.38, 0.05);
	glVertex3f(-0.095, 0.4, -0.02);
	glVertex3f(-0.085, 0.4, -0.02);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.085, 0.4, -0.02);
	glVertex3f(-0.095, 0.4, -0.02);
	glVertex3f(-0.095, 0.27, 0.02);
	glVertex3f(-0.085, 0.27, 0.02);
	glEnd();

	//right
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_POLYGON);
	glVertex3f(0.095, 0.27, 0.02);
	glVertex3f(0.095, 0.24, 0.042);
	glVertex3f(0.095, 0.32, 0.09);
	glVertex3f(0.095, 0.38, 0.05);
	glVertex3f(0.095, 0.4, -0.02);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.085, 0.27, 0.02);
	glVertex3f(0.085, 0.24, 0.042);
	glVertex3f(0.085, 0.32, 0.085);
	glVertex3f(0.085, 0.38, 0.05);
	glVertex3f(0.085, 0.4, -0.02);
	glEnd();

	//right thick
	glColor3f(0.85, 0.85, 0.85);
	glBegin(GL_POLYGON);
	glVertex3f(0.085, 0.27, 0.02);
	glVertex3f(0.095, 0.27, 0.02);
	glVertex3f(0.095, 0.24, 0.042);
	glVertex3f(0.085, 0.24, 0.042);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.085, 0.24, 0.042);
	glVertex3f(0.095, 0.24, 0.042);
	glVertex3f(0.095, 0.32, 0.09);
	glVertex3f(0.085, 0.32, 0.09);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.085, 0.32, 0.09);
	glVertex3f(0.095, 0.32, 0.09);
	glVertex3f(0.095, 0.38, 0.05);
	glVertex3f(0.085, 0.38, 0.05);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.085, 0.38, 0.05);
	glVertex3f(0.095, 0.38, 0.05);
	glVertex3f(0.095, 0.4, -0.02);
	glVertex3f(0.085, 0.4, -0.02);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.085, 0.4, -0.02);
	glVertex3f(0.095, 0.4, -0.02);
	glVertex3f(0.095, 0.27, 0.02);
	glVertex3f(0.085, 0.27, 0.02);
	glEnd();

	
}

void rightArmJoints() {
	//joint
	glPushMatrix();
	glColor3f(0.2, 0.2, 0.2);

	glTranslatef(-0.026, -0.115, 0);
	glRotatef(90, 0, 1, 0);
	gluQuadricDrawStyle(rightArmJoint, GLU_FILL);
	gluCylinder(rightArmJoint, 0.0125, 0.0125, 0.052, 100, 1);

	//circle
	//left
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);
	for (int angle = 0; angle <= 360; angle++)
	{
		float tempz = 0.0125 * cos(angle * 3.142 / 180);
		float tempy = 0.0125 * sin(angle * 3.142 / 180);
		glVertex3f(0, tempy, tempz);

	}
	glEnd();

	//right
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(0.052, 0, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);
	for (int angle = 0; angle <= 360; angle++)
	{
		float tempz = 0.0125 * cos(angle * 3.142 / 180);
		float tempy = 0.0125 * sin(angle * 3.142 / 180);
		glVertex3f(0, tempy, tempz);

	}
	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

	//inner joint
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);

	glTranslatef(-0.0135, -0.115, 0);
	glRotatef(90, 0, 1, 0);
	gluQuadricDrawStyle(rightArmJointInner, GLU_FILL);
	gluCylinder(rightArmJointInner, 0.025, 0.025, 0.027, 100, 1);

	//circle
	//left
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);
	for (int angle = 0; angle <= 360; angle++)
	{
		float tempz = 0.025 * cos(angle * 3.142 / 180);
		float tempy = 0.025 * sin(angle * 3.142 / 180);
		glVertex3f(0, tempy, tempz);

	}
	glEnd();

	//right
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	glTranslatef(0.027, 0, 0);
	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);
	for (int angle = 0; angle <= 360; angle++)
	{
		float tempz = 0.025 * cos(angle * 3.142 / 180);
		float tempy = 0.025 * sin(angle * 3.142 / 180);
		glVertex3f(0, tempy, tempz);

	}
	glEnd();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

void knee() {
	//red inside
	glColor3f(colorr,colorg,colorb);

	//left
	glBegin(GL_POLYGON);
	glVertex3f(-0.041,0.55,0.13);
	glVertex3f(-0.041, 0.63, 0.20);
	glVertex3f(-0.041, 0.67, 0.20);
	glVertex3f(-0.041, 0.69, 0.18);
	glVertex3f(-0.041, 0.68, 0.13);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.041, 0.55, 0.13);
	glVertex3f(0.041, 0.63, 0.20);
	glVertex3f(0.041, 0.67, 0.20);
	glVertex3f(0.041, 0.69, 0.18);
	glVertex3f(0.041, 0.68, 0.13);
	glEnd();

	//below
	glBegin(GL_POLYGON);
	glVertex3f(-0.041, 0.55, 0.13);
	glVertex3f(0.041, 0.55, 0.13);
	glVertex3f(0.041, 0.63, 0.20);
	glVertex3f(-0.041, 0.63, 0.20);
	glEnd();

	//up
	glBegin(GL_POLYGON);	
	glVertex3f(-0.041, 0.68, 0.13);
	glVertex3f(0.041, 0.68, 0.13);
	glVertex3f(0.041, 0.69, 0.18);
	glVertex3f(-0.041, 0.69, 0.18);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.041, 0.69, 0.18);
	glVertex3f(-0.041, 0.69, 0.18);
	glVertex3f(-0.041, 0.67, 0.20);
	glVertex3f(0.041, 0.67, 0.20);
	glEnd();

	//front
	glBegin(GL_POLYGON);
	glVertex3f(-0.041, 0.63, 0.20);
	glVertex3f(0.041, 0.63, 0.20);
	glVertex3f(0.041, 0.67, 0.20);
	glVertex3f(-0.041, 0.67, 0.20);
	glEnd();

	//upper armor
	glPushMatrix();

	upKneeRotation += upKneeRotationSpeed;

	glTranslatef(-0.05, 0.681, 0.13);
	glRotatef(-upKneeRotation, 1, 0, 0);
	glTranslatef(0.05, -0.681, -0.13);

	if (upKneeRotation >= 25) {
		upKneeRotation = 25;
		upKneeRotationSpeed = 0.0f;
	}else if (upKneeRotation <= 0) {
		upKneeRotation = 0;
		upKneeRotationSpeed = 0.0f;
	}

	glColor3f(0.96,0.96,0.96);

	//left
	glBegin(GL_POLYGON);
	glVertex3f(-0.05,0.62,0.13);
	glVertex3f(-0.05, 0.66, 0.21);
	glVertex3f(-0.05, 0.72, 0.21);
	glVertex3f(-0.05, 0.681, 0.13);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.05, 0.62, 0.13);
	glVertex3f(0.05, 0.66, 0.21);
	glVertex3f(0.05, 0.72, 0.21);
	glVertex3f(0.05, 0.681, 0.13);
	glEnd();

	//up
	glBegin(GL_POLYGON);
	glVertex3f(-0.05, 0.72, 0.21);
	glVertex3f(0.05, 0.72, 0.21);
	glVertex3f(0.05, 0.681, 0.13);
	glVertex3f(-0.05, 0.681, 0.13);
	glEnd();

	//front
	glColor3f(0.98, 0.98, 0.98);
	glBegin(GL_POLYGON);
	glVertex3f(-0.05, 0.66, 0.21);
	glVertex3f(0.05, 0.66, 0.21);
	glVertex3f(0.05, 0.72, 0.21);
	glVertex3f(-0.05, 0.72, 0.21);
	glEnd();

	

	glPopMatrix();

	//lower armor
	glPushMatrix();
	glColor3f(0.90, 0.90, 0.90);

	downKneeBreak += downKneeBreakSpeed;
	glTranslatef(0, -downKneeBreak, 0);

	if (downKneeBreak >= 0.02f) {
		downKneeBreak = 0.02f;
		downKneeBreakSpeed = 0.0f;
	}
	else if (downKneeBreak <= 0.0f) {
		downKneeBreak = 0.0f;
		downKneeBreakSpeed = 0.0f;
	}

	glBegin(GL_POLYGON);
	glVertex3f(-0.05, 0.54, 0.13);
	glVertex3f(-0.05, 0.62, 0.21);
	glVertex3f(-0.05, 0.66, 0.21);
	glVertex3f(-0.05, 0.62, 0.13);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.05, 0.54, 0.13);
	glVertex3f(0.05, 0.62, 0.21);
	glVertex3f(0.05, 0.66, 0.21);
	glVertex3f(0.05, 0.62, 0.13);
	glEnd();

	//down
	glBegin(GL_POLYGON);
	glVertex3f(-0.05, 0.54, 0.13);
	glVertex3f(0.05, 0.54, 0.13);
	glVertex3f(0.05, 0.62, 0.21);
	glVertex3f(-0.05, 0.62, 0.21);
	glEnd();

	//front
	glColor3f(0.92, 0.92, 0.92);
	glBegin(GL_POLYGON);
	glVertex3f(-0.05, 0.62, 0.21);
	glVertex3f(0.05, 0.62, 0.21);
	glVertex3f(0.05, 0.66, 0.21);
	glVertex3f(-0.05, 0.66, 0.21);
	glEnd();
	glPopMatrix();

}

void leftLeg() {
	//leg up
	glPushMatrix();
	/*glRotatef(-5, 0, 0, 1);
	glTranslatef(-0.115, -1.05, -0.1);*/
	
	
	

	glTranslatef(0.0, 1, 0.1);
	////////glRotatef(-5, 0, 0, 1);
	glRotatef(leftLeg1, 1, 0, 0);


	glRotatef(leftLeg2, 0, 1, 0);

	glRotatef(leftLeg3, 0, 0, 1);

	
	

	////glRotatef(5, 0, 0, 1);
	glTranslatef(0.0, -1, -0.1);
	//to centre

	



	//upper break
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0, 0.9, 0);
	glScalef(0.8, 1, 0.8);
	glTranslatef(0, -0.9, 0);
	leftBigLegUp();
	glPopMatrix();

	//middle break
	glPushMatrix();
	upperLegBreak += upperLegBreakSpeed;
	glTranslatef(0, -upperLegBreak, 0);

	if (upperLegBreak >= 0.035f) {
		upperLegBreak = 0.035f;
		upperLegBreakSpeed = 0.0f;
	}
	else if (upperLegBreak <= 0) {
		upperLegBreak = 0.0f;
		upperLegBreakSpeed = 0.0f;
	}



	glPushMatrix();
	glTranslatef(0, 0.8, 0);
	glScalef(0.8, 1, 0.8);
	glTranslatef(0, -0.8, 0);
	leftBigLegDown();
	glPopMatrix();
	
	

	


	//leg middle
	glPushMatrix();

	glTranslatef(0, 0.65, 0.1);

	glRotatef(leftLeg4, 1, 0, 0);


	glTranslatef(0, -0.65, -0.1);
	//to centre

	leftLegUpJoint();
	knee();
	leftSmallLeg();
	legThruster();
	smallLegShield();
	



	
	

	//lower break move down
	glPushMatrix();

	lowerLegBreak += lowerLegBreakSpeed;
	glTranslatef(0, -lowerLegBreak, 0);

	if (lowerLegBreak >= 0.03f) {
		lowerLegBreak = 0.03f;
		lowerLegBreakSpeed = 0.0f;
	}
	else if (lowerLegBreak <= 0) {
		lowerLegBreak = 0.0f;
		lowerLegBreakSpeed = 0.0f;
	}


	//bone
	glPushMatrix();
	glColor3f(0.15, 0.15, 0.15);

	glTranslatef(0, 0.2, 0.1);
	glRotatef(45, 0.0f, 1.0f, 0.0f);
	glRotatef(270, 1.0f, 0.0f, 0.0f);
	gluQuadricDrawStyle(leftLegBone, GLU_FILL);
	gluCylinder(leftLegBone, 0.06, 0.06, 0.40, 4, 1);

	glPopMatrix();

	glPushMatrix();
	glColor3f(colorr, colorg, colorb);

	glTranslatef(0, 0.37, 0.1);
	glRotatef(45, 0.0f, 1.0f, 0.0f);
	glRotatef(270, 1.0f, 0.0f, 0.0f);
	gluQuadricDrawStyle(leftLegRedBone, GLU_FILL);
	gluCylinder(leftLegRedBone, 0.08, 0.08, 0.1, 4, 1);

	glPopMatrix();

	

	leftSmallLegBreakDown();
	
	
	
	
	
	//leg down
	glPushMatrix();
	glTranslatef(0, 0.25, 0.1);

	glRotatef(leftLeg5, 1, 0, 0);


	glRotatef(leftLeg6, 0, 0, 1);
	

	glTranslatef(0, -0.25, -0.1);
	//to centre
	
	leftFoot();

	glPopMatrix();






	glPopMatrix();

	glPopMatrix();


	
	glPopMatrix();

	//leg middle
	glPopMatrix();

	

	//leg up
	glPopMatrix();
}

void rightLeg() {
	//leg up
	glPushMatrix();
	/*glRotatef(-5, 0, 0, 1);
	glTranslatef(-0.115, -1.05, -0.1);*/



	glTranslatef(0.0, 1, 0.1);
	////////glRotatef(-5, 0, 0, 1);

	glRotatef(rightLeg1, 1, 0, 0);


	glRotatef(rightLeg2, 0, 1, 0);


	glRotatef(rightLeg3, 0, 0, 1);



	////glRotatef(5, 0, 0, 1);
	glTranslatef(0.0, -1, -0.1);
	//to centre





	//upper break
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0, 0.9, 0);
	glScalef(0.8, 1, 0.8);
	glTranslatef(0, -0.9, 0);
	rightBigLegUp();
	glPopMatrix();

	//middle break
	glPushMatrix();
	upperLegBreak += upperLegBreakSpeed;
	glTranslatef(0, -upperLegBreak, 0);

	if (upperLegBreak >= 0.035f) {
		upperLegBreak = 0.035f;
		upperLegBreakSpeed = 0.0f;
	}
	else if (upperLegBreak <= 0) {
		upperLegBreak = 0.0f;
		upperLegBreakSpeed = 0.0f;
	}



	glPushMatrix();
	glTranslatef(0, 0.8, 0);
	glScalef(0.8, 1, 0.8);
	glTranslatef(0, -0.8, 0);
	rightBigLegDown();
	glPopMatrix();






	//leg middle
	glPushMatrix();
	glTranslatef(0, 0.65, 0.1);

	glRotatef(rightLeg4, 1, 0, 0);


	glTranslatef(0, -0.65, -0.1);
	//to centre

	leftLegUpJoint();
	knee();
	leftSmallLeg();
	legThruster();
	smallLegShield();







	//lower break move down
	glPushMatrix();

	lowerLegBreak += lowerLegBreakSpeed;
	glTranslatef(0, -lowerLegBreak, 0);

	if (lowerLegBreak >= 0.03f) {
		lowerLegBreak = 0.03f;
		lowerLegBreakSpeed = 0.0f;
	}
	else if (lowerLegBreak <= 0) {
		lowerLegBreak = 0.0f;
		lowerLegBreakSpeed = 0.0f;
	}


	//bone
	glPushMatrix();
	glColor3f(0.15, 0.15, 0.15);

	glTranslatef(0, 0.2, 0.1);
	glRotatef(45, 0.0f, 1.0f, 0.0f);
	glRotatef(270, 1.0f, 0.0f, 0.0f);
	gluQuadricDrawStyle(leftLegBone, GLU_FILL);
	gluCylinder(leftLegBone, 0.06, 0.06, 0.40, 4, 1);

	glPopMatrix();

	glPushMatrix();
	glColor3f(colorr, colorg, colorb);

	glTranslatef(0, 0.37, 0.1);
	glRotatef(45, 0.0f, 1.0f, 0.0f);
	glRotatef(270, 1.0f, 0.0f, 0.0f);
	gluQuadricDrawStyle(leftLegRedBone, GLU_FILL);
	gluCylinder(leftLegRedBone, 0.08, 0.08, 0.1, 4, 1);

	glPopMatrix();



	leftSmallLegBreakDown();





	//leg down
	glPushMatrix();
	glTranslatef(0, 0.25, 0.1);

	glRotatef(rightLeg5, 1, 0, 0);


	glRotatef(rightLeg6, 0, 0, 1);

	glTranslatef(0, -0.25, -0.1);
	//to centre

	leftFoot();

	glPopMatrix();






	glPopMatrix();

	glPopMatrix();



	glPopMatrix();

	//leg middle
	glPopMatrix();



	//leg up
	glPopMatrix();
}

void hand() {
	//upper hand
	//front


	glColor3f(0.8, 0.8, 0.8);

	glPushMatrix();
	glTranslatef(0, 0.0, 0);
	glScalef(1.4, 1.2, 1.2);

	glBegin(GL_QUADS);
	glVertex3f(-0.025, -0.09, 0.025);
	glVertex3f(0.025, -0.09, 0.025);
	glVertex3f(0.025, 0.06, 0.025);
	glVertex3f(-0.025, 0.06, 0.025);
	glEnd();

	//back
	glBegin(GL_QUADS);
	glVertex3f(-0.025, -0.09, -0.025);
	glVertex3f(0.025, -0.09, -0.025);
	glVertex3f(0.025, 0.06, -0.025);
	glVertex3f(-0.025, 0.06, -0.025);
	glEnd();

	//left
	glBegin(GL_QUADS);
	glVertex3f(-0.025, -0.09, -0.025);
	glVertex3f(-0.025, -0.09, 0.025);
	glVertex3f(-0.025, 0.06, 0.025);
	glVertex3f(-0.025, 0.06, -0.025);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glVertex3f(0.025, -0.09, -0.025);
	glVertex3f(0.025, -0.09, 0.025);
	glVertex3f(0.025, 0.06, 0.025);
	glVertex3f(0.025, 0.06, -0.025);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.025, 0.06, 0.025);
	glVertex3f(0.025, 0.06, 0.025);
	glVertex3f(0.025, 0.06, -0.025);
	glVertex3f(-0.025, 0.06, -0.025);
	glEnd();



	//curve in
	glBegin(GL_QUADS);
	glVertex3f(-0.015, -0.1, 0.015);
	glVertex3f(0.015, -0.1, 0.015);
	glVertex3f(0.025, -0.09, 0.025);
	glVertex3f(-0.025, -0.09, 0.025);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.015, -0.1, -0.015);
	glVertex3f(0.015, -0.1, -0.015);
	glVertex3f(0.025, -0.09, -0.025);
	glVertex3f(-0.025, -0.09, -0.025);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.015, -0.1, -0.015);
	glVertex3f(-0.015, -0.1, 0.015);
	glVertex3f(-0.025, -0.09, 0.025);
	glVertex3f(-0.025, -0.09, -0.025);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.015, -0.1, -0.015);
	glVertex3f(0.015, -0.1, 0.015);
	glVertex3f(0.025, -0.09, 0.025);
	glVertex3f(0.025, -0.09, -0.025);
	glEnd();

	glPopMatrix();




}

void rightBighand()
{
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(1.4, 1.2, 1.4);

	rightArmJoints();

	//big hand
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_QUADS);
	glVertex3f(-0.04, -0.15, 0.04);
	glVertex3f(0.04, -0.15, 0.04);
	glVertex3f(0.025, -0.13, 0.025);
	glVertex3f(-0.025, -0.13, 0.025);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.04, -0.15, -0.04);
	glVertex3f(0.04, -0.15, -0.04);
	glVertex3f(0.025, -0.13, -0.025);
	glVertex3f(-0.025, -0.13, -0.025);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.04, -0.15, -0.04);
	glVertex3f(-0.04, -0.15, 0.04);
	glVertex3f(-0.025, -0.13, 0.025);
	glVertex3f(-0.025, -0.13, -0.025);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.04, -0.15, -0.04);
	glVertex3f(0.04, -0.15, 0.04);
	glVertex3f(0.025, -0.13, 0.025);
	glVertex3f(0.025, -0.13, -0.025);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.025, -0.13, 0.025);
	glVertex3f(-0.025, -0.13, 0.025);
	glVertex3f(-0.025, -0.13, -0.025);
	glVertex3f(0.025, -0.13, -0.025);
	glEnd();

	//upperbreak
	glBegin(GL_POLYGON);
	glVertex3f(-0.04, -0.20, 0.04);
	glVertex3f(0.04, -0.24, 0.04);
	glVertex3f(0.04, -0.15, 0.04);
	glVertex3f(-0.04, -0.15, 0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.04, -0.20, -0.04);
	glVertex3f(0.04, -0.24, -0.04);
	glVertex3f(0.04, -0.15, -0.04);
	glVertex3f(-0.04, -0.15, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.04, -0.20, -0.04);
	glVertex3f(-0.04, -0.20, 0.04);
	glVertex3f(-0.04, -0.15, 0.04);
	glVertex3f(-0.04, -0.15, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.24, -0.04);
	glVertex3f(0.04, -0.24, 0.04);
	glVertex3f(0.04, -0.15, 0.04);
	glVertex3f(0.04, -0.15, -0.04);
	glEnd();

	//outter hand
	//front
	glColor3f(0.95, 0.95, 0.95);
	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.26, 0.04);
	glVertex3f(0.10, -0.23, 0.04);
	glVertex3f(0.10, -0.04, 0.04);
	glVertex3f(0.08, -0.04, 0.04);
	glVertex3f(0.04, -0.08, 0.04);
	glEnd();

	//thick
	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.26, 0.025);
	glVertex3f(0.10, -0.23, 0.025);
	glVertex3f(0.10, -0.04, 0.025);
	glVertex3f(0.08, -0.04, 0.025);
	glVertex3f(0.04, -0.08, 0.025);
	glEnd();

	//back
	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.26, -0.04);
	glVertex3f(0.10, -0.23, -0.04);
	glVertex3f(0.10, -0.04, -0.04);
	glVertex3f(0.08, -0.04, -0.04);
	glVertex3f(0.04, -0.08, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.26, -0.025);
	glVertex3f(0.10, -0.23, -0.025);
	glVertex3f(0.10, -0.04, -0.025);
	glVertex3f(0.08, -0.04, -0.025);
	glVertex3f(0.04, -0.08, -0.025);
	glEnd();

	//thick de wall
	glColor3f(0.96, 0.96, 0.96);
	glBegin(GL_QUADS);
	glVertex3f(0.1, -0.23, 0.04);
	glVertex3f(0.1, -0.23, 0.025);
	glVertex3f(0.1, -0.04, 0.025);
	glVertex3f(0.1, -0.04, 0.04);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.1, -0.23, -0.04);
	glVertex3f(0.1, -0.23, -0.025);
	glVertex3f(0.1, -0.04, -0.025);
	glVertex3f(0.1, -0.04, -0.04);
	glEnd();

	//left
	glBegin(GL_QUADS);
	glVertex3f(0.04, -0.26, -0.04);
	glVertex3f(0.04, -0.26, 0.04);
	glVertex3f(0.04, -0.08, 0.04);
	glVertex3f(0.04, -0.08, -0.04);
	glEnd();

	//lower up
	glBegin(GL_QUADS);
	glVertex3f(0.04, -0.08, -0.04);
	glVertex3f(0.04, -0.08, 0.04);
	glVertex3f(0.08, -0.04, 0.04);
	glVertex3f(0.08, -0.04, -0.04);
	glEnd();

	//up up
	glBegin(GL_QUADS);
	glVertex3f(0.08, -0.04, -0.04);
	glVertex3f(0.08, -0.04, 0.04);
	glVertex3f(0.1, -0.04, 0.04);
	glVertex3f(0.1, -0.04, -0.04);
	glEnd();

	//middle de wall
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_QUADS);
	glVertex3f(0.04, -0.14, -0.04);
	glVertex3f(0.04, -0.14, 0.04);
	glVertex3f(0.1, -0.11, 0.04);
	glVertex3f(0.1, -0.11, -0.04);
	glEnd();

	glColor3f(0.96, 0.96, 0.96);
	glBegin(GL_QUADS);
	glVertex3f(0.1, -0.11, 0.04);
	glVertex3f(0.1, -0.11, -0.04);
	glVertex3f(0.1, -0.04, -0.04);
	glVertex3f(0.1, -0.04, 0.04);
	glEnd();


	//below de wall
	//middle
	glBegin(GL_QUADS);
	glVertex3f(0.04, -0.26, -0.04);
	glVertex3f(0.04, -0.26, 0.04);
	glVertex3f(0.06, -0.25, 0.04);
	glVertex3f(0.06, -0.25, -0.04);
	glEnd();

	//left (front)
	glBegin(GL_QUADS);
	glVertex3f(0.04, -0.26, 0.04);
	glVertex3f(0.04, -0.26, 0.025);
	glVertex3f(0.1, -0.23, 0.025);
	glVertex3f(0.1, -0.23, 0.04);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.04, -0.26, -0.04);
	glVertex3f(0.04, -0.26, -0.025);
	glVertex3f(0.1, -0.23, -0.025);
	glVertex3f(0.1, -0.23, -0.04);
	glEnd();

	//inside de wall
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_QUADS);
	glVertex3f(0.06, -0.25, 0.04);
	glVertex3f(0.06, -0.25, -0.04);
	glVertex3f(0.06, -0.06, -0.04);
	glVertex3f(0.06, -0.06, 0.04);
	glEnd();

	//red inside for outter hand
	glColor3f(colorr, colorg, colorb);
	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.29, 0.034);
	glVertex3f(0.08, -0.27, 0.034);
	glVertex3f(0.08, -0.24, 0.034);
	glVertex3f(0.04, -0.26, 0.034);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.29, -0.034);
	glVertex3f(0.08, -0.27, -0.034);
	glVertex3f(0.08, -0.24, -0.034);
	glVertex3f(0.04, -0.26, -0.034);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.08, -0.27, 0.034);
	glVertex3f(0.08, -0.27, -0.034);
	glVertex3f(0.08, -0.24, -0.034);
	glVertex3f(0.08, -0.24, 0.034);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.29, -0.034);
	glVertex3f(0.04, -0.29, 0.034);
	glVertex3f(0.04, -0.26, 0.034);
	glVertex3f(0.04, -0.26, -0.034);
	glEnd();

	glColor3f(0.95, 0.95, 0.95);
	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.26, -0.034);
	glVertex3f(0.04, -0.26, 0.034);
	glVertex3f(0.08, -0.24, 0.034);
	glVertex3f(0.08, -0.24, -0.034);
	glEnd();

	//red inside for inside
	glColor3f(colorr, colorg, colorb);
	glBegin(GL_QUADS);
	glVertex3f(-0.03, -0.28, 0.03);
	glVertex3f(0.04, -0.28, 0.03);
	glVertex3f(0.04, -0.16, 0.03);
	glVertex3f(-0.03, -0.16, 0.03);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.03, -0.28, -0.03);
	glVertex3f(0.04, -0.28, -0.03);
	glVertex3f(0.04, -0.16, -0.03);
	glVertex3f(-0.03, -0.16, -0.03);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.03, -0.28, -0.03);
	glVertex3f(-0.03, -0.28, 0.03);
	glVertex3f(-0.03, -0.16, 0.03);
	glVertex3f(-0.03, -0.16, -0.03);
	glEnd();

	rightSaber();


	//sheild

	glPushMatrix();

	if (rightshield == 1) {
		glTranslatef(+0.110, -0.15, 0);
		glRotatef(90, 0.0f, 1.0f, 0.0f);
		shield();
	}

	glPopMatrix();

	//lowerbreak
	glPushMatrix();


	lowerHandBreak += lowerHandBreakSpeed;
	glTranslatef(0, -lowerHandBreak, 0);
	if (lowerHandBreak >= 0.03f) {
		lowerHandBreak = 0.03f;
		lowerHandBreakSpeed = 0.0f;
	}
	else if (lowerHandBreak <= 0.0f) {
		lowerHandBreak = 0.0f;
		lowerHandBreakSpeed = 0.0f;
	}

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-0.04, -0.3, 0.04);
	glVertex3f(0.04, -0.3, 0.04);
	glVertex3f(0.04, -0.24, 0.04);
	glVertex3f(-0.04, -0.20, 0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.04, -0.3, -0.04);
	glVertex3f(0.04, -0.3, -0.04);
	glVertex3f(0.04, -0.24, -0.04);
	glVertex3f(-0.04, -0.20, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.04, -0.3, -0.04);
	glVertex3f(-0.04, -0.3, 0.04);
	glVertex3f(-0.04, -0.20, 0.04);
	glVertex3f(-0.04, -0.20, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.3, -0.04);
	glVertex3f(0.04, -0.3, 0.04);
	glVertex3f(0.04, -0.24, 0.04);
	glVertex3f(0.04, -0.24, -0.04);
	glEnd();

	//outter part low
	glColor3f(0.98, 0.98, 0.98);
	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.295, 0.038);
	glVertex3f(0.085, -0.272, 0.038);
	glVertex3f(0.085, -0.234, 0.038);  //23
	glVertex3f(0.04, -0.26, 0.038);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.295, -0.038);
	glVertex3f(0.085, -0.272, -0.038);
	glVertex3f(0.085, -0.234, -0.038);
	glVertex3f(0.04, -0.26, -0.038);
	glEnd();

	//down
	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.295, 0.038);
	glVertex3f(0.04, -0.295, -0.038);
	glVertex3f(0.085, -0.272, -0.038);
	glVertex3f(0.085, -0.272, 0.038);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.085, -0.272, -0.038);
	glVertex3f(0.085, -0.272, 0.038);
	glVertex3f(0.085, -0.234, 0.038);
	glVertex3f(0.085, -0.234, -0.038);
	glEnd();

	glPopMatrix();

	glPopMatrix();


}

void leftBighand()
{
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(1.4, 1.2, 1.4);

	rightArmJoints();

	//big hand
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_QUADS);
	glVertex3f(-0.04, -0.15, 0.04);
	glVertex3f(0.04, -0.15, 0.04);
	glVertex3f(0.025, -0.13, 0.025);
	glVertex3f(-0.025, -0.13, 0.025);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.04, -0.15, -0.04);
	glVertex3f(0.04, -0.15, -0.04);
	glVertex3f(0.025, -0.13, -0.025);
	glVertex3f(-0.025, -0.13, -0.025);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.04, -0.15, -0.04);
	glVertex3f(-0.04, -0.15, 0.04);
	glVertex3f(-0.025, -0.13, 0.025);
	glVertex3f(-0.025, -0.13, -0.025);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.04, -0.15, -0.04);
	glVertex3f(0.04, -0.15, 0.04);
	glVertex3f(0.025, -0.13, 0.025);
	glVertex3f(0.025, -0.13, -0.025);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.025, -0.13, 0.025);
	glVertex3f(-0.025, -0.13, 0.025);
	glVertex3f(-0.025, -0.13, -0.025);
	glVertex3f(0.025, -0.13, -0.025);
	glEnd();

	//upperbreak
	glBegin(GL_POLYGON);
	glVertex3f(-0.04, -0.20, 0.04);
	glVertex3f(0.04, -0.24, 0.04);
	glVertex3f(0.04, -0.15, 0.04);
	glVertex3f(-0.04, -0.15, 0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.04, -0.20, -0.04);
	glVertex3f(0.04, -0.24, -0.04);
	glVertex3f(0.04, -0.15, -0.04);
	glVertex3f(-0.04, -0.15, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.04, -0.20, -0.04);
	glVertex3f(-0.04, -0.20, 0.04);
	glVertex3f(-0.04, -0.15, 0.04);
	glVertex3f(-0.04, -0.15, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.24, -0.04);
	glVertex3f(0.04, -0.24, 0.04);
	glVertex3f(0.04, -0.15, 0.04);
	glVertex3f(0.04, -0.15, -0.04);
	glEnd();



	//outter hand
	//front
	glColor3f(0.95, 0.95, 0.95);
	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.26, 0.04);
	glVertex3f(0.10, -0.23, 0.04);
	glVertex3f(0.10, -0.04, 0.04);
	glVertex3f(0.08, -0.04, 0.04);
	glVertex3f(0.04, -0.08, 0.04);
	glEnd();

	//thick
	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.26, 0.025);
	glVertex3f(0.10, -0.23, 0.025);
	glVertex3f(0.10, -0.04, 0.025);
	glVertex3f(0.08, -0.04, 0.025);
	glVertex3f(0.04, -0.08, 0.025);
	glEnd();

	//back
	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.26, -0.04);
	glVertex3f(0.10, -0.23, -0.04);
	glVertex3f(0.10, -0.04, -0.04);
	glVertex3f(0.08, -0.04, -0.04);
	glVertex3f(0.04, -0.08, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.26, -0.025);
	glVertex3f(0.10, -0.23, -0.025);
	glVertex3f(0.10, -0.04, -0.025);
	glVertex3f(0.08, -0.04, -0.025);
	glVertex3f(0.04, -0.08, -0.025);
	glEnd();

	//thick de wall
	glColor3f(0.96, 0.96, 0.96);
	glBegin(GL_QUADS);
	glVertex3f(0.1, -0.23, 0.04);
	glVertex3f(0.1, -0.23, 0.025);
	glVertex3f(0.1, -0.04, 0.025);
	glVertex3f(0.1, -0.04, 0.04);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.1, -0.23, -0.04);
	glVertex3f(0.1, -0.23, -0.025);
	glVertex3f(0.1, -0.04, -0.025);
	glVertex3f(0.1, -0.04, -0.04);
	glEnd();

	//left
	glBegin(GL_QUADS);
	glVertex3f(0.04, -0.26, -0.04);
	glVertex3f(0.04, -0.26, 0.04);
	glVertex3f(0.04, -0.08, 0.04);
	glVertex3f(0.04, -0.08, -0.04);
	glEnd();

	//lower up
	glBegin(GL_QUADS);
	glVertex3f(0.04, -0.08, -0.04);
	glVertex3f(0.04, -0.08, 0.04);
	glVertex3f(0.08, -0.04, 0.04);
	glVertex3f(0.08, -0.04, -0.04);
	glEnd();

	//up up
	glBegin(GL_QUADS);
	glVertex3f(0.08, -0.04, -0.04);
	glVertex3f(0.08, -0.04, 0.04);
	glVertex3f(0.1, -0.04, 0.04);
	glVertex3f(0.1, -0.04, -0.04);
	glEnd();

	//middle de wall
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_QUADS);
	glVertex3f(0.04, -0.14, -0.04);
	glVertex3f(0.04, -0.14, 0.04);
	glVertex3f(0.1, -0.11, 0.04);
	glVertex3f(0.1, -0.11, -0.04);
	glEnd();

	glColor3f(0.96, 0.96, 0.96);
	glBegin(GL_QUADS);
	glVertex3f(0.1, -0.11, 0.04);
	glVertex3f(0.1, -0.11, -0.04);
	glVertex3f(0.1, -0.04, -0.04);
	glVertex3f(0.1, -0.04, 0.04);
	glEnd();


	//below de wall
	//middle
	glBegin(GL_QUADS);
	glVertex3f(0.04, -0.26, -0.04);
	glVertex3f(0.04, -0.26, 0.04);
	glVertex3f(0.06, -0.25, 0.04);
	glVertex3f(0.06, -0.25, -0.04);
	glEnd();

	//left (front)
	glBegin(GL_QUADS);
	glVertex3f(0.04, -0.26, 0.04);
	glVertex3f(0.04, -0.26, 0.025);
	glVertex3f(0.1, -0.23, 0.025);
	glVertex3f(0.1, -0.23, 0.04);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.04, -0.26, -0.04);
	glVertex3f(0.04, -0.26, -0.025);
	glVertex3f(0.1, -0.23, -0.025);
	glVertex3f(0.1, -0.23, -0.04);
	glEnd();

	//inside de wall
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_QUADS);
	glVertex3f(0.06, -0.25, 0.04);
	glVertex3f(0.06, -0.25, -0.04);
	glVertex3f(0.06, -0.06, -0.04);
	glVertex3f(0.06, -0.06, 0.04);
	glEnd();

	//red inside for outter hand
	glColor3f(colorr, colorg, colorb);
	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.29, 0.034);
	glVertex3f(0.08, -0.27, 0.034);
	glVertex3f(0.08, -0.24, 0.034);
	glVertex3f(0.04, -0.26, 0.034);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.29, -0.034);
	glVertex3f(0.08, -0.27, -0.034);
	glVertex3f(0.08, -0.24, -0.034);
	glVertex3f(0.04, -0.26, -0.034);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.08, -0.27, 0.034);
	glVertex3f(0.08, -0.27, -0.034);
	glVertex3f(0.08, -0.24, -0.034);
	glVertex3f(0.08, -0.24, 0.034);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.29, -0.034);
	glVertex3f(0.04, -0.29, 0.034);
	glVertex3f(0.04, -0.26, 0.034);
	glVertex3f(0.04, -0.26, -0.034);
	glEnd();

	glColor3f(0.95, 0.95, 0.95);
	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.26, -0.034);
	glVertex3f(0.04, -0.26, 0.034);
	glVertex3f(0.08, -0.24, 0.034);
	glVertex3f(0.08, -0.24, -0.034);
	glEnd();

	//red inside for inside
	glColor3f(colorr, colorg, colorb);
	glBegin(GL_QUADS);
	glVertex3f(-0.03, -0.28, 0.03);
	glVertex3f(0.04, -0.28, 0.03);
	glVertex3f(0.04, -0.16, 0.03);
	glVertex3f(-0.03, -0.16, 0.03);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.03, -0.28, -0.03);
	glVertex3f(0.04, -0.28, -0.03);
	glVertex3f(0.04, -0.16, -0.03);
	glVertex3f(-0.03, -0.16, -0.03);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-0.03, -0.28, -0.03);
	glVertex3f(-0.03, -0.28, 0.03);
	glVertex3f(-0.03, -0.16, 0.03);
	glVertex3f(-0.03, -0.16, -0.03);
	glEnd();

	leftSaber();

	//sheild

	glPushMatrix();

	if (leftshield == 1) {
		glTranslatef(+0.110, -0.15, 0);
		glRotatef(90, 0.0f, 1.0f, 0.0f);
		shield();
	}

	glPopMatrix();


	//lowerbreak
	glPushMatrix();


	lowerHandBreak += lowerHandBreakSpeed;
	glTranslatef(0, -lowerHandBreak, 0);
	if (lowerHandBreak >= 0.03f) {
		lowerHandBreak = 0.03f;
		lowerHandBreakSpeed = 0.0f;
	}
	else if (lowerHandBreak <= 0.0f) {
		lowerHandBreak = 0.0f;
		lowerHandBreakSpeed = 0.0f;
	}

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-0.04, -0.3, 0.04);
	glVertex3f(0.04, -0.3, 0.04);
	glVertex3f(0.04, -0.24, 0.04);
	glVertex3f(-0.04, -0.20, 0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.04, -0.3, -0.04);
	glVertex3f(0.04, -0.3, -0.04);
	glVertex3f(0.04, -0.24, -0.04);
	glVertex3f(-0.04, -0.20, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.04, -0.3, -0.04);
	glVertex3f(-0.04, -0.3, 0.04);
	glVertex3f(-0.04, -0.20, 0.04);
	glVertex3f(-0.04, -0.20, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.3, -0.04);
	glVertex3f(0.04, -0.3, 0.04);
	glVertex3f(0.04, -0.24, 0.04);
	glVertex3f(0.04, -0.24, -0.04);
	glEnd();

	//outter part low
	glColor3f(0.98, 0.98, 0.98);
	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.295, 0.038);
	glVertex3f(0.085, -0.272, 0.038);
	glVertex3f(0.085, -0.234, 0.038);  //23
	glVertex3f(0.04, -0.26, 0.038);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.295, -0.038);
	glVertex3f(0.085, -0.272, -0.038);
	glVertex3f(0.085, -0.234, -0.038);
	glVertex3f(0.04, -0.26, -0.038);
	glEnd();

	//down
	glBegin(GL_POLYGON);
	glVertex3f(0.04, -0.295, 0.038);
	glVertex3f(0.04, -0.295, -0.038);
	glVertex3f(0.085, -0.272, -0.038);
	glVertex3f(0.085, -0.272, 0.038);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.085, -0.272, -0.038);
	glVertex3f(0.085, -0.272, 0.038);
	glVertex3f(0.085, -0.234, 0.038);
	glVertex3f(0.085, -0.234, -0.038);
	glEnd();

	glPopMatrix();

	glPopMatrix();


}

void leftpunch()
{


	//punch
	//upper
	glPushMatrix();
	glScalef(1.4, 1.2, 1.4);
	glTranslatef(0, -lowerHandBreak, 0);
	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 1);
	glVertex3f(0.04, -0.3, -0.04);
	glVertex3f(-0.04, -0.3, -0.04);
	glVertex3f(-0.04, -0.3, 0.04);
	glVertex3f(0.04, -0.3, 0.04);
	glEnd();

	glBegin(GL_POLYGON);//down
	glColor3f(0, 0, 0);
	glVertex3f(0.03, -0.31, -0.03);
	glVertex3f(-0.03, -0.31, -0.03);
	glVertex3f(-0.03, -0.31, 0.03);
	glVertex3f(0.03, -0.31, 0.03);
	glEnd();

	glBegin(GL_POLYGON);//front
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(0.04, -0.3, 0.04);
	glVertex3f(-0.04, -0.3, 0.04);
	glVertex3f(-0.03, -0.31, 0.03);
	glVertex3f(0.03, -0.31, 0.03);
	glEnd();

	glBegin(GL_POLYGON);//back
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(0.04, -0.3, -0.04);
	glVertex3f(-0.04, -0.3, -0.04);
	glVertex3f(-0.03, -0.31, -0.03);
	glVertex3f(0.03, -0.31, -0.03);
	glEnd();

	glBegin(GL_POLYGON);//left
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(0.04, -0.3, -0.04);
	glVertex3f(0.04, -0.3, 0.04);
	glVertex3f(0.03, -0.31, 0.03);
	glVertex3f(0.03, -0.31, -0.03);
	glEnd();

	glBegin(GL_POLYGON);//right
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-0.04, -0.3, -0.04);
	glVertex3f(-0.04, -0.3, 0.04);
	glVertex3f(-0.03, -0.31, 0.03);
	glVertex3f(-0.03, -0.31, -0.03);
	glEnd();

	//hand
	glBegin(GL_POLYGON);//outside
	glColor3f(1, 1, 1);
	glVertex3f(-0.04, -0.31, -0.036);
	glVertex3f(-0.04, -0.31, 0.036);
	glVertex3f(-0.04, -0.4, 0.036);
	glVertex3f(-0.04, -0.4, -0.036);
	glEnd();

	glBegin(GL_POLYGON);//inside
	glColor3f(1, 1, 1);
	glVertex3f(-0.025, -0.31, -0.042);
	glVertex3f(-0.025, -0.31, 0.042);
	glVertex3f(-0.025, -0.41, 0.042);
	glVertex3f(-0.025, -0.41, -0.042);
	glEnd();

	glBegin(GL_POLYGON);//front
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-0.04, -0.31, 0.036);
	glVertex3f(-0.04, -0.4, 0.036);
	glVertex3f(-0.025, -0.41, 0.042);
	glVertex3f(-0.025, -0.31, 0.042);
	glEnd();

	glBegin(GL_POLYGON);//back
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-0.04, -0.31, -0.036);
	glVertex3f(-0.04, -0.4, -0.036);
	glVertex3f(-0.025, -0.41, -0.042);
	glVertex3f(-0.025, -0.31, -0.042);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-0.04, -0.31, -0.036);
	glVertex3f(-0.04, -0.31, 0.036);
	glVertex3f(-0.025, -0.31, 0.042);
	glVertex3f(-0.025, -0.31, -0.042);
	glEnd();

	glBegin(GL_POLYGON);//down
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-0.04, -0.4, 0.036);
	glVertex3f(-0.04, -0.4, -0.036);
	glVertex3f(-0.025, -0.41, -0.042);
	glVertex3f(-0.025, -0.41, 0.042);
	glEnd();

	//hand 2
	glBegin(GL_POLYGON);//outside
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-0.01, -0.31, -0.036);
	glVertex3f(-0.01, -0.31, 0.036);
	glVertex3f(-0.01, -0.4, 0.036);
	glVertex3f(-0.01, -0.4, -0.036);
	glEnd();

	glBegin(GL_POLYGON);//inside
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-0.025, -0.31, -0.04);
	glVertex3f(-0.025, -0.31, 0.04);
	glVertex3f(-0.025, -0.41, 0.04);
	glVertex3f(-0.025, -0.41, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//front
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-0.01, -0.31, 0.036);
	glVertex3f(-0.01, -0.4, 0.036);
	glVertex3f(-0.025, -0.41, 0.04);
	glVertex3f(-0.025, -0.31, 0.04);
	glEnd();

	glBegin(GL_POLYGON);//back
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-0.01, -0.31, -0.036);
	glVertex3f(-0.01, -0.4, -0.036);
	glVertex3f(-0.025, -0.41, -0.04);
	glVertex3f(-0.025, -0.31, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-0.01, -0.31, -0.036);
	glVertex3f(-0.01, -0.31, 0.036);
	glVertex3f(-0.025, -0.31, 0.04);
	glVertex3f(-0.025, -0.31, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//down
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-0.01, -0.4, 0.036);
	glVertex3f(-0.01, -0.4, -0.036);
	glVertex3f(-0.025, -0.41, -0.04);
	glVertex3f(-0.025, -0.41, 0.04);
	glEnd();

	//big finger
	glBegin(GL_POLYGON);//right
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-0.025, -0.385, -0.04);
	glVertex3f(-0.025, -0.385, 0.04);
	glVertex3f(-0.025, -0.41, 0.04);
	glVertex3f(-0.025, -0.41, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//left
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(0.03, -0.385, -0.04);
	glVertex3f(0.03, -0.385, 0.04);
	glVertex3f(0.03, -0.41, 0.04);
	glVertex3f(0.03, -0.41, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//front
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(-0.025, -0.385, 0.04);
	glVertex3f(-0.025, -0.41, 0.04);
	glVertex3f(0.03, -0.41, 0.04);
	glVertex3f(0.03, -0.385, 0.04);
	glEnd();

	glBegin(GL_POLYGON);//back
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(-0.025, -0.385, -0.04);
	glVertex3f(-0.025, -0.41, -0.04);
	glVertex3f(0.03, -0.41, -0.04);
	glVertex3f(0.03, -0.385, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 0);
	glVertex3f(-0.025, -0.385, -0.04);
	glVertex3f(-0.025, -0.385, 0.04);
	glVertex3f(0.03, -0.385, 0.04);
	glVertex3f(0.03, -0.385, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 0);
	glVertex3f(-0.025, -0.41, -0.04);
	glVertex3f(-0.025, -0.41, 0.04);
	glVertex3f(0.03, -0.41, 0.04);
	glVertex3f(0.03, -0.41, -0.04);
	glEnd();

	//big finger 2
	glBegin(GL_POLYGON);//right
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(0.025, -0.36, -0.04);
	glVertex3f(0.025, -0.36, 0.04);
	glVertex3f(0.025, -0.41, 0.04);
	glVertex3f(0.025, -0.41, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//left
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(0.04, -0.36, -0.04);
	glVertex3f(0.04, -0.36, 0.04);
	glVertex3f(0.04, -0.41, 0.04);
	glVertex3f(0.04, -0.41, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//front
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(0.025, -0.36, 0.04);
	glVertex3f(0.025, -0.41, 0.04);
	glVertex3f(0.04, -0.41, 0.04);
	glVertex3f(0.04, -0.36, 0.04);
	glEnd();

	glBegin(GL_POLYGON);//back
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(0.025, -0.36, -0.04);
	glVertex3f(0.025, -0.41, -0.04);
	glVertex3f(0.04, -0.41, -0.04);
	glVertex3f(0.04, -0.36, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 0);
	glVertex3f(0.025, -0.36, -0.04);
	glVertex3f(0.025, -0.36, 0.04);
	glVertex3f(0.04, -0.36, 0.04);
	glVertex3f(0.04, -0.36, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 0);
	glVertex3f(0.025, -0.41, -0.04);
	glVertex3f(0.025, -0.41, 0.04);
	glVertex3f(0.04, -0.41, 0.04);
	glVertex3f(0.04, -0.41, -0.04);
	glEnd();

	//mother finger 1
	glBegin(GL_POLYGON);//right
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(0.025, -0.3335, -0.0);
	glVertex3f(0.025, -0.3335, 0.04);
	glVertex3f(0.025, -0.36, 0.04);
	glVertex3f(0.025, -0.36, -0.0);
	glEnd();

	glBegin(GL_POLYGON);//left
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(0.04, -0.3335, -0.0);
	glVertex3f(0.04, -0.3335, 0.04);
	glVertex3f(0.04, -0.36, 0.04);
	glVertex3f(0.04, -0.36, -0.0);
	glEnd();

	glBegin(GL_POLYGON);//front
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(0.025, -0.3335, 0.04);
	glVertex3f(0.025, -0.36, 0.04);
	glVertex3f(0.04, -0.36, 0.04);
	glVertex3f(0.04, -0.3335, 0.04);
	glEnd();

	glBegin(GL_POLYGON);//back
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(0.025, -0.3335, -0.0);
	glVertex3f(0.025, -0.36, -0.0);
	glVertex3f(0.04, -0.36, -0.0);
	glVertex3f(0.04, -0.3335, -0.0);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 0);
	glVertex3f(0.025, -0.3335, -0.0);
	glVertex3f(0.025, -0.3335, 0.04);
	glVertex3f(0.04, -0.3335, 0.04);
	glVertex3f(0.04, -0.3335, -0.0);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 0);
	glVertex3f(0.025, -0.36, -0.0);
	glVertex3f(0.025, -0.36, 0.04);
	glVertex3f(0.04, -0.36, 0.04);
	glVertex3f(0.04, -0.36, -0.0);
	glEnd();

	//mother finger 2
	glBegin(GL_POLYGON);//right
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-0.025, -0.31, 0.02);
	glVertex3f(-0.025, -0.31, 0.04);
	glVertex3f(-0.025, -0.36, 0.04);
	glVertex3f(-0.025, -0.36, 0.02);
	glEnd();

	glBegin(GL_POLYGON);//left
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(0.0, -0.31, 0.02);
	glVertex3f(0.0, -0.31, 0.04);
	glVertex3f(0.025, -0.3335, 0.04);
	glVertex3f(0.025, -0.3335, 0.02);
	glEnd();

	glBegin(GL_POLYGON);//front
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-0.025, -0.31, 0.04);
	glVertex3f(-0.025, -0.36, 0.04);
	glVertex3f(0.025, -0.36, 0.04);
	glVertex3f(0.025, -0.3335, 0.04);
	glVertex3f(0.0, -0.31, 0.04);
	glEnd();

	glBegin(GL_POLYGON);//back
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-0.025, -0.31, 0.02);
	glVertex3f(-0.025, -0.36, 0.02);
	glVertex3f(0.025, -0.36, 0.02);
	glVertex3f(0.025, -0.3335, 0.02);
	glVertex3f(0.0, -0.31, 0.02);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 0);
	glVertex3f(-0.025, -0.31, 0.02);
	glVertex3f(-0.025, -0.31, 0.04);
	glVertex3f(0.0, -0.31, 0.04);
	glVertex3f(0.0, -0.31, 0.02);
	glEnd();

	glBegin(GL_POLYGON);//down
	glColor3f(0, 0, 0);
	glVertex3f(-0.025, -0.36, 0.02);
	glVertex3f(-0.025, -0.36, 0.04);
	glVertex3f(0.025, -0.36, 0.04);
	glVertex3f(0.025, -0.36, 0.02);
	glEnd();

	if (handsaber1 == 1) {
		handsaber1speed += 0.001;

		if (handsaber1speed >= 0.8) {
			handsaber1speed = 0.8;
		}

		//lasersword
		glBegin(GL_POLYGON);//upper
		glColor3f(0.7, 0.7, 0.7);
		glVertex3f(-0.010, -0.36, -0.08);
		glVertex3f(-0.010, -0.36, 0.08);
		glVertex3f(0.025, -0.36, 0.08);
		glVertex3f(0.025, -0.36, -0.08);
		glEnd();

		glBegin(GL_POLYGON);//lower
		glColor3f(0.7, 0.7, 0.7);
		glVertex3f(-0.010, -0.385, -0.08);
		glVertex3f(-0.010, -0.385, 0.08);
		glVertex3f(0.025, -0.385, 0.08);
		glVertex3f(0.025, -0.385, -0.08);
		glEnd();

		glBegin(GL_POLYGON);//left
		glColor3f(0.8, 0.8, 0.8);
		glVertex3f(0.025, -0.36, 0.08);
		glVertex3f(0.025, -0.36, -0.08);
		glVertex3f(0.025, -0.385, -0.08);
		glVertex3f(0.025, -0.385, 0.08);
		glEnd();

		glBegin(GL_POLYGON);//right
		glColor3f(0.8, 0.8, 0.8);
		glVertex3f(-0.010, -0.36, -0.08);
		glVertex3f(-0.010, -0.36, 0.08);
		glVertex3f(-0.010, -0.385, 0.08);
		glVertex3f(-0.010, -0.385, -0.08);
		glEnd();

		glBegin(GL_POLYGON);//back
		glColor3f(0.4, 0.4, 0.4);
		glVertex3f(-0.010, -0.36, -0.08);
		glVertex3f(0.025, -0.36, -0.08);
		glVertex3f(0.025, -0.385, -0.08);
		glVertex3f(-0.010, -0.385, -0.08);
		glEnd();

		glBegin(GL_POLYGON);//front 1
		glColor3f(0.898, 0.388, 1);
		glVertex3f(-0.010, -0.36, 0.08);
		glVertex3f(0.025, -0.36, 0.08);
		glVertex3f(0.0075, -0.3725, 0.08 + handsaber1speed);
		glVertex3f(0.0075, -0.3725, 0.08 + handsaber1speed);
		glEnd();

		glBegin(GL_POLYGON);//front 2
		glColor3f(0.898, 0.388, 1);
		glVertex3f(0.025, -0.36, 0.08);
		glVertex3f(0.0075, -0.3725, 0.08 + handsaber1speed);
		glVertex3f(0.0075, -0.3725, 0.08 + handsaber1speed);
		glVertex3f(0.025, -0.385, 0.08);
		glEnd();

		glBegin(GL_POLYGON);//front 3
		glColor3f(0.898, 0.388, 1);
		glVertex3f(0.025, -0.385, 0.08);
		glVertex3f(-0.010, -0.385, 0.08);
		glVertex3f(0.0075, -0.3725, 0.08 + handsaber1speed);
		glVertex3f(0.0075, -0.3725, 0.08 + handsaber1speed);
		glEnd();

		glBegin(GL_POLYGON);//front 2
		glColor3f(0.898, 0.388, 1);
		glVertex3f(-0.010, -0.36, 0.08);
		glVertex3f(0.0075, -0.3725, 0.08 + handsaber1speed);
		glVertex3f(0.0075, -0.3725, 0.08 + handsaber1speed);
		glVertex3f(-0.010, -0.385, 0.08);
		glEnd();
	}

	else {
		handsaber1speed = 0;
	}

	glPopMatrix();
}

void rightpunch()
{


	//punch
	//upper
	glPushMatrix();
	glScalef(1.4, 1.2, 1.4);
	glTranslatef(0, -lowerHandBreak, 0);
	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 1);
	glVertex3f(-0.04, -0.3, -0.04);
	glVertex3f(0.04, -0.3, -0.04);
	glVertex3f(0.04, -0.3, 0.04);
	glVertex3f(-0.04, -0.3, 0.04);
	glEnd();

	glBegin(GL_POLYGON);//down
	glColor3f(0, 0, 0);
	glVertex3f(-0.03, -0.31, -0.03);
	glVertex3f(0.03, -0.31, -0.03);
	glVertex3f(0.03, -0.31, 0.03);
	glVertex3f(-0.03, -0.31, 0.03);
	glEnd();

	glBegin(GL_POLYGON);//front
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-0.04, -0.3, 0.04);
	glVertex3f(0.04, -0.3, 0.04);
	glVertex3f(0.03, -0.31, 0.03);
	glVertex3f(-0.03, -0.31, 0.03);
	glEnd();

	glBegin(GL_POLYGON);//back
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-0.04, -0.3, -0.04);
	glVertex3f(0.04, -0.3, -0.04);
	glVertex3f(0.03, -0.31, -0.03);
	glVertex3f(-0.03, -0.31, -0.03);
	glEnd();

	glBegin(GL_POLYGON);//left
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-0.04, -0.3, -0.04);
	glVertex3f(-0.04, -0.3, 0.04);
	glVertex3f(-0.03, -0.31, 0.03);
	glVertex3f(-0.03, -0.31, -0.03);
	glEnd();

	glBegin(GL_POLYGON);//right
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(0.04, -0.3, -0.04);
	glVertex3f(0.04, -0.3, 0.04);
	glVertex3f(0.03, -0.31, 0.03);
	glVertex3f(0.03, -0.31, -0.03);
	glEnd();

	//hand
	glBegin(GL_POLYGON);//outside
	glColor3f(1, 1, 1);
	glVertex3f(0.04, -0.31, -0.036);
	glVertex3f(0.04, -0.31, 0.036);
	glVertex3f(0.04, -0.4, 0.036);
	glVertex3f(0.04, -0.4, -0.036);
	glEnd();

	glBegin(GL_POLYGON);//inside
	glColor3f(1, 1, 1);
	glVertex3f(0.025, -0.31, -0.042);
	glVertex3f(0.025, -0.31, 0.042);
	glVertex3f(0.025, -0.41, 0.042);
	glVertex3f(0.025, -0.41, -0.042);
	glEnd();

	glBegin(GL_POLYGON);//front
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(0.04, -0.31, 0.036);
	glVertex3f(0.04, -0.4, 0.036);
	glVertex3f(0.025, -0.41, 0.042);
	glVertex3f(0.025, -0.31, 0.042);
	glEnd();

	glBegin(GL_POLYGON);//back
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(0.04, -0.31, -0.036);
	glVertex3f(0.04, -0.4, -0.036);
	glVertex3f(0.025, -0.41, -0.042);
	glVertex3f(0.025, -0.31, -0.042);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(0.04, -0.31, -0.036);
	glVertex3f(0.04, -0.31, 0.036);
	glVertex3f(0.025, -0.31, 0.042);
	glVertex3f(0.025, -0.31, -0.042);
	glEnd();

	glBegin(GL_POLYGON);//down
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(0.04, -0.4, 0.036);
	glVertex3f(0.04, -0.4, -0.036);
	glVertex3f(0.025, -0.41, -0.042);
	glVertex3f(0.025, -0.41, 0.042);
	glEnd();

	//hand 2
	glBegin(GL_POLYGON);//outside
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(0.01, -0.31, -0.036);
	glVertex3f(0.01, -0.31, 0.036);
	glVertex3f(0.01, -0.4, 0.036);
	glVertex3f(0.01, -0.4, -0.036);
	glEnd();

	glBegin(GL_POLYGON);//inside
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.025, -0.31, -0.04);
	glVertex3f(0.025, -0.31, 0.04);
	glVertex3f(0.025, -0.41, 0.04);
	glVertex3f(0.025, -0.41, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//front
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(0.01, -0.31, 0.036);
	glVertex3f(0.01, -0.4, 0.036);
	glVertex3f(0.025, -0.41, 0.04);
	glVertex3f(0.025, -0.31, 0.04);
	glEnd();

	glBegin(GL_POLYGON);//back
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(0.01, -0.31, -0.036);
	glVertex3f(0.01, -0.4, -0.036);
	glVertex3f(0.025, -0.41, -0.04);
	glVertex3f(0.025, -0.31, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.01, -0.31, -0.036);
	glVertex3f(0.01, -0.31, 0.036);
	glVertex3f(0.025, -0.31, 0.04);
	glVertex3f(0.025, -0.31, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//down
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.01, -0.4, 0.036);
	glVertex3f(0.01, -0.4, -0.036);
	glVertex3f(0.025, -0.41, -0.04);
	glVertex3f(0.025, -0.41, 0.04);
	glEnd();

	//big finger
	glBegin(GL_POLYGON);//right
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(0.025, -0.385, -0.04);
	glVertex3f(0.025, -0.385, 0.04);
	glVertex3f(0.025, -0.41, 0.04);
	glVertex3f(0.025, -0.41, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//left
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-0.03, -0.385, -0.04);
	glVertex3f(-0.03, -0.385, 0.04);
	glVertex3f(-0.03, -0.41, 0.04);
	glVertex3f(-0.03, -0.41, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//front
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(0.025, -0.385, 0.04);
	glVertex3f(0.025, -0.41, 0.04);
	glVertex3f(-0.03, -0.41, 0.04);
	glVertex3f(-0.03, -0.385, 0.04);
	glEnd();

	glBegin(GL_POLYGON);//back
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(0.025, -0.385, -0.04);
	glVertex3f(0.025, -0.41, -0.04);
	glVertex3f(-0.03, -0.41, -0.04);
	glVertex3f(-0.03, -0.385, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 0);
	glVertex3f(0.025, -0.385, -0.04);
	glVertex3f(0.025, -0.385, 0.04);
	glVertex3f(-0.03, -0.385, 0.04);
	glVertex3f(-0.03, -0.385, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 0);
	glVertex3f(0.025, -0.41, -0.04);
	glVertex3f(0.025, -0.41, 0.04);
	glVertex3f(-0.03, -0.41, 0.04);
	glVertex3f(-0.03, -0.41, -0.04);
	glEnd();

	//big finger 2
	glBegin(GL_POLYGON);//right
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-0.025, -0.36, -0.04);
	glVertex3f(-0.025, -0.36, 0.04);
	glVertex3f(-0.025, -0.41, 0.04);
	glVertex3f(-0.025, -0.41, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//left
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-0.04, -0.36, -0.04);
	glVertex3f(-0.04, -0.36, 0.04);
	glVertex3f(-0.04, -0.41, 0.04);
	glVertex3f(-0.04, -0.41, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//front
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(-0.025, -0.36, 0.04);
	glVertex3f(-0.025, -0.41, 0.04);
	glVertex3f(-0.04, -0.41, 0.04);
	glVertex3f(-0.04, -0.36, 0.04);
	glEnd();

	glBegin(GL_POLYGON);//back
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(-0.025, -0.36, -0.04);
	glVertex3f(-0.025, -0.41, -0.04);
	glVertex3f(-0.04, -0.41, -0.04);
	glVertex3f(-0.04, -0.36, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 0);
	glVertex3f(-0.025, -0.36, -0.04);
	glVertex3f(-0.025, -0.36, 0.04);
	glVertex3f(-0.04, -0.36, 0.04);
	glVertex3f(-0.04, -0.36, -0.04);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 0);
	glVertex3f(-0.025, -0.41, -0.04);
	glVertex3f(-0.025, -0.41, 0.04);
	glVertex3f(-0.04, -0.41, 0.04);
	glVertex3f(-0.04, -0.41, -0.04);
	glEnd();

	//mother finger 1
	glBegin(GL_POLYGON);//right
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-0.025, -0.3335, -0.0);
	glVertex3f(-0.025, -0.3335, 0.04);
	glVertex3f(-0.025, -0.36, 0.04);
	glVertex3f(-0.025, -0.36, -0.0);
	glEnd();

	glBegin(GL_POLYGON);//left
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(-0.04, -0.3335, -0.0);
	glVertex3f(-0.04, -0.3335, 0.04);
	glVertex3f(-0.04, -0.36, 0.04);
	glVertex3f(-0.04, -0.36, -0.0);
	glEnd();

	glBegin(GL_POLYGON);//front
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-0.025, -0.3335, 0.04);
	glVertex3f(-0.025, -0.36, 0.04);
	glVertex3f(-0.04, -0.36, 0.04);
	glVertex3f(-0.04, -0.3335, 0.04);
	glEnd();

	glBegin(GL_POLYGON);//back
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-0.025, -0.3335, -0.0);
	glVertex3f(-0.025, -0.36, -0.0);
	glVertex3f(-0.04, -0.36, -0.0);
	glVertex3f(-0.04, -0.3335, -0.0);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 0);
	glVertex3f(-0.025, -0.3335, -0.0);
	glVertex3f(-0.025, -0.3335, 0.04);
	glVertex3f(-0.04, -0.3335, 0.04);
	glVertex3f(-0.04, -0.3335, -0.0);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 0);
	glVertex3f(-0.025, -0.36, -0.0);
	glVertex3f(-0.025, -0.36, 0.04);
	glVertex3f(-0.04, -0.36, 0.04);
	glVertex3f(-0.04, -0.36, -0.0);
	glEnd();

	//mother finger 2
	glBegin(GL_POLYGON);//right
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(0.025, -0.31, 0.02);
	glVertex3f(0.025, -0.31, 0.04);
	glVertex3f(0.025, -0.36, 0.04);
	glVertex3f(0.025, -0.36, 0.02);
	glEnd();

	glBegin(GL_POLYGON);//left
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(-0.0, -0.31, 0.02);
	glVertex3f(-0.0, -0.31, 0.04);
	glVertex3f(-0.025, -0.3335, 0.04);
	glVertex3f(-0.025, -0.3335, 0.02);
	glEnd();

	glBegin(GL_POLYGON);//front
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(0.025, -0.31, 0.04);
	glVertex3f(0.025, -0.36, 0.04);
	glVertex3f(-0.025, -0.36, 0.04);
	glVertex3f(-0.025, -0.3335, 0.04);
	glVertex3f(-0.0, -0.31, 0.04);
	glEnd();

	glBegin(GL_POLYGON);//back
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(0.025, -0.31, 0.02);
	glVertex3f(0.025, -0.36, 0.02);
	glVertex3f(-0.025, -0.36, 0.02);
	glVertex3f(-0.025, -0.3335, 0.02);
	glVertex3f(-0.0, -0.31, 0.02);
	glEnd();

	glBegin(GL_POLYGON);//up
	glColor3f(0, 0, 0);
	glVertex3f(0.025, -0.31, 0.02);
	glVertex3f(0.025, -0.31, 0.04);
	glVertex3f(-0.0, -0.31, 0.04);
	glVertex3f(-0.0, -0.31, 0.02);
	glEnd();

	glBegin(GL_POLYGON);//down
	glColor3f(0, 0, 0);
	glVertex3f(0.025, -0.36, 0.02);
	glVertex3f(0.025, -0.36, 0.04);
	glVertex3f(-0.025, -0.36, 0.04);
	glVertex3f(-0.025, -0.36, 0.02);
	glEnd();

	if (handsaber2 == 1) {
		handsaber2speed += 0.001;

		if (handsaber2speed >= 0.8) {
			handsaber2speed = 0.8;
		}

		//lasersword
		glBegin(GL_POLYGON);//upper
		glColor3f(0.7, 0.7, 0.7);
		glVertex3f(0.010, -0.36, -0.08);
		glVertex3f(0.010, -0.36, 0.08);
		glVertex3f(-0.025, -0.36, 0.08);
		glVertex3f(-0.025, -0.36, -0.08);
		glEnd();

		glBegin(GL_POLYGON);//lower
		glColor3f(0.7, 0.7, 0.7);
		glVertex3f(0.010, -0.385, -0.08);
		glVertex3f(0.010, -0.385, 0.08);
		glVertex3f(-0.025, -0.385, 0.08);
		glVertex3f(-0.025, -0.385, -0.08);
		glEnd();

		glBegin(GL_POLYGON);//left
		glColor3f(0.8, 0.8, 0.8);
		glVertex3f(-0.025, -0.36, 0.08);
		glVertex3f(-0.025, -0.36, -0.08);
		glVertex3f(-0.025, -0.385, -0.08);
		glVertex3f(-0.025, -0.385, 0.08);
		glEnd();

		glBegin(GL_POLYGON);//right
		glColor3f(0.8, 0.8, 0.8);
		glVertex3f(0.010, -0.36, -0.08);
		glVertex3f(0.010, -0.36, 0.08);
		glVertex3f(0.010, -0.385, 0.08);
		glVertex3f(0.010, -0.385, -0.08);
		glEnd();

		glBegin(GL_POLYGON);//back
		glColor3f(0.4, 0.4, 0.4);
		glVertex3f(0.010, -0.36, -0.08);
		glVertex3f(-0.025, -0.36, -0.08);
		glVertex3f(-0.025, -0.385, -0.08);
		glVertex3f(0.010, -0.385, -0.08);
		glEnd();

		glBegin(GL_POLYGON);//front 1
		glColor3f(0.898, 0.388, 1);
		glVertex3f(0.010, -0.36, 0.08);
		glVertex3f(-0.025, -0.36, 0.08);
		glVertex3f(-0.0075, -0.3725, 0.08 + handsaber2speed);
		glVertex3f(-0.0075, -0.3725, 0.08 + handsaber2speed);
		glEnd();

		glBegin(GL_POLYGON);//front 2
		glColor3f(0.898, 0.388, 1);
		glVertex3f(-0.025, -0.36, 0.08);
		glVertex3f(-0.0075, -0.3725, 0.08 + handsaber2speed);
		glVertex3f(-0.0075, -0.3725, 0.08 + handsaber2speed);
		glVertex3f(-0.025, -0.385, 0.08);
		glEnd();

		glBegin(GL_POLYGON);//front 3
		glColor3f(0.898, 0.388, 1);
		glVertex3f(-0.025, -0.385, 0.08);
		glVertex3f(0.010, -0.385, 0.08);
		glVertex3f(-0.0075, -0.3725, 0.08 + handsaber2speed);
		glVertex3f(-0.0075, -0.3725, 0.08 + handsaber2speed);
		glEnd();

		glBegin(GL_POLYGON);//front 2
		glColor3f(0.898, 0.388, 1);
		glVertex3f(0.010, -0.36, 0.08);
		glVertex3f(-0.0075, -0.3725, 0.08 + handsaber2speed);
		glVertex3f(-0.0075, -0.3725, 0.08 + handsaber2speed);
		glVertex3f(0.010, -0.385, 0.08);
		glEnd();
	}

	else {
		handsaber2speed = 0;
	}

	glPopMatrix();
}

void arm() {
	hand();
}

void background()
{
	//space
	glEnable(GL_TEXTURE_2D);
	gluQuadricTexture(space, GL_TRUE & logo5);
	glPushMatrix();

	glColor3f(1.0f, 1.0f, 1.0f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	gluSphere(space, 5.0, 18, 18);//radius,slices,stacks
	glColor3f(1.0f, 1.0f, 1.0f);

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void display()
{
	//--------------------------------
	//	OpenGL drawing
	//--------------------------------
	glMatrixMode(GL_MODELVIEW);

	//texture
	GetObject(hBMP1, sizeof(BMP1), &BMP1);
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &logo1);
	glBindTexture(GL_TEXTURE_2D, logo1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP1.bmWidth, BMP1.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP1.bmBits);
	glDisable(GL_TEXTURE_2D);

	GetObject(hBMP2, sizeof(BMP2), &BMP2);
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &logo2);
	glBindTexture(GL_TEXTURE_2D, logo2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP2.bmWidth, BMP2.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP2.bmBits);
	glDisable(GL_TEXTURE_2D);

	GetObject(hBMP3, sizeof(BMP3), &BMP3);
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &logo3);
	glBindTexture(GL_TEXTURE_2D, logo3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP3.bmWidth, BMP3.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP3.bmBits);
	glDisable(GL_TEXTURE_2D);

	GetObject(hBMP4, sizeof(BMP4), &BMP4);
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &logo4);
	glBindTexture(GL_TEXTURE_2D, logo4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP4.bmWidth, BMP4.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP4.bmBits);
	glDisable(GL_TEXTURE_2D);

	GetObject(hBMP5, sizeof(BMP5), &BMP5);
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &logo5);
	glBindTexture(GL_TEXTURE_2D, logo5);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP5.bmWidth, BMP5.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP5.bmBits);
	glDisable(GL_TEXTURE_2D);



	glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//gluLookAt(eyeX, eyeY, eyeZ, 0.0f, 0.0f, 0.0f, 0, 1, 0);
	
	leftLeg3 += leftLeg3s;
	leftLeg6 += leftLeg6s;
	rightLeg1 += rightLeg1s;
	rightLeg3 += rightLeg3s;
	rightLeg4 += rightLeg4s;
	rightLeg6 += rightLeg6s;
	rotaionhead1 += rotaionhead1s;
	rotaionhead2 += rotaionhead2s;
	rotationhandleft += rotationhandlefts;
	rotationhandleft2 += rotationhandleft2s;
	rotationhandleft3 += rotationhandleft3s;
	rotationhandleft4 += rotationhandleft4s;
	rotationhandright += rotationhandrights;
	rotationhandright2 += rotationhandright2s;
	rotationhandright3 += rotationhandright3s;




	glTranslatef(0.0f, -0.0f, -3.0f);
	glTranslatef(0.0f, -0.0f, 0.0f);

	glRotatef(rotation3, 0.0f, 0.0f, 1.0f);


	glRotatef(rotation2, 1.0f, 0.0f, 0.0f);


	glRotatef(rotation, 0.0f, 1.0f, 0.0f);



	background();


	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -0.03f);

	glPushMatrix();
	//waist
	waist();
	glPopMatrix();

	//upper body
	glPushMatrix();

	if (rotationwaist >= 0.03f) {
		rotationwaist = 0.03f;
	}

	if (rotationwaist < 0.0) {
		rotationwaist = 0.0;
		rotationSpeedwaist = 0.0;
	}

	rotationwaist += rotationSpeedwaist;
	glTranslatef(0.0f, rotationwaist, 0.0f);

	//head
	glPushMatrix();
	glTranslatef(0.0f, 0.43f, 0.0f);

	if (rotaionhead1 >= 25) {
		rotaionhead1 = 25;
	}

	if (rotaionhead1 < -25) {
		rotaionhead1 = -25;
	}

	if (rotaionhead2 >= 60) {
		rotaionhead2 = 60;
	}

	if (rotaionhead2 < -60) {
		rotaionhead2 = -60;
	}

	glRotatef(rotaionhead1, 1.0f, 0.0f, 0.0f);
	
	glRotatef(rotaionhead2, 0.0f, 1.0f, 0.0f);
	

	head();
	glPopMatrix();

	//body
	glPushMatrix();
	body();
	glPopMatrix();

	//neck
	glPushMatrix();
	neck();
	glPopMatrix();



	//shouder(left)

	glPushMatrix();

	glTranslatef(0.0f, 0.325f, 0.0f);

	glRotatef(rotationhandleft, 1.0f, 0.0f, 0.0f);



	glTranslatef(0.0f, -0.325f, 0.0f);

	glTranslatef(-rotationarmor, rotationarmor / 2, 0.0f);
	glRotatef(-7, 0.0f, 0.0f, 1.0f);
	glTranslatef(-0.06f, -0.04f, 0.0f);

	shouderLeft();

	glPushMatrix();//left hand

	glRotatef(-6, 0, 0, 1);

	glTranslatef(-0.295, 0.21, 0.0);

	glTranslatef(0.0, 0.05, 0.0);

	if (rotationhandleft2 >= 40) {
		rotationhandleft2 = 40;
	}

	if (rotationhandleft2 < -5) {
		rotationhandleft2 = -5;
	}

	if (rotationhandleft3 >= 90) {
		rotationhandleft3 = 90;
	}

	if (rotationhandleft3 < -90) {
		rotationhandleft3 = -90;
	}

	glRotatef(-rotationhandleft2, 0.0f, 0.0f, 1.0f);



	glRotatef(-rotationhandleft3, 0.0f, 1.0f, 0.0f);


	glTranslatef(0.0, -0.05, 0.0);

	glRotatef(180, 0, 1, 0);
	arm();
	glPushMatrix();
	glTranslatef(0, -0.14, 0);

	if (rotationhandleft4 >= 90) {
		rotationhandleft4 = 90;
	}

	if (rotationhandleft4 < 0) {
		rotationhandleft4 = 0;
	}

	glRotatef(rotationhandleft4, 1.0f, 0.0f, 0.0f);


	glTranslatef(0, +0.14, 0);
	leftBighand();

	glPushMatrix();
	glRotatef(180, 0.0f, 1.0f, 0.0f);
	leftpunch();
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	glPopMatrix();



	//shouder right
	glPushMatrix();

	glTranslatef(0.0f, 0.325f, 0.0f);

	glRotatef(rotationhandright, 1.0f, 0.0f, 0.0f);



	glTranslatef(0.0f, -0.325f, 0.0f);

	glPushMatrix();

	glRotatef(180, 0.0f, 1.0f, 0.0f);

	glTranslatef(-rotationarmor, rotationarmor / 2, 0.0f);
	glRotatef(-7, 0.0f, 0.0f, 1.0f);
	glTranslatef(-0.06f, -0.04f, 0.0f);

	shouderLeft();

	glPopMatrix();

	glPushMatrix();//right hand
	glRotatef(12, 0, 0, 1);
	glTranslatef(0.35, 0.17, -0.00);

	glTranslatef(0.0, 0.05, 0.0);

	if (rotationhandright2 >= 40) {
		rotationhandright2 = 40;
	}

	if (rotationhandright2 < -10) {
		rotationhandright2 = -10;
	}

	if (rotationhandright3 >= 90) {
		rotationhandright3 = 90;
	}

	if (rotationhandright3 < -90) {
		rotationhandright3 = -90;
	}

	glRotatef(rotationhandright2, 0.0f, 0.0f, 1.0f);




	glRotatef(rotationhandright3, 0.0f, 1.0f, 0.0f);



	glTranslatef(0.0, -0.05, 0.0);

	arm();
	glPushMatrix();
	glTranslatef(0, -0.14, 0);

	if (rotationhandright4 >= 90) {
		rotationhandright4 = 90;
	}

	if (rotationhandright4 < 0) {
		rotationhandright4 = 0;
	}

	glRotatef(-rotationhandright4, 1.0f, 0.0f, 0.0f);

	glTranslatef(0, +0.14, 0);

	rightBighand();

	glPushMatrix();
	rightpunch();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

	//lower boddy
	//left leg
	glPushMatrix();
	glRotatef(-5, 0, 0, 1);
	glTranslatef(-0.115, -1.05, -0.1);
	leftLeg();
	glPopMatrix();


	//right leg
	glPushMatrix();
	glRotatef(5, 0, 0, 1);
	glTranslatef(0.115, -1.05, -0.1);
	rightLeg();
	glPopMatrix();



	if (transform == 1) {
		animation();
	}
	else if (transform == 0) {
		backAnimation();
	}

	if (pose1 == 1) {
		pose1a();
	}
	else if (pose1 == 0) {
		pose1ab();
	}

	if (pose2 == 1) {
		pose2a();
	}
	else if (pose2 == 0) {
		pose2ab();
	}

	if (rightSaberB == 1) {
		rightSaberAnimation();
	}
	else if (rightSaberB == 0) {
		rightSaberAnimationBack();
	}

	if (leftSaberB == 1) {
		leftSaberAnimation();
	}
	else if (leftSaberB == 0) {
		leftSaberAnimationBack();
	}


	//ball1
	glPushMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(-0.20f, 0.325f, 0.0f);
	gluSphere(ball1, 0.045, 18, 18);//radius,slices,stacks

	glPopMatrix();

	//ball2
	glPushMatrix();

	glRotatef(180, 0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(-0.20f, 0.325f, 0.0f);
	gluSphere(ball2, 0.045, 18, 18);//radius,slices,stacks

	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.05f, 0.0f);
	sifat();
	glPopMatrix();



	glDeleteTextures(1, &logo1);
	glDeleteTextures(1, &logo2);
	glDeleteTextures(1, &logo3);
	glDeleteTextures(1, &logo4);
	glDeleteTextures(1, &logo5);
	//--------------------------------
	//	End of OpenGL drawing
	//--------------------------------

}




//--------------------------------
//	End of OpenGL drawing
//--------------------------------

//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 900, 900,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//PROJECTION
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1, 0.01, 10);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);


	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}
	UnregisterClass(WINDOW_TITLE, wc.hInstance);
	DeleteObject(hBMP1);
	DeleteObject(hBMP2);
	DeleteObject(hBMP3);
	DeleteObject(hBMP4);
	DeleteObject(hBMP5);
	return true;
}
