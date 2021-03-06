#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <SOIL.h>
#else
#include <GL/freeglut.h>
#include <SOIL.h>
#endif

class TexRect {
public:
    float x;
    float y;
    float w;
    float h;

    float rows;
    float cols;
    // adding some bools here
    bool triggered;
    bool image2_load;
    bool complete;

    GLuint texture_id;  // image 1
    GLuint texture_id2; // image 2
    
    // Standdard TextRect 
    TexRect (const char*, float, float, float, float);
    // Modified TextRect
    TexRect (const char*, const char*, float, float, float, float);

    void draw();
    
    bool contains(float, float);
    
    void moveUp(float rate=0.01);
    void moveDown(float rate=0.01);
    void moveLeft(float rate=0.01);
    void moveRight(float rate=0.01);
    
    void jump();
    void done();
    void reset();
    void advance();

    void Update1(float, float);
    void Update2(bool);

    bool rising;
    bool movingLeft;

    float getPose()const;
    float get_yPose()const;
    
    void  newW(float);
    void  newH(float);

    float xinc;
    float yinc;

    ~TexRect();
};

#endif
