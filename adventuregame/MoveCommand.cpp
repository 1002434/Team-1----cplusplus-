////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#include "MoveCommand.h"
#include "Game.h"
#include "Room.h"
#include "TextRenderer.h"
////////////////////////////////////////////////////////////////////////////////
// Juha Perala - Added '<<' operator overloading for IRenderer
void MoveCommand::Execute()
{
  Room *pRoom = GetGame()->GetCurrentRoom();
  if ( pRoom ) {
    Room *newRoom = pRoom->OnMoveCommand(this);
    if ( newRoom )
      GetGame()->SetCurrentRoom(newRoom);
    else
      GetGame()->GetRenderer() << "Cannot go that way\n";
  }
}
////////////////////////////////////////////////////////////////////////////////
