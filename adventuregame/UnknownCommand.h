////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __UnknownCommand_h__
#define __UnknownCommand_h__
////////////////////////////////////////////////////////////////////////////////
#include "Command.h"
////////////////////////////////////////////////////////////////////////////////
class UnknownCommand  : public Command
{
public:
  UnknownCommand( Game *pGame ) : Command(pGame) { }
  
  void Execute()
  {
    // Juha Perala - Added '<<' operator overloading for IRenderer
    GetGame()->GetRenderer() << "I do not understand you.\n";
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
