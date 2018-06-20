#pragma once

#include "cocos2d.h"

class AppDelegate : private cocos2d::Application 
{
public:
	// Constructor and Destructor
	AppDelegate();
	virtual ~AppDelegate();

	// State functions
	virtual bool applicationDidFinishLaunching();
	virtual void applicationDidEnterBackground();
	virtual void applicationWillEnterForeground();
};