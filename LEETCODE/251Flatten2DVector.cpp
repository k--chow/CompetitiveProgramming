class Vector2D {
public:
    int currentRow;
    int currentCol;
    vector<vector<int>> arr;
    Vector2D(vector<vector<int>>& vec2d) {
        currentRow = 0;
        currentCol = -1;
        arr = vec2d;
    }

    int next() {
        return arr[currentRow][currentCol];
    }

    bool hasNext() {
        currentCol++;
        if (arr.size() == 0) return false;
        while (currentCol == arr[currentRow].size()) {
            currentRow++;
            currentCol = 0;
            if (currentRow == arr.size()) {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
