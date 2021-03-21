#include <iostream>

struct string {
    char *str;
    size_t size;
    size_t capacity;

    string()
    {
            str = new char[2];
            size = 0;
            capacity = 2;
    }  // Конструктор пустой строки

    string(size_t cnt, char c)
    {
        str = new char[cnt*2];
        size = cnt;
        capacity = cnt*2;
        for(size_t i=0;i<cnt;i++)
        {
            str[i]=c;
        }

    }  // Заполняющий конструктор

    string(const string& s)
    {
        str = new char[s.capacity];
        size = s.size;
        capacity = s.capacity;
        for(size_t i=0;i<s.size;i++)
        {
            str[i] = s.str[i];
        }
    }  // Копирующий конструктор

    string(char c)
    {
        str = new char[2];
        size = 1;
        capacity = 2;
        str[0] = c;
    } // Конструктор строки из одного символа

    string(const char * c_str)
    {
        size_t i = 0;
        while(c_str[i]!=0)
        {
            i++;
        }
        str = new char[i*2];
        size = i;
        capacity = i*2;
        for(size_t j=0; j<i; j++)
        {
            str[j] = c_str[j];
        }
    }// Конструктор строки из c-style строки (массива символов)

    ~string()
    {
        delete [] str;
    }     //очистить всю используемую память

    string& operator= (const string& new_str)
    {
        str = new char[new_str.capacity];
        size = new_str.size;
        for(size_t i=0;i<size;i++)
        {
            str[i] = new_str.str[i];
        }
    }

    bool operator== (const string& other)
    {
        if(size!=other.size)
            return 0;
        else
            for(size_t i=0; i<size; i++)
            {
                if(str[i]!=other.str[i])
                    return 0;
            }
            return 1;


    }

    bool operator!= (const string& other)
    {
        if(size!=other.size)
            return 1;
        else
            for(size_t i=0; i<size; i++)
            {
                if(str[i]!=other.str[i])
                    return 1;
            }
            return 0;

    }

    bool operator> (const string& other)
    {
        if(size>other.size)
        {
            for(size_t i=0; i<other.size; i++)
            {
                if(str[i]<other.str[i])
                    return 0;
                if(str[i]>other.str[i])
                    return 1;
            }
            return 1;
        }

        if(size<other.size)
        {
            for(size_t i=0; i<size; i++)
            {
                if(str[i]<other.str[i])
                    return 0;
                if(str[i]>other.str[i])
                    return 1;
            }
            return 0;
        }

        if(size = other.size)
        {
            for(size_t i=0; i<size; i++)
            {
                if(str[i]<other.str[i])
                    return 0;
                if(str[i]>other.str[i])
                    return 1;
            }
            return 0;
        }

    }

    bool operator< (const string& other)
    {
        if(size>other.size)
        {
            for(size_t i=0; i<other.size; i++)
            {
                if(str[i]<other.str[i])
                    return 1;
                if(str[i]>other.str[i])
                    return 0;
            }
            return 0;
        }

        if(size<other.size)
        {
            for(size_t i=0; i<size; i++)
            {
                if(str[i]<other.str[i])
                    return 1;
                if(str[i]>other.str[i])
                    return 0;
            }
            return 1;
        }

        if(size = other.size)
        {
            for(size_t i=0; i<size; i++)
            {
                if(str[i]<other.str[i])
                    return 1;
                if(str[i]>other.str[i])
                    return 0;
            }
            return 0;
        }

    }

    string& operator+= (const string& other)
    {
       char * a = new char[capacity+other.capacity];
       size_t b = size + other.size;
       for(size_t i=0; i<size;i++)
       {
           a[i]=str[i];
       }
       for(size_t i=0;i<other.size;i++)
       {
           a[size+i]=other.str[i];
       }

        delete [] str;
        str = a;
    }

    char operator[] (unsigned int pos) const
    {
        return str[pos];
    }

    void append(const string other)
    {
        *this+=other;

    }  // дописать в конец данной строки другую

    void resize(unsigned int new_capacity)
    {
        capacity+=new_capacity;
    }// увеличить/уменьшить емкость строки

    void reserve(unsigned int capacity); // зарезервировать память в нужном объеме

    void insert(unsigned int pos, string other);  // Вставка другой строки внутрь данной

    void shrink_to_fit();  //очистить неиспользуемую память

    void clear()
    {
    }   //очистить содержимое строки, занимаемое место при этом не меняется

    friend std::ostream& operator<< (std::ostream& ostr, const string& str) {  }
    friend std::istream& operator>> (std::istream& istr, const string& str) {  }

};


string operator + (const string & str1, const string & str2)
{

}


int stoi(const string str, size_t pos = 0, int base = 10 );
// Преобразование числа, записанного символами в строке, в int
// base - основание системы счисления
// Числа могут быть отрицательными
// Обработка чисел в сс > 10. Большие и маленькие буквы.
