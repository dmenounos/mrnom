#include "SoundService.hpp"

using namespace engine;

SoundService::SoundService(android_app* application) :
	_application(application),
	_engineItf(NULL),
	_engineObj(NULL),
	_outputMixObj(NULL) {
	LOG_D("### SoundService::SoundService()");
}

SoundService::~SoundService() {
	LOG_D("$$$ SoundService::~SoundService()");
}

void SoundService::setUp() {
	LOG_D("--> SoundService::setUp()");

	SLresult result;

	const SLuint32 engineMixIIDCount    = 1;
	const SLInterfaceID engineMixIIDs[] = { SL_IID_ENGINE };
	const SLboolean engineMixReqs[]     = { SL_BOOLEAN_TRUE };

	const SLuint32 outputMixIIDCount    = 1;
	const SLInterfaceID outputMixIIDs[] = { SL_IID_VOLUME };
	const SLboolean outputMixReqs[]     = { SL_BOOLEAN_FALSE };

	// Initialize _engineObj.
	// LOG_D("### Initialize _engineObj.");

	result = slCreateEngine(&_engineObj, 0, NULL, engineMixIIDCount, engineMixIIDs, engineMixReqs);
	if (result != SL_RESULT_SUCCESS) goto ERROR;

	result = (*_engineObj)->Realize(_engineObj, SL_BOOLEAN_FALSE);
	if (result != SL_RESULT_SUCCESS) goto ERROR;

	// Cast _engineObj to _engine.
	// LOG_D("### Cast _engineObj to _engine.");

	result = (*_engineObj)->GetInterface(_engineObj, SL_IID_ENGINE, &_engineItf);
	if (result != SL_RESULT_SUCCESS) goto ERROR;

	// Initialize _outputMixObj.
	// LOG_D("### Initialize _outputMixObj.");

	result = (*_engineItf)->CreateOutputMix(_engineItf, &_outputMixObj, outputMixIIDCount, outputMixIIDs, outputMixReqs);
	if (result != SL_RESULT_SUCCESS) goto ERROR;

	result = (*_outputMixObj)->Realize(_outputMixObj, SL_BOOLEAN_FALSE);
	if (result != SL_RESULT_SUCCESS) goto ERROR;

	return;

	ERROR:
	LOG_E("Error while initializing OpenSL: %lu", result);
}

void SoundService::tearDown() {
	LOG_D("--> SoundService::tearDown()");

	if (_outputMixObj != NULL) {
		(*_outputMixObj)->Destroy(_outputMixObj);
		_outputMixObj = NULL;
	}

	if (_engineObj != NULL) {
		(*_engineObj)->Destroy(_engineObj);
		_engineObj = NULL;
		_engineItf = NULL;
	}
}
