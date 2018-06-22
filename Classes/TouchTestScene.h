#pragma once

#include "cocos2d.h"

class TouchTest : public cocos2d::Layer
{
public:
	// Create and initialize functions
	static cocos2d::Scene* createScene();
	virtual bool init();

	// Touch functions
	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);

	// cocos2d magic
	CREATE_FUNC(TouchTest);

private:
	cocos2d::Label* labelTouchInfo;
};