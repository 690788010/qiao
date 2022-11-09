#pragma once

#include <string>
#include <map>
#include "link_auto_uniform.h"

namespace qiao {
	class LinkAutoUniformCollection : public std::map<std::string, LinkAutoUniform*> {};
}