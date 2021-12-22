//
//  ImageView.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 6/11/2015.
//  Copyright © 2015 The Caffeinated Coder. All rights reserved.
//

#ifndef ImageView_hpp
#define ImageView_hpp

#include <stdio.h>

#include "View.hpp"
#include "Sprite.h"
#include "MathConstants.h"
#include "ImageViewRenderer.hpp"

#define IMAGEVIEW_DEFAULT_POSITION VECTOR_EMPTY
#define IMAGEVIEW_DEFAULT_SHAPE 

class ImageView : public View {
    
public:
    ImageView();
    ImageView(const Sprite& sprite);
    ImageView(const Sprite& sprite, const glm::vec2& position);
    ImageView(const Sprite& sprite, const glm::vec2& position, const glm::vec2& size);
    ~ImageView();
    
    void setSprite(Sprite sprite);
private:
};

#endif /* ImageView_hpp */
