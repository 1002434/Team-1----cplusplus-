////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#include "CommandFactory.h"
#include "QuitCommand.h"
#include "SearchCommand.h"
#include "AttackCommand.h"
#include "UnknownCommand.h"
#include "MoveCommand.h"
#include "SaveCommand.h"
#include "Game.h"
#include "globals.h"
#include <sstream>
#include <string>
#include <iostream>
#include "InvalidCommandException.h"
////////////////////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////////////////////
// Juha Perala - insert command, ICommand pairs to the map
CommandFactory::CommandFactory( Game *pGame ) : m_pGame(pGame)
{
	cmdMap.insert(pair<string,ICommand*>("quit", new QuitCommand(m_pGame)));
	cmdMap.insert(pair<string,ICommand*>("search", new SearchCommand(m_pGame)));
	cmdMap.insert(pair<string,ICommand*>("attack", new AttackCommand(m_pGame)));
	cmdMap.insert(pair<string,ICommand*>("save", new SaveCommand(m_pGame)));
	
	MoveCommand *command = new MoveCommand(m_pGame);
    command->SetDirection(North);
	cmdMap.insert(pair<string,ICommand*>("move north", command));
	
	command = new MoveCommand(m_pGame);
    command->SetDirection(South);
	cmdMap.insert(pair<string,ICommand*>("move south", command));
	
	command = new MoveCommand(m_pGame);
    command->SetDirection(East);
	cmdMap.insert(pair<string,ICommand*>("move east", command));
	
	command = new MoveCommand(m_pGame);
    command->SetDirection(West);
	cmdMap.insert(pair<string,ICommand*>("move west", command));
}

// Juha Perala - map clean up
CommandFactory::~CommandFactory()
{
	for(map<string,ICommand*>::iterator it = cmdMap.begin(); it != cmdMap.end(); it++)
	{
		if (it->second) delete it->second;
	}
	cmdMap.clear();
}

// Juha Perala - fetch ICommand from the map
ICommand * 
CommandFactory::Create( const std::string & str )
{
  map<string,ICommand*>::iterator it = cmdMap.find(str);
  if(it != cmdMap.end()) return it->second;
  
  /*std::istringstream s(str);
  std::string word;
  s >> word;
    
  if ( word == "quit" )
  {
    return new QuitCommand(m_pGame);
  }
  
  if ( word == "search")
  {
    return new SearchCommand(m_pGame);
  }
  
  if ( word == "attack" )
  {
    return new AttackCommand(m_pGame);
  }

  if ( word == "move" )
  {
    string dir;
    s >> dir;
    //cout << "got dir '" << dir << "'\n";
    MoveCommand *command = NULL;
    if ( dir == "north" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(North);
      return command;
    }
    else if ( dir == "south" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(South);
      return command;
    }
    else if ( dir == "east" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(East);
      return command;
    }
    else if ( dir == "west" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(West);
      return command;
    }
  }
  // Taneli Peltoniemi
  if( word == "save") 
  {
	return new SaveCommand(m_pGame);
  }*/
  // Taneli Peltoniemi
  throw InvalidCommandException();
}
////////////////////////////////////////////////////////////////////////////////
