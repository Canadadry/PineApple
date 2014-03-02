#include <SFML/Graphics.hpp>
#include <SceneGraph/scenenode.h>
#include <SceneGraph/rectanglenode.h>
#include <iostream>

void renderSceneGraph(const SceneNode& mainNode)
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "PineApple Test",sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

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


	window.clear(sf::Color::Black);
	window.draw(mainNode);
	window.display();
    }
}


int main(int argc, char** argv)
{
    printf("build time %s\n",__TIME__);

    RectangleNode mainNode;
    mainNode.setPosition(100,100);
    mainNode.rotate(45);
    mainNode.attachChild(new RectangleNode)->setPosition(sf::Vector2f(100,100));

    renderSceneGraph(mainNode);

}




