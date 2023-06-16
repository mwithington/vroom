class Tile {
  public:
    Tile();
    Tile(int x, int y, int w, int h, int type);
    ~Tile();
    void render();
    void update();
    void setX(int x);
    void setY(int y);
    void setW(int w);
    void setH(int h);
    void setType(int type);
    int getX();
    int getY();
    int getW();
    int getH();
    int getType();
}
