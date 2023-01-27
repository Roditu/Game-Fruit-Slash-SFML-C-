#include <SFML\Graphics.hpp>

class Animation
{
private:
    //choosing image
    sf::Vector2f imagecount;
    sf::Vector2f currentimage;

    //animation time
    float totalT;
    float switchT;

public:
    Animation(sf::Texture* texture, sf::Vector2f imagecount, float switchT);

    //texture rectangle
    sf::IntRect uvRect;

    //Update
    void Update(int row, float deltaT);
};