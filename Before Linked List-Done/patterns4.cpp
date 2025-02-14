////Namaste
#include<iostream>
#include<string>
using namespace std;

int main() {
    int m, n, i, j, k;

    //1
    /////// Zig-zag pattern
    cout << "Enter the number of columns for the Zig-zag pattern: ";
    cin >> n;
    cout<<endl;    cout<<endl;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            if (((i + j) % 4 == 0) || (i == 2 && j % 4 == 0)) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
    cout << "\n";

    //2
    ////// Butterfly pattern
    cout << "Enter the size for the Butterfly pattern: ";
    cin >> n;
    cout<<endl;    cout<<endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        int space = 2 * n - 2 * i;
        for (int j = 1; j <= space; j++) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        int space = 2 * n - 2 * i;
        for (int j = 1; j <= space; j++) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    cout << "\n";

    //3
    ////// Pattern of Floyd's triangle
    cout << "Enter the number of rows for Floyd's triangle: ";
    cin >> m;
    cout<<endl;    int num = 1;
    cout << "The pattern generated is: " << endl;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << "\n";
    }
    cout << "\n";

    //4
    //// Left half pyramid using number repetition
    cout << "Enter the size for the Left half pyramid using number repetition: ";
    cin >> m;
    cout<<endl;    cout << "The pattern generated is: " << endl;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= i; j++) {
            cout << i;
        }
        cout << "\n";
    }
    cout << "\n";

    //5
    ////// Left half pyramid using number repetition in reverse order
    cout << "Enter the size for the Left half pyramid using numbers in reverse order: ";
    cin >> m;
    cout<<endl;    cout << "The pattern generated is: " << endl;
    for (i = m; i >= 1; i--) {
        for (k = m; k >= i; k--) {
            cout << i;
        }
        cout << "\n";
    }
    cout << "\n";

    //6
    //// Left half pyramid
    cout << "Enter the size for the Left half pyramid: ";
    cin >> m;
    cout<<endl;    for (i = m; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            cout << " ";
        }
        for (k = m; k >= i; k--) {
            cout << "*";
        }
        cout << "\n";
    }
    cout << "\n";

    //7
    ///////// Left half pyramid can also be constructed by this code
    cout << "Enter the size for the alternative Left half pyramid: ";
    cin >> n;
    cout<<endl;    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j <= n - i) {
                cout << " ";
            } else {
                cout << "*";
            }
        }
        cout << "\n";
    }
    cout << "\n";


    //8
    //// Inverted half pyramid
    cout << "Enter the size for the Inverted half pyramid: ";
    cin >> m;
    cout<<endl;    for (i = m; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            cout << "*";
        }
        cout << "\n";
    }
    cout << "\n";

    //9
    //// HOLLOW RECTANGULAR PATTERN
    cout << "Enter the dimensions for the Hollow rectangular pattern (rows columns): ";
    cin >> m>>n;
    cout<<endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == m || j == 1 || j == n) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    cout << "\n";

    //10
    //// REGULAR RECTANGULAR PATTERN
    cout << "Enter the dimensions for the Regular rectangular pattern (rows columns): ";
    cin >> m>>n;
    cout<<endl;
    for (i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}

// //OUTPUT
// Enter the number of columns for the Zig-zag pattern: 

//     *     
//   *   *   
// *       * 

// Enter the size for the Butterfly pattern: 

// *            *
// **          **
// ***        ***
// ****      ****
// *****    *****
// ******  ******
// **************
// **************
// ******  ******
// *****    *****
// ****      ****
// ***        ***
// **          **
// *            *

// Enter the number of rows for Floyd's triangle: 
// The pattern generated is: 
// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10 
// 11 12 13 14 15 
// 16 17 18 19 20 21 
// 22 23 24 25 26 27 28 
// 29 30 31 32 33 34 35 36 
// 37 38 39 40 41 42 43 44 45 
// 46 47 48 49 50 51 52 53 54 55 
// 56 57 58 59 60 61 62 63 64 65 66 

// Enter the size for the Left half pyramid using number repetition: 
// The pattern generated is: 
// 1
// 22
// 333
// 4444
// 55555
// 666666
// 7777777

// Enter the size for the Left half pyramid using numbers in reverse order: 
// The pattern generated is: 
// 7
// 66
// 555
// 4444
// 33333
// 222222
// 1111111

// Enter the size for the Left half pyramid: 
//        *
//       **
//      ***
//     ****
//    *****
//   ******
//  *******

// Enter the size for the alternative Left half pyramid: 
//       *
//      **
//     ***
//    ****
//   *****
//  ******
// *******

// Enter the size for the Inverted half pyramid: 
// *******
// ******
// *****
// ****
// ***
// **
// *

// Enter the dimensions for the Hollow rectangular pattern (rows columns): 
// *******
// *     *
// *     *
// *     *
// *     *
// *     *
// *******

// Enter the dimensions for the Regular rectangular pattern (rows columns): 
// *******
// *******
// *******
// *******
// *******
// *******
// *******