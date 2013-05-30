#include "MrNomGame.hpp"

MrNomGame::~MrNomGame() {
	LOG_D("MrNomGame::~MrNomGame");
}

GameScreen* MrNomGame::getStartScreen() {
	return new LoadingScreen(this);
}

void printTypeLimits()
{
	LOG_D( "type\tsize\tmin\t\tmax\n" );
	LOG_D( "----------------------------------------------------------\n" );
	LOG_D( "bool\t%zu\n",              sizeof(bool)                       );
	LOG_D( "char\t%zu\t%d\t\t%d\n",    sizeof(char),   CHAR_MIN, CHAR_MAX );
	LOG_D( "short\t%zu\t%hd\t\t%hd\n", sizeof(short),  SHRT_MIN, SHRT_MAX );
	LOG_D( "int\t%zu\t%d\t%d\n",       sizeof(int),    INT_MIN,  INT_MAX  );
	LOG_D( "long\t%zu\t%ld\t%ld\n",    sizeof(long),   LONG_MIN, LONG_MAX );
	LOG_D( "float\t%zu\t%e\t%e\n",     sizeof(float),  FLT_MIN,  FLT_MAX  );
	LOG_D( "double\t%zu\t%e\t%e\n",    sizeof(double), DBL_MIN,  DBL_MAX  );
}

void android_main(android_app* application)
{
	printTypeLimits();

	MrNomGame gameContext;
	gameContext.init(application);
}
