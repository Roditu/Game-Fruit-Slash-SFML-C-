#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2f imagecount, float switchT)
{
    this->imagecount = imagecount;
    this->switchT = switchT;
    totalT = 0.0f;
    currentimage.x =0;

    uvRect.width = texture->getSize().x / float(imagecount.x);
    uvRect.height = texture->getSize().y / float(imagecount.y);

}


void Animation::Update(int row, float deltaT)
{
    currentimage.y = row;
    totalT += deltaT;
    
    if(totalT >= switchT){
        totalT -= switchT;
        currentimage.x++;
       
        //Current wont pass out from image
        if(currentimage.x >= imagecount.x){
            currentimage.x;
        }
    }

    uvRect.left = currentimage.x * uvRect.width;
    uvRect.top = currentimage.y * uvRect.height;
}
