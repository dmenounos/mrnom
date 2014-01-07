#ifndef CALLBACK_HPP
#define CALLBACK_HPP

#include "../../common.h"

namespace engine {

/**
 * Generic callback interface.
 */
class Callback {

public:

	virtual ~Callback() {}

	/**
	 * Generic callback method.
	 */
	virtual void execute() = 0;
};

}

#endif
