import java.io.*;
import java.lang.*;
import java.util.*;

class Position 
{

    public int x, y;

    public Position() 
    {
    }

    public Position(int x, int y) 
    {
        this.x = x;
        this.y = y;
    }
    
    
    @Override
    public boolean equals(Object obj) 
    {
        return ((Position)obj).x == this.x && ((Position)obj).y == this.y;
    }
    
    @Override
    public int hashCode() 
    {
        final int prime = 10007;
        return x * prime + y;
    }

}


class test
{
    public static void main(String[] args)
    {
        Map<Position, Position> m = new HashMap<Position, Position> ();
        m.put(new Position(5, 5), new Position(1, 1));
        System.out.println(m.get(new Position(5, 5)));
    }
}


