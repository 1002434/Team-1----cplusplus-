////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __Gold_h__
#define __Gold_h__
////////////////////////////////////////////////////////////////////////////////
class GoldFactory;

//--- Nina Ranta ---
class Game;
//-------

////////////////////////////////////////////////////////////////////////////////
class Gold 
{
  friend class GoldFactory;
  // ---- Nina Ranta -----
  friend class Game;
private:
  unsigned int m_nAmount;
  // ---- Nina Ranta ----  
  Gold();
  Gold(unsigned int value);
  unsigned int c_nAmount;
  // ----

public:
  virtual ~Gold();
  unsigned int GetAmount() const;
  // ---- Nina Ranta -----
  unsigned int GetCountAmount() const;
  void SetCountAmount( unsigned int count );
  void ZeroCountAmount( unsigned int count);
  // ----
  void SetAmount( unsigned int value );
};
////////////////////////////////////////////////////////////////////////////////
#endif
