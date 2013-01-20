////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __IRenderer_h__
#define __IRenderer_h__
#include <iostream>
////////////////////////////////////////////////////////////////////////////////
class IRenderer 
{
public:
  virtual void Render( const std::string & str ) = 0;
  // Juha Perala - Added '<<' operator overloading for IRenderer
  //virtual IRenderer& operator<<(const std::string & str) = 0;
};

// Juha Perala - Added templated '<<' operator overload
template<typename T>
IRenderer& operator<<(IRenderer& r, const T& str)
{
	std::cout << str;
	return r;
}
////////////////////////////////////////////////////////////////////////////////
#endif
