#ifndef Vector2D_H
#define Vector2D_H

#include<iostream>
#include<math.h>
#include <assert.h>

class Vector2D
{
public:
    

    
    float x;   // The frist element of a Vector2D object
    float y;   // The second element of a Vector2D object

    

    
    static  const Vector2D  ZERO;    //The ZERO    define as a Vector2D object with coordinate(0.0)
    static  const Vector2D  UP;      //The UP      define as a Vector2D object with coordinate(1.0)
    static  const Vector2D  DOWN;    //The DOWN    define as a Vector2D object with coordinate(-1.0)
    static  const Vector2D  RIGHT;   //The RIGHT   define as a Vector2D object with coordinate(0.1)
    static  const Vector2D  LEFT;    //The LEFT    define as a Vector2D object with coordinate(0.-1)
   
    
    
    
    
    Vector2D();                                     //The defult constructor ,initializes a new instance of a Vector2D with elements(0,0,0)
    Vector2D(const float value1,
             const float value2                    // The constructor ,initializes a new instance of a Vector2D with  element (value1,value2 , )
             );
    
    ~Vector2D();                                    // The distructor
    
    
    static float Cross(const Vector2D &,
                          const Vector2D &);       //Calculates the cross product of two Vector2D objects.//
    
    static float Dot(const Vector2D &,
                     const Vector2D &);             //Calculates the dot productof two Vector2D objects.//
    
    
    void  Normalize();                              //Normalizes the current Vector2D object.
    float Length()const;                            //Calculates   the current Vector2D object's length.
    float LengthSquared() const;                    //Calculates  the current  Vector2D object's LengthSquared.
    
    void  Set(const float,                           // Sets the current  Vector2D object's value
              const float
             );
    

    
    Vector2D  operator-()const;                     //Negates  the current Vector2D object
    
    Vector2D  operator/(const float )const;         //Divides the current Vector2D object by the specified scalar
    
    inline Vector2D& operator=(const Vector2D &vector1)
    {
        x = vector1.x;
        y = vector1.y;
        
        return *this;
    }        //Assgins all the values from target Vector2Dobject to the current Vector2D object.*/
    
    Vector2D  operator+(const Vector2D  & )const;   //Adds two Vector2D objects
    float  operator*(const Vector2D  & )const;     //dots two Vector2D objects
    
    Vector2D  operator-(const Vector2D  & )const;   //Subtracts a Vector2D object from a Vector2D object.
    Vector2D  operator+=(const Vector2D  & );   //Subtracts a Vector2D object from a Vector2D object.
    Vector2D  operator-=(const Vector2D  & );   //Subtracts a Vector2D object from a Vector2D object.
    bool      operator==(const Vector2D &)const;    //Compares two Vector2D objects for equality.
    
    // --- Friends And Related Function ---//
    
    /*
     operator<<(): Overload operator
     Description:To get cout to accept a Vector2D object after the insertion operator
     param:
     out: std::ostream&
     vector1: Vector2D&
     
     return:A reference of a std::ostream object.
     
     */
    friend inline std::ostream & operator << (std::ostream& out,
                                              const Vector2D& vector1)
    {
        out << "( " << vector1.x << " , " << vector1.y << " ,  )";
        return out ;
        
    }
    
};




#endif
