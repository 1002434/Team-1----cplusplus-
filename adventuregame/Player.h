////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __Player_h__
#define __Player_h__
#include <string>
#include <stack>
#include "GameObject.h"
class Game;
class HealthPotion;
////////////////////////////////////////////////////////////////////////////////
class Player : public GameObject
{
private:
  Game *game;
  std::stack<HealthPotion*> potions;
public:
  Player();

  virtual ~Player();
  void SetGame( Game * game );
  void Attack( GameObject *pObject);

  void PrintSummary();
  void UsePotion();
  static void AskInfo( Player & p );

};
////////////////////////////////////////////////////////////////////////////////
#endif
