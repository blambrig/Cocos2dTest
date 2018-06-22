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

	// Create sprite in center
	auto sprite = Sprite::create("flcl.jpg");
	sprite->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, 
		Director::getInstance()->getVisibleSize().height / 2));

	// Add touch listener event
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [](Touch* touch, Event* event) -> bool {
		auto bounds = event->getCurrentTarget()->getBoundingBox();

		// Print info
		if (bounds.containsPoint(touch->getLocation())) {
			std::stringstream touchDetails;
			touchDetails << "Touched at OpenGL coords: " <<
				touch->getLocation().x << ", " << touch->getLocation().y << std::endl <<
				"Touched at UI coords: " <<
				touch->getLocationInView().x << ", " << touch->getLocationInView().y << std::endl <<
				"Touched at Local coords: " <<
				event->getCurrentTarget()->convertToNodeSpace(touch->getLocation()).x << ", " <<
				event->getCurrentTarget()->convertToNodeSpace(touch->getLocation()).y << std::endl <<
				"Touch moved by: " << touch->getDelta().x << ", " << touch->getDelta().y;
			
			MessageBox(touchDetails.str().c_str(), "Touch Info");
		}

		return true;
	};

	// Register touch listener and parent scene to sprite
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, sprite);
	this->addChild(sprite, 0);

	return true;
}