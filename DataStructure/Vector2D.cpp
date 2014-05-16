
#include "Vector2D.h"
//---------------------------Overload Operator----------------------------//

/************************************************
 operator+(): Overload operator
 Description:Adds two Vector2D objects
 Parameters:
 
 vector1:Vector2D
 The second Vector2D object.
 
 Returns:A Vector2D object that is the result of adding the
 current Vector2D object to second Vector2D object.
 ************************************************/
 Vector2D Vector2D::operator+(const Vector2D & vector1)const
{
    
    return Vector2D(x + vector1.x, y + vector1.y);
    
}
/************************************************
 operator-(): Overload operator
 Description:Subtracts a Vector2D object from a
 Vector2D object.
 Parameters:
 
 vector1:Vector2D
 The second Vector2D object.
 
 Returns:A Vector2D object that is the result of
 subtracting the current Vector2D object from
 second Vector2D object.
 ************************************************/


inline Vector2D Vector2D::operator-(const Vector2D  & vector1)const
{
    
    return Vector2D(x - vector1.x, y - vector1.y);
    
}

/************************************************
 operator-(): Overload operator
 Description: Negates  the current Vector2D object.
 
 
 Returns:A Vector2D object that is the result of negating  the
 current Vector2D .
 
 ************************************************/
inline Vector2D Vector2D::operator-()const
{
    float value1=-x;
    float value2=-y;
    
    Vector2D  vector1(value1,value2);
    return vector1;
}
/************************************************
 operator/(): Overload operator
 Description: Divides the current Vector2D object by
 the specified scalar.
 Parameters:
 
 scalar:float
 The scalar to divide vector by
 
 Returns:A Vector2D object that is the result of dividing c
 urrent vector by scalar.
 
 ************************************************/

inline Vector2D Vector2D::operator/(const float scalar)const
{
    if ( scalar == 0 )
    {
        return Vector2D::ZERO;
        
    }
    
    Vector2D  vector1(x /scalar, y /scalar );
    return vector1;
    
}
/************************************************
 operator=(): Overload operator
 Description: Assgins all the values from target Vector2D
 object to the current Vector2D object.
 Parameters:
 
 vector1:Vector2D
 The target Vector2D
 
 Returns:A reference of current Vector2D object.
 ************************************************/

/************************************************
 operator==(): Overload operator
 Description:Compares two Vector2D objects for equality.
 Parameters:
 
 vector1:Vector2D
 The second Vector2D structure to compare.
 
 Returns:True if the x, y, and z components of current
 Vector2D object and vector2 are equal; false otherwise.
 
 ************************************************/


inline bool Vector2D::operator==(const Vector2D &vector1)const
{
    return (x == vector1.x && y == vector1.y );
}


//----------------------------------------------------------------Defination-----------------------------------------------------------------------//

//----------------------Predefined const vectors----------------------//

/************************************************
 ZERO :constant
 [Public static const]
 Vector that defines the (0,0,-1) constant
 ************************************************/

const  Vector2D Vector2D::ZERO = Vector2D(0.0f, 0.0f);

/************************************************
 UP    :constant
 [Public static const]
 Vector that defines the (0,1,0) constant
 ************************************************/

const Vector2D Vector2D::UP      = Vector2D(0.0f, 1.0f);

/************************************************
 DOWN   :constant
 [Public static const]
 Vector that defines the (0,-1,0) constant
 ************************************************/

const Vector2D Vector2D::DOWN    = Vector2D(0.0f, -1.0f);

/************************************************
 RIGHT  :constant
 [Public static const]
 Vector that defines the (1,0,0) constant
 ************************************************/

const Vector2D Vector2D::RIGHT   = Vector2D(1.0f, 0.0f);

/************************************************
 LEFT  :constant
 [Public static const]
 Vector that defines the (-1,0,0) constant
 ************************************************/

const Vector2D Vector2D::LEFT    = Vector2D(-1.0f, 0.0f);



//-----------------------The constructors  and distructors------------------//

/************************************************
 Vector2D(): Constructor
 Districption: The defult constructor ,initializes a new instance
 of a Vector2D with elements (0,0,0)
 ************************************************/



Vector2D::Vector2D()
{
    
    x = 0;
    y = 0;
    
}

/************************************************
 
 Vector2D(): Constructor
 Description: Initializes a new instance
 of a Vector2D with elements(value1,value2,value3)
 Parameters:
 
 value1:float
 The new Vector2D object's x value.
 
 value2:float
 The new Vector2D object's y value.
 
 value3:float
 The new Vector2D object's z  value.
 
 ************************************************/


Vector2D::Vector2D(const float value1,
                   const float value2
                   )
{
    
    x = value1;
    y = value2;
    
}

/************************************************
 ~Vector2D(): Distructor
 Description: The Distructor of Vector2D object
 ************************************************/

Vector2D::~Vector2D(){};

//-----------------------Public  Static Methods---------------------------------------//


/************************************************
 Dot(): Public static method
 Description: Calculates the dot product with the current
 Vector2D object and a specifed Vector2D object
 Parameters:
 
 vector1:Vector2D
 The first Vector2D object.
 vector2:Vector2D
 The second Vector2D object.
 
 
 Return: A scalar which is the dot product of the current
 Vector2D object and the specified Vector2D object
 
 ************************************************/

inline float Vector2D::Dot(const Vector2D &vector1,
                           const Vector2D &vector2)
{
    return vector1.x*vector2.x+vector1.y*vector2.y;
}

/************************************************
 Cross(): Public static method
 Description: Calculates the cross product of two
 Vector2D objects.
 Parameters:
 
 vector1:Vector2D
 The first Vector2D object.
 vector2:Vector2D
 The second Vector2D object.
 
 Returns: A Vector2D object which is the Cross product
 of the two Vector2D object
 
 ************************************************/

inline float Vector2D::Cross(const Vector2D &vector1,
                             const Vector2D &vector2
                             )
{
    
    return (vector1.x*vector2.y)-(vector2.y*vector1.x);
    
}
/************************************************
 Set(): Public method
 Description:Sets the current  Vector2D object's value
 Parameters:
 
 value1:float
 The current Vector2D object's x value.
 
 value2:float
 The current Vector2D object's y value.
 
 value3:float
 The current Vector2D object's z  value.
 
 ************************************************/


inline void Vector2D::Set(const float value1,
                          const float value2
                          )
{
    x = value1;
    y = value2;
    
}


/************************************************
 Length(): Public method
 
 Description: Calculates   the current Vector2D
 object's length.
 
 Returns: A scalar which is the current
 Vector2D object's length.
 
 ************************************************/



inline float Vector2D::Length()const
{
    return sqrt(LengthSquared());
    
}
/************************************************
 LengthSquared(): Public method
 
 Description: Calculates   the current Vector2D object's
 LengthSquared.
 
 Returns: A scalar which is the current
 Vector2D object's LengthSquared.
 ************************************************/

inline float Vector2D::LengthSquared() const
{
    float lenSquared = x*x + y*y;
    
    return lenSquared;
}
/************************************************
 Normalize(): Public method
 
 Description: Normalizes the current Vector2D object
 
 Ret
 ************************************************/

inline void Vector2D::Normalize()
{
    float len = Length();   // Gets the current Vector2D object's length;
    assert (len!=0);        //when the length of the current Vector2D equal to 0
    
    x = x / len;
    y = y / len;
}
float  Vector2D::operator*(const Vector2D  & vector1)const
{
    return this->x*vector1.x+this->y*vector1.y;
}

Vector2D  Vector2D::operator+=(const Vector2D  & vector)
{
    this->x+=vector.x;
    this->y+=vector.y;
    return *this;
}

Vector2D  Vector2D::operator-=(const Vector2D  & vector)
{
    this->x-=vector.x;
    this->y-=vector.y;
    return *this;
}