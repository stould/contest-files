int curr = 0;
bool has = false;
        
for (int i = 0; i < N; i++) {
    if (i == 0) {
        curr = P[i];
    } else {
        curr ^= P[i];
    }

    if (P[i] > 1) {
        has = true;
    }
 }

if (has) {
    if (curr != 0) {
        cout << "F";
    } else {
        cout << "S";
    }
 } else {
    if (curr == 0) {
        cout << "F";
    } else {
        cout << "S";
    }
 }
