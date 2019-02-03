/****************************************************************
** Program name: Final Project
** Author: Milad Mikeal
** Date: 11/23/18
** Description: Space class header file.
****************************************************************/
#ifndef FINALPROJECT_SPACE_HPP
#define FINALPROJECT_SPACE_HPP


class Space {
protected:
    Space *top, *right, *left, *bottom;
    char type;
public:
    Space();
    void setTop(Space *);
    Space* getTop();
    void setRight(Space *);
    Space* getRight();
    void setLeft(Space *);
    Space* getLeft();
    void setBottom(Space *);
    Space* getBottom();
    void setType(char);
    char getType();
    virtual void setSteps(int) =0;
    virtual int getSteps() =0;
    virtual void addComrade(Space *) =0;
    virtual int numComrades() =0;
    virtual ~Space() = default;
};


#endif //FINALPROJECT_SPACE_HPP
