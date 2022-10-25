#include <iostream>
#include <cmath>
using namespace std; 

int main()
{
    cout << "\n";
    int r = 0; //radius of rotating circle
    int t = 0; //angle
    cout<< "Cycloid Analysis"<< "\n\n";
    cout << "Enter the value of the radius"<<"\n";
    cin >> r;
    cout << "The Area of the Cycloid is " << 3*3.14*r<<"\n";
    cout << "The Arc Length of the Cycloid is " << 8*r<<"\n";
    cout << "The coordinates of the roulette can be found using the parametric equations"<< "\n";
    cout << "Please enter an angle for the parametric equations" << "\n";
    cin >> t;

    double x = r*(t-sin(t));
    double y = r*(1-cos(t));
    cout << "The coordinates of the point tracing the Cycloid is " 
    << "\n" << "(" << x <<","<< y << ")" << "\n" ;  


    

}
