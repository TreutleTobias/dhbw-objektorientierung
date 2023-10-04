/*#include <Gosu/Gosu.hpp>
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

	drawQuad(0, 0, 0xff000000);
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
*/
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

class MyWindow : public Gosu::Window {
public:
	MyWindow() : Gosu::Window(800, 600) {
	}

	void draw() {
		// Löschen Sie den Bildschirm
		graphics().draw_quad(100.0, 400.0,Gosu::Color::GREEN, 200.0, 500.0, Gosu::Color::GREEN, 300.0, 800.0, Gosu::Color::GREEN,400.0, 600.0, Gosu::Color::GREEN,0);

		
	}
};

int main() {
	MyWindow window;
	window.show();
	return 0;
}
