#include <bits/stdc++.h>
using namespace std;

vector<int> seg = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int getDiff(string time, string prev) {
    return 3600*(10*(time[0] - prev[0]) + (time[1] - prev[1])) + 60*(10*(time[3] - prev[3]) + (time[4] - prev[4])) + 10*(time[6] - prev[6]) + (time[7] - prev[7]); 
}

int energy(int s) {
    int ans = 0;
    if (s == 0) return 6;
    while (s != 0) {
        ans += seg[s % 10];
        s /= 10;
    }
    return ans;
}

int main() {
    string cmd, time, team, prev_time_home, prev_time_guest;
    int g = 0, h = 0, g_energy = 0, h_energy = 0, c = 0;
    int s; 
    while (cin >> cmd) {
        if (cmd == "START") {
            cin >> time;
            prev_time_home = time;
            prev_time_guest = time;
        } else if (cmd == "SCORE") {
            cin >> time >> team >> s;
            if (team == "home") {
                h_energy += getDiff(time, prev_time_home)*energy(h);
                prev_time_home = time;
                h += s;
            } else {
                g_energy += getDiff(time, prev_time_guest)*energy(g);
                prev_time_guest = time;
                g += s;
            } 
        } else {
            cin >> time;
            h_energy += getDiff(time, prev_time_home)*energy(h);
            g_energy += getDiff(time, prev_time_guest)*energy(g);
            ++c;
            cout << "Case " << c << ": " << h_energy + g_energy << "\n";
            g = 0, h = 0, g_energy = 0, h_energy= 0;
        }
    }
    return 0;
}