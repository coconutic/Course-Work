package sample;

import java.io.Serializable;

/**
 * Created by katrin on 4/10/16.
 */
public class Position implements Serializable{
    private int x;
    private int y;


    public void setX(int value)
    {
        x = value;
    }
    public int getX()
    {
        return x;
    }

    public void setY(int value)
    {
        y = value;
    }
    public int getY()
    {
        return y;
    }

    public Position()
    {
        setX(0);
        setY(0);
    }

    public Position(int x, int y)
    {
        setX(x);
        setY(y);
    }

    @Override
    public boolean equals(Object obj) {
        return ((Position) obj).getX() == this.x &&
                ((Position) obj).getY() == this.y;
    }

    @Override
    public int hashCode() {
        final int prime = 10007;
        return x * prime + y;
    }
}
