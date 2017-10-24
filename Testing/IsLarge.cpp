template <class T>
class IsLarge
{
private:
    IsLarge(T t0) : t(t0) {};
    bool operator () (T x) { return x > t; }

public:
    T t;
};
