#ifndef __GAME_OVER_H
#define __GAME_OVER_H

#include <string>
#include <stdexcept>
// Taneli Peltoniemi
struct GameOverException : public std::runtime_error {
	GameOverException(std::string error) : std::runtime_error(error.c_str()) { }
};

#endif