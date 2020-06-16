#include "stdafx.h"
#include "HTMLDecodeFunctions.h"

using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
        cout << HTMLDecode(str) << endl;

    return 0;
}