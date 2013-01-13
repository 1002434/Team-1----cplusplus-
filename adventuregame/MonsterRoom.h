////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __MonsterRoom_h__
#define __MonsterRoom_h__
#include "Room.h"
#include "Enemy.h"
#include <sstream>
#include "MoveCommand.h"
#include "GameOverException.h"
////////////////////////////////////////////////////////////////////////////////
// Juha Perala - Added '<<' operator overloading for IRenderer
class MonsterRoom : public Room
{
private:
  Enemy e;
  bool noticedPlayer;
public:
  MonsterRoom() : Room(2)
  {
    noticedPlayer = false;
    e.SetName( "Orc");
    SetDescription("You are in the monster room. There is an orc here!");
  }
  
  Enemy& GetEnemy() { return e; }
  
  ////////////////////
  /// Makes enemy attack player once on every turn.
  void Update() 
  {
   
    if ( e.IsAlive() && noticedPlayer )
    {
      std::ostringstream s;
      Player & player = GetGame()->GetPlayer();
      s << e.GetName() << " attacks " << player.GetName() << "\n";
      GetGame()->GetRenderer() << s.str();

      e.Attack(&player);
	  
	  // Taneli Peltoniemi
	  if(player.GetHitpoints() <= 0) {
		throw GameOverException("You have died\n");
	  }
    }

    noticedPlayer = true;
  }
  ////////////////////
  /// Restricts movement until enemy is killed.
  /// \param pCommand Move command.
  /// \return Room pointer to next available room, NULL if none available.
  Room * OnMoveCommand( MoveCommand *pCommand )
  {
    if ( e.IsAlive())
    {
      return NULL;
    }
    else
      return GetNextRoom( pCommand->GetDirection() );
  }
  
  void OnAttack( AttackCommand *pCommand )
  {
    if ( e.IsAlive() && noticedPlayer)
    {
      Player & player = GetGame()->GetPlayer();
      std::ostringstream s;
      s << player.GetName() << " attacks " << e.GetName() << "\n";
      GetGame()->GetRenderer() << s.str();
      player.Attack( &e );
      // Change room description a bit
      if ( e.IsAlive() == false )
      {
	SetDescription("You are in the monster room. There is a pretty dead orc here.");
      }
    } 
    else 
    {
      // to encourage player to stop beating it further
      GetGame()->GetRenderer() << "Whoa! You already got your pound of flesh out of that one. Literally.\n";
    }

  }

};
////////////////////////////////////////////////////////////////////////////////
#endif



