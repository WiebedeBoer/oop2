// twice.cpp
// Compile with: g++ twice.cpp -o twice

#include <iostream>

using namespace std;

int twice(int i)
{
    return i + i;
}

double twice(double d)
{
	return d + d;
}

int main()
{
    cout << twice(5) << endl;
    cout << twice(5.3) << endl;

    return 0;
}

