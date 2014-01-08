#ifndef FRAMECOUNTER_HPP
#define FRAMECOUNTER_HPP

#include "../core/Accumulator.hpp"

namespace engine {

class FrameCounter : public Accumulator {

public:

	FrameCounter();

	virtual ~FrameCounter();

	// override
	virtual void execute();

	// override
	virtual void update(float deltaTime);

	uint32_t getFps() const;

private:

	float _deltaTime;
	uint32_t _fpsCounter;
	uint32_t _fps;
};

}

#endif
