#ifndef GRID
#define GRID

#include <vector>

using namespace std;

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

    // https://stackoverflow.com/a/18385553
    typedef typename vector<T>::iterator iterator;
    typedef typename vector<T>::const_iterator const_iterator;

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    iterator row_begin(size_t row_num);
    const_iterator row_begin(size_t row_num) const;
    iterator row_end(size_t row_num);
    const_iterator row_end(size_t row_num) const;

    class MutableReference {
    public:
        friend class Grid;
        T& operator[](size_t col);
        const T& operator[](size_t col) const;

    private:
        MutableReference(Grid* grid, size_t row);

        Grid* grid;  // We use pointer instead of a reference because `this` is a pointer
        size_t row;
    };

    MutableReference operator[](size_t row);
    const MutableReference operator[](size_t row) const;

    bool operator< (const Grid& other) const;
    bool operator<= (const Grid& other) const;
    bool operator== (const Grid& other) const;
    bool operator!= (const Grid& other) const;
    bool operator>= (const Grid& other) const;
    bool operator> (const Grid& other) const;

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
    // vector clear vs resize(0): https://stackoverflow.com/a/2738999
    elems.resize(0, 0);
}

template <typename T> void Grid<T>::resize(size_t rows, size_t cols) {
/*  vector resize vs assign
    =======================
    https://stackoverflow.com/a/19673757
    Assign means replacing a vector with new properties ( size and elements) Reszie means holding old data and expanding the new vector with new elements this in case the new size is greater than the old one. otherwise shrink the size and eliminate the extra. */
    // elems.resize(rows * cols);

    /* The only function that you may
    find interesting is resize , which uses the vector 's assign member function.
     assign is similar to resize in that it changes the size of the vector , but
     unlike resize assign discards all of the current vector contents and
     replaces them with the specified number of copies of the specified element.
     The use of ElemType() as the second parameter to assign means that we will 
     fill the vector with copies of the default value of the type being stored
     (since ElemType() uses the temporary object syntax to create a new ElemType ).
       */ 
    elems.assign(rows * cols, T());
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
    return elems[rows * this->cols + cols];
}

template <typename T> const T& Grid<T>::getAt(size_t rows, size_t cols) const {
    return elems[rows * this->cols + cols];
}

template <typename T> typename Grid<T>::iterator Grid<T>::begin() {
    return elems.begin();
}

template <typename T> typename Grid<T>::const_iterator Grid<T>::begin() const {
    return elems.begin();
}

template <typename T> typename Grid<T>::iterator Grid<T>::end() {
    return elems.end();
}

template <typename T> typename Grid<T>::const_iterator Grid<T>::end() const {
    return elems.end();
}

template <typename T> typename Grid<T>::iterator Grid<T>::row_begin(size_t row_num) {
    return begin() + num_cols() * row_num;
}

template <typename T> typename Grid<T>::const_iterator Grid<T>::row_begin(size_t row_num) const {
    return begin() + num_cols() * row_num;
}

template <typename T> typename Grid<T>::iterator Grid<T>::row_end(size_t row_num) {
    return begin() + num_cols() * (row_num + 1);
}

template <typename T> typename Grid<T>::const_iterator Grid<T>::row_end(size_t row_num) const {
    return row_begin(row_num) + num_cols();
}

// XXX: No `typename Grid<T>::` here, because we are defining a method, instead of an expression (e.g. the returned type)
template <typename T>  Grid<T>::MutableReference::MutableReference(Grid* grid, size_t row)
: grid(grid), row(row) {}

template <typename T> T& Grid<T>::MutableReference::operator[](size_t col) {
    return grid->getAt(row, col);
}

template <typename T> const T& Grid<T>::MutableReference::operator[](size_t col) const {
    return grid->getAt(row, col);
}

template <typename T> typename Grid<T>::MutableReference Grid<T>::operator[](size_t row) {
    return MutableReference(this, row);
}

template <typename T> const typename Grid<T>::MutableReference Grid<T>::operator[](size_t row) const {
    return MutableReference(this, row);
}

template <typename T> bool Grid<T>::operator< (const Grid<T>& other) const {
    if (rows != other.num_rows()) {
        return rows < other.num_rows();
    }

    if (cols != other.num_cols()) {
        return cols < other.num_cols();
    }

    return lexicographical_compare(begin(), end(), other.begin(), other.end());
}

template <typename T> bool Grid<T>::operator<= (const Grid<T>& other) const {
    return !(other < *this);
}

template <typename T> bool Grid<T>::operator== (const Grid<T>& other) const {
    // return !(*this < other) && !(other < *this);

    // Practice 16: Rewrite the grid 's operator== function to directly check
    //              whether the grid s are identical. Then rewrite operator!= in
    //              terms of operator== .
    if (rows != other.num_rows() || cols != other.num_cols()) {
        return false;
    }

    pair<Grid<T>::const_iterator, Grid<T>::const_iterator> result = mismatch(begin(), end(), other.begin());
    return result.first == end() && result.second == other.end();
}

template <typename T> bool Grid<T>::operator!= (const Grid<T>& other) const {
    return !(*this < other) || !(other < *this);
}

template <typename T> bool Grid<T>::operator>= (const Grid<T>& other) const {
    return !(*this < other);
}

template <typename T> bool Grid<T>::operator> (const Grid<T>& other) const {
    return other < *this;
}

#endif