#ifndef HANDLE_HPP
#define HANDLE_HPP

#include "../../common.h"

namespace engine {

/**
 * OpenGL resource handle.
 */
class Handle {

public:

	Handle();

	virtual ~Handle();

	/**
	 * Rebinds the resource into OpenGL.
	 */
	virtual void rebind() = 0;

	/**
	 * Unbinds the resource from OpenGL.
	 */
	virtual void unbind() = 0;
};

}

#endif
