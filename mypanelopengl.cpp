#include "mypanelopengl.h"
#include <QDebug>
#include "GL/glu.h"
#include <cmath>
#include <iostream>
#include "creature.h"

using namespace std;

const int s =200;

MyPanelOpenGL::MyPanelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    timer=NULL;
    r=0;
    w.InitializeH();
    w.InitializeP();
    w.InitializeD();
    w.InitializeV();
}

void MyPanelOpenGL::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void MyPanelOpenGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    for(int i = 0;i<s;i++)
    {
        for(int j = 0; j<s;j++)
        {
            if(w.Getthis(i,j)!=NULL&&w.Getthis(i,j)->Face()=='H')
                glColor3f(0.0, 0.0, 1.0);
            else if(w.Getthis(i,j)!=NULL&&w.Getthis(i,j)->Face()=='P')
                glColor3f(0.0, 1.0, 0.0);
            else if(w.Getthis(i,j)!=NULL && w.Getthis(i,j)->Face()=='D')
                glColor3f(0.0, 0.0, 0.0);
            else if(w.Getthis(i,j)!=NULL && w.Getthis(i,j)->Face()=='V')
                glColor3f(1.0, 0.0, 0.0);
            else if(w.Getthis(i,j)!=NULL && w.Getthis(i,j)->Face()=='F')
                glColor3f(0.9, 0.0, 1.0);
            else
                glColor3f(1.0,1.0,1.0);
            glBegin(GL_QUADS);
              glVertex2f(i,j);
              glVertex2f(i+0.8,j);
              glVertex2f(i+0.8,j+0.8);
              glVertex2f(i,j+0.8);
            glEnd();
        }
    }
//    w.Display();
}

void MyPanelOpenGL::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_Down:
        run();
        break;
    case Qt::Key_Up:
        stop();
        break;
    case Qt::Key_Left:
        w.Save();
        break;
    case Qt::Key_Right:
        w.Load();
        updateGL();
        break;
    }

}

void MyPanelOpenGL::run()
{
    if(!timer)
    {
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(process()));
        timer->start(10);
    }
}

void MyPanelOpenGL::stop()
{
    if(timer)
    {
        delete timer;
        timer = NULL;
    }
}

void MyPanelOpenGL::process()
{
    w.Run();
    updateGL();
}


void MyPanelOpenGL::resizeGL(int width, int height)
{
    glViewport( 0, 0, (GLint)width,(GLint) height );
    gluOrtho2D(0,s,0,s);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 45.0f,(GLfloat)width/(GLfloat)height,1.0f, 100.0f );

}
