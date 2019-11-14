#include <SFML/Graphics.hpp>
using namespace sf;


typedef struct 
{
    int x, y;
} vertex_t;


bool is_in_triangle(vertex_t, vertex_t, vertex_t, int, int);


int main()
{
    RenderWindow window(VideoMode(800, 600), "Sierpinski triangle");
    window.setFramerateLimit(60);

    srand(time(0));

    RectangleShape point(Vector2f(1, 1));
    point.setFillColor(Color::Black);

    vertex_t A, B, C;
    A.x = 50, A.y = 550;
    B.x = 400, B.y = 50;
    C.x = 750, C.y = 550;

    int x = 0, y = 0;
    int which;

    while (!is_in_triangle(A, B, C, x, y))
    {
        x = rand() % 800;
        y = rand() % 600;
    }

    window.clear(Color::White);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        for(int i = 0; i < 50; i++)
        {
            point.setPosition(x, y);
            which = rand() % 3;
            switch(which)
            {
            case 0:
                x = (A.x + x) / 2;
                y = (A.y + y) / 2;
                break;
            case 1:
                x = (B.x + x) / 2;
                y = (B.y + y) / 2;
                break;
            case 2:
                x = (C.x + x) / 2;
                y = (C.y + y) / 2;
                break;
            }
            window.draw(point);
        }

        window.display();
    }

    return 0;
}


bool is_in_triangle(vertex_t A, vertex_t B, vertex_t C, int x, int y)
{
    int a = (A.x - x) * (B.y - A.y) - (B.x - A.x) * (A.y - y);
    int b = (B.x - x) * (C.y - B.y) - (C.x - B.x) * (B.y - y);
    int c = (C.x - x) * (A.y - C.y) - (A.x - C.x) * (C.y - y);
    if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
        return true;
    else
        return false;
}