#pragma once

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer 
{
public:
	// Create and initialize functions
	static cocos2d::Scene* createScene();
	virtual bool init();

	// cocos2d magic
	CREATE_FUNC(HelloWorld);
};