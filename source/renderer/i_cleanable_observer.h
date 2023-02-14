#pragma once

#include "i_cleanable.h"

namespace qiao {
	class ICleanableObserver {
	public:
		virtual void notifyDirty(ICleanable* value) = 0;
	};
}