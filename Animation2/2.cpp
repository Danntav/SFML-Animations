#include <SFML/Graphics.hpp>


int main(){

	int default_width = 1000;
	int default_height= 1000;
	float angle = 0.0;

	sf::ContextSettings settings;
	settings.antialiasingLevel=8;
	sf::RenderWindow window(sf::VideoMode(default_width,default_height), "Animation2");

	window.setFramerateLimit(60);

	sf::CircleShape shape(300.f);

	shape.setOutlineThickness(2);
	shape.setFillColor(sf::Color::Transparent);
	shape.setPointCount(300);
	shape.setOrigin(300.f, 300.f);
	shape.setPosition(default_width/2, default_height/2);

	while(window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
		}
		int blueColor= (blueColor + 1) % 256;
		int redColor = (redColor + 2) % 256;
		int greenColor = (greenColor + 3) % 256;
		angle += 0.1;
		if (angle >= 360.0){
			angle = 0.0;}

		shape.setRotation(angle);
		shape.setOutlineColor(sf::Color(redColor, greenColor, blueColor));

		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}
