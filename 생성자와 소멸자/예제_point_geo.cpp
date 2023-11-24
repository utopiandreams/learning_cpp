#include <iostream>

class Point{
    int x, y;

    public:
    Point(int pos_x, int pos_y);
};

class Geometry {
    Point* point_array[100];

    public:
        Geometry();
        Geometry(Point **point_list);

        void AddPoint(const Point &point){

        }

        // 모든 점들간의 거리를 출력하는 함수
        void PrintDistance(){

        // 모든 점들들 잇는 직선들 간의 교점의 수를 출력
        void PringNumMeets()
};