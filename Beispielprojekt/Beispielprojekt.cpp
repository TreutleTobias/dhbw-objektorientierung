#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

class GameWindow : public Gosu::Window
{
public:

	GameWindow()
		: Window(800, 600)
	{
		set_caption("Gosu Tutorial mit Git");
	}

	// Wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{

		Gosu::Graphics::draw_triangle(
			x, y, Gosu::Color::RED,
			200, 100, Gosu::Color::GREEN,
			200, 400, Gosu::Color::BLUE,
			0.0
		);
	}
	double x = 0;
	double y = 0;

	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{

		x = input().mouse_x();
		y = input().mouse_y();
	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
