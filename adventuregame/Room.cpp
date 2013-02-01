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
#include "GameOverException.h"
#include <cstdlib>
// --- Nina Ranta ---
//#include <deque>
#include <vector>
#include <algorithm>
#include <exception>
// ---
using namespace std;
////////////////////////////////////////////////////////////////////////////////
Room::Room(int id)
{
  this->id =id;
  // --- Nina Ranta ---
  this->numOfDir = 4;

  // --- Nina Ranta --- fill all of the elements of a vector of NULL value
  //fill(rooms.begin(), rooms.begin()+4, NULL);

   /*for (vector<Room *>::iterator it = rooms.begin(); it != rooms.end(); ++it)
     {
	renderer << "Element value is: " << *it;
     } */

  //--- Nina Ranta --- inserts every element with value NULL
  rooms.push_back(NULL);
  rooms.push_back(NULL);
  rooms.push_back(NULL);
  rooms.push_back(NULL);
  
  // --- Nina Ranta --- count and exception_ptr
  int eCount = count(rooms.begin(), rooms.end(), NULL);

  exception_ptr eptr;
  try
  {
    if(eCount != numOfDir)
    {
       throw GameOverException;
    }
  }

  catch(GameOverException &gameover)
  {
      eptr = current_exception();
  }

  Handle_eptr(eptr);
}
////////////////////////////////////////////////////////////////////////////////
Room::~Room()
{
  
}
////////////////////////////////////////////////////////////////////////////////
// --- Nina Ranta ---
void
Room::Handle_eptr(exception_ptr eptr)
{

  try
  {
    if(eptr != exception_ptr() )
    {
       rethrow_exception(eptr);
    }

  }
 
  catch(const exception &e)
  {
       running = false;
       renderer << "Exception: Missmatch between vector and directions " << e.what();
  }
}
////////////////////////////////////////////////////////////////////////////////
void
Room::SetNextRoom( Direction d, Room * pRoom )
{
  // --- Nina Ranta --- Returns a reference to the element 'at' position
  // rooms.at(d) = pRoom;
  rooms[d] = pRoom;
}
////////////////////////////////////////////////////////////////////////////////
Room * 
Room::GetNextRoom( Direction d )
{
  // --- Nina Ranta --- Returns a reference to the element 'at' position
  // return rooms.at(d);
  return rooms[d];
}
////////////////////////////////////////////////////////////////////////////////
void 
Room::SetDescription( const std::string & desc )
{
  description = desc;
}
////////////////////////////////////////////////////////////////////////////////
const string & 
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
