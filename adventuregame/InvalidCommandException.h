#ifndef __INVALID_COMMAND_H
#define __INVALID_COMMAND_H

#include <string>
#include <stdexcept>
// Taneli Peltoniemi
struct InvalidCommandException : public std::runtime_error {
	InvalidCommandException() : std::runtime_error("I do not understand you\n") { }
};

#endif