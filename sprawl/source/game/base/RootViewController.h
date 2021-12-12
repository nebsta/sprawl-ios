//
//  RootViewController.h
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

#include "Logger.h"

#include "ShaderManager.h"
#include "SpriteManager.h"
#include "BoardManager.hpp"
#include "BlueprintManager.hpp"

#include "BoardContext.hpp"

@interface RootViewController : GLKViewController {
    glm::mat4 _projectionMatrix;
    BoardContext *_boardContext;
}
@property (strong, nonatomic) EAGLContext *context;
@property (nonatomic) BoardView *boardView;
@property (nonatomic) View *mainView;
@property (nonatomic) float runningAverage;
- (void)setupOpenGL;
- (void)tearDownGL;
@end
