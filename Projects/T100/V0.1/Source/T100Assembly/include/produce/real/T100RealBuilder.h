#ifndef T100REALBUILDER_H
#define T100REALBUILDER_H


class T100RealBuilder
{
    public:
        T100RealBuilder();
        virtual ~T100RealBuilder();

        T100BOOL            save(T100STRING&, T100BuildInfo*);

    protected:

    private:
};

#endif // T100REALBUILDER_H
