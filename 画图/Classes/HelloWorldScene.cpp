#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "MySprite.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    MySprite * sprite = MySprite::create("dead.gif");
    sprite->setPosition(ccp(240,160));
//    sprite->setRotation(30);
    this->addChild(sprite);
    
    CCGrid3DAction * grid = CCWaves3D::create(50, CCSizeMake(100, 100), 50, 20);
    this->runAction(grid);
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::draw(void)
{
    CCPoint origin = CCPointZero;
    CCPoint directiron = ccp(0.5,0.5);//方向
    directiron = ccpMult(directiron, 1024);
    CCPoint target = ccpAdd(origin, directiron);
    
    ccDrawColor4B(255, 255, 255, 255);
    ccDrawLine(origin, target);
}