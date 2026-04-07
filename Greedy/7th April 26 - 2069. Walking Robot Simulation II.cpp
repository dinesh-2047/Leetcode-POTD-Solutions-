// 2069. Walking Robot Simulation II

class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    char dir;

    Robot(int width, int height) {
        w = width;
        h = height;
        dir = 'E';
    }

    void step(int num) {
        int cycle = 2 * (w + h) - 4;
        num %= cycle;

        if(num == 0 ) num = cycle;

        while (num--) {
            if (dir == 'E') {
                if (x + 1 < w) x++;
                else {
                    dir = 'N';
                    y++;
                }
            }
            else if (dir == 'N') {
                if (y + 1 < h) y++;
                else {
                    dir = 'W';
                    x--;
                }
            }
            else if (dir == 'W') {
                if (x - 1 >= 0) x--;
                else {
                    dir = 'S';
                    y--;
                }
            }
            else {
                if (y - 1 >= 0) y--;
                else {
                    dir = 'E';
                    x++;
                }
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        if (dir == 'N') return "North";
        if (dir == 'S') return "South";
        if (dir == 'E') return "East";
        return "West";
    }
};