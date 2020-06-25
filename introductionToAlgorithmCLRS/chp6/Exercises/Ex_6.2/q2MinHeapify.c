int Parent(int i) {
    return (i/2);
}

int Left(int i) {
    return (2*i)+1;
}

int Right(int i) {
    return (2*i)+2;
}

void Max (int array[], int i, int heapSize) {

    int l = Left(i);
    int r = Right(i);
    int smallest;

    if (l<=heapSize && array[l] < array[i]) {
        smallest = l;
    }
    else {
        smallest = i;
    }

    if (r <= heapSize && array[r] < array[smallest]) {
        smallest = r;
    }

    if (smallest != i) {
        int temp = array[i];
        array[i] = array[smallest];
        array[smallest] = temp;
        Max(array, smallest, heapSize);
    }
}

