////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __Game_h__
#define __Game_h__
////////////////////////////////////////////////////////////////////////////////
class IRenderer;
class Room;
////////////////////////////////////////////////////////////////////////////////
enum RoomId { kDungeon, kHallway, kMonster, kChambers, kNumRooms };
#include "Player.h"
#include "Enemy.h"
//-- Nina Ranta --
#include "Gold.h"
#include <vector>
//----
////////////////////////////////////////////////////////////////////////////////
// Juha Perala - Added '<<' operator overloading for IRenderer
class Game 
{
private:
  bool running;
  Player player;
  //--- Nina Ranta ---  
  Gold gold;
  //----
  IRenderer& renderer;
  //Room *rooms[kNumRooms]; ///< Map.
  // --- Nina Ranta ---
  std::vector <Room *> rooms;
  Room *currentRoom;
public:
  Game();
  virtual ~Game();
  void Play();
  void SetRenderer( IRenderer *pRenderer );
  IRenderer & GetRenderer() const;
  bool IsRunning() const;
  void SetRunning(bool bFlag ) ;
  Player & GetPlayer();
  //--- Nina Ranta ---
  Gold & GetGold();
  //------
  Room * GetCurrentRoom();
  void SetCurrentRoom( Room *pRoom );
  
  
          // Taneli Peltoniemi
  void SaveGameState();
  int LoadGameState();
};
////////////////////////////////////////////////////////////////////////////////
#endif
