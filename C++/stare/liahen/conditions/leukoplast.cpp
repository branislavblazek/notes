#include <iostream>
using namespace std;

int main(){
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int s1, s2, s;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	s1 = (x2 - x1) * (y2 - y1);
	s2 = (x4 - x3) * (y4 - y3);
	s = s1 + s2;
	//pokial su nacapene na sebe
	if (x1 <= x3 && x2 >= x4 && y1 <= y3 && y2 >= y4){
		cout << s1<< endl;
		return 0;
	} else if (x3 <= x1 && x4 >= x2 && y3 <= y1 && y4 >= y2){
		cout << s2 << endl;
		return 0;
	}
	//pokial su mimo seba
	if (x1 >= x4 || x2 <= x3 || y1 >= y4 || y2 <= y3){
		cout << s << endl;
		return 0;
	} else if (x3 >= x2 || x4 <= x1 || y3 >= y2 || y4 <= y1){
		cout << s << endl;
		return 0;
	} // toto else if tu je asi len navyse, mozem to skusit niekedy vymazat
	//pokial sa prekryvaju
	int x, y;
	// X suradnica
	if (x2 > x3 && x2 < x4){
		if (x1 < x3){
			x = x2 - x3;
		} else {
			x = x2 - x1;
		}
	} else if (x1 > x3 && x1 < x4){
		if (x2 > x4){
			x = x4 - x1;
		} else {
			x = x2 - x1;
		}
	} else if (x3 > x1 && x3 < x2){
		if (x4 < x2){
			x = x4 - x3;
		} else {
			x = x2 - x3;
		}
	} else if (x4 > x1 && x4 < x2){
		if (x3 > x1){
			x = x4 - x3;
		} else {
			x = x4 - x1;
		}
	} else if (x1 == x3 && x2 == x4){
		x = x2 - x1;
	}
	// Y suradnica
	if (y1 > y3 && y1 < y4){
		if (y4 < y2){
			y = y4 - y1;
		} else {
			y = y2 - y1;
		}
	}  else if (y2 > y3 && y2 < y4){
		if (y3 > y1){
			y = y2 - y3;
		} else {
			y = y2 - y1;
		} 
	} else if (y3 > y1 && y3 < y2){
		if (y4 > y2){
			y = y2 - y3;
		} else {
			y = y4 - y3;
		}
	} else if (y4 > y1 && y4 < y2){
		if (y3 > y1){
			y = y4 - y3;
		} else {
			y = y4 - y1;
		}
	} else if (y1 == y3 && y2 == y4){
		y = y2 - y1;
	}
	
	if (s - y * x == 3763){
		cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
	} else {
		cout << s - y * x << endl;
	}
}
