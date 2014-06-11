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
#include <vector>
#if !defined(OSX)
	#include <crtdbg.h>
#endif
#include <iostream>
#include <list>
#include <string>
#include "sqlite3.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

using namespace std;

typedef enum eGAMESTATES
{
	eSPLASH_SCREEN,
	eMAIN_MENU,
	eLOADING,
	eGAMEPLAY,
	eHIGH_SCORE,
	eEND,
}GameStates;


// State Updates
void UpdateMainMenu();
void UpdateGameState();
void UpdateHighScoreState();
void UpdateEndState();
void UpdateSplashState();
void UpdateLoadingState();

// State Draws
void DrawMainMenuState();
void DrawGameState();
void DrawHighScoreState();
void DrawEndState();
void DrawSplashState();
void DrawLoadingState();

// Variables for Images
unsigned int iBulletSpriteID;
unsigned int iEnemySpriteID;
unsigned int iSplashScreen;
unsigned int iPlayGameButton;
unsigned int iHighScoreButton;
unsigned int iQuitGameButton;
unsigned int iPlayerSpriteID;
unsigned int iMainMenuScreen;

int iEnemyWidth = 50;
int iEnemyHeight = 50;
int iButtonWidth = 190;
int iButtonHeight = 90;
float fMaxEnemyRespawn;
float fCurrentEnemySpawner;

vector<Enemy> Enemies;


// Mouse for Menu Variables
double dCursX, dCursY;
bool bPressed;
float fMouseX, fMouseY;

// Collision Variables
bool bSpheretoSphere(float x1,float y1,float x2,float y2);

// Screen Width and Height
const int iScreenWidth = 672;
const int iScreenHeight = 780;

Player PlayerController;
//Bullet BulletController;

GameStates eCurrentState = eSPLASH_SCREEN;

int main( int argc, char* argv[] )
{	

	Initialise( iScreenWidth, iScreenHeight, false, "Just Another Retro Pew Pew" );
	SetBackgroundColour( SColour( 000, 000, 000, 000 ) );

	// Sprite Creation
	iPlayerSpriteID = CreateSprite("./images/player.png", 50, 50, true);
	iBulletSpriteID = CreateSprite("./images/bullet.png", 50, 50, true);
	iEnemySpriteID = CreateSprite("./images/enemy.png", iEnemyWidth, iEnemyHeight, true);
	iSplashScreen = CreateSprite("./images/splashscreen.png", iScreenWidth, iScreenHeight, true);
	iPlayGameButton = CreateSprite("./images/playgamebutton.png", iButtonWidth, iButtonHeight, true);
	iHighScoreButton = CreateSprite("./images/highscorebutton.png", iButtonWidth, iButtonHeight, true);
	iQuitGameButton = CreateSprite("./images/quitbutton.png", iButtonWidth, iButtonHeight, true);
	iMainMenuScreen = CreateSprite("./images/mainmenu.png", iScreenWidth, iScreenHeight, true);

	fMaxEnemyRespawn = 2.0f;
	fCurrentEnemySpawner = 0;

	
	PlayerController = Player(iPlayerSpriteID);
	//BulletController = Bullet(iBulletSpriteID);

	do 
	{
		ClearScreen();
		float fDeltaT = GetDeltaTime();
		switch (eCurrentState)
		{
		case eSPLASH_SCREEN:
			UpdateSplashState();
			DrawSplashState();

			break;
	case eMAIN_MENU:
		UpdateMainMenu();
		DrawMainMenuState();
			
			break;
	case eHIGH_SCORE:
		UpdateHighScoreState();
		DrawHighScoreState();

		break;
	case eLOADING:
		UpdateLoadingState();
		DrawLoadingState();

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
	DestroySprite(iEnemySpriteID);
	DestroySprite(iSplashScreen);
	DestroySprite(iMainMenuScreen);
	DestroySprite(iPlayGameButton);
	DestroySprite(iHighScoreButton);
	DestroySprite(iQuitGameButton);

	Shutdown();

	return 0;
}

bool bSpheretoSphere(float x1, float y1, float x2, float y2)
{
	float distance = sqrt(((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));

	if( distance < (iEnemyWidth + iEnemyHeight) * 0.25f )
	{
		return true;
	}
	else
	{
		return false;
	}

	if( distance < (iButtonWidth, iButtonHeight) * 0.25f)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UpdateMainMenu()
{
	SetBackgroundColour( SColour( 000, 000, 000, 000 ) );
	GetMouseLocation(dCursX, dCursY);

	
	if( GetMouseButtonDown (0))
		{
				eCurrentState = eGAMEPLAY;	
		}
	else
	{
		if(!GetMouseButtonDown (0))
	{
		
	}
	}
	if( IsKeyDown( KEY_F1) )
		{
				eCurrentState = eGAMEPLAY;				
		}
	if( IsKeyDown( KEY_F2) )
		{
				eCurrentState = eHIGH_SCORE;				
		}
	if( IsKeyDown( KEY_F3) )
		{
				//Work on Shutdown.
		}

	MoveSprite(iMainMenuScreen, iScreenWidth * .5f, iScreenHeight *.5f);
	MoveSprite(iPlayGameButton, iScreenWidth * .5f, iScreenHeight -450);
	MoveSprite(iHighScoreButton, iScreenWidth * .5f, iScreenHeight -550);
	MoveSprite(iQuitGameButton, iScreenWidth * .5f, iScreenHeight -650);
}

void UpdateGameState()
{
	float fDeltaT = GetDeltaTime();

	fCurrentEnemySpawner += fDeltaT;

	if(fCurrentEnemySpawner > fMaxEnemyRespawn)
	{
			//		Sprite ID	RandomPos on Screen Width, Height at which they spawn, horizontal vel, Random vertical vel
		Enemy E(iEnemySpriteID, rand() % iScreenWidth, 800, 0, rand() % -60 + -120);
		Enemies.push_back(E);
		fCurrentEnemySpawner = 0;
	}

	for (int n = 0; n < Enemies.size(); n++)
	{
		Enemies[n].Update(fDeltaT);
		Enemies[n].Draw();
	}

	if(IsKeyDown(KEY_F2))
	{
		PlayerController.PlayerDeath();
	}
	if(PlayerController.iLives == 0 )
	{
		PlayerController.PlayerDeath();
	}
	
	

	SetBackgroundColour( SColour( 7, 73, 255, 254 ) );

	DrawString("SCORE: ", iScreenWidth * 0.025f, iScreenHeight - 1 );
	std::string Score = std::to_string(PlayerController.iScore);
	DrawString(Score.c_str(), iScreenWidth * 0.2f, iScreenHeight -1 ); 

	DrawString("LIVES: ", iScreenWidth * 0.75f, iScreenHeight - 1 );
	std::string Lives = std::to_string(PlayerController.iLives);
	DrawString(Lives.c_str(), iScreenWidth * 0.90f, iScreenHeight - 1 ); 

	if( IsKeyDown( KEY_ESCAPE) )
		{
			eCurrentState = eMAIN_MENU;

		}

	PlayerController.Update(fDeltaT);
	//BulletController.Update(fDeltaT);

	PlayerController.Shoot(iBulletSpriteID);

	for(int i = 0; i < MAX_BULLETS; i++)
	{    
	 PlayerController.bullets[i].Update(fDeltaT);    
	 PlayerController.bullets[i].Draw();



	 for(int j = 0; j < Enemies.size(); j++)
	 {
		 if(Enemies[j].fPositionY <= (iEnemyHeight - 1))
		 {
			 Enemies[j].Destroy();
			 PlayerController.iLives -= 1;

			 cout << "Player Lives -1" << endl;
			 cout << "Enemy Moved" << endl;
		 }

		 if(Enemies[j].bEnemyActive == false || PlayerController.bullets[i].bIsActive == false )
		 {
			 continue;
		 }

		 // When the Enemies hit the bottom of the screen take a life away
		
		
			// When the Players Bullet hits the enemy, moves the enemy and bullet off screen and makes them inactive
		 if( bSpheretoSphere(PlayerController.bullets[i].fPositionX, PlayerController.bullets[i].fPositionY, Enemies[j].fPositionX, Enemies[j].fPositionY) )
		 {
			cout << "Bullet Hit" << endl;
			PlayerController.bullets[i].Destroy();
			Enemies[j].Destroy();

			PlayerController.iScore += 10;
			
			cout << "Enemy Moved" << endl;
			cout << "Bullet Moved" << endl;
			cout << "Player Score +10" << endl;

		}
	}

	}
}

void UpdateHighScoreState()
{
	if( IsKeyDown( KEY_ESCAPE) )
			{
				eCurrentState = eMAIN_MENU;

			}
}

void UpdateEndState()
{
	SetBackgroundColour( SColour( 199, 31, 31, 000 ) );
	if( IsKeyDown( KEY_ENTER ) )
	{
		eCurrentState = eGAMEPLAY;
	}
	if(IsKeyDown ( KEY_ESCAPE ))
	{
		eCurrentState = eMAIN_MENU;
	}
}

void UpdateSplashState()
{
	// Centers Sprite on screen
	MoveSprite(iSplashScreen, iScreenWidth * .5f, iScreenHeight * .5f);
	if( IsKeyDown( KEY_ENTER) )
		{
				eCurrentState = eMAIN_MENU;
		}
}

void UpdateLoadingState()
{

}

void DrawMainMenuState()
{
	DrawSprite(iMainMenuScreen);
	DrawSprite(iPlayGameButton);
	DrawSprite(iHighScoreButton);
	DrawSprite(iQuitGameButton);
}

void DrawGameState()
{
	PlayerController.Draw();
	//BulletController.Draw();
}

void DrawHighScoreState()
{

}

void DrawEndState()
{

}

void DrawSplashState()
{
	DrawSprite(iSplashScreen);
}

void DrawLoadingState()
{

}