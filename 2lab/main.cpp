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
        cout << "Check method getSize of v2(3):" << v2.getSize() << endl;

        Vector<double> v3 = {1., 2., 3., 4.};
        cout << "Print v3 = {1., 2., 3., 4.}:" << v3 << "\n";
        cout << "Print element 0 of v3:" << v3[0] << "\n";
        v3.changeElement(0, 5.);
        cout << "Print changed element 0 of v3:" << v3.getNeedElement(0) << endl;
        cout << "Print v3:" << v3 << "\n";
        v1 = v3;
        cout << "Print v1 after v1 = v3:" << v1 << endl;
        v1 = {5., 4., 3., 2.};
        cout << "Print v1 after v1 = {5., 4., 3., 2.}:" << v1 << endl;

        cout << "-----------------\n";
        Vector<double> v4 = {3., 4., 5.};
        Vector<double> v5 = {1., 2., 3.};
        cout << "Check V4 = {3., 4., 5.} * v5 = {1., 2., 3.}:" << v4 * v5 << endl;
        cout << "Check v5 = {1., 2., 3.} * 4. :" << v5 * 4. << endl;
        v4 *= v5;
        cout << "Check V4 = {3., 4., 5.} *= v5 = {1., 2., 3.}:" << v4 << endl;
        v5 *= 4.;
        cout << "Check v5 = {1., 2., 3.} *= 4. :" << v5 << endl;

        cout << "-----------------\n";
        Vector<double> v6 = {10., 20., 30.};
        Vector<double> v7 = {5., 10., 15.};
        cout << "Check v6 = {10., 20., 30.} / v7 = {5., 10., 15.}:" << v6 / v7 << endl;
        cout << "Check v6 = {10., 20., 30.} / 2. :" << v6 / 2. << endl;
        v6 /= v7;
        cout << "Check v6 = {10., 20., 30.} /= v7 = {5., 10., 15.}:" << v6 << endl;
        v7 /= 5.;
        cout << "Check v7 = {5., 10., 15.} /= 5. :" << v7 << endl;

        cout << "-----------------\n";
        Vector<double> v8 = {3., 4., 5.};
        Vector<double> v9 = {1., 2., 3.};
        cout << "Check V8 = {3., 4., 5.} + v9 = {1., 2., 3.}:" << v8 + v9 << endl;
        cout << "Check v9 = {1., 2., 3.} + 4. :" << v9 + 4. << endl;
        v8 += v9;
        cout << "Check V8 = {3., 4., 5.} += v9 = {1., 2., 3.}:" << v8 << endl;
        v9 += 4.;
        cout << "Check v9 = {1., 2., 3.} += 4. :" << v9 << endl;

        cout << "-----------------\n";
        Vector<double> v10 = {3., 4., 5.};
        Vector<double> v11 = {1., 2., 3.};
        cout << "Check V10 = {3., 4., 5.} - v11 = {1., 2., 3.}:" << v10 - v11 << endl;
        cout << "Check v11 = {1., 2., 3.} - 4. :" << v11 - 4. << endl;
        v10 -= v11;
        cout << "Check V10 = {3., 4., 5.} -= v11 = {1., 2., 3.}:" << v10 << endl;
        v11 -= 4.;
        cout << "Check v11 = {1., 2., 3.} -= 4. :" << v11 << endl;
        
        cout << "-----------------\n";
        Vector<double> v12 = {3., 4., 5.};
        Vector<double> v13 = {1., 2., 3.};
        cout << "Check scalar mult of v12 = {3., 4., 5.} & v13 = {1., 2., 3.}:" << (v12 & v13) << endl;
        cout << "Check scalar mult of v12 and v13 with method:" << v12.scalarMult(v13) << endl;
        
        cout << "-----------------\n";
        Vector<double> v14 = {3., 4., 5.};
        Vector<double> v15 = {1., 2., 3.};
        cout << "Check sum of vector mult of v14 = {3., 4., 5.} and v15 = {1., 2., 3.}:" << v14.sumOfVectMult(v15) << endl;
        cout << "Check vector mult of v14 and v15 with method:" << v14.vectMult(v15) << endl;
        cout << "Check vector mult of v14 = {3., 4., 5.} % v15 = {1., 2., 3.}:" << (v14 % v15) << endl;
        v14 %= v15;
        cout << "Check vector mult of v15 = {3., 4., 5.} %= v15 = {1., 2., 3.}:" << v14 << endl;

        cout << "-----------------\n";
        Vector<double> v16 = {4, 3, 2};
        Vector<double> v17 = {2, 3, 4};
        cout << "Angle between v16, v17: " << v16.getAngle(v17) << endl;
        Vector<double> v18 = {0, 2};
        Vector<double> v19 = {2, 0};
        if (v18.isOrthogonality(v19))
            cout << "Orthogonality between {0, 2}, {2, 0} is true!\n";
        if (v19.isCollinearity(v19))
            cout << "Collinearity between v19 and v19 is true!\n";

        cout << "-----------------\n";
        Vector<double> v20 = {3., 4., 5.};
        Vector<double> v21 = {1., 2., 3.};
        if (v20 != v21)
            cout << "v20 = {3., 4., 5.} != v21 = {1., 2., 3.}\n";
        if (v20.isNotEqual(v21))
            cout << "v20 = {3., 4., 5.} not Equal v21 = {1., 2., 3.}\n";

        cout << "-----------------\n";
        Vector<double> v22 = {2., 0.};
        cout << "Check v22 = {2., 0.} is single vector: " << v22.isSingleVect() << endl;
        cout << "Create single vector from v22 = {2., 0.}:" << v22.getSingleVect() << endl;

        cout << "-----------------\n";
        cout << "Check len of v22 = {2., 0.}: " << v22.len() << endl;
        cout << "Check v22 if it is zero: " << v22.isZero() << endl;


    }
    catch (VectorExceptions& except)
    {
        cout << except.what() << endl;
    }
    return 0;
}
