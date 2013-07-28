//
//  Victorian_Rush_HourAppDelegate.cpp
//  Victorian Rush Hour
//
//  Created by Hiromasa Suzuki on 07/28/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "GameLayer.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    
    pDirector->setOpenGLView(pEGLView);
    
    CCSize screenSize = pEGLView->getFrameSize();
    CCSize designSize = CCSize(2048, 1536);
    
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, kResolutionExactFit);

    if (screenSize.height > 768) {
        CCFileUtils::sharedFileUtils()->setResourceDirectory("ipadhd");
        pDirector->setContentScaleFactor(1536/designSize.height);
    } else if (screenSize.height > 320) {
        CCFileUtils::sharedFileUtils()->setResourceDirectory("ipad");
        pDirector->setContentScaleFactor(768/designSize.height);
    } else {
        CCFileUtils::sharedFileUtils()->setResourceDirectory("iphone");
        pDirector->setContentScaleFactor(380/designSize.height);
    }
    
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("background.mp3"));
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("falling.wav") );
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("hitBuilding.wav") );
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("jump.wav") );
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("crashing.wav") );
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("start.wav") );
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("openUmbrella.wav") );
    
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5f);
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5f);
    
    
    // turn on display FPS
    pDirector->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = GameLayer::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();

    // if you use SimpleAudioEngine, it must be paused
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();
    
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
