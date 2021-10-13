#include <iostream>
using namespace std;

void hanoi(int n1, string s, string m, string d){
    if (n1!=0)
    {
        hanoi(n1-1,s,d,m);
        cout << "\nMove " <<n1<<" from "<<s<<" to "<<d;
        hanoi(n1-1,m,s,d);
    }
}
int main() {
	int n1 = 4; 
    string s,d,m;
    cout << "Enter number of rings: ";
    cin >> n1;
    cout << "Enter name of first tower: ";
    cin >> s;
    cout << "Enter name of second tower: ";
    cin >> m;
    cout << "Enter name of third tower: ";
    cin >> d;
    hanoi(n1,s,m,d);
}


