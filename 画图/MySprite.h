//
//  MySprite.h
//  画图
//
//  Created by msp on 13-11-21.
//
//

#ifndef ______MySprite__
#define ______MySprite__

#include <iostream>

#endif /* defined(______MySprite__) */


#include "cocos2d.h"
using namespace cocos2d;


class MySprite:public CCSprite
{
    
    
public:
     void draw(void);
     static MySprite * create(const char *pszFileName);
     bool initWithFile(const char *pszFilename);
    
};