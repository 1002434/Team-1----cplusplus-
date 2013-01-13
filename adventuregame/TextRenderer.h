////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#include <iostream>
#include "IRenderer.h"
////////////////////////////////////////////////////////////////////////////////
class TextRenderer : public IRenderer
{
public:
  void Render( const std::string & str )
  {
    std::cout << str;
  }
  
  // Juha Perala - Added '<<' operator overloading for IRenderer
  IRenderer& operator<<(const std::string & str)
  {
	std::cout << str;
	return *this;
  }
  
};
////////////////////////////////////////////////////////////////////////////////
