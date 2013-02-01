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
//#include <deque>
#include <vector>
#include <algorithm>
#include <exception>
// ---
#include "Updateable.h"
#include "globals.h"

using namespace std;
////////////////////////////////////////////////////////////////////////////////
class MoveCommand;
class AttackCommand;
class Game;
////////////////////////////////////////////////////////////////////////////////
class Room : public Updateable 
{
private:
  //Room * rooms[kNumDirs];
  // --- Nina Ranta ---
  //deque<Room *> rooms;
  vector<Room *> rooms;
  // ---
  string description;
  Game * game;
  int id;
  // --- Nina Ranta --- number of directions to go
  int numOfDir;
public:
  // --- Nina Ranta ---
  void Handle_eptr(exception_ptr eptr);
  Room(int id);
  virtual ~Room();
  void SetGame( Game * pGame );
  Game * GetGame() const;
  void SetDescription( const string & desc );
  const string & GetDescription() const;
  void   SetNextRoom( Direction d, Room * pRoom );
  Room * GetNextRoom( Direction d );
  // Taneli Peltoniemi
  int GetRoomID() const;

  virtual Room * OnMoveCommand( MoveCommand *pCommand );
  virtual void   OnAttack( AttackCommand *pCommand );
};
////////////////////////////////////////////////////////////////////////////////
#endif
