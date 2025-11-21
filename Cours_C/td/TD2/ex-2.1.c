void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//a++ incrémente a après l'utilisation de a (post-incrémentation)
//++a incrémente a avant l'utilisation de a (pré-incrémentation)

void post_increment(int *a) {
    (*a)++;
}

void pre_increment(int *a) {
    ++(*a);
}