//////////////////////////////////////////////////////////// 
// File: <main.cpp> 
// Author: <Elijah Wardle> 
// Date Created: <18/03/2014> 
// Brief: <description of the purpose of the file> 
//////////////////////////////////////////////////////////// 

#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#if !defined(OSX)
	#include <crtdbg.h>
#endif
#include <iostream>
#include <list>
#include <string>
#include "sqlite3.h"
#include "Player.h"
#include "Bullet.h"

typedef enum eGAMESTATES
{
	eSplashScreen,
	eMAIN_MENU,
	eLoading,
	eGAMEPLAY,
	eHIGH_SCORE,
	eEND,
}GameStates;

void UpdateMainMenu();
void UpdateGameState();
void DrawMainMenuState();
void DrawGameState();

const int iScreenWidth = 672;
const int iScreenHeight = 780;

Player PlayerController;
Bullet BulletController;

GameStates eCurrentState = eMAIN_MENU;

int main( int argc, char* argv[] )
{	

	Initialise( iScreenWidth, iScreenHeight, false, "Just Another Retro Pew Pew" );
	SetBackgroundColour( SColour( 000, 000, 000, 000 ) );

	unsigned int iPlayerSpriteID = CreateSprite("./images/player.png", 50, 50, true);
	unsigned int iBulletSpriteID = CreateSprite("./images/bullet.png", 50, 50, true);


	
	PlayerController = Player(iPlayerSpriteID);
	BulletController = Bullet(iBulletSpriteID);

	do 
	{
		ClearScreen();
		float fDeltaT = GetDeltaTime();
		switch (eCurrentState)
		{
	case eMAIN_MENU:
		UpdateMainMenu();
		DrawMainMenuState();
			
			break;
	case eGAMEPLAY:
		UpdateGameState();
		DrawGameState();
	
		break;
	default:
		break;
		}
			
	} while ( FrameworkUpdate() == false );

	DestroySprite(iPlayerSpriteID);
	DestroySprite(iBulletSpriteID);

	Shutdown();

	return 0;
}


void UpdateMainMenu()
{
	SetBackgroundColour( SColour( 000, 000, 000, 000 ) );
	if( IsKeyDown( KEY_ENTER) )
		{
				eCurrentState = eGAMEPLAY;
				
			
		}
}

void UpdateGameState()
{
	SetBackgroundColour( SColour( 7, 73, 255, 254 ) );
	DrawString("SCORE < 1 >", iScreenWidth * 0.025f, iScreenHeight - 1 );
	DrawString("LIVES < 1 >", iScreenWidth * 0.75f, iScreenHeight - 1 );
	if( IsKeyDown( KEY_ESCAPE) )
			{
				eCurrentState = eMAIN_MENU;

			}
	PlayerController.Update();
	BulletController.Update(a_fDeltaT);

	for(int i = 0; i < MAX_BULLETS; i++)
	{    
	 PlayerController.bullets[i].Update(a_fDeltaT);    
	 PlayerController.bullets[i].Draw();
	}

}

void DrawMainMenuState()
{

}

void DrawGameState()
{
	PlayerController.Draw();
	BulletController.Draw();
}

