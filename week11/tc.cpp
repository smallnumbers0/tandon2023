int func(int n) {
    int i, j;
    int sum = 0;

    for(i=1; i <= n; i *=3) {
        for(j = 1; j <= n; j++) {
            sum += (i+j);
        }
    }

    if(n%2 == 0) {
        for(i=1; i < n; i *=2) {
            for(j = 1; j <= n; j++) {
                sum += (i+j);
            }
        }
    }
}

