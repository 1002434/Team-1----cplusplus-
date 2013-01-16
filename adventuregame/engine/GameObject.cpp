////////////////////

/// C++ Object-oriented Programming

/// Adventure Game 6

/// Reference answer 

/// anssi.grohn@pkamk.fi

////////////////////

#include "GameObject.h"

#include "IRenderer.h"
#include "Game.h"
#include "Player.h"
#include <cstdlib>

#include <iostream>



using namespace std;


GameObject::GameObject()
{
  
}


GameObject::~GameObject()
{
  
}


void
GameObject::Attack( GameObject *pObject )

{
  
	int hp = pObject->GetHitpoints();
  
	if ( (rand() % 10) < 6 )
  
	{
    
		// TODO: convert this into weapon 
    
		// with damage property.   
		pObject->SetHitpoints(hp-1); 

		// --- Nina Ranta --- removed cout and added renderer 
		ostringstream s;
    		s << GetName() << " hits!\n";
		game->GetRenderer()->Render( s.str() );
  
		
	}
  

	else
  	{
    		ostringstream s;
    		s << GetName() << " misses!\n";
    		game->GetRenderer()->Render( s.str() );
		// ----
  	}

}


int 
GameObject::GetHitpoints() const

{
  
	return hitpoints;

}


void 
GameObject::SetHitpoints(int hp )

{
  
	hitpoints = hp;

}



void 
GameObject::SetName( string name) 

{
  
	this->name = name;

}


string 
GameObject::GetName() const

{
  
	return name;

}


void 
GameObject::SetClass( Class c)

{
 
	myClass = c;

}


Class 
GameObject::GetClass() const

{
  
	return myClass;

}


void 
GameObject::SetAge( unsigned short int age )

{
  
	this->age = age;

}




unsigned short int 
GameObject::GetAge() const

{
  
	return age;

}


void 
GameObject::SetGender( Gender g )

{
  
	gender = g;

}


Gender 
GameObject::GetGender() const

{
  
	return gender;

}




void 
GameObject::SetExperience( int experience )

{
  
	this->experience = experience;

}


int 
GameObject::GetExperience() const

{
  
	return experience;

}


void 
GameObject::SetRace( string r )

{
  
	race = r;

}


string 
GameObject::GetRace() const

{
  
	return race;

}



void
GameObject::Update()
{
  
}
