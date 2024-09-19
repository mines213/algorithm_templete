int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
