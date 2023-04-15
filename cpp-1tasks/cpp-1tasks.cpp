#include <iostream>
#include "DynamicIntArray.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    DynamicIntArray dynamic0;
    cout << "Конструктор без параметров: " << dynamic0 << endl;

    DynamicIntArray dynamic1(3);
    cout << "Конструктор по размеру(3): " << dynamic1 << endl;

    DynamicIntArray dynamic2(5, 11);
    cout << "Конструктор по размеру (5) и числу (11): " << dynamic2 << endl;

    dynamic2.resize(8);
    cout << "Resize(8): " << dynamic2 << endl;

    dynamic2.resize(3);
    cout <<"Resize(3): " << dynamic2 << endl;

    DynamicIntArray copy(4, 6);
    auto* dynamic3 = new DynamicIntArray(copy);
    cout << "Конструктор копирования (4, 6): " << *dynamic3 << endl;

    DynamicIntArray move(4, 12);
    DynamicIntArray dynamic4(std::move(move));
    cout << "Конструктор перемещения (4, 12): " << dynamic4 << endl;

    DynamicIntArray dynamic5(3);
    cout << "Длина массива: " << dynamic5.getSizeOfArray() << endl;

    cout << "Введите масив размера(3) " << endl;
    DynamicIntArray dynamic6(3);
    for (int i = 0; i < dynamic6.getSizeOfArray(); i++) {
        cout <<"[" << i << "]" << ": ";
        cin >> dynamic6[i];
    }

    //DynamicIntArray dynamic6(5, 1);
    cout << "Массив: " << dynamic6 << endl << "Элемент [2]: " << dynamic6[2] << endl;;

    DynamicIntArray dynamic7 = dynamic6;
    cout << "Оператор копирования: " << dynamic7 << ", Скопированный объект: " << dynamic6
        << endl;

    DynamicIntArray dynamic8 = std::move(dynamic6);
    cout << "Оператор перемещения: " << dynamic8 << endl;


    /*cout << endl << "Введите массивы для дальнейших операций" << endl;
    cout << "Введите маcсив размера(3) " << endl;
    DynamicIntArray dynamic9(3);
    for (int i = 0; i < dynamic9.getSizeOfArray(); i++) {
        cout << "[" << i << "]" << ": ";
        cin >> dynamic9[i];
    }

    cout << "Введите масcив размера(3) " << endl;
    DynamicIntArray dynamic10(3);
    for (int i = 0; i < dynamic10.getSizeOfArray(); i++) {
        cout << "[" << i << "]" << ": ";
        cin >> dynamic10[i];
    }

    cout << "Введите масcив размера(2) " << endl;
    DynamicIntArray dynamic11(2);
    for (int i = 0; i < dynamic11.getSizeOfArray(); i++) {
        cout << "[" << i << "]" << ": ";
        cin >> dynamic11[i];
    }*/
    
    DynamicIntArray dynamic9(4, 6);
    DynamicIntArray dynamic10(4, 5);
    DynamicIntArray dynamic11(3, 11);
    DynamicIntArray dynamic12(4, 6);

    cout << endl<<dynamic9 << " == " << dynamic10 <<": " << (dynamic9 == dynamic10) << endl;
    cout << dynamic9 << " == " << dynamic11 << ": " << (dynamic9 == dynamic11) << endl;
    cout << endl << dynamic9 << " == " << dynamic12 << ": " << (dynamic9 == dynamic12) << endl;
    cout << endl<<dynamic9 << " != " << dynamic10 << ": " << (dynamic9 != dynamic10) << endl;
    cout << dynamic9 << " != " << dynamic11 << ": " << (dynamic9 == dynamic11) << endl;
    cout << endl << dynamic9 << " != " << dynamic12 << ": " << (dynamic9 != dynamic12) << endl;
    cout << endl << dynamic9 << " < " << dynamic10 << ": " << (dynamic9 < dynamic10) << endl;
    cout << endl << dynamic9 << " <= "<< dynamic10 << ": " << (dynamic9 <= dynamic10) << endl;
    cout << endl << dynamic9 << " > " << dynamic10 << ": " << (dynamic9 > dynamic10) << endl;
    cout << endl << dynamic9 << " >= "<< dynamic10 << ": " << (dynamic9 >= dynamic10) << endl;
    cout << endl << dynamic9 << " + "<< dynamic10 << " = " << dynamic9 + dynamic10 << endl;
}