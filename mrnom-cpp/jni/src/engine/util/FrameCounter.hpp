#ifndef FRAMECOUNTER_HPP
#define FRAMECOUNTER_HPP

#include "../../common.h"

#include "../core/Accumulator.hpp"

namespace engine {

class FrameCounter : public Accumulator {

public:

	FrameCounter();

	virtual ~FrameCounter();

	// override
	virtual void update(float deltaTime);

	uint32_t getFps() const;

protected:

	// override
	virtual void onTick();

private:

	uint32_t _fpsCounter;
	uint32_t _fps;
};

}

#endif
