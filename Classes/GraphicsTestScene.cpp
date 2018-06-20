#include "GraphicsTestScene.h"

USING_NS_CC;

Scene* GraphicsTest::createScene()
{
	// Scene is autorelease, layer created by cocos2d magic
	auto scene = Scene::create();
	auto layer = GraphicsTest::create();

	// Parent scene to layer
	scene->addChild(layer);

	return scene;
}

bool GraphicsTest::init()
{
	// Always call base init, and if fail break
	if (!Layer::init()) {
		return false;
	}

	// Create 2 sprites, parent 1 to 0, move to center
	auto sprite0 = Sprite::create("flcl.jpg");
	auto sprite1 = Sprite::create("neko.png");

	sprite0->addChild(sprite1);
	sprite0->setPosition(320, 240);

	this->addChild(sprite0, 0);

	return true;
}