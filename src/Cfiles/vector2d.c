#include "vector2d.h"


void vector(vector2d* v,int x,int y){
    v->x=x;
    v->y=y;
}


vector2d addVec(vector2d p_a,vector2d p_b){
    vector2d res;
    res.x=p_a.x+p_b.x;
    res.y=p_a.y+p_b.y;
    return res;
    
}
vector2d SubVec(vector2d p_a,vector2d p_b){
    vector2d res;
    res.x=p_a.x-p_b.x;
    res.y=p_a.y-p_b.y;
    return res;
}

vector2d multiplyBy(vector2d p_a,float x){
    vector2d res;
    res.x=p_a.x*x;
    res.y=p_a.y*x;
    return res;

}
// vector2d rotateVector(vector2d* p_a,int angle){
//     p_a.x=cos(angle+
// }