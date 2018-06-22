#include "AppDelegate.h"

#include "HelloWorldScene.h"
#include "GraphicsTestScene.h"
#include "TouchTestScene.h"
#include "MultiTouchTestScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {}

AppDelegate::~AppDelegate() {}

bool AppDelegate::applicationDidFinishLaunching() 
{
	// Setup Director and view
	auto director = Director::getInstance();
	auto glView = director->getOpenGLView();
	if (!glView) {
		glView = GLViewImpl::create("Cocos2dTest");
		director->setOpenGLView(glView);
	}

	// Setup scene
	auto scene = MultiTouchTest::createScene();
	director->runWithScene(scene);

	return true;
}

void AppDelegate::applicationDidEnterBackground() 
{

}

void AppDelegate::applicationWillEnterForeground() 
{

}