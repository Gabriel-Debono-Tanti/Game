#include <SFML/Graphics.hpp>
#include "Biome.hpp"
#include "Object.hpp"


#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <ctime>

using namespace std;
using namespace sf;


//Color dd(111, 111, 111);
//Color cw(89, 176, 13);
//Color c(0,202,27);
//Color c2(67,202,0);
//Color magic(58, 228, 205);
//Color maple(103, 137, 24);
//Color cdb(33, 78, 211);
//Color a(132, 8, 16);
//Color co(8, 146, 208);
//Color swa(35, 40, 0);
//Color ta(0, 66, 37);

void damageClickedSprites(std::vector<Object>& trees, Vector2f clickPosF) {
    for (auto& sprite : trees) {
        if (sprite.contains(Vector2f(clickPosF))) {
            sprite.takeDamage(10);
            if (sprite.m_health <= 0) {
                // destroy sprite
                auto it = std::find_if(trees.begin(), trees.end(),
                                       [&sprite](const Object &s) { return &s == &sprite; });
                trees.erase(it);
            }
        }
    }
}

void updateTrees(std::vector<Object>& trees, RenderWindow& window) {
    for (auto& sprite : trees)
    {
        for (auto& otherSprite : trees)
        {
            if (&sprite == &otherSprite)
            {
                continue;
            }

            // Calculate the distance between the sprites
            sf::Vector2f displacement = sprite.getPosition() - otherSprite.getPosition();
            float distance = sqrt(displacement.x * displacement.x + displacement.y * displacement.y);

            // If the sprites are colliding, subtract damage from the sprite's health
            if (distance < sprite.getRadius() + otherSprite.getRadius())
            {
                sprite.takeDamage(std::rand() % 10 + 1);
            }
        }
    }

    // Remove any sprites whose health has reached 0 or less
    trees.erase(std::remove_if(trees.begin(), trees.end(), [](const Object& sprite) {
        return !sprite.isAlive();
    }), trees.end());

    // Draw sprites to window
    for (auto& sprite : trees){
        sprite.draw(window);
    }
}

int main() {

    Texture gl;
    gl.loadFromFile("Art/Others/Biomes/gl.png");
    Texture ds;
    ds.loadFromFile("Art/Others/Biomes/desertbiome.png");
    Texture bf;
    bf.loadFromFile("Art/Others/Biomes/birchforest.png");
    Texture col;
    col.loadFromFile("Art/Others/Biomes/countryland.png");
    Texture magic;
    magic.loadFromFile("Art/Others/Biomes/magicalforest.png");
    Texture dd;
    dd.loadFromFile("Art/Others/Biomes/deathdesertbiome.png");
    Texture maple;
    maple.loadFromFile("Art/Others/Biomes/mapleforest.png");
    Texture cdb;
    cdb.loadFromFile("Art/Others/Biomes/ci.png");
    Texture cw;
    cw.loadFromFile("Art/Others/Biomes/cherrywoods.png");
    Texture ta;
    ta.loadFromFile("Art/Others/Biomes/taigabiome.png");
    Texture swa;
    swa.loadFromFile("Art/Others/Biomes/swampbiome.png");
    Texture a;
    a.loadFromFile("Art/Others/Biomes/alaphanty.png");
    Texture co;
    co.loadFromFile("Art/Others/Biomes/comory.png");
    Texture moun;
    moun.loadFromFile("Art/Others/Biomes/mountains.png");
    Texture cl;
    cl.loadFromFile("Art/Others/Biomes/coldbiome.png");
    Texture fl;
    fl.loadFromFile("Art/Others/Biomes/flower.png");
    Biome grassland(Vector2f(700, 700), &gl);
    Biome desert(Vector2f(600, 600), &ds);
    Biome birchforest(Vector2f(950, 950), &bf);
    Biome countryland(Vector2f(900, 900), &col);
    Biome magicalforest(Vector2f(900, 900), &magic);
    Biome mapleforest(Vector2f(900, 950), &maple);
    Biome CherryWoods(Vector2f(800, 1350), &cw);
    Biome Moun(Vector2f(1600, 650), &moun);
    Biome cold(Vector2f(700, 1000), &cl);
    Biome flower(Vector2f(500, 700), &fl);
    Biome DeathD(Vector2f(900, 900), &dd);
    Biome CB(Vector2f(400, 400), &cdb);

    Biome Taiga(Vector2f(1000, 800), &ta);
    Biome Swamp(Vector2f(500, 500), &swa);
    Biome Al(Vector2f(650, 650), &a);
    Biome Com(Vector2f(600, 600), &co);


    time_t now = time(0);
    tm *ltm = localtime(&now);
    sf::View view1;
    view1.setSize(1000.f, 1000.f);

// zoom the view relatively to its current size (apply a factor 0.5, so its final size is 600x400)
    view1.zoom(6);
    ContextSettings settings;

    RenderWindow window(VideoMode(800, 800), "New Game", Style::Titlebar | Style::Close, settings);
    window.setFramerateLimit(60);
    grassland.setPos(Vector2f(-1000, 550));
    desert.setPos(Vector2f(500, 1000));
    birchforest.setPos(Vector2f(-1200, -1200));
    countryland.setPos(Vector2f(-400, 300));
    magicalforest.setPos(Vector2f(1000, 200));
    mapleforest.setPos(Vector2f(-300, -1150));
    CherryWoods.setPos(Vector2f(1200, -1150));
    Moun.setPos(Vector2f(-400, -300));
    cold.setPos(Vector2f(600, -1150));
    flower.setPos(Vector2f(500, 350));
    DeathD.setPos(Vector2f(-1300, -300));
    CB.setPos(Vector2f(-2000, 2500));
    Swamp.setPos(Vector2f(-1000, 1250));
    Taiga.setPos(Vector2f(-500, 1200));
    Al.setPos(Vector2f(2000, 2400));
    Com.setPos(Vector2f(-2000, -2000));
    Texture t;
    t.loadFromFile("Art/Trees/tree1.png");
    Texture cherryt;
    cherryt.loadFromFile("Art/Trees/tree6.png");
    Texture Bircht;
    Bircht.loadFromFile("Art/Trees/tree2.png");
    Texture Maplet;
    Maplet.loadFromFile("Art/Trees/tree4.png");
    Texture bonet;
    bonet.loadFromFile("Art/Trees/bonetree.png");
    Texture taigat;
    taigat.loadFromFile("Art/Trees/tree3.png");
    Texture magicalt;
    magicalt.loadFromFile("Art/Trees/tree5.png");
    Texture mangrovet;
    mangrovet.loadFromFile("Art/Trees/tree7.png");
    Texture Icespiket;
    Icespiket.loadFromFile("Art/Trees/ICESPIKE.png");
    Texture burntt;
    burntt.loadFromFile("Art/Trees/burnttree.png");
    //Sprite oaktree[100];
    // for(int i = 0; i < 100; i++){
    //    int x = rand()%(480+400 + 1) - 400;
    //    int y = rand()%(1200-300 + 1) + 300;
    //    oaktree[i].setPosition(x, y);
    //   oaktree[i].setTexture(t);

    // }
    auto month = 1 + ltm->tm_mon;
    auto day = ltm->tm_mday;
    std::vector<Object> oaktrees;
    std::vector<Object> cherrytrees;
    std::vector<Object> Birchtrees;
    std::vector<Object> Mapletrees;
    std::vector<Object> bonetrees;
    std::vector<Object> taigatrees;
    std::vector<Object> magicaltrees;
    std::vector<Object> mangrovetrees;
    std::vector<Object> Icespikes;
    std::vector<Object> burnttrees;

    std::vector<std::vector<Object>> treeTypes;

    treeTypes.push_back(oaktrees);
    treeTypes.push_back(cherrytrees);
    treeTypes.push_back(Birchtrees);
    treeTypes.push_back(Mapletrees);
    treeTypes.push_back(bonetrees);
    treeTypes.push_back(taigatrees);
    treeTypes.push_back(magicaltrees);
    treeTypes.push_back(mangrovetrees);
    treeTypes.push_back(Icespikes);
    treeTypes.push_back(burnttrees);

    for (int i = 0; i < 200; ++i) {
        int x = rand() % ((int) (countryland.biome.getSize().x + countryland.biome.getPosition().x) - 50 -
                          (int) (countryland.biome.getPosition().x) - 1) + countryland.biome.getPosition().x;
        int y = rand() % ((int) (countryland.biome.getSize().y + countryland.biome.getPosition().y) - 60 -
                          (int) (countryland.biome.getPosition().y) - 1) + countryland.biome.getPosition().y;
        Object tree(t, Vector2f((x), (y)), 500);
        // Push the sprite into the vector
        oaktrees.push_back(tree);
    }
    for (int i = 0; i < 200; ++i) {
        int x = rand() % ((int) (CherryWoods.biome.getSize().x + CherryWoods.biome.getPosition().x) - 50 -
                          (int) (CherryWoods.biome.getPosition().x) - 1) + CherryWoods.biome.getPosition().x;
        int y = rand() % ((int) (CherryWoods.biome.getSize().y + CherryWoods.biome.getPosition().y) - 60 -
                          (int) (CherryWoods.biome.getPosition().y) - 1) + CherryWoods.biome.getPosition().y;
        Object tree(cherryt, Vector2f((x), (y)), 10000);
        // Push the sprite into the vector
        cherrytrees.push_back(tree);
    }
    for (int i = 0; i < 200; ++i) {
        int x = rand() % ((int) (birchforest.biome.getSize().x + birchforest.biome.getPosition().x) - 50 -
                          (int) (birchforest.biome.getPosition().x) - 1) + birchforest.biome.getPosition().x;
        int y = rand() % ((int) (birchforest.biome.getSize().y + birchforest.biome.getPosition().y) - 60 -
                          (int) (birchforest.biome.getPosition().y) - 1) + birchforest.biome.getPosition().y;
        Object tree(Bircht, Vector2f((x), (y)), 10000);
        // Push the sprite into the vector
        Birchtrees.push_back(tree);
    }

    for (int i = 0; i < 200; ++i) {
        int x = rand() % ((int) (mapleforest.biome.getSize().x + mapleforest.biome.getPosition().x) - 90 -
                          (int) (mapleforest.biome.getPosition().x) - 1) + mapleforest.biome.getPosition().x + 70;
        int y = rand() % ((int) (mapleforest.biome.getSize().y + mapleforest.biome.getPosition().y) - 150 -
                          (int) (mapleforest.biome.getPosition().y) - 1) + mapleforest.biome.getPosition().y;
        Object tree(Maplet, Vector2f((x), (y)), 10000);
        // Push the sprite into the vector
        Mapletrees.push_back(tree);
    }
    for (int i = 0; i < 200; ++i) {
        int x = rand() % ((int) (DeathD.biome.getSize().x + DeathD.biome.getPosition().x) - 50 -
                          (int) (DeathD.biome.getPosition().x) - 1) + DeathD.biome.getPosition().x;
        int y = rand() % ((int) (DeathD.biome.getSize().y + DeathD.biome.getPosition().y) - 60 -
                          (int) (DeathD.biome.getPosition().y) - 1) + DeathD.biome.getPosition().y;
        Object tree(bonet, Vector2f((x), (y)), 1000);
        // Push the sprite into the vector
        bonetrees.push_back(tree);
    }
    for (int i = 0; i < 200; ++i) {
        int x = rand() % ((int) (Taiga.biome.getSize().x + Taiga.biome.getPosition().x) - 50 -
                          (int) (Taiga.biome.getPosition().x) - 1) + Taiga.biome.getPosition().x;
        int y = rand() % ((int) (Taiga.biome.getSize().y + Taiga.biome.getPosition().y) - 60 -
                          (int) (Taiga.biome.getPosition().y) - 1) + Taiga.biome.getPosition().y;
        Object tree(taigat, Vector2f((x), (y)), 1000);
        // Push the sprite into the vector
        taigatrees.push_back(tree);
    }
    for (int i = 0; i < 200; ++i) {
        int x = rand() % ((int) (magicalforest.biome.getSize().x + magicalforest.biome.getPosition().x) - 50 -
                          (int) (magicalforest.biome.getPosition().x) - 1) + magicalforest.biome.getPosition().x;
        int y = rand() % ((int) (magicalforest.biome.getSize().y + magicalforest.biome.getPosition().y) - 60 -
                          (int) (magicalforest.biome.getPosition().y) - 1) + magicalforest.biome.getPosition().y;
        Object tree(magicalt, Vector2f((x), (y)), 1000);
        // Push the sprite into the vector
        magicaltrees.push_back(tree);
    }
    for (int i = 0; i < 200; ++i) {
        int x = rand() % ((int) (Swamp.biome.getSize().x + Swamp.biome.getPosition().x) - 50 -
                          (int) (Swamp.biome.getPosition().x) - 1) + Swamp.biome.getPosition().x;
        int y = rand() % ((int) (Swamp.biome.getSize().y + Swamp.biome.getPosition().y) - 60 -
                          (int) (Swamp.biome.getPosition().y) - 1) + Swamp.biome.getPosition().y;
        Object tree(mangrovet, Vector2f((x), (y)), 1000);
        // Push the sprite into the vector
        mangrovetrees.push_back(tree);
    }
    for (int i = 0; i < 200; ++i) {
        int x = rand() % ((int) (cold.biome.getSize().x + cold.biome.getPosition().x) - 150 -
                          (int) (cold.biome.getPosition().x) - 1) + cold.biome.getPosition().x;
        int y = rand() % ((int) (cold.biome.getSize().y + cold.biome.getPosition().y) - 200 -
                          (int) (cold.biome.getPosition().y) - 1) + cold.biome.getPosition().y;
        Object tree(Icespiket, Vector2f((x), (y)), 1000);
        // Push the sprite into the vector
        Icespikes.push_back(tree);
    }
    for (int i = 0; i < 200; ++i) {
        int x = rand() %
                ((int) (Al.biome.getSize().x + Al.biome.getPosition().x) - 50 - (int) (Al.biome.getPosition().x) - 1) +
                Al.biome.getPosition().x;
        int y = rand() %
                ((int) (Al.biome.getSize().y + Al.biome.getPosition().y) - 50 - (int) (Al.biome.getPosition().y) - 1) +
                Al.biome.getPosition().y;
        Object tree(burntt, Vector2f((x), (y)), 500);
        // Push the sprite into the vector
        burnttrees.push_back(tree);
    }

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

            // and align shape

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);

                for (auto &treeType : treeTypes) {
                    damageClickedSprites(treeType, mousePosF);
                }
            }
        }


        window.clear(sf::Color::Blue);

        mapleforest.drawTo(window);
        grassland.drawTo(window);
        desert.drawTo(window);
        birchforest.drawTo(window);
        countryland.drawTo(window);


        cold.drawTo(window);
        flower.drawTo(window);
        Moun.drawTo(window);
        countryland.drawTo(window);
        DeathD.drawTo(window);
        Swamp.drawTo(window);
        Taiga.drawTo(window);
        Al.drawTo(window);
        Com.drawTo(window);
        CherryWoods.drawTo(window);
        magicalforest.drawTo(window);

        window.setView(view1);
        if (day == 6 && month == 5) {
            CB.drawTo(window);
        }

        for (auto &treeType: treeTypes) {
            updateTrees(treeType, window);
        }
    }

    return 0;
}