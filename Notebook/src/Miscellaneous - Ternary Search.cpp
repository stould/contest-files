double l = 0, h = 1000000000;

for (int x = 0; x < 150; x++) {
    double ml = l + (h - l) / 3.0;
    double mr = h - (h - l) / 3.0;
    
    if (good) {
        l = ml;
    } else {
        h = mr;
    }
 }
