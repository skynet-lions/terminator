#ifndef T100NOTIFY_H
#define T100NOTIFY_H

#include <string>


class T100Notify
{
    public:
        T100Notify();
        virtual ~T100Notify();

        bool    start(std::string);
        bool    stop();

    protected:

    private:
        virtual void    run();

};

#endif // T100NOTIFY_H
