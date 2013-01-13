////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __SearchCommand_h__
#define __SearchCommand_h__
#include <cstdlib>
#include "GoldFactory.h"
#include "Gold.h"
#include "Game.h"
#include <sstream>
#include "IRenderer.h"
////////////////////////////////////////////////////////////////////////////////
// Juha Perala - Added '<<' operator overloading for IRenderer
class SearchCommand : public Command
{
public:
  SearchCommand( Game *pGame ) : Command(pGame) {}
  void Execute()
  {
    if ( rand()%1000 < 436 )
    {
      GoldFactory f;
      Gold *g = f.Create( 1+rand()%100 );
      std::ostringstream s;
      s << "You found " << g->GetAmount() << " gold!\n";
      
      // ---- Nina Ranta----
	  // ---- Taneli Peltoniemi, added operator overloading to Gold class ----
      //int ad = g->GetAmount();
	  GetGame()->GetGold() += g;
      //GetGame()->GetGold().SetCountAmount(ad) ;
      s << "You have now " << GetGame()->GetGold().GetCountAmount() << " amount of gold!\n";
      // ----
      
      GetGame()->GetRenderer() << s.str();
      delete g;
    }
    else {
      GetGame()->GetRenderer() << "You found nothing.\n";
    }
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
