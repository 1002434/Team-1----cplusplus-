////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#include "MoveCommand.h"
#include "Room.h"
#include "Game.h"
#include "IRenderer.h"
#include <cstdlib>
// --- Nina Ranta ---
#include <deque>
////////////////////////////////////////////////////////////////////////////////
Room::Room(int id)
{
  this->id =id;
  // --- Nina Ranta --- inserts every element with value NULL
  rooms.push_back(NULL);
  rooms.push_back(NULL);
  rooms.push_back(NULL);
  rooms.push_back(NULL);
}
////////////////////////////////////////////////////////////////////////////////
Room::~Room()
{
  
}
////////////////////////////////////////////////////////////////////////////////
void
Room::SetNextRoom( Direction d, Room * pRoom )
{
  // --- Nina Ranta --- Returns a reference to the element 'at' position
  rooms.at(d) = pRoom;
}
////////////////////////////////////////////////////////////////////////////////
Room * 
Room::GetNextRoom( Direction d )
{
  // --- Nina Ranta --- Returns a reference to the element 'at' position
  return rooms.at(d);
}
////////////////////////////////////////////////////////////////////////////////
void 
Room::SetDescription( const std::string & desc )
{
  description = desc;
}
////////////////////////////////////////////////////////////////////////////////
const std::string & 
Room::GetDescription() const
{
  return description;
}
////////////////////////////////////////////////////////////////////////////////
Room * 
Room::OnMoveCommand( MoveCommand *pCommand )
{
  return GetNextRoom( pCommand->GetDirection() );
}
////////////////////////////////////////////////////////////////////////////////
void
Room::OnAttack( AttackCommand *pCommand )
{
  // NO enemy , NO attack possibility
  // Juha Perala - Added '<<' operator overloading for IRenderer
  GetGame()->GetRenderer() << "Attack what? There's nothing there!\n";
}
////////////////////////////////////////////////////////////////////////////////
void 
Room::SetGame( Game * pGame )
{
  game = pGame;
}
////////////////////////////////////////////////////////////////////////////////
Game * 
Room::GetGame() const
{
  return game;
}
////////////////////////////////////////////////////////////////////////////////
int
Room::GetRoomID() const
{
  return id;
}
