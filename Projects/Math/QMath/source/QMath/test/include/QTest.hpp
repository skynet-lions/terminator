#ifndef QTEST_HPP
#define QTEST_HPP


class QTest
{
    public:
        QTest();
        virtual ~QTest();

        virtual void Test() = 0;

    protected:
    private:
};

#endif // QTEST_HPP
