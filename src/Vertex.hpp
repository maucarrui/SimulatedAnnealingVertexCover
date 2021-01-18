#include <string>

class Vertex {
    private:
        int ID;
        int xPos;
        int yPos;
        std::string name;

    public:
        Vertex(int _ID, int _xPos, int _yPos, std::string _name);

        int getID();
        int getX();
        int getY();
        std::string getName();
};
