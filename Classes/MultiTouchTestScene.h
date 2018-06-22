#pragma once

#include "cocos2d.h"

class MultiTouchTest : public cocos2d::Layer
{
public:
	// Create and initialize functions
	static cocos2d::Scene* createScene();
	virtual bool init();

	// cocos2d magic
	CREATE_FUNC(MultiTouchTest);

private:
	const static int MAX_TOUCHES = 5;

protected:
	cocos2d::Label* labelTouchLocations[MAX_TOUCHES];
};