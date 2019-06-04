#include <iostream>
#include <algorithm>

template<typename T>
class Sort {
    T *container = nullptr;
    int length = 0;
    int capacity = 5;

public:
    void addElement(T item)
    {
        if(length + 1 >= capacity) {
            int newCapacity = capacity * 2;
            T *newArray = new T[newCapacity];
            for(int i = 0; i < length; i++) {
                newArray[i] = container[i];
            }
            delete[] container;
            container = newArray;
        }
        container[length++] = item;
    }

    const T* getContainer()
    {
        return container;
    }

    int getLength()
    {
        return length;
    }

    void sortAscending()
    {
        std::sort(container, container + length, [](const auto& a, const auto& b) { return a < b; });
    }

    void sortDescending()
    {
        std::sort(container, container + length, [](const auto& a, const auto& b) { return a > b; });
    }

    Sort()
    {
        container = new T[capacity];
    }

    ~Sort()
    {
        delete[] container;
    }
};

class HappyAlpaca {
    int happiness = 0;

public:
    HappyAlpaca()
    {
    }

    HappyAlpaca(int h)
    {
        happiness = h;
    }

    bool operator<(const HappyAlpaca &a) const
    {
        return happiness < a.happiness;
    }

    bool operator>(const HappyAlpaca &a) const
    {
        return happiness > a.happiness;
    }

    friend std::ostream& operator<<(std::ostream& out, const HappyAlpaca &a);
};

std::ostream& operator<<(std::ostream& out, const HappyAlpaca &a)
{
    out << "happiness: " << a.happiness;
    return out;
}

int main() {
    Sort<int> si;
    si.addElement(5);
    si.addElement(3);
    si.addElement(0);
    si.addElement(2);
    si.addElement(9);
    si.sortAscending();
    const int* cptr = si.getContainer();
    for(int i = 0; i < si.getLength(); i++) {
        std::cout << cptr[i] << " ";
    }
    std::cout << std::endl;
    si.sortDescending();
    for(int i = 0; i < si.getLength(); i++) {
        std::cout << cptr[i] << " ";
    }
    std::cout << std::endl;

    Sort<double> sd;
    sd.addElement(3.1415926535);
    sd.addElement(2.71);
    sd.addElement(0.001);
    sd.addElement(-1.16);
    sd.sortAscending();
    const double* cdptr = sd.getContainer();
    for(int i = 0; i < sd.getLength(); i++) {
        std::cout << cdptr[i] << " ";
    }
    std::cout << std::endl;
    sd.sortDescending();
    for(int i = 0; i < sd.getLength(); i++) {
        std::cout << cdptr[i] << " ";
    }
    std::cout << std::endl;

    Sort<std::string> ss;
    ss.addElement("asdf");
    ss.addElement("aaaa");
    ss.addElement("bb");
    ss.addElement("abc");
    ss.sortAscending();
    const std::string* csptr = ss.getContainer();
    for(int i = 0; i < ss.getLength(); i++) {
        std::cout << csptr[i] << " ";
    }
    std::cout << std::endl;
    ss.sortDescending();
    for(int i = 0; i < ss.getLength(); i++) {
        std::cout << csptr[i] << " ";
    }
    std::cout << std::endl;

    Sort<HappyAlpaca> sha;
    sha.addElement(HappyAlpaca(5));
    sha.addElement(HappyAlpaca(-2));
    sha.addElement(HappyAlpaca(9));
    sha.addElement(HappyAlpaca(1));
    sha.sortAscending();
    const HappyAlpaca* cshaptr = sha.getContainer();
    for(int i = 0; i < sha.getLength(); i++) {
        std::cout << cshaptr[i] << " ";
    }
    std::cout << std::endl;
    sha.sortDescending();
    for(int i = 0; i < sha.getLength(); i++) {
        std::cout << cshaptr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}