////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __Room_h__
#define __Room_h__
////////////////////////////////////////////////////////////////////////////////
#include <string>
// --- Nina Ranta ---
#include <deque>
#include "Updateable.h"
#include "globals.h"
////////////////////////////////////////////////////////////////////////////////
class MoveCommand;
class AttackCommand;
class Game;
////////////////////////////////////////////////////////////////////////////////
class Room : public Updateable 
{
private:
  //Room * rooms[kNumDirs];
  std::deque<Room *> rooms;
  std::string description;
  Game * game;
  int id;
public:

  Room(int id);
  virtual ~Room();
  void SetGame( Game * pGame );
  Game * GetGame() const;
  void SetDescription( const std::string & desc );
  const std::string & GetDescription() const;
  void   SetNextRoom( Direction d, Room * pRoom );
  Room * GetNextRoom( Direction d );
  // Taneli Peltoniemi
  int GetRoomID() const;

  virtual Room * OnMoveCommand( MoveCommand *pCommand );
  virtual void   OnAttack( AttackCommand *pCommand );
};
////////////////////////////////////////////////////////////////////////////////
#endif
