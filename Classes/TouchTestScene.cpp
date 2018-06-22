#include "TouchTestScene.h"

USING_NS_CC;

Scene* TouchTest::createScene()
{
	// Scene is autorelease, layer created by cocos2d magic
	auto scene = Scene::create();
	auto layer = TouchTest::create();

	// Parent scene to layer
	scene->addChild(layer);

	return scene;
}

bool TouchTest::init()
{
	// Always call base init, and if fail break
	if (!Layer::init()) {
		return false;
	}

	// Beginning label, set to middle
	labelTouchInfo = Label::createWithSystemFont("Touch to begin", "Arial", 25);
	labelTouchInfo->setPosition(Vec2(
		Director::getInstance()->getVisibleSize().width / 2,
		Director::getInstance()->getVisibleSize().height / 2
	));

	// Create touch listener and bind callbacks
	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(TouchTest::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(TouchTest::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(TouchTest::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(TouchTest::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	// Parent scene to label
	this->addChild(labelTouchInfo);

	return true;
}

bool TouchTest::onTouchBegan(Touch* touch, Event* event)
{
	labelTouchInfo->setPosition(touch->getLocation());
	labelTouchInfo->setString("Touched Here");
	return true;
}

void TouchTest::onTouchEnded(Touch* touch, Event* event)
{
	cocos2d::log("Touch End");
}

void TouchTest::onTouchMoved(Touch* touch, Event* event)
{
	cocos2d::log("Touch Moved");
}

void TouchTest::onTouchCancelled(Touch* touch, Event* event)
{
	cocos2d::log("Touch Cancelled");
}