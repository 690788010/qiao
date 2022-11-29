#pragma once

#include <list>
#include "draw_auto_uniform.h"

namespace qiao {
	class DrawAutoUniformCollection : public std::list<DrawAutoUniform*> {};
}