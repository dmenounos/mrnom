#ifndef SOUNDSERVICE_HPP
#define SOUNDSERVICE_HPP

#include "../../common.h"

namespace engine {

/**
 * Encapsulates OpenSL management.
 */
class SoundService {

public:

	SoundService(android_app* application);

	virtual ~SoundService();

	virtual void setUp();

	virtual void tearDown();

private:

	// shared system pointer
	android_app* _application;

	SLEngineItf _engineItf;
	SLObjectItf _engineObj;
	SLObjectItf _outputMixObj;
};

}

#endif
