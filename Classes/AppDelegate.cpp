#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "GraphicsTestScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {}

AppDelegate::~AppDelegate() {}

bool AppDelegate::applicationDidFinishLaunching() 
{
	// Setup Director and view
	auto director = Director::getInstance();
	auto glView = director->getOpenGLView();
	if (!glView) {
		glView = GLViewImpl::create("GraphicsTest");
		glView->setFrameSize(640, 480);
		director->setOpenGLView(glView);
	}

	// Setup scene
	auto scene = GraphicsTest::createScene();
	director->runWithScene(scene);

	return true;
}

void AppDelegate::applicationDidEnterBackground() 
{

}

void AppDelegate::applicationWillEnterForeground() 
{

}