#pragma once

#include <map>
#include <string>
#include "draw_auto_uniform_factory.h"

namespace qiao {
	class DrawAutoUniformFactoryCollection : public std::map<std::string, DrawAutoUniformFactory*> {};
}