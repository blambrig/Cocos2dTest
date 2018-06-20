#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene() 
{
	// Scene is autorelease, layer created by cocos2d magic
	auto scene = Scene::create();
	auto layer = HelloWorld::create();

	// Parent scene to layer
	scene->addChild(layer);

	return scene;
}

bool HelloWorld::init()
{
	// Always call base init, and if fail break
	if (!Layer::init()) {
		return false;
	}

	// Create label with lower left anchor then parent layer to label
	auto label = Label::createWithSystemFont("Hello World!", "Arial", 96);
	label->setAnchorPoint(Vec2(0.0, 0.0));
	this->addChild(label, 1);

	return true;
}