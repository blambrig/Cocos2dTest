#include "MultiTouchTestScene.h"

USING_NS_CC;

Scene* MultiTouchTest::createScene()
{
	// Scene is autorelease, layer created by cocos2d magic
	auto scene = Scene::create();
	auto layer = MultiTouchTest::create();

	// Parent scene to layer
	scene->addChild(layer);

	return scene;
}

bool MultiTouchTest::init()
{
	// Always call base init, and if fail break
	if (!Layer::init()) {
		return false;
	}

	// Create label array
	for (int i = 0; i < MAX_TOUCHES; ++i) {
		labelTouchLocations[i] = Label::createWithSystemFont("", "Arial", 25);
		labelTouchLocations[i]->setVisible(false);
		this->addChild(labelTouchLocations[i]);
	}

	// Add touch listener event
	auto touchListener = EventListenerTouchAllAtOnce::create();

	// Create event listener to handle touches
	touchListener->onTouchesBegan = [=](const std::vector<Touch*> &touches, Event* event) {
		std::for_each(labelTouchLocations, labelTouchLocations + MAX_TOUCHES, [] (Label* touchLabel) {
			touchLabel->setVisible(false);
		});

		// Move each label and set visible
		for (int i = 0; i < touches.size(); ++i) {
			labelTouchLocations[i]->setPosition(touches[i]->getLocation());
			labelTouchLocations[i]->setVisible(true);
			labelTouchLocations[i]->setString("Touched");
		}
	};

	// Register listener
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}