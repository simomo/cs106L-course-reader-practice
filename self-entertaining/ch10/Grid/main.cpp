template <typename T> class Grid {
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