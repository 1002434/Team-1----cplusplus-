////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __CommandFactory_h__
#define __CommandFactory_h__
#include <string>
#include <map>
class Game;
class ICommand;
////////////////////////////////////////////////////////////////////////////////
class CommandFactory 
{
private:
  Game * m_pGame;
  // Juha Perala - Added a map container
  std::map<std::string,ICommand*> cmdMap;
public:
  CommandFactory( Game *pGame );
  virtual ~CommandFactory();
  
  ICommand * Create( const std::string & str );
};
////////////////////////////////////////////////////////////////////////////////

#endif
