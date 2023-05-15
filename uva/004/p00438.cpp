#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define pb push_back
#define reset(a, b) memset(a, int(b), sizeof(a))
#define MOD 1e9 + 7
#define PI 3.141592653589793

int main() {
	double x1, y1, x2, y2, x3, y3, p12_x, p12_y, p13_x, p13_y, cx, cy;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) { 
		p12_x = (x1 + x2)/2;
		p13_x = (x1 + x3)/2;
		p12_y = (y1 + y2)/2;
		p13_y = (y1 + y3)/2;
		if (y1 == y2) {
			double m13 = (x3 - x1)/(y1 - y3);
			cx = p12_x;
			cy = p13_y + m13*(cx - p13_x);
		} else { 
			if (y1 == y3) { 
				double m12 = (x2 - x1)/(y1 - y2);
				cx = p13_x;
				cy = p12_y + m12*(cx - p12_x);			
			} else { 
				double m12 = (x2 - x1)/(y1 - y2);
				double m13 = (x3 - x1)/(y1 - y3);
				cx = ((p12_y - p13_y) + m13*p13_x - m12*p12_x)/(m13 - m12);
				cy = p12_y - m12*(p12_x - cx);
			}
		}
		printf("%.2lf\n", 2*PI*sqrt(pow(cx - x1, 2) + pow(cy - y1, 2)));
	}
	return 0;
}
