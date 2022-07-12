#ifndef T100UNICODE_H
#define T100UNICODE_H

#include <string>


class T100Unicode
{
    public:
        T100Unicode();
        virtual ~T100Unicode();

        static std::string      to_string(std::wstring);

    protected:

    private:
};

#endif // T100UNICODE_H
