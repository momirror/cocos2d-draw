//
//  MySprite.cpp
//  画图
//
//  Created by msp on 13-11-21.
//
//

#include "MySprite.h"

void MySprite::draw(void)
{
    CCSprite::draw();
    
    CCPoint origin = CCPointZero;
    CCPoint directiron = ccp(0,1);//当前垂直方向
    directiron = ccpMult(directiron, 1024);
    CCPoint target = ccpAdd(origin, directiron);
    
    ccDrawColor4B(255, 255, 255, 255);
    ccDrawLine(origin, target);
}

MySprite * MySprite::create(const char *pszFileName)
{
    CCSprite::create(pszFileName);
    MySprite *pobSprite = new MySprite();
    if (pobSprite && pobSprite->initWithFile(pszFileName))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;

}

bool MySprite::initWithFile(const char *pszFilename)
{
    CCAssert(pszFilename != NULL, "Invalid filename for sprite");
    
    CCTexture2D *pTexture = CCTextureCache::sharedTextureCache()->addImage(pszFilename);
    if (pTexture)
    {
        CCRect rect = CCRectZero;
        rect.size = pTexture->getContentSize();
        return initWithTexture(pTexture, rect);
    }
    
    // don't release here.
    // when load texture failed, it's better to get a "transparent" sprite then a crashed program
    // this->release();
    return false;

}