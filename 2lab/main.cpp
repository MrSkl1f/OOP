#include <QCoreApplication>

#include "Vector.hpp"

using namespace std;

int main()
{
    try
    {
        Vector<double> v1;

        if (v1.isEmpty())
            cout << "v1 is empty!\n";

        Vector<int> v2(3);
        cout << "Check method getSize of v2(3):" << v2.getSize() << "\n";

        Vector<double> v3 = {1., 2., 3., 4.};
        cout << "Print v3 = {1., 2., 3., 4.}:" << v3 << "\n";
        cout << "Print element 0 of v3:" << v3[0] << "\n";
        v3.changeElement(0, 5.);
        cout << "Print changed element 0 of v3:" << v3.getNeedElement(0) << "\n";
        cout << "Print index of element 3:" << v3.getIndex(3) << "\n";
        cout << "Print v3:" << v3 << "\n";
        cout << "Print sum of elements of v3:" << v3.sumOfElements() << "\n";
        v1 = v3;
        cout << "Print v1 after v1 = v3:" << v1 << "\n";
        v1 = {5., 4., 3., 2.};
        cout << "Print v1 after v1 = {5., 4., 3., 2.}:" << v1 << "\n";
        cout << "Check mult of vectors v1 and v3: " << v1 * v3 << "\n";
        cout << "Print sum of vectors v1 and v3:" << v1 + v3 << "\n";

        v1 = {1., 2., 3., 4.};
        v3 = {1., 2., 3., 4.};  
        v1 += v3;
        cout << "Check (v1 = v3 = {1., 2., 3., 4.}) v1 += v3" << v1 << "\n";
        cout << "Print diff of vectors v1 and v3" << v1 - v3 << "\n";
        v1 -= v3;
        cout << "Print diff of vectors v1 -= v3" << v1 << "\n";
        
        cout << "Check v1 == v3: " << "\n";
        if (v1 == v3)
            cout << "equal\n";
        else
            cout << "not equal\n";

        cout << "Check v1 != v3: " <<  "\n";
        if (v1 != v3)
            cout << "not equal\n";
        else
            cout << "equal\n";

        Vector<int> v4 = {1, 2, 3, 4};
        v4.pushBack(5);
        v4.pushBack(6);
        cout << "Check pushBack 5 and 6 of v4 = {1, 2, 3, 4}:" << v4 << "\n";
        cout << "Check pop of v4 = {1, 2, 3, 4, 5, 6}: " << v4.pop() << "\n";
        cout << "Check v4:" << v4 << "\n";

        Vector<int> v5;
        v5.pushBack(5);
        cout << v5;

        //Vector<int> v6;
        //v6 -= v5;
    }
    catch (BaseExceptions& except)
    {
        cout << except.what() << "\n";
    }
    return 0;
}
