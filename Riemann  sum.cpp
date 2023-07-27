#include <iostream>
#include <cmath>
#include <string> 
using namespace std;
int main()
{
    float a, b, n, deltax, remsum, fx, fxsum = 0, coff, poww, add, x, v, powx, fxss;
    int i, zlen = 0, ylen = 0, values, ct = 0, j;
    int y[200], z[200];
    char boo, boo2, rorl, velocity;
    cout << "is this a velocity equation? yes(y) no(n) " << endl;
    cin >> velocity;
    cout << "Enter the 'A' (Where the graph STARTS): " << endl;
    cin >> a;
    cout << "Enter the 'B' (Where the graph ENDS): " << endl;
    cin >> b;
    cout << "DO you want the right(R) or the left(L) subdivisions?" << endl;
    cin >> rorl;
    if (rorl != 'L' && rorl != 'l' && rorl != 'R' && rorl != 'r') { cout << "wrong value:("; exit(3); }
    cout << "Are you going to enter the number of subdivisions (N) or the deltax(X)?" << endl;
    cin >> boo2;

    if (boo2 == 'N' || boo2 == 'n')
    {
        cout << "Enter the 'N' (The count of subdivisons): " << endl;
        cin >> n;
        deltax = (b - a) / n;

    }
    else if (boo2 == 'X' || boo2 == 'x')
    {
        cout << "Enter the 'X' (The delta X): " << endl;
        cin >> deltax;
        n = (b - a) / deltax;
    }
    else { cout << "please enter a valid value and try again :("; exit(3); }

    if (rorl == 'L' || rorl == 'l')
    {
        x = a;
    }
    else if (rorl == 'R' || rorl == 'r')
    {
        x = b;
    }

    cout << "Are you going to Enter Values in a table (V) or equation(E)" << endl;
    cin >> boo;
    if ((boo == 'E' || boo == 'e'))
    {

        cout << "Enter the 'Coff' confessions  of the X (if there is non enter 1): " << endl;
        cin >> coff;
        cout << "Enter the power(degree) of the X: " << endl;
        cin >> poww;
        cout << "Enter the 'add' number added after the X: (if there is non enter 0)" << endl;
        cin >> add;
        fxss = (b - a) / deltax;
        for (i = 0; i < fxss;i++)
        {
            if (poww == (int)poww)
            {
                powx = x;
                for (v = 0;v < poww - 1;v++)
                {
                    powx = powx * x;
                }
            }
            else
            {
                powx = pow(x, poww);
            }
            fxsum = fxsum + ((coff * powx) + add);
            cout << "this is the fxsum: " << fxsum << endl;
            if (rorl == 'L' || rorl == 'l')
            {
                x = x + deltax;
            }
            else if (rorl == 'R' || rorl == 'r')
            {
                x = x - deltax;
            }

        }
        remsum = deltax * fxsum;
    }


    //if user going to enter VALUES/ LEFT subdiv UNDERDEV
    else if (boo == 'V' || boo == 'v')
    {
        cout << "How many values are you going to enter?";
        cin >> values;
        cout << "Enter The X values in ascending  order (enter the values one by one by pressing press enter): " << endl;
        for (i = 0;i < values;i++) { cin >> y[i]; }
        cout << "Enter The Y values in ascending  order (enter the values one by one by pressing press enter): " << endl;
        for (i = 0;i < values;i++) { cin >> z[i]; }

        if ((velocity == 'Y' || velocity == 'y') && (rorl == 'L' || rorl == 'l'))
        {
            for (i = 0;z[i] == 0;i++)
            {
                x = y[i + 1];
            }
        }
        if (rorl == 'L' || rorl == 'l')
        {
            for (i = 0; i < values;i++)
            {
                if (y[i] > b || ct >= n) { break; }
                if (y[i] < a == false)
                {
                    if (x == y[i])
                    {
                        fxsum = fxsum + z[i];
                        ct++;
                        x = x + deltax;
                    }
                }
            }
        }
        else if (rorl == 'R' || rorl == 'r')
        {
            for (i = values - 1; i >= 0;i--)
            {
                if (y[i] < a || ct >= n) { break; }

                if (x == y[i])
                {
                    fxsum = fxsum + z[i];
                    x = x - deltax;
                    ct++;
                }

            }
        }
        remsum = deltax * fxsum;
    }






    else if (boo == 'V' || boo == 'v' && (rorl == 'R' || rorl == 'r'))
    {
        cout << "How many values are you going to enter?";
        cin >> values;
        cout << "Enter The X values in ascending  order (enter the values one by one by pressing press enter): " << endl;
        for (i = 0;i < values;i++) { cin >> y[i]; }
        cout << "Enter The Y values in ascending  order (enter the values one by one by pressing press enter): " << endl;
        for (i = 0;i < values;i++) { cin >> z[i]; }


        remsum = deltax * fxsum;
    }
    //user enter smth wrong
    else { cout << "close the program this is wrong value restart it"; }

    //coutss
    cout << "this is the final fxsum: " << fxsum << endl;
    cout << "this is the DeltaX: " << deltax << endl;
    cout << "this is the riemann sum: " << remsum << endl;

}