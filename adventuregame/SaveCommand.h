////////////////////
/// Advanced C++
/// Adventure Game 2 
/// taneli.peltoniemi@cou.fi
////////////////////
#ifndef __SaveCommand_h__
#define __SaveCommand_h__
////////////////////////////////////////////////////////////////////////////////
#include "Command.h"
////////////////////////////////////////////////////////////////////////////////
class SaveCommand  : public Command
{
public:
  SaveCommand( Game *pGame ) : Command(pGame) { }
  
  void Execute()
  {
    // Taneli Peltoniemi
	GetGame()->SaveGameState();
	// Juha Perala - Added '<<' operator overloading for IRenderer
    GetGame()->GetRenderer() << "Game state saved!";
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
