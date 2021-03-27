#include <iostream>
#include <cassert>
#include <algorithm>

class ArrayInt
{
private:
    int m_capacity;
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_capacity(0), m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length) :
        m_capacity(length), m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int getLength() const { return m_length; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newLength)
    {
        if (newLength == m_length) return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        if (newLength < m_length)
        {
            for (int i = newLength; i < m_length; ++i)
                m_data[i] = 0;

            m_length = newLength;
            return;
        }
        
        if (newLength <= m_capacity)
        {
            m_length = newLength;
            return;
        }

        m_capacity = newLength * 2;
        int* data = new int[m_capacity];
        
        for (int index = 0; index < m_length; ++index)
            data[index] = m_data[index];

        for (int hid = m_length; hid < m_capacity; hid++)
            data[hid] = 0;

        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);

        if (m_capacity > m_length)
        {
            for (int after = m_length; after > index; --after)
                m_data[after] = m_data[after - 1];

            m_data[index] = value;
            ++m_length;
        }
        else
        {
            this->resize(m_length + 1);
            
            for (int after = m_length; after > index; --after)
                m_data[after] = m_data[after - 1];

            m_data[index] = value;
        }
    }

    void push_back(int value) { insertBefore(value, m_length); }

    void print() const
    {
        for (int i = 0; i < m_length; i++)
        {
            std::cout << '[' << m_data[i] << "] ";
        }
        puts("");
    }

    void pop_back()
    {
        this->resize(m_length - 1);
    }

    void pop_front()
    {
        for (int i = 0; i < m_length - 1; ++i)
            m_data[i] = m_data[i + 1];
        
        m_data[--m_length] = 0;
    }

    void sort()
    {
        for (int startIndex = 0; startIndex < m_length - 1; ++startIndex)
        {
            int smallestIndex = startIndex;
            for (int currentIndex = startIndex + 1; currentIndex < m_length; ++currentIndex)
            {
                if (m_data[currentIndex] < m_data[smallestIndex])
                    smallestIndex = currentIndex;
            }
            std::swap(m_data[startIndex], m_data[smallestIndex]);
        }
    }

    int* begin() { return m_data; }
    int* end() { return &m_data[m_length]; }
};


int main(int argc, char *argv[])
{
    ArrayInt arr(5);
    for (int i = 0; i < arr.getLength(); i++)
        arr[i] = i + 3;
    arr.print();

    arr.insertBefore(15, 2);
    arr.print();
    arr.push_back(25);
    arr.push_back(-1);
    arr.push_back(27);
    arr.push_back(28);
    arr.print();

    arr.resize(15);
    arr.print();

    arr.resize(9);
    arr.print();

    arr.pop_back();
    arr.print();

    arr.pop_front();
    arr.print();

    std::sort(arr.begin(), arr.end());
    //arr.sort(); // альттернатива
    arr.print();

    return 0;
}
