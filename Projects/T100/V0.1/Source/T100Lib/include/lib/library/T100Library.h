#ifndef T100LIBRARY_H
#define T100LIBRARY_H

#include <string>


class T100Library
{
    public:
        T100Library();
        virtual ~T100Library();


        bool        open(std::wstring&, void*&);
        bool        find(void*, std::wstring&);
        bool        close(void*);

    protected:

    private:
};

#endif // T100LIBRARY_H
