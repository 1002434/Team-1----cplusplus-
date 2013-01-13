 ////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#include "Game.h"
#include "Player.h"
#include "GoldFactory.h"
#include "Gold.h"
#include "QuitCommand.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "TextRenderer.h"
#include <sstream>
#include "IRenderer.h"
#include "CommandFactory.h"
#include "Dungeon.h"
#include "Hallway.h"
#include "MonsterRoom.h"
#include "Chambers.h"
#include "globals.h"
#include "InvalidCommandException.h"
#include "GameOverException.h"

#include <ctime>
////////////////////////////////////////////////////////////////////////////////
using namespace std;
#define DEV_NAME "anssi.grohn@pkamk.fi"
#define YEAR 2011

////////////////////////////////////////////////////////////////////////////////
// Juha Perala - Added '<<' operator overloading for IRenderer
Game::Game() : running(true), renderer(*new TextRenderer)
{
  //renderer = new TextRenderer();

  rooms[kDungeon] = new Dungeon();
  rooms[kDungeon]->SetGame(this);

  rooms[kHallway] = new Hallway();
  rooms[kHallway]->SetGame(this);

  rooms[kMonster] = new MonsterRoom();
  rooms[kMonster]->SetGame(this);
  
  rooms[kChambers] = new Chambers();
  rooms[kChambers]->SetGame(this);

  rooms[kDungeon]->SetNextRoom(North,rooms[kHallway]);

  rooms[kHallway]->SetNextRoom(South,rooms[kDungeon]);
  rooms[kHallway]->SetNextRoom(North,rooms[kMonster]);

  rooms[kMonster]->SetNextRoom(South,rooms[kHallway]);
  rooms[kMonster]->SetNextRoom(North,rooms[kChambers]);

  rooms[kChambers]->SetNextRoom(South,rooms[kMonster]);
  
  currentRoom = rooms[kDungeon];

  //--- Nina Ranta ---
  gold.ZeroCountAmount(0);
  //---

}
////////////////////////////////////////////////////////////////////////////////
Game::~Game()
{

}
////////////////////////////////////////////////////////////////////////////////
// Taneli Peltoniemi - Added the GameOverException, InvalidCommandException
// Juha Perala - Added '<<' operator overloading for IRenderer
void Game::Play()
{
  string cmd;
  
  renderer << "Welcome to Fiends'n'Frogs adventure game!\n";
  ostringstream s;
  s << "by " << DEV_NAME << "(c) " << YEAR << ". Licensed under GPLv3.\n";
  renderer << s.str();
  // if(LoadGameState()) {
  //
//	renderer->Render("\nWe have loaded a saved game now!\n");
 // 
 // } else {
	Player::AskInfo(player);
	renderer << "\nPlayer statistics:\n\n";
	player.PrintSummary();
//  }
  renderer << "\nAnd behold, the adventure begins!\n";
  
  player.SetGame(this);
  
  srand(time(NULL));
  while(running)
  {
    renderer << GetCurrentRoom()->GetDescription();
	renderer << "\n> ";

	getline(cin,cmd);

	try {
		CommandFactory comm(this);
		ICommand *pCommand = comm.Create( cmd ); 
		if ( pCommand ) pCommand->Execute();
			delete pCommand;

		GetCurrentRoom()->Update();
	} catch(GameOverException &gameover) {
		running = false;
		renderer << gameover.what();
	} catch(InvalidCommandException &invalidCommandException) {
	    renderer << invalidCommandException.what();
	}
  }
  // final message to player
  renderer << "Exiting, bye!\n";
}
////////////////////////////////////////////////////////////////////////////////
// Juha Perala - Added '<<' operator overloading for IRenderer
void
Game::SetRenderer( IRenderer *pRenderer )
{
  renderer = *pRenderer;
}
////////////////////////////////////////////////////////////////////////////////
// Juha Perala - Added '<<' operator overloading for IRenderer
IRenderer & 
Game::GetRenderer() const
{
  return renderer;
}
////////////////////////////////////////////////////////////////////////////////
bool
Game::IsRunning() const
{
  return running;
}
////////////////////////////////////////////////////////////////////////////////
void
Game::SetRunning( bool bFlag ) 
{
  running = bFlag;
}
////////////////////////////////////////////////////////////////////////////////
Player & 
Game::GetPlayer()
{
  return player;
}
////////////////////////////////////////////////////////////////////////////////
//--- Nina Ranta ---
Gold & 
Game::GetGold()
{
  return gold;
}

//------------------
////////////////////////////////////////////////////////////////////////////////

Room *
Game::GetCurrentRoom()
{
  return currentRoom;
}
////////////////////////////////////////////////////////////////////////////////
void 
Game::SetCurrentRoom( Room *pRoom )
{
  currentRoom = pRoom;
}
////////////////////////////////////////////////////////////////////////////////
// Taneli Peltoniemi
void Game::SaveGameState() {
	ofstream savegame("gamestate.txt");
	if(savegame.is_open()) {
			savegame << player.GetName() << "\r\n";
			savegame << player.GetRace() << "\r\n";
			savegame << player.GetClass() << "\r\n";
			savegame << player.GetAge() << "\r\n";
			savegame << player.GetGender() << "\r\n";
			savegame << player.GetExperience() << "\r\n";
			savegame << player.GetHitpoints() << "\r\n";
			//--- Nina Ranta ---
			savegame << gold.GetCountAmount() << "\r\n";
			//------------------
			savegame << currentRoom->GetRoomID() << "\r\n";

			MonsterRoom *room = dynamic_cast<MonsterRoom*>(rooms[kMonster]);
			if(room != NULL) {
				savegame << room->GetEnemy().GetHitpoints() << "\r\n";
			}
			savegame.close();
	}
}
// Taneli Peltoniemi
int Game::LoadGameState() {
	ifstream savegame("gamestate.txt");
	if(savegame.is_open()) {
		int iTmp;
		string sTmp;
		int cTmp;
		
		savegame >> sTmp; player.SetName(sTmp);
		savegame >> sTmp; player.SetRace(sTmp);
		savegame >> iTmp; player.SetClass((Class)iTmp);
		savegame >> iTmp; player.SetAge(iTmp);
		savegame >> cTmp; player.SetGender( (cTmp == 'm' ? Male : Female) );
		savegame >> iTmp; player.SetExperience(iTmp);
		savegame >> iTmp; player.SetHitpoints(iTmp);

		//--- Nina Ranta ---
		savegame >> iTmp; gold.SetCountAmount(iTmp);
                //------------------
		
		savegame >> iTmp; currentRoom = rooms[iTmp];
		
		MonsterRoom *room = dynamic_cast<MonsterRoom*>(rooms[kMonster]);
		if(room != NULL) {
			savegame >> iTmp;
			room->GetEnemy().SetHitpoints(iTmp);
			if(!room->GetEnemy().IsAlive()) {
				room->SetDescription("You are in the monster room. There is a pretty dead orc here!");
			}
		}
		savegame.close();	
		return 1;
	}
	return 0;
}

