#include <stdio.h>

// create macro
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/*
------------------------------------

A structure with two members. This declaration merely describes 
a shape of a structure as in the interface in TypeScript.

As this is not an object, it doesn't need to be in uppercase.

------------------------------------
*/
struct point {
    int x;
    int y;
};

/*
------------------------------------

Structure can be nested as follows

------------------------------------
*/
struct rect {
    struct point pt1;
    struct point pt2;
};

struct point makePoint(int, int);
void printPoint(struct point);
struct point addPoint(struct point, struct point);
int ptInRect(struct point, struct rect);
struct rect toCanonical(struct rect);
void printRect(struct rect);
void toCanonicalEnh(struct rect*);
void printRectEnh(struct rect*);
void ptpdemo();

/*
------------------------------------

Structure is similar to but different from class.
It's main purpose is hold a group of data, instead of 
being an object. 

To access fields in a struct: use '.' dot, 
    
    e.g., 
    
        point.x. 

To access fields in a struct by pointer, use '->', or (*pt_name).member

    e.g., 
    
        if a *point (*pt) pointer is passed to a method, we use it like this:

        printf("%d", pt -> x);

        or

        printf("%d", (*pt).x);

The only legal operations on a structure are copying it or assigning to it as a unit, taking its
address with & , and accessing its members.

If we want to access a member by a pointer, but the member is also a pointer:

    e.g.,

        // an struct that internally contains a pointer
        struct ptp {
            int* np;
        };
        struct ptp ptp1 = { &n };

        // we can access to it as follows
        printf("%d\n", *pp->np);

To increment the value that the member as a pointer that it's pointing to

    e.g.,

        say *p is a pointer to a struct, *np is a member of this sturct

         ++*p->np    increments pointer p
         *p->++np    increments pointer np
         (*p->np)    increments the variable that is pointed by np

------------------------------------
*/
int main()
{
    // reuse the defined struct
    struct point pt;
    pt.x = 111;
    pt.y = 222;

    // almost the same in modern lang like JS and TS
    struct point ptv = { 123, 321 };

    // access members by '.'
    printf("x: %d, y:%d\n", ptv.x, ptv.y);

    // for nested structure
    struct rect rec = { pt, ptv };
    printRect(rec);

    printf("\nmakePoint()\n");
    struct point tp = makePoint(50, 50);
    printPoint(tp);

    printf("\naddPoint()\n");
    struct point tp2 = makePoint(25, 25);
    printPoint(addPoint(tp, tp2));

    printf("\ntoCanonical()\n");
    struct rect rt = { tp, tp2 };
    printf("Before Converting to be cononical: ");
    printRect(rt);
    printf("After Converting to be cononical: ");
    rt = toCanonical(rt);
    printRect(rt);

    printf("\nptInRect()\n");
    struct point inpt = makePoint(30, 30);
    printPoint(inpt);
    int inRect = ptInRect(inpt, rt);
    if (inRect == 1)
        printf("In rectangle\n");
    else
        printf("Not in rectangle\n");

    printf("\ntoCanonicalEnh() & printRectEnh() \n");
    struct rect nonConRect = { tp, tp2 };
    printf("Before Converting to be cononical: ");
    printRectEnh(&nonConRect);
    toCanonicalEnh(&nonConRect);
    printf("After Converting to be cononical: ");
    printRectEnh(&nonConRect);

    // demo of accessing a member of a pointer when the member is also a pointer
    ptpdemo();
}

// function that create structure
struct point makePoint(int x, int y)
{
    struct point p = { x, y };
    return p;
}

// function that do arithmatic on point
struct point addPoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

void printPoint(struct point p)
{
    printf("point - { x: %d, y: %d }\n", p.x, p.y);
}

// check whether a point is in the rectangle
int ptInRect(struct point p, struct rect r)
{
    // this requires the rectangle to be canonical
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

// convert to a canonical rectangle
struct rect toCanonical(struct rect r)
{
    struct rect t;
    t.pt1.x = min(r.pt1.x, r.pt2.x);
    t.pt1.y = min(r.pt1.y, r.pt2.y);
    t.pt2.x = max(r.pt1.x, r.pt2.x);
    t.pt2.y = max(r.pt1.y, r.pt2.y);
    return t;
}

void printRect(struct rect r)
{
    // same way to access member even for nested struct
    printf("Rectangle, pt1: (%d, %d), pt2: (%d, %d)\n", r.pt1.x, r.pt1.y, r.pt2.x, r.pt2.y);
}

void printRectEnh(struct rect* r)
{
    //(*r.pt1) or (*r.pt1.x) are illegal, because only the r is a pointer, -> is more like a shorthand that is easiert to use
    printf("Rectangle, pt1: (%d, %d), pt2: (%d, %d)\n", (*r).pt1.x, (*r).pt1.y, (r->pt2).x, (r->pt2).y);
}

// enhanced version of toCanonical() by using pointer, this is much faster
void toCanonicalEnh(struct rect* r)
{
    //(*r.pt1) or (*r.pt1.x) are illegal, because only the r is a pointer, -> is more like a shorthand that is easiert to use
    (*r).pt1.x = min((*r).pt1.x, (*r).pt2.x);
    (*r).pt1.y = min((*r).pt1.y, (*r).pt2.y);
    // point to rt2, and x is a member in rt2
    (r->pt2).x = max((r->pt1).x, (r->pt2).x);
    (*r).pt2.x = max((*r).pt1.y, (*r).pt2.y);
}

// an struct that internally contains a pointer
struct ptp {
    int n;
    int* np;
};

void ptpdemo()
{
    int x, n, *np;
    x = 50;
    n = 100;
    np = &n;

    // the second member is a pointer
    struct ptp ptp1 = { x, &n };

    // here is an example of how to access a pointer (of a struct)'s member if the member is also a pointer
    struct ptp* pp = &ptp1;
    printf("\nOne way to access member of pointer if the member is a value: %d\n", (*pp).n);
    printf("Another way to access member of pointer if the member is a value: %d\n", pp->n);
    printf("Access member of pointer if the member is also a pointer: %d\n", *pp->np);

    // to increment the value that the member as a pointer that it's pointing to
    // note that:
    //      ++*p->np    increments pointer p
    //      *p->++np    increments pointer np
    //      (*p->np)    increments the variable that is pointed by np
    printf("Increment value of the variable that the member (as a pointer) is pointing to: %d\n", ++(*pp->np));
}