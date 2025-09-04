class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distX = abs(x - z);
        int distY = abs(y - z);

        if (distX < distY) return 1;
        else if (distY < distX) return 2;
        else return 0;
    }
};