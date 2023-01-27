#include <iostream>
#include <vector>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include "Animation.h"

using namespace std;
void Firemovement(int &firemove, int &delay,
                    sf::Music &sring, sf::Sprite &sword,
                    sf::RenderWindow &window);

void FruitMovement( vector<sf::Sprite> &fruits, sf::Sprite &fruit, sf::Sprite &sword, sf::Music &suarabuah,
                    vector<Animation> &splash, sf::Texture &splashTex, sf::RenderWindow &window, vector<sf::Vector2f> &posisi,
                    int &fruitcounter, int &count, int &point, int &x);

void Bomb(  int &bombcounter, int &count, int &hp,
             vector<sf::Sprite> &bombs, sf::Sprite &bomb, sf::Sprite &sword, 
             sf::Music &bombsound,  sf::Music &low_hp, sf::RenderWindow &window);

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Fruit Slash!");
    window.setFramerateLimit(30);
    window.setMouseCursorVisible(false);
    sf::Texture bgTex;
    sf::Sprite bg;
    bgTex.loadFromFile("background.png");
    bg.setTexture(bgTex);
    bg.setScale(2.f, 2.f);

    //Score
    sf::Font scoreTex;
    sf::Text score;
    scoreTex.loadFromFile("gang_of_three.ttf");
    score.setFont(scoreTex);
    score.setPosition(10.f, 5.f);
    score.setCharacterSize(30);
    score.setColor(sf::Color::White);
    score.setOutlineThickness(3);
    score.setOutlineColor(sf::Color::Black);
    
    //hp
    sf::Font healthTex;
    sf::Text health;
    healthTex.loadFromFile("gang_of_three.ttf");
    health.setFont(healthTex);
    health.setPosition(window.getSize().x - 100, 5.f);
    health.setCharacterSize(30);
    health.setColor(sf::Color::Red);
    health.setOutlineThickness(3);
    health.setOutlineColor(sf::Color::Black);
    int hp = 3;
    
    //fruitTex
    int count = rand()%150;
    int point = 0;
    //apple
    sf::Texture appleTex;
    sf::Sprite apple;
    appleTex.loadFromFile("apple.png");
    apple.setTexture(appleTex);
    apple.setScale(0.5f, 0.5f);
    apple.setOrigin(73.f, 80.f);
    std::vector<sf::Sprite> apples;
    apples.push_back(sf::Sprite(apple));
    int applecounter =60;
    int a = 10;

    //banana
    sf::Texture bananaTex;
    sf::Sprite banana;
    bananaTex.loadFromFile("banana.png");
    banana.setTexture(bananaTex);
    banana.setOrigin(73.f, 80.f);
    std::vector<sf::Sprite> bananas;
    bananas.push_back(sf::Sprite(banana));
    banana.setScale(0.5f, 0.5f);
    int bananacounter = 70;
    int b = 20;

    //grape
    sf::Texture grapeTex;
    sf::Sprite grape;
    grapeTex.loadFromFile("grape.png");
    grape.setTexture(grapeTex);
    grape.setOrigin(73.f, 80.f);
    std::vector<sf::Sprite> grapes;
    grapes.push_back(sf::Sprite(grape));
    grape.setScale(0.5f, 0.5f);
    int grapecounter = 80;
    int c = 50;

    //Sword
    sf::Texture swordTex;
    sf::Sprite sword;
    swordTex.loadFromFile("sword.png");
    sword.setTexture(swordTex);
    sword.setScale(0.5f,0.5f);
    int firemove = 0;
    int delay = 20;
    sword.setOrigin(76.f, 324.f);
    sword.setPosition(20.f, 100.f);

    //bomb
    sf::Texture bombTex;
    sf::Sprite bomb;
    bombTex.loadFromFile("bomb.png");
    bomb.setTexture(bombTex);
    bomb.setOrigin(110.f, 130.f);
    std::vector<sf::Sprite> bombs;
    bombs.push_back(sf::Sprite(bomb));
    bomb.setScale(0.3f, 0.3f);
    int bombcounter = 200;
    sf::Music bombsound;
    if(!bombsound.openFromFile("bombsound.wav")){
        return -1;
    }
    bombsound.setVolume(20.f);

    //SoundEffect
    sf::Music sring;
    if(!sring.openFromFile("sring.wav")){
        return -1;
    }
    sf::Music suarabuah;
    if(!suarabuah.openFromFile("suarabuah.wav")){
        return -1;
    }
    sf::Music low_hp;
    low_hp.openFromFile("low_hp.wav");
    low_hp.setVolume(30);
    
    sf::Music bgm;
    bgm.openFromFile("Taiko.wav");
    bgm.setVolume(80);
    bgm.setLoop(true);


    //ANIMATION
    sf::Texture splashTex;
    sf::Sprite splash;
    splashTex.loadFromFile("splash.png");
    splash.setTexture(splashTex);
    splash.setRotation(180.f);
    splash.setScale(0.8f, 0.8f);
    splash.setOrigin(50.f, 50.f);
    vector<Animation> Animation;
    vector<sf::Vector2f> posisi;

    //clock
    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        window.clear();
        window.draw(bg);
        bgm.play();

        deltaTime = clock.restart().asSeconds();
        if(hp <= 0){
            window.close();
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }
        int limit = rand()% 300;
    
        if(bgm.getStatus() != sf::Sound::Playing){
            bgm.play();
        }

        score.setString("SCORE : " + to_string(point)) ;
        health.setString("HP : " + to_string(hp));


        Firemovement(firemove, delay, sring, sword, window);
        FruitMovement(apples, apple, sword, suarabuah, Animation, splashTex, window, posisi, applecounter, count, point, a);
        FruitMovement(bananas, banana, sword, suarabuah,Animation ,splashTex, window, posisi, bananacounter, count, point, b);
        FruitMovement(grapes, grape, sword, suarabuah, Animation ,splashTex, window, posisi, grapecounter, count, point, c);
        Bomb(bombcounter, count, hp, bombs, bomb, sword, bombsound, low_hp, window);
        sword.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        
        
        //Draw
        for(int i = 0; i < Animation.size(); i++){
            Animation[i].Update(0, deltaTime);
            splash.setTextureRect(Animation[i].uvRect);

            splash.setPosition(posisi[i]);

            window.draw(splash);
        }
        
        window.draw(sword);
        window.draw(score);
        window.draw(health);
        window.display();

         /*for(int i = 0; i < slashing.size(); i++){
            slashing[i].Update(0, deltaTime);
            slash.setTextureRect(slashing[i].uvRect);

            slash.setPosition(effect[i]);

            window.draw(slash);
        }*/ 
    }

    return 0;
}

void Bomb(  int &bombcounter, int &count, int &hp,
             vector<sf::Sprite> &bombs, sf::Sprite &bomb, sf::Sprite &sword, 
             sf::Music &bombsound, sf::Music &low_hp, sf::RenderWindow &window){

    for(size_t i =0; i<bombs.size(); i++){
            window.draw(bombs[i]);
        }
    
    for(size_t i=0; i < bombs.size(); i ++){
            bombs[i].move(0.f, -13.f);
            if(bombs[i].getPosition().y < 0 ){
                bombs.erase(bombs.begin() + i);
            }
            bombs[i].rotate(13.f);
        }
        if(bombcounter < count){
            bombcounter ++;
        }
        if(bombcounter >= rand()%500){
            bomb.setPosition(rand()% window.getSize().x, window.getSize().y);
            bombs.push_back(sf::Sprite(bomb));
            bombcounter =0;
        }

    for (size_t i=0; i< bombs.size(); i++){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sword.getGlobalBounds().intersects(bombs[i].getGlobalBounds())){
                
                bombsound.play();
                low_hp.play();
                bombs.erase(bombs.begin() + i);

                hp -= 1;
                
            }
        }
}
 
void Firemovement(  int &firemove, int &delay,
                    sf::Music &sring, sf::Sprite &sword, 
                    sf::RenderWindow &window){
        //Update Fire
        if(firemove < 100){
            firemove++;
        }
        if(delay < 20){
            delay++;
        }else{
            sword.setRotation(0.f);
            sring.stop();

        }
        if(delay >= 20 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                sword.rotate(100.f);
                sring.play();

                delay = 0;
        }
    }

void FruitMovement(vector<sf::Sprite> &fruits, 
                    sf::Sprite &fruit,
                    sf::Sprite &sword,
                    sf::Music &suarabuah,
                    vector<Animation> &splash,
                    sf::Texture &splashTex,
                    sf::RenderWindow &window,
                    vector<sf::Vector2f> &posisi,
                    int &fruitcounter,
                    int &count,
                    int &point,
                    int &x
                    ){ 
        for(size_t i =0; i<fruits.size(); i++){
            window.draw(fruits[i]);
        }
        //collision
        for (size_t i=0; i< fruits.size(); i++){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sword.getGlobalBounds().intersects(fruits[i].getGlobalBounds())){

                Animation a(&splashTex, sf::Vector2f(6.f, 1.f), 0.08f);
                splash.push_back(a);
                posisi.push_back(fruits[i].getPosition());

                suarabuah.play();
                fruits.erase(fruits.begin() + i);

                point += x;
                
            }
        }

    for(size_t i=0; i < fruits.size(); i ++){
            fruits[i].move(0.f, -13.f);
            if(fruits[i].getPosition().y < 0 ){
                fruits.erase(fruits.begin() + i);
            }
            fruits[i].rotate(13.f);
        }
        if(fruitcounter < count){
            fruitcounter ++;
        }
        if(fruitcounter >= rand()%500){
            fruit.setPosition(rand()% window.getSize().x, window.getSize().y);
            fruits.push_back(sf::Sprite(fruit));
            fruitcounter =0;
        }
        
        
}