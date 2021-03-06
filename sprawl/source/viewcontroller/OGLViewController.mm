//
//  RootViewController.m
//  sprawl
//
//  Created by Benjamin Wallis on 4/10/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#import "OGLViewController.h"

#define MS_PER_UPDATE 30

@interface OGLViewController ()
@property(nonatomic,readwrite) float frameLag;
@end

@implementation OGLViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    ScreenManager::instance().initialize([[UIScreen mainScreen] scale], self.view.frame.size.width, self.view.frame.size.height);
    
    [self setupOpenGL];
    
    ShaderManager::instance().initialize();
    _game = new Game(ScreenManager::instance());
}

- (void)dealloc {
    [self tearDownGL];
    
    if ([EAGLContext currentContext] == self.context) {
        [EAGLContext setCurrentContext:nil];
    }
    
    delete _game;
    _game = nullptr;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];

    if ([self isViewLoaded] && ([[self view] window] == nil)) {
        self.view = nil;
        
        [self tearDownGL];
        
        if ([EAGLContext currentContext] == self.context) {
            [EAGLContext setCurrentContext:nil];
        }
        self.context = nil;
    }
}

- (BOOL)prefersStatusBarHidden {
    return YES;
}

- (void)setupOpenGL {
    self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
    
    GLKView *view = (GLKView *)self.view;
    view.context = self.context;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    
    [EAGLContext setCurrentContext:self.context];
    
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_SCISSOR_TEST);
    glEnable(GL_BLEND);
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glm::vec2 screenSizePixels = ScreenManager::instance().screenPixelSize();
    glScissor(0, 0, screenSizePixels.x, screenSizePixels.y);
    glBindVertexArrayOES(0);
}

- (void)tearDownGL {
    [EAGLContext setCurrentContext:self.context];
    
    ShaderManager::instance().teardown();
}

- (void)update {
    
    self.frameLag += self.timeSinceLastUpdate;
    
    while (self.frameLag * 1000 >= MS_PER_UPDATE) {
        _game->update(MS_PER_UPDATE / 1000.0);
        self.frameLag -= MS_PER_UPDATE/1000.0;
    }
}

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    _game->render();
}

#pragma mark UIGestureRecognizer

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    
//    NSSet *set = [event touchesForView:self.view];
//    if ([set count] > 0) {
//        UITouch *touch = [set anyObject];
//        CGPoint location = [touch locationInView:self.view];
//        Touch data = {(int)touch.hash,glm::vec2(location.x,location.y)};
//        _mainView->touchBegin(data);
//    }
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
    
//    NSSet *set = [event touchesForView:self.view];
//    if ([set count] > 0) {
//        UITouch *touch = [set anyObject];
//        CGPoint location = [touch locationInView:self.view];
//        Touch data = {(int)touch.hash,glm::vec2(location.x,location.y)};
//        _mainView->touchEnd(data);
//    }
}

- (void)touchesCancelled:(NSSet<UITouch*>*)touches withEvent:(UIEvent *)event {
    
    NSSet *set = [event touchesForView:self.view];
    if ([set count] > 0) {
//        UITouch *touch = [set anyObject];
//        CGPoint location = [touch locationInView:self.view];
//        Touch data = {(int)touch.hash,glm::vec2(location.x,location.y)};
    }
}

@end
