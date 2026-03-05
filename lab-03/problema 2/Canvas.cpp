#include "Canvas.h"
#include <iostream>
Canvas::Canvas(int width, int height)
{
    this->width=width;
    this->height=height;
    mat=new char*[height];
    for(int y=0; y<height; y++)
        mat[y]=new char[width];
    Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{//(X-x)^2 + (Y-y)^2 = ray^2
    int px= 0;
    int py= ray;
    int d= 1-ray;
    while(px <= py)
    {
        SetPoint(x+px, y+py, ch);
        SetPoint(x-px, y+py, ch);
        SetPoint(x+px, y-py, ch);
        SetPoint(x-px, y-py, ch);

        SetPoint(x+py, y+px, ch);
        SetPoint(x-py, y+px, ch);
        SetPoint(x+py, y-px, ch);
        SetPoint(x-py, y-px, ch);

        if(d<0)
            d=d+2*px+3;
        else
        {
            d=d+2*(px-py)+5;
            py--;
        }
        px++;
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for(int yy=-ray; yy<=ray; yy++)
        for(int xx=-ray; xx<=ray; xx++)
            if(xx * xx + yy * yy <= ray * ray)
                SetPoint(x+xx, y+yy, ch);
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for(int x=left;x<=right;x++){ SetPoint(x,top,ch); SetPoint(x,bottom,ch); }
    for(int y=top;y<=bottom;y++){ SetPoint(left,y,ch); SetPoint(right,y,ch); }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for(int y=top; y<=bottom; y++)
        for(int x=left; x<=right; x++)
            SetPoint(x, y, ch);
}
void Canvas::SetPoint(int x, int y, char ch)
{
    if(x<0||x>=width||y<0||y>=height)return;
        mat[y][x]=ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx=abs(x2-x1), sx= x1 < x2 ? 1 : -1;//sx, sy decid daca mergem inainte sau inapoi
    int dy=-abs(y2-y1), sy= y1 < y2 ? 1 : -1;
    int err=dx+dy;//err= x2-x1+y2-y1
    while(true)
    {
        SetPoint(x1,y1,ch);
        if(x1==x2&&y1==y2)break;
        int e2=2*err;
        if(e2>=dy)
        {
            err+=dy;
            x1+=sx;
        }
        if(e2<=dx)
        {
            err+=dx;
            y1+=sy;
        }
    }
}
void Canvas::Print()
{
    for(int y=0;y<height;y++)
    {
        for(int x=0;x<width;x++)
            std::cout<<mat[y][x];
        std::cout<<'\n';
    }
}

void Canvas::Clear()
{
    for(int y=0;y<height;y++)
        for(int x=0;x<width;x++)
            mat[y][x]=' ';
}