#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// 2D Voxel Grid Class
// 
// template arguments are all int and arae as follows
// gridx, gridy (width and height)
// dx, dy (positive x, and y offsets)
template<int gridx, int gridy, int dx = 0, int dy = 0>
class VoxelGrid {
    private:
        // 
    public:
        VoxelGrid() {}
        void print() {
            cout << "width: " << gridx << endl;
            cout << "height: " << gridy << endl;
            cout << "delta x: " << dx << endl;
            cout << "delta y: " << dy << endl;
        }
};


int main() {
    unique_ptr<RenderWindow> window(new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Example Window"));

    VoxelGrid<WINDOW_WIDTH, WINDOW_HEIGHT> vgrid;
    vgrid.print();

    bool running = true;

    while (running) {
        Event event;
        while (window->pollEvent(event)) {
            if (event.type == Event::Closed) {
                running = false;
                window->close();
                break;
            }else if (event.type == Event::KeyPressed) {
                switch (event.key.code) {
                    case Keyboard::Escape:
                        running = false;
                        window->close();
                        break;
                    default:
                        cout << "unset key entered: " << event.key.code << endl;
                }
            }
        }
    }

    return 0;
}