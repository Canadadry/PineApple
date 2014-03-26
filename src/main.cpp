#include <SFML/Graphics.hpp>
#include <SceneGraph/Core/scenenode.h>
#include <SceneGraph/Core/rectanglenode.h>
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

    SceneNode* child = mainNode.attachChild(new RectangleNode);
    child->x = 100;
    child->y = 100;
    child->width = 100;
    child->height = 100;
    child->origin = Geometry::TopLeft;

    mainNode.animateOf(mainNode.x,500,sf::milliseconds(300),Easing::ELASTIC_OUT);
    child->animateOf(child->rotation,360.0,sf::seconds(2.0f));

    renderSceneGraph(mainNode);

}




