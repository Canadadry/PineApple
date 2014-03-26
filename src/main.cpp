#include <SFML/Graphics.hpp>
#include <SceneGraph/Core/scenenode.h>
#include <SceneGraph/Core/rectanglenode.h>
#include <SceneGraph/Core/spritenode.h>
#include <SceneGraph/Core/textnode.h>
#include <iostream>

void renderSceneGraph(SceneNode& mainNode)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "PineApple Test",sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    sf::Clock clock;
    while (window.isOpen())
    {
	sf::Event event;
	while (window.pollEvent(event))
	{
	    if (event.type == sf::Event::Closed)
	    {
		window.close();
	    }
	}
	sf::Time elapsed = clock.restart();
	mainNode.update(elapsed);
	window.clear(sf::Color::Black);
	window.draw(mainNode);
	window.display();
    }
}


int main(int argc, char** argv)
{
    printf("build time %s\n",__TIME__);


    RectangleNode mainNode;
    mainNode.x = 100;
    mainNode.y = 100;
    mainNode.width = 100;
    mainNode.height = 100;
    mainNode.color = sf::Color::Red;
    //mainNode.rotation = 45;
    mainNode.origin = Geometry::TopLeft;

    std::string lena_path = "/Users/mooglwy/Pictures/lena.png";
    sf::Texture lena;
    if(lena.loadFromFile(lena_path) == false) return EXIT_FAILURE;
    SpriteNode* sprite = new SpriteNode(lena);
    sprite->x = 100;
    sprite->y = 100;
    sprite->origin = Geometry::TopLeft;
    sprite->scale = 0.2;
    mainNode.attachChild(sprite);

    TextNode* text = new TextNode;
    text->x = 100;
    text->y = 200;
    text->origin = Geometry::TopLeft;
    text->text = "I m lena";
    text->fontName = "/Library/Fonts/Impact.ttf";
    mainNode.attachChild(text);

    mainNode.animateOf(mainNode.x,500,sf::milliseconds(300),Easing::ELASTIC_OUT);
    sprite->animateOf(sprite->rotation,360.0,sf::seconds(2.0f));

    renderSceneGraph(mainNode);

    return EXIT_SUCCESS;
}




