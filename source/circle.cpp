#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>
#include <iostream>
#include <string>

Circle::Circle():
    r_{},
    base_{},
    rgb_{}, 
    name_{} {}

Circle::Circle(float const& r):
    r_{r},
    base_{},
    rgb_{},
    name_{} {}

Circle::Circle(float const& r, Vec2 const& base, Color const& rgb):
    r_{r},
    base_{base},
    rgb_{rgb},
    name_{} {}

Circle::Circle(float const& r, Vec2 const& base, Color const& rgb, std::string name):
    r_{ r },
    base_{ base },
    rgb_{ rgb },
    name_{ name } {}

float Circle::circumfence() const
{
    return fabs(2* M_PI *r_);
}

void Circle::draw(Window const& fensterchen)
{
    Vec2 start{ 0.0f, r_ };
    Mat2 rotation{ make_rotation_mat2(M_PI / 180) };
    Vec2 next{ rotation * start };
    for (int i = 0; i < 360; i++) {
        fensterchen.draw_line(start.x + base_.x, start.y + base_.y, next.x + base_.x, next.y + base_.y, rgb_.r, rgb_.g, rgb_.b, 1.0f);
        start = next;
        next = rotation * next;
    }
}

void Circle::draw(Window const& fensterchen, float t)
{
    Vec2 start{ 0.0f, r_ };
    Mat2 rotation{ make_rotation_mat2(M_PI / 180) };
    Vec2 next{ rotation * start };
    for (int i = 0; i < 360; i++) {
        fensterchen.draw_line(start.x + base_.x, start.y + base_.y, next.x + base_.x, next.y + base_.y, rgb_.r, rgb_.g, rgb_.b, t);
        start = next;
        next = rotation * next;

    }
}

void Circle::draw(Window const& fensterchen, float t, Color rgb)
{
    Vec2 start{ 0.0f, r_ };
    Mat2 rotation{ make_rotation_mat2(M_PI / 180) };
    Vec2 next{ rotation * start };
    for (int i = 0; i < 360; i++) {
        fensterchen.draw_line(start.x + base_.x, start.y + base_.y, next.x + base_.x, next.y + base_.y, rgb.r, rgb.g, rgb.b, t);
        start = next;
        next = rotation * next;

    }
}

bool Circle::is_inside(Vec2 const& Point)const
{
    float rad{pow(r_, 2)};
    float value{ (pow((Point.x - base_.x), 2) + pow((Point.y - base_.y),2)) };
    if (value <= rad)
    {
        return true;
    }
    return false;
}

float Circle::give_r(){
    return r_;
}

std::string Circle::give_name() {
    return name_;
}

bool operator< (Circle c1, Circle c2) {
    if (c1.give_r() >= c2.give_r()) {
        return false;
    }
    else {
        return true;
    }
}
bool operator> (Circle c1, Circle c2) {
    if (c1.give_r() <= c2.give_r()) {
        return false;
    }
    else {
        return true;
    }
}
bool operator== (Circle c1, Circle c2) {
    if (c1.give_r() != c2.give_r()) {
        return false;
    }
    else {
        return true;
    }
}

