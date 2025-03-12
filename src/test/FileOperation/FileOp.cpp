#include "downloader.h"

int main() {
    Downloader down;

    down.calcSHA256("D:\\test.txt");
    return 0;
}