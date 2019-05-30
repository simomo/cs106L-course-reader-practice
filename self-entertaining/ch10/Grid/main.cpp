#include <vector>

template <typename T>
class Grid {
public:
    Grid();
    Grid(size_t rows, size_t cols);

    void clear();
    void resize(size_t rows, size_t cols);

    size_t num_rows() const;
    size_t num_cols() const;
    bool empty() const;
    size_t size() const;

    T& getAt(size_t rows, size_t cols);
    const T& getAt(size_t rows, size_t cols) const;

private:
    vector<T> elems;
    size_t rows;
    size_t cols;
};

template <typename T> Grid<T>::Grid() : elems(0), rows(0), cols(0) {};

template <typename T> Grid<T>::Grid(size_t rows, size_t cols) :
    elems(rows * cols),
    rows(rows),
    cols(cols) {};

template <typename T> void Grid<T>::clear() {
    elems.clear();
}

template <typename T> void Grid<T>::resize(size_t rows, size_t cols) {
    elems.resize(rows, cols);
    this.rows = rows;
    this.cols = cols;
}

template <typename T> size_t Grid<T>::num_rows() const {
    return rows;
}

template <typename T> size_t Grid<T>::num_cols() const {
    return cols;
}

template <typename T> bool Grid<T>::empty() const {
    return elems.empty();
}

template <typename T> size_t Grid<T>::size() const {
    return elems.size();
}

template <typename T> T& Grid<T>::getAt(size_t rows, size_t cols) {
    return elems[rows * this.cols + cols];
}

template <typename T> const T& Grid<T>::getAt(size_t rows, size_t cols) const {
    return elems[rows * this.cols + cols];
}

int main() {
    Grid<int> g1;
    Grid<int> g2(2, 3);

    return 0;
}
