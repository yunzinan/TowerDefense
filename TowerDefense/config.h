#ifndef CONFIG_H
#define CONFIG_H

#include <QDebug>
#include <QPushButton>
#include <vector>
#include <QString>

using namespace std;

typedef struct ps{
    int row; // 从0开始计数
    int col;
    friend bool operator == (const ps &a, const ps&b) {
        return a.col == b.col && a.row == b.row;
    }
    friend bool operator != (const ps&a, const ps&b) {
        return !(a == b);
    }
    ps(int row = 0, int col = 0) {this->row = row; this->col = col;}
}ps;

#define MAPMAXWIDTH 20
#define MAPMAXHEIGHT 10
#define MAPMINWIDTH 10
#define MAPMINHEIGHT 4

#endif // CONFIG_H
