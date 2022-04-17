#include <iostream>


#include "QMath.hpp"


using namespace std;

int main()
{
    cout << "Hello world!" << endl;


    QVector2 vec1, vec2, vec3;

    cout << sizeof(QVector2) << endl;

    vec1 = {1, 2};
    vec2 = {3, 4};

    vec3 = vec1 + QVector2(5,6);

    vec3 = vec1 + 1;
    vec3 = 1.0000001 + vec1;

    cout << vec3.x << endl;

    cout << vec3 << endl;


    QColumnVector2 vec;


    vec = {1.1, 2.2};

    cout << vec << endl;

    return 0;
}
