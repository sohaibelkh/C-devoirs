#include <iostream>
using namespace std;

class test
{
public:
    static int count;

    void call()
    {
        count++;
    }
};

int test::count = 0;

int main()
{
    test t1;

    t1.call();

    cout << "La fonction call a ete apele " << test::count << " fois." << endl;
}