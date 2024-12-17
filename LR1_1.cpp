#include <iostream>

using namespace std;
int main()
{
    const int size = 10;
    short* arr = new short[size];
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
        if (cin.good()) {
            cout << "Correct input" << endl;
        }
        else {
            cout << "Error input" << endl;
            cin.clear();
            cin.ignore();
            return 0;
        }
    }

    cout << "Array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "] = " << arr[i] << ", adress = " << &arr[i] << ", S = " << (reinterpret_cast<char*>(&arr[i]) - reinterpret_cast<char*>(arr)) << endl;
    }

    delete[] arr;

    return 0;
}
