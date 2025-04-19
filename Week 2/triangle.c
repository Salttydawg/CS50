// just notes for function shorts in week 2 of CS50

bool valid_triangle(float x, float y, float z);

bool valid_triangle(float x, float y, float z)
{

    //check for all positive sides
    if (x <= 0 || y <= 0 || z <=0)
    {
        return false;
    }

    // check to see if interger a and b are less than c when combined
    if ((x + y <= z) || (x + z <= y) || (y + z <= x))
    {
        return false;
    }

    // If it passes then just print true!
    return true;
}
